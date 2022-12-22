# Device Settings HAL Documentation

# History

|Version|Date|Author|
|-------|-----|-----|
|1.0.0| 22/12/22 (Reverse Date)|Akhil Baby sarada|

1.0.0 Intial version of the Device settngs HAL layer documentation.

# Description

Device Settings HAL provides a set of API's to initialize following modules and driver and communicate with peripheral devices like Front Pane displlay, Video Ports, Audio Ports etc. HAL Api's curresponds to each functionality and status of the devices and modules. teh APIs are provided to initlaize, select specific device using its handle and set or get a specific property of the device.  

The diagram below describes a high-level software architecture of the Devicesettings module stack. We have ds manager acting as the middleman between the hal and applicaton inteface or thunder layer. All teh initialization and deinitialization will be done by dsmanager. Hal layer provides the apis to dsManager to help to communicate with the SOC specific libraries. HAL acts as a single abstraction layer for multiple SOC libraries for multiple platforms.  

Device Settings Architecture Diag

# Component Runtime Execution Requirements

The Harware layer API's are provided by each SOC vendors specific to the device. the operations should be completed within 5 sec otherwise the dsmanager Iarm calls will fail due to timeout. Any operations that may take more than 5 sec shoudl be done in a parellel thread.

Failure to meet these requirements will likely result in undefined and
unexpected behaviour.

## Initialization and Startup

Intialization is expected to be done from dsmanger using Device::Manager::Initialize call.


## Threading Model

Device settings HAL is not thread safe, any module which is invoking the DeviceSettings HAL api should ensure calls are made in a thread safe manner.

All thread should be correctly terminated when deinitialize() is called.

## Process Model

dsMgr process takes care of Initializing Device Settings HAL component. At any point of time a single instance of dsMgr process exists to respond to any device settings related functionality to the application. The interface implementation should not manipulate any process-wide state, such as the current directory, locale, etc. Doing so could have unintended consequences for other threads within the process group.


## Memory Model

dsMgr service  is responsible to pass message buffer and free it. 

## Power Management Requirements

powerManager is responsible for communicating with dsMgr to shut down/ startup the modules and peripherels as per teh requirement. 

## Asynchronous Notification Model

Asynchronus call backs are supported for specific functionlities like HDMI hotplug event or Audio port change etc. 
Asynchronus call should be handled by call backs

## Internal Error Handling

All the Device Settings HAL API's should return error synchronously as a return argument. HAL is responsible to handle system errors(e.g. out of memory) internally.

## Persistence Model
There is no requirement for HAL to persist any setting information. Application/Client is responsible to persist any settings related to Device Settings feature.

# Non functional requirements

## Logging and debugging requirements
Device Settings HAL component should log all the error and critical informative messages which helps to debug/triage the issues and understand the functional flow of the system.

## Memory and performance requirements


## Quality Control
Device Settings HAL implementation should pass Coverity, Black duck scan, valgrind checks without any issue.

There should not be any memory leaks/corruption introduced by HAL and underneath 3rd party software implementation.

//ToDo: HAL implementation should pass RDK DSevice settnigs HAL available at: 

## Licensing

Device Settings HAL implementation is expected to released under the Apache License.

## Build Requirements

Device Settings HAL source code should be build under Linux Yocto environment and should be delivered as a shared library.

## Variability Management
Anyy new API introduced should be implemented by all the 3rd party module and RDK generic code should be compatible with specific version of device settings HAL software

## Platform or Product Customization

None

# Interface API Documentation

Covered as per Doxygen documentations.

## Theory of operation and key concepts
device Settings HAL API is initialized by dsMgr module. RDK-V middleware expected to have complete control over the life cycle over the Device settings HAL module.

Initialize the modules using function: Init() before making any other Module API calls. This call does the module initialization. If Init() calls fails, HAL should return the respective error code, so that the client can retry the operation.

Once intializtion is success. Device settings module should able to set or get teh peripherel properties and functionalities.

Finally close the DeviceSettings using the HAL api: DeInit()
