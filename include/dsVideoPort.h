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
 * @file dsVideoPort.h
 */



/**
* @defgroup devicesettings
* @{
* @defgroup hal
* @{
**/


#ifndef _DS_VIDEOPORT_H
#define _DS_VIDEOPORT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "dsError.h"
#include "dsTypes.h"


/**
 * @brief Callback function used to notify applications of Video Format change
 *
 * HAL Implementation should call this method to deliver updated Video Format info
 * to the application
 *
 * @param audioFormat     Current video format of the content playing
 *
 *
 * @return None.
 */
typedef void (*dsVideoFormatUpdateCB_t)(dsHDRStandard_t videoFormat);
/** 
 * @addtogroup DSHAL_VIDEOPORT_API Device Settings HAL Video Port Public API
 * @ingroup devicesettingshalapi
 *
 *  Described herein are the DeviceSettings HAL types and functions that are part of the
 *  Video Port subsystem. The Video Port subsystem manages video output port hardware operations.
 * @{
 */

/**
 * @brief Initialize underlying Video Port sub-system.
 * 
 * This function must initialize all the video specific output ports.
 *
 * @return  dsError_t
 * @retval dsERR_NONE If sucessfully dsVideoportinit api has been called using IARM support.
 * @retval dsERR_GENERAL General failure.
 */
dsError_t  dsVideoPortInit();

/**
 * @brief Get the video port handle.
 * 
 * This function gets the handle for the type of video port requested. It must return
 * ::dsERR_OPERATION_NOT_SUPPORTED if the requested video port is unavailable.
 *
 * @param[in]  type       Type of video port (e.g. HDMI).
 * @param[in]  index      The index of the video device (0, 1, ...).
 * @param[out] handle    The address of a location to hold the video device handle on return.
 * @return Device Settings error code
 * @retval dsERR_NONE If sucessfully dsgetvideoport api has been called using IARM support.
 * @retval dsERR_GENERAL General failure.
 */
dsError_t  dsGetVideoPort(dsVideoPortType_t type, int index, int *handle);

/**
 * @brief Indicate whether a video port is enabled.
 * 
 * This function indicates whether the specified video port is enabled or not.
 *
 * @param[in]  handle      Handle of the video port.
 * @param[out] enabled    The address of a location to hold the video port enable state
 *                          on return (@a true when port is enabled, @a false otherwise).
 * @return Device Settings error code
 * @retval dsERR_NONE If sucessfully dsIsVideoPortEnabled api has been called using IARM support.
 * @retval dsERR_GENERAL General failure .
 */
dsError_t  dsIsVideoPortEnabled(int handle, bool *enabled);

/**
 * @brief Indicate whether a video port is connected to a display.
 * 
 * This function is used to find out whether the video port is connected to a display or not.
 *
 * @param[in]  handle        Handle of the video port.
 * @param[out] connected    The address of a location to hold the connection state on
 *                            return (@a true when connected, @a false otherwise).
 * @return Device Settings error code
 * @retval dsERR_NONE If sucessfully dsIsDisplayConnected api has been called using IARM support.
 * @retval dsERR_GENERAL General failure.
 */
dsError_t  dsIsDisplayConnected(int handle, bool *connected);

/**
 * @brief This function is used to indicate if the display connected supports surround audio.
 *
 * @param[in]  handle Handle of the video port.
 * @param[out] surround It is set to True if the display supports surround audio.
 *
 * @return Device Settings error code
 * @retval dsERR_NONE Indicates dsIsDisplaySurround api has been called using IARM support.
 * @retval dsERR_GENERAL General failure.
 */
dsError_t  dsIsDisplaySurround(int handle, bool *surround);
  
/**
 * @brief This function is used to get supported surround mode.
 *
 * @param[in]  handle Handle of the video port.
 * @param[out] surround mode.
 *
 * @return Device Settings error code
 * @retval dsERR_NONE Indicates dsGetSurroundMode api has been called using IARM support.
 * @retval dsERR_GENERAL General failure.
 */
dsError_t  dsGetSurroundMode(int handle, int *surround);


