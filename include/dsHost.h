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
 * - EDID:    Extended Display Information Data.
 * - CPU:     Central Processing Unit
 * - SoC:     System on chip
 * 
 * @ingroup DSSETTINGS_HAL
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
 * the Host subsystem. The Host subsystem manages system-specific HAL operations.
 *  @{
 */

/** @defgroup DSHAL_HOST_API Device Settings HAL Host Public API
 *
 *
 *  @{
 */


#ifndef _DS_HOST_H_
#define _DS_HOST_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "dsError.h"
#include "dsTypes.h"

#define EDID_DATA_SIZE 256
#define EDID_MAX_DATA_SIZE 512

/**
 * @brief Initialize the Host HAL.
 * 
 * This function has to initialize any needed resources within the module.
 *
 * @return dsError_t                   - Status
 * @retval dsERR_NONE                   - Success
 * @retval dsERR_ALREADY_INITIALIZED    - Function is already initialized.
 * @retval dsERR_GENERAL                - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * @see dsHostTerm()
 * 
 * 
 */

dsError_t dsHostInit();

/**
 * @brief Terminate the Host sub-system.
 *
 * This function has to release all the resources allocated during the init function.
 *
 * @return dsError_t               - Status
 * @retval dsERR_NONE               - Success 
 * @retval dsERR_NOT_INITIALIZED    - Module is not initialised
 * @retval dsERR_GENERAL            - General failure.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsHostInit()
 * 
 */

dsError_t dsHostTerm();

/**
 * @brief This function returns the preferred sleep mode which is persisted.
 * 
 * This function is not apart of the HAL interface.
 *
 * @param[out] pMode    - Current preferred sleep mode settings of the device. 
 *                              See dsSleepMode_t for possible values.
 * 
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetPreferredSleepMode()
 * 
 */

dsError_t dsGetPreferredSleepMode(dsSleepMode_t *pMode);

/**
 * @brief This function sets the preferred sleep mode. 
 * 
 * This function is not apart of the HAL interface.
 *
 * @param[in] mode  - Sleep mode to set. See dsSleepMode_t for possible values.
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetPreferredSleepMode()
 * 
 */

dsError_t dsSetPreferredSleepMode(dsSleepMode_t mode);

/**
 * @brief This function gets the CPU temperature in centigrade.
 * 
 *
 * @param[out] cpuTemperature   - CPU temperature value is obtained in centigrade 
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsError_t dsGetCPUTemperature(float *cpuTemperature);

/**
 * @brief Get DS HAL API Version.
 *
 * @param[out] versionNumber    - 4 Bytes of version number of DS HAL. 
 *                                  Two Most significant Bytes are Major number,
 *                                  Two Least Significant Bytes are minor number.
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetVersion()
 * 
 */


@todo Version to be discussed with  amit.
dsError_t dsGetVersion(uint32_t *versionNumber);

/**
 * @brief Allows the Caller to set the runtime version of the dsHAL
 *
 * @param[in] versionNumber - 4 Bytes of version number of DS HAL.
 *                              Two Most significant Bytes are Major number,
 *                              Two Least Significant Bytes are minor number.
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetVersion()
 * 
 */

dsError_t dsSetVersion(uint32_t versionNumber);

/**
 * @brief This function returns SOC ID
 *
 * @param[out] socID    - 8 byte Chip ID programmed to the CHIP One Time Programmable area.
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsError_t dsGetSocIDFromSDK(char *socID);

/**
 * @brief This function is used to get the host EDID and length
 *
 * @param[out] edid     - host EDID.
 * @param[out] length   - length of host EDID. Min value of 0. 
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsError_t dsGetHostEDID(unsigned char *edid, int *length);

/** @} */ // End of DSHAL_HOST_API doxygen group 
/** @} */ // End of DS HAL
/** @} */ // End of HPK
#ifdef __cplusplus
}
#endif
#endif /* _DS_HOST_H_ */
