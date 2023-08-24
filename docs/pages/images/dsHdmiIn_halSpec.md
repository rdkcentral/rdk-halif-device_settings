# Device Settings HdmiIn HAL Documentation

# History

| Date(DD/MM/YY) | Comment | Version |
| ---- | ------- | ------- |
| TBD | Edit  | 1.0.1 |
| 30/11/22  | First Release | 1.0.0 |

1.0.0 Initial version of the Device settings HAL layer documentation.

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
- `Caller` - Any user of the interface via the `API`s
- `CPU`    - Central Processing Unit
- `DS`     - Device Settings
- `HAL`    - Hardware Abstraction Layer
- `EDID`   - Extended Display Information Data
- `CPU`    - Central Processing Unit
- `SoC`    - System on chip

## Description

The diagram below describes a high-level software architecture of the HdmiIn stack.

```mermaid
%%{ init : { "theme" : "forest", "flowchart" : { "curve" : "linear" }}}%%
flowchart TD
y[Caller]<-->x[DEVICE SETTINGS HdmiIn HAL];
x[DEVICE SETTINGS HdmiIn HAL]<-->z[SOC Drivers];
style y fill:#99CCFF,stroke:#333,stroke-width:0.3px,align:left
style z fill:#fcc,stroke:#333,stroke-width:0.3px,align:left
style x fill:#9f9,stroke:#333,stroke-width:0.3px,align:left
 ```

DeviceSettings `HdmiIn` `HAL` provides a set of `APIs` to initialize, query, and set information about the HDMI ports, such as the number of HDMI ports, the current status of a selected HDMI port, pausing and playing audio, setting the video scale, and selecting which HDMI input is being used.

## Component Runtime Execution Requirements

The component must adeptly manage resources to prevent issues like memory leaks and excessive utilization. It must also meet performance goals for response time, throughput, and resource use as per the platform's capabilities.

Failure to meet these requirements will likely result in undefined and unexpected behavior.

### Initialization and Startup

`Caller` initialize `dsHdmiIn` by calling `dsHdmiInInit()` before calling any other `APIs`. The `Caller` is expected to have complete control over the life cycle of the `DeviceSettings HdmiIn` module.

### Threading Model

This interface is not required to be thread safe. Any `caller` invoking the `API`s should ensure calls are made in a thread safe manner. `HAL` is allowed to create internal threads for its operations without excessively consuming system resources. Any threads created by the `HAL` should be handled gracefully and respective error codes should be returned if any corresponding `API` fails.

### Process Model

This interface is required to support a single instantiation with a single process.

### Memory Model

This interface is not required to allocate any memory. Any pointers created by the interface must be cleaned up upon termination.

### Power Management Requirements

Although this interface is not required to be involved in any of the power management operations, the state transitions MUST not affect its operation. e.g. on resumption from a low power state, the interface should operate as if no transition has occurred.

### Asynchronous Notification Model

 - The `HdmiIn` module should support asynchronous notifications for image write operations.
 - The `HdmiIn` `API` `dsHdmiInRegisterConnectCB()` should facilitate asynchronous status notifications using the callback `dsHdmiInConnectCB_t`.
 - The `HdmiIn` `API` `dsHdmiInRegisterSignalChangeCB()` should facilitate asynchronous status notifications using the callback `dsHdmiInSignalChangeCB_t`.
 - The `HdmiIn` `API` `dsHdmiInRegisterStatusChangeCB()` should facilitate asynchronous status notifications using the callback `dsHdmiInStatusChangeCB_t`.
 - The `HdmiIn` `API` `dsHdmiInRegisterVideoModeUpdateCB()` should facilitate asynchronous status notifications using the callback `dsHdmiInVideoModeUpdateCB_t`.
 - The `HdmiIn` `API` `dsHdmiInRegisterAllmChangeCB()` should facilitate asynchronous status notifications using the callback `dsHdmiInAllmChangeCB_t`.
 - The `HAL` is allowed to establish its own thread context for its operation, ensuring minimal impact on system resources.
 - Additionally, the `HAL` is responsible for releasing the resources it creates for its operation once the respective operation concludes.


