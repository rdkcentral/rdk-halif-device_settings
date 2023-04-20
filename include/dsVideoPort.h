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
 * Describe the details about Device Settings HAL API specifications.
 *
 * <b> Following abbreviations present in HAL API </b>
 *
 * @par Abbreviations
 * - cb:      Callback function (suffix).
 * - DS:      Device Settings.
 * - HAL:     Hardware Abstraction Layer.
 * - _t:      Type (suffix).
 * - DTCP:    Digital Transmission Content Protection
 * - HDCP:    High-bandwidth Digital Copy Protection.
 * - EOTF:    Electro-Optical Transfer Function 
 * - HDR:     High Dynamic Range
 * - HDMI:    High-Definition Multimedia Interface
 * - SDR:     Standard Dynamic Range
 * - SCART:   SCART stands for Syndicat des Constructeursd’AppareilsRadiorécepteurs et Téléviseurs 
 *                      or Radio and Television Receiver Manufacturers.
 * 
 * @ingroup DSSETTINGS_HAL
 */

/**
 * @file dsVideoPort.h
 */



/**
* @defgroup devicesettings Device Settings
* @{
* @defgroup hal Device Settings HAL
* @{
**/


#ifndef _DS_VIDEOPORT_H
#define _DS_VIDEOPORT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "dsError.h"
#include "dsTypes.h"

typedef void (*dsVideoFormatUpdateCB_t)(dsHDRStandard_t videoFormat);

/** 
 * @addtogroup Device Settings HAL Video Port Public API. See DSHAL_VIDEOPORT_API
 * @ingroup devicesettingshalapi
 *
 *  Described herein are the DeviceSettings HAL types and functions that are part of the
 *  Video Port subsystem. The Video Port subsystem manages video output port HAL operations.
 * @{
 */

/**
 * @brief Initialize underlying Video Port sub-system.
 * 
 * This function is required to be called before the other APIs in this module.@n
 *
 * @return dsError_t            - Status
 * @retval dsERR_NONE           - Success
 * @retval dsERR_INVALID_STATE  - Function is already initialized.
 * @retval dsERR_GENERAL        - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsVideoPortTerm()
 */
dsError_t  dsVideoPortInit();


/**
 * @brief This function is used to get the video port handle.
 *
 * @param[in]  type     - Type of video port. See dsVideoPortType_t.
 * @param[in]  index    - The index of the video device. Max number of ports is device specific. Min of 0.
 * @param[out] handle   - The handle used by the caller to uniquely identify the HAL instance

 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsVideoPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t  dsGetVideoPort(dsVideoPortType_t type, int index, int *handle);


/**
 * @brief This function is used to get the enabled status of the Video Port.
 *
 * @param[in]  handle   - The handle returned from the dsGetVideoPort() function
 * @param[out] enabled  - Video Port Enable Status. True to enabled, false to disabled.
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 *
 * @pre dsVideoPortInit() must be called before calling this API.
 *
 * @warning  This API is Not thread safe.
 * 
 * @see dsEnableVideoPort()
 */
dsError_t  dsIsVideoPortEnabled(int handle, bool *enabled);


/**
 * @brief This function is used to find out whether the video port is connected to a display or not.
 *
 * @param[in]  handle       - The handle returned from the dsGetVideoPort() function
 * @param[out] connected    - Connection status. True to connected, false to disconnected.
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 *
 * @pre dsVideoPortInit() must be called before calling this API.
 *
 * @warning  This API is Not thread safe.
 */
dsError_t  dsIsDisplayConnected(int handle, bool *connected);


/**
 * @brief  This function is used to check if the connected display supports the audio surround.
 *
 * @param[in]  handle   - The handle returned from the dsGetVideoPort() function
 * @param[out] surround - Supported status of the display surround. True for supported, false for not supported.
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 *
 * @pre dsVideoPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 */
dsError_t  dsIsDisplaySurround(int handle, bool *surround);


/**
 * @brief This function is used to get the surround mode set for the display
 *
 * @param[in]  handle   - The handle returned from the dsGetVideoPort() function
 * @param[out] surround - Current Surround mode. See dsSURROUNDMode_t for possible values.
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsVideoPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 */
dsError_t  dsGetSurroundMode(int handle, int *surround);


