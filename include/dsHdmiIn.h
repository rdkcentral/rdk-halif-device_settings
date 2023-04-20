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
/*
 * If not stated otherwise in this file or this component's Licenses.txt file the
 * following copyright and licenses apply:
 *
 * Copyright ARRIS Enterprises, Inc. 2015.
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
 * limitations under
*/
 
/**
 * @file dsHdmiIn.h
 *
 * @brief Device Settings HAL HDMI Input Public API.
 * This API defines the HAL for the Device Settings HDMI Input interface.
 *
 * @par Document
 * Document reference.
 *
 * @par Open Issues (in no particular order)
 * -# None
 *
 * @par Assumptions
 * -# None
 *
 * @par Abbreviations
 * - cb:      Callback function (suffix).
 * - DS:      Device Settings.
 * - HAL:     Hardware Abstraction Layer.
 * - _t:      Type (suffix).
 * - EDID:    Extended Display Identification Data.
 * - SPD:     Surge Protector Device.
 * - ARC:     Audio Return Channel.
 * - ALLM:    Auto Low Latency Mode
 * - HDMI:    High-Definition Multimedia Interface
 *
 * @par Implementation Notes
 * -# None
 *
 */

/**
* @defgroup devicesettings Device Settings
* @{
* @defgroup hal Device Settings HAL
* @{
**/

#ifndef _DS_dsHdmiInH_
#define _DS_dsHdmiInH_

