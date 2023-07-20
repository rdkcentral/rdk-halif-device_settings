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

/** @addtogroup DS_Manager_HAL DS Manager Hal
 *  @{
 */

#ifndef _DS_AUDIOOUTPUTPORTSETTINGS_H
#define _DS_AUDIOOUTPUTPORTSETTINGS_H

#ifdef __cplusplus
extern "C" {
#endif

#include "dsUtl.h"
#include "dsTypes.h"

namespace  {

/*
 * Enumerate the supported configurations here.
 */

/**
 * @brief A static constant array of supported HDMI port types.
 *
 * The array is accessible only within the current unit and the
 * values cannot be modified at runtime.
 *
 */
static const dsAudioPortType_t      kSupportedPortTypes[]       
                                    = { 
                                        dsAUDIOPORT_TYPE_HDMI,      ///< See dsAudioPortType_t 
                                        dsAUDIOPORT_TYPE_SPDIF      ///< See dsAudioPortType_t
                                      }; ///< Supported Port types.

/**
 * @brief A static constant array of supported HDMI encoding settings.
 *
 * The array is accessible only within the current unit and the
 * values cannot be modified at runtime.
 *
 */
static const dsAudioEncoding_t      kSupportedHDMIEncodings[]   
                                    = { 
                                        dsAUDIO_ENC_PCM,            ///< See dsAudioEncoding_t
                                        dsAUDIO_ENC_AC3             ///< See dsAudioEncoding_t
                                      }; ///< Supported audio encodings for HDMI port.

/**
 * @brief A static constant array of supported HDMI audio compression settings.
 *
 * The array is accessible only within the current unit and the
 * values cannot be modified at runtime.
 *
 */
static const dsAudioCompression_t   kSupportedHDMICompressions[]      
                                    = { 
                                        dsAUDIO_CMP_NONE,           ///< See dsAudioCompression_t
                                        dsAUDIO_CMP_LIGHT,          ///< See dsAudioCompression_t
                                        dsAUDIO_CMP_MEDIUM,         ///< See dsAudioCompression_t
                                        dsAUDIO_CMP_HEAVY,          ///< See dsAudioCompression_t
                                      }; ///< Supported audio compressions for HDMI port.

/**
 * @brief A static constant array of supported HDMI audio stereo settings.
 *
 * The array is accessible only within the current unit and the
 * values cannot be modified at runtime.
 *
 */
static const dsAudioStereoMode_t    kSupportedHDMIStereoModes[]       
                                    = { 
                                        dsAUDIO_STEREO_STEREO,      ///< See dsAudioStereoMode_t
                                        dsAUDIO_STEREO_SURROUND,    ///< See dsAudioStereoMode_t    
                                      }; ///< Supported stereo modes for HDMI port.
/**
 * @brief A static constant array of supported SPDIF encoding settings.
 *
 * The array is accessible only within the current unit and the
 * values cannot be modified at runtime.
 *
 */
static const dsAudioEncoding_t      kSupportedSPDIFEncodings[]  
                                    = { 
                                        dsAUDIO_ENC_PCM,            ///< See dsAudioEncoding_t
                                        dsAUDIO_ENC_AC3,            ///< See dsAudioEncoding_t 
                                      }; ///< Supported audio encodings for SPDIF port.
/**
 * @brief A static constant array of supported SPDIF audio compression settings.
 *
 * The array is accessible only within the current unit and the
 * values cannot be modified at runtime.
 *
 */
static const dsAudioCompression_t   kSupportedSPDIFCompressions[]
                                    = { 
                                        dsAUDIO_CMP_NONE,           ///< See dsAudioCompression_t
                                        dsAUDIO_CMP_LIGHT,          ///< See dsAudioCompression_t
                                        dsAUDIO_CMP_MEDIUM,         ///< See dsAudioCompression_t
                                        dsAUDIO_CMP_HEAVY,          ///< See dsAudioCompression_t
                                      }; ///< Supported audio compressions for SPDIF port.

/**
 * @brief A static constant array of supported SPDIF audio stereo settings.
 *
 * The array is accessible only within the current unit and the
 * values cannot be modified at runtime.
 *
 */
static const dsAudioStereoMode_t    kSupportedSPDIFStereoModes[]      
                                    = { 
                                        dsAUDIO_STEREO_STEREO,      ///< See dsAudioStereoMode_t
                                        dsAUDIO_STEREO_SURROUND,    ///< See dsAudioStereoMode_t  
                                      }; ///< Supported audio compressions for SPDIF port.

/* 
 * Enumerate the supported Audio port types 
 */

static const dsAudioTypeConfig_t    kConfigs[]= {
    {
    /*.typeId = */                  dsAUDIOPORT_TYPE_HDMI,                  ///< See dsAudioPortType_t. 
    /*.name = */                    "HDMI",                                 ///< Port name.
    /*.numSupportedCompressions = */dsUTL_DIM(kSupportedHDMICompressions),  ///< Number of supported audio compressions for HDMI port.
    /*.compressions = */            kSupportedHDMICompressions,             ///< List of supported compressions for HDMI port.
    /*.numSupportedEncodings = */   dsUTL_DIM(kSupportedHDMIEncodings),     ///< Number of supported encodings for HDMI port.
    /*.encodings = */               kSupportedHDMIEncodings,                ///< List of supported encodings for HDMI port.
    /*.numSupportedStereoModes = */ dsUTL_DIM(kSupportedHDMIStereoModes),   ///< Number of supported stereo modes for HDMI port.
    /*.stereoModes = */             kSupportedHDMIStereoModes,              ///< List of supported stereo modes for HDMI port.
    },
    {
    /*.typeId = */                  dsAUDIOPORT_TYPE_SPDIF,                 ///< See dsAudioPortType_t
    /*.name = */                    "SPDIF", //SPDIF                        ///< Port name
    /*.numSupportedCompressions = */dsUTL_DIM(kSupportedSPDIFCompressions), ///< Number of supported audio compressions for SPDIF port.
    /*.compressions = */            kSupportedSPDIFCompressions,            ///< List of supported compressions for SPDIF port.
    /*.numSupportedEncodings = */   dsUTL_DIM(kSupportedSPDIFEncodings),    ///< Number of supported encodings for SPDIF port.
    /*.encodings = */               kSupportedSPDIFEncodings,               ///< List of supported encodings for SPDIF port.
    /*.numSupportedStereoModes = */ dsUTL_DIM(kSupportedSPDIFStereoModes),  ///< Number of supported stereo modes for SPDIF port.
    /*.stereoModes = */             kSupportedSPDIFStereoModes,             ///< List of supported stereo modes for SPDIF port.
    }
};  ///< Configs for each of the supported audio types.

/*
 * Enumerate the Video Ports that are connected to each Audio port.
 */

static const dsVideoPortPortId_t connectedVOPs[dsAUDIOPORT_TYPE_MAX][dsVIDEOPORT_TYPE_MAX] = {
        {/*VOPs connected to LR Audio */

        },
        {/*VOPs connected to HDMI Audio */
                {
                    dsVIDEOPORT_TYPE_HDMI,  ///< See dsVideoPortType_t
                    0                       ///< Selected video port.
                },
        },
        {/*VOPs connected to SPDIF Audio */
                {
                    dsVIDEOPORT_TYPE_HDMI,  ///< See dsVideoPortType_t
                    0                       ///< Selected video port.
                },
        },
};

/*
 * Enumerate the Audio Ports available on the device.  
 */

static const dsAudioPortConfig_t kPorts[] = {
    {
    /*.typeId = */          {
                                dsAUDIOPORT_TYPE_HDMI,  ///< See dsAudioPortType_t 
                                0                       ///< Port id.   
                            },
    /*.connectedVOPs = */   connectedVOPs[
                                dsAUDIOPORT_TYPE_HDMI
                            ],                          ///< Connected VOPs for HDMI ports.
    },
    {
    /*.typeId = */          {
                                dsAUDIOPORT_TYPE_SPDIF, ///< See dsAudioPortType_t 
                                0                       ///< Port id. 
                            },
    /*.connectedVOPs = */   connectedVOPs[
                                dsAUDIOPORT_TYPE_SPDIF
                            ],                          ///< Connected VOPs for SPDIF ports.
    },
};

}
#ifdef __cplusplus
}
#endif

#endif

/** @} */
/** @} */
