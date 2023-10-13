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

/** @addtogroup Device_Settings Device Settings Module
 * @{
 */

/** @addtogroup Device_Settings_HAL Device Settings HAL
 * @par Application API Specification
 * Described herein are the DeviceSettings HAL types and functions that are part of
 *  @{
 */

/** @addtogroup DSHAL_LOGGER_H DS Logger Header
 *  @{
 * @par Application API Specification
 * Logging interface
 */

/** @defgroup DSHAL_HAL_LOGGER_REGISTER Device Settings HAL Logger Register
 *
 *
 *  @{
 */


#ifndef __DS_HAL_REGISTER_H__
#define __DS_HAL_REGISTER_H__

typedef void (*DSHal_LogCb)(int priority,const char *);

#ifdef __cplusplus
extern "C"
{
#endif

void DSHal_RegisterForLog(DSHal_LogCb cb);

#ifdef __cplusplus
};
#endif


#endif // End of __DS_HAL_REGISTER_H__

/** @} */ // End of DSHAL_HAL_LOGGER_REGISTER
/** @} */ // End of DSHAL_LOGGER_H
/** @} */ // End of Device Settings HAL
/** @} */ // End of Device Settings Module
/** @} */ // End of HPK