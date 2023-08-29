# DEVICE SETTINGS AUDIO HAL Documentation

## Version History

| Date(DD/MM/YY) | Comment | Version |
| ---- | ------- | ------- |
| 24/08/23 | Edit  | 1.0.1 |
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

- `DS`     - Device Settings
- `HAL`    - Hardware Abstraction Layer
- `API`    - Application Programming Interface
- `Caller` - Any user of the interface via the `API`s
- `CB`     - Callback function (suffix)
- `ARC`    - Audio Return Channel
- `eARC`   - Enhanced Audio Return Channel
- `HDMI`   - High-Definition Multimedia Interface
- `LE`     - Loudness Equivalence
- `DRC`    - Dynamic Range Control
- `RF`     - Radio Frequency
- `dB`     - Decibel
- `MS12`   - MultiStream 12
- `AC4`    - Audio Compression 4
- `ms`     - milliseconds
- `CPU`    - Central Processing Unit

## References


## Description

The diagram below describes a high-level software architecture of the Device Settings Audio module.

```mermaid
%%{ init : { "theme" : "forest", "flowchart" : { "curve" : "linear" }}}%%
flowchart TD
y[Caller]<-->x[DEVICE SETTINGS AUDIO HAL];
x[DEVICE SETTINGS AUDIO HAL]<-->z[Audio Driver];
style y fill:#99CCFF,stroke:#333,stroke-width:0.3px,align:left
style z fill:#fcc,stroke:#333,stroke-width:0.3px,align:left
style x fill:#9f9,stroke:#333,stroke-width:0.3px,align:left
 ```


This interface provides a set of `APIs` to facilitate communication to the Audio Driver.


This interface provides control to enable or disable Audio Output ports like TV Internal Speakers, ARC/eARC, Headphones, SPDIF and allows `Caller` to configure or retrieve various audio parameters.


## Component Runtime Execution Requirements

The component must adeptly manage resources to prevent issues like memory leaks and excessive utilization. It must also meet performance goals for response time, throughput, and resource use as per the platform's capabilities.

Failure to meet these requirements will likely result in undefined and unexpected behaviour.

### Initialization and Startup

`Caller` should initialize by calling `dsAudioPortInit()` before calling any other `API`s. The `Caller` is expected to have complete control over the life cycle of the `Device Settings Audio` module.

### Threading Model

This interface is not required to be thread safe. Any caller invoking the `API`s must ensure calls are made in a thread safe manner.

### Process Model

This interface is required to support a single instantiation with a single process.

### Memory Model

This interface is not required to allocate any memory.

### Power Management Requirements

The Audio HAL is not involved in the power management operation.

### Asynchronous Notification Model

AudioPort provides the following asynchronous registration : 
- `dsAudioOutRegisterConnectCB` 
- `dsAudioFormatUpdateCB`


### Blocking calls

This interface is not required to have any blocking calls. Synchronous calls must complete within a reasonable time period. Any call that can fail due to the lack of response from the connected device must have a timeout period and the function must return the relevant error code.

### Internal Error Handling

All the `API`s must return error synchronously as a return argument. `HAL` is responsible for handling system errors (e.g. out of memory) internally.

### Persistence Model

There is no requirement for HAL to persist any setting information.



## Non-functional requirements

### Logging and debugging requirements

This interface is required to support DEBUG, INFO and ERROR messages. INFO and DEBUG should be disabled by default and enabled when required.

### Memory and performance requirements

This interface is required to not cause excessive memory and `CPU` utilization.

### Quality Control

- This interface is required to perform static analysis, our preferred tool is Coverity.
- Have a zero-warning policy with regards to compiling. All warnings are required to be treated as errors.
- Copyright validation is required to be performed, e.g.: Black duck, and FossID.
- Use of memory analysis tools like Valgrind are encouraged, to identify leaks/corruptions.
- `HAL` Tests will endeavour to create worst case scenarios to assist investigations.
- Improvements by any party to the testing suite are required to be fed back.

### Licensing

The `HAL` implementation is expected to released under the Apache License 2.0.

### Build Requirements

The source code must build into a shared library for Device Settings `HAL` as Audio is a part of Device Settings and must be named as libdshal.so. The build mechanism must be independent of Yocto.
 
### Variability Management

Any changes in the `API`s should be reviewed and approved by the component architects. `DS` Audio `HAL` must return the dsERR_OPERATION_NOT_SUPPORTED error code if any of the interface APIs are not supported by the underlying hardware.

### Platform or Product Customization 

None

## Interface API Documentation

`API` documentation will be provided by Doxygen which will be generated from the header file.

### Theory of operation and key concepts

The caller is expected to have complete control over the life cycle of the `HAL`

1. Initialize the `Audio HAL` using function: `dsAudioPortInit()` before making any other `API` calls.  If `dsAudioPortInit()` call fails, the `HAL` must return the respective error code, so that the caller can retry the operation

