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

/** @defgroup Device_Settings Device Settings Module
 * @{
 */

/**@defgroup Device_Settings_HAL Device Settings HAL
 * @par Application API Specification
 * Described herein are the DeviceSettings HAL types and functions that are part of
 * the FPD subsystem. The FPD subsystem manages system-specific HAL operations.
 *  @{
 */

/** @defgroup dsFPD_HAL Device Settings Front Panel Display HAL
 *  @{
 * @par Application API Specification
 * dsFPD HAL provides an interface for managing Front Panel Display settings
 */

/** @defgroup DSHAL_FPD_API Device Settings HAL Front Panel Display Public API
 *
 *
 *  @{
 */

/**
 * Describe the details about Device Settings HAL API specifications.
 *
 * <b> Following abbreviations present in Device Settings Front Panel Display API </b>
 *
 * @par Abbreviations
 * - DS  : Device Settings
 * - FPD : Front-Panel Display
 * - HAL : Hardware Abstraction Layer
 * - LED : Light-Emitting Diode
 * - SoC : System-On-Chip
 * - ms  : miliseconds
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


#ifndef __DS_FPD_H__
#define __DS_FPD_H__

#include <sys/types.h>
#include "dsError.h"
#include "dsFPDTypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief  Initializes the Front Panel Display(FPD) sub-module of Device Settings HAL.
 *
 * This function allocates required resources for Front Panel and is required to be called before the other APIs in this module.
 * 
 * @todo Proper prefix for all enums and APIs to be added in next phase ie DS_FPD_*
 *
 * @return dsError_t                  -  Status
 * @retval dsERR_NONE                 -  Success
 * @retval dsERR_ALREADY_INITIALIZED  -  Function is already initialized
 * @retval dsERR_GENERAL              -  Underlying undefined platform error
 * 
 * @todo Remove dsERR_GENERAL and add specific error codes in next phase
 *
 * @warning  This API is Not thread safe.
 * 
 * @see dsFPTerm()
 * 
 */
dsError_t dsFPInit (void);

/**
 * @brief  Sets blink pattern of specified FP LED.
 * 
 * This function is used to set the individual discrete LED to blink for a specified number of iterations with blink interval.
 * This function must return dsERR_OPERATION_NOT_SUPPORTED if FP State is "OFF".
 *
 * @param[in] eIndicator        -  FPD indicator index. @see dsFPDIndicator_t
 * @param[in] uBlinkDuration    -  Blink interval. The time in ms the text display will remain ON 
 *                                   during one blink iteration.
 * @param[in] uBlinkIterations  -  The number of iterations per minute data will 
 *                                   blink.
 * 
 * @return dsError_t                      -  Status
 * @retval dsERR_NONE                     -  Success
 * @retval dsERR_NOT_INITIALIZED          -  Module is not initialised
 * @retval dsERR_INVALID_PARAM            -  Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED  -  The attempted operation is not supported
 * @retval dsERR_GENERAL                  -  Underlying undefined platform error
 * 
 * 
 * @pre dsFPInit() must be called and FP State must be "ON" before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsSetFPBlink (dsFPDIndicator_t eIndicator, unsigned int uBlinkDuration, unsigned int uBlinkIterations);

/**
 * @brief  Sets the brightness level of specified Front Panel LED.
 * 
 * This function will set the brightness of the specified discrete LED on the Front
 * Panel Display to the specified brightness level. This function must return dsERR_OPERATION_NOT_SUPPORTED
 * if the FP State is "OFF".
 *
 * @param[in] eIndicator  - FPD indicator index. @see dsFPDIndicator_t
 * @param[in] eBrightness - The brightness value(0 to 100) for the specified indicator.
 *                            @see dsFPDBrightness_t
 *
 * @return dsError_t                      -  Status
 * @retval dsERR_NONE                     -  Success
 * @retval dsERR_NOT_INITIALIZED          -  Module is not initialised
 * @retval dsERR_INVALID_PARAM            -  Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED  -  The attempted operation is not supported
 * @retval dsERR_GENERAL                  -  Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called and FP State must be "ON" before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @@see dsGetFPBrightness()
 * 
 */
