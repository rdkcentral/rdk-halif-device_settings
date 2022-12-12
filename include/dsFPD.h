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
 */

/**
* @defgroup devicesettings
* @{
* @defgroup hal
* @{
**/

#ifndef _DS_FPD_H_
#define _DS_FPD_H_

#include <sys/types.h>
#include "dsError.h"
#include "dsTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/** @addtogroup DSHAL_FPD_API Device Settings HAL Front Panel Display (FPD) Public API
 *  @ingroup devicesettingshalapi
 *  @{
 */

/**
 * @brief This function is used to initialize the underlying front panel display sub-system.
 *
 * @return Device Settings error code
 * @retval dsERR_NONE Indicates dsFPInit API was successfully called using iarmbus call.
 * @retval dsERR_GENERAL Indicates error due to general failure.
 * @warning  This API is Not thread safe.
 * @see dsFPTerm()
 */

dsError_t dsFPInit (void);

/**
 * @brief Set LED blinking mode.
 * 
 * This function is used to set the individual discrete LEDs to blink for a specified
 * number of times at the specified blink interval.
 *
 * @param[in] eIndicator        FPD Indicator index (Power LED, Record LED, etc.).
 * @param[in] uBlinkDuration    Blink interval. The percentage of time the text display will remain on during one blink iteration.
 * @param[in] uBlinkIterations  Number of times for the given LED to blink. The number of times per minute data will blink across all of the LEDs.
 * 
 * @return Device Settings error code
 * @retval dsERR_NONE Indicates dsSetFPBlink API was successfully called using iarmbus call.
 * @retval dsERR_GENERAL Indicates error due to general failure.
 * @pre dsFPInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsSetFPBlink (dsFPDIndicator_t eIndicator, unsigned int uBlinkDuration, unsigned int uBlinkIterations);

/**
 * @brief Set LED brightness level.
 * 
 * This function will set the brightness of the specified discrete LEDs on the Front
 * Panel Display to the specified brightness level. The Power LED brightness setting
 * will also be adjusted to this setting. 
 *
 * @param[in] eIndicator    FPD Indicator index (Power LED, Record LED, and so on).
 * @param[in] eBrightness   The brightness value for the specified indicator.
 *
 * @return Device Settings error code
 * @retval dsERR_NONE Indicates dsSetFPBrightness API was successfully called using iarmbus call.
 * @retval dsERR_GENERAL Indicates error due to general failure.
 * @pre dsFPInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetFPBrightness()
 */

dsError_t dsSetFPBrightness (dsFPDIndicator_t eIndicator, dsFPDBrightness_t eBrightness);

/**
 * @brief This function will Get the ON or OFF state of Specified LEDs
 * 
 *
 * @param[in]  eIndicator   FPD Indicator index (Power LED, Record LED and so on).
 * @param[out] state        Pointer to hold the state of the specified indicator.
 *
 * @return Device Settings error code
 * @retval dsERR_NONE Indicates dsGetFPState API was successfully called using iarmbus call.
 * @retval dsERR_GENERAL Indicates error due to general failure.
 * @pre dsFPInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetFPState()
 */

dsError_t dsGetFPState(dsFPDIndicator_t eIndicator, dsFPDState_t* state);

/**
 * @brief This function will enable or disable the specified discrete LED on the front
 * panel display.
 *
 * @param[in] eIndicator    FPD Indicator index (Power LED, Record LED and so on).
 * @param[in] state         Indicates ON or OFF state for the indicator.(ON = 1 and OFF = 0).
 *
 * @return Device Settings error code
 * @retval dsERR_NONE Indicates dsSetFPState API was successfully called using iarmbus call.
 * @retval dsERR_GENERAL Indicates error due to general failure.
 * @pre dsFPInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetFPState()
 */

dsError_t dsSetFPState(dsFPDIndicator_t eIndicator, dsFPDState_t state);

/**
 * @brief Get the brightness level for Front Panel Display LEDs.
 * 
 * This function returns the brightness level of the specified discrete LEDs on the front
 * panel.
 *
 * @param[in]  eIndicator   FPD Indicator index (Power LED, Record LED, etc.).
 * @param[out] pBrightness  The address of a location to hold the brightness value
 *                          for the specified indicator on return.
 *
 * @return Device Settings error code
 * @retval dsERR_NONE Indicates dsGetFPBrightness API was successfully called using iarmbus call.
 * @retval dsERR_GENERAL Indicates error due to general failure.
 * @pre dsFPInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetFPBrightness()
 */

dsError_t dsGetFPBrightness (dsFPDIndicator_t eIndicator, dsFPDBrightness_t *pBrightness);

/**
 * @brief Get LED color.
 * 
 * This function Gets the color of the specified front panel indicator LED, if the
 * indicator supports it (i.e. is multi-colored). It must return
 * ::dsERR_OPERATION_NOT_SUPPORTED if the indicator is single-colored.
 *
 * @param[in] eIndicator    FPD Indicator index (Power LED, Record LED, etc.).
 * @param[in] pColor        The address of a location to hold the color value
 *
 * @return Device Settings error code
 * @retval dsERR_NONE Indicates dsGetFPColor API was successfully called using iarmbus call.
 * @retval dsERR_GENERAL Indicates error due to general failure.
 * @pre dsFPInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetFPColor()
 */

dsError_t dsGetFPColor (dsFPDIndicator_t eIndicator, dsFPDColor_t *pColor);

/**
 * @brief Set LED color.
 * 
 * This function sets the color of the specified front panel indicator LED, if the
 * indicator supports it (i.e. is multi-colored). It must return
 * ::dsERR_OPERATION_NOT_SUPPORTED if the indicator is single-colored.
 *
 * @param[in] eIndicator    FPD Indicator index (Power LED, Record LED, etc.).
 * @param[in] eColor        The color index for the specified indicator.
 *
 * @return Device Settings error code
 * @retval dsERR_NONE Indicates dsSetFPColor API was successfully called using iarmbus call.
 * @retval dsERR_GENERAL Indicates error due to general failure.
 * @pre dsFPInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetFPColor()
 */

dsError_t dsSetFPColor (dsFPDIndicator_t eIndicator, dsFPDColor_t eColor);

/**
 * @brief Set time on 7-Segment Display.
 * 
 * This function sets the 7-segment display LEDs to show the time. The format
 * (12/24-hour) must be specified. If there are no 7-Segment display LEDs present on the
 * device then ::dsERR_OPERATION_NOT_SUPPORTED must be returned.
 * The function shall return ::dsERR_INVALID_PARAM if the format and hours values do not agree,
 * or if the hours/minutes are invalid.
 *
 * @param[in] eTimeFormat   Time format (12 or 24 hrs).
 * @param[in] uHour         Hour information.
 * @param[in] uMinutes      Minutes information.
 *
 * @return Device Settings error code
 * @retval dsERR_NONE Indicates dsSetFPTime API was successfully called using iarmbus call.
 * @retval dsERR_GENERAL Indicates error due to general failure.
 * @pre dsFPInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetFPTimeFormat()
 */

dsError_t dsSetFPTime (dsFPDTimeFormat_t eTimeFormat, const unsigned int uHour, const unsigned int uMinutes);

/**
 * @brief Set text on 7-Segment Display.
 * 
 * This function is used to set the 7-segment display LEDs to show the given text. The
 * supported format of text is specified. If there are no 7-Segment display LEDs present
 * on the device then ::dsERR_OPERATION_NOT_SUPPORTED must be returned.
 *
 * @param[in] pText         Test message
 *
 * @return Device Settings error code
 * @retval dsERR_NONE Indicates dsSetFPText API was successfully called using iarmbus call.
 * @retval dsERR_GENERAL Indicates error due to general failure
 * @pre dsFPInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetFPTextBrightness() 
 */

dsError_t dsSetFPText(const char* pText);

/**
 * @brief Set brightness level of 7-Segment Display.
 * 
 * This function will set the brightness of the specified 7-Segment Display LEDs on the Front
 * Panel Display to the specified brightness level.   
 *
 * @param[in] eIndicator    FPD Indicator index (Clock LED).
 * @param[in] eBrightness   The brightness value for the specified indicator.
 *
 * @return Device Settings error code
 * @retval dsERR_NONE Indicates dsSetFPTextBrightness API was successfully called using iarmbus call.
 * @retval dsERR_GENERAL Indicates error due to general failure.
 * @pre dsFPInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetFPTextBrightness(), dsSetFPText()
 */

dsError_t dsSetFPTextBrightness (dsFPDTextDisplay_t eIndicator, dsFPDBrightness_t eBrightness);

/**
 * @brief Get the brightness of  7-Segment Display LEDs
 * 
 * This function will Get the brightness of the specified 7-Segment Display LEDs on the Front
 * Panel Text Display .   
 *
 * @param[in] eIndicator    FPD Indicator index (CLock LED.).
 * @param[in] eBrightness   The address of a location to hold the brightness value
 *                          for the specified indicator on return.
 *
 * @return Device Settings error code
 * @retval dsERR_NONE Indicates dsGetFPTextBrightness API was successfully called using iarmbus call.
 * @retval dsERR_GENERAL Indicates error due to general failure.
 * @pre dsFPInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetFPTextBrightness()
 */

dsError_t dsGetFPTextBrightness (dsFPDTextDisplay_t eIndicator, dsFPDBrightness_t *eBrightness);

/**
 * @brief Use disable and enable display of clock
 * 
 * This function will enable or disable displaying of clock.   
 *
 * @param[in] enable        Indicates the clock to be enabled or disabled.
 *                          (TRUE = enable clock and FALSE = disable clock).
 *
 * @return Device Settings error code
 * @retval dsERR_NONE Indicates dsFPEnableCLockDisplay API was successfully called using iarmbus call.
 * @retval dsERR_GENERAL Indicates error due to general failure.
 * @pre dsFPInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsFPEnableCLockDisplay (int enable);

/**
 * @brief Scroll text on 7-Segment Display.
 * 
 * This function scrolls the text in the 7-segment LEDs for the given number of iterations.
 *
 * @param[in] uScrollHoldOnDur       Duration for the scroll to hold each character before scrolling 
 *                                    it to the next position during one scroll iteration.
 * @param[in] uHorzScrollIterations  Number of iterations for which to scroll horizontally.
 * @param[in] uVertScrollIterations  Number of iterations for which to scroll vertically.
 *
 * @return Device Settings error code
 * @retval dsERR_NONE Indicates dsSetFPScroll API was successfully called using iarmbus call.
 * @retval dsERR_GENERAL Indicates error due to general failure.
 * @pre dsFPInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsSetFPScroll(unsigned int uScrollHoldOnDur, unsigned int uHorzScrollIterations, unsigned int uVertScrollIterations);

/**
 * @brief Terminate the the Front Panel Display sub-system.
 * 
 * This function resets any data structures used within the platform front-panel module,
 * and releases the front-panel specific device handles.
 *
 * @return Device Settings error code
 * @retval dsERR_NONE Indicates dsFPTerm API was successfully called using iarmbus call.
 * @retval dsERR_GENERAL Indicates error due to general failure.
 * @pre dsFPInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsFPInit()
 */

dsError_t dsFPTerm(void);

/**
 * @brief This function will set the brightness of the specified discrete LED on the front
 * panel display to the specified brightness level in multi-app mode using iarmbus call.
 * The brightness level shall be persisted if the input parameter toPersist passed is TRUE.
 *
 * @param[in] eIndicator    FPD Indicator index (Power LED, Record LED, and so on).
 * @param[in] eBrightness   The brightness value for the specified indicator.
 * @param[in] toPersist     If set to TRUE, the brightness value shall be persisted.
 *
 * @return Device Settings error code
 * @retval dsERR_NONE Indicates dsSetFPBrightness API was successfully called using iarmbus call.
 * @retval dsERR_GENERAL Indicates error due to general failure.
 * @pre dsFPInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetFPTextBrightness()
 */

dsError_t dsSetFPDBrightness(dsFPDIndicator_t eIndicator, dsFPDBrightness_t eBrightness,bool toPersist);

/**
 * @brief This function sets the color of the specified LED on the front panel in
 * multi-app mode using iarmbus call. The color of the LED shall be persisted if the
 * input parameter toPersist is set to TRUE.
 *
 * @param[in] eIndicator    FPD Indicator index (Power LED, Record LED and so on).
 * @param[in] eColor        Indicates the RGB color to be set for the specified LED.
 * @param[in] toPersist     Indicates whether to persist the specified LED color or not.
 *                          (If TRUE persists the LED color else doesn't persist it)
 *
 * @return Device Settings error code
 * @retval dsERR_NONE Indicates dsSetFPColor API was successfully called using iarmbus call.
 * @retval dsERR_GENERAL Indicates error due to general failure.
 * @pre dsFPInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetFPColor()
 */

dsError_t dsSetFPDColor (dsFPDIndicator_t eIndicator, dsFPDColor_t eColor,bool toPersist);

/**
 * @brief This function sets the 7-segment display LEDs to show the specified time in specified format.
 *
 * @param[in] eTimeFormat   Indicates the time format (12 hour or 24 hour).
 *
 * @return Device Settings error code
 * @retval dsERR_NONE Indicates dsSetFPTime API was successfully called using iarmbus call.
 * @retval dsERR_GENERAL Indicates error due to general failure.
 * @pre dsFPInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetFPTimeFormat()
 */

dsError_t dsSetFPTimeFormat (dsFPDTimeFormat_t eTimeFormat);

 /**
 * @brief This function get the Current time zone format set on 7-segment display LEDs panel.
 *
 * @param[in]               None.
 * @param[out] pTimeFormat  Pointer to hold the Current time format  value .
 *
 * @return Device Settings error code
 * @retval dsERR_NONE Indicates dsGetFPBrightness API was successfully called using iarmbus call.
 * @retval dsERR_GENERAL Indicates error due to general failure.
 * @pre dsFPInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetFPTimeFormat()
 */

dsError_t dsGetFPTimeFormat (dsFPDTimeFormat_t *pTimeFormat);

/**
 * @brief This function sets the display mode of the FPD text display
 *
 * @param[in] eMode         Indicates the mode (any, clock or text)
 *
 * @return Device Settings error code
 * @retval dsERR_NONE Indicates dsSetFPDMode API was successfully called using iarmbus call.
 * @retval dsERR_GENERAL Indicates error due to general failure.
 * @pre dsFPInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsSetFPDMode (dsFPDMode_t eMode);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif
#endif /* _DS_FPD_H_ */

/** @} */
/** @} */
