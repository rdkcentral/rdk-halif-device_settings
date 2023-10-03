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
 * @defgroup devicesettings Device Settings
 * Describe the details about Device Settings HAL function specifications.
 *
 * <b> Following abbreviations present in HAL function </b>
 *
 * @par Abbreviations
 * - cb:      Callback function (suffix).
 * - DS:      Device Settings.
 * - HAL:     Hardware Abstraction Layer.
 * - FPS:     Frames Per Second.
 * - FRF:     TODO
 * - HDR:     High Dynamic Range
 * 
 * @ingroup DSSETTINGS_HAL
 */

/**
 * @file dsVideoDevice.h
 */

/**
 * @addtogroup HPK HPK
 * @{
 * @par The Hardware Porting Kit
 * HPK is the next evolution of the well-defined Hardware Abstraction Layer
 * (HAL), but augmented with more comprehensive documentation and test suites
 * that OEM or SOC vendors can use to self-certify their ports before taking
 * them to RDKM for validation or to an operator for final integration and
 * deployment. The Hardware Porting Kit effectively enables an OEM and/or SOC
 * vendor to self-certify their own Video Accelerator devices, with minimal RDKM
 * assistance.
 *
 */

/** @addtogroup DS_Manager_HAL DS Manager Hal
 * @par Application API Specification
 * Described herein are the DeviceSettings HAL types and functions that are part of
 * the Video Device subsystem. The Video Device subsystem manages system-specific HAL operations.
 *  @{
 */

/** @defgroup DSHAL_VIDEODEVICE_API Device Settings HAL Video Device Public API
 *
 *
 *  @{
 */


#ifndef _DS_VIDEODEVICE_H_
#define _DS_VIDEODEVICE_H_

#include <sys/types.h>
#include "dsError.h"
#include "dsTypes.h"


#ifdef __cplusplus
extern "C" {
#endif


/** @addtogroup DSHAL_VIDEODEVICE_API Device Settings HAL Video Device Public function
 *  @ingroup devicesettingshalapi
 *
 *  Described herein are the DeviceSettings HAL types and functions that are part of the
 *  Video Device subsystem. The Video Device subsystem manages video decoder HAL
 *  operations.
 *
 *  @{
 */

/**
 * @brief This function initialize all the video devices in the system.
 *
 * @return dsError_t                   - Status
 * @retval dsERR_NONE                   - Success
 * @retval dsERR_ALREADY_INITIALIZED    - Function is already initialized.
 * @retval dsERR_GENERAL                - Underlying undefined platform error
 *
 * @warning  This function is Not thread safe.
 * @see dsVideoDeviceTerm()
 * 
 * 
 */
dsError_t  dsVideoDeviceInit();


/**
 * @brief This function gets the handle for the video device requested.
 * 
 * @param[in]  index    - Index of video device. Max number is device specific. Min of 0.
 * @param[out] handle   - The handle used by Caller to uniquely identify the HAL instance
 * 
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsVideoDeviceInit() must be called before calling this function.
 * 
 * @warning  This function is Not thread safe.
* 
 * 
 */
dsError_t  dsGetVideoDevice(int index, int *handle);


/**
 * @brief This function is used to set the screen zoom mode (decoder format conversion).
 *
 * @param[in] handle    - The handle returned from the dsGetVideoDevice() function
 * @param[in] dfc       - Type of zoom mode to be used. See dsVideoZoom_t
 * 
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsVideoDeviceInit() must be called before calling this function.
 * 
 * @warning  This function is Not thread safe.
 * \
 * @see dsGetDFC()
 * 
 */
dsError_t  dsSetDFC(int handle, dsVideoZoom_t dfc);


/**
 * @brief This function is used to get the screen zoom mode (decoder format conversion).
 *
 * @param[in] handle    - The handle returned from the dsGetVideoDevice() function
 * @param[out] dfc      - Type of zoom mode to be used. See dsVideoZoom_t
 * 
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsVideoDeviceInit() must be called before calling this function.
 * 
 * @warning  This function is Not thread safe.
 * 
 * @see dsSetDFC()
 * 
 */
dsError_t  dsGetDFC(int handle, dsVideoZoom_t *dfc);


/**
 * @brief This function deinitialize all the video devices in the system.
 * This function reset any data structures used within this module and 
 *              release any handles specific to the video devices.
 *
 * @return dsError_t           - Status
 * @retval dsERR_NONE           - Success 
 * @retval dsERR_NOT_INITIALIZED- Module is not initialised
 * @retval dsERR_GENERAL        - General failure.
 * 
 * @pre dsVideoDeviceInit() must be called before calling this function.
 * 
 * @warning  This function is Not thread safe.
 * 
 * @see dsVideoDeviceInit()
 * 
 */
dsError_t  dsVideoDeviceTerm();
 

/**
 * @brief This function is used to get the HDR capabilities.
 *
 * @param[in]  handle       - The handle returned from the dsGetVideoDevice() function
 * @param[out] capabilities - OR-ed values of all supported HDR standards. See dsHDRStandard_t,
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsVideoDeviceInit() must be called before calling this function.
 * 
 * @warning  This function is Not thread safe.
 * 
 */
dsError_t dsGetHDRCapabilities(int handle, int *capabilities);


/**
 * @brief This function is used to get the video formats supported.
 *
 * @param[in]   handle              - The handle returned from the dsGetVideoDevice() function
 * @param[out]  supported_formats   - OR-ed values of all the supported video codec formats. 
 *                                          See dsVideoCodingFormat_t
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsVideoDeviceInit() must be called before calling this function.
 * 
 * @warning  This function is Not thread safe.
 * 
 */
dsError_t dsGetSupportedVideoCodingFormats(int handle, unsigned int * supported_formats);


/**
 * @brief This function is used to get the video codec information.
 *
 * @param[in]  handle   - The handle returned from the dsGetVideoDevice() function
 * @param[in]  codec    - OR-ed value of supported video codec formats. See dsVideoCodingFormat_t.
 * @param[out] info     - Structure containing Video codec information. See dsVideoCodecInfo_t
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsVideoDeviceInit() must be called before calling this function.
 * 
 * @warning  This function is Not thread safe.
 * 
 */
dsError_t dsGetVideoCodecInfo(int handle, dsVideoCodingFormat_t codec, dsVideoCodecInfo_t * info); 


/**
 * @brief This function is used to forcefully disable the HDR support of the device
 *
 * @param[in] handle    - The handle returned from the dsGetVideoDevice() function
 * @param[in] disable   - Boolean value to force disable HDR or not. 
 *                              True to force disable, false to remove force disable.
 * 
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsVideoDeviceInit() must be called before calling this function.
 * 
 * @warning  This function is Not thread safe.
 * 
 */
dsError_t dsForceDisableHDRSupport(int handle, bool disable);

/**
 * @brief This function is used to set the FRF mode of the device
 *
 * @param[in] handle    - The handle returned from the dsGetVideoDevice() function
 * @param[in] frfmode   - integer with corresponding Framerate value. 
 *                              Max framerate device specific. Min framerate is 0.
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsVideoDeviceInit() must be called before calling this function.
 * 
 * @warning  This function is Not thread safe.
 * 
 * @see dsGetFRFMode()
 * 
 */
dsError_t dsSetFRFMode(int handle, int frfmode);


/**
 * @brief This function is used to get the FRF mode of the device
 *
 * @param[in]  handle   - The handle returned from the dsGetVideoDevice() function
 * @param[out] frfmode  - integer with corresponding Framerate value of the device. 
 *                              Max framerate device specific. Min framerate is 0.
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsVideoDeviceInit() must be called before calling this function.
 * 
 * @warning  This function is Not thread safe.
 * 
 * @see dsSetFRFMode()
 * 
 */
dsError_t dsGetFRFMode(int handle, int *frfmode);

/**
 * @brief This function is used to get the current Framerate of the device
 *
 * @param[in]  handle       - The handle returned from the dsGetVideoDevice() function
 * @param[out] framerate    - Current frame rate will be represented in FPS. 
 *                                  Max Framerate is device specific. Min Framerate is 0.
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsVideoDeviceInit() must be called before calling this function.
 * 
 * @warning  This function is Not thread safe.
 * 
 * @see dsSetDisplayframerate()
 * 
 */
dsError_t dsGetCurrentDisplayframerate(int handle, char *framerate);
 

/**
 * @brief This function is used to set the display framerate for the device.
 *
 * @param[in] handle    - The handle returned from the dsGetVideoDevice() function
 * @param[in] framerate - Framerate value to be set frame will be represented in FPS. 
 *                                  Max Framerate is device specific. Min Framerate is 0.
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsVideoDeviceInit() must be called before calling this function.
 * 
 * @warning  This function is Not thread safe.
 * 
 * @see dsGetCurrentDisplayframerate()
 * 
 */
dsError_t dsSetDisplayframerate(int handle, char *framerate);

/**
 * @brief Call back function to receive the framerate change event form the HAL side.
 * @param [in] tSecond time elapsed after the change. Time in seconds.
 *
 */
typedef void (*dsRegisterFrameratePreChangeCB_t)(unsigned int tSecond);


/**
 * @brief This function is used to register the callback function for the Display framerate pre change event.
 *
 * @param[in] CBFunc    - Function callback to register for the event. 
 *                              See dsRegisterFrameratePreChangeCB_t.
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsVideoDeviceInit() must be called before calling this function.
 * 
 * @warning  This function is Not thread safe.
 * 
 */
dsError_t dsRegisterFrameratePreChangeCB(dsRegisterFrameratePreChangeCB_t CBFunc);


/**
 * @brief Call back function to receive the framerate change is event.
 * @param [in] tSecond time elapsed after the change.
 * 
 * @pre dsVideoDeviceInit() must be called before calling this function.
 *
 */
typedef void (*dsRegisterFrameratePostChangeCB_t)(unsigned int tSecond);


/**
 * @brief This function is used to register a callback function for the Display framerate 
 *                      post change event from the HAL side.
 *
 * @param[in] CBFunc    - Function to register for the event. 
 *                                  See dsRegisterFrameratePostChangeCB_t.
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsVideoDeviceInit() must be called before calling this function.
 * 
 * @warning  This function is Not thread safe.
 * 
 */
dsError_t dsRegisterFrameratePostChangeCB(dsRegisterFrameratePostChangeCB_t CBFunc);


/** @} */ // End of DSHAL_VIDEODEVICE_API doxygen group 
/** @} */ // End of DS HAL
/** @} */ // End of HPK

#ifdef __cplusplus
}
#endif
#endif /* _DS_VIDEODEVICE_H_ */