### Blocking calls

This interface is not required to have any blocking calls. Synchronous calls should complete within a reasonable time period.

### Internal Error Handling

All the `API`s must return error synchronously as a return argument. `HAL` is responsible for handling system errors (e.g. out of memory) internally.

### Persistence Model

There is no requirement for the interface to persist any setting information. `Caller` is responsible to persist any settings related to the `HAL`.

## Non-functional requirements

The following non-functional requirements will be supported by the module.

### Logging and debugging requirements

This interface is required to support DEBUG, INFO and ERROR messages. INFO and DEBUG should be disabled by default and enabled when required.

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

The source code must build into a shared library for Device Settings as `HdmiIn` module is a part of Device Settings and must be named as `libdshal.so`. The build mechanism shall be independent of Yocto.
 
### Variability Management

- Any changes in the `APIs` should be reviewed and approved by the component architects.
- `DeviceSettings HdmiIn` `HAL` modification should support backward compatibility for the generic operations like image upgrade and downgrade.
- `DeviceSettings HdmiIn` should return the dsERR_OPERATION_NOT_SUPPORTED error code, if any of the interface - `APIs` are not supported by the underlying hardware.
- Providers of the `DeviceSettings HdmiIn` `HAL` should keep a well-defined version history for tracking alterations across diverse library versions, along with their corresponding verification results.

### Platform or Product Customization

None

## Interface API Documentation

`API` documentation will be provided by Doxygen which will be generated from the header file.

### Theory of operation and key concepts

The `caller` is expected to have complete control over the life cycle of the `HAL`.

1. Initialize the `HAL` using function: `dsHdmiInInit()` before making any other `API`s calls.  If `dsHdmiInInit()` call fails, the `HAL` must return the respective error code, so that the `caller` can retry the operation.

2. The `caller` can call `dsHdmiInSelectPort()`, `dsHdmiInScaleVideo()`, `dsHdmiInPauseAudio()` and `dsHdmiInResumeAudio()` to set the needed information.

3. The `caller` can call `dsHdmiInGetNumberOfInputs()`, `dsHdmiInGetStatus()`, `dsGetEDIDBytesInfo()` and `dsHdmiInGetCurrentVideoMode()` to query the needed information.

4. De-initialized the `HAL` using the function: `dsHdmiInTerm()`

### Diagrams

#### Operational Call Sequence

```mermaid
%%{ init : { "theme" : "default", "flowchart" : { "curve" : "stepBefore" }}}%%
   sequenceDiagram
    participant Caller as Caller
    participant HAL as DEVICE SETTINGS HdmiIn HAL
    participant Driver as SoC
    Caller->>HAL:dsHdmiInInit()
    Note over HAL: SOC initializes the underlying subsystems.
    HAL-->>Caller:return
    Caller->>HAL:dsHdmiInSelectPort()
    Note over HAL: Sets the passed port as active.
    HAL->>Driver:Setting the selected port as active.
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsHdmiInGetStatus()
    Note over HAL: Gets the status of the current port.
    HAL->>Driver:Getting the status of the current port.
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsHdmiInScaleVideo()
    Note over HAL: Sets the video scale.
    HAL->>Driver:Setting the video scale.
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsHdmiInPauseAudio()
    Note over HAL: Pauses the audio.
    HAL->>Driver:Pausing the audio.
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsHdmiInResumeAudio()
    Note over HAL: Resumes the audio.
    HAL->>Driver:Pausing the audio.
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsGetEDIDBytesInfo()
    Note over HAL: Gets the EDID Bytes info.
    HAL->>Driver:Returns the EDID Bytes info.
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsHdmiInGetNumberOfInputs()
    Note over HAL: Gets the number of inputs.
    HAL->>Driver:Returns the number of inputs.
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsHdmiInGetCurrentVideoMode()
    Note over HAL: Gets the current video mode.
    HAL->>Driver:Returns the current video mode.
    Driver-->>HAL:return
    HAL-->>Caller:return

    Caller ->>HAL:dsHdmiInTerm()
    HAL-->>Caller:return
 ```