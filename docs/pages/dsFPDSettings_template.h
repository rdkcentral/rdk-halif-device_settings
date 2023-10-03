/*
 * If not stated otherwise in this file or this component's Licenses.txt file the
 * following copyright and licenses apply:
 *
 * Copyright 2020 RDK Management
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

/** @addtogroup Device_Settings Device Settings Module
 * @{
 */

/** @addtogroup Device_Settings_HAL Device Settings HAL
 * @par Application API Specification
 * Described herein are the DeviceSettings HAL types and functions that are part of
 * the FPD subsystem. The FPD subsystem manages system-specific HAL operations.
 *  @{
 */

/** @addtogroup dsFPD_HAL Device Settings Front Panel Display HAL
 *  @{
 * @par Application API Specification
 * dsFPD HAL provides an interface for managing Front Panel Display settings
 */

/** @defgroup dsFPD_Settings_Template Device Settings Front Panel Display Settings Template
 *  @{
 * @par Application API Specification
 * dsFPD provides an template for various Front Panel Indicator configurations
 */

#ifndef __DS_FPD_SETTINGS_H__
#define __DS_FPD_SETTINGS_H__

#warning "CONFIGING PLATFORM FRONTPANELSETTINGS"

#include "include/dsFPDTypes.h"

#ifdef __cplusplus
extern "C" {
namespace {
#endif

/**
 * @brief Max brightness
 */
#define _MAX_BRIGHTNESS 100
/**
 * @brief Min brightness
 */
#define _MIN_BRIGHTNESS 0
/**
 * @brief Default levels
 */
#define _DEFAULT_LEVELS 10
/**
 * @brief Max Cyclerate
 */
#define _MAX_CYCLERATE  2
/**
 * @brief Max Horizontal Columns
 */
#define _MAX_HORZ_COLS  0
/**
 * @brief Max vertical rows
 */
#define _MAX_VERT_ROWS  0
/**
 * @brief Max Horizontal iterators
 */
#define _MAX_HORZ_ITER  0
/**
 * @brief Max vertical iterators
 */
#define _MAX_VERT_ITER  0
/**
 * @brief Default color mode
 */
#define _DEFAULT_COLOR_MODE 0
/**
 * @brief Color Max
 */
#define dsFPD_COLOR_MAX_NEW 1

/**
 * @brief Structure that defines the Front Panel Display Color Configurations
 */
typedef struct _dsFPDColorConfig_t {
	int id;
	dsFPDColor_t color;
}dsFPDColorConfig_t;

/**
 * @brief Structure that defines the Front Panel Display Indicator Configurations
 */
typedef struct _dsFPDIndicatorConfig_t {
	dsFPDIndicator_t id;
	dsFPDColorConfig_t * supportedColors;
	int	maxBrightness;
	int maxCycleRate;
    int minBrightness;
    int levels;
    int colorMode;
} dsFPDIndicatorConfig_t;

/**
 * @brief Structure that defines the Front Panel Text Display Configurations
 */
typedef struct _dsFPDTextDisplayConfig_t {
	dsFPDTextDisplay_t id;
	const char * name;
	dsFPDColorConfig_t * supportedColors;
	int	maxBrightness;
	int maxCycleRate;
	const char * supportedCharacters;
	int columns;
	int rows;
	int	maxHorizontalIterations;
	int maxVerticalIterations;
    int levels;
    int colorMode;
} dsFPDTextDisplayConfig_t;

/**
 * @brief Array that holds various Front Panel Indicator Colors
 */
static   dsFPDColorConfig_t  kIndicatorColors[dsFPD_COLOR_MAX_NEW] = {
	{
		/*.Id = */ 2,
		/*.color = */ dsFPD_COLOR_RED,
	},
};

/**
 * @brief Array that holds Front Panel Indicator Configurations
 */
static const dsFPDIndicatorConfig_t kIndicators[] = {
	{
		/*.id = */ 			dsFPD_INDICATOR_POWER,
		/*.supportedColors = */		kIndicatorColors,
		/*.maxBrightness   = */ 	_MAX_BRIGHTNESS,
		/*.maxCycleRate    = */ 	_MAX_CYCLERATE,
		/*.minBrightness   = */ 	_MIN_BRIGHTNESS,
        	/*.levels          = */ 	_DEFAULT_LEVELS,
        	/*.colorMode       = */ 	_DEFAULT_COLOR_MODE,
	},
};

/**
 * @brief Array that holds Front Panel Text Display Configurations
 */
static const dsFPDTextDisplayConfig_t  kTextDisplays[dsFPD_TEXTDISP_MAX] = {
	{
		/*.id = */ 			dsFPD_TEXTDISP_TEXT,
		/*.name   = */ 			"Text",
		/*.supportedColors =  */	kIndicatorColors,
		/*.maxBrightness = */		_MAX_BRIGHTNESS,
		/*.maxCycleRate = 	 */	_MAX_CYCLERATE,
		/*.supportedCharacters=*/ 	"ABCDEFG",
		/*.columns = */			_MAX_HORZ_COLS,
		/*.rows= */ 			_MAX_VERT_ROWS,
		/*.horizontal iterations =*/    _MAX_HORZ_ITER,
		/*.vertical iterations */ 	_MAX_VERT_ITER,
		/*.levels */ 	                _DEFAULT_LEVELS,
		/*.colorMode       = */		_DEFAULT_COLOR_MODE
	},
};

#ifdef __cplusplus
}
}
#endif
#endif /* __DS_FPD_SETTINGS_H__ */

/** @} */ // End of DS FP Settings Template
/** @} */ // End of DS FPD HAL
/** @} */ // End of Device Settings HAL
/** @} */ // End of Device Settings Module
/** @} */ // End of HPK
