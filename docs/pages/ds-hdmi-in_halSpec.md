# Device Settings HdmiIn HAL Documentation

# History

| Date(DD/MM/YY) | Comment | Version |
| ---- | ------- | ------- |
| 25/08/23  | First Release | 1.0.0 |

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
- `Caller` - Any user of the interface via the `APIs`
- `CPU`    - Central Processing Unit
- `DS`     - Device Settings
- `HAL`    - Hardware Abstraction Layer
- `EDID`   - Extended Display Information Data
- `CPU`    - Central Processing Unit
- `SoC`    - System on chip
- `AV`     - Audio-Visual
- `HDMI`   - High-Definition Multimedia Interface
- `SPD`    - Source Product Description.
- `HdmiIn` - HDMI Input

## Description

The diagram below describes a high-level software architecture of the HdmiIn stack.

```mermaid
%%{ init : { "theme" : "forest", "flowchart" : { "curve" : "linear" }}}%%
flowchart TD
y[Caller]<-->x[Device Settings HdmiIn HAL];
x[Device Settings HdmiIn HAL]<-->z[SOC Drivers];
style y fill:#99CCFF,stroke:#333,stroke-width:0.3px,align:left
style z fill:#fcc,stroke:#333,stroke-width:0.3px,align:left
style x fill:#9f9,stroke:#333,stroke-width:0.3px,align:left
 ```

DS `HdmiIn` `HAL` provides a set of `APIs` to initialize, query and set information about the HDMI input ports such as getting the number of input ports, getting the current status of a selected input port, setting the video scale, selecting which HDMI input to be selected as active and registering callbacks for asynchronous notifications.

## Component Runtime Execution Requirements

The component must adeptly manage resources to prevent issues like memory leaks and excessive utilization. It must also meet performance goals for response time, throughput and resource use as per the platform's capabilities.

Failure to meet these requirements will likely result in undefined and unexpected behavior.

### Initialization and Startup

`Caller` must initialize this interface by calling `dsHdmiInInit()` before calling any other `APIs`. The `caller` is expected to have complete control over the life cycle of this module.

### Threading Model

This interface is not required to be thread safe. Any `caller` invoking the `APIs` must ensure calls are made in a thread safe manner. This interface is allowed to create internal threads for its operations without excessively consuming system resources. Any threads created by this interface must be handled gracefully and respective error codes must be returned if any corresponding `API` fails.

### Process Model

This interface is required to support a single instantiation with a single process.

### Memory Model

This interface is not required to allocate any memory. Any pointers created by the interface must be cleaned up upon termination.

### Power Management Requirements

Although this interface is not required to be involved in any of the power management operations, the state transitions must not affect its operation. e.g. on resumption from a low power state, the interface must operate as if no transition has occurred.

### Asynchronous Notification Model

This interface must support asynchronous notifications operations:

 - `dsHdmiInRegisterConnectCB()` must facilitate asynchronous status notifications using the callback when the connection status of the callback `dsHdmiInConnectCB_t`. This callback must be used when the connection status when the HDMI input port changes.
 - `dsHdmiInRegisterSignalChangeCB()` must facilitate asynchronous status notifications using the callback `dsHdmiInSignalChangeCB_t`. This callback must be used when the signal status changes.
 - `dsHdmiInRegisterStatusChangeCB()` must facilitate asynchronous status notifications using the callback `dsHdmiInStatusChangeCB_t`. This callback must be used when the HDMI input status changes.
 - `dsHdmiInRegisterVideoModeUpdateCB()` must facilitate asynchronous status notifications using the callback `dsHdmiInVideoModeUpdateCB_t`. This callback must be used when the video mode changes. This callback must be used when the ALLM mode changes.
 - `dsHdmiInRegisterAllmChangeCB()` must facilitate asynchronous status notifications using the callback `dsHdmiInAllmChangeCB_t`.
 - `dsHdmiInRegisterAVLatencyChangeCB()` must facilitate asynchronous notifications using the callback `dsAVLatencyChangeCB_t` when the AV latency changes.
 - `dsHdmiInRegisterAviContentTypeChangeCB()` must facilitate asynchronous notifications using the call back `dsHdmiInAviContentTypeChangeCB_t` when HDMI input content type changes.


 This interface is allowed to establish its own thread context for its operation, ensuring minimal impact on system resources. Additionally, this interface is responsible for releasing the resources it creates for its operation once the respective operation concludes.