dsError_t dsSetFPBrightness (dsFPDIndicator_t eIndicator, dsFPDBrightness_t eBrightness);

/**
 * @brief  Gets the brightness level of specified Front Panel LED.
 * 
 * This function returns the brightness level of the specified discrete LED on the Front
 * Panel. This function must return dsERR_OPERATION_NOT_SUPPORTED if FP State is "OFF".
 *
 * @param[in]  eIndicator  - FPD indicator index. @see dsFPDIndicator_t
 * @param[out] pBrightness - current brightness value(0 to 100) of the specified indicator. 
 *                             @see dsFPDBrightness_t
 *
 * @return dsError_t                      -  Status
 * @retval dsERR_NONE                     -  Success
 * @retval dsERR_NOT_INITIALIZED          -  Module is not initialised
 * @retval dsERR_INVALID_PARAM            -  Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED  -  The attempted operation is not supported
 * @retval dsERR_GENERAL                  -  Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called and FP State must be "ON" before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetFPBrightness()
 * 
 */
dsError_t dsGetFPBrightness (dsFPDIndicator_t eIndicator, dsFPDBrightness_t *pBrightness);

/**
 * @brief  This function will set the Front Panel indicator state of specified discrete LED.
 *
 * @param[in] eIndicator - FPD indicator index. @see dsFPDIndicator_t
 * @param[in] state      - Indicates the state of the indicator to be set. @see dsFPDState_t
 *
 * @return dsError_t                      -  Status
 * @retval dsERR_NONE                     -  Success
 * @retval dsERR_NOT_INITIALIZED          -  Module is not initialised
 * @retval dsERR_INVALID_PARAM            -  Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED  -  The attempted operation is not supported
 * @retval dsERR_GENERAL                  -  Underlying undefined platform error
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
 * @brief This function will get the Front Panel Indicator state of Specified discrete LED.
 * 
 * @param[in]  eIndicator - FPD indicator index. @see dsFPDIndicator_t
 * @param[out] state      - current state of the specified indicator. @see dsFPDState_t
 *
 * @return dsError_t                      -  Status
 * @retval dsERR_NONE                     -  Success
 * @retval dsERR_NOT_INITIALIZED          -  Module is not initialised
 * @retval dsERR_INVALID_PARAM            -  Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED  -  The attempted operation is not supported
 * @retval dsERR_GENERAL                  -  Underlying undefined platform error
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
 * @brief  Sets the color of specified Front Panel LED.
 * 
 * This function sets the color of the specified Front Panel Indicator LED, if the 
 * indicator supports it (i.e. is multi-colored). It must return
 * dsERR_OPERATION_NOT_SUPPORTED if the indicator is single-colored or if the FP State is "OFF".
 *
 * @param[in] eIndicator    - FPD indicator index. @see dsFPDIndicator_t
 * @param[in] eColor        - The color index for the specified indicator. @see dsFPDColor_t
 *
 * @return dsError_t                      -  Status
 * @retval dsERR_NONE                     -  Success
 * @retval dsERR_NOT_INITIALIZED          -  Module is not initialised
 * @retval dsERR_INVALID_PARAM            -  Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED  -  The attempted operation is not supported
 * @retval dsERR_GENERAL                  -  Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called and FP State must be "ON" before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetFPColor()
 * 
 */
dsError_t dsSetFPColor (dsFPDIndicator_t eIndicator, dsFPDColor_t eColor);

