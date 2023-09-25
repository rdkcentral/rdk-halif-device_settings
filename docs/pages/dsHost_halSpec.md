# DEVICE SETTINGS Host HAL Documentation

## Version History

| Date(DD/MM/YY) | Comment | Version |
| ---- | ------- | ------- |
| 23/08/23 | First Release  | 1.0.0 |

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

The diagram below describes a high-level software architecture of the Device Settings Host module.

```mermaid
%%{ init : { "theme" : "forest", "flowchart" : { "curve" : "linear" }}}%%
flowchart TD
y[Caller]<-->x[Device Settings HOST HAL];
x[Device Settings HOST HAL]<-->z[SOC Drivers];
style y fill:#99CCFF,stroke:#333,stroke-width:0.3px,align:left
style z fill:#fcc,stroke:#333,stroke-width:0.3px,align:left
style x fill:#9f9,stroke:#333,stroke-width:0.3px,align:left
 ```

`Device Settings Host` `HAL` provides a set of `APIs` to initialize, query information about the `SoC`.

The main purpose of this module is to facilitate communication between the `caller`, and `HAL` interface, such that information about the Host EDID number, the current CPU temperature, and the SoC ID can be queried by the `caller`.

## Component Runtime Execution Requirements

This interface  shall adeptly manage resources to prevent issues like memory leaks and excessive utilization. It shall also meet performance goals for response time, throughput, and resource use as per the platform's capabilities.

Failure to meet these requirements will likely result in undefined and unexpected behavior.

### Initialization and Startup

`Caller` initialize `dsHost` by calling `dsHostInit()` before calling any other `APIs`. The `caller` is expected to have complete control over the life cycle of the this module.

### Threading Model

This interface is not required to be thread safe. Any `caller` invoking the `APIs` shall ensure calls are made in a thread safe manner. `HAL` is allowed to create internal threads for its operations without excessively consuming system resources. Any threads created by the `HAL` shall be handled gracefully and respective error codes shall be returned if any corresponding `API` fails.

### Process Model

This interface is required to support a single instantiation with a single process.

### Memory Model

This interface is not required to allocate any memory. Any pointers created by the interface should be cleaned up upon termination.

### Power Management Requirements

Although this interface is not required to be involved in any of the power management operations, the state transitions shall not affect its operation. e.g. on resumption from a low power state, the interface shall operate as if no transition has occurred.

### Asynchronous Notification Model

This interface is not required to support asynchronous notification.

### Blocking calls

This interface is not required to have any blocking calls. Synchronous calls shall complete within a reasonable time period.

### Internal Error Handling

All the `APIs` shall return error synchronously as a return argument. `HAL` is responsible for handling system errors (e.g. out of memory) internally.

### Persistence Model

There is no requirement for the interface to persist any setting information. `Caller` is responsible to persist any settings related to the `HAL`.

## Non-functional requirements

The following non-functional requirements will be supported by the module:

### Logging and debugging requirements

This interface is required to support DEBUG, INFO and ERROR messages. INFO and DEBUG shall be disabled by default and enabled when required.

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

The source code shall build into a shared library for Device Settings as this module is a part of Device Settings and shall be named as `libdshal.so`. The build mechanism shall be independent of Yocto.
 
### Variability Management

- Any changes in the `APIs` shall be reviewed and approved by the component architects.
- `DeviceSettings Host` `HAL` modification shall support backward compatibility for the generic operations like image upgrade and downgrade.
- This interface shall return the dsERR_OPERATION_NOT_SUPPORTED error code, if any of the interface - `APIs` are not supported by the underlying hardware.

### Platform or Product Customization

This interface is not required to have any platform or product customizations.

## Interface API Documentation

`API` documentation will be provided by Doxygen which will be generated from the header file.

### Theory of operation and key concepts

The `caller` is expected to have complete control over the life cycle of the `HAL`.

1. Initialize the `HAL` using function: `dsHostInit()` before making any other `API` calls.  If `dsHostInit()` call fails, the `HAL` shall return the respective error code, so that the `caller` can retry the operation.

2. The `caller` can call `dsGetCPUTemperature()`, `dsGetHostEDID()`, `dsGetPreferredSleepMode()` and `dsGetSocIDFromSDK()` to query the needed information.

3. The `caller` can call `dsSetPreferredSleepMode()` to set the needed information.

4. De-initialized the `HAL` using the function: `dsHostTerm()`

### Diagrams

#### Operational Call Sequence

```mermaid
%%{ init : { "theme" : "default", "flowchart" : { "curve" : "stepBefore" }}}%%
   sequenceDiagram
    participant Caller as Caller
    participant HAL as DEVICE SETTINGS HOST HAL
    participant Driver as SoC
    Caller->>HAL:dsHostInit()
    Note over HAL: SOC can initialize the underlying subsystems if needed
    HAL-->>Caller:return
    Caller->>HAL:dsGetCPUTemperature()
    Note over HAL: Returns the current CPU temp
    HAL->>Driver:Getting the current CPU temp
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsGetSocIDFromSDK()
    Note over HAL: Returns the SoC ID
    HAL->>Driver:Getting the SoC ID
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsGetHostEDID()
    Note over HAL: Returns the Host EDID
    HAL->>Driver:Getting the Host EDID
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller ->>HAL:dsSetPreferredSleepMode()
    Note over HAL: Sets the preferred sleep mode
    HAL-->>Caller:return
    Caller ->>HAL:dsGetPreferredSleepMode()
    Note over HAL: Gets the preferred sleep mode
    HAL-->>Caller:return
    Caller ->>HAL:dsHostTerm()
    HAL-->>Caller:return
 ```
