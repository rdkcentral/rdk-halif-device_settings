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
 * - BE:      Big-Endian.
 * - cb:      Callback function (suffix).
 * - DS:      Device Settings.
 * - FPD:     Front-Panel Display.
 * - HAL:     Hardware Abstraction Layer.
 * - LE:      Little-Endian.
 * - LS:      Least Significant.
 * - MBZ:     Must be zero.
 * - MS:      Most Significant.
 * - RDK:     Reference Design Kit.
 * - _t:      Type (suffix).
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
 * @brief Initialize the underlying HDMI Input sub-system.
 * 
 * This function must initialize the HDMI Input module and any associated data
 * structures.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this value. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @warning  This API is Not thread safe.
 * @see dsHdmiInTerm()
 */

dsError_t dsHdmiInInit (void);

/**
 * @brief Terminate the underlying HDMI Input sub-system.
 * 
 * This function must terminate the HDMI Input module and any associated data
 * structures.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this value. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @pre dsHdmiInInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsHdmiInInit()
 */

dsError_t dsHdmiInTerm (void);

/**
 * @brief Get the number of HDMI Input ports on the set-top.
 * 
 * This function is used to get the number of HDMI Input ports on the set-top.
 *
 * @param[out] pNumberOfInputs   number of HDMI Input ports.
 * 
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsHdmiInInit() or  preceding dsHdmiInInit has failed
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this value. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @pre dsHdmiInInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsHdmiInGetNumberOfInputs (uint8_t *pNumberOfInputs);

/**
 * @brief Get the HDMI Inpuut Status.
 * 
 * This function is used to get the current HDMI Input Status.
 *
 * @param[out] pStatus          returns the current status of HdmiInput port: Possible statuses are
 *                              HDMI Input enabled, HDMI Input port connected,
 *                              Active HDMI Input port, and HW Pass-Through enabled.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsHdmiInInit() or  preceding dsHdmiInInit has failed
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this value. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @pre dsHdmiInInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsHdmiInGetStatus (dsHdmiInStatus_t *pStatus);

/**
 * @brief Select the HDMI Input port to be displayed on the screen.
 * 
 * This function is used to select the HDMI Input port for presentation.
 *
 * @param[in] ePort             HDMI Input port to be presented,
 * 
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsHdmiInInit() or  preceding dsHdmiInInit has failed
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this value. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @pre dsHdmiInInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsHdmiInSelectPort (dsHdmiInPort_t ePort);

/**
 * @brief Scale the HDMI In video
 * This function is used to scale the HDMI In video.
 *
 * @param[in] x                 x coordinate for the video
 * @param[in] y                 y coordinate for the video
 * @param[in] width             width of the video
 * @param[in] height            height of the video
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsHdmiInInit() or  preceding dsHdmiInInit has failed
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this value. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @pre dsHdmiInInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsHdmiInScaleVideo (int32_t x, int32_t y, int32_t width, int32_t height);

/**
 * @brief Select the HDMI Input zoom mode
 * 
 * This function is used to select the HDMI Input zoom mode.
 *
 * @param[in] requestedZoomMode HDMI Input zoom mode,
 * 
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsHdmiInInit() or  preceding dsHdmiInInit has failed
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this value. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @pre dsHdmiInInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsHdmiInSelectZoomMode (dsVideoZoom_t requestedZoomMode);

/**
 * @brief This function pauses the HDMI Input audio from HDMI out.
 *
 * This function stops sending the HDMI Input audio to the HDMI Out.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsHdmiInInit() or  preceding dsHdmiInInit has failed
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this value. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @pre dsHdmiInInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsHdmiInPauseAudio (void);

/**
 * @brief Start the output of HDMI Input audio.
 *
 * This function presents the HDMI Input audio via HDMI Out.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsHdmiInInit() or  preceding dsHdmiInInit has failed
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this value. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @pre dsHdmiInInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsHdmiInResumeAudio (void);

/**
 * @brief Get the current HDMI Input video mode.
 *
 * This function gets the current HDMI Input video mode.
 *
 * @param[out] resolution       Current HDMI Input video mode resolution
 *
 * @return Current HDMI Input video mode (resolution)
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsHdmiInInit() or  preceding dsHdmiInInit has failed
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this value. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @pre dsHdmiInInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsHdmiInGetCurrentVideoMode (dsVideoPortResolution_t *resolution);

/**
 * @brief Callback function used to notify the HDMI In hot plug event to the respective clients.
 *
 * HAL Implementation should call this method to deliver HDMI In hot plug status
 * to the application (e.g. Connect/Disconnect for Port 0/1).
 * @param[in] Port Port id where connection status is changed.
 * @param[in] isPortConnected Port connection status.
 *
 */