#include <sys/types.h>
#include "dsError.h"
#include "dsTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup DSHAL_HdmiIn_API Device Settings HAL HDMI Input Public APIs
 *  @ingroup devicesettingshalapi
 *  @{
 */

/**
 * @brief Initializes the HDMI Input Hal.
 *
 *
 * @return dsError_t            - Status
 * @retval dsERR_NONE           - Success
 * @retval dsERR_INVALID_STATE  - Function is already initialized.
 * @retval dsERR_GENERAL        - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsHdmiInTerm()
 */

dsError_t dsHdmiInInit (void);

/**
 * @brief Terminate the underlying HDMI Input sub-system.
 * 
 * This function must terminate the HDMI Input module and any associated data
 * structures.
 *
 * @return dsError_t            - Status
 * @retval dsERR_NONE           - Success
 * @retval dsERR_INVALID_STATE  - Module is not initialised
 * @retval dsERR_GENERAL        - Underlying undefined platform error
 * 
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsHdmiInInit()
 */

dsError_t dsHdmiInTerm (void);

/**
 * @brief This function is used to get the number of HDMI Input ports on the set-top.
 *
 * @param[out] pNumberOfInputs  - number of HDMI Input ports. 
 *                                  Max number of inputs is platform specific.
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 */

dsError_t dsHdmiInGetNumberOfInputs (uint8_t *pNumberOfInputs);

/**
 * @brief This function is used to get the current HDMI Input Status.
 *
 * @param[out] pStatus  - current status of the HdmiInput port. See dsHdmiInStatus_t
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 */

dsError_t dsHdmiInGetStatus (dsHdmiInStatus_t *pStatus);

/**
 * @brief This function is used to select the HDMI Input port for presentation.
 *
 * @param[in] ePort     - HDMI Input port to be presented. See dsHdmiInPort_t
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported.
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 */

dsError_t dsHdmiInSelectPort (dsHdmiInPort_t ePort);

/**
 * @brief Scale the HDMI In video
 * This function is used to scale the HDMI In video.
 *
 * @param[in] x         - x coordinate for the video
 * @param[in] y         - y coordinate for the video
 * @param[in] width     - width of the video. Width in pixels.
 * @param[in] height    - height of the video. Height in pixels.
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsHdmiInScaleVideo (int32_t x, int32_t y, int32_t width, int32_t height);

/**
 * @brief This function is used to select the HDMI Input zoom mode.
 *
 * @param[in] requestedZoomMode     - HDMI Input zoom mode. See dsVideoZoom_t
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 */

dsError_t dsHdmiInSelectZoomMode (dsVideoZoom_t requestedZoomMode);

/**
 * @brief This function stops sending the HDMI Input audio to the HDMI Out.
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 */

dsError_t dsHdmiInPauseAudio (void);

/**
 * @brief This function presents the HDMI Input audio via HDMI Out.
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 */

dsError_t dsHdmiInResumeAudio (void);

/**
 * @brief This function gets the current HDMI Input video mode.
 *
 * @param[out] resolution       - current HDMI Input video mode resolution. 
 *                                      See dsVideoPortResolution_t
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 */

dsError_t dsHdmiInGetCurrentVideoMode (dsVideoPortResolution_t *resolution);

/**
 * @brief HAL must call this function when the HDMI in port connection status changes.
 *
 * @param[in] Port              - Port id where connection status is changed. See dsHdmiInPort_t
 * @param[in] isPortConnected   - Port connection status. True if connected, false if not.
 *
 */
typedef void (*dsHdmiInConnectCB_t)(dsHdmiInPort_t Port, bool isPortConnected);

/**
 * @brief HAL must call this function when the HDMI In signal status changes.
 * 
 * @param[in] port      - Port id where signal status is changed. See dsHdmiInPort_t
 * @param[in] sigStatus - Current signal status of the port. See dsHdmiInSignalStatus_t
 *
 */
typedef void (*dsHdmiInSignalChangeCB_t)(dsHdmiInPort_t port, dsHdmiInSignalStatus_t sigStatus);

/**
 * @brief HAL must call this function when the HDMI Input status changes.
 *
 * HAL Implementation must call this method to deliver HDMI Input status
 * to the Caller whenever the HDMI Input status changes.
 * 
 * @param[in] inputStatus   - Present hdmi input status. See dsHdmiInStatus_t
 *
 */

typedef void (*dsHdmiInStatusChangeCB_t)(dsHdmiInStatus_t inputStatus);

/**
 * @brief HAL must call this function when the HDMI In video mode changes.
 *
 * HAL Implementation must call this method to deliver updated HDMI In video mode info
 * to the Caller
 *
 * @param[in] port              - Port in which video mode updated. See dsHdmiInPort_t
 * @param[in] videoResolution   - current video resolution of the port. See dsVideoPortResolution_t
 *
 */

typedef void (*dsHdmiInVideoModeUpdateCB_t)(dsHdmiInPort_t port, dsVideoPortResolution_t videoResolution);

/**
 * @brief HAL must call this function when the HDMI Input ALLM mode changes.
 *
 * @param[in] port      - Hdmi port number in which ALLM Mode changed. See dsHdmiInPort_t
 * @param[in] allm_mode - Current ALLM mode of the port. True if the port is in ALLM mode, false if not.
 *
 */

typedef void (*dsHdmiInAllmChangeCB_t)(dsHdmiInPort_t port, bool allm_mode);

/**
 * @brief This function is used to register a callback for the 
 *              HDMI Input hot plug event notification from the HAL side.
 *
 * @param[in] CBFunc    - HDMI Input hot plug callback function. See dsHdmiInConnectCB_t
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 */

dsError_t dsHdmiInRegisterConnectCB (dsHdmiInConnectCB_t CBFunc);

/**
 * @brief This function is used to register a callback for the HDMI Input Signal Change event.
 *
 * @param[in] CBFunc    - HDMI Input Signal change callback function. See dsHdmiInSignalChangeCB_t
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 */

dsError_t dsHdmiInRegisterSignalChangeCB (dsHdmiInSignalChangeCB_t CBFunc);

/**
 * @brief This function is used to register a callback for the HDMI Input Status Change event.
 *               See dsHdmiInStatus_t.
 *
 * @param[in] CBFunc    - HDMI Input Status change callback function. See dsHdmiInStatusChangeCB_t
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 */

dsError_t dsHdmiInRegisterStatusChangeCB (dsHdmiInStatusChangeCB_t CBFunc);

/**
 * @brief This function is used to register a callback for the HDMI Input video mode Change event. 
 *                  The mode change is triggered whenever the video resolution changes.
 *
 * @param[in] CBFunc    - HDMI Input video mode change callback function. 
 *                              See dsHdmiInVideoModeUpdateCB_t
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 */

dsError_t dsHdmiInRegisterVideoModeUpdateCB(dsHdmiInVideoModeUpdateCB_t CBFunc);

/**
 * @brief This function is used to register a callback for the HDMI Input ALLM Mode Change event.
 *
 * @param[in] CBFunc    - HDMI Input ALLM Mode change callback function. 
 *                              See dsHdmiInAllmChangeCB_t
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 */

dsError_t dsHdmiInRegisterAllmChangeCB (dsHdmiInAllmChangeCB_t CBFunc);

/**
 * @brief This function is used to check the availability of the 
 *              HDMI Arc port in the respective platform.
 *
 * @param[in] iPort - HDMI Arc port. Max value is device specific. Min value of 0.
 *
 * @return Boolean  - ARC support
 * @retval True     - Port supports ARC
 * @retval False    - Port does not support ARC
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 */

bool dsIsHdmiARCPort (int iPort);

/**
 * @brief This function is used to get the EDID bytes info event form the connected display.
 *
 * @param[in] iHdmiPort     - HDMI Input port. Max value is device specific. Min value of 0.
 * @param[out] edid         - EDID data for which info is required
 * @param[out] length       - length of the EDID data. Min value of 0.
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 */

dsError_t dsGetEDIDBytesInfo (int iHdmiPort, unsigned char **edid, int *length);

/**
 * @brief his function is used to get the HDMI SPD info.
 *
 * @param[in] iHdmiPort     - HDMI Input port. Max value is device specific. Min value of 0.
 * @param[out] data         - HDMI SPD info data to get
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 */

dsError_t dsGetHDMISPDInfo (int iHdmiPort, unsigned char **data);

/**
 * @brief This function is used to set the EDID version info
 *
 * @param[in] iHdmiPort     - HDMI input port. Max value is device specific. Min value of 0.
 * @param[in] iEdidVersion  - Input EDID version number to set
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetEdidVersion()
 */

dsError_t dsSetEdidVersion (int iHdmiPort, int iEdidVersion);

/**
 * @brief This function is used to get the EDID version info
 *
 * @param[in] iHdmiPort     - HDMI input port. Max value is device specific. Min value of 0.
 * @param[out] iEdidVersion - input EDID version number to get.
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetEdidVersion()
 */

dsError_t dsGetEdidVersion (int iHdmiPort, int *iEdidVersion);

/**
 * @brief This function is used to get the allm status details of the specific port
 *
 * @param[in] iHdmiPort     - HDMI input port. Max value is device specific. Min value of 0.
 * @param[out] allmStatus   - allmstatus. True if enabled, false if not.
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 */

dsError_t dsGetAllmStatus (int iHdmiPort, bool *allmStatus);

/**
 * @brief This function is used to get all the supported game features list information.
 *
 * @param[out] features         - List of all supported game features. 
 *                                      See dsSupportedGameFeatureList_t
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 */

dsError_t dsGetSupportedGameFeaturesList (dsSupportedGameFeatureList_t* features);

/* End of DSHAL_HdmiIn_API doxygen group */
/**
 * @}
 */

#ifdef __cplusplus
}
#endif
#endif /* _DS_dsHdmiInH_ */

/** @} */
/** @} */
