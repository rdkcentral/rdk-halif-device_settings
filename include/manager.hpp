/*
 * If not stated otherwise in this file or this component's Licenses.txt file the
 * following copyright and licenses apply:
 *
 * Copyright 2016 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

/**
 * @defgroup DSSETTINGS Device Settings Module
 * RDK Device Settings library is a cross-platform library for controlling the following hardware configurations:
 * - Audio Output Ports (Volume, Mute, etc.)
 * - Video Ouptut Ports (Resolutions, Aspect Ratio, etc.)
 * - Front Panel Indicators
 * - Zoom Settings
 * - Display (Aspect Ratio, EDID data etc.)
 * - General Host configuration (Power managements, event management etc.)
 *
 * The library is split into three major components
 *  - Application Level APIs. (Comcast component)
 *  - SoC level APIs. (SoC component)
 *  - IARM support. (Comcast Component)
 *
 * @par Application Level API
 * This is the API that application should use to control hardware configurations in a platform independent way.
 * It also hides single-app and multi-app difference of the implementation from the applications.
 * This allows the application to switch among different SoC versions or between single or multi app mode freely.
 * Eg : API to get the current video resolution : const VideoResolution & VideoOutputPort::getResolution() const
 *
 * @par SoC Level API
 * SoC Level APIs that that need to implement by SoC vendors.
 * It provides primitive and hardware specific implementation  for each controllable aspect of their device.
 * This level API is considered single-app mode only, even though its SoC implementation may potentially support
 * multiple-app mode.
 * Eg: API to get the current video resolution : dsError_t dsGetResolution ( int handle, dsVideoPortResolution_t *resolution )
 *
 * @par IARM Support
 * If multiple applications need to control the device settings simultaneously, this component turns the single-app
 * mode SoC level API into multi-app mode.
 * Even though some SoC vendors implement the SoC level API to be multi-app capable, we still use Comcast’s IARM
 * support to achieve multiple-app mode. This allows the Application level API to remain truly platform neutral.
 *
 * @par Architectural Overview
 * The Device Settings (DS) registers its services with the service manager.
 * The Application uses/calls the DS Public API through service manager and DS Public API’s intern calls the
 * underlying SoC level API’s to perform the required functionality.
 *
 * @image html dsArch.png
 *
 * @defgroup devicesettingsclass Device Settings Classes
 * @ingroup DSSETTINGS
 */


/**
 * @defgroup devicesettingsapi Device Settings API list
 * Described the details about Public APIs provided by Device Settings module
 * @ingroup DSSETTINGS
 *
 * @defgroup dssettingsmanagerapi Device Settings - Manager APIs
 * RDK Device Settings module is a cross-platform device for controlling the following hardware configurations:
 * - Audio Output Ports (Volume, Mute, etc.)
 * - Video Ouptut Ports (Resolutions, Aspect Ratio, etc.)
 * - Front Panel Indicators such as DFC[zoom] Settings,  Display (Aspect Ratio, EDID data etc.),
 *  General Host configuration (Power managements, event management etc.)
 * @ingroup devicesettingsapi
 *
 * @defgroup dssettingshostapi Device Settings - Host APIs
 * The host module is the central module of the Device Settings module.
 * Each devices establishes one and only one host instance that represents the entire host device.
 * @ingroup devicesettingsapi
 *
 * @defgroup dssettingsvideodeviceapi Device Settings - Video Device APIs
 * - Video Device is also called "Decoder". VideoDevice objects are instantiated by the
 * Device Settings module upon initialization.
 * - Applications do not need to create any such objects on its own.
 * - References to these objects can be retrieved by applications via Host::getVideoDevices()
 * @ingroup devicesettingsapi
 *
 * @defgroup dssettingsvidoutportapi Device Settings - Video Output Port APIs
 * - VideoOutputPort objects are instantiated by the Device Settings module upon initialization.
 * Applications do not need to create any such objects on its own. 
 * - References to the preallocated objects can be retrieved by applications via 
 * Host::getVideoOutputPort(const std::string &name).
 * - Each VideoOutputPort is associated with an instance of VideoOutputPortType.
 * @ingroup devicesettingsapi
 *
 * @defgroup dssettingsvidoutporttypeapi Device Settings - Video Output Port Types APIs
 * - VideoOutputPortType objects are instantiated by the Device Settings module upon initialization.
 * - Applications do not need to create any such objects on its own.
 * - References to these objects can be retrieved using a VideoOutputPort object invoking VideoOutputPort::getType().
 * - A VideoOutputPortType object represent the shared properties of all output ports of same type.
 * - Control over a specific instance of Video Output Port is access over a Video Output Port object
 * @ingroup devicesettingsapi
 *
 * @defgroup dssettingsvidresolutionapi Device Settings - Video Resolution APIs
 * This defines the videoResolution objects by the device settings module upon intialization.
 * @ingroup devicesettingsapi
 *
 * @defgroup dssettingsaudoutportapi Device Settings - Audio Output Port APIs
 * - AudioOutputPort objects are instantiated by the Device Settings module upon initialization.
 * - Applications do not need to create any such objects on its own.
 * - References to these objects can be retrieved by applications via the VideoOutputPort
 * - connected to the AudioOutputPort: VideoOutputPort::getAudioOutputPort()
 * @ingroup devicesettingsapi
 *
 * @defgroup dssettingsaudoutporttypeapi Device Settings - Audio Outport Types APIs
 * - AudioOutputPortType objects are instantiated by the Device Settings module upon initialization.
 * - Applications do not need to create any such objects on its own.
 * - References to these objects can be retrieved using a AudioOutputPort object invoking AudioOutputPort::getType()
 * @ingroup devicesettingsapi
 *
 * @defgroup dssettingsfpindicatorapi Device Settings - Front Panel Indicator APIs
 * Configuration of individual indicators are managed here. The blink rate, color, and maximum
 * cycle rate of the front panel indicator can be configured.
 * @ingroup devicesettingsapi
 *
 * @defgroup dssettingsfptextdisplayapi Device Settings - Front Panel text display APIs
 * Configuration of individual text display sub-panel to display system time or text is managed here.
 * The scroll speed, time format (12Hour or 24 Hour format) and a string to display can be configured.
 * @ingroup devicesettingsapi
 *
 * @defgroup dssettingsaudencodingapi Device Settings - Audio Encoding APIs
 * This contains implementation of AudioEncoding class methods, support functions and
 * variable assignments to manage the audio encoding types.
 * @ingroup devicesettingsapi
 */


/**
* @defgroup devicesettings
* @{
* @defgroup ds
* @{
**/


#ifndef _DS_MANAGER_HPP_
#define _DS_MANAGER_HPP_


/**
 * @file manager.hpp
 * @brief It contains class referenced by manager.cpp file
 */
namespace device {


/**
 * @class Manager
 * @brief Class to implement the manager interface.
 * @ingroup devicesettingsclass
 */
class Manager {
	Manager();
	virtual ~Manager();
public:
	static void Initialize();
	static void DeInitialize();
	static int IsInitialized;   //!< Indicates the application has initialized with devicettings modules.
};

}

#endif /* _DS_MANAGER_HPP_ */


/** @} */
/** @} */
