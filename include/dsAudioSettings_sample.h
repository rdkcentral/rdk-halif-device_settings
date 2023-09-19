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

#ifndef _DS_AUDIOOUTPUTPORTSETTINGS_H
#define _DS_AUDIOOUTPUTPORTSETTINGS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "dsUtl.h"
#include "dsTypes.h"

namespace  {

/*
 * @brief This enumeration defines the supported audio configurations.
 */
/// Audio supported port types	
static const dsAudioPortType_t 	    kSupportedPortTypes[] 				= { dsAUDIOPORT_TYPE_HDMI, dsAUDIOPORT_TYPE_SPDIF };
/// Audio supported encoding types
static const dsAudioEncoding_t 		kSupportedHDMIEncodings[]			= { dsAUDIO_ENC_PCM, dsAUDIO_ENC_AC3};
/// Audio supported HDMI compression types
static const dsAudioCompression_t 	kSupportedHDMICompressions[] 		= { dsAUDIO_CMP_NONE, dsAUDIO_CMP_LIGHT, dsAUDIO_CMP_MEDIUM, dsAUDIO_CMP_HEAVY, };
/// Audio supported HDMI stereo mode types
static const dsAudioStereoMode_t 	kSupportedHDMIStereoModes[] 		= { dsAUDIO_STEREO_STEREO, dsAUDIO_STEREO_SURROUND, };
/// Audio supported SPDIF encoding types
static const dsAudioEncoding_t 		kSupportedSPDIFEncodings[] 			= { dsAUDIO_ENC_PCM, dsAUDIO_ENC_AC3, };
/// Audio supported SPDIF compression types 
static const dsAudioCompression_t 	kSupportedSPDIFCompressions[] 		= { dsAUDIO_CMP_NONE, dsAUDIO_CMP_LIGHT, dsAUDIO_CMP_MEDIUM, dsAUDIO_CMP_HEAVY, };
/// Audio supported SPDIF stereo mode types
static const dsAudioStereoMode_t 	kSupportedSPDIFStereoModes[] 		= { dsAUDIO_STEREO_STEREO, dsAUDIO_STEREO_SURROUND, };

/* 
 * This enumeration defines the supported Audio port types. 
 */
static const dsAudioTypeConfig_t 	kConfigs[]= {
		{
		/*.typeId = */					dsAUDIOPORT_TYPE_HDMI,
		/*.name = */					"HDMI", //HDMI
		/*.numSupportedCompressions = */dsUTL_DIM(kSupportedHDMICompressions),
		/*.compressions = */			kSupportedHDMICompressions,
		/*.numSupportedEncodings = */	dsUTL_DIM(kSupportedHDMIEncodings),
		/*.encodings = */				kSupportedHDMIEncodings,
		/*.numSupportedStereoModes = */	dsUTL_DIM(kSupportedHDMIStereoModes),
		/*.stereoModes = */				kSupportedHDMIStereoModes,
		},
		{
		/*.typeId = */					dsAUDIOPORT_TYPE_SPDIF,
		/*.name = */					"SPDIF", //SPDIF
		/*.numSupportedCompressions = */dsUTL_DIM(kSupportedSPDIFCompressions),
		/*.compressions = */			kSupportedSPDIFCompressions,
		/*.numSupportedEncodings = */	dsUTL_DIM(kSupportedSPDIFEncodings),
		/*.encodings = */				kSupportedSPDIFEncodings,
		/*.numSupportedStereoModes = */	dsUTL_DIM(kSupportedSPDIFStereoModes),
		/*.stereoModes = */				kSupportedSPDIFStereoModes,
		}
};

/*
 * This enumeration defines the video ports that are connected to each audio port.
 */
static const dsVideoPortPortId_t connectedVOPs[dsAUDIOPORT_TYPE_MAX][dsVIDEOPORT_TYPE_MAX] = {
		{/*VOPs connected to LR Audio */

		},
		{/*VOPs connected to HDMI Audio */
				{dsVIDEOPORT_TYPE_HDMI, 0},
		},
		{/*VOPs connected to SPDIF Audio */
				{dsVIDEOPORT_TYPE_HDMI, 0},
		},
};

/*
 * This enumeration defines the available audio ports on the device.  
 */
static const dsAudioPortConfig_t kPorts[] = {
		{
		/*.typeId = */ 					{dsAUDIOPORT_TYPE_HDMI, 0},
		/*.connectedVOPs = */			connectedVOPs[dsAUDIOPORT_TYPE_HDMI],
		},
		{
		/*.typeId = */ 					{dsAUDIOPORT_TYPE_SPDIF, 0},
		/*.connectedVOPs = */			connectedVOPs[dsAUDIOPORT_TYPE_SPDIF],
		},
};

}
#ifdef __cplusplus
}
#endif

#endif

/** @} */
/** @} */