/**
 * @brief This function is used to indicate whether a video port connected to a display is active
 *
 * @param[in]  handle   - The handle returned from the dsGetVideoPort() function
 * @param[out] active   - Active status of the video port. True for active, false inactive.
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsVideoPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 */
dsError_t  dsIsVideoPortActive(int handle, bool *active);


/**
 * @brief This function is used to turn on/off the DTCP content protection for the specified video port.
 *
 * @param[in]  handle           - The handle returned from the dsGetVideoPort() function
 * @param[in]  contentProtect   - Flag to control DTCP content protection. True for enabled, false for disabled.
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.
 * 
 * @see dsIsDTCPEnabled()
 */
dsError_t  dsEnableDTCP(int handle, bool contentProtect);


/**
 * @brief This function is used to turn on/off the HDCP content protection for the specified video port. 
 *
 * @param[in]  handle           - The handle returned from the dsGetVideoPort() function
 * @param[in]  contentProtect   - Flag to control HDCP content protection. True for enabled, false for disabled.
 * @param[in]  hdcpKey          - HDCP key.
 * @param[in]  keySize          - HDCP key size. Min of 0.
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.
 * 
 * @see dsGetHDCPStatus(), dsIsHDCPEnabled()
 */
dsError_t  dsEnableHDCP(int handle, bool contentProtect, char *hdcpKey, size_t keySize);


/**
 * @brief This function indicates whether the specified video port is configured for DTCP content protection.
 *
 * @param[in]  handle               - The handle returned from the dsGetVideoPort() function
 * @param[out] pContentProtected    - Current DTCP content protection state. True for enabled, false for disabled.
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.
 * 
 * @see dsEnableDTCP()
 */
dsError_t  dsIsDTCPEnabled (int handle, bool* pContentProtected);


 /**
 * @brief This function used to get the HDCP protected status of the specifed port. .
 *
 * @param[in]  handle               - The handle returned from the dsGetVideoPort() function
 * @param[out] pContentProtected    - Current DTCP content protection status. True for enabled, false for disabled.
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.
 * 
 * @see dsEnableHDCP()
 */
dsError_t  dsIsHDCPEnabled (int handle, bool* pContentProtected);


 /**
 * @brief This function enables or disables the specified video port.
 *
 * @param[in]  handle    - The handle returned from the dsGetVideoPort() function
 * @param[in]  enabled   - Enable value for specified port. True for enabled, false for disabled.
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.
 * 
 * @see dsIsVideoPortEnabled()
 */
dsError_t  dsEnableVideoPort(int handle, bool enabled);


/**
 * @brief This function is used to set the resolution of the specific video port.
 *
 * @param[in]  handle       - The handle returned from the dsGetVideoPort() function
 * @param[in]  resolution   - New video port resolution settings. See dsVideoPortResolution_t.
 * @param[in]  persist      - Status to be persisted. True to persist, false to not persist.
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.
 * 
 * @see dsGetResolution()
 */
dsError_t  dsSetResolution(int handle, dsVideoPortResolution_t *resolution, bool persist);


/**
 * @brief This function is used to get the current resolution of the specific video port at the index.
 *
 * @param[in]  handle       - The handle returned from the dsGetVideoPort() function
 * @param[out] resolution   - Current resolution settings of the port. See dsVideoPortResolution_t.
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.
 * 
 * @see dsSetResolution()
 */
dsError_t  dsGetResolution(int handle, dsVideoPortResolution_t *resolution);


/**
 * @brief This function is used to set the port to the active source.
 * 
 * @param[in]  handle   - The handle returned from the dsGetVideoPort() function
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.
 */
dsError_t dsSetActiveSource(int handle);


 /**
 * @brief Terminate the Video Port sub-system.
 *
 * This function must terminate all the video output ports.
 *
 * @return dsError_t            - Status
 * @retval dsERR_NONE           - Success 
 * @retval dsERR_INVALID_STATE  - Module is not initialised
 * @retval dsERR_GENERAL        - General failure.
 * 
 * @pre dsVideoPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsVideoPortInit()
 */
dsError_t dsVideoPortTerm();


