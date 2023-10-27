# Device Settings Video Port HAL Documentation

## Version History

| Date(DD/MM/YY) | Comment | Version |
| ---- | ------- | ------- |
| 13/10/23  | First Release | 1.0.0 |

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
- `SoC`    - System on Chip
- `HDMI`   - High-Definition Multimedia Interface
- `DTCP`   - Digital Transmission Content Protection
- `HDCP`   - High-bandwidth Digital Content Protection
- `HDR`    - High Dynamic Range
- `SDR`    - Standard Dynamic Range
- `SCART`  - Syndicat des Constructeurs d'Appareils Radiorécepteurs et Téléviseurs - Radio and Television Receiver Manufacturers' Association
-  `EDID` - Extended Display Identification Data



## Description

The diagram below describes a high-level software architecture of the `DS` Video Port stack.

```mermaid
%%{ init : { "theme" : "forest", "flowchart" : { "curve" : "linear" }}}%%
flowchart TD
y[Caller]<-->x[Device Settings Video Port HAL];
x[Device Settings Video Port HAL]<-->z[SOC Drivers];
style y fill:#99CCFF,stroke:#333,stroke-width:0.3px,align:left
style z fill:#fcc,stroke:#333,stroke-width:0.3px,align:left
style x fill:#9f9,stroke:#333,stroke-width:0.3px,align:left
 ```

`DS` Video Port `HAL` provides a set of `APIs` to initialize, query and set information about the Video ports like getting  video port handle, fetching connected display information such as color depth, color space, matrix coefficients, quantization range, supported video resolutions using the video port handle. It also provides `APIs` to enable or disable content protection like `HDCP` and `DTCP`, to set  the `SCART` parameters , background color and preferred color depth of the video port.


## Component Runtime Execution Requirements

The interface must adeptly manage resources to prevent issues like memory leaks and excessive utilization. It must also meet performance goals for response time, throughput and resource use as per the platform's capabilities.

Failure to meet these requirements will likely result in undefined and unexpected behavior.

### Initialization and Startup

`Caller` must initialize this interface by calling `dsVideoPortInit()` before calling any other `APIs`. The `caller` is expected to have complete control over the life cycle of this module.

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

 - `dsHDCPStatusCallback_t` is triggered when the connection status when the HDCP status of video port changes.
 - `dsVideoFormatUpdateCB` is triggered when the video format changes.
 

 This interface is allowed to establish its own thread context for its operation, ensuring minimal impact on system resources. Additionally, this interface is responsible for releasing the resources it creates for its operation once the respective operation concludes.


### Blocking calls

This interface is not required to have any blocking calls. Synchronous calls must complete within a reasonable time period.

### Internal Error Handling

The `API` must return error synchronously as a return argument. This interface is responsible for handling system errors (e.g. out of memory) internally.

### Persistence Model

There is no requirement for the interface to persist any setting information. Caller is responsible to persist any settings related to the HAL.

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

The source code must build into a shared library for `DS` as Video Port module is a part of `DS` and must be named as `libdshal.so`. The build mechanism must be independent of Yocto.
 
### Variability Management

- Any changes in the `APIs` must be reviewed and approved by the component architects.
- Any modification must support backward compatibility for the generic operations like image upgrade and downgrade.
- This interface must return the dsERR_OPERATION_NOT_SUPPORTED error code, if any of the interface - `APIs` are not supported by the underlying hardware.

### Platform or Product Customization

The configuration settings file for `DS` Video Port can be used for adding platform specific configurations. The sample files are [<b>dsVideoPortSettings_template.h</b>](./dsVideoPortSettings_template.h ) and [<b>dsVideoResolutionSettings_template.h</b>](./dsVideoResolutionSettings_template.h ) 

## Interface API Documentation

`API` documentation will be provided by Doxygen which will be generated from the header file.

### Theory of operation and key concepts

The `caller` is expected to have complete control over the life cycle of the `HAL`.

1. Initialize the `HAL` `dsVideoPortInit()` before making any other `APIs` calls.  If `dsVideoPortInit()` call fails, the `HAL` must return the respective error code, so that the `caller` can retry the operation.

2. The `caller` can call `dsEnableDTCP()`, `dsEnableHDCP()`, `dsEnableVideoPort()`, `dsSetResolution()`, `dsSetActiveSource()`, `dsSetForceDisable4KSupport()`, `dsSetScartParameter()`, `dsSetHdmiPreference()`, `dsSetBackgroundColor()`, `dsSetForceHDRMode()` and `dsSetPreferredColorDepth()` to set the needed information.

