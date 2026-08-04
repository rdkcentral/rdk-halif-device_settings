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
#define DS_REBOOT_REASON_STR_LEN 128 /**< Maximum length of any reason string field (including NUL) */
#define DS_REBOOT_REASON_DESC_LEN 256

/* -------------------------------------------------------------------------
 * Normalised reboot-reason codes
 *
 * All vendor-specific raw strings from every supported SoC family are
 * collapsed into these platform-agnostic groups.
 *
 * ---------------------------------------------------------------------- 
 */

typedef enum
{
    DS_REBOOT_REASON_POWER_ON       = 0, /**< Cold boot / power-cable unplug.
                                          *   Raw tokens: POWER_ON, POWER_ON_RESET,
                                          *   POWER_ON_REBOOT, HARDWARE, COLD_BOOT    */

    DS_REBOOT_REASON_SOFTWARE_RESET,     /**< Software / user-initiated reboot.
                                          *   Raw tokens: SOFTWARE_MASTER_RESET,
                                          *   SOFTWARE_RESET, SW_RESET,
                                          *   SOFTWARE_REBOOT, NORMAL_BOOT            */

    DS_REBOOT_REASON_KERNEL_PANIC,       /**< Kernel oops / panic / crash dump.
                                          *   Raw tokens: KERNEL_PANIC,
                                          *   KERNEL_PANIC_RESET, CRASH_DUMP,
                                          *   CRASH_REBOOT                            */

    DS_REBOOT_REASON_WATCHDOG,           /**< Any watchdog timer expiry.
                                          *   Raw tokens: WATCHDOG, WATCHDOG_RESET,
                                          *   WATCHDOG_TIMER_RESET, WATCH_DOG,
                                          *   GEN_WATCHDOG_RESET, GEN_WATCHDOG_1_RESET,
                                          *   WATCHDOG_REBOOT                         */

    DS_REBOOT_REASON_THERMAL,            /**< Thermal threshold exceeded.
                                          *   Raw tokens: OVERTEMP, OVERHEAT,
                                          *   THERMAL, THERMAL_REBOOT                 */

    DS_REBOOT_REASON_VOLTAGE,            /**< Over- or under-voltage protection.
                                          *   Raw tokens: OVERVOLTAGE, UNDERVOLTAGE,
                                          *   OVERVOLTAGE_RESET, UNDERVOLTAGE_RESET,
                                          *   UNDERVOLTAGE_0_RESET,
                                          *   UNDERVOLTAGE_1_RESET                    */

    DS_REBOOT_REASON_FACTORY_RESET,      /**< Factory reset reboot.
                                          *   Raw tokens: FACTORY_RESET,
                                          *   FACTORY_RESET_REBOOT                    */

    DS_REBOOT_REASON_STANDBY_WAKEUP,     /**< Wakeup from standby / hibernate.
                                          *   Raw tokens: S3_WAKEUP_RESET,
                                          *   SUSPEND_REBOOT, SUSPEND_BOOT,
                                          *   HIBERNATE_REBOOT, HIBERNATE_BOOT        */

    DS_REBOOT_REASON_SECURITY_RESET,     /**< Security / authentication failure reset.
                                          *   Raw tokens: SECURITY_MASTER_RESET,
                                          *   STR_AUTH_FAIL,
                                          *   AMLOGIC_DDR_SHA2_REBOOT                 */

    DS_REBOOT_REASON_UPDATE,             /**< System upgrade / OTA reboot.
                                          *   Raw tokens: UPGRADE_SYSTEM_REBOOT,
                                          *   UPDATE_BOOT                             */

    DS_REBOOT_REASON_UNKNOWN,            /**< Unrecognised or unclassified reason.
                                          *   Includes: CPU_EJTAG_RESET,
                                          *   SCPU_EJTAG_RESET, MAIN_CHIP_INPUT_RESET,
                                          *   MAIN_CHIP_RESET_INPUT, SMARTCARD_INSERT_RESET,
                                          *   PCIE_HOT_BOOT_RESET, AUX_CHIP_EDGE_RESET,
                                          *   AUX_CHIP_LEVEL_RESET, MPM_RESET,
                                          *   RPMPB_REBOOT, FFV_REBOOT,
                                          *   FASTBOOT_BOOTLOADER, BOOTLOADER_REBOOT,
                                          *   SHUTDOWN_REBOOT, FASTBOOT_REBOOT,
                                          *   FAST_BOOT, FRONT_PANEL_4SEC_RESET,
                                          *   FRONT_PANEL_RESET, TAP_IN_SYSTEM_RESET,
                                          *   HARD_POWER, absent / unmatched values   */

    DS_REBOOT_REASON_MAX                 /**< Sentinel - out-of-range marker, do not use */

} dsRebootReasonType_t;

/**
 * @brief Platform-agnostic reboot reason descriptor populated by the vendor HAL.
 *
 * The middleware maps these fields directly into its internal RebootInfo
 * structure.
 *
 */
typedef struct
{
    /** @brief Raw value read verbatim from the hardware register / sysfs node.
     *  Stored as an uppercase string, e.g. "WATCHDOG", "3", "0xEF". */
    char rawReason[DS_REBOOT_REASON_STR_LEN];

    /** @brief Normalised reason type corresponding to rawReason.
     *  Set by the vendor library so middleware can switch on an integer value
     *  instead of string-comparing rawReason. */
    dsRebootReasonType_t reasonType;

    /** @brief Camel-case human-readable source, e.g. "KernelPanic", "WatchDog".
     *  Mapped to RebootInfo.source in the middleware classifica    tion pipeline. */
    char rebootInitiatedBy[DS_REBOOT_REASON_STR_LEN];

    /** @brief Platform-specific descriptive variant of rawReason,
     *  typically identical to rawReason, e.g. "Hardware Register KERNEL_PANIC".
     *  Mapped to RebootInfo.customReason. */
    char customReason[DS_REBOOT_REASON_STR_LEN];

    /** @brief Free-text human description of the reboot event,
     *  e.g. "Reboot due to oops dump caused panic".
     *  Mapped to RebootInfo.otherReason. */
    char otherReason[DS_REBOOT_REASON_DESC_LEN];

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
* @retval dsERR_OPERATION_NOT_SUPPORTED  -Not supported on platform
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