/**
 * @brief This function Initialize the Video Resolution
 *
 * @param[in] resolution    - Video Resolution Structure to be initialized. See dsVideoPortResolution_t.
 *                            
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.
 */
dsError_t  dsInitResolution(dsVideoPortResolution_t *resolution);


/**
 * @brief Callback function to notify the HDCP status change.
 * 
 * @param handle    - The handle returned from the dsGetVideoPort() function
 * @param status    - HDCP status. See dsHdcpStatus_t
 * 
 * HAL Implementation must invoke this call back to notify the  HDCP status change event
 * to the Caller (Authentication , Failure, enabled, disabled).
 */
typedef void (*dsHDCPStatusCallback_t)(int handle, dsHdcpStatus_t status);


/**
 * @brief Register callback function to listen for the HDCP status change event.
 *
 * This function registers a callback function to receive the HDCP status change event from
 * the specific HDMI Port
 * 
 * @note Caller must install at most one callback function per handle.
 * Multiple listeners are supported at Caller layer and thus not
 * required in HAL implementation.
 *
 * @param[in]  handle   - The handle returned from the dsGetVideoPort() function
 * @param[in]  cb       - The callback function. See dsHDCPStatusCallback_t.
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.
 */
 dsError_t dsRegisterHdcpStatusCallback (int handle, dsHDCPStatusCallback_t cb);


 /**
 * @brief This function is used to get the current HDCP status
 *
 * @param[in]  handle   - The handle returned from the dsGetVideoPort() function
 * @param[out] status   - HDCP status of the device. See dsHdcpStatus_t.
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.
 
 * @warning  This API is Not thread safe.
 * 
 * @see dsEnableHDCP()
 */
dsError_t dsGetHDCPStatus (int handle, dsHdcpStatus_t *status);


/**
 * @brief This function is used to get the current set-up box HDCP protocol version
 *
 * @param[in]  handle           - The handle returned from the dsGetVideoPort() function
 * @param[out] protocolVersion  - HDCP protocol version. See dsHdcpProtocolVersion_t.
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.
 * 
 * @see dsEnableHDCP()
 */
dsError_t dsGetHDCPProtocol (int handle,dsHdcpProtocolVersion_t *protocolVersion);


/**
 * @brief This function is used to get the Receiver/TV HDCP protocol version 
 *
 * @param[in]  handle           - The handle returned from the dsGetVideoPort() function
 * @param[out] protocolVersion  - HDCP protocol version. See dsHdcpProtocolVersion_t.
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.
 * 
 * @see dsEnableHDCP()
 */
dsError_t dsGetHDCPReceiverProtocol (int handle,dsHdcpProtocolVersion_t *protocolVersion);


/**
 * @brief This function is used to get the current HDCP protocol version
 *
 * @param[in]  handle           - The handle returned from the dsGetVideoPort() function
 * @param[out] protocolVersion  - HDCP protocol version. See dsHdcpProtocolVersion_t.
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.
 * 
 * @see dsEnableHDCP()
 */
dsError_t dsGetHDCPCurrentProtocol (int handle,dsHdcpProtocolVersion_t *protocolVersion);


/**
 * @brief This function is used to get the HDR capabilities supported by the TV.
 *
 * @param[in]  handle       - The handle returned from the dsGetVideoPort() function
 * @param[out] capabilities - Supported HDR standards. See _dsHDRStandard_t.
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.
 */
dsError_t dsGetTVHDRCapabilities(int handle, int *capabilities);


/**
 * @brief his function is used to get the TV supported resolutions.
 *
 * @param[in]  handle       - The handle returned from the dsGetVideoPort() function
 * @param[out] resolutions  - Resolutions supported by the TV. Device specific.
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.
 */
dsError_t dsSupportedTvResolutions(int handle, int *resolutions);


/**
 * @brief This function is used to Forcefully disable 4K support.
 *
 * @param[in]  handle   - The handle returned from the dsGetVideoPort() function
 * @param[out] disable  - Disable 4k support. True to force disable, false to stop force disable.
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.
 * 
 * @see dsGetForceDisable4KSupport()
 */
dsError_t dsSetForceDisable4KSupport(int handle, bool disable);