### Blocking calls

This interface is not required to have any blocking calls. Synchronous calls must complete within a reasonable time period.

### Internal Error Handling

The `API` must return error synchronously as a return argument. This interface is responsible for handling system errors (e.g. out of memory) internally.

### Persistence Model

There is no requirement for the interface to persist any setting information. `Caller` is responsible to persist any settings related to this interface.

## Non-functional requirements

The following non-functional requirements will be supported by the module.

### Logging and debugging requirements

This interface is required to support DEBUG, INFO and ERROR messages. INFO and DEBUG must be disabled by default and enabled when required.

### Memory and performance requirements

This interface will ensure optimal use of memory and `CPU` according to the specific capabilities of the platform.

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

The source code must build into a shared library for DS as `HdmiIn` module is a part of DS and must be named as `libdshal.so`. The build mechanism must be independent of Yocto.
 
### Variability Management

- Any changes in the `APIs` must be reviewed and approved by the component architects.
- Any modification must support backward compatibility for the generic operations like image upgrade and downgrade.
- This interface must return the dsERR_OPERATION_NOT_SUPPORTED error code, if any of the interface - `APIs` are not supported by the underlying hardware.

### Platform or Product Customization

This interface is not required to have any platform or product customizations.

## Interface API Documentation

`API` documentation will be provided by Doxygen which will be generated from the header file.

### Theory of operation and key concepts

The `caller` is expected to have complete control over the life cycle of the `HAL`.

1. Initialize the `HAL` `dsHdmiInInit()` before making any other `APIs` calls.  If `dsHdmiInInit()` call fails, the `HAL` must return the respective error code, so that the `caller` can retry the operation.

2. The `caller` can call `dsHdmiInSelectPort()`, `dsHdmiInScaleVideo()`, `dsSetEdidVersion()` and `dsHdmiInSelectZoomMode()` to set the needed information.

3. The `caller` can call `dsHdmiInGetNumberOfInputs()`, `dsHdmiInGetStatus()`, `dsGetEDIDBytesInfo()`, `dsIsHdmiARCPort()`, `dsGetHDMISPDInfo()`,  `dsGetEdidVersion()`, `dsGetAllmStatus()`, `dsGetSupportedGameFeaturesList()`, `dsGetAVLatency()` and `dsHdmiInGetCurrentVideoMode()` to query the needed information.

4. Callbacks can be set with:
    - `dsHdmiInRegisterConnectCB()` - used when the HDMIin port connection status changes
    - `dsHdmiInRegisterSignalChangeCB()` - used when the HDMIin signal status changes
    - `dsHdmiInRegisterStatusChangeCB()` - used when the HDMI input status changes
    - `dsHdmiInRegisterVideoModeUpdateCB()` - used when the HDMIin video mode changes
    - `dsHdmiInRegisterAllmChangeCB()` - used when the HDMI input ALLM mode changes
    - `dsHdmiInRegisterAVLatencyChangeCB()` - used when the AV latency changes
    - `dsHdmiInRegisterAviContentTypeChangeCB()` - used when the Avi Content type changes

5. De-initialize the `HAL` using `dsHdmiInTerm()`

### Diagrams

