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
 * @see the License for the specific language governing permissions and
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
 * @see the License for the specific language governing permissions and
 * limitations under
*/
 
/**
 * @file dsHdmiIn.h
 *
 * @brief Device Settings HAL HDMI input Public API.
 * This API defines the HAL for the Device Settings HDMI input interface.
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
 * - EDID:    Extended Display Identification Data.
 * - SPD:     Source Product Description.
 * - ARC:     Audio Return Channel.
 * - ALLM:    Auto Low Latency Mode
 * - HDMI:    High-Definition Multimedia Interface
 * - AV:      Audio-Visual
 *
 * @par Implementation Notes
 * -# None
 *
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

/** @addtogroup DeviceSettings_Module DeviceSettings Module
 * @par Application API Specification
 * Described herein are the DeviceSettings HAL types and functions that are part of
 * the HdmiIn subsystem. The HdmiIn subsystem manages system-specific HAL operations.
 *  @{
 */

/** @defgroup DSHAL_HdmiIn_API Device Settings HAL HdmiIn Public API
 *
 *
 *  @{
 */

#ifndef _DS_dsHdmiInH_
#define _DS_dsHdmiInH_

#include <sys/types.h>
#include "dsError.h"
#include "dsTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initializes the underlying HDMI input sub-system.
 * 
 * This function must initialize the HDMI input module and any associated resources.
 *
 * @return dsError_t                    - Status
 * @retval dsERR_NONE                   - Success
 * @retval dsERR_ALREADY_INITIALIZED    - Function is already initialized
 * @retval dsERR_RESOURCE_NOT_AVAILABLE - Resources have failed to allocate
 * @retval dsERR_GENERAL                - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsHdmiInTerm()
 * 
 */
dsError_t dsHdmiInInit (void);

/**
 * @brief Terminates the underlying HDMI input sub-system.
 * 
 * This function must terminate the HDMI input module and any associated resources.
 *
 * @return dsError_t                    - Status
 * @retval dsERR_NONE                   - Success
 * @retval dsERR_NOT_INITIALIZED        - Module is not initialised
 * @retval dsERR_GENERAL                - Underlying undefined platform error
 * 
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsHdmiInInit()
 * 
 */
dsError_t dsHdmiInTerm (void);

/**
 * @brief Sets the number of HDMI input ports on the device.
 * 
 * This function sets the number of HDMI input ports on the device.
 *
 * @param[out] pNumberOfinputs  - number of HDMI input ports.
 *                                  Max number of inputs is platform specific. Min is 0
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsHdmiInGetNumberOfinputs (uint8_t *pNumberOfinputs);

/**
 * @brief Sets the current HDMI input port status.
 * 
 * This function sets the current HDMI input port status.
 *
 * @param[out] pStatus  - current status of the HDMI input port. @see dsHdmiInStatus_t
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsHdmiInGetStatus (dsHdmiInStatus_t *pStatus); 

/**
 * @brief Selects the HDMI input port for presentation.
 * 
 * This function selects the HDMI input port for presentation.
 *
 * @param[in] ePort     - HDMI input port to be presented. @see dsHdmiInPort_t
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported.
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsHdmiInSelectPort (dsHdmiInPort_t ePort);

/**
 * @brief Scales the HDMI input video
 * This function scales the HDMI input video. The width and height, based on the x, y coordinates, 
 *      cannot exceed that of the current resolution of the device.
 *      e.g.  x(in pixels)+width cannot be greater then the width of the resolution.
 *
 * @param[in] x         - x coordinate for the video
 * @param[in] y         - y coordinate for the video
 * @param[in] width     - width of the video. Width in pixels.
 * @param[in] height    - height of the video. Height in pixels.
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid. 
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsHdmiInScaleVideo (int32_t x, int32_t y, int32_t width, int32_t height);

/**
 * @brief Updates the video zoom on the active HDMI input using the provided zoom mode.
 * 
 * This function updates the video zoom on the active HDMI input using the provided zoom mode.
 *
 * @param[in] requestedZoomMode     - HDMI input zoom mode. @see dsVideoZoom_t
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsHdmiInSelectZoomMode (dsVideoZoom_t requestedZoomMode);

/**
 * @brief Gets the current HDMI input video mode of the active port
 * 
 * This function gets the current HDMI input video mode of the active port
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsHdmiInGetCurrentVideoMode (dsVideoPortResolution_t *resolution);

/**
 * @brief HAL must call this function when the HDMI input port connection status changes.
 *
 * @param[in] Port              - Port id where connection status is changed. @see dsHdmiInPort_t
 * @param[in] isPortConnected   - Flag to control the port connection status. 
 *                                  ( @a true to enable, @a false to disable)
 * 
 * @pre dsHdmiInRegisterConnectCB() must be called before this API
 *
 */
typedef void (*dsHdmiInConnectCB_t)(dsHdmiInPort_t Port, bool isPortConnected);

/**
 * @todo updating the signal status enum
 * @brief HAL must call this function when the HDMI input port signal status changes.
 * 
 * @param[in] port      - Port id where signal status is changed. @see dsHdmiInPort_t
 * @param[in] sigStatus - Current signal status of the port. @see dsHdmiInSignalStatus_t
 * 
 * @pre dsHdmiInRegisterSignalChangeCB() must be called before this API
 *
 */
typedef void (*dsHdmiInSignalChangeCB_t)(dsHdmiInPort_t port, dsHdmiInSignalStatus_t sigStatus);

/**
 * @brief HAL must call this function when the HDMI input status changes on any port.
 *
 * HAL Implementation must call this method to deliver HDMI input status
 * to the Caller whenever the HDMI input status changes.
 * 
 * @param[in] inputStatus   - Present hdmi input status. @see dsHdmiInStatus_t
 * 
 * @pre dsHdmiInRegisterStatusChangeCB() must be called before this API
 *
 */
typedef void (*dsHdmiInStatusChangeCB_t)(dsHdmiInStatus_t inputStatus);

/**
 * @brief HAL must call this function when the HDMI input port video mode changes.
 *
 * HAL Implementation must call this method to deliver updated HDMI input port video mode info
 * to the Caller
 *
 * @param[in] port              - Port in which video mode updated. @see dsHdmiInPort_t
 * @param[in] videoResolution   - current video resolution of the port. @see dsVideoPortResolution_t
 * 
 * @pre dsHdmiInRegisterVideoModeUpdateCB() must be called before this API
 *
 */
typedef void (*dsHdmiInVideoModeUpdateCB_t)(dsHdmiInPort_t port, dsVideoPortResolution_t videoResolution);

/**
 * @brief HAL must call this function when the HDMI input ALLM mode changes.
 * @todo discuss dolby vision game mode offline
 *
 * @param[in] port      - HDMI input port number in which ALLM Mode changed. @see dsHdmiInPort_t
 * @param[in] allm_mode - Flag to hold the current ALLM mode of the port.
 *                              ( @a true to enable, @a false to disable)
 * 
 * @pre dsHdmiInRegisterAllmChangeCB() must be called before this API
 *
 */
typedef void (*dsHdmiInAllmChangeCB_t)(dsHdmiInPort_t port, bool allm_mode);

/**
 * @brief Callback function used to notify applications of HDMI Input AV Latency
 *
 * HAL Implementation should call this method to deliver HDMI Input AV Latency
 * to the application.
 *
 * @param[in] audio_latency - Audio latency value. Max value 500ms. Min value 0.
 * @param[in] video_latency - Video latency value. Max value 500ms. Min value 0.
 *
 * @pre dsHdmiInRegisterAVLatencyChangeCB() must be called before this API
 */
typedef void (*dsAVLatencyChangeCB_t)(int audio_latency, int video_latency);

/**
 * @brief Callback function used to notify applications of HDMI Input Content Type change
 *
 * HAL Implementation should call this method to deliver HDMI Input Content Type change 
 * to the application
 *
 * @param port			    - HDMI Input port. @see dsHdmiInPort_t
 * @param avi_content_type	- HDMI port AVI Content Type Info. @see dsAviContentType_t
 *
 * @pre dsHdmiInRegisterAviContentTypeChangeCB() must be called before this API
 */
typedef void (*dsHdmiInAviContentTypeChangeCB_t)(dsHdmiInPort_t port, dsAviContentType_t avi_content_type);