/**
 * @brief This function is used to get status if the device is Forcefully disabled 4K support.
 *
 * @param[in]  handle   - The handle returned from the dsGetVideoPort() function
 * @param[out] disable  - Disable Status. True if force disabled is, false if off.
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.
 * 
 * @see dsSetForceDisable4KSupport()
 */
dsError_t dsGetForceDisable4KSupport(int handle, bool *disable);


 /**
 * @brief This function is used to set various SCART parameters
 *
 * @param[in]  handle           - The handle returned from the dsGetVideoPort() function
 * @param[in]  parameter_str    - a name of parameter. See list bellow.
 * @param[in]  value_str        - a value of parameter. See list bellow.
 * Supported values for parameter_str and value_str pairs:
 * parameter_str  value_str
 * "aspect_ratio" "4x3", 16x9"
 * "tv_startup"   "on", "off"
 * "rgb"          "on" (disables cvbs)
 * "cvbs"         "on" (disables rgb)
 * "macrovision", "*"  (not implemented)
 * "cgms",        "disabled", "copyNever" "copyOnce" "copyFreely" "copyNoMore"
 * "port"         "on", "off"
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.
 */
dsError_t dsSetScartParameter(int handle, const char* parameter_str, const char* value_str);


/**
 * @brief This function is used to get the current video EOTF value;
 *
 * @param[in]  handle       - The handle returned from the dsGetVideoPort() function
 * @param[out] video_eotf   - Requested EOTF value. See dsHDRStandard_t
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.
 */
dsError_t dsGetVideoEOTF(int handle, dsHDRStandard_t *video_eotf);


/**
 * @brief This function is used to get the current matrix coefficients value.
 *
 * @param[in]  handle               - The handle returned from the dsGetVideoPort() function
 * @param[out] matrix_coefficients  - Matrix coefficients value. See dsDisplayMatrixCoefficients_t
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.
 */
dsError_t dsGetMatrixCoefficients(int handle, dsDisplayMatrixCoefficients_t *matrix_coefficients);


/**
 * @brief This function is used to get the current color depth value.
 *
 * @param[in]  handle       - The handle returned from the dsGetVideoPort() function
 * @param[out] color_depth  - Color depth value. See dsDisplayColorDepth_t.
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.
 * @warning  This API is Not thread safe.
 */
dsError_t dsGetColorDepth(int handle, unsigned int* color_depth);


/**
 * @brief This function is used to get the current color space setting.
 *
 * @param[in]  handle       - The handle returned from the dsGetVideoPort() function
 * @param[out] color_space  - Color space value as defined in dsDisplayColorSpace_t. See dsDisplayColorSpace_t
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.
 */
dsError_t dsGetColorSpace(int handle, dsDisplayColorSpace_t* color_space);
 

/**
 * @brief This function is used to get the quantization range.
 *
 * @param[in]  handle               - The handle returned from the dsGetVideoPort() function
 * @param[out] quantization_range   - Quantization range value. See dsDisplayQuantizationRange_t.
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.
 */
dsError_t dsGetQuantizationRange(int handle, dsDisplayQuantizationRange_t* quantization_range);


/**
 * @brief This function is used to get the current color space setting, color depth, 
 *              matrix coefficients, video EOTF and  quantization range in one call
 *
 * @param[in]  handle               - The handle returned from the dsGetVideoPort() function
 * @param[out] video_eotf           - EOTF value. See dsHDRStandard_t
 * @param[out] matrix_coefficients  - Matrix coefficients value. See dsDisplayMatrixCoefficients_t
 * @param[out] color_space          - Color space value as defined in dsDisplayColorSpace_t. 
 *                                              See dsDisplayColorSpace_t
 * @param[out] color_depth          - Color depths value as defined in dsDisplayColorDepth_t.
 * @param[out] quantization_range   - Quantization range value. See dsDisplayQuantizationRange_t.
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.
 */
dsError_t dsGetCurrentOutputSettings(int handle, dsHDRStandard_t* video_eotf, 
            dsDisplayMatrixCoefficients_t* matrix_coefficients, 
            dsDisplayColorSpace_t* color_space, unsigned int* color_depth, 
            dsDisplayQuantizationRange_t* quantization_range);


