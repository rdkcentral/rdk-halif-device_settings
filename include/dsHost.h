/*
 * If not stated otherwise in this file or this component's LICENSE file the
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

/**
 * @defgroup Device_Settings Device Settings Module
 * @{
 */

/**
 * @defgroup Device_Settings_HAL Device Settings HAL
 * @par Application API Specification
 * Described herein are the DeviceSettings HAL types and functions that are part of
 * the Host subsystem. The Host subsystem manages system-specific HAL operations.
 *  @{
 */

/**
 * @defgroup dsHOST_HAL Device Settings Host HAL
 *  @{
 * @par Application API Specification
 * dsHost HAL provides an interface for managing the host settings for the device settings module
 */

/**
 * @defgroup DSHAL_HOST_API Device Settings HAL Host Public API
 *  @{
 */

/** 
 * 
 * Describe the details about Device Settings HAL API specifications.
 *
 * <b> Following abbreviations present in HAL API </b>
 *
 * @par Abbreviations
 * - BE:      Big-Endian.
 * - cb:      Callback function (suffix).
 * - DS:      Device Settings.
 * - FPD:     Front-Panel Display.
 * - HAL:     Hardware Abstraction Layer.
 * - LE:      Little-Endian.
 * - LS:      Least Significant.
 * - MBZ:     Must be zero.
 * - MS:      Most Significant.
 * - RDK:     Reference Design Kit.
 * - _t:      Type (suffix).
 * - HDCP:    High-bandwidth Digital Copy Protection.
 * - DTCP:    Digital Transmission Copy Protection.
 * - EDID:    Extended Display Information Data.
 * 
 * @ingroup DSSETTINGS_HAL
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
 * @brief Initializes the Host HAL sub-system
 * 
 * This function initializes any needed resources within the module.
 *
 * @return dsError_t                    - Status
 * @retval dsERR_NONE                   - Success
 * @retval dsERR_GENERAL                - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * @see dsHostTerm()
 * 
 * 
 * 
 */
dsError_t dsHostInit();

/**
 * @brief Set the power mode.
 *
 * This function sets the power mode of the host to active or standby and turns on/off
 * all the ouput ports.
 *
 * @param [in] newPower  The power mode of the host (::dsPOWER_STANDBY or ::dsPOWER_ON)
 * @return Device Settings error code
 * @retval    ::dsError_t
 *
 * @pre dsHostInit() must be called before this function
 *
 * @note dsPOWER_OFF is not currently being used.
 */
dsError_t dsSetHostPowerMode(int newPower);

/**
 * @brief Get the current power mode.
 *
 * This function gets the current power mode of the host. 
 *
 * @param [out] *currPower  The address of a location to hold the host's current power
 *                          mode on return. It returns one of:
 *                              - ::dsPOWER_OFF
 *                              - ::dsPOWER_STANDBY
 *                              - ::dsPOWER_ON
 * @return Device Settings error code
 * @retval    ::dsError_t
 *
 * @pre dsHostInit() must be called before this function
 */
dsError_t dsGetHostPowerMode(int *currPower);

/**
 * @brief Terminates the Host sub-system
 *
 * This function has to release all the resources allocated in the initialisation function.
 *
 * @return dsError_t                - Status
 * @retval dsERR_NONE               - Success 
 * @retval dsERR_GENERAL            - General failure
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
 * @param[out] pMode Data will be copied to this. This shall be preallocated before the call.
 * @return Device Settings error code
 * @retval dsERR_NONE If sucessfully dsGetPreferredSleepMode api has been called using IARM support.
 * @retval dsERR_GENERAL General failure.
 *
 * @pre dsHostInit() must be called before this function
 */
dsError_t dsGetPreferredSleepMode(dsSleepMode_t *pMode);

/**
 * @brief This function sets the preferred sleep mode which needs to be persisted.
 *
 * @param[in] mode Sleep mode that is expected to be persisted.
 * @return Device Settings error code
 * @retval dsERR_NONE If sucessfully dsSetPreferredSleepMode api has been called using IARM support.
 * @retval dsERR_GENERAL General failure.
 *
 * @pre dsHostInit() must be called before this function
 */
dsError_t dsSetPreferredSleepMode(dsSleepMode_t mode);

/**
 * @brief Gets the CPU temperature in centigrade
 * 
 * @param[out] cpuTemperature   - CPU temperature value returned in centigrade
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHostInit() must be called before this function
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsGetCPUTemperature(float *cpuTemperature);

/**
 * @brief Get DS HAL API Version.
 *
 * In 4 byte VersionNumber, Two Most significant Bytes are Major number
 * and Two Least Significant Bytes are minor number.
 *
 * @param[out] versionNumber 4 Bytes of version number of DS HAL
 *
 * @return Returns 4 byte Version Number
 * @retval dsERR_NONE Successfully got the version number from dsHAL.
 * @retval dsERR_GENERAL Failed to get the version number.
 *
 * @pre dsHostInit() must be called before this function
 */
dsError_t dsGetVersion(uint32_t *versionNumber);

/**
 * @brief Allows the application to set the runtime version of the dsHAL
 *
 * @param[in] versionNumber 4 Bytes of version number of DS HAL
 *
 * @retval dsERR_NONE Successfully set the version for dsHAL.
 * @retval dsERR_GENERAL Failed to set the version.
 *
 * @pre dsHostInit() must be called before this function
 */
dsError_t dsSetVersion(uint32_t versionNumber);

/**
 * @brief Returns the SOC ID
 *
 * @param[out] socID    - 8 byte Chip ID programmed to the CHIP One Time Programmable area
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHostInit() must be called before this function
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsGetSocIDFromSDK(char *socID);

/**
 * @brief Gets the host EDID and length
 * 
 * The host EDID will be used on devices supporting HDMI input feature.
 *
 * @param[out] edid     - host EDID.
 * @param[out] length   - length of host EDID. Min value of 0.  Max value of 2048
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsHostInit() must be called before this function
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsGetHostEDID(unsigned char *edid, int *length);

/**
 * @brief This function is used to get the MS12 config platform supports.
 * 
 * @param[out] configType   - ms12 config type.
 *
 * @return Device Settings error code
 * @retval dsERR_NONE If sucessfully dsGetMS12ConfigType api has read the ms12 configType from persistance
 * @retval dsERR_GENERAL General failure.
 *
 * @pre dsHostInit() must be called before this function
 */
dsError_t dsGetMS12ConfigType(const char *configType);

/** @} */ // End of DSHAL_HOST_API doxygen group 
/** @} */ // End of DS Host HAL
/** @} */ // End of Device Settings HAL
/** @} */ // End of Device Settings Module
/** @} */ // End of HPK

#ifdef __cplusplus
}
#endif
#endif /* _DS_HOST_H_ */