/**
 * @brief  Gets the color of specified Front Panel LED.
 * 
 * This function gets the color of the specified Front Panel Indicator LED, if the
 * indicator supports it (i.e. is multi-colored). It must return
 * dsERR_OPERATION_NOT_SUPPORTED if the indicator is single-colored or if the FP State is "OFF".
 *
 * @param[in] eIndicator - FPD indicator index. @see dsFPDIndicator_t
 * @param[out] pColor    - current color value of the specified indicator. @see dsFPDColor_t
 *
 * @return dsError_t                      -  Status
 * @retval dsERR_NONE                     -  Success
 * @retval dsERR_NOT_INITIALIZED          -  Module is not initialised
 * @retval dsERR_INVALID_PARAM            -  Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED  -  The attempted operation is not supported
 * @retval dsERR_GENERAL                  -  Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called and FP State must be "ON" before calling this API. 
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetFPColor()
 * 
 */
dsError_t dsGetFPColor (dsFPDIndicator_t eIndicator, dsFPDColor_t *pColor);

/**
 * @brief  Sets the time on 7-Segment Display.
 * 
 * This function sets the 7-segment display LEDs to show the time in specified format.
 * The format (12/24-hour) has to be specified. If there are no 7-Segment display LEDs present on the
 * device or if the FP State is "OFF" then dsERR_OPERATION_NOT_SUPPORTED must be returned.
 * It must return dsERR_INVALID_PARAM if the format and hours values do not agree,
 * or if the hours/minutes are invalid.
 *
 * @param[in] eTimeFormat   - Time format (12 or 24 hrs). @see dsFPDTimeFormat_t
 * @param[in] uHour         - Hour information
 * @param[in] uMinutes      - Minutes information
 *
 * @return dsError_t                      -  Status
 * @retval dsERR_NONE                     -  Success
 * @retval dsERR_NOT_INITIALIZED          -  Module is not initialised
 * @retval dsERR_INVALID_PARAM            -  Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED  -  The attempted operation is not supported.
 * @retval dsERR_GENERAL                  -  Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called and FP State must be "ON" before calling this API.
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetFPTimeFormat()
 * 
 */
dsError_t dsSetFPTime (dsFPDTimeFormat_t eTimeFormat, const unsigned int uHour, const unsigned int uMinutes);

/**
 * @brief  Displays the specified text on 7-segment display.
 * 
 * This function is used to set the 7-segment display LEDs to show the given text.  
 * If there are no 7-Segment display LEDs present on the device or if the FP State is "OFF",
 * then dsERR_OPERATION_NOT_SUPPORTED must be returned.
 * Maximum length of Text is 10 characters.
 *
 * @param[in] pText - Text to be displayed
 *
 * @return dsError_t                      -  Status
 * @retval dsERR_NONE                     -  Success
 * @retval dsERR_NOT_INITIALIZED          -  Module is not initialised
 * @retval dsERR_INVALID_PARAM            -  Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED  -  The attempted operation is not supported
 * @retval dsERR_GENERAL                  -  Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called and FP State must be "ON" before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetFPTextBrightness() 
 * 
 */
dsError_t dsSetFPText(const char* pText);

/**
 * @brief  Sets the brightness level of 7-segment display.
 * 
 * This function will set the brightness of the specified 7-segment display LEDs on the Front
 * Panel Display to the specified brightness level. If there are no 7-Segment display LEDs present
 * on the device or if the FP State is "OFF" then dsERR_OPERATION_NOT_SUPPORTED must be returned.
 *
 * @param[in] eIndicator    - FPD Text indicator index. @see dsFPDTextDisplay_t
 * @param[in] eBrightness   - The brightness value for the specified indicator. From 0 to 100. 
 *                              @see dsFPDBrightness_t
 *
 * @return dsError_t                      -  Status
 * @retval dsERR_NONE                     -  Success
 * @retval dsERR_NOT_INITIALIZED          -  Module is not initialised
 * @retval dsERR_INVALID_PARAM            -  Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED  -  The attempted operation is not supported
 * @retval dsERR_GENERAL                  -  Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called and FP State must be "ON" before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetFPTextBrightness(), dsSetFPText()
 * 
 */
