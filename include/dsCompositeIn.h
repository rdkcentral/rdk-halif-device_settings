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
 * @addtogroup HPK Hardware Porting Kit
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

/**
 * @addtogroup Device_Settings Device Settings Module
 * @{
 */

/**
 * @addtogroup Device_Settings_HAL Device Settings HAL
 * @par Application API Specification
 * Described herein are the DeviceSettings HAL types and functions that are part of
 * the CompositeIn subsystem. The CompositeIn subsystem manages system-specific HAL operations.
 *  @{
 */

/**
*   @defgroup dsCompositeIn_HAL DS CompositeIn HAL
 *  @{
 * @par Application API Specification
 * dsCompositeIn HAL provides an interface for managing the CompositeIn settings for the device settings module
 */

/**
 * @defgroup DSHAL_COMPOSITE_IN_API DS HAL Composite Input Public APIs
 *  @{
 */


/**
 * @file dsCompositeIn.h
 *
 * @brief Device Settings HAL COMPOSITE Input Public API.
 * This API defines the HAL for the Device Settings COMPOSITE Input interface.
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

#ifndef __DS_COMPOSITE_IN_H__
#define __DS_COMPOSITE_IN_H__

#include "dsError.h"
#include "dsCompositeInTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initializes the underlying COMPOSITE Input sub-system.
 *
 * This function must initialize the COMPOSITE Input module and any associated data
 * structures.
 *
 * @return dsError_t                      - Status
 * @retval dsERR_NONE                     - Success
 * @retval dsERR_ALREADY_INITIALIZED      - Module is already initialised
 * @retval dsERR_OPERATION_NOT_SUPPORTED  - The attempted operation is not supported; e.g: source devices
 * @retval dsERR_GENERAL                  - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsCompositeInTerm()
 */

dsError_t dsCompositeInInit (void);

/**
 * @brief Terminates the underlying COMPOSITE Input sub-system.
 *
 * This function must terminate the COMPOSITE Input module and any associated data
 * structures.
 *
 * @return dsError_t                      - Status
 * @retval dsERR_NONE                     - Success
 * @retval dsERR_NOT_INITIALIZED          - Module is not initialised
 * @retval dsERR_OPERATION_NOT_SUPPORTED  - The attempted operation is not supported; e.g: source devices
 * @retval dsERR_GENERAL                  - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 * @pre  dsCompositeInInit() should be called before calling this API.
 * 
 * @see dsCompositeInInit()
 */

dsError_t dsCompositeInTerm (void);

/**
 * @brief Gets the number of COMPOSITE Input ports on the specific platform.
 *
 * This function is used to get the number of COMPOSITE Input ports on the specific platform.
 *
 * @param[out] pNumberOfInputs   - number of COMPOSITE Input ports. Min 0. Max please refer ::dsCompositeInPort_t
 *
 * @return dsError_t                      - Status
 * @retval dsERR_NONE                     - Success
 * @retval dsERR_INVALID_PARAM            - Parameter passed to this function is invalid
 * @retval dsERR_NOT_INITIALIZED          - Module is not initialised
 * @retval dsERR_OPERATION_NOT_SUPPORTED  - The attempted operation is not supported; e.g: source devices
 * @retval dsERR_GENERAL                  - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 * @pre  dsCompositeInInit() should be called before calling this API.
 */

dsError_t dsCompositeInGetNumberOfInputs (uint8_t *pNumberOfInputs);

/**
 * @brief Gets the COMPOSITE Input Status.
 *
 * This function is used to get the status of all COMPOSITE Input Status.
 *
 * @param [out] pStatus - status of compositeIn ports. Please refer ::dsCompositeInStatus_t
 * 
 * @return dsError_t                      - Status
 * @retval dsERR_NONE                     - Success
 * @retval dsERR_INVALID_PARAM            - Parameter passed to this function is invalid
 * @retval dsERR_NOT_INITIALIZED          - Module is not initialised
 * @retval dsERR_OPERATION_NOT_SUPPORTED  - The attempted operation is not supported; e.g: source devices
 * @retval dsERR_GENERAL                  - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 * @pre  dsCompositeInInit() should be called before calling this API.
 */
dsError_t dsCompositeInGetStatus (dsCompositeInStatus_t *pStatus);

/**
 * @brief Sets the COMPOSITE Input port as active available for presentation.
 *
 * This function is used to set the COMPOSITE Input port for presentation.
 *
 * @param[in] Port  - COMPOSITE Input port to be presented. Please refer ::dsCompositeInPort_t
 * 
 * @return dsError_t                      - Status
 * @retval dsERR_NONE                     - Success
 * @retval dsERR_INVALID_PARAM            - Parameter passed to this function is invalid(port is not present or index is out of range)
 * @retval dsERR_NOT_INITIALIZED          - Module is not initialised
 * @retval dsERR_OPERATION_NOT_SUPPORTED  - The attempted operation is not supported; e.g: source devices
 * @retval dsERR_GENERAL                  - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 * @note When a port is selected that port should be set as activePort in ::dsCompositeInStatus_t.
 *              Also, if there is a signal (ie isPortConnected[that port ID] is true), once active, isPresented should be set to true as well.
 * 
 * @pre  dsCompositeInInit() should be called before calling this API.
 */
dsError_t dsCompositeInSelectPort (dsCompositeInPort_t Port);

/**
 * @brief Scales the COMPOSITE In video
 * This function scales the COMPOSITE input video. The width and height, based on the x, y coordinates, 
 *      cannot exceed that of the current resolution of the device.
 *      e.g.  x(in pixels)+width cannot be greater then the width of the resolution.
 *      The current resolution will return by ::dsGetResolution()
 *
 * @param[in] x         - x coordinate for the video. Min of 0. Max is based on the current resolution
 * @param[in] y         - y coordinate for the video. Min of 0. Max is based on the current resolution
 * @param[in] width     - width of the video. Min of 0. Max is based on the current resolution
 * @param[in] height    - height of the video. Min of 0. Max is based on the current resolution
 *
 * @return dsError_t                      - Status
 * @retval dsERR_NONE                     - Success
 * @retval dsERR_INVALID_PARAM            - Parameter passed to this function is invalid
 * @retval dsERR_NOT_INITIALIZED          - Module is not initialised
 * @retval dsERR_OPERATION_NOT_SUPPORTED  - The attempted operation is not supported; e.g: source devices
 * @retval dsERR_GENERAL                  - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 * @pre  dsCompositeInInit(), dsCompositeInSelectPort() should be called before calling this API.
 */

dsError_t dsCompositeInScaleVideo (int32_t x, int32_t y, int32_t width, int32_t height);

/**
 * @brief Callback function used to notify applications of COMPOSITE In hot plug status
 *
 * HAL Implementation should call this method to deliver COMPOSITE In hot plug status
 * to the application (e.g. Connect/Disconnect for Port 0/1).
 *
 * @param[in] Port              - COMPOSITE Input port. Please refer ::dsCompositeInPort_t
 * @param[in] isPortConnected   - Connection state of COMPOSITE In Port. @a true if connected, @a false if not
 *
 * @return None.
 * 
 * @pre  dsCompositeInRegisterConnectCB() should be called before calling this API.
 * 
 * @note This should update isPortConnected in ::dsCompositeInStatus_t when this callback is triggered.
 *          If this port is currently active and presents video after being connected, isPresented should also be updated
 * 
 * @see dsCompositeInRegisterConnectCB()
 */
typedef void (*dsCompositeInConnectCB_t)(dsCompositeInPort_t Port, bool isPortConnected);

/**
 * @brief Callback function used to notify applications of Composite In signal change status
 *
 * HAL Implementation should call this method to deliver Composite In signal change status
 * to the application (e.g. NoSignal/UnstableSignal/NotSupportedSignal/StableSignal for Composite In ports).
 *
 * @param[in] port      - Composite Input port. Please refer ::dsCompositeInPort_t
 * @param[in] sigStatus - signal Status of Composite In Port. Please refer ::dsCompInSignalStatus_t
 *
 * @return None.
 * 
 * @pre  dsCompositeInRegisterSignalChangeCB() should be called before calling this API.
 * 
 * @see dsCompositeInRegisterSignalChangeCB()
 */
typedef void (*dsCompositeInSignalChangeCB_t)(dsCompositeInPort_t port, dsCompInSignalStatus_t sigStatus);

/**
 * @brief Callback function used to notify applications of Composite Input status change event.
 *
 * HAL Implementation should call this method to deliver Composite Input status
 * to the application (e.g. port, isPresented(true/false) etc. for Composite In ports).
 *
 * @param[in] inputStatus   - Composite Input status of a specific Port. Please refer ::dsCompositeInStatus_t
 *
 * @return None.
 * 
 * @pre  dsCompositeInRegisterStatusChangeCB() should be called before calling this API.
 * 
 * @see dsCompositeInRegisterStatusChangeCB()
 * 
 * @note This callback should be triggered whenever dsCompositeInStatus_t is updated. Please refer ::dsCompositeInSelectPort(), ::dsCompositeInConnectCB_t()
 */
typedef void (*dsCompositeInStatusChangeCB_t)(dsCompositeInStatus_t inputStatus);

/**
 * @brief Registers the COMPOSITE Input hot plug event.
 *
 * This function is used to register for the COMPOSITE Input hot plug event.
 *
 * @param[in] CBFunc    - COMPOSITE Input hot plug callback function. Please refer ::dsCompositeInConnectCB_t
 * 
 * @return dsError_t                      - Status
 * @retval dsERR_NONE                     - Success
 * @retval dsERR_INVALID_PARAM            - Parameter passed to this function is invalid
 * @retval dsERR_NOT_INITIALIZED          - Module is not initialised
 * @retval dsERR_OPERATION_NOT_SUPPORTED  - The attempted operation is not supported; e.g: source devices
 * @retval dsERR_GENERAL                  - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 * @pre  dsCompositeInInit() should be called before calling this API.
 * 
 * @see dsCompositeInConnectCB_t()
 */
dsError_t dsCompositeInRegisterConnectCB (dsCompositeInConnectCB_t CBFunc);

/**
 * @brief Registers the Composite Input Signal Change event.
 *
 * This function is used to register for the Composite Input Signal Change event.
 *
 * @param[in] CBFunc    - Composite Input Signal change callback function. Please refer ::dsCompositeInSignalChangeCB_t
 * 
 * @return dsError_t                      - Status
 * @retval dsERR_NONE                     - Success
 * @retval dsERR_INVALID_PARAM            - Parameter passed to this function is invalid
 * @retval dsERR_NOT_INITIALIZED          - Module is not initialised
 * @retval dsERR_OPERATION_NOT_SUPPORTED  - The attempted operation is not supported; e.g: source devices
 * @retval dsERR_GENERAL                  - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 * @pre  dsCompositeInInit() should be called before calling this API.
 * 
 * @see dsCompositeInSignalChangeCB_t()
 */
dsError_t dsCompositeInRegisterSignalChangeCB (dsCompositeInSignalChangeCB_t CBFunc);

/**
 * @brief Registers the Composite Input Status Change event.
 *
 * This function is used to register for the Composite Input Status Change event.
 *
 * @param[in] CBFunc    - Composite Input Status change callback function. Please refer ::dsCompositeInStatusChangeCB_t
 *
 * 
 * @return dsError_t                      - Status
 * @retval dsERR_NONE                     - Success
 * @retval dsERR_INVALID_PARAM            - Parameter passed to this function is invalid
 * @retval dsERR_NOT_INITIALIZED          - Module is not initialised
 * @retval dsERR_OPERATION_NOT_SUPPORTED  - The attempted operation is not supported; e.g: source devices
 * @retval dsERR_GENERAL                  - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 * @pre  dsCompositeInInit() should be called before calling this API.
 * 
 * @see dsCompositeInStatusChangeCB_t()
 */

dsError_t dsCompositeInRegisterStatusChangeCB (dsCompositeInStatusChangeCB_t CBFunc);

#ifdef __cplusplus
}
#endif
#endif /* __DS_COMPOSITE_IN_H__ */

/** @} */ // End of DS HAL Composite Input Public APIs
/** @} */ // End of DS CompositeIn HAL
/** @} */ // End of Device Settings HAL
/** @} */ // End of Device Settings Module
/** @} */ // End of HPK
