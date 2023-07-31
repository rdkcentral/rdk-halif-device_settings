@mainpage

# DEVICE SETTINGS HAL Documentation

## Version History

| Date(DD/MM/YY) | Comment | Version |
| ---- | ------- | ------- |
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
- `CPU`    - Central Processing Unit

## References


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

This interface provides a set of `API`s to facilitate communication through the `Caller` and `HAL`.

The interface initialize, configure and deinitialize the device peripherals.

## Component Runtime Execution Requirements


### Initialization and Startup

`Caller` should initialize by calling `dsHostInit()` before calling any other `APIs`.

### Threading Model

This interface is not required to be thread safe. Any caller invoking the `API`s should ensure calls are made in a thread safe manner.

### Process Model

This interface is required to support a single instantiation with a single process.

### Memory Model

### Power Management Requirements

Although this interface is not required to be involved in any of the power management operations, the state transitions MUST not affect its operation. e.g. on resumption from a low power state, the interface should operate as if no transition has occurred.

### Asynchronous Notification Model

No Asynchronous notification.

### Blocking calls

There are no blocking calls. Synchronous calls should complete within a reasonable time period. Any call that can fail due to the lack of response from the connected device should have a timeout period and the function should return the relevant error code.

### Internal Error Handling

All the `API`s must return error synchronously as a return argument. `HAL` is responsible for handling system errors (e.g. out of memory) internally.

### Persistence Model

There is no requirement for the interface to persist any setting information. `Caller` is responsible to persist any settings related to the `HAL`.

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

1. Initialize the `HAL` using function: `dsHostInit()` before making any other `API`s calls.  If `dsHostInit()` call fails, the `HAL` must return the respective error code, so that the caller can retry the operation.

2. Once initialized, the `caller` can call `dsSetHostPowerMode()`, `dsSetPreferredSleepMode()` and `dsSetVersion()` to set functions.

3. The `caller` can call `dsGetHostPowerMode()`, `dsGetPreferredSleepMode()` and `dsGetVersion()` to query functions.

4. De-initialized the `HAL` using the function: `dsHostTerm()`

### Diagrams

#### Operational Call Sequence

```mermaid
%%{ init : { "theme" : "default", "flowchart" : { "curve" : "stepBefore" }}}%%
   sequenceDiagram
    participant Caller as Caller
    participant HAL as DEVICE SETTINGS HOST HAL
    participant Driver as HAL Device Control
    Caller->>HAL:dsHostInit()
    Note over HAL: SOC initializes the underlying subsystems.
    HAL-->>Caller:return
    Caller->>HAL:dsSetHostPowerMode()
    Note over HAL: Sets the power mode of the host.
    HAL->>Driver:Setting the power mode
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsGetHostPowerMode()
    Note over HAL: Returns the power mode of the host.
    HAL->>Driver:Getting the power mode
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsSetPreferredSleepMode()
    Note over HAL: Sets the preferred sleep mode.
    HAL->>Driver:Setting the preferred sleep mode.
    Driver-->>HAL:return
    HAL-->>Caller:return
    Caller->>HAL:dsGetPreferredSleepMode()
    Note over HAL: Returns the current preferred sleep mode.
    HAL->>Driver:Getting the preferred sleep mode.
    Driver-->>HAL:return
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
    HAL-->>Caller:return
    Caller ->>HAL:dsHostTerm()
    HAL-->>Caller:return
 ```