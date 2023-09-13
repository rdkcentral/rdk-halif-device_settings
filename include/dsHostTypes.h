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
 * @file dsTypes.h
 *
 * @brief HAL types.
 *
 * @brief This API defines common types used by the HAL.
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

/** 
 * @defgroup DSSETTINGS_HAL HAL Types & Public API
 * HAL types and public API definitions.
 * @ingroup DSSETTINGS
 * @{
 */

/** @addtogroup DSHAL_HOST HAL Host Types
 * @ingroup DSHAL_API
 *  @{
 */

/**
 * @brief This enumeration defines the type of sleep modes.
 * @see dsSleepMode_isValid
 */
typedef enum _dsSleepMode_t{
    dsHOST_SLEEP_MODE_LIGHT,    ///< Light sleep mode.                              
    dsHOST_SLEEP_MODE_DEEP,     ///< Deep sleep mode.                               
    dsHOST_SLEEP_MODE_MAX,      ///< Out of range                 
} dsSleepMode_t;

/* End of DSHAL_HOST_TYPES doxygen group */
/**
 * @}
 */
/** @} */ // End of DSHAL_API HAL Data Types
/** @} */ // End of HPK