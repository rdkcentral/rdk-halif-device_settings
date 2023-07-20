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
 * - HDCP:    High-bandwidth Digital Copy Protection.
 * - DTCP:    Digital Transmission Copy Protection.
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
 * @return dsStatus_t           - Status
 * @retval dsERR_NONE           - Success
 * @retval dsERR_INVALID_STATE  - Function is already initialized.
 * @retval dsERR_GENERAL        - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * @see dsHostTerm()
 * 
 * @todo: Change the dsERR_INVALID_STATE 
 *          to dsERR_ALREADY_INITIALIZED. Will do it in the next phase.
 * 
 */

dsStatus_t dsHostInit();

/**
 * @brief Set the power mode.
 *
 * This function sets the power mode of the host to active or standby and turns on/off
 * all the ouput ports.
 *
 * @param[in] newPower  - The power mode of the host. See dsPowerState_t.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 *
 * @note dsPOWER_OFF is not currently being used.
 * 
 * @pre dsHostInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetHostPowerMode()
 * 
 * @todo: Change the dsERR_INVALID_STATE 
 *          to dsERR_NOT_INITIALIZED. Will do it in the next phase.
 */

dsStatus_t dsSetHostPowerMode(int newPower);

/**
 * @brief Get the current power mode.
 *
 * This function gets the current power mode of the host. 
 *
 * @param[out] currPower    - current power state of the system mode on return. 
 *                                  See dsPowerState_t for possible returns.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetHostPowerMode()
 * 
 * @todo: Change the dsERR_INVALID_STATE 
 *          to dsERR_NOT_INITIALIZED. Will do it in the next phase.
 */

dsStatus_t dsGetHostPowerMode(int *currPower);

/**
 * @brief Terminate the Host sub-system.
 *
 * This function resets the data structures used within the Host module and releases any
 * handles specific to the host module.
 *
 * @return dsStatus_t           - Status
 * @retval dsERR_NONE           - Success 
 * @retval dsERR_INVALID_PARAM  - Invalid parameter value.
 * @retval dsERR_INVALID_STATE  - Module is not initialised
 * @retval dsERR_GENERAL        - General failure.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsHostInit()
 * 
 * @todo: Change the dsERR_INVALID_STATE 
 *          to dsERR_NOT_INITIALIZED. Will do it in the next phase.
 */

dsStatus_t dsHostTerm();

/**
 * @brief This function returns the preferred sleep mode which is persisted.
 *
 * @param[out] pMode    - Current preferred sleep mode settings of the device. 
 *                              See dsSleepMode_t for possible values.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetPreferredSleepMode()
 * 
 * @todo: Change the dsERR_INVALID_STATE 
 *          to dsERR_NOT_INITIALIZED. Will do it in the next phase.
 */

dsStatus_t dsGetPreferredSleepMode(dsSleepMode_t *pMode);

/**
 * @brief This function sets the preferred sleep mode. This value will persisted across reboots.
 *
 * @param[in] mode  - Sleep mode to set. See dsSleepMode_t for possible values.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetPreferredSleepMode()
 * 
 * @todo: Change the dsERR_INVALID_STATE 
 *          to dsERR_NOT_INITIALIZED. Will do it in the next phase.
 */

dsStatus_t dsSetPreferredSleepMode(dsSleepMode_t mode);

/**
 * @brief This function gets the CPU temperature in centigrade.
 *
 * @param[out] cpuTemperature   - CPU temperature value is obtained in centigrade 
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 * @todo: Change the dsERR_INVALID_STATE 
 *          to dsERR_NOT_INITIALIZED. Will do it in the next phase.
 */

dsStatus_t dsGetCPUTemperature(float *cpuTemperature);

/**
 * @brief Get DS HAL API Version.
 *
 * @param[out] versionNumber    - 4 Bytes of version number of DS HAL. 
 *                                  Two Most significant Bytes are Major number,
 *                                  Two Least Significant Bytes are minor number.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetVersion()
 * 
 * @todo: Change the dsERR_INVALID_STATE 
 *          to dsERR_NOT_INITIALIZED. Will do it in the next phase.
 */

dsStatus_t dsGetVersion(uint32_t *versionNumber);

/**
 * @brief Allows the Caller to set the runtime version of the dsHAL
 *
 * @param[in] versionNumber - 4 Bytes of version number of DS HAL.
 *                              Two Most significant Bytes are Major number,
 *                              Two Least Significant Bytes are minor number.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetVersion()
 * 
 * @todo: Change the dsERR_INVALID_STATE 
 *          to dsERR_NOT_INITIALIZED. Will do it in the next phase.
 */

dsStatus_t dsSetVersion(uint32_t versionNumber);

/**
 * @brief This function returns SOC ID
 *
 * @param[out] socID    - 8 byte Chip ID programmed to the CHIP One Time Programmable area.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 * @todo: Change the dsERR_INVALID_STATE 
 *          to dsERR_NOT_INITIALIZED. Will do it in the next phase.
 */

dsStatus_t dsGetSocIDFromSDK(char *socID);

/**
 * @brief This function is used to get the host EDID and length
 *
 * @param[out] edid     - host EDID.
 * @param[out] length   - length of host EDID. Min value of 0. 
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_STATE              - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 * @todo: Change the dsERR_INVALID_STATE 
 *          to dsERR_NOT_INITIALIZED. Will do it in the next phase.
 */

dsStatus_t dsGetHostEDID(unsigned char *edid, int *length);

/** @} */ // End of DSHAL_HOST_API doxygen group 
/** @} */ // End of DS HAL
/** @} */ // End of HPK
#ifdef __cplusplus
}
#endif
#endif /* _DS_HOST_H_ */
