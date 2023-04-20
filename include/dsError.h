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
 * @file
 *
 * @brief Device Settings HAL error codes.
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
 * - cb:      Callback function (suffix).
 * - DS:      Device Settings.
 * - HAL:     Hardware Abstraction Layer.
 * - _t:      Type (suffix).
 *
 * @par Implementation Notes
 * -# None
 *
 */

/**
* @defgroup devicesettings Device Settings
* @{
* @defgroup hal Device Settings HAL
* @{
**/

#ifndef _DS_ERROR_H_ 
#define _DS_ERROR_H_

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup DSHAL_ERROR Device Settings HAL Error Codes
*  @ingroup DSHAL_API
*
*  Defined hereunder are the error codes that are used in the Device Settings library.
*
*  @{
*/

/** 
 * @brief Device Settings API Error return codes.
 * 
 * A non-zero value indicates an error.
 * 
 */

typedef enum {
    dsERR_NONE = 0,                 ///< Input output operation is successful          
    dsERR_GENERAL = 1,              ///< Operation general error
    dsERR_INVALID_PARAM,            ///< Invalid parameter is passed to the module
    dsERR_INVALID_STATE,            ///< Module is not initialised
    dsERR_OPERATION_NOT_SUPPORTED,  ///< Operation not supported
    dsERR_UNKNOWN                   ///< Unknown error
} dsError_t;

/* End of DSHAL_ERROR doxygen group */
/**
 * @}
 */

#ifdef __cplusplus
}
#endif
#endif /* _DS_ERROR_H_ */

/** @} */
/** @} */
