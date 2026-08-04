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
 * Describe the details about Device Settings HAL API specifications.
 *
 * <b> Following abbreviations present in Device Settings Host HAL APIs </b>
 *
 * @par Abbreviations
 * - cb:      Callback function (suffix).
 * - DS:      Device Settings.
 * - HAL:     Hardware Abstraction Layer.
 * - EDID:    Extended Display Information Data.
 * - CPU:     Central Processing Unit
 * - SoC:     System on chip
 */


#ifndef __DS_HOST_H__
#define __DS_HOST_H__

#ifdef __cplusplus
extern "C" {
#endif

#include "dsError.h"

#define EDID_DATA_SIZE 256
#define EDID_MAX_DATA_SIZE 512
#define DS_REBOOT_REASON_STR_LEN 256 /**< Maximum length of the diagnostic log string (including NUL) */

/* -------------------------------------------------------------------------
 * Normalised reboot-reason enumeration
 *
 * Mandatory set of platform-agnostic reboot reasons. Vendor HAL
 * implementations MUST map every hardware-specific reboot cause to one
 * of these values.
 *
 * ---------------------------------------------------------------------- 
 */

typedef enum
{
    DS_REBOOT_REASON_POWER_ON       = 0, /**< Cold boot or power-cable reconnect.
                                          *   Device was fully power-cycled with
                                          *   no prior software involvement. */

    DS_REBOOT_REASON_SOFTWARE_RESET,     /**< Controlled software or user-initiated
                                          *   reboot (e.g. system call, RDK reboot
                                          *   command, normal restart). */

    DS_REBOOT_REASON_KERNEL_PANIC,       /**< Kernel oops, panic, or crash dump
                                          *   triggered an uncontrolled reset. */

    DS_REBOOT_REASON_WATCHDOG,           /**< Hardware or software watchdog timer
                                          *   expired, forcing a reset. */

    DS_REBOOT_REASON_THERMAL,            /**< Thermal protection threshold exceeded;
                                          *   device reset to prevent damage. */

    DS_REBOOT_REASON_VOLTAGE,            /**< Over-voltage or under-voltage
                                          *   protection triggered a reset. */

    DS_REBOOT_REASON_FACTORY_RESET,      /**< Device was reset to factory defaults. */

    DS_REBOOT_REASON_STANDBY_WAKEUP,     /**< Wakeup from standby or hibernate
                                          *   state (S3 / suspend / hibernate). */

    DS_REBOOT_REASON_SECURITY_RESET,     /**< Security or authentication failure
                                          *   forced a reset (e.g. secure-boot
                                          *   verification error). */

    DS_REBOOT_REASON_UPDATE,             /**< System firmware / OTA update
                                          *   triggered a reboot. */

    DS_REBOOT_REASON_UNKNOWN,            /**< Reason could not be determined or
                                          *   does not match any defined category.
                                          *   Consult logString for vendor detail. */

    DS_REBOOT_REASON_MAX                 /**< Sentinel - out-of-range marker, do not use */

} dsRebootReasonType_t;

/**
 * @brief Reboot reason descriptor populated by the vendor HAL.
 *
 */
typedef struct
{
    /** @brief Normalised reboot reason.
     *  Mandatory. The vendor HAL MUST map the hardware-specific cause to one
     *  of the @p dsRebootReasonType_t values. */
    dsRebootReasonType_t reasonType;

    /** @brief Optional vendor diagnostic string for logging purposes.
     *  May contain the raw hardware token, register value, or any other
     *  platform-specific detail that aids diagnostics, e.g. "WATCHDOG_RESET",
     *  "0xEF", or "Kernel panic - oops dump". Set to an empty string if not
     *  applicable. Must not be used for programmatic decision-making. */
    char rebootReasonString[DS_REBOOT_REASON_STR_LEN];

} dsRebootReason_t;

/**
 * @brief Initializes the Host HAL sub-system
 * 
 * This function initializes any needed resources within the module.
 *
 * @return dsError_t                    - Status
 * @retval dsERR_NONE                   - Success
 * @retval dsERR_ALREADY_INITIALIZED    - Function is already initialized
 * @retval dsERR_GENERAL                - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * @see dsHostTerm()
 * @post dsHostTerm() must be called to release resources.
 * 
 * 
 * 
 */
dsError_t dsHostInit();

/**
 * @brief Terminates the Host sub-system
 *
 * This function has to release all the resources allocated in the initialisation function.
 *
 * @return dsError_t                - Status
 * @retval dsERR_NONE               - Success 
 * @retval dsERR_NOT_INITIALIZED    - Module is not initialised
 * @retval dsERR_GENERAL            - General failure
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsHostInit()
 * 
 */
dsError_t dsHostTerm();

/**
 * @brief Gets the CPU temperature in centigrade
 * 
 * @param[out] cpuTemperature   - CPU temperature value returned in centigrade
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
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
 * @brief Returns the SOC ID
 *
 * @param[out] socID    - 20 byte Chip ID programmed including a null terminator to the CHIP One Time Programmable area. 
 *
 * @return dsError_t                        - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
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
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
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
* @brief Retrieves the last reboot reason from the platform.
*
* This API returns a normalized reboot reason along with
* vendor-specific diagnostic information.
*
* Platform implementations are responsible for translating
* hardware-specific reboot causes into the common
* dsRebootReasonType_t enumeration.
*
* @param[out] rebootReason    -    Reboot reason information.
*
* @return dsError_t
* @retval dsERR_NONE                     - Success
* @retval dsERR_NOT_INITIALIZED          - Module not initialized
* @retval dsERR_INVALID_PARAM            - Invalid parameter
* @retval dsERR_OPERATION_NOT_SUPPORTED  - Not supported on platform
* @retval dsERR_GENERAL                  - Platform-specific failure
*/
dsError_t dsGetLastRebootReason(dsRebootReason_t *rebootReason);

/** @} */ // End of DSHAL_HOST_API doxygen group 
/** @} */ // End of DS Host HAL
/** @} */ // End of Device Settings HAL
/** @} */ // End of Device Settings Module
/** @} */ // End of HPK

#ifdef __cplusplus
}
#endif
#endif /* __DS_HOST_H__ */