/**
 * @brief Registers a callback for the HDMI input hot plug event notification from the HAL side.
 * 
 * This function registers a callback for the HDMI input hot plug event notification from the HAL side.
 *
 * @param[in] CBFunc    - HDMI input hot plug callback function. @see dsHdmiInConnectCB_t
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * @see dsHdmiInConnectCB_t for related callback
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsHdmiInRegisterConnectCB (dsHdmiInConnectCB_t CBFunc);

/**
 * @brief Registers a callback for the HDMI input Signal Change event.
 * 
 * This function registers a callback for the HDMI input Signal Change event.
 *
 * @param[in] CBFunc    - HDMI input Signal change callback function. @see dsHdmiInSignalChangeCB_t
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * @see dsHdmiInSignalChangeCB_t for related callback.
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsHdmiInRegisterSignalChangeCB (dsHdmiInSignalChangeCB_t CBFunc);

/**
 * @brief Registers a callback for the HDMI input Status Change event.
 * 
 * This function registers a callback for the HDMI input Status Change event.
 *
 * @param[in] CBFunc    - HDMI input Status change callback function. @see dsHdmiInStatusChangeCB_t
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * @see dsHdmiInStatusChangeCB_t for related callback.
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsHdmiInRegisterStatusChangeCB (dsHdmiInStatusChangeCB_t CBFunc);

/**
 * @brief Registers a callback for the HDMI input video mode Change event. 
 * 
 * This function registers a callback for the HDMI input video mode Change event. 
 *       The mode change is triggered whenever the video resolution changes.
 *
 * @param[in] CBFunc    - HDMI input video mode change callback function. 
 *                              @see dsHdmiInVideoModeUpdateCB_t
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * @see dsHdmiInVideoModeUpdateCB_t for related callback.
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsHdmiInRegisterVideoModeUpdateCB(dsHdmiInVideoModeUpdateCB_t CBFunc);

/**
 * @brief Registers a callback for the HDMI input ALLM Mode Change event.
 * 
 * This function registers a callback for the HDMI input ALLM Mode Change event.
 *
 * @param[in] CBFunc    - HDMI input ALLM Mode change callback function. 
 *                              @see dsHdmiInAllmChangeCB_t
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * @see dsHdmiInAllmChangeCB_t for related callback.
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsHdmiInRegisterAllmChangeCB (dsHdmiInAllmChangeCB_t CBFunc);

/**
 * @brief Registers the HDMI In Latency Change event.
 *
 * This function registers for the AV Latency Change event.
 *
 * @param[in] CBFunc    - HDMI input AV Latency change callback function. 
 *                              @see dsAVLatencyChangeCB_t
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * @see dsAVLatencyChangeCB_t for related callback.
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsHdmiInRegisterAVLatencyChangeCB (dsAVLatencyChangeCB_t CBFunc);

/**
 * @brief Registers the HDMI Input Content type Change event.
 *
 * This function registers for the HDMI Input content type change event.
 *
 * @param[in] CBFunc    - HDMI input Avi Content Mode change callback function. 
 *                              @see dsHdmiInAviContentTypeChangeCB_t
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * @see dsHdmiInAviContentTypeChangeCB_t for related callback.
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsHdmiInRegisterAviContentTypeChangeCB (dsHdmiInAviContentTypeChangeCB_t CBFunc);

/**
 * @brief Checks if the given port is an HDMI ARC port or not
 * 
 * This function checks if the given port is an HDMI ARC port or not
 *
 * @param[in] iPort     - HDMI Arc port. Max value is device specific. Min value of 0
 * @param[in] isArcPort - Flag to hold the HDMI Arc port status 
 *                              ( @a true to enable, @a false to disable)
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsIsHdmiARCPort (dsHdmiInPort_t iPort, bool isArcPort);

/**
 * @brief Gets the EDID bytes info corresponds to the given input port.
 * 
 * This function gets the EDID bytes info corresponds to the given input port.
 * @todo How the EDID information is read.
 *
 * @param[in] iHdmiPort     - HDMI input port. @see dsHdmiInPort_t
 * @param[out] edid         - EDID data for which info is required
 * @param[out] length       - length of the EDID data. Min value of 0
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsGetEDIDBytesInfo (dsHdmiInPort_t iHdmiPort, unsigned char **edid, int *length);

/**
 * @brief Gets the HDMI SPD info.
 * 
 * This function gets the HDMI SPD info.
 *
 * @param[in] iHdmiPort     - HDMI input port. @see dsHdmiInPort_t
 * @param[out] data         - HDMI SPD info data
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsGetHDMISPDInfo (dsHdmiInPort_t iHdmiPort, unsigned char **data);

/**
 * @brief Sets the EDID version to be used for a given port id
 * 
 * This function sets the EDID version to be used for a given port id
 *
 * @param[in] iHdmiPort     - HDMI input port. @see dsHdmiInPort_t
 * @param[in] iEdidVersion  - input EDID version number to set @todo Create an enum iEdidVersion
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetEdidVersion()
 * 
 */
dsError_t dsSetEdidVersion (dsHdmiInPort_t iHdmiPort, int iEdidVersion);

/**
 * @brief Gets the EDID version currently being used for the given port id
 * 
 * This function gets the EDID version currently being used for the given port id
 *
 * @param[in] iHdmiPort     - HDMI input port. @see dsHdmiInPort_t
 * @param[out] iEdidVersion - input EDID version number
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetEdidVersion()
 * 
 */
dsError_t dsGetEdidVersion (dsHdmiInPort_t iHdmiPort, int *iEdidVersion);

/**
 * @brief Checks whether ALLM status is enabled or disabled for the specific HDMI input port
 * 
 * This function checks whether ALLM status is enabled or disabled for the specific HDMI input port
 *
 * @param[in] iHdmiPort     - HDMI input port. @see dsHdmiInPort_t
 * @param[out] allmStatus   - Flag to control the allm status
 *                              ( @a true to enable, @a false to disable)
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsGetAllmStatus (dsHdmiInPort_t iHdmiPort, bool *allmStatus);

/**
 * @brief Gets all the supported game features list information.
 * 
 * This function gets all the supported game features list information.
 *
 * @param[out] features         - List of all supported game features. 
 *                                      @see dsSupportedGameFeatureList_t
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsGetSupportedGameFeaturesList (dsSupportedGameFeatureList_t* features);

/**
 * @brief Gets the current AV latency
 * 
 * This function gets the current AV latency.
 *
 * @param[out] audio_latency    - Audio latency value. Max value 500ms. Min value 0
 * @param[out] video_latency    - Video latency value. Max value 500ms. Min value 0
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHdmiInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsGetAVLatency (int *audio_latency, int *video_latency);

#ifdef __cplusplus
}
#endif
#endif /* _DS_dsHdmiInH_ */

/** @} */ // End of DSHAL_HdmiIn_API doxygen group 
/** @} */ // End of DeviceSettings_Module
/** @} */ // End of HPK
