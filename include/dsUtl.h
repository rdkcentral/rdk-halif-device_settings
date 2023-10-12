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
 * @brief Device Settings HAL utilities.
 *
 * This API defines some common utilities for the Device Settings HAL.
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
 * - HAL:     Hardware Abstraction Layer.
 *
 * @par Implementation Notes
 * -# None
 *
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
 *  @{
 */


/** @defgroup DSHAL_UTLS Device Settings HAL dsUtls
 *
 *
 *  @{
 */

#ifndef _DS_UTILS_H_
#define _DS_UTILS_H_

#include <stdio.h>

/** @addtogroup DSHAL_UTILS Device Settings HAL Utilities
 *  @ingroup DSHAL_API
 *  @{
 */

/**
 * @brief Device Settings general Assert Failure inline definition.
 */

#define dsUTL_ASSERT(x) do {\
    if (!(x)) printf("ASSERTFAILURE at %s-%d\r\n", __FUNCTION__, __LINE__);\
}\
while(0)

/**
 * @brief Device Settings general Array dimension calculation inline definition.
 */

#define dsUTL_DIM(arr) (sizeof((arr))/sizeof((arr)[0]))

/* End of DSHAL_UTILS doxygen group */
/**
 * @}
 */

#endif /* _DS_UTILS_H_ */

/** @} */ // End of DS Utls
/** @} */ // End of Device Settings HAL
/** @} */ // End of Device Settings Module
/** @} */ // End of HPK