typedef void (*dsHdmiInConnectCB_t)(dsHdmiInPort_t Port, bool isPortConnected);

/**
 * @brief Callback function used to notify the HDMI In signal change event to the respective clients.
 *
 * HAL Implementation should call this method to deliver HDMI In signal change status
 * to the application (e.g. NoSignal/UnstableSignal/NotSupportedSignal/StableSignal for HDMI In ports).
 * @param[in] port Port id where signal status is changed
 * @param[in] sigStatus Current signal status of the port.
 *
 */
typedef void (*dsHdmiInSignalChangeCB_t)(dsHdmiInPort_t port, dsHdmiInSignalStatus_t sigStatus);

/**
 * @brief Callback function used to notify the HDMI Input status change event to the respective clients.
 *
 * HAL Implementation should call this method to deliver HDMI Input status
 * to the application (e.g. port, isPresented(true/false) etc. for HDMI In ports).
 * @param[in] inputStatus Present hdmi input status
 *
 */

typedef void (*dsHdmiInStatusChangeCB_t)(dsHdmiInStatus_t inputStatus);

/**
 * @brief Callback function used to notify the HDMI In video mode change event to the respective clients.
 *
 * HAL Implementation should call this method to deliver updated HDMI In video mode info
 * to the application
 *
 * @param[in] port Port in which video mode updated.
 * @param[in] videoResolution current video resolution of the port.
 *
 */

typedef void (*dsHdmiInVideoModeUpdateCB_t)(dsHdmiInPort_t port, dsVideoPortResolution_t videoResolution);

/**
 * @brief Callback function used to notify the HDMI Input ALLM Mode change event to the respective clients.
 *
 * HAL Implementation should call this method to deliver HDMI Input ALLM Mode
 * to the application (e.g. port, allm_mode(true/false) etc. for HDMI In ports).
 *
 * @param[in] port Hdmi port number in which ALLM Mode changed.
 * @param[in] allm_mode Current ALLM mode of the port.
 *
 */

typedef void (*dsHdmiInAllmChangeCB_t)(dsHdmiInPort_t port, bool allm_mode);

