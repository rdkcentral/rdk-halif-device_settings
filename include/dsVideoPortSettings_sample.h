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
 * Describe the details about Device Settings HAL API specifications.
 *
 * <b> Following abbreviations present in HAL API </b>
 *
 * @par Abbreviations
 * - cb:      Callback function (suffix).
 * - DS:      Device Settings.
 * - HAL:     Hardware Abstraction Layer.
 * - _t:      Type (suffix).
 * - DTCP:    Digital Transmission Content Protection
 * - HDCP:    High-bandwidth Digital Copy Protection.
 * - HDMI:    High-Definition Multimedia Interface
 * 
 * @ingroup DSSETTINGS_HAL
 */


#ifndef _DS_VIDEOOUTPUTPORTSETTINGS_H_
#define _DS_VIDEOOUTPUTPORTSETTINGS_H_

#include "dsTypes.h"
#include "dsUtl.h"
#include "dsVideoResolutionSettings.h"


#ifdef __cplusplus
extern "C" {
#endif

namespace {
/*
 * Enumerate the supported configurations here.
 */
static const dsVideoPortType_t kSupportedPortTypes[] = { 
        dsVIDEOPORT_TYPE_HDMI ///< HDMI video output. 
    };

/* 
 * Enumerate all configurations for each port type. 
 */
static const dsVideoPortTypeConfig_t kConfigs[]= {
    {
    /*.typeId = */                  dsVIDEOPORT_TYPE_HDMI,    ///< See dsVideoPortType_t
    /*.name = */                    "HDMI",                   ///< Port name
    /*.dtcpSupported = */           false,                    ///< Is DTCP supported
    /*.hdcpSupported = */           true,                     ///< Is HDCP supported
    /*.numSupportedResolutions = */ dsUTL_DIM(kResolutions),  ///< Number of supported resolutions.
    /*.supportedResolutons = */     kResolutions,             ///< See dsTVResolution_t
    },
};

/*
 *  Enumerate all enabled Video Output Ports here.
 */
static const dsVideoPortPortConfig_t kPorts[] = {
    {
    /*.typeId = */                  {dsVIDEOPORT_TYPE_HDMI, 0}, ///< See dsVideoPortType_t
    /*.connectedAOP */              {dsAUDIOPORT_TYPE_HDMI, 0}, ///< See dsVideoPortType_t
    /*.defaultResolution = */       "720p"                      ///< Resolution name.
    },
};

}

#ifdef __cplusplus  /*.restrictedResollution = */   -1,   ///< Any restricted resolution; -1 if no.

}
#endif


#endif /* VIDEOOUTPUTPORTSETTINGS_H_ */


/** @} */
/** @} */
