# Device Settings HAL Documentation

# History

|Version|Date|Author|
|-------|-----|-----|
|1.0.0| 22/12/22 (Reverse Date)|Akhil Baby Sarada|

1.0.0 Initial version of the Device settings HAL layer documentation.

# Description

Device Settings HAL provides a set of APIs to initialize following modules and driver and communicate with peripheral devices like Front Pane display, Video Ports, Audio Ports etc. HAL APIs corresponds to each functionality and status of the devices and modules. the APIs are provided to initialize, select specific device using its handle and set or get a specific property of the device.  

The diagram below describes a high-level software architecture of the Device settings module stack. We have ds manager acting as the middleman between the hal and application interface or thunder layer. All the initialization and deinitialization will be done by ds manager. Hal layer provides the APIs to ds manager to help to communicate with the SOC specific libraries. HAL acts as a single abstraction layer for multiple SOC libraries for multiple platforms.  

Device Settings Architecture Diagram

# Component Runtime Execution Requirements

The Hardware layer API's are provided by each SOC vendors specific to the device. the operations should be completed in reasonable time and max time allowed is 5 sec otherwise the ds manager IARM calls will fail with error timeout. Any operations that may take more than 5 sec should be done in a parallel thread.

Failure to meet these requirements will likely result in undefined and
unexpected behavior.

## Initialization and Startup

Initialization is expected to be done from ds manger using Device::Manager::Initialize call.

## Threading Model

Device settings HAL is not thread safe, any module which is invoking the Device Settings HAL API should ensure calls are made in a thread safe manner.

All thread should be correctly terminated when module terminate is called.

## Process Model

dsMgr process takes care of Initializing Device Settings HAL component. At any point of time a single instance of dsMgr process exists to respond to any device settings related functionality to the application. The interface implementation should not manipulate any process-wide state, such as the current directory, locale, etc. Doing so could have unintended consequences for other threads within the process group.

## Memory Model

dsMgr service is responsible to pass message buffer and free it. 

## Power Management Requirements

power manager is responsible for communicating with dsMgr to shut down/ startup the modules and peripherals as per the requirement. 

## Asynchronous Notification Model

Asynchronous call backs are supported for specific functionalities like HDMI hot plug event or Audio port change etc. 
Asynchronous call should be handled by call backs

## Internal Error Handling

All the Device Settings HAL API's should return error synchronously as a return argument. HAL is responsible to handle system errors (e.g. out of memory) internally.

## Persistence Model
There is no requirement for HAL to persist any setting information. Application/Client is responsible to persist any settings related to Device Settings feature.

# Nonfunctional requirements

## Logging and debugging requirements
Device Settings HAL component should log all the error and critical informative messages which helps to debug/triage the issues and understand the functional flow of the system.

## Memory and performance requirements

## Quality Control
Device Settings HAL implementation should pass Coverity, Black duck scan, Valgrind checks without any issue.

There should not be any memory leaks/corruption introduced by HAL and underneath 3rd party software implementation.

//ToDo: HAL implementation should pass RDK Device settings HAL available at: 

## Licensing

Device Settings HAL implementation is expected to release under the Apache License.

## Build Requirements

Device Settings HAL source code should be built under Linux Yocto environment and should be delivered as a shared library.

## Variability Management
Any new API introduced should be implemented by all the 3rd party module and RDK generic code should be compatible with specific version of device settings HAL software

## Platform or Product Customization

None

# Interface API Documentation

Covered as per Doxygen documentations.

## Theory of operation and key concepts
device Settings HAL API is initialized by dsMgr module. RDK-V middleware expected to have complete control over the life cycle over the Device settings HAL module.

Initialize the modules using function: Init() before making any other Module API calls. This call does the module initialization. If Init() calls fails, HAL should return the respective error code, so that the client can retry the operation.

Once initialization is success. Device settings module should able to set or get the peripheral properties and functionalities.

Finally close the Device Settings using the HAL API: Term()

