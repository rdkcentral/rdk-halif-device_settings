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

#ifndef _DS_HAL_LOGGER_H_
#define _DS_HAL_LOGGER_H_

#include <stdio.h>
#include "dshalregisterlog.h"

/**
 * @brief This function logs the sent message based on the priority.
 * 
 * @param[in]  priority - Priority of the message to be logged.
 * @param[out] format   - Message format.
 * 
 * @return int         - Status. Success if non-negative, failure if negative.
 * 
 */

int ds_hal_log(int priority,const char *format, ...);  

#define INFO_LEVEL   0  ///< Messages giving a general overview of the program execution.
#define WARN_LEVEL   1  ///< Messages giving warning about the program execution.
#define ERROR_LEVEL  2  ///< Messages giving an overview of program errors.
#define DEBUG_LEVEL  3  ///< Messages giving an overview of the program execution for debugging.

#define INT_INFO(FORMAT, ...)           ds_hal_log(INFO_LEVEL ,FORMAT, ##__VA_ARGS__ )      ///< To handle logging of info level logs.
#define INT_WARN(FORMAT, ...)           ds_hal_log(WARN_LEVEL ,FORMAT,  ##__VA_ARGS__ )     ///< To handle logging of warn level logs.
#define INT_ERROR(FORMAT, ...)          ds_hal_log(ERROR_LEVEL ,FORMAT,  ##__VA_ARGS__ )    ///< To handle logging of error level logs.
#define INT_DEBUG(FORMAT, ...)          ds_hal_log(DEBUG_LEVEL ,FORMAT,  ##__VA_ARGS__ )    ///< To handle logging of debug level logs.

#endif

/** @} */
/** @} */