3. The `caller` can call `dsGetVideoPort()`, `dsGetSurroundMode()`, `dsGetResolution()`, `dsIsVideoPortEnabled()`, `dsIsDisplayConnected()`,  `dsIsDisplaySurround()`, `dsGetSurroundMode()`, `dsIsVideoPortActive()`, `dsIsDTCPEnabled()` , `dsIsHDCPEnabled()`, `dsGetResolution()`, `dsGetHDCPStatus()`, `dsGetHDCPProtocol()`, `dsGetHDCPReceiverProtocol()`, `dsGetHDCPCurrentProtocol()`, `dsGetTVHDRCapabilities()`, `dsGetForceDisable4KSupport()`, `dsGetVideoEOTF()`, `dsGetMatrixCoefficients()`, `dsGetColorDepth()` to query the needed information.

4. Callbacks can be set with:
    - `dsRegisterHdcpStatusCallback()` is triggered when there is a change in HDCP status of the video port
    - `dsVideoFormatUpdateCB()` is triggered when there is a change in video format of the content
    

5. De-initialize the `HAL` using `dsVideoPortTerm()`.

### Diagrams

#### Operational Call Sequence
```mermaid
%%{ init : { "theme" : "default", "flowchart" : { "curve" : "stepBefore" }}}%%
   sequenceDiagram
    participant Caller as Caller
    participant HAL as DS Video Port HAL
    participant Driver as SoC
    Caller->>HAL:dsVideoPortInit()
    Note over HAL: SOC initializes the underlying Video Port sub-system
    HAL->>Driver:Initializes the Video Port sub-system
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsGetVideoPort()
    Note over HAL: Gets the handle for video port
    HAL->>Driver:Getting the handle of video port
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsIsVideoPortEnabled()
    Note over HAL: Indicates whether video port is enabled or not
    HAL->>Driver:Getting the status of the video port
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsIsDisplayConnected()
    Note over HAL: Indicates whether video port is connected to display or not
    HAL->>Driver: Getting the connection status of display
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsIsDisplaySurround()
    Note over HAL: Indicates whether connected display supports surround sound
    HAL->>Driver: Getting the surround capability of display connected to video port
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsGetSurroundMode()
    Note over HAL: Gets the surround mode of display 
    HAL->>Driver:Getting the surround mode of display connected to video port
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsEnableDTCP()
    Note over HAL: Enables/Disables the DTCP for specified video port
    HAL->>Driver: DTCP is enabled / disabled based on input parameter
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsEnableHDCP()
    Note over HAL: Enables/Disables the HDCP for specified video port
    HAL->>Driver: HDCP is enabled / disabled based on input parameter
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsSetResolution()
    Note over HAL: Sets the resolution of video port
    HAL->>Driver: Setting the resolution of display corresponding to specified video port
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsGetResolution()
    Note over HAL: Gets the resolution of video port
    HAL->>Driver:Getting the resolution of display corresponding to specified video port
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsGetHDCPReceiverProtocol()
    Note over HAL: Gets the HDCP protocol version of Receiver/TV 
    HAL->>Driver:Getting the  HDCP protocol version of display corresponding to specified video port
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsGetTVHDRCapabilities()
    Note over HAL: Gets the HDR capabilities of TV
    HAL->>Driver:Getting the HDR capabilities of TV/Display corresponding to specified video port
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsSupportedTvResolutions()
    Note over HAL: Gets the supported resolutions of TV
    HAL->>Driver:Getting the supported resolutions of TV corresponding to specified video port
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsSetScartParameter()
    Note over HAL: Sets the SCART parameters of Display
    HAL->>Driver:Setting the SCART parameters of display corresponding to specified video port
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsGetVideoEOTF()
    Note over HAL: Gets the current Electro-Optical Transfer Function (EOT) value
    HAL->>Driver:Getting the EOT function value of display corresponding to specified video port
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsRegisterHdcpStatusCallback()
    Note over HAL: Creates the callback for getting the HDCP status on HDMI Ports
    HAL-->>Caller:return
    Caller->>HAL:dsVideoFormatUpdateRegisterCB()
    Note over HAL: Creates the callback for getting the video format updates
    HAL-->>Caller:return
    HAL-->>Caller:dsHDCPStatusCallback_t callback returned
    Note over HAL: The HDCP status changed
    Driver-->>HAL:return
    HAL-->>Caller:dsVideoFormatUpdateCB callback returned
    Note over HAL: Video Format changed
    Driver-->>HAL:return
    Caller ->>HAL:dsVideoPortTerm()
    Note over HAL: Terminates the underlying Video Port sub-system
    HAL->>Driver:Terminates the underlying Video Port sub-system
    Driver-->>HAL:return
    HAL-->>Caller:return
 ```
