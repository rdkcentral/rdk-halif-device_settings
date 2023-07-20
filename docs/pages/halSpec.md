@mainpage

# DEVICE SETTINGS HAL Documentation

## Version History

| Date | Comment | Version |
| ---- | ------- | ------- |
| 13/03/23 | Updated after final review | 1.0.2 |
| 13/03/23 | Edit  | 1.0.1 |
| 20/04/23 | First Release | 1.0.0 |

## Table of Contents

- [Acronyms, Terms and Abbreviations](#acronyms-terms-and-abbreviations)
- [References](#references)
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
- `ARC`    - Audio Return Channel.
- `eARC`   - Enhance Audio Return Channel
- `HDMI`   - High-Definition Multimedia Interface.
- `LE`     - Loudness Equivalence.
- `DRC`    - Dynamic Range Control.
- `RF`     - Radio Frequency.
- `EDID`   - Extended Display Identification Data.
- `SPD`    - Surge Protector Device.
- `ALLM`   - Auto Low Latency Mode
- `HDCP`   - High-bandwidth Digital Copy Protection.
- `DTCP`   - Digital Transmission Copy Protection.
- `CPU`    - Central Processing Unit
- `FPS`    - Frames Per Second
- `SDR`    - Standard Dynamic Range
- `EOTF`   - Electro-Optical Transfer Function 
- `HDR`    - High Dynamic Range
- `SCART`  - SCART stands for Syndicat des Constructeursd’AppareilsRadiorécepteurs et Téléviseurs or Radio and Television Receiver Manufacturers.


## References


## Description

The diagram below describes a high-level software architecture of the module stack.

```mermaid
%%{ init : { "theme" : "forest", "flowchart" : { "curve" : "linear" }}}%%
flowchart TD
y[Caller]-->x[DEVICE SETTINGS HAL];
x[DEVICE SETTINGS HAL]-->z[SOC Drivers];
style y fill:#99CCFF,stroke:#333,stroke-width:0.3px,align:left
style z fill:#fcc,stroke:#333,stroke-width:0.3px,align:left
style x fill:#9f9,stroke:#333,stroke-width:0.3px,align:left
 ```

This interface provides a set of `API`s to facilitate communication through the `Caller` and `HAL`.

The interface initialize, configure and deinitialize the device peripherals.

Configuration Options.

- AudioPort provides the following configuration options to change Volume control, mute, MS12 settings, Audio Delay, Audio Mixing, Fader Control, and Primary Language
- ComporisteIn provides the following configuration option to change Scale video
- Display provides the following configuration options to change Aspect ratio, and EDID data
- FPD provides the following configuration options to change Indicator brightness, Indicator color, Indicator Time, and Indicator Text
- HdmiIn provides the following configuration options to change Scale Video, Zoom mode, EDID data, and Audio control
- Host provides the following configuration options to change Power mode, and Sleep mode
- VideoPort provides the following configuration options to change Zoom settings, and 4k support
- VideoDevice provides the following configuration options to change Resolutions, Aspect ratio, Active Source, and Color

## Component Runtime Execution Requirements


### Initialization and Startup

`Caller` should initialize by calling `ds<Component>Init()` before calling any other `API`s. 
The main components provided by the device settings module are AudioPort, ComporsiteIn, Display, FP, HdmiIn, Host, VideoDevice, and VideoPort.

### Threading Model

This interface is not required to be thread safe. Any caller invoking the `API`s should ensure calls are made in a thread safe manner.

### Process Model

This interface is required to support a single instantiation with a single process.

### Memory Model

### Power Management Requirements

Although this interface is not required to be involved in any of the power management operations, the state transitions MUST not affect its operation. e.g. on resumption from a low power state, the interface should operate as if no transition has occurred.

### Asynchronous Notification Model

For asynchronous transmit and receive operations, the `dsRegister` function `API`s callback registrations are used.
- AudioPort provides the following asynchronous registration API dsAudioOutRegisterConnectCB, and dsAudioFormatUpdateRegisterCB
- CompositeIn provides the following asynchronous registration API dsCompositeInRegisterConnectCB, dsCompositeInRegisterSignalChangeCB, and dsCompositeInRegisterStatusChangeCB, 
- Display provides the following asynchronous registration API dsRegisterDisplayEventCallback
- HdmiIn provides the following asynchronous registration APIs dsHdmiInRegisterAllmChangeCB, dsHdmiInRegisterVideoModeUpdateCB, dsHdmiInRegisterStatusChangeCB, dsHdmiInRegisterSignalChangeCB, and dsHdmiInRegisterConnectCB
- VideoDevice provides the following asynchronous registration API dsRegisterFrameratePostChangeCB, and dsRegisterFrameratePreChangeCB
- VideoPort provides the following asynchronous registration API dsRegisterHdcpStatusCallback



### Blocking calls

There are no blocking calls. Synchronous calls should complete within a reasonable time period. Any call that can fail due to the lack of response from the connected device should have a timeout period and the function should return the relevant error code.

### Internal Error Handling

All the `API`s must return error synchronously as a return argument. `HAL` is responsible for handling system errors (e.g. out of memory) internally.

### Persistence Model

There is a requirement for the `HAL` interface to persist setting information.

Host `HAL` must persist the following function's setting information if persist is true. dsSetPreferredSleepMode.
VideoPort `HAL` must persist the following function's setting information if persist is true. dsSetResolution, dsGetPreferredColorDepth, and dsSetPreferredColorDepth



## Non-functional requirements

### Logging and debugging requirements

This interface is required to support DEBUG, INFO and ERROR messages. INFO and DEBUG should be disabled by default and enabled when required.

### Memory and performance requirements

This interface is required to not cause excessive memory and CPU utilization.

### Quality Control

- This interface is required to perform static analysis, our preferred tool is Coverity.
- Have a zero-warning policy with regards to compiling. All warnings are required to be treated as error.
- Copyright validation is required to be performed, e.g.: Black duck, and FossID.
- Use of memory analysis tools like Valgrind are encouraged, to identify leaks/corruptions.
- `HAL` Tests will endeavour to create worst case scenarios to assist investigations.
- Improvements by any party to the testing suite are required to be fed back.

### Licensing

The `HAL` implementation is expected to released under the Apache License 2.0. 

### Build Requirements

The source code must build into a shared library and must be named as `libdshal.so`. The build mechanism must be independent of Yocto.
 
### Variability Management

Any changes in the `API`s should be reviewed and approved by the component architects.

### Platform or Product Customization

None

## Interface API Documentation

`API`s documentation will be provided by Doxygen which will be generated from the header files.

### Theory of operation and key concepts

The caller is expected to have complete control over the life cycle of the `HAL`.

1. Initialize the `HAL` using function: `ds<Component>Init()` before making any other `API`s calls.  If `Init()` call fails, the `HAL` must return the respective error code, so that the caller can retry the operation.

2. Once initialized is done caller can get the handle for the component using `dsGet<Component>()` if the module uses a handle.

3. Using the handle of the component, different Configurations can be set for that component.

4. De-initialized the `HAL` using the function: `ds<Component>Term()`

NOTE: The module would operate deterministically if the above call sequence is followed.

### Diagrams

#### Operational Call Sequence

```mermaid
%%{ init : { "theme" : "default", "flowchart" : { "curve" : "stepBefore" }}}%%
   sequenceDiagram
    participant Caller as Caller
    participant HAL as DEVICE SETTINGS HAL
    Caller->>HAL:ds<Component>Init()
    Note over HAL: SOC initializes the underlying subsystems.
    HAL-->>Caller:return
    Caller->>HAL:dsSet<Component>()
    Note over HAL: peripheral configurations are set using specific calls
    HAL-->>Caller:return
    Caller->>HAL:dsGet<Component>()
    Note over HAL: peripheral configurations are returned using specific calls
    HAL-->>Caller:return
    Caller->>HAL:dsRegister<Function>()
    HAL-->>Caller:return
    Note over HAL: Once a callback is registered, events notification happen through the callback.
    Caller->>HAL:<Function>CB_t()
    HAL-->>Caller:return
    Caller ->>HAL:ds<Component>Term()
    HAL-->>Caller:return
 ```