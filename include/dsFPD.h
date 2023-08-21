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
 * @file dsFPD.h
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
 * - FPD:     Front-Panel Display.
 * - HAL:     Hardware Abstraction Layer.

 * - LED:     Light-Emitting Diode.
 * - ms:      miliseconds
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

/** @addtogroup DS_Manager_HAL DS Manager Hal
 * @par Application API Specification
 * Described herein are the DeviceSettings HAL types and functions that are part of
 * the FPD subsystem. The FPD subsystem manages system-specific HAL operations.
 *  @{
 */

/** @defgroup DSHAL_FPD_API Device Settings HAL FPD Public API
 *
 *
 *  @{
 */


#ifndef _DS_FPD_H_
#define _DS_FPD_H_

#include <sys/types.h>
#include "dsError.h"
#include "dsTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Initializes the Front Panel Display(FPD) Hal.
 *
 *
 * @return dsError_t                   - Status
 * @retval dsERR_NONE                   - Success
 * @retval dsERR_ALREADY_INITIALIZED    - Function is already initialized.
 * @retval dsERR_GENERAL                - Underlying undefined platform error
 * @warning  This API is Not thread safe.
 * @see dsFPTerm()
 * 
 * 
 */

dsError_t dsFPInit (void);

/**
 * @brief This function is used to set LED blinking mode.
 * 
 * This function is used to set the individual discrete LEDs to blink for a specified
 * number of times at the specified blink interval.
 *
 * @param[in] eIndicator        - FPD Indicator index. See dsFPDIndicator_t
 * @param[in] uBlinkDuration    - Blink interval. The percentage of time in ms 
 *                                  the text display will remain on during one blink iteration.
 * @param[in] uBlinkIterations  - Number of times for the given LED to blink. 
 *                                  The number of times per minute data will 
 *                                  blink across all of the LEDs.
 * 
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsError_t dsSetFPBlink (dsFPDIndicator_t eIndicator, unsigned int uBlinkDuration, unsigned int uBlinkIterations);

/**
 * @brief This function is used to set LED brightness level.
 * 
 * This function will set the brightness of the specified discrete LEDs on the Front
 * Panel Display to the specified brightness level. The Power LED brightness setting
 * will also be adjusted to this setting. 
 *
 * @param[in] eIndicator    - FPD Indicator index. See dsFPDIndicator_t
 * @param[in] eBrightness   - The brightness value for the specified indicator. 
 *                                  From 0 to 100. See dsFPDBrightness_t.
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetFPBrightness()
 * 
 */

dsError_t dsSetFPBrightness (dsFPDIndicator_t eIndicator, dsFPDBrightness_t eBrightness);

/**
 * @brief This function will Get the ON or OFF state of Specified LED.
 * 
 *
 * @param[in]  eIndicator   - FPD Indicator index. See dsFPDIndicator_t
 * @param[out] state        - current state of the specified indicator. See dsFPDState_t
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetFPState()
 * 
 */

dsError_t dsGetFPState(dsFPDIndicator_t eIndicator, dsFPDState_t* state);

/**
 * @brief This function will enable or disable the specified discrete LED on the front
 * panel display.
 *
 * @param[in] eIndicator    - FPD Indicator index. See dsFPDIndicator_t
 * @param[in] state         - Indicates ON or OFF state for the indicator.(ON = 1 and OFF = 0).
 *                                       See dsFPDState_t
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetFPState()
 * 
 */

dsError_t dsSetFPState(dsFPDIndicator_t eIndicator, dsFPDState_t state);

/**
 * @brief This function is used to get the brightness level for Front Panel Display LEDs.
 * 
 * This function returns the brightness level of the specified discrete LEDs on the front
 * panel.
 *
 * @param[in]  eIndicator   - FPD Indicator index. See dsFPDIndicator_t
 * @param[out] pBrightness  - current brightness value for the specified indicator. 
 *                                  From 0 to 100. See dsFPDBrightness_t
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetFPBrightness()
 * 
 */

dsError_t dsGetFPBrightness (dsFPDIndicator_t eIndicator, dsFPDBrightness_t *pBrightness);

/**
 * @brief This function is used to get LED color.
 * 
 * This function Gets the color of the specified front panel indicator LED, if the
 * indicator supports it (i.e. is multi-colored). It must return
 * ::dsERR_OPERATION_NOT_SUPPORTED if the indicator is single-colored.
 *
 * @param[in] eIndicator    - FPD Indicator index. See dsFPDIndicator_t
 * @param[out] pColor       - current color value of the specified indicator. See dsFPDColor_t
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetFPColor()
 * 
 */

dsError_t dsGetFPColor (dsFPDIndicator_t eIndicator, dsFPDColor_t *pColor);

/**
 * @brief This function is used to set LED color.
 * 
 * This function sets the color of the specified front panel indicator LED, if the
 * indicator supports it (i.e. is multi-colored). It must return
 * ::dsERR_OPERATION_NOT_SUPPORTED if the indicator is single-colored.
 *
 * @param[in] eIndicator    - FPD Indicator index. See dsFPDIndicator_t
 * @param[in] eColor        - The color index for the specified indicator. See dsFPDColor_t
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetFPColor()
 * 
 */

dsError_t dsSetFPColor (dsFPDIndicator_t eIndicator, dsFPDColor_t eColor);

/**
 * @brief This function is used to set time on 7-Segment Display.
 * 
 * This function sets the 7-segment display LEDs to show the time. The format
 * (12/24-hour) must be specified. If there are no 7-Segment display LEDs present on the
 * device then ::dsERR_OPERATION_NOT_SUPPORTED must be returned.
 * The function must return ::dsERR_INVALID_PARAM if the format and hours values do not agree,
 * or if the hours/minutes are invalid.
 *
 * @param[in] eTimeFormat   - Time format (12 or 24 hrs). See dsFPDTimeFormat_t.
 * @param[in] uHour         - Hour information.
 * @param[in] uMinutes      - Minutes information.
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported.
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called before calling this API.
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetFPTimeFormat()
 * 
 */

dsError_t dsSetFPTime (dsFPDTimeFormat_t eTimeFormat, const unsigned int uHour, const unsigned int uMinutes);

/**
 * @brief This function is used to set text on 7-Segment Display.
 * 
 * This function is used to set the 7-segment display LEDs to show the given text. The
 * supported format of text is specified. If there are no 7-Segment display LEDs present
 * on the device then ::dsERR_OPERATION_NOT_SUPPORTED must be returned.
 *
 * @param[in] pText - Text to be displayed
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported.
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetFPTextBrightness() 
 * 
 */

dsError_t dsSetFPText(const char* pText);

/**
 * @brief This function is used to set brightness level of 7-Segment Display.
 * 
 * This function will set the brightness of the specified 7-Segment Display LEDs on the Front
 * Panel Display to the specified brightness level.   
 *
 * @param[in] eIndicator    - FPD Indicator index (Clock LED). See dsFPDTextDisplay_t
 * @param[in] eBrightness   - The brightness value for the specified indicator. From 0 to 100. 
 *                                  See dsFPDBrightness_t.
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported.
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetFPTextBrightness(), dsSetFPText()
 * 
 */

dsError_t dsSetFPTextBrightness (dsFPDTextDisplay_t eIndicator, dsFPDBrightness_t eBrightness);

/**
 * @brief This function is used to get the brightness of  7-Segment Display LEDs
 * 
 * This function will Get the brightness of the specified 7-Segment Display LEDs on the Front
 * Panel Text Display .   
 *
 * @param[in] eIndicator    - FPD Indicator index (CLock LED.). See dsFPDTextDisplay_t
 * @param[out] eBrightness  - brightness value. From 0 to 100. See dsFPDBrightness_t.
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetFPTextBrightness()
 * 
 */

dsError_t dsGetFPTextBrightness (dsFPDTextDisplay_t eIndicator, dsFPDBrightness_t *eBrightness);

/**
 * @brief This function will disable and enable display of clock
 * 
 * This function will enable or disable displaying of clock.   
 *
 * @param[in] enable    - Indicates the clock to be enabled or disabled. 
 *                          1 if enabled, 0 if disabled.
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported.
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsError_t dsFPEnableCLockDisplay (int enable);

/**
 * @brief This function will set the scroll text on 7-Segment Display.
 * 
 * This function scrolls the text in the 7-segment LEDs for the given number of iterations.
 *
 * @param[in] uScrollHoldOnDur      - Duration in ms before between scrolling to the next position
 * @param[in] uHorzScrollIterations - Number of iterations for which to scroll horizontally.
 * @param[in] uVertScrollIterations - Number of iterations for which to scroll vertically.
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported.
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsError_t dsSetFPScroll(unsigned int uScrollHoldOnDur, unsigned int uHorzScrollIterations, unsigned int uVertScrollIterations);

/**
 * @brief This function will terminate the the Front Panel Display sub-system.
 * 
 * This function resets any data structures used within the platform front-panel module,
 * and releases the front-panel specific device handles.
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsFPInit()
 * 
 */

dsError_t dsFPTerm(void);

/**
 * @brief This function will set the brightness of the specified discrete LED on the front
 * panel display to the specified brightness level in multi-app mode.
 * The brightness level must be persisted if the input parameter toPersist passed is TRUE.
 *
 * @param[in] eIndicator    - FPD Indicator index. See dsFPDIndicator_t
 * @param[in] eBrightness   - The brightness value for the specified indicator. 
 *                                  From 0 to 100. See dsFPDBrightness_t.
 * @param[in] toPersist     - If set to TRUE, the brightness value must be persisted.
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetFPTextBrightness()
 * 
 */

dsError_t dsSetFPDBrightness(dsFPDIndicator_t eIndicator, dsFPDBrightness_t eBrightness,bool toPersist);

/**
 * @brief This function sets the color of the specified LED on the front panel in
 * multi-app mode. The color of the LED must be persisted if the
 * input parameter toPersist is set to TRUE.
 *
 * @param[in] eIndicator    - FPD Indicator index. See dsFPDIndicator_t
 * @param[in] eColor        - Indicates the RGB color to be set for the specified LED. 
 *                                      See dsFPDColor_t
 * @param[in] toPersist     - Indicates whether to persist the specified LED color or not. 
 *                                      True if to persist, false if not.
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetFPColor()
 * 
 */

dsError_t dsSetFPDColor (dsFPDIndicator_t eIndicator, dsFPDColor_t eColor,bool toPersist);

/**
 * @brief This function sets the 7-segment display LEDs to show the 
 *                      specified time in specified format.
 *
 * @param[in] eTimeFormat   - Indicates the time format (12 hour or 24 hour). 
 *                                          See dsFPDTimeFormat_t.
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported.
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetFPTimeFormat()
 * 
 */

dsError_t dsSetFPTimeFormat (dsFPDTimeFormat_t eTimeFormat);

 /**
 * @brief This function get the Current time format set on 7-segment display LEDs panel.
 *
 * @param[out] pTimeFormat      - Current time format value (12 hour or 24 hour). 
 *                                          See dsFPDTimeFormat_t.
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetFPTimeFormat()
 * 
 */

dsError_t dsGetFPTimeFormat (dsFPDTimeFormat_t *pTimeFormat);

/**
 * @brief This function sets the display mode of the FPD text display
 *
 * @param[in] eMode - Indicates the mode. See dsFPDMode_t
 *
 * @return dsError_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsError_t dsSetFPDMode (dsFPDMode_t eMode);

/** @} */ // End of DSHAL_FPD_API doxygen group 
/** @} */ // End of DS HAL
/** @} */ // End of HPK

#ifdef __cplusplus
}
#endif
#endif /* _DS_FPD_H_ */
