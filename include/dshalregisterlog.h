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
 *  @{
 */


/** 
 * @file
 *
 * @brief Device Settings HAL error codes.
 * 
 * @par Abbreviations
 * - cb:      Callback function (suffix).
 * - DS:      Device Settings.
 * - HAL:     Hardware Abstraction Layer.
 * - _t:      Type (suffix).
 * 
 * @ingroup DSSETTINGS_HAL
 */

#ifndef _DS_HAL_REGISTER_H_
#define _DS_HAL_REGISTER_H_

/**
 * @brief HAL will call this function to do the logging to respective log 
 *                  files based on the priority
 *
 * @param[in] priority      Priority of the log that is being made. Possible values:
 *                                   INFO_LEVEL, WARN_LEVEL, ERROR_LEVEL, DEBUG_LEVEL
 * @param[in] log           Log to be written the log file.
 *
 * @warning  This API is Not thread safe.
 */

typedef void (*DSHal_LogCb)(int priority,const char * log);
#ifdef __cplusplus
extern "C"
{
#endif
/**
 * @brief This function is used to register the call back to logging functionality.
 *
 * @param[in] cb    callback function. See DSHal_LogCb
 *
 * @warning  This API is Not thread safe.
 */

void DSHal_RegisterForLog(DSHal_LogCb cb);
#ifdef __cplusplus
};
#endif

#endif


/** @} */
/** @} */
