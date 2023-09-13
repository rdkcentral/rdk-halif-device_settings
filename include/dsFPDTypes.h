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
 * - FPD:     Front-Panel Display.
 * - HAL:     Hardware Abstraction Layer.
 * - SAD:     Short Audio Descriptors
 * - EDID:    Extended Display Information Data.
 * - HEVC:    High Efficiency Video Coding
 * - DTCP:    Digital Transmission Content Protection
 * - HDCP:    High-bandwidth Digital Copy Protection.
 * - HDR:     High Dynamic Range
 * - HDMI:    High-Definition Multimedia Interface
 * - ARC:     Audio Return Channel.
 * - eARC:    Enhance Audio Return Channel
 * - RF:      Radio Frequency.
 * - MS12:    MultiStream 12.
 * - SPDIF:   Sony/Phillips Digital Interface
 * - AC-3:    Audio Compression 3
 * - CEA:     Consumer Electornic Association
 * - ITU:     International Telecommunication Union
 * - ITU-R:   ITU Radiocommunication Sector
 * - BT:      British Telecomm
 * - SMPTE:   Society of Television and Motion Picture Engineers
 * - YCbCr:   Y is luma (brightness), Cb is blue minus luma (B-Y) and Cr is red minus luma (R-Y)
 * - XvYCC:   extended-gamut YCbCr.
 * - RGB:     Red Green Blue
 * - eDVI:    Digital Video Interface
 * - eFCC:    Future Computing and Communication
 * - IEC:     International Electrotechnical Commission
 * - MPEG4:   Moving Picture Experts Group version 4, part 14.
 * - AVC:     Advanced Video Coding
 * - LED:     Light-Emitting Diode.
 * - SCART:   SCART stands for Syndicat des Constructeursd’AppareilsRadiorécepteurs et Téléviseurs 
 *                      or Radio and Television Receiver Manufacturers.
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

/** @addtogroup DSHAL_FPD_TYPES HAL Front Panel Display (FPD) Type Definitions
 *  @ingroup DSHAL_FPD
 *  @{
 */

/**
 * @brief dsFPDColor_t is an 4-byte integer that is composed of RGB32 value in the
 * following pattern:
 *
 * @todo explain this in words, instead of a formula
 * 
 * FPD_COLOR = (((R8)<<16) | ((G8)<< 8) | ((B8) << 0))
 *
 * The Most Significant 8 bit is reserved.
 */
typedef uint32_t dsFPDColor_t;

/**
 * @brief Defines the color values in RGB format.
 * @todo Check and see where the FPDColor calls are used, and if we need them or not.
*/
#define dsFPDColor_Make(R8,G8,B8)  (((R8)<<16) | ((G8)<< 8) | ((B8) )) ///< combine Red Green Blue value to a single Hex value
#define dsFPDColor_R(RGB32)    (((RGB32) >> 16) & 0xFF)                ///< Extract Red value form RGB value
#define dsFPDColor_G(RGB32)    (((RGB32) >>  8) & 0xFF)                ///< Extract Green value form RGB value
#define dsFPDColor_B(RGB32)    (((RGB32)      ) & 0xFF)                ///< Extract Blue value form RGB value

/**
 * @brief Define a set of common colors, for backward compatibility 
 * @todo check where these are used
 */
#define dsFPD_COLOR_BLUE   dsFPDColor_Make(0, 0, 0xFF)          ///< Blue color LED.                 
#define dsFPD_COLOR_GREEN  dsFPDColor_Make(0, 0xFF, 0)          ///< Green color LED.                
#define dsFPD_COLOR_RED    dsFPDColor_Make(0xFF, 0, 0x0)        ///< Red color LED.                  
#define dsFPD_COLOR_YELLOW dsFPDColor_Make(0xFF, 0xFF, 0xE0)    ///< Yellow color LED.               
#define dsFPD_COLOR_ORANGE dsFPDColor_Make(0xFF, 0x8C, 0x00)    ///< Orange color LED.               
#define dsFPD_COLOR_WHITE  dsFPDColor_Make(0xFF, 0xFF, 0xFF)    ///< White color LED.               
#define dsFPD_COLOR_MAX    6                                    ///< Out of range 

