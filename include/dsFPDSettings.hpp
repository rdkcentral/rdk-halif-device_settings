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
* @defgroup devicesettings
* @{
* @defgroup ds
* @{
**/


#ifndef _DS_FRONTPANELSETTINGS_H_
#define _DS_FRONTPANELSETTINGS_H_

#warning "CONFIGING GENERIC FRONTPANELSETTINGS"

#include "dsTypes.h"
#define _MAX_BRIGHTNESS 100
#define _MIN_BRIGHTNESS 0
#define _DEFAULT_LEVELS 10
#define _MAX_CYCLERATE  2
#define _MAX_HORZ_COLS  0
#define _MAX_VERT_ROWS  0
#define _MAX_HORZ_ITER  0
#define _MAX_VERT_ITER  0
#define _DEFAULT_COLOR_MODE 0

static   dsFPDColorConfig_t  kIndicatorColors[dsFPD_COLOR_MAX] = {
	{
		/*.Id = */ 0,
		/*.color = */ dsFPD_COLOR_BLUE,
	},
	{
		/*.Id = */ 1,
		/*.color = */ dsFPD_COLOR_GREEN,
	},
	{
		/*.Id = */ 2,
		/*.color = */ dsFPD_COLOR_RED,
	},
	{
		/*.Id = */ 3,
		/*.color = */ dsFPD_COLOR_YELLOW,
	},
	{
		/*.Id = */ 4,
		/*.color = */ dsFPD_COLOR_ORANGE,
	},
	{
		/*.Id = */ 5,
		/*.color = */ dsFPD_COLOR_WHITE,
	},

};


static const dsFPDIndicatorConfig_t kIndicators[] = {
	{
		/*.id = */ 			dsFPD_INDICATOR_MESSAGE,
		/*.supportedColors = */ kIndicatorColors,
		/*.maxBrightness   = */ _MAX_BRIGHTNESS,
		/*.maxCycleRate    = */  _MAX_CYCLERATE,
		/*.minBrightness   = */ _MIN_BRIGHTNESS,
        /*.levels          = */ _DEFAULT_LEVELS,
        /*.colorMode       = */ _DEFAULT_COLOR_MODE,

	},
	{
		/*.id = */ 				dsFPD_INDICATOR_POWER,
		/*.supportedColors = */ kIndicatorColors,
		/*.maxBrightness   = */ _MAX_BRIGHTNESS,
		/*.maxCycleRate    = */ _MAX_CYCLERATE,
		/*.minBrightness   = */ _MIN_BRIGHTNESS,
        /*.levels          = */ _DEFAULT_LEVELS,
        /*.colorMode       = */ _DEFAULT_COLOR_MODE,


	},
	{
		/*.id = */ 				dsFPD_INDICATOR_RECORD,
		/*.supportedColors = */ kIndicatorColors,
		/*.maxBrightness   = */ _MAX_BRIGHTNESS,
		/*.maxCycleRate   = */  _MAX_CYCLERATE,
		/*.minBrightness   = */ _MIN_BRIGHTNESS,
        /*.levels          = */ _DEFAULT_LEVELS,
        /*.colorMode       = */ _DEFAULT_COLOR_MODE,

	},
	{
		/*.id = */ 				dsFPD_INDICATOR_REMOTE,
		/*.supportedColors = */ kIndicatorColors,
		/*.maxBrightness   = */ _MAX_BRIGHTNESS,
		/*.maxCycleRate   = */  _MAX_CYCLERATE,
		/*.minBrightness   = */ _MIN_BRIGHTNESS,
        /*.levels          = */ _DEFAULT_LEVELS,
        /*.colorMode       = */ _DEFAULT_COLOR_MODE,

	},
};

static const dsFPDTextDisplayConfig_t  kTextDisplays[dsFPD_TEXTDISP_MAX] = {
	{
		/*.id = */ 					dsFPD_TEXTDISP_TEXT,
		/*.name   = */ 				"Text",
		/*.supportedColors =  */	kIndicatorColors,
		/*.maxBrightness = */		_MAX_BRIGHTNESS,
		/*.maxCycleRate = 	 */		_MAX_CYCLERATE,
		/*.supportedCharacters=*/ 	"ABCDEFG",
		/*.columns = */			 	_MAX_HORZ_COLS,
		/*.rows= */ 			 	_MAX_VERT_ROWS,
		/*.horizontal iterations =*/_MAX_HORZ_ITER,
		/*.vertical iterations */ 	_MAX_VERT_ITER,
		/*.levels */ 	            _DEFAULT_LEVELS,
		/*.colorMode       = */		_DEFAULT_COLOR_MODE
	},
};

#endif /* RPFRONTPANELSETTINGS_H_ */


/** @} */
/** @} */