#### Operational Call Sequence
```mermaid
%%{ init : { "theme" : "default", "flowchart" : { "curve" : "stepBefore" }}}%%
   sequenceDiagram
    participant Caller as Caller
    participant HAL as DS HdmiIn HAL
    participant Driver as SoC
    Caller->>HAL:dsHdmiInInit()
    Note over HAL: SOC initializes the underlying subsystems
    HAL->>Driver:Initializes the underlying subsystems.
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsHdmiInSelectPort()
    Note over HAL: Sets the passed port as active and available for presentation
    HAL->>Driver:Setting the selected port as active
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsHdmiInGetStatus()
    Note over HAL: Gets the status of the current port
    HAL->>Driver:Getting the status of the current port
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsHdmiInScaleVideo()
    Note over HAL: Sets the video scale
    HAL->>Driver:Setting the video scale
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsGetEDIDBytesInfo()
    Note over HAL: Gets the EDID Bytes info
    HAL->>Driver:Getting the EDID Bytes info
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsHdmiInGetNumberOfInputs()
    Note over HAL: Gets the number of HDMI inputs
    HAL->>Driver:Getting the number of HDMI inputs
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsHdmiInGetCurrentVideoMode()
    Note over HAL: Gets the current video mode
    HAL->>Driver:Getting the current video mode
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsSetEdidVersion()
    Note over HAL: Sets the EDID version
    HAL->>Driver:Sets the EDID version
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsGetEdidVersion()
    Note over HAL: Gets the current EDID Version
    HAL->>Driver:Getting the current EDID Version
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsGetAllmStatus()
    Note over HAL: Gets the ALLM status
    HAL->>Driver:Getting the ALLM status
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsGetSupportedGameFeaturesList()
    Note over HAL: Gets the supported game features
    HAL-->>Caller:return
    Caller->>HAL:dsIsHdmiARCPort()
    Note over HAL: Gets whether the specified HDMI input port supports ARC
    HAL->>Driver:Getting whether the specified HDMI input port supports ARC
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsGetHDMISPDInfo()
    Note over HAL: Gets the HDMI SPD info
    HAL->>Driver:Getting the HDMI SPD info
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsHdmiInSelectZoomMode()
    Note over HAL: Sets the zoom mode
    HAL->>Driver:Setting the zoom mode
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsGetAVLatency()
    Note over HAL: Gets the AV latency
    HAL->>Driver:Getting the AV latency
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsHdmiInRegisterConnectCB()
    Note over HAL: Creates the callback for when the HDMI connection status changes.
    HAL-->>Caller:return
    Caller->>HAL:dsHdmiInRegisterSignalChangeCB()
    Note over HAL: Creates the callback for when the HDMI in signal status changes.
    HAL-->>Caller:return
    Caller->>HAL:dsHdmiInRegisterStatusChangeCB()
    Note over HAL: Creates the callback for when the HDMI in status changes.
    HAL-->>Caller:return
    Caller->>HAL:dsHdmiInRegisterVideoModeUpdateCB()
    Note over HAL: Creates the callback for when the video mode changes.
    HAL-->>Caller:return
    Caller->>HAL:dsHdmiInRegisterAllmChangeCB()
    Note over HAL: Creates the callback for when the ALLM mode changes.
    HAL-->>Caller:return
    Caller->>HAL:dsHdmiInRegisterAVLatencyChangeCB()
    Note over HAL: Creates the callback for when the AV latency changes.
    HAL-->>Caller:return
    Caller->>HAL:dsHdmiInRegisterAviContentTypeChangeCB()
    Note over HAL: Creates the callback for when the Avi Content type changes.
    HAL-->>Caller:return
    Note over HAL: HDMI Input connection status changed
    Driver-->>HAL:return
    HAL-->>Caller:dsHdmiInConnectCB_t callback returned
    Note over HAL: The HDMI Input signal status changed
    Driver-->>HAL:return
    HAL-->>Caller:dsHdmiInSignalChangeCB_t callback returned
    Note over HAL: HDMI Input status changed
    Driver-->>HAL:return
    HAL-->>Caller:dsHdmiInStatusChangeCB_t callback returned
    Note over HAL: Hdmi Input video mode changed
    Driver-->>HAL:return
    HAL-->>Caller:dsHdmiInVideoModeUpdateCB_t callback returned
    Note over HAL: HDMI Input mode changed
    Driver-->>HAL:return
    HAL-->>Caller:dsHdmiInAllmChangeCB_t callback returned
    Note over HAL: AV latency changed
    Driver-->>HAL:return
    HAL-->>Caller:dsAVLatencyChangeCB_t callback returned
    Note over HAL: Avi content type changed
    Driver-->>HAL:return
    HAL-->>Caller:dsHdmiInAviContentTypeChangeCB_t callback returned
    Caller ->>HAL:dsHdmiInTerm()
    Note over HAL: Terminates the underlying sub-systems
    HAL->>Driver:Terminates the underlying sub-systems
    Driver-->>HAL:return
    HAL-->>Caller:return
 ```

 #### Flow Diagram
<br/>

![State Diagram](/docs/pages/images/signal_state_diagram.png)

<br/>