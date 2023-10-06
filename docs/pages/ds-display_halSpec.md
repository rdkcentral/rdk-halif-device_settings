# DEVICE SETTINGS Display HAL Documentation

## Version History

| Date(DD/MM/YY) | Comment | Version |
| ---- | ------- | ------- |
| 06/10/23 | First Release  | 1.0.0 |

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

- `API`     - Caller Programming Interface
- `Caller`  - Any user of the interface via the `API`
- `DS`      - Device Settings
- `HAL`     - Hardware Abstraction Layer
- `EDID`    - Extended Display Identification Data
- `HDCP`    - High-bandwidth Digital Content Protection
- `SoC`     - System on chip

## Description

The diagram below describes a high-level software architecture of the `DS` Display module.

```mermaid
%%{ init : { "theme" : "forest", "flowchart" : { "curve" : "linear" }}}%%
flowchart TD
y[Caller]<-->x[Device Settings Display HAL];
x[DS Display HAL]<-->z[SOC Drivers];
style y fill:#99CCFF,stroke:#333,stroke-width:0.3px,align:left
style z fill:#fcc,stroke:#333,stroke-width:0.3px,align:left
style x fill:#9f9,stroke:#333,stroke-width:0.3px,align:left
 ```

`DS` Display `HAL` provides a set of `APIs` to manage operations related to connected display devices connected to HDMI Output port of the source devices.

The main purpose of this module is to facilitate communication between the `caller`, and `HAL` interface, such that information about the EDID , Aspect Ratio can be queried by the `caller`. The Display Device parameters such as Device Connected/Disconnected, HDCP Protocol Changes, RX Sense ON/OFF are notified to the `caller`.

## Component Runtime Execution Requirements

This interface  must adeptly manage resources to prevent issues like memory leaks and excessive utilization. It must also meet performance goals for response time, throughput, and resource use as per the platform's capabilities.

Failure to meet these requirements will likely result in undefined and unexpected behavior.

### Initialization and Startup

`Caller` must initialize `dsDisplay` by calling `dsDisplayInit()` before calling any other `APIs`. The `caller` is expected to have complete control over the life cycle of the this module.

### Threading Model

This interface is not required to be thread safe. Any `caller` invoking the `APIs` must ensure calls are made in a thread safe manner. `HAL` is allowed to create internal threads for its operations without excessively consuming system resources. Any threads created by the `HAL` must be handled gracefully and respective error codes must be returned if any corresponding `API` fails.

### Process Model

This interface is required to support a single instantiation with a single process.

### Memory Model

This interface is not required to allocate any memory. Any pointers created by the interface must be cleaned up upon termination.

### Power Management Requirements

The `DS` Display `HAL` is not involved in the power management operation.

### Asynchronous Notification Model

The below mentioned callback registration is used for aysnchronous notification:
- dsRegisterDisplayEventCallback() - Callback registration which listens for display events


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
- `DS` Display `HAL` modification must support backward compatibility for the generic operations like image upgrade and downgrade.
- This interface must return the dsERR_OPERATION_NOT_SUPPORTED error code, if any of the interface - `APIs` are not supported by the underlying hardware.

### Platform or Product Customization

This interface is not required to have any platform or product customizations.

## Interface API Documentation

`API` documentation will be provided by Doxygen which will be generated from the header file.

### Theory of operation and key concepts

The `caller` is expected to have complete control over the life cycle of the `HAL`.

1. Initialize the `DS` Display `HAL` using function: `dsDisplayInit()` before making any other `API` calls.  If `dsDisplayInit()` call fails, the `HAL` must return the respective error code, so that the `caller` can retry the operation.

2. The `caller` can call `dsGetEDID()`, `dsGetDisplayAspectRatio()` and `dsGetEDIDBytes()` to query the information of connected display device. It is also used to notify HDCP Protocol changes of display device to the `caller`.

3. De-initialize the `HAL` using the function: `dsDisplayTerm()`

### Diagrams

#### Operational Call Sequence

```mermaid
%%{ init : { "theme" : "default", "flowchart" : { "curve" : "stepBefore" }}}%%
   sequenceDiagram
    participant Caller as Caller
    participant HAL as DS DISPLAY HAL
    participant Driver as SoC
    Caller->>HAL:dsDisplayInit()
    Note over HAL: SoC initializes the underlying Display subsystem 
    HAL->>Driver:Initializes Display sub-system & associated data structures
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsGetDisplay()
    Note over HAL: Returns the handle for connected display Device 
    HAL->>Driver:Getting the handle for connected display device
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsGetEDID()
    Note over HAL: Gets the EDID Information from connected display device
    HAL->>Driver:Getting the EDID Info from HDMI/DVI display device
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsGetDisplayAspectRatio()
    Note over HAL: Gets the Aspect Ratio of connected display device 
    HAL->>Driver:Getting the Aspect Ratio of display device
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller ->>HAL:dsDisplayTerm()
    HAL->>Driver:Deallocates the associated data structures & releases display specific handles
    Driver-->>HAL:return
    HAL-->>Caller:return
 ```
