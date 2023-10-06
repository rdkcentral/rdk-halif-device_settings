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
 * @file dsDisplay.h
 * 
 *  @brief Device Settings HAL error codes.
 *
 * This API defines common error codes used by the Device Settings HAL.
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
 * - cb     - Callback function (suffix)
 * - DS     - Device Settings
 * - HAL    - Hardware Abstraction Layer
 * - EDID   - Extended Display Identification Data
 * - Rx     - Receive and Transmit
 * - HDCP   - High-bandwidth Digital Content Protection
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

/** @addtogroup DS_Manager_HAL DS Manager Hal
 * @par Application API Specification
 *  Described herein are DeviceSettings HAL types and functions that are part of the
 *  Display subsystem. The Display subsystem manages operations relating to connected
 *  display devices, e.g. TVs.
 *  Vendors please add appropriate events needed for your implementation.
 *  @{
 */

/** @defgroup DSHAL_DISPLAY_API Device Settings HAL Video Port Public API
 *
 *
 *  @{
 */

#ifndef __DS_VIDEODISPLAY_H__
#define __DS_VIDEODISPLAY_H__

#include "dsError.h"
#include "dsTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @enum _dsDisplayEvent_t
 * @brief This enumeration defines standard display event types. 
 * @note  Appropriate events can be added based on requirement.
 */
typedef enum _dsDisplayEvent_t {
    dsDISPLAY_EVENT_CONNECTED = 0,  ///< Display connected event   
    dsDISPLAY_EVENT_DISCONNECTED,   ///< Display disconnected event       
    dsDISPLAY_RXSENSE_ON,           ///< Rx Sense ON event
    dsDISPLAY_RXSENSE_OFF,          ///< Rx Sense OFF event
    dsDISPLAY_HDCPPROTOCOL_CHANGE,  ///< HDCP Protocol Version Change event
    dsDISPLAY_EVENT_MAX             ///< Display max event
} dsDisplayEvent_t;

/**
 * @brief Callback function used to notify display related events to application.
 * 
 * This callback is triggered whenever there is a display related change and notify the application. 
 *
 * @param[in]  handle   - Handle of the display device
 * @param[in]  event    - Display event. @see dsDisplayEvent_t
 * @param[in] eventData - Data associated with the event(optional parameter)
 *
 * @note HAL implementation is responsible for allocation of memory needed for event data. 
 * The memory can be free'd after callback returns.
 *
 * @return None
 * 
 */
typedef void (*dsDisplayEventCallback_t)(int handle, dsDisplayEvent_t event,
                                             void *eventData/*Optional*/);

/**
 * @brief Initializes the DS Display sub-system.
 *
 * This function initializes all required resources for Display sub-system and
 * is required to be called before the other APIs in this module.
 * 
 * @return dsError_t                    - Status
 * @retval dsERR_NONE                   - Success
 * @retval dsERR_ALREADY_INITIALIZED    - Function is already initialized
 * @retval dsERR_GENERAL                - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe
 * 
 * @see dsDisplayTerm()
 * 
 */
dsError_t dsDisplayInit();

/**
 * @brief Gets the handle of connected display device.
 * 
 * This function is used to get the handle for the connected display device corresponding to the 
 * specified video port.
 *
 * @param[in]  vType    - Type of video port. @see dsVideoPortType_t
 * @param[in]  index    - Index of the video port
 *                          Max index is platform specific. Min value is 0.
 * @param[out] handle   - Pointer to hold the handle of display device corresponding 
 *                          to specified video port
 * 
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported.
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsDisplayInit() must be called before calling this API
 * 
 * @warning  This API is Not thread safe
 * 
 */
 dsError_t dsGetDisplay(dsVideoPortType_t vType, int index, intptr_t *handle);
  
/** 
 * @brief Gets the EDID information from the specified display device.
 * 
 * This function gets the EDID information from the HDMI/DVI display corresponding to
 * the specified display device handle.
 * 
 * @param[in]  handle   - Handle of the display device
 * @param[out] edid     - EDID info of the specified display device. @see dsDisplayEDID_t
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsDisplayInit() and dsGetDisplay() must be called before calling this API
 * 
 * @warning  This API is Not thread safe
 * 
 */
dsError_t dsGetEDID(intptr_t handle, dsDisplayEDID_t *edid);

/**
 * @brief Gets the EDID buffer and EDID length of connected display device. 
 * 
 * This function is used to get the EDID buffer and size of the connected display corresponding to
 * the specified display device handle.
 *
 * @param[in] handle    - Handle of the display device
 * @param[out] edid     - EDID raw buffer of the current display device
 * @param[out] length   - length of the EDID buffer data. Min value is 0
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsDisplayInit() and dsGetDisplay() must be called before calling this API
 * 
 * @warning  This API is Not thread safe
 * 
 */
dsError_t dsGetEDIDBytes(intptr_t handle, unsigned char **edid, int *length);

/**
 * @brief Gets the aspect ratio of connected display device.
 * 
 * This function returns the aspect ratio of the display corresponding to the 
 * specified display device handle.
 *
 * @param[in]  handle       - Handle of the display device
 * @param[out] aspectRatio  - Current aspect ratio of the specified display device
 *                              @see dsVideoAspectRatio_t
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsDisplayInit() and dsGetDisplay() must be called before calling this API
 * 
 * @warning  This API is Not thread safe
 * 
 */
dsError_t dsGetDisplayAspectRatio(intptr_t handle, dsVideoAspectRatio_t *aspectRatio);

/**
 * @brief Terminate the display sub-system.
 * 
 * This function resets any data structures used within Display sub-system,
 * and releases all the resources allocated during the init function.
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsDisplayInit() and dsGetDisplay() must be called before calling this API
 * 
 * @warning  This API is Not thread safe
 * 
 * @see dsDisplayInit()
 * 
 */
dsError_t dsDisplayTerm();

/**
 * @brief Callback registration which listens for display events 
 * 
 * This function registers a callback for display events corresponding to
 * the specified display device handle.
 * 
 * @note Caller should install at most one callback function per handle.
 * Multiple listeners are supported at Caller layer and thus not
 * required in HAL implementation.
 *
 * @param[in] handle    - Handle of the display device
 * @param[in] cb        - Display Event callback function. @see dsDisplayEventCallback_t
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe
 * 
 * @see dsRegisterDisplayEventCallback()
 * 
 */
dsError_t dsRegisterDisplayEventCallback(intptr_t handle, dsDisplayEventCallback_t cb);

/** @} */ // End of DSHAL_DISPLAY_API doxygen group 
/** @} */ // End of DS HAL
/** @} */ // End of HPK

#ifdef __cplusplus
}
#endif