/**
 * @brief Front panel LED colors validation check.
 * @todo Move isValid functions to dsUtls
 */
#define dsFPDColor_isValid(t)  (((t) & 0xFF000000) == 0)

/**
 * @brief dsFPDIndicator_t is an ID number that  uniquely identifies a HAL
 * LED entity on the front panel. Each HAL implementation is free
 * to assign any number to its LEDs. The mapping of LED ID to its
 * display name (such as "Record LED") is done outside HAL library.
 * @todo Look into how this is supposed to work
 */
typedef int32_t dsFPDIndicator_t;

/**
 * @brief This enumeration pre-defines common front panel indicators.
 * Implementation may not have to use these enumerators.
 * @todo change to enum in future phase
 */
#define    dsFPD_INDICATOR_MESSAGE  0   ///< Message/Mail LED.         
#define    dsFPD_INDICATOR_POWER    1   ///< Power LED.                
#define    dsFPD_INDICATOR_RECORD   2   ///< Record LED.               
#define    dsFPD_INDICATOR_REMOTE   3   ///< Remote LED.               
#define    dsFPD_INDICATOR_RFBYPASS 4   ///< RF Bypass LED.            
#define    dsFPD_INDICATOR_MAX      5   ///< Out of range            

/**
 * @brief Front panel LED indicator type validation check.
 */
#define dsFPDIndicator_isValid(t)  (true)

/**
 * @brief This enumeration defines the FPD text display types.
 */
typedef enum __dsFPDTextDisplay_t
{
    dsFPD_TEXTDISP_TEXT,    ///< 7-segment LED display.                  
    dsFPD_TEXTDISP_MAX      ///< Out of range 
}dsFPDTextDisplay_t;

/**
 * @brief FPD text display type validation check.
 */
#define dsFPDTextDisplay_isValid(t)  (((t)  >= dsFPD_TEXTDISP_TEXT ) && ((t) < dsFPD_TEXTDISP_MAX))

/**
 * @brief This enumeration defines the front panel display state.
 */
typedef enum __dsFPDState_t
{
    dsFPD_STATE_OFF=0,  ///< FPD State Disable.
    dsFPD_STATE_ON,     ///< FPD State Enable.
    dsFPD_STATE_MAX,    ///< Out of range 
}dsFPDState_t;

/**
 * @brief This enumeration defines the time formats to be used in the Front panel text display
 */
typedef enum __dsFPDTimeFormat_t
{
    dsFPD_TIME_12_HOUR, ///< 12 hour time format.
    dsFPD_TIME_24_HOUR, ///< 24 hour time format.
    dsFPD_TIME_STRING,  ///< Text string.        
    dsFPD_TIME_MAX      ///< Out of range 
}dsFPDTimeFormat_t;
/**
 * @brief Maximum Value of FPD Led Brightness
 */

#define dsFPD_BRIGHTNESS_MAX    100     ///< Maximum Value of FPD LED brightness.

/**
 * @brief Type definition for the brightness setting of a front panel indicator LED.
 *
 */
typedef uint32_t dsFPDBrightness_t;

/**
 * @brief This enumeration defines the front panel display mode.
 */
typedef enum __dsFPDMode_t{
    dsFPD_MODE_ANY = 0, ///< All modes (text/clock) are supported
    dsFPD_MODE_TEXT,    ///< only Text mode is supported
    dsFPD_MODE_CLOCK,   ///< only clock mode is supported
    dsFPD_MODE_MAX,     ///< Out of range 
} dsFPDMode_t;

/* End of DSHAL_FPD_TYPES doxygen group */
/**
 * @}
 */
/** @} */ // End of DSHAL_API HAL Data Types
/** @} */ // End of HPK