/**
 * @brief This function is used to indicate whether a video port is connected to a display.
 *
 * @param[in]  handle        Handle of the video port.
 * @param[out] connected    The address of a location to hold the connection state on
 *                            return (@a true when connected, @a false otherwise).
 * @return Device Settings error code
 * @retval dsERR_NONE If sucessfully dsIsDisplayConnected api has been called using IARM support.
 * @retval dsERR_GENERAL General failure.
 */
dsError_t  dsIsVideoPortActive(int handle, bool *active);


/**
 * @brief Toggle DTCP protection of a video port.
 * 
 * This function is used to turn on/off the DTCP content protection for the specified
 * video port. Must return ::dsERR_OPERATION_NOT_SUPPORTED if DTCP content protection
 * is not available.
 *
 * @param [in] handle            Handle of the video  port.
 * @param [in] contentProtect    Flag to control DTCP content protection
 *                               (@a true for enabled, @a false for disabled).
 * @return Device Settings error code
 * @retval    ::dsError_t
 */
dsError_t  dsEnableDTCP(int handle, bool contentProtect);

/**
 * @brief Toggle HDCP protection of a video port.
 * 
 * This function is used to turn on/off the HDCP content protection for the specified
 * video port. Must return ::dsERR_OPERATION_NOT_SUPPORTED if HDCP content protection
 * is not available.
 *
 * @param[in] handle            Handle of the video port.
 * @param[in] contentProtect    Flag to control HDCP content protection
 *                               (@a true for enabled, @a false for disabled).
 * @param[in] hdcpKey HDCP key.
 * @param[in] keySize HDCP key size.
 * @return Device Settings error code
 * @retval dsERR_NONE If sucessfully dsEnableHDCP api has been called using IARM support.
 * @retval dsERR_GENERAL General failure.
 * @retval dsERR_INVALID_PARAM If invalid HCDP key is used.
 */
dsError_t  dsEnableHDCP(int handle, bool contentProtect, char *hdcpKey, size_t keySize);

/**
 * @brief Indicate whether a video port is DTCP protected.
 * 
 * This function indicates whether the specified video port is configured for DTCP
 * content protection. It must return ::dsERR_OPERATION_NOT_SUPPORTED if content protection
 * is not supported.
 *
 * @param [in]  handle                Handle of the video port.
 * @param [out] *pContentProtected    The address of a location to hold the DTCP content
 *                                    protection state on return (@a true when enabled,
 *                                    @a false otherwise).
 * @return Device Settings error code
 * @retval    ::dsError_t
 */
dsError_t  dsIsDTCPEnabled (int handle, bool* pContentProtected);

 /**
 * @brief Indicate whether a video port is HDCP protected.
 *
 * @param[in]  handle                Handle of the video port.
 * @param[out] enabled              The address of a location to hold the HDCP content
 *                                    protection state on return (@a true when enabled,
 *                                    @a false otherwise).
 * @return Device Settings error code
 * @retval dsERR_NONE If sucessfully dsIsHDCPEnabled api has been called using IARM support.
 * @retval dsERR_GENERAL General failure.
 */
dsError_t  dsIsHDCPEnabled (int handle, bool* pContentProtected);

 /**
 * @brief Enable/disable a video port.
 *
 * This function enables or disables the specified video port.
 *
 * @param [in] handle      Handle of the video port.
 * @param [in] enabled     Flag to control the video port state 
 *                         (@a true to enable, @a false to disable)
 * @return Device Settings error code
 * @retval dsERR_NONE If sucessfully dsEnableVideoPort api has been called using IARM support.
 * @retval dsERR_GENERAL General failure.
 */
dsError_t  dsEnableVideoPort(int handle, bool enabled);

/**
 * @brief Set video port's display resolution.
 *
 * This function sets the resolution for the video corresponding to the specified port handle.
 *
 * @param [in] handle         Handle of the video port.
 * @param [in] *resolution    The address of a structure containing the video port
 *                            resolution settings.
 * @param [in] persist        In false state allows disabling persist of resolution value.
 * @return Device Settings error code
 * @retval dsERR_NONE If sucessfully dsSetResolution api has been called using IARM support.
 * @retval dsERR_GENERAL General failure.
 */
dsError_t  dsSetResolution(int handle, dsVideoPortResolution_t *resolution, bool persist);

/**
 * @brief Get the video display resolution.
 *
 * This function Gets the resolution for the video corresponding to the specified port and index.
 *
 * @param [in] handle         Handle of the video output port.
 * @param [in] *resolution    The address of a structure containing the video output port
 *                            resolution settings.
 * @return Device Settings error code
 * @retval dsERR_NONE If sucessfully dsGetResolution api has been called using IARM support.
 * @retval dsERR_GENERAL General failure.
 */
dsError_t  dsGetResolution(int handle, dsVideoPortResolution_t *resolution);

/**
 * @brief Set the port to the the active source.
 * 
 * @param handle Handle of the video port.
 *
 * @return Device Settings error code
 * @retval    ::dsError_t
 */
dsError_t dsSetActiveSource(int handle);

 /**
 * @brief Terminate the Video Port sub-system.
 *
 * This function must terminate all the video output ports. It must reset any data
 * structures used within video port module and release any video port specific handles.
 *
* @return Device Settings error code
 * @retval dsERR_NONE If sucessfully dsVideoPortTerm api has been called using IARM support.
 * @retval dsERR_GENERAL General failure.
 */
dsError_t dsVideoPortTerm();

/**
 * @brief Initialize the Video Resolution
 *
 * This function Initialize the Video Resolution
 *
 * @param [in] Initialize the Video Resolution
 *                            
 * @return Device Settings error code
 * @retval    ::dsError_t
 */
dsError_t  dsInitResolution(dsVideoPortResolution_t *);


/**
 * @brief Callback function used to notify applications of HDCP status
 * 
 * HAL Implementation should call this method to delivery HDCP status
 * to the application (e.g. Authentication , Failure etc.).
 *
 * @param handle    Handle of the display device.
 * @param event     Display HDCP status.
 *
 *
 *
 * @return None.
 */
typedef void (*dsHDCPStatusCallback_t)(int handle, dsHdcpStatus_t status);


/**
 * @brief Register a callback function to listen for HDCP status
 *
 * This function registers a callback function for getting the HDCP status on HDMI Ports
 * 
 * @note Application should install at most one callback function per handle.
 * Multiple listeners are supported at application layer and thus not
 * required in HAL implementation.
 *
 * @param handle Handle of the display device.
 * @param cb     The callback function.
 * @return       Error code.
 * @retval       ::dsError_t 
 */
 dsError_t dsRegisterHdcpStatusCallback (int handle, dsHDCPStatusCallback_t cb);

 /**
 * @brief Get current HDCP status
 *
 * @param[in] status Handle HDCP status
 * @return Device Settings error code
 * @retval dsERR_NONE If sucessfully dsGetHDCPStatus api has been called using IARM support.
 * @retval dsERR_GENERAL General failure.
 */
dsError_t dsGetHDCPStatus (int handle, dsHdcpStatus_t *status);

/**
* @brief Get STB HDCP protocol version
*
* @param handle Handle of the display device.
* @param[in/out] HDCP protocol version
* @return Device Settings error code
* @retval dsERR_NONE If sucessfully dsGetHDCPProtocol api has been called.
* @retval dsERR_GENERAL General failure.
*/
dsError_t dsGetHDCPProtocol (int handle,dsHdcpProtocolVersion_t *protocolVersion);

/**
* @brief Get Receiver/TV HDCP protocol version
*
* @param handle Handle of the display device.
* @param[in/out] HDCP protocol version
* @return Device Settings error code
* @retval dsERR_NONE If sucessfully dsGetHDCPProtocol api has been called.
* @retval dsERR_GENERAL General failure.
*/
dsError_t dsGetHDCPReceiverProtocol (int handle,dsHdcpProtocolVersion_t *protocolVersion);

/**
* @brief Get current used HDCP protocol version
*
* @param handle Handle of the display device.
* @param[in/out] HDCP protocol version
* @return Device Settings error code
* @retval dsERR_NONE If sucessfully dsGetHDCPProtocol api has been called.
* @retval dsERR_GENERAL General failure.
*/
dsError_t dsGetHDCPCurrentProtocol (int handle,dsHdcpProtocolVersion_t *protocolVersion);

/**
 * @brief To find the HDR capabilities of TV
 *
 * This function is used to get the HDR capabilities supported by the TV.
 *
 * @param [in] handle   Handle for the video device (video decoder)
 * @param [out] *capabilities OR-ed value of supported HDR standards.
 * @return dsError_t Error code.
 */
dsError_t dsGetTVHDRCapabilities(int handle, int *capabilities);

/**
 * @brief To find the TV supported resolutions.
 *
 * This function is used to get the TV supported resolutions.
 *
 * @param [in] handle   Handle for the video device (video decoder)
 * @param [out] *resolution OR-ed value supported by TV.
 * @return dsError_t Error code.
 */
dsError_t dsSupportedTvResolutions(int handle, int *resolutions);
dsError_t dsSetForceDisable4KSupport(int handle, bool disable);
dsError_t dsGetForceDisable4KSupport(int handle, bool *disable);

 /**
 * @brief Sets various SCART parameters
 *
 * Supported values:
 * parameter_str  value_str
 * "aspect_ratio" "4x3", 16x9"
 * "tv_startup"   "on", "off"
 * "tv_startup"   "on", "off"
 * "rgb"          "on" (disables cvbs)
 * "cvbs"         "on" (disables rgb)
 * "macrovision", "*"  (not implemented)
 * "cgms",        "disabled"
 * "cgms",        "copyNever"
 * "cgms",        "copyOnce"
 * "cgms",        "copyFreely"
 * "cgms",        "copyNoMore"
 * "port"         "on", "off"
 *
 * @param[in] parameter_str - a name of parameter
 * @param[in] value_str - a value of parameter
 * @retval dsERR_NONE on success
 * @retval dsERR_GENERAL General failure.
 */
dsError_t dsSetScartParameter(int handle, const char* parameter_str, const char* value_str);

/**
 * @brief Get current video Electro-Optical Transfer Function (EOT) value;
 *
 * @param[in]  handle -  Handle of the display device.
 * @param[out] video_eotf - pointer to EOFF value
 *
 * @return Device Settings error code
 * @retval dsERR_NONE on success
 * @retval dsERR_GENERAL General failure.
 */
dsError_t dsGetVideoEOTF(int handle, dsHDRStandard_t *video_eotf);

/**
 * @brief Get current matrix coefficients value.
 *
 * @param[in]  handle -  Handle of the display device.
 * @param[out] matrix_coefficients - pointer to matrix coefficients value
 *
 * @return Device Settings error code
 * @retval dsERR_NONE on success
 * @retval dsERR_GENERAL General failure.
 */
dsError_t dsGetMatrixCoefficients(int handle, dsDisplayMatrixCoefficients_t *matrix_coefficients);

/**
 * @brief Get current color depth value.
 *
 * @param[in]  handle -  Handle of the display device.
 * @param[out] color_depth - pointer to color depths value.
 *
 * @return Device Settings error code
 * @retval dsERR_NONE on success
 * @retval dsERR_GENERAL General failure.
 */
dsError_t dsGetColorDepth(int handle, unsigned int* color_depth);

/**
 * @brief Get current color space setting.
 *
 * @param[in]  handle -  Handle of the display device.
 * @param[out] color_space - pointer to color space value.
 *
 * @return Device Settings error code
 * @retval dsERR_NONE on success
 * @retval dsERR_GENERAL General failure.
 */
dsError_t dsGetColorSpace(int handle, dsDisplayColorSpace_t* color_space);

/**
 * @brief Get quatization range.
 *
 * @param[in]  handle -  Handle of the display device.
 * @param[out] quantization_range - pointer to quantization range value.
 *
 * @return Device Settings error code
 * @retval dsERR_NONE on success
 * @retval dsERR_GENERAL General failure.
 */
dsError_t dsGetQuantizationRange(int handle, dsDisplayQuantizationRange_t* quantization_range);

/**
 * @brief Get current color space setting, color depth, matrix coefficients, video Electro-Optical Transfer Function (EOT)
 * and  quantization range in one call
 *
 * @param[in]  handle -  Handle of the display device.
 * @param[out] video_eotf - pointer to EOFF value
 * @param[out] matrix_coefficients - pointer to matrix coefficients value
 * @param[out] color_space - pointer to color space value.
 * @param[out] color_depth - pointer to color depths value.
 * @param[out] quantization_range - pointer to quantization range value.
 *
 * @return Device Settings error code
 * @retval dsERR_NONE on success
 * @retval dsERR_GENERAL General failure.
 */
dsError_t dsGetCurrentOutputSettings(int handle, dsHDRStandard_t* video_eotf, dsDisplayMatrixCoefficients_t* matrix_coefficients, dsDisplayColorSpace_t* color_space, unsigned int* color_depth, dsDisplayQuantizationRange_t* quantization_range);

/**
 * @brief Check Video Output is HDR or not.
 *
 * This function checks if the video output is HDR or not.
 *
 * @param [in] handle         Handle of the video port.
 * @param [in] *hdr           The bool pointer
 *
 * @return    Error Code.
 * @retval    ::dsError_t
 */
dsError_t dsIsOutputHDR(int handle, bool *hdr);

/**
 * @brief Reset Video Output to SDR
 *
 * This function resets the video output to SDR
 *
 * @return    Error Code.
 * @retval    ::dsError_t
 */
dsError_t dsResetOutputToSDR();

/**
 * @brief This API is used to set the Preferred HDMI Protocol
 *
 * This function sets the Preferred HDMI Protocol
 *
 * @param [in] handle                   Handle of the video port.
 * @param [in] *hdcpCurrentProtocol     Address of the structure containing
 *                                      HDCP Protocol version enums
 *  dsHDCP_VERSION_1X = 0,            < HDCP Protocol version 1.x
 *  dsHDCP_VERSION_2X,                < HDCP Protocol version 2.x
 *  dsHDCP_VERSION_MAX                < Maximum index for HDCP protocol.
 *
 * @return    Error Code.
 * @retval    ::dsError_t
 */
dsError_t dsSetHdmiPreference(int handle, dsHdcpProtocolVersion_t *hdcpCurrentProtocol);

/**
 * @brief This API is used to get the Preferred HDMI Protocol
 *
 * This function gets the Preferred HDMI Protocol and updates the
 * *hdcpCurrentProtocol accordingly
 *
 * @param [in] handle                   Handle of the video port.
 * @param [in] *hdcpCurrentProtocol     Address of the structure containing
 *                                      HDCP Protocol version enums
 *  dsHDCP_VERSION_1X = 0,            < HDCP Protocol version 1.x
 *  dsHDCP_VERSION_2X,                < HDCP Protocol version 2.x
 *  dsHDCP_VERSION_MAX                < Maximum index for HDCP protocol.
 *
 * @return    Error Code.
 * @retval    ::dsError_t
 */
dsError_t dsGetHdmiPreference(int handle, dsHdcpProtocolVersion_t *hdcpCurrentProtocol);

dsError_t dsGetIgnoreEDIDStatus(int handle, bool* status);

/**
 * @brief This API is used to set the background color for video port
 *
 * This function sets the background color for video port.
 *
 * @param [in] handle                   Handle of the video port.
 * @param [in] color                    color to be set
 *
 * @return    Error Code.
 * @retval    ::dsError_t
 */
dsError_t dsSetBackgroundColor(int handle, dsVideoBackgroundColor_t color);

/**
 * @brief This API is used to set/reset force HDR mode
 *
 * This function set/reset force HDR mode for  video port.
 *
 * @param [in] handle                   Handle of the video port.
 * @param [in] mode                   dsHDRStandard_t type
 *
 * @return    Error Code.
 * @retval    ::dsError_t
 */
dsError_t dsSetForceHDRMode(int handle, dsHDRStandard_t mode);

/**
 * @brief To find the color depth capabilities.
 *
 * This function is used to get the supported color depth capabilities.
 *
 * @param [in] handle   Handle for the video port.
 * @param [out] *capabilities OR-ed value of supported color depth  standards.
 * @return dsError_t Error code.
 */
dsError_t dsColorDepthCapabilities(int handle, unsigned int *colorDepthCapability );

/**
 * @brief To get the preffered color depth mode.
 *
 * This function is used to get the preffered color depth mode.
 *
 * @param [in] handle   Handle for the video port.
 * @param [out] colorDepth color depth value.
 * @return dsError_t Error code.
 */
dsError_t dsGetPreferredColorDepth(int handle, dsDisplayColorDepth_t *colorDepth, bool persist );

/**
 * @brief To set the preffered color depth mode.
 *
 * This function is used to set the preffered color depth mode.
 *
 * @param [in] handle   Handle for the video port.
 * @param [in] colorDepth color depth value.
 * @param [in] persist  to persist value
 * @return dsError_t Error code.
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