/**
 * @brief This function checks if the video output is HDR or not.
 *
 * @param[in]  handle   - The handle returned from the dsGetVideoPort() function
 * @param[out] hdr      - HDR support status. True for supported, false for not supported.
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.
 */
dsError_t dsIsOutputHDR(int handle, bool *hdr);


/**
 * @brief This function is used to reset the video output to SDR
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.
 */
dsError_t dsResetOutputToSDR();


/**
 * @brief This function is used to set the Preferred HDMI Protocol
 *
 * @param[in]  handle               - The handle returned from the dsGetVideoPort() function
 * @param[in]  hdcpCurrentProtocol  - New HDCP protocol to set. See dsHdcpProtocolVersion_t.
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API. 
 *
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetHdmiPreference()
 */
dsError_t dsSetHdmiPreference(int handle, dsHdcpProtocolVersion_t *hdcpCurrentProtocol);


/**
 * @brief This function is used to get the Preferred HDMI Protocol and updates the
 * *hdcpCurrentProtocol accordingly
 *
 * @param[in]  handle               - The handle returned from the dsGetVideoPort() function
 * @param[out] hdcpCurrentProtocol  - Current Preferred HDMI Protocol applied. 
 *                                          See dsHdcpProtocolVersion_t.
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.
 *
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetHdmiPreference()
 */
dsError_t dsGetHdmiPreference(int handle, dsHdcpProtocolVersion_t *hdcpCurrentProtocol);


/**
 * @brief This function is used to get the status of ignore the EDID data value.
 *
 * @param[in]   handle  - The handle returned from the dsGetVideoPort() function
 * @param[out]  status  - Status of Ignore EDID variable. 
 *                              True to ignore EDID, false to not ignore.
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.
 
 * @warning  This API is Not thread safe.
 */
dsError_t dsGetIgnoreEDIDStatus(int handle, bool* status);


/**
 * @brief This function is used to set the background color for video port.
 *
 * @param[in]  handle   - The handle returned from the dsGetVideoPort() function
 * @param[in]  color    - Color to be set. See dsVideoBackgroundColor_t.
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.
 */
dsError_t dsSetBackgroundColor(int handle, dsVideoBackgroundColor_t color);


/**
 * @brief This function is used to set/reset force HDR mode for  video port.
 *
 * @param[in]  handle   - The handle returned from the dsGetVideoPort() function
 * @param[in]  mode     - Force set HDR mode. See dsHDRStandard_t
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.
 */
dsError_t dsSetForceHDRMode(int handle, dsHDRStandard_t mode);


/**
 * @brief This function is used to get the supported color depth capabilities.
 *
 * @param[in]   handle                  - The handle returned from the dsGetVideoPort() function
 * @param[out]  colorDepthCapability    - Supported color depth. 
 *                                          See dsDisplayColorDepth_t for valid returns.
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.

 * @todo    Updating colorDepthCapability type to dsDisplayColorDepth_t.
 */
dsError_t dsColorDepthCapabilities(int handle, unsigned int *colorDepthCapability );


/**
 * @brief This function is used to get the preferred color depth mode.
 *
 * @param[in]   handle      - The handle returned from the dsGetVideoPort() function
 * @param[out]  colorDepth  - Color depth value. See dsDisplayColorDepth_t.
 * @param[in]   persist     - Value to be persisted. True to persist, false to not persist.
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.
 * 
 * @see dsSetPreferredColorDepth()
 */
dsError_t dsGetPreferredColorDepth(int handle, dsDisplayColorDepth_t *colorDepth, bool persist );


/**
 * @brief This function is used to set the preferred color depth mode.
 *
 * @param[in]  handle       - The handle returned from the dsGetVideoPort() function
 * @param[in]  colorDepth   - Color depth value as defined in dsDisplayColorDepth_t.
 * @param[in]  persist      - Value to be persisted. True to persist, false to not persist.
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error

 * @pre dsVideoPortInit() must be called before calling this API.

 * @warning  This API is Not thread safe.

 * @see dsGetPreferredColorDepth()
 */
dsError_t dsSetPreferredColorDepth(int handle,dsDisplayColorDepth_t colorDepth, bool persist );


/**
 * @}
 */

#ifdef __cplusplus
}
#endif
#endif /* _DS_VIDEOPORT_H */


/** @} */
/** @} */