dsError_t dsSetFPTextBrightness (dsFPDTextDisplay_t eIndicator, dsFPDBrightness_t eBrightness);

/**
 * @brief  Gets the brightness of 7-segment display LEDs.
 * 
 * This function will get the brightness of the specified 7-segment display LEDs on the Front
 * Panel Text Display. If there are no 7-segment display LEDs present or if the FP State is "OFF"
 * then dsERR_OPERATION_NOT_SUPPORTED must be returned.
 *
 * @param[in] eIndicator    - FPD Text indicator index. @see dsFPDTextDisplay_t
 * @param[out] eBrightness  - Brightness value. From 0 to 100. @see dsFPDBrightness_t.
 *
 * @return dsError_t                      -  Status
 * @retval dsERR_NONE                     -  Success
 * @retval dsERR_NOT_INITIALIZED          -  Module is not initialised
 * @retval dsERR_INVALID_PARAM            -  Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED  -  The attempted operation is not supported
 * @retval dsERR_GENERAL                  -  Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called and FP State must be "ON" before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetFPTextBrightness()
 * 
 */
dsError_t dsGetFPTextBrightness (dsFPDTextDisplay_t eIndicator, dsFPDBrightness_t *eBrightness);

/**
 * @brief  Enable/Disable the clock display of Front Panel.
 * 
 * This function will enable or disable displaying of clock. It will return dsERR_OPERATION_NOT_SUPPORTED
 * if Clock display is not available
 *
 * @param[in] enable    - Indicates the clock to be enabled or disabled. 
 *                          1 if enabled, 0 if disabled.
 *
 * @return dsError_t                      -  Status
 * @retval dsERR_NONE                     -  Success
 * @retval dsERR_NOT_INITIALIZED          -  Module is not initialised
 * @retval dsERR_INVALID_PARAM            -  Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED  -  The attempted operation is not supported
 * @retval dsERR_GENERAL                  -  Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called and FP State must be "ON" before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsFPEnableCLockDisplay (int enable);

/**
 * @brief  Enables Text Scrolling on 7-segment display.
 * 
 * This function scrolls the text in the 7-segment display LEDs for the given number of iterations.
 * If there are no 7-segment display LEDs present or if the FP State is "OFF" then
 * dsERR_OPERATION_NOT_SUPPORTED must be returned. Horizontal and Vertical scroll cannot work at the same time.
 *
 * @param[in] uScrollHoldOnDur       - Duration in ms to hold each char before scrolling to the next position 
 *                                       during one scroll iteration
 * @param[in] uHorzScrollIterations  - Number of iterations to scroll horizontally
 * @param[in] uVertScrollIterations  - Number of iterations to scroll vertically
 *
 * @return dsError_t                      -  Status
 * @retval dsERR_NONE                     -  Success
 * @retval dsERR_NOT_INITIALIZED          -  Module is not initialised
 * @retval dsERR_INVALID_PARAM            -  Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED  -  The attempted operation is not supported
 * @retval dsERR_GENERAL                  -  Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called and FP State must be "ON" before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsSetFPScroll(unsigned int uScrollHoldOnDur, unsigned int uHorzScrollIterations, unsigned int uVertScrollIterations);

/**
 * @brief  Terminates the the Front Panel Display sub-module.
 * 
 * This function resets any data structures used within Front Panel sub-module,
 * and releases all the resources allocated during the init function.
 *
 * @return dsError_t                      -  Status
 * @retval dsERR_NONE                     -  Success
 * @retval dsERR_NOT_INITIALIZED          -  Module is not initialised
 * @retval dsERR_OPERATION_NOT_SUPPORTED  -  The attempted operation is not supported
 * @retval dsERR_GENERAL                  -  Underlying undefined platform error
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
 * @brief  This function sets the 7-segment display LEDs to show the 
 * specified time in specified format. It must return dsERR_OPERATION_NOT_SUPPORTED 
 * if the underlying hardware does not have support for Text or Clock.
 *
 * @param[in] eTimeFormat   -  Indicates the time format (12 hour or 24 hour). 
 *                               @see dsFPDTimeFormat_t
 *
 * @return dsError_t                      -  Status
 * @retval dsERR_NONE                     -  Success
 * @retval dsERR_NOT_INITIALIZED          -  Module is not initialised
 * @retval dsERR_INVALID_PARAM            -  Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED  -  The attempted operation is not supported
 * @retval dsERR_GENERAL                  -  Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called and FP State must be "ON" before calling this API.
 * 
 * @note The time display should also change according to the new format set.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetFPTimeFormat()
 * 
 */
