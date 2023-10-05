# DEVICE SETTINGS Video Device HAL Documentation

## Version History

| Date(DD/MM/YY) | Comment | Version |
| ---- | ------- | ------- |
| 04/10/23 | First Release  | 1.0.0 |

## Table of Contents

- [Acronyms, Terms and Abbreviations](#acronyms-terms-and-abbreviations)
- [Description](#description)
- [Component Runtime Execution Requirements](#component-runtime-execution-requirements)
  - [Initialization and Startup](#initialization-and-startup)
  - [Threading Model](#threading-model)
  - [Process Model](#process-model)
  - [Memory Model](#memory-model)
  - [Power Management Requirements](#power-management-requirements)
  - [Asynchronous Notification Model](#asynchronous-notification-model)
  - [Blocking calls](#blocking-calls)
  - [Internal Error Handling](#internal-error-handling)
  - [Persistence Model](#persistence-model)
- [Non-functional requirements](#non-functional-requirements)
  - [Logging and debugging requirements](#logging-and-debugging-requirements)
  - [Memory and performance requirements](#memory-and-performance-requirements)
  - [Quality Control](#quality-control)
  - [Licensing](#licensing)
  - [Build Requirements](#build-requirements)
  - [Variability Management](#variability-management)
  - [Platform or Product Customization](#platform-or-product-customization)
- [Interface API Documentation](#interface-api-documentation)
  - [Theory of operation and key concepts](#theory-of-operation-and-key-concepts)
  - [Diagrams](#diagrams)

## Acronyms, Terms and Abbreviations

- `HAL`    - Hardware Abstraction Layer
- `API`    - Caller Programming Interface
- `Caller` - Any user of the interface via the `API`
- `CPU`    - Central Processing Unit
- `DS`     - Device Settings
- `HAL`    - Hardware Abstraction Layer
- `EDID`   - Extended Display Information Data
- `CPU`    - Central Processing Unit
- `SoC`    - System on chip

## Description

The diagram below describes a high-level software architecture of the Device Settings Video Device module.

```mermaid
%%{ init : { "theme" : "forest", "flowchart" : { "curve" : "linear" }}}%%
flowchart TD
y[Caller]<-->x[Device Settings VIDEO DEVICE HAL];
x[Device Settings VIDEO DEVICE HAL]<-->z[SOC Drivers];
style y fill:#99CCFF,stroke:#333,stroke-width:0.3px,align:left
style z fill:#fcc,stroke:#333,stroke-width:0.3px,align:left
style x fill:#9f9,stroke:#333,stroke-width:0.3px,align:left
 ```

`Device Settings Video Device` `HAL` provides a set of `APIs` to initialize, query information about the `SoC`.

The main purpose of this module is to facilitate communication between the `caller`, and `HAL` interface, such that information about the zoom mode, HDR capabilities, Video encoding formats frame rate information and etc can be set and queried.
@todo doublecheck that these are all the major components

## Component Runtime Execution Requirements

This interface  must adeptly manage resources to prevent issues like memory leaks and excessive utilization. It must also meet performance goals for response time, throughput, and resource use as per the platform's capabilities.

Failure to meet these requirements will likely result in undefined and unexpected behavior.

### Initialization and Startup

`Caller` must initialize `dsVideoDevice` by calling `dsVideoDeviceInit()` before calling any other `APIs`. The `caller` is expected to have complete control over the life cycle of the this module.

### Threading Model

This interface is not required to be thread safe. Any `caller` invoking the `APIs` must ensure calls are made in a thread safe manner. `HAL` is allowed to create internal threads for its operations without excessively consuming system resources. Any threads created by the `HAL` must be handled gracefully and respective error codes must be returned if any corresponding `API` fails.

### Process Model

This interface is required to support a single instantiation with a single process.

### Memory Model

This interface is not required to allocate any memory. Any pointers created by the interface must be cleaned up upon termination.

### Power Management Requirements

Although this interface is not required to be involved in any of the power management operations, the state transitions must not affect its operation. e.g. on resumption from a low power state, the interface must operate as if no transition has occurred.

### Asynchronous Notification Model

This interface is not required to support asynchronous notification.

### Blocking calls

This interface is not required to have any blocking calls. Synchronous calls must complete within a reasonable time period.

### Internal Error Handling

All the `APIs` must return error synchronously as a return argument. `HAL` is responsible for handling system errors (e.g. out of memory) internally.

### Persistence Model

There is no requirement for the interface to persist any setting information. `Caller` is responsible to persist any settings related to the `HAL`.

## Non-functional requirements

The following non-functional requirements will be supported by the module:

### Logging and debugging requirements

This interface is required to support DEBUG, INFO and ERROR messages. INFO and DEBUG must be disabled by default and enabled when required.

### Memory and performance requirements

This interface will ensure optimal use of memory and `CPU` according to the specific capabilities of the system.

### Quality Control

- This interface is required to perform static analysis, our preferred tool is Coverity.
- Have a zero-warning policy with regards to compiling. All warnings are required to be treated as errors.
- Copyright validation is required to be performed, e.g.: Black duck, and FossID.
- Use of memory analysis tools like Valgrind are encouraged to identify leaks/corruptions.
- `HAL` Tests will endeavour to create worst case scenarios to assist investigations.
- Improvements by any party to the testing suite are required to be fed back.

### Licensing

The `HAL` implementation is expected to released under the Apache License 2.0. 

### Build Requirements

The source code must build into a shared library for Device Settings as this module is a part of Device Settings and must be named as `libdshal.so`. The build mechanism must be independent of Yocto.
 
### Variability Management

- Any changes in the `APIs` must be reviewed and approved by the component architects.
- `DeviceSettings Video Device` `HAL` modification must support backward compatibility for the generic operations like image upgrade and downgrade.
- This interface must return the dsERR_OPERATION_NOT_SUPPORTED error code, if any of the interface - `APIs` are not supported by the underlying hardware.

### Platform or Product Customization

This interface is not required to have any platform or product customizations.

## Interface API Documentation

`API` documentation will be provided by Doxygen which will be generated from the header file.

### Theory of operation and key concepts

The `caller` is expected to have complete control over the life cycle of the `HAL`.

1. Initialize the `HAL` using function: `dsVideoDeviceInit()` before making any other `API` calls.  If `dsVideoDeviceInit()` call fails, the `HAL` must return the respective error code, so that the `caller` can retry the operation.

2. The `caller` can call `dsGetVideoDevice()` to get the handle for a specific video device, to be used in the other function calls.

3. The `caller` can call `dsSetDFC()`, `dsSetDisplayframerate()`, `dsSetFRFMode()` and `dsForceDisableHDRSupport()` to set the needed information.

4. The `caller` can call `dsGetDFC()`, `dsGetHDRCapabilities()`, `dsGetSupportedVideoCodingFormats()`, `dsGetVideoCodecInfo()`, `dsGetFRFMode()`, `dsGetCurrentDisplayframerate()`, to query the needed information.

5. De-initialized the `HAL` using the function: `dsVideoDeviceTerm()`

### Diagrams

#### Operational Call Sequence
```mermaid
%%{ init : { "theme" : "default", "flowchart" : { "curve" : "stepBefore" }}}%%
   sequenceDiagram
    participant Caller as Caller
    participant HAL as DEVICE SETTINGS VIDEO DEVICE HAL
    participant Driver as SoC
    Caller->>HAL:dsVideoDeviceInit()
    Note over HAL: SoC initializes the Video Device subsystem
    HAL->>Driver: Allocates required resources for Video Device
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL: ds_Video_Device_SetMethods
    Note over HAL: APIs to set the Video Device Parameters
    HAL->>Driver:Setting the Video Device Parameters
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL: ds_Video_Device_GetMethods
    Note over HAL: APIs to get the Video Device Parameters
    HAL->>Driver:Getting the Video Device Parameters
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller ->>HAL:dsVideoDeviceTerm()
    HAL ->> Driver: Releases all the resources allocated during Video Device init
    Driver-->>HAL:return
    HAL-->>Caller:return
``````


<b> LEGEND: </b>

<b>ds_Video_Device_SetMethods:</b>
dsSetDFC(),
dsSetDisplayframerate(),
dsSetFRFMode(),
dsForceDisableHDRSupport()

<b>ds_Video_Device_GetMethods:</b>
dsGetDFC(),
dsGetHDRCapabilities(),
dsGetSupportedVideoCodingFormats(),
dsGetVideoCodecInfo(),
dsGetVideo_DeviceTimeFormat(),
dsGetFRFMode(),
dsGetCurrentDisplayframerate()