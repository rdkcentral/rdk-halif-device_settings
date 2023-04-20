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
