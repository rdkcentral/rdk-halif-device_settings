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
* @{
* @defgroup hal Device Settings HAL
* @{
**/


#ifndef _DS_VIDEODEVICESETTINGS_H_
#define _DS_VIDEODEVICESETTINGS_H_

#include "dsUtl.h"
#include "dsTypes.h"


#ifdef __cplusplus
extern "C" {
#endif

namespace  {
/**
 * @brief A static constant array of supported ZOOM settings.
 *
 * The array is accessible only within the current translation unit and the
 * values cannot be modified at runtime.
 *
 * @note The size of the array is fixed and cannot be changed.
 */
static const dsVideoZoom_t kSupportedDFCs[] = { dsVIDEO_ZOOM_NONE, dsVIDEO_ZOOM_FULL, dsVIDEO_ZOOM_PLATFORM};
/**
 * @brief Default ZOOM Settings value
 *
 * The variable is accessible only within the current translation unit and the
 * values cannot be modified at runtime.
 *
 */
static const dsVideoZoom_t kDefaultDFC 	   = dsVIDEO_ZOOM_FULL;

/**
 * @brief Number of Video Devices supported
 *
 * The variable is accessible only within the current translation unit and the
 * values cannot be modified at runtime.
 *
 */
static const int kNumVideoDevices = 1;

/**
 * @brief A static constatnt array of the device configuration
 *
 * The variable is accessible only within the current translation unit and the
 * values cannot be modified at runtime.
 *
 * @note The size of the array is fixed and cannot be changed.
 */

static const dsVideoConfig_t kConfigs[]= {
		{
		/*.numSupportedDFCs = */ 		dsUTL_DIM(kSupportedDFCs), // 0 means "Info available at runtime"
		/*.supportedDFCs = */			kSupportedDFCs,
		/*.defaultDFC = */			    dsVIDEO_ZOOM_FULL,
		},
};

typedef int _SafetyCheck[(dsUTL_DIM(kConfigs) == kNumVideoDevices) ? 1 : -1];

}
#ifdef __cplusplus
}
#endif

#endif /* RPVIDEODEVICESETTINGS_H_ */


/** @} */
/** @} */
