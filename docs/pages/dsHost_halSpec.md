# DEVICE SETTINGS HAL Documentation

## Version History

| Date(DD/MM/YY) | Comment | Version |
| ---- | ------- | ------- |
| 13/03/23 | Edit  | 1.0.1 |
| 20/04/23 | First Release | 1.0.0 |

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
- `DS`:      Device Settings.
- `HAL`:     Hardware Abstraction Layer.
- `EDID`:    Extended Display Information Data.
- `CPU`:     Central Processing Unit
- `SoC`:     System on chip

## Description

The diagram below describes a high-level software architecture of the module stack.

```mermaid
%%{ init : { "theme" : "forest", "flowchart" : { "curve" : "linear" }}}%%
flowchart TD
y[Caller]<-->x[DEVICE SETTINGS HOST HAL];
x[DEVICE SETTINGS HOST HAL]<-->z[SOC Drivers];
style y fill:#99CCFF,stroke:#333,stroke-width:0.3px,align:left
style z fill:#fcc,stroke:#333,stroke-width:0.3px,align:left
style x fill:#9f9,stroke:#333,stroke-width:0.3px,align:left
 ```

DeviceSettings Host `HAL` provides a set of `APIs` to initialize, set, and query information about the `HAL` and `SoC`.

- The main purpose is to facilitate communication between the `Caller`, `HAL` and the `SoC`, such that information about the current `HAL` version number, the Host EDID number, the current CPU temperature, and the SoC ID can be queried by the `Caller`.

## Component Runtime Execution Requirements

The component should manage system resources appropriately to avoid memory leaks and excessive resource utilization. Efficient memory management and resource cleanup are essential for stable and reliable execution. Additionally, the component should meet specified performance requirements, including response time, throughput, and resource usage based on the underlying platform's capabilities. The component should also be designed to scale effectively with increased load, being able to handle higher levels of usage without significant degradation in performance or stability.

Failure to meet these requirements will likely result in undefined and unexpected behavior.

### Initialization and Startup

`Caller` must be initialized by calling `dsHostInit()` before calling any other `APIs`. The `Caller` is expected to have complete control over the life cycle of the `DeviceSettings Host` module.

### Threading Model

This interface is not required to be thread safe. Any `caller` invoking the `API`s should ensure calls are made in a thread safe manner. `HAL` is allowed to create internal threads for its operations without excessively consuming system resources. Any threads created by the `HAL` should be handled gracefully and respective error codes should be returned if any corresponding `API` fails.

### Process Model

This interface is required to support a single instantiation with a single process.

### Memory Model

This interface is not required to allocate and return memory pointers. Any pointers created by the interface must be cleaned up upon termination.

### Power Management Requirements

Although this interface is not required to be involved in any of the power management operations, the state transitions MUST not affect its operation. e.g. on resumption from a low power state, the interface should operate as if no transition has occurred.

### Asynchronous Notification Model

This interface is not required to support asynchronous notification.

### Blocking calls

There are no blocking calls. Synchronous calls should complete within a reasonable time period. Any call that can fail due to the lack of response from the connected device should have a timeout period and the function should return the relevant error code.

### Internal Error Handling

All the `API`s must return error synchronously as a return argument. `HAL` is responsible for handling system errors (e.g. out of memory) internally.

### Persistence Model

There is no requirement for the interface to persist any setting information. `Caller` is responsible to persist any settings related to the `HAL`.

## Non-functional requirements

The following non-functional requirements will be supported by the module.

### Logging and debugging requirements

This interface is required to support DEBUG, INFO and ERROR messages. INFO and DEBUG should be disabled by default and enabled when required.

### Memory and performance requirements

This interface will ensure optimal use of memory and CPU according to the specific capabilities of the system.

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

- Any changes in the `APIs` should be reviewed and approved by the component architects.
- `DeviceSettings Host` `HAL` modification should support backward compatibility for the generic operations like image upgrade and downgrade
- `DeviceSettings Host` should return the dsERR_OPERATION_NOT_SUPPORTED error code, If any of the interface - `APIs` are not supported by the underlying hardware
- Providers of the `DeviceSettings Host` `HAL` should keep a well-defined version history for tracking alterations across diverse library versions, along with their corresponding verification results.

### Platform or Product Customization

None

## Interface API Documentation

`API`s documentation will be provided by Doxygen which will be generated from the header files.

### Theory of operation and key concepts

The `caller` is expected to have complete control over the life cycle of the `HAL`.

1. Initialize the `HAL` using function: `dsHostInit()` before making any other `API`s calls.  If `dsHostInit()` call fails, the `HAL` must return the respective error code, so that the `caller` can retry the operation.

2. Once initialized, the `caller` can call `dsSetVersion()` to set the version.

3. The `caller` can call `dsGetVersion()`, `dsGetCPUTemperature()`, `dsGetHostEDID()` and `dsGetSocIDFromSDK()` to query the needed information.

4. De-initialized the `HAL` using the function: `dsHostTerm()`

### Diagrams

#### Operational Call Sequence

@todo discuss further on the dsSetVersion function call.

```mermaid
%%{ init : { "theme" : "default", "flowchart" : { "curve" : "stepBefore" }}}%%
   sequenceDiagram
    participant Caller as Caller
    participant HAL as DEVICE SETTINGS HOST HAL
    participant Driver as SoC
    Caller->>HAL:dsHostInit()
    Note over HAL: SOC initializes the underlying subsystems.
    HAL-->>Caller:return
    Caller->>HAL:dsSetVersion()
    Note over HAL: Sets the version
    HAL->>Driver:Setting the version number.
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsGetVersion()
    Note over HAL: Returns the version.
    HAL->>Driver:Getting the version number
    Driver-->>HAL:return
    Caller->>HAL:dsGetCPUTemperature()
    Note over HAL: Returns the current CPU temp.
    HAL->>Driver:Getting the current CPU temp
    Driver-->>HAL:return
    Caller->>HAL:dsGetSocIDFromSDK()
    Note over HAL: Returns the SoC ID.
    HAL->>Driver:Getting the SoC ID.
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsGetHostEDID()
    Note over HAL: Returns the Host EDID.
    HAL->>Driver:Getting the Host EDID.
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller ->>HAL:dsHostTerm()
    HAL-->>Caller:return
 ```