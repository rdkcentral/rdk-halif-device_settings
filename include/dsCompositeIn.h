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
 * - cb:      Callback function (suffix).
 * - DS:      Device Settings.
 * - HAL:     Hardware Abstraction Layer.
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
 * Described herein are the DeviceSettings HAL types and functions that are part of
 * the CompositeIn subsystem. The CompositeIn subsystem manages system-specific HAL operations.
 *  @{
 */

/** @defgroup DSHAL_COMPOSITEIN_API Device Settings HAL Composite Public API
 *
 *  @{
 */

#ifndef _DS_dsCompositeInH_
#define _DS_dsCompositeInH_

#include <sys/types.h>
#include "dsError.h"
#include "dsTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initializes the Composite input Hal.
 *
 *
 * @return dsError_t                   - Status
 * @retval dsERR_NONE                   - Success 
 * @retval dsERR_ALREADY_INITIALIZED    - Function is already initialized.
 * @retval dsERR_GENERAL                - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsCompositeInTerm()
 * 
 * 
 */

dsError_t dsCompositeInInit (void);

/**
 * @brief This function will terminate the underlying COMPOSITE Input sub-system.
 * Subsequent calls will return dsERR_NONE.
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsCompositeInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsCompositeInInit()
 * 
 */

dsError_t dsCompositeInTerm (void);

/**
 * @brief This function is used to get the number of COMPOSITE Input ports on the 
 *              specific platform for eg: set-top.
 *
 * @param[in] pNumberOfInputs   - number of COMPOSITE Input ports.
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsCompositeInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsError_t dsCompositeInGetNumberOfInputs (uint8_t *pNumberOfInputs);

/**
 * @brief This function is used to get the current COMPOSITE Input Status.
 *
 * @param [out] pStatus - current status of the composite input. See dsCompositeInStatus_t.
 * 
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsCompositeInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsError_t dsCompositeInGetStatus (dsCompositeInStatus_t *pStatus);

/**
 * @brief This function is used to select the COMPOSITE Input port for presentation.
 *
 * @param[in] Port  - COMPOSITE Input port to be used. See dsCompositeInPort_t.
 * 
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsCompositeInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsError_t dsCompositeInSelectPort (dsCompositeInPort_t Port);

/**
 * @brief This function is used to scale the COMPOSITE In video.
 *
 * @param[in] x         - x coordinate for the video.
 * @param[in] y         - y coordinate for the video.
 * @param[in] width     - width of the video in pixels.
 * @param[in] height    - height of the video in pixels.
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsCompositeInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsError_t dsCompositeInScaleVideo (int32_t x, int32_t y, int32_t width, int32_t height);

/**
 * @brief HAL must call this function when composite hotplug status changes.
 *
 * @param[in] Port              - COMPOSITE Input port. See dsCompositeInPort_t.
 * @param[in] isPortConnected   - Connection state of COMPOSITE In Port. 
 *                                      True if connected, false if not.
 *
 * @return None.
 * @warning  This API is Not thread safe.
 * @see dsCompositeInRegisterConnectCB()
 */

typedef void (*dsCompositeInConnectCB_t)(dsCompositeInPort_t Port, bool isPortConnected);

/**
 * @brief This function is used to register for the COMPOSITE Input hot plug event.
 *
 * @param[in] CBFunc    - COMPOSITE Input hot plug callback function. 
 *                              See dsCompositeInConnectCB_t.
 * 
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsCompositeInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsCompositeInConnectCB_t()
 * 
 */

dsError_t dsCompositeInRegisterConnectCB (dsCompositeInConnectCB_t CBFunc);

/**
 * @brief HAL must call this function when the composite port connection status changes.
 *
 * @param[in] port      - Composite Input port. See dsCompositeInPort_t.
 * @param[in] sigStatus - signal Status of Composite In Port. See dsCompInSignalStatus_t.
 *
 * @warning  This API is Not thread safe.
 * 
 * @see dsCompositeInRegisterSignalChangeCB()
 */

typedef void (*dsCompositeInSignalChangeCB_t)(dsCompositeInPort_t port, dsCompInSignalStatus_t sigStatus);

/**
 * @brief This function is used to register for the Composite Input Signal Change event.
 *
 * @param[in] CBFunc    - Composite Input Signal change callback function. 
 *                              See dsCompositeInSignalChangeCB_t
 * 
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsCompositeInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsCompositeInSignalChangeCB_t()
 * 
 */

dsError_t dsCompositeInRegisterSignalChangeCB (dsCompositeInSignalChangeCB_t CBFunc);

/**
 * @brief This function must be called when the Composite Input status changes.
 *
 * @param[in] inputStatus   - Composite Input status of a specific Port. 
 *                                  See dsCompositeInStatus_t.
 *
 * @warning  This API is Not thread safe.
 * @see dsCompositeInRegisterStatusChangeCB()
 */

typedef void (*dsCompositeInStatusChangeCB_t)(dsCompositeInStatus_t inputStatus);

/**
 * @brief This function will register for the Composite Input Status Change event.
 *
 * This function is used to register for the Composite Input Status Change event.
 *
 * @param[in] CBFunc    - Composite Input Status change callback function. 
 *                              See dsCompositeInStatusChangeCB_t.
 * 
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsCompositeInInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsCompositeInStatusChangeCB_t()
 * 
 */

dsError_t dsCompositeInRegisterStatusChangeCB (dsCompositeInStatusChangeCB_t CBFunc);

/** @} */ // End of DSHAL_CompositeIn_API doxygen group 
/** @} */ // End of DS HAL
/** @} */ // End of HPK

#ifdef __cplusplus
}
#endif
#endif /* _DS_dsCompositeInH_ */

