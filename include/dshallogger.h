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
* @defgroup devicesettings
* @{
* @defgroup hal
* @{
**/


#ifndef _DS_HAL_LOGGER_H_
#define _DS_HAL_LOGGER_H_

#include <stdio.h>
#include "dshalregisterlog.h"

int ds_hal_log(int priority,const char *format, ...);

#define INFO_LEVEL   0
#define WARN_LEVEL   1
#define ERROR_LEVEL  2
#define DEBUG_LEVEL  3




#define INT_INFO(FORMAT, ...)           ds_hal_log(INFO_LEVEL ,FORMAT, ##__VA_ARGS__ )
#define INT_WARN(FORMAT, ...)           ds_hal_log(WARN_LEVEL ,FORMAT,  ##__VA_ARGS__ )
#define INT_ERROR(FORMAT, ...)          ds_hal_log(ERROR_LEVEL ,FORMAT,  ##__VA_ARGS__ )
#define INT_DEBUG(FORMAT, ...)          ds_hal_log(DEBUG_LEVEL ,FORMAT,  ##__VA_ARGS__ )


#endif



/** @} */
/** @} */