/**
 * @brief Register for the HDMI Input hot plug event.
 * 
 * This function is used to register a callback for the HDMI Input hot plug event notification from the HAL side.
 *
 * @param[in] CBFunc            HDMI Input hot plug callback function.
 * 
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsHdmiInInit() or  preceding dsHdmiInInit has failed
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this value. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @pre dsHdmiInInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsHdmiInRegisterConnectCB (dsHdmiInConnectCB_t CBFunc);

/**
 * @brief Register for the HDMI Input Signal Change event.
 *
 * This function is used to register a callback for the HDMI Input Signal Change event.
 *
 * @param[in] CBFunc            HDMI Input Signal change callback function.
 * 
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsHdmiInInit() or  preceding dsHdmiInInit has failed
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this value. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @pre dsHdmiInInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsHdmiInRegisterSignalChangeCB (dsHdmiInSignalChangeCB_t CBFunc);

/**
 * @brief Register for the HDMI Input Status Change event.
 *
 * This function is used to register a callback for the HDMI Input Status Change event.
 *
 * @param[in] CBFunc            HDMI Input Status change callback function.
 * 
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsHdmiInInit() or  preceding dsHdmiInInit has failed
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this value. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @pre dsHdmiInInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsHdmiInRegisterStatusChangeCB (dsHdmiInStatusChangeCB_t CBFunc);

/**
 * @brief Register for the HDMI Input Video Mode change event
 *
 * This function is used to register a callback for the HDMI Input video mode Change event.
 *
 * @param[in] CBFunc            HDMI Input video mode change callback function.
 * 
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsHdmiInInit() or  preceding dsHdmiInInit has failed
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this value. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @pre dsHdmiInInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsHdmiInRegisterVideoModeUpdateCB(dsHdmiInVideoModeUpdateCB_t CBFunc);

/**
 * @brief Register for the HDMI Input ALLM Mode Change event.
 *
 * This function is used to register a callback for the HDMI Input ALLM Mode Change event.
 *
 * @param[in] CBFunc            HDMI Input ALLM Mode change callback function.
 * 
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsHdmiInInit() or  preceding dsHdmiInInit has failed
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this value. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @pre dsHdmiInInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsHdmiInRegisterAllmChangeCB (dsHdmiInAllmChangeCB_t CBFunc);

/**
 * @brief routine to check the availability of the HDMI Arc port in the respective platform.
 *
 * This function is used to check the availability of the HDMI Arc port in the respective platform.
 *
 * @param[in] iPort             HDMI Arc port
 *
 * @return Boolean returns true if the port supports AC and false if not supported or an invalid port is passed.
 * @pre dsHdmiInInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

bool dsIsHdmiARCPort (int iPort);

/**
 * @brief routine to get the EDID bytes info
 *
 * This function is used to get the EDID bytes info event form the connected display.
 *
 * @param[in] iHdmiPort         HDMI Input port
 * @param[out] edid              EDID data for which info is required
 * @param[out] length            Length of the EDID data
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsHdmiInInit() or  preceding dsHdmiInInit has failed
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this value. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @pre dsHdmiInInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsGetEDIDBytesInfo (int iHdmiPort, unsigned char **edid, int *length);

/**
 * @brief routine to get the HDMI SPD info 
 *
 * This function is used to get the HDMI SPD info.
 *
 * @param[in] iHdmiPort         HDMI Input port
 * @param[out] data              HDMI SPD info data to get
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsHdmiInInit() or  preceding dsHdmiInInit has failed
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this value. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @pre dsHdmiInInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsGetHDMISPDInfo (int iHdmiPort, unsigned char **data);

/**
 * @brief routine to set the EDID version
 *
 * This function is used to set the EDID version info
 *
 * @param[in] iHdmiPort         HDMI Input port
 * @param[in] iEdidVersion      Input EDID version number to set
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsHdmiInInit() or  preceding dsHdmiInInit has failed
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this value. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @pre dsHdmiInInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetEdidVersion()
 */

dsError_t dsSetEdidVersion (int iHdmiPort, int iEdidVersion);

/**
 * @brief Routine to get the EDID version
 *
 * This function is used to get the EDID version info
 *
 * @param[in] iHdmiPort         HDMI Input port
 * @param[out] iEdidVersion      Input EDID version number to get
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsHdmiInInit() or  preceding dsHdmiInInit has failed
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this value. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @pre dsHdmiInInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetEdidVersion()
 */

dsError_t dsGetEdidVersion (int iHdmiPort, int *iEdidVersion);

/**
 * @brief Routine to get all the mstatus
 *
 * This function is used to get the all mstatus details of the specific port
 *
 * @param[in] iHdmiPort         HDMI Input port
 * @param[out] allmStatus        mstatus details to get
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsHdmiInInit() or  preceding dsHdmiInInit has failed
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this value. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @pre dsHdmiInInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsGetAllmStatus (int iHdmiPort, bool *allmStatus);

/**
 * @brief Routine to get all supported game features list
 *
 * This function is used to get all the supported game features list information.
 *
 * @param[out] features          List of all supported game features
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsHdmiInInit() or  preceding dsHdmiInInit has failed
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this value. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @pre dsHdmiInInit() should be called before calling this API.
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