dsError_t dsSetFPTimeFormat (dsFPDTimeFormat_t eTimeFormat);

 /**
 * @brief  This function gets the current time format set on 7-segment display LEDs panel.
 * It must return dsERR_OPERATION_NOT_SUPPORTED if the underlying hardware does not 
 * have support for clock.
 *
 * @param[out] pTimeFormat      - Current time format value (12 hour or 24 hour). 
 *                                  @see dsFPDTimeFormat_t
 *
 * @return dsError_t                      -  Status
 * @retval dsERR_NONE                     -  Success
 * @retval dsERR_NOT_INITIALIZED          -  Module is not initialised
 * @retval dsERR_INVALID_PARAM            -  Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED  -  The attempted operation is not supported
 * @retval dsERR_GENERAL                  -  Underlying undefined platform error
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
 * @brief  Sets the display mode of the FPD text.
 * 
 * This function sets the display mode (clock or text or both) for FPD.
 * It must return dsERR_OPERATION_NOT_SUPPORTED if the underlying hardware does not 
 * have support for Text or Clock.
 *
 * @param[in] eMode - Indicates the mode. @see dsFPDMode_t
 *
 * @return dsError_t                      -  Status
 * @retval dsERR_NONE                     -  Success
 * @retval dsERR_NOT_INITIALIZED          -  Module is not initialised
 * @retval dsERR_INVALID_PARAM            -  Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED  -  The attempted operation is not supported
 * @retval dsERR_GENERAL                  -  Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called and FP State must be "ON" before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */
dsError_t dsSetFPDMode (dsFPDMode_t eMode);

/**
 * @brief Gets the current power LED state
 * 
 * This function gets the current power LED state
 *
 * @param[out] returns - Current LED state. @see dsFPDLedState_t
 *
 * @return dsError_t                      -  Status
 * @retval dsERR_NONE                     -  Success
 * @retval dsERR_NOT_INITIALIZED          -  Module is not initialised
 * @retval dsERR_INVALID_PARAM            -  Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED  -  The attempted operation is not supported
 * @retval dsERR_GENERAL                  -  Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called and FP State must be "ON" before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsFPSetLEDState()
 */
dsError_t dsFPGetLEDState (dsFPDLedState_t* state);

/**
 * @brief Sets the power LED state
 * 
 * This function sets the power LED state
 *
 * @param[in] state - LED state. @see dsFPDLedState_t
 *
 * @return dsError_t                      -  Status
 * @retval dsERR_NONE                     -  Success
 * @retval dsERR_NOT_INITIALIZED          -  Module is not initialised
 * @retval dsERR_INVALID_PARAM            -  Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED  -  The attempted operation is not supported
 * @retval dsERR_GENERAL                  -  Underlying undefined platform error
 * 
 * @pre dsFPInit() must be called and FP State must be "ON" before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsFPGetLEDState()
 */
dsError_t dsFPSetLEDState (dsFPDLedState_t state);

#ifdef __cplusplus
}
#endif
#endif /* __DS_FPD_H__ */

/** @} */ // End of DSHAL_FPD_API doxygen group 
/** @} */ // End of DS FPD HAL
/** @} */ // End of Device Settings HAL
/** @} */ // End of Device Settings Module
/** @} */ // End of HPK
