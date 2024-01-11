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
 * @file dsVideoDevice.h
 */



/**
* @defgroup devicesettings
* @{
* @defgroup hal
* @{
**/


#ifndef _DS_VIDEODEVICE_H_
#define _DS_VIDEODEVICE_H_

#include <sys/types.h>
#include "dsError.h"
#include "dsTypes.h"


#ifdef __cplusplus
extern "C" {
#endif


/** @addtogroup DSHAL_VIDEODEVICE_API Device Settings HAL Video Device Public API
 *  @ingroup devicesettingshalapi
 *
 *  Described herein are the DeviceSettings HAL types and functions that are part of the
 *  Video Device subsystem. The Video Device subsystem manages video decoder hardware
 *  operations.
 *
 *  @{
 */

/**
 * @brief This function initialize all the video devices in the system.
 *
 * @return dsError_t
 * @retval dsERR_NONE If sucessfully dsVideoDeviceInit api has been called using IARM support.
 * @retval dsERR_GENERAL General failure.
 */
dsError_t  dsVideoDeviceInit();

/**
 * @brief This function gets the handle for the video device requested.
 *
 * @param[in]  index      Index of video device (0, 1, ...).
 * @param[out] handle    The address of a location to hold the video device handle on
 *                         return.
 * @return dsError_t
 * @retval dsERR_NONE If sucessfully dsGetVideoDevice api has been called using IARM support.
 * @retval dsERR_GENERAL General failure.
 */
dsError_t  dsGetVideoDevice(int index, intptr_t *handle);

/**
 * @brief This function is used to set the screen zoom mode (decoder format conversion).
 * This function sets the screen zoom mode (Pan & Scan, LetterBox, PillarBox, etc.) for the specified video device.
 *
 * @param[in] handle  Handle of the video output port.
 * @param[in] dfc     Type of zoom mode to be used.
 * @return dsError_t
 * @retval dsERR_NONE If sucessfully dsSetDFC api has been called using IARM support.
 * @retval dsERR_GENERAL General failure.
 */
dsError_t  dsSetDFC(intptr_t handle, dsVideoZoom_t dfc);

/**
 * @brief This function is used to get the screen zoom mode (decoder format conversion).
 * This function Gets the screen zoom mode (None,Full ,Pan & Scan, LetterBox, PillarBox, etc.) for the specified video device.
 *
 * @param[in] handle  Handle of the video output port.
 * @param[in] dfc     Type of zoom mode to be used.
 * @return dsError_t
 * @retval dsERR_NONE If sucessfully dsGetDFC api has been called using IARM support.
 * @retval dsERR_GENERAL General failure.
 */
dsError_t  dsGetDFC(intptr_t handle, dsVideoZoom_t *dfc);

/**
 * @brief This function deinitialize all the video devices in the system.
 * It reset any data structures used within this module and release any handles specific to the video devices.
 *
 * @return dsError_t
 * @retval dsERR_NONE If sucessfully dsVideoDeviceTerm has been called using IARM support.
 * @retval dsERR_GENERAL General failure.
 */
dsError_t  dsVideoDeviceTerm();
/**
 * @brief To find the HDR capabilities of SoC
 * 
 * This function is used to check which HDR capabilities the SoC supports
 *
 * @param [in] handle   Handle for the video device (video decoder)
 * @param [out] *capabilities OR-ed value of supported HDR standards.
 * @return dsError_t Error code.
 */
dsError_t dsGetHDRCapabilities(intptr_t handle, int *capabilities);

/**
 * @brief To find the Video formats supported by the SoC.
 *
 * This function is used to check which video formats the SoC supports
 *
 * @param [in]   handle              Handle for the video device (video decoder)
 * @param [out]  supported_formats   OR-ed value of supported video codec formats.
 *
 * @return dsError_t Error code.
 */
dsError_t dsGetSupportedVideoCodingFormats(intptr_t handle, unsigned int * supported_formats);

/**
 * @brief This API is used to get the video codec information.
 *
 * @param [in]   handle  Handle for the video device (video decoder)
 * @param [in]   codec   OR-ed value of supported video codec formats.
 * @param [out]  info    Video codec information like profile, level etc.
 *
 * @return dsError_t Error code.
 */
dsError_t dsGetVideoCodecInfo(intptr_t handle, dsVideoCodingFormat_t codec, dsVideoCodecInfo_t * info);

dsError_t dsForceDisableHDRSupport(intptr_t handle, bool disable);

/* End of DSHAL_VIDEODEVICE_API doxygen group */
/**
 * @}
 */
dsError_t dsSetFRFMode(intptr_t handle, int frfmode);
dsError_t dsGetFRFMode(intptr_t handle, int *frfmode);
dsError_t dsGetCurrentDisplayframerate(intptr_t handle, char *framerate);
dsError_t dsSetDisplayframerate(intptr_t handle, char *framerate);

typedef void (*dsRegisterFrameratePreChangeCB_t)(unsigned int tSecond);
dsError_t dsRegisterFrameratePreChangeCB(dsRegisterFrameratePreChangeCB_t CBFunc);

typedef void (*dsRegisterFrameratePostChangeCB_t)(unsigned int tSecond);
dsError_t dsRegisterFrameratePostChangeCB(dsRegisterFrameratePostChangeCB_t CBFunc);
#ifdef __cplusplus
}
#endif
#endif /* _DS_VIDEODEVICE_H_ */


/** @} */
/** @} */
