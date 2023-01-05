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
* @defgroup devicesettings Device Settings
* @{
* @defgroup hal Device Settings HAL
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
 * @return dsError_t - error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @warning  This API is Not thread safe.
 * @see dsVideoDeviceTerm()
 */
dsError_t  dsVideoDeviceInit();


/**
 * @brief This function gets the handle for the video device requested.
 *
 * @param[in]  index      Index of video device (0, 1, ...).
 * @param[out] handle     Video device handle for the specific index.
 *                         return.
 * @return dsError_t - error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid prameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsVideoDeviceInit() or  preceding dsVideoDeviceInit has failed
 * @pre dsVideoDeviceInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */
dsError_t  dsGetVideoDevice(int index, int *handle);


/**
 * @brief This function is used to set the screen zoom mode (decoder format conversion).
 * This function sets the screen zoom mode (Pan & Scan, LetterBox, PillarBox, etc.) for the specified video device.
 *
 * @param[in] handle  Handle of the video output port.
 * @param[in] dfc     Type of zoom mode to be used.
 * @return dsError_t - error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid prameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsVideoDeviceInit() or  preceding dsVideoDeviceInit has failed
 * @pre dsVideoDeviceInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetDFC()
 */
dsError_t  dsSetDFC(int handle, dsVideoZoom_t dfc);


/**
 * @brief This function is used to get the screen zoom mode (decoder format conversion).
 * This function Gets the screen zoom mode (None,Full ,Pan & Scan, LetterBox, PillarBox, etc.) for the specified video device.
 *
 * @param[in] handle  Handle of the video output port.
 * @param[out] dfc     Type of zoom mode to be used.
 * @return dsError_t - error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid prameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsVideoDeviceInit() or  preceding dsVideoDeviceInit has failed
 * @pre dsVideoDeviceInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetDFC()
 */
dsError_t  dsGetDFC(int handle, dsVideoZoom_t *dfc);


/**
 * @brief This function deinitialize all the video devices in the system.
 * It reset any data structures used within this module and release any handles specific to the video devices.
 *
 * @return dsError_t - error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid prameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsVideoDeviceInit() or  preceding dsVideoDeviceInit has failed
 * @pre dsVideoDeviceInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsVideoDeviceInit()
 */
dsError_t  dsVideoDeviceTerm();
 

/**
 * @brief To get the HDR capabilities of SoC
 * 
 * This function is used to get the HDR capabilities supported by the SoC
 *
 * @param[in] handle   Handle for the video device (video decoder)
 * @param [out] capabilities OR-ed values of all supported HDR standards as defined in dsHDRStandard_t
 *
 * @return dsError_t Error code.
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid prameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsVideoDeviceInit() or  preceding dsVideoDeviceInit has failed
 * @pre dsVideoDeviceInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */
dsError_t dsGetHDRCapabilities(int handle, int *capabilities);


/**
 * @brief To get the Video formats supported by the SoC.
 *
 * This function is used to get the video formats supported by the SoC.
 *
 * @param[in]   handle              Handle for the video device (video decoder)
 * @param [out]  supported_formats   OR-ed values of all the supported video codec formats as defined in dsVideoCodingFormat_t
 *
 * @return dsError_t - error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid prameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsVideoDeviceInit() or  preceding dsVideoDeviceInit has failed
 * @pre dsVideoDeviceInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */
dsError_t dsGetSupportedVideoCodingFormats(int handle, unsigned int * supported_formats);


/**
 * @brief This API is used to get the video codec information.
 *
 * @param[in]   handle  Handle for the video device (video decoder)
 * @param[in]   codec   OR-ed value of supported video codec formats.
 * @param [out]  info    Video codec information like profile, level etc.
 *
 * @return dsError_t - error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid prameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsVideoDeviceInit() or  preceding dsVideoDeviceInit has failed
 * @pre dsVideoDeviceInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */
dsError_t dsGetVideoCodecInfo(int handle, dsVideoCodingFormat_t codec, dsVideoCodecInfo_t * info); 


/**
 * @brief This API is used to forcefully disable the HDR support of the device
 *
 * @param[in]   handle  Handle for the video device (video decoder)
 * @param[in]   disable Boolean value to force diableHDR or not.
 *
 * @return dsError_t - error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid prameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsVideoDeviceInit() or  preceding dsVideoDeviceInit has failed
 * @pre dsVideoDeviceInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */
dsError_t dsForceDisableHDRSupport(int handle, bool disable);

/**
 * @brief This API is used to set the FRF mode of the device
 *
 * @param[in]   handle  Handle for the video device (video decoder)
 * @param[in]   frfmode integer with corresponding Framerate value.
 *
 * @return dsError_t - error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid prameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsVideoDeviceInit() or  preceding dsVideoDeviceInit has failed
 * @pre dsVideoDeviceInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetFRFMode()
 */
dsError_t dsSetFRFMode(int handle, int frfmode);


/**
 * @brief This API is used to get the FRF mode of the device
 *
 * @param[in]   handle  Handle for the video device (video decoder)
 * @param [out]  frfmode integer with corresponding Framerate value of the device.
 *
 * @return dsError_t - error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid prameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsVideoDeviceInit() or  preceding dsVideoDeviceInit has failed
 * @pre dsVideoDeviceInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetFRFMode()
 */
dsError_t dsGetFRFMode(int handle, int *frfmode);

/**
 * @brief This API is used to get the current Framerate of the device
 *
 * @param[in]   handle  Handle for the video device (video decoder)
 * @param [out]  framerate Byte with corresponding freamrate value of the device.
 *
 * @return dsError_t - error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid prameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsVideoDeviceInit() or  preceding dsVideoDeviceInit has failed
 * @pre dsVideoDeviceInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetDisplayframerate()
 */
dsError_t dsGetCurrentDisplayframerate(int handle, char *framerate);
 

/**
 * @brief This API is used to set the display framerate for the device.
 *
 * @param[in]  handle  Handle for the video device (video decoder)
 * @param[in]  framerate Provides the display framerate value to be set.
 *
 * @return dsError_t - error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid prameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsVideoDeviceInit() or  preceding dsVideoDeviceInit has failed
 * @pre dsVideoDeviceInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetCurrentDisplayframerate()
 */
dsError_t dsSetDisplayframerate(int handle, char *framerate);

/**
 * @brief Call back function to receive the framerate change event form the HAL side.
 * @param [in] tSecond time elapsed after the change.
 *
 */
typedef void (*dsRegisterFrameratePreChangeCB_t)(unsigned int tSecond);


/**
 * @brief This API is used to register the callback funciton for the Display framerate pre change event.
 *
 * @param[in]   CBFunc  Function callback to register for the event.
 *
 * @return dsError_t - error code
 * @retval dsERR_NONE Indicates the call was successful
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid prameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsVideoDeviceInit() or  preceding dsVideoDeviceInit has failed
 * @pre dsVideoDeviceInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */
dsError_t dsRegisterFrameratePreChangeCB(dsRegisterFrameratePreChangeCB_t CBFunc);


/**
 * @brief Call back function to receive the framerate change is event.
 * @param [in] tSecond time elapsed after the change.
 *
 */
typedef void (*dsRegisterFrameratePostChangeCB_t)(unsigned int tSecond);


/**
 * @brief This API is used to register a callback funciton for the Display framerate post change event from the HAL side.
 *
 * @param[in]   CBFunc  Function to register for the event.
 *
 * @return dsError_t - error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid prameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsVideoDeviceInit() or  preceding dsVideoDeviceInit has failed
 * @pre dsVideoDeviceInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */
dsError_t dsRegisterFrameratePostChangeCB(dsRegisterFrameratePostChangeCB_t CBFunc);


/* End of DSHAL_VIDEODEVICE_API doxygen group */
/**
 * @}
 */
#ifdef __cplusplus
}
#endif
#endif /* _DS_VIDEODEVICE_H_ */


/** @} */
/** @} */