2. Once the Audio Ports are initialized, Audio Output ports like TV Internal Speakers, ARC/eARC, Headphones, SPDIF can be enabled or disabled using Audio Port Handle. 

3. The Audio Parameters like Audio Encoding, Audio Format, Audio Compression, Dialog Enhancement, Dolby Volume Mode, Audio Ducking, Bass Enhancer, MI Steering, `LE`, Stereo Mode, Audio Gain, Loop Through, Intelligent Equivalizer, Dynamic Range Control, Fader Control, `MS12` capabilities, Audio Delay, Audio Mixing, Primary Language and Secondary Language can be set or retrieved for specific Audio Ports using Audio Port Handle.


4. De-initialize the `Audio HAL` using the function: `dsAudioPortTerm()`



NOTE: The module would operate deterministically if the above call sequence is followed

### Diagrams

#### Operational Call Sequence


```mermaid
%%{ init : { "theme" : "default", "flowchart" : { "curve" : "stepBefore" }}}%%
   sequenceDiagram
    participant Caller as Caller
    participant HAL as DEVICE SETTINGS AUDIO HAL
    participant Driver as SoC
    Caller->>HAL:dsAudioPortInit()
    Note over HAL: SoC initializes the Audio Ports
    HAL->>Driver: Initializes the Audio Output Ports
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsGetAudioPort()
    Note over HAL: API to get Audio Port Handle
    HAL->>Driver: Get the Audio Port handle
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsEnableAudioPort()
    Note over HAL: API to enable or disable specified Audio Output Port
    HAL->>Driver:Specified Audio Port is enabled or disabled 
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:ds_Audio_SetMethods
    Note over HAL: APIs to set the Audio related parameters 
    HAL->>Driver: Set the Audio Paramters using Audio Port Handle
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:ds_Audio_GetMethods
    Note over HAL: APIs to get the Audio related parameters 
    HAL->>Driver: Get the Audio Paramters using Audio Port Handle
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsSetAudioDucking()
    Note over HAL: API to set the Audio Ducking level of specified Audio Port
    HAL->>Driver:Set the Audio Ducking Level of Specified Audio Output Port
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsEnableLoopThru()
    Note over HAL: API to set loop-through mode of the specified audio port
    HAL->>Driver:Set the loop-through mode of Specified Audio Output Port
    Caller->>HAL:dsGetHDMIARCPortId()
    Note over HAL: API to get HDMI ARC Port ID of each platform
    HAL->>Driver: Get the HDMI ARC Port ID   
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller ->>HAL:dsFPTerm()
    HAL ->> Driver: 
    Driver-->>HAL:return
    HAL-->>Caller:return
 ```


 LEGEND:

ds_Audio_SetMethods:
dsSetAudioEncoding(),
dsSetAudioCompression(),
dsSetDialogEnhancement(),
dsSetDolbyVolumeMode(),
dsSetIntelligentEqualizerMode(),
dsSetVolumeLeveller(),
dsSetBassEnhancer(),
dsSetDRCMode(),
dsSetSurroundVirtualizer(),
dsSetMISteering(),
dsSetGraphicEqualizerMode(),
dsSetMS12AudioProfile(),
dsSetStereoMode(),
dsSetStereoAuto(),
dsSetAudioGain(),
dsSetAudioDB(),
dsSetAudioLevel(),
dsSetAudioDucking(),
dsSetAudioMute(),
dsSetAudioDelay(),
dsSetAudioDelayOffset(),
dsSetMS12AudioProfileSetttingsOverride(),
dsSetAssociatedAudioMixing(),
dsSetFaderControl(),
dsSetPrimaryLanguage(),
dsSetSecondaryLanguage()

ds_Audio_GetMethods:
dsGetAudioEncoding(),
dsGetAudioFormat(),
dsGetAudioCompression(),
dsGetDialogEnhancement(),
dsGetDolbyVolumeMode(),
dsGetIntelligentEqualizerMode(),
dsGetVolumeLeveller(),
dsGetBassEnhancer(),
dsGetDRCMode(),
dsGetSurroundVirtualizer(),
dsGetMISteering(),
dsGetGraphicEqualizerMode(),
dsGetMS12AudioProfileList(),
dsGetMS12AudioProfile(),
dsGetSupportedARCTypes(),
dsGetStereoMode(),
dsGetStereoAuto(),
dsGetAudioGain(),
dsGetAudioDB(),
dsGetAudioLevel(),
dsGetAudioMaxDB(),
dsGetAudioMinDB(),
dsGetAudioOptimalLevel(),
dsGetAudioDelay(),
dsGetAudioDelayOffset(),
dsGetLEConfig(),
dsGetAudioCapabilities(),
dsGetMS12Capabilities(),
dsGetAssociatedAudioMixing(),
dsGetFaderControl(),
dsGetPrimaryLanguage(),
dsGetSecondaryLanguage()
