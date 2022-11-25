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
* @defgroup devicesettings
* @{
* @defgroup hal
* @{
**/


#ifndef _DS_dsCompositeInH_
#define _DS_dsCompositeInH_

#include <sys/types.h>
#include "dsError.h"
#include "dsTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup DSHAL_CompositeIn_API Device Settings HAL COMPOSITE Input Public APIs
 *  @ingroup devicesettingshalapi
 *  @{
 */

/**
 * @brief Initialize the underlying COMPOSITE Input sub-system.
 *
 * This function must initialize the COMPOSITE Input module and any associated data
 * structures.
 *
 * @param None
 * @return Device Settings error code
 * @retval    ::dsError_t
 */
dsError_t dsCompositeInInit (void);

/**
 * @brief Terminate the underlying COMPOSITE Input sub-system.
 *
 * This function must terminate the COMPOSITE Input module and any associated data
 * structures.
 *
 * @param None
 * @return Device Settings error code
 * @retval    ::dsError_t
 */
dsError_t dsCompositeInTerm (void);

/**
 * @brief Get the number of COMPOSITE Input ports on the set-top.
 *
 * This function is used to get the number of COMPOSITE Input ports on the set-top.
 *
 * @param [in]pNumberOfInputs   number of COMPOSITE Input ports.
 * @return Device Settings error code
 * @retval    ::dsError_t
 */
dsError_t dsCompositeInGetNumberOfInputs (uint8_t *pNumberOfInputs);

/**
 * @brief Get the COMPOSITE Input Status.
 *
 * This function is used to get the current COMPOSITE Input Status.
 *
 * @param [in]pStatus       COMPOSITE Input enabled, COMPOSITE Input port connected,
 *                          Active COMPOSITE Input port, and HW Pass-Through enabled.
 * @return Device Settings error code
 * @retval    ::dsError_t
 */
dsError_t dsCompositeInGetStatus (dsCompositeInStatus_t *pStatus);

/**
 * @brief Select the COMPOSITE Input port to be presented.
 *
 * This function is used to select the COMPOSITE Input port for presentation.
 *
 * @param [in]ePort       COMPOSITE Input port to be presented,
 * @return Device Settings error code
 * @retval    ::dsError_t
 */
dsError_t dsCompositeInSelectPort (dsCompositeInPort_t Port);

/**
 * @brief Scale the COMPOSITE In video
 * This function is used to scale the COMPOSITE In video.
 *
 * @param[in] x      : x coordinate for the video
 * @param[in] y      : y coordinate for the video
 * @param[in] width  : width of the video
 * @param[in] height : height of the video
 *
 * @return Device Settings error code
 * @retval    ::dsError_t
 */
dsError_t dsCompositeInScaleVideo (int32_t x, int32_t y, int32_t width, int32_t height);


/**
 * @brief Callback function used to notify applications of COMPOSITE In hot plug status
 *
 * HAL Implementation should call this method to deliver COMPOSITE In hot plug status
 * to the application (e.g. Connect/Disconnect for Port 0/1).
 *
 * @param Port                COMPOSITE Input port.
 * @param isPortConnected     Connection state of COMPOSITE In Port.
 *
 *
 * @return None.
 */
typedef void (*dsCompositeInConnectCB_t)(dsCompositeInPort_t Port, bool isPortConnected);


/**
 * @brief Register for the COMPOSITE Input hot plug event.
 *
 * This function is used to register for the COMPOSITE Input hot plug event.
 *
 * @param[in] CBFunc COMPOSITE Input hot plug callback function.
 * @return Device Settings error code
 * @retval    ::dsError_t
 */
dsError_t dsCompositeInRegisterConnectCB (dsCompositeInConnectCB_t CBFunc);


/**
 * @brief Callback function used to notify applications of Composite In signal change status
 *
 * HAL Implementation should call this method to deliver Composite In signal change status
 * to the application (e.g. NoSignal/UnstableSignal/NotSupportedSignal/StableSignal for Composite In ports).
 *
 * @param port                Composite Input port.
 * @param sigStatus           signal Status of Composite In Port.
 *
 *
 * @return None.
 */
typedef void (*dsCompositeInSignalChangeCB_t)(dsCompositeInPort_t port, dsCompInSignalStatus_t sigStatus);


/**
 * @brief Register for the Composite Input Signal Change event.
 *
 * This function is used to register for the Composite Input Signal Change event.
 *
 * @param[in] CBFunc Composite Input Signal change callback function.
 * @return Device Settings error code
 * @retval    ::dsError_t
 */
dsError_t dsCompositeInRegisterSignalChangeCB (dsCompositeInSignalChangeCB_t CBFunc);



/**
 * @brief Callback function used to notify applications of Composite Input status
 *
 * HAL Implementation should call this method to deliver Composite Input status
 * to the application (e.g. port, isPresented(true/false) etc. for Composite In ports).
 *
 * @param inputStatus         Composite Input status of a specific Port.
 *
 *
 * @return None.
 */
typedef void (*dsCompositeInStatusChangeCB_t)(dsCompositeInStatus_t inputStatus);


/**
 * @brief Register for the Composite Input Status Change event.
 *
 * This function is used to register for the Composite Input Status Change event.
 *
 * @param[in] CBFunc Composite Input Status change callback function.
 * @return Device Settings error code
 * @retval    ::dsError_t
 */
dsError_t dsCompositeInRegisterStatusChangeCB (dsCompositeInStatusChangeCB_t CBFunc);


/* End of DSHAL_CompositeIn_API doxygen group */
/**
 * @}
 */

#ifdef __cplusplus
}
#endif
#endif /* _DS_dsCompositeInH_ */

/** @} */
/** @} */
