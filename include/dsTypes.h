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
 */

/**
 * @defgroup DSHAL_API HAL Data Types
 * @ingroup DSSETTINGS_HAL
 * 
 * @{
 *
 * Main configuration options provided by the device settings modules are:
 *  - Audio output ports (volume, mute, MS12 settings, Audio Delay, Audio Mixing,
 *           Fader Control, Primary Language),
 *  - Video output ports (resolutions, aspect ratio, Active Source, color),
 *  - Video device (zoom settings),
 *  - Display (aspect ratio, EDID data),
 *  - Front-panel indicators,
 *  - General platform (host) configuration,
 *
 * @note Each module in the must have an initialization function and
 * a termination function. Clients of the HAL API are required to call the initialization
 * function first before using any other APIs from the module. If the initialization
 * function is not yet called, all HAL API invocations must return ::dsERR_NOT_INITIALIZED.
 * If an API is not supported on a platform, the implementation must return
 * ::dsERR_OPERATION_NOT_SUPPORTED. Otherwise, the API must return ::dsERR_NONE upon
 * success, or return the most suitable error code. Vendors implementing HAL APIs are
 * allowed to add to the dsError_t enumerations, but should only do so with discretion.
 *
 * @defgroup DSHAL_HOST HAL Host Types
 * @ingroup DSHAL_API
 *
 * DeviceSettings HAL types and public API definitions that are part of the Device
 * Settings Host subsystem.
 *
 * @defgroup DSHAL_AUDIO HAL Audio Types
 * @ingroup DSHAL_API
 *
 *  DeviceSettings HAL types and public API definitions that are part of the Device
 *  Settings Audio subsystem.
 *
 * @defgroup DSHAL_VIDEO HAL Video Sub-Component
 * @ingroup DSHAL_API
 *
 * DeviceSettings HAL types and public API definitions that are part of the Device
 * Settings Video subsystem.  The video subsystem consists of two sub-components, the
 * Video Port subsystem and the Video Device subsystem.
 *
 * @defgroup DSHAL_VIDEOPORT HAL VideoPort Types
 * @ingroup DSHAL_VIDEO
 *
 * DeviceSettings HAL types and public API definitions that are part of the Device
 * Settings Video Port subsystem.
 *
 * @defgroup DSHAL_VIDEODEVICE HAL VideoDevice Types
 * @ingroup DSHAL_VIDEO
 *
 * DeviceSettings HAL types and public API definitions that are part of the Device
 * Settings Video Device subsystem.
 *
 * @defgroup DSHAL_DISPLAY HAL Display Types
 * @ingroup DSHAL_API
 *
 * DeviceSettings HAL types and public API definitions that are part of the Device
 * Settings Display subsystem.
 *
 * @defgroup DSHAL_FPD HAL Front Panel Display Types
 * @ingroup DSHAL_API
 *
 * DeviceSettings HAL types and public API definitions that are part of the Device
 * Settings Front Panel Display (FPD) subsystem.
 * 
 * @defgroup DSHAL_HDMI_IN HAL HDMI input Types
 * @ingroup DSHAL_API
 *
 * DeviceSettings HAL types and public API definitions that are part of the Device
 * Settings HDMI In subsystem.
 *
 * @defgroup DSHAL_VERSION HAL Version Types
 * @ingroup DSHAL_API
 *
 * DeviceSettings HAL types and public API definitions that are part of the Device
 * Settings HDMI In subsystem.
 */

/**
* @defgroup devicesettings Device Settings
* @{
**/

#ifndef _DS_TYPES_H_
#define _DS_TYPES_H_

#include <sys/types.h>
#include <stdint.h>    
#include <stdbool.h>

/** @addtogroup DSHAL_AUDIO HAL Audio Types
 *  @{
 * @todo check if these are used.
 */

#define dsAUDIOPORT_TYPE_NUM_MAX 4     ///< Maximum number of audio output port types.  
#define dsAudioPORT_NUM_MAX 4          ///< Maximum number of audio output ports.       

/**
 * @brief This enumeration defines the audio port types.
 */

typedef enum _dsAudioPortType_t{
    dsAUDIOPORT_TYPE_ID_LR,     ///< RCA audio output.                
    dsAUDIOPORT_TYPE_HDMI,      ///< HDMI audio output.               
    dsAUDIOPORT_TYPE_SPDIF,     ///< SPDIF audio output.             
    dsAUDIOPORT_TYPE_SPEAKER,   ///< SPEAKER audio output.            
    dsAUDIOPORT_TYPE_HDMI_ARC,  ///< HDMI ARC/EARC audio output.      
    dsAUDIOPORT_TYPE_HEADPHONE, ///< 3.5mm headphone jack.            
    dsAUDIOPORT_TYPE_MAX        ///< Out of range 
} dsAudioPortType_t;

/**
 * @brief Audio output port type validation check.
 */

#define dsAudioType_isValid(t)  (((t) >= dsAUDIOPORT_TYPE_ID_LR ) && ((t) < dsAUDIOPORT_TYPE_MAX))

/**
 * @brief This enumeration defines the audio encoding types
 * @todo remove all extraneous extra line spaces
 */
typedef enum _dsAudioEncoding_t{
    dsAUDIO_ENC_NONE = 0,   ///< No digital audio output.                       
    dsAUDIO_ENC_DISPLAY,    ///< Platform-selected digital audio encoding format.
    dsAUDIO_ENC_PCM,        ///< PCM digital audio encoding format.             
    dsAUDIO_ENC_AC3,        ///< AC-3 digital audio encoding format.            
    dsAUDIO_ENC_EAC3,       ///< DD+/E-AC-3 digital audio encoding format.      
    dsAUDIO_ENC_MAX         ///< Out of range         
} dsAudioEncoding_t;

/**
 * @brief Audio encoding type validation check.
 * @todo add @see to the proper enum for all isValid functions
 * @todo move all isValid functions to the dsUtl.h file
 */

#define dsAudioEncoding_isValid(t)  (((t) >= dsAUDIO_ENC_NONE ) && ((t) < dsAUDIO_ENC_MAX))

/**
 * @brief This enumeration defines the type of audio compression.
 */

typedef enum _dsAudioCompression_t{
    dsAUDIO_CMP_NONE,   ///< No audio compression.                    
    dsAUDIO_CMP_LIGHT,  ///< Light audio level compression.           
    dsAUDIO_CMP_MEDIUM, ///< Medium audio level compression.          
    dsAUDIO_CMP_HEAVY,  ///< Heavy audio level compression.           
    dsAUDIO_CMP_MAX     ///< Out of range 
} dsAudioCompression_t;

/**
 * @brief This enumeration defines the type of audio format
 */

typedef enum _dsAudioFormat_t {
    dsAUDIO_FORMAT_NONE,                ///< No audio format.
    dsAUDIO_FORMAT_PCM,                 ///< Pulse-code Modulation audio format.
    dsAUDIO_FORMAT_DOLBY_AC3,           ///< Audio Compression 3 audio format.
    dsAUDIO_FORMAT_DOLBY_EAC3,          ///< Enhance Audio Compression 3 audio format.
    dsAUDIO_FORMAT_DOLBY_AC4,           ///< Audio Compression 4 audio format.
    dsAUDIO_FORMAT_DOLBY_MAT,           ///< Metadata-enhanced Audio Transmission audio format.
    dsAUDIO_FORMAT_DOLBY_TRUEHD,        ///< Dolby TrueHD audio format.
    dsAUDIO_FORMAT_DOLBY_EAC3_ATMOS,    ///< Audio Compression 3 Dolby Atmos audio format.
    dsAUDIO_FORMAT_DOLBY_TRUEHD_ATMOS,  ///< Dolby TrueHD Dolby Atmos audio format.
    dsAUDIO_FORMAT_DOLBY_MAT_ATMOS,     ///< Metadata-enhanced Audio Transmission Dolby Atmos audio format.
    dsAUDIO_FORMAT_DOLBY_AC4_ATMOS,     ///< Audio Compression 4 Dolby Atmos audio format.
    dsAUDIO_FORMAT_AAC,                 ///< Advanced Audio Coding.
    dsAUDIO_FORMAT_VORBIS,              ///< Vorbis sound audio format.
    dsAUDIO_FORMAT_WMA,                 ///< Windows Media audio format.
    dsAUDIO_FORMAT_UNKNOWN,             ///< Unknown audio format.
    dsAUDIO_FORMAT_MAX                  ///< Out of range 
}dsAudioFormat_t;


/**
 * @brief This enumeration defines the type of audio ducking action.
 */
typedef enum _dsAudioDuckingAction_t{
    dsAUDIO_DUCKINGACTION_START,    ///< Audio ducking start.
    dsAUDIO_DUCKINGACTION_STOP,     ///< Audio ducking stop. 
    dsAudio_DUCKINGACTION_MAX,      ///< Out of range 
} dsAudioDuckingAction_t;

/**
 * @brief This enumeration defines the type of audio ducking type.
 */
typedef enum _dsAudioDuckingType_t{
    dsAUDIO_DUCKINGTYPE_ABSOLUTE,   ///< Audio ducking absolute.
    dsAUDIO_DUCKINGTYPE_RELATIVE,   ///< Audio ducking relative.
    dsAudio_DUCKINGTYPE_MAX,        ///< Out of range 
} dsAudioDuckingType_t;

/**
 * @brief This defines the type of audio compression.
 * @todo check for duplicates
 */
typedef int dsAudioCompressionValue_t;

/**
 * @brief This defines the type of dialog enhancer level .
 */
typedef int dsDialogEnhancer_t;

/**
 * @brief This defines the type of dialog enhancer level .
 */
typedef int dsIntelligentEqualizerMode_t;


/**
 * @brief Enumeration defines all of the supported Audio types.
 * Each bit of uint32_t represent a standard. 
 * If a device supports multiple standards, the capability is the bitwise OR
* of the standards.
 */
typedef enum _dsAudioCapabilities_t {
    dsAUDIOSUPPORT_NONE = 0x0,      ///< None.
    dsAUDIOSUPPORT_ATMOS = 0x01,    ///< Dolby Atmos.
    dsAUDIOSUPPORT_DD = 0x02,       ///< Dolby Digitial.
    dsAUDIOSUPPORT_DDPLUS = 0x04,   ///< Dolby Digital Plus.
    dsAUDIOSUPPORT_DAD = 0x08,      ///< Digital Audio Delivery.
    dsAUDIOSUPPORT_DAPv2 = 0x10,    ///< Digital Audio Processing version 2.
    dsAUDIOSUPPORT_MS12 = 0x20,     ///< Multi Stream 12.
    dsAUDIOSUPPORT_MS12V2 = 0x40,   ///< Multi Stream Version 2.
    dsAUDIOSUPPORT_Invalid = 0x80,  ///< Invalid.
    dsAUDTIOSUPPORT_MAX,            ///< Out of range 
} dsAudioCapabilities_t;

/**
 * @brief Enumeration defines all of the supported Arc types.
 * Each bit of uint32_t represent an ARC support type.
 * If a device multiple ARC types support, it's represented as bitwise OR
* of the types.
 */
typedef enum _dsAudioARCTypes_t {
    dsAUDIOARCSUPPORT_NONE = 0x0,   ///< None
    dsAUDIOARCSUPPORT_ARC = 0x01,   ///< Audio Return Channel
    dsAUDIOARCSUPPORT_eARC = 0x02,  ///< Enhanced Audio Return Channel
    dsAUDIOARCSUPPORT_MAX,          ///< Out of range 
} dsAudioARCTypes_t;

/**
 * @brief @todo fill out brief for MAX_SAD
 */
#define MAX_SAD 15  

/**
 * @brief Structure that holds Short Audio Descriptors retrieved from 
 * connected ARC device
 */
typedef struct _dsAudioSADList_t {
    int sad[MAX_SAD];   ///< Array of SADs
    int count;          ///< Amount of items in SAD array.
} dsAudioSADList_t;

/**
 * @brief Structure that holds ARC status for the HDMI ARC/EARC port.
 */
typedef struct _dsAudioARCStatus_t {
   dsAudioARCTypes_t type;  ///< ARC type.
   bool status;             ///< Enabled ARC status for the port.
} dsAudioARCStatus_t;

/**
 * @brief Enumeration defines all of the supported MS12 types.
 * Each bit of uint32_t represent a standard. 
 * If a device supports multiple standards, the capability is the bitwise OR
* of the standards.
 */
typedef enum _dsMS12Capabilities_t {
    dsMS12SUPPORT_NONE = 0x0,                   ///< MS12 Supported None.
    dsMS12SUPPORT_DolbyVolume = 0x01,           ///< MS12 supported Dolby Volume.
    dsMS12SUPPORT_InteligentEqualizer = 0x02,   ///< MS12 supported Intelligent Equalizer
    dsMS12SUPPORT_DialogueEnhancer = 0x04,      ///< MS12 Dialogue Enhancer supported.
    dsMS12SUPPORT_Invalid = 0x80,               ///< Invalid
    dsMS12SUPPORT_MAX,                          ///< Out of range 
} dsMS12Capabilities_t;

/**
 * @brief Structure that captures MS12 Audio Profile list 
 */
#define MAX_PROFILE_LIST_BUFFER_LEN 1024
typedef struct _dsMS12AudioProfileList_t {
    char audioProfileList[MAX_PROFILE_LIST_BUFFER_LEN]; ///< buffer containing the list of comma separated audio profile names 
                                                        ///< (e.g: "Music,Movie,Voice,Night")
    int audioProfileCount;                              ///< Total number of profiles
} dsMS12AudioProfileList_t;

/**
 * @brief This defines the type of volume leveller mode.
 */
typedef struct _dsVolumeLeveller_t {
    int mode;   ///< 0 = off, 1= on, 2= auto
    int level;  ///< Value for the volume leveller. From 0 to 10
} dsVolumeLeveller_t;

/**
 * @brief This defines the type of surround virtualizer mode.
 */
typedef struct _dsSurroundVirtualizer_t {
    int mode;   ///< 0 = off, 1= on, 2= auto
    int boost;  ///< Value for the boost level. From 0 to 96
} dsSurroundVirtualizer_t;

/**
 * @brief Audio compression type validation check.
 */
#define dsAudioCompression_isValid(t)  (((t) >= dsAUDIO_CMP_NONE ) && ((t) < dsAUDIO_CMP_MAX))

/**
 * @brief This enumeration defines the type of audio stereo mode.
 */
typedef enum StereoMode{
    dsAUDIO_STEREO_UNKNOWN,   ///< Stereo mode none
    dsAUDIO_STEREO_MONO = 1,  ///< Mono mode.                            
    dsAUDIO_STEREO_STEREO,    ///< Normal stereo mode (L+R).             
    dsAUDIO_STEREO_SURROUND,  ///< Surround mode.                        
    dsAUDIO_STEREO_PASSTHRU,  ///< Passthrough mode.                     
    dsAUDIO_STEREO_DD,        ///< Dolby Digital.                        
    dsAUDIO_STEREO_DDPLUS,    ///< Dolby Digital Plus.                   
    dsAUDIO_STEREO_MAX        ///< Out of range          
} dsAudioStereoMode_t;

/** 
 * @brief This enumeration defines HDCP protocol version types 
 */

typedef enum _dsATMOSCapability_t{
    dsAUDIO_ATMOS_NOTSUPPORTED= 0,  ///< ATMOS audio not supported.
    dsAUDIO_ATMOS_DDPLUSSTREAM,     ///< can handle dd plus stream which is only way to pass ATMOS metadata.
    dsAUDIO_ATMOS_ATMOSMETADATA,    ///< capable of parsing ATMOS metadata.
    dsAUDIO_ATMOS_MAX,              ///< Out of range 
} dsATMOSCapability_t;

/**
 * @brief Audio stereo mode type validation check.
 */

#define dsAudioStereoMode_isValid(t)  (((t) >= dsAUDIO_STEREO_UNKNOWN ) && ((t) < dsAUDIO_STEREO_MAX))

/**
 * @ingroup DSHAL_AUDIO_TYPES
 * @brief Structure that defines audio output device configuration.
 */

typedef struct _dsAudioTypeConfig_t {
    int32_t  typeId;                            ///< The audio output type.     
    const char *name;                           ///< Name of the audio output device. 
    size_t numSupportedCompressions;            ///< Number of supported audio compression methods.   
    const dsAudioCompression_t *compressions;   ///< List of audio compression methods supported.     
    size_t numSupportedEncodings;               ///< Number of supported audio encodings.             
    const dsAudioEncoding_t *encodings;         ///< List of audio encodings supported.               
    size_t numSupportedStereoModes;             ///< Number of supported stereo modes.                
    const dsAudioStereoMode_t *stereoModes;     ///< List of stereo modes supported.                  
} dsAudioTypeConfig_t;

/**
 * @ingroup DSHAL_AUDIO_TYPES
 * @brief Structure that defines the audio port type and associated ID.
 */

typedef struct _dsAudioPortId_t {
    dsAudioPortType_t type; ///< Audio port type.
    int32_t index;          ///< Port ID/number.
} dsAudioPortId_t;

/**
 * @brief Enumeration defines surround mode.
 * Each bit of uint32_t represent supported surround mode. 
 */

typedef enum _dsSURROUNDMode_t {
    dsSURROUNDMODE_NONE = 0x0,      ///< No surround mode.
    dsSURROUNDMODE_DD = 0x1,        ///< Surround mode Dolby Digital.
    dsSURROUNDMODE_DDPLUS = 0x2,    ///< Surround mode Dolby Digital Plus
    dsSURROUNDMODE_MAX,             ///< Out of range 
} dsSURROUNDMode_t;

/**
 * @brief Enumeration defines MS12 feature.
 */

typedef enum _dsMS12FEATURE_t {
    dsMS12FEATURE_DAPV2 = 0x0,  ///< Dolby Audio Processing Version 2
    dsMS12FEATURE_DE = 0x1,     ///< Dolby Enhanced
    dsMS12FEATURE_MAX = 0x2,    ///< Out of range 
} dsMS12FEATURE_t;

/**
 * @ingroup DSHAL_AUDIO_TYPES
 * @brief Structure that defines audio port configuration.
 */

typedef struct _dsAudioPortConfig_t {
    dsAudioPortId_t id;                         ///< Port ID.             
    const dsVideoPortPortId_t *connectedVOPs;   ///< Connected video port.
} dsAudioPortConfig_t;

#define MAX_LANGUAGE_LEN 10

/* End of DSHAL_AUDIO_TYPES doxygen group */
/**
 * @}
 */

/** @addtogroup DSHAL_VIDEOPORT_TYPES HAL VideoPort Type Definitions
 *  @ingroup DSHAL_VIDEOPORT
 *  @{
 */

/**
 * @brief This enumeration defines all of the standard type of Video ports.
 */

typedef enum _dsVideoPortType_t {
    dsVIDEOPORT_TYPE_RF = 0,      ///< RF modulator (channel 3/4) video output.           
    dsVIDEOPORT_TYPE_BB,          ///< Baseband (composite, RCA) video output.            
    dsVIDEOPORT_TYPE_SVIDEO,      ///< S-Video video output.                              
    dsVIDEOPORT_TYPE_1394,        ///< IEEE 1394 (Firewire) video output.                 
    dsVIDEOPORT_TYPE_DVI,         ///< DVI (Panel-Link, HDCP) video output.               
    dsVIDEOPORT_TYPE_COMPONENT,   ///< Component video output.                            
    dsVIDEOPORT_TYPE_HDMI,        ///< HDMI video output.                                 
    dsVIDEOPORT_TYPE_HDMI_INPUT,  ///< HDMI video input.                                  
    dsVIDEOPORT_TYPE_INTERNAL,    ///< Internal (integrated/internal display) video output.
    dsVIDEOPORT_TYPE_SCART,       ///< SCART video output.                                
    dsVIDEOPORT_TYPE_MAX          ///< Out of range               
} dsVideoPortType_t;

/**
 * @brief Video output port type validation check.
 */

#define dsVideoPortType_isValid(t)  (((t) >= dsVIDEOPORT_TYPE_RF ) && ((t) < dsVIDEOPORT_TYPE_MAX))

/**
 * @brief This enumeration defines all of the standard video port resolutions.
 */

typedef enum _dsVideoResolution_t{
    dsVIDEO_PIXELRES_720x480,     ///< 720x480 Resolution.                       
    dsVIDEO_PIXELRES_720x576,     ///< 720x576 Resolution.                       
    dsVIDEO_PIXELRES_1280x720,    ///< 1280x720 Resolution.                      
    dsVIDEO_PIXELRES_1920x1080,   ///< 1920x1080 Resolution.                     
    dsVIDEO_PIXELRES_3840x2160,   ///< 3840x2160 Resolution.                     
    dsVIDEO_PIXELRES_4096x2160,   ///< 3840x2160 Resolution.                     
    dsVIDEO_PIXELRES_MAX          ///< Out of range 
}dsVideoResolution_t;

/**
 * @brief This enumeration defines all of the standard TV 
 *      supported resolution with interlace information.
 */

typedef enum _dsTVResolution_t{
    dsTV_RESOLUTION_480i = 0x0001,      ///< 480i Resolution.                       
    dsTV_RESOLUTION_480p = 0x0002,      ///< 480p Resolution.                       
    dsTV_RESOLUTION_576i = 0x0004,      ///< 576p Resolution.                       
    dsTV_RESOLUTION_576p = 0x0008,      ///< 576p Resolution.                       
    dsTV_RESOLUTION_720p = 0x0010,      ///< 720p Resolution.                       
    dsTV_RESOLUTION_1080i = 0x0020,     ///< 1080i Resolution.                      
    dsTV_RESOLUTION_1080p = 0x0040,     ///< 1080p Resolution.                      
    dsTV_RESOLUTION_2160p30 = 0x0080,   ///< 2160p30 Resolution.                    
    dsTV_RESOLUTION_2160p60 = 0x0100,   ///< 2160p60 Resolution.                    
    dsTV_RESOLUTION_MAX,                ///< Out of range 
}dsTVResolution_t;

/**
 * @brief Video output resolutions type validation check.
 */

#define dsVideoPortPixelResolution_isValid(t)  (((t) >= dsVIDEO_PIXELRES_720x480 ) && ((t) < dsVIDEO_PIXELRES_MAX))

/**
 * @brief This enumeration defines all of the standard frame rates at which 
 *      video may be played out of the video port.
 */

typedef enum _dsVideoFrameRate_t{
    dsVIDEO_FRAMERATE_UNKNOWN,  ///< Unknown frame rate.                     
    dsVIDEO_FRAMERATE_24,       ///< Played at 24 frames per second.         
    dsVIDEO_FRAMERATE_25,       ///< Played at 25 frames per second.         
    dsVIDEO_FRAMERATE_30,       ///< Played at 30 frames per second.         
    dsVIDEO_FRAMERATE_60,       ///< Played at 60 frames per second.         
    dsVIDEO_FRAMERATE_23dot98,  ///< Played at 23.98 frames per second.      
    dsVIDEO_FRAMERATE_29dot97,  ///< Played at 29.97 frames per second.      
    dsVIDEO_FRAMERATE_50,       ///< Played at 50 frames per second.         
    dsVIDEO_FRAMERATE_59dot94,  ///< Played at 59.94 frames per second.      
    dsVIDEO_FRAMERATE_MAX       ///< Out of range   
}dsVideoFrameRate_t;

/**
 * @brief Video output framerate validation check.
 */

#define dsVideoPortFrameRate_isValid(t)  (((t) >= dsVIDEO_FRAMERATE_UNKNOWN ) && ((t) < dsVIDEO_FRAMERATE_MAX))

/**
 * @brief This enumeration defines all of the standard video port scan modes.
 */

typedef enum _dsVideoScanMode_t{
    dsVIDEO_SCANMODE_INTERLACED,    ///< Interlaced video.                 
    dsVIDEO_SCANMODE_PROGRESSIVE,   ///< Progressive video.                
    dsVIDEO_SCANMODE_MAX            ///< Out of range 
}dsVideoScanMode_t;

/**
 * @brief This enumeration defines background color for video port.
 */

typedef enum _dsVideoBackgroundColor_t{
    dsVIDEO_BGCOLOR_BLUE,   ///< Background color BLUE.
    dsVIDEO_BGCOLOR_BLACK,  ///< Background color BLACK.
    dsVIDEO_BGCOLOR_NONE,   ///< Background color NONE.
    dsVIDEO_BGCOLOR_MAX     ///< Out of range 
}dsVideoBackgroundColor_t;

/**
 * @brief Video scan mode type validation check.
 */

#define dsVideoPortScanMode_isValid(t)  (((t) >= dsVIDEO_SCANMODE_INTERLACED ) && ((t) < dsVIDEO_SCANMODE_MAX))

/**
 * @brief This enumeration defines all of the standard video aspect ratios.
 */

typedef enum _dsVideoAspectRatio_t{
    dsVIDEO_ASPECT_RATIO_4x3,    ///< 4:3 aspect ratio.                    
    dsVIDEO_ASPECT_RATIO_16x9,   ///< 16:9 aspect ratio.                   
    dsVIDEO_ASPECT_RATIO_MAX     ///< Out of range 
}dsVideoAspectRatio_t;

/**
 * @brief Video aspect ratio type validation check.
 */

#define dsVideoPortAspectRatio_isValid(t)  (((t)  >= dsVIDEO_ASPECT_RATIO_4x3 ) && ((t) < dsVIDEO_ASPECT_RATIO_MAX))

/**
 * @brief This enumeration defines all of the standard video Stereo Scopic modes.
 */

typedef enum _dsVideoStereoScopicMode_t {
    dsVIDEO_SSMODE_UNKNOWN = 0,         ///< Unknown mode.                              
    dsVIDEO_SSMODE_2D,                  ///< 2D mode.                                   
    dsVIDEO_SSMODE_3D_SIDE_BY_SIDE,     ///< 3D side by side (L/R) stereo mode.         
    dsVIDEO_SSMODE_3D_TOP_AND_BOTTOM,   ///< 3D top & bottom stereo mode.               
    dsVIDEO_SSMODE_MAX                  ///< Out of range 
}dsVideoStereoScopicMode_t;

/**
 * @brief Video Stereo Scopic modes type validation check.
 */

#define dsVideoPortStereoScopicMode_isValid(t)  (((t) >= dsVIDEO_SSMODE_UNKNOWN ) && ((t) < dsVIDEO_SSMODE_MAX))

/**
 * @brief This enumeration defines all of the standard screen zoom (format conversion) modes.
 */

typedef enum _dsVideoZoom_t {
    dsVIDEO_ZOOM_UNKNOWN = -1,      ///< Unknown mode.                                                                                 
    dsVIDEO_ZOOM_NONE = 0,          ///< Decoder format conversion is inactive.                                                        
    dsVIDEO_ZOOM_FULL,              ///< Full screen (16:9 video is streched to fit 4:3 frame).                                        
    dsVIDEO_ZOOM_LB_16_9,           ///< 16:9 Letterbox (16:9 video is placed in a 4:3 frame with a full letterbox effect).            
    dsVIDEO_ZOOM_LB_14_9,           ///< 14:9 Letterbox (16:9 video is transferred into a 4:3 frame with 14:9
                                    ///< letterbox effect).       
    dsVIDEO_ZOOM_CCO,               ///< Center Cut-out (16:9 video is cut to fill 4:3 frame with its center part).                    
    dsVIDEO_ZOOM_PAN_SCAN,          ///< Pan & Scan (16:9 is cut and panned to fille 4:3 frame, following MPEG pan & scan vectors).    
    dsVIDEO_ZOOM_LB_2_21_1_ON_4_3,  ///< 2.21:1 Letterbox on 4:3 (video is transferred into 4:3 frame with a 2.21:1 letterbox effect). 
    dsVIDEO_ZOOM_LB_2_21_1_ON_16_9, ///< 2.21:1 Letterbox on 16:9 (video is transferred into 16:9 frame with a 2.21:1 letterbox effect).
    dsVIDEO_ZOOM_PLATFORM,          ///< Control over the decoder format conversions is managed by the platform.                       
    dsVIDEO_ZOOM_16_9_ZOOM,         ///< 16:9 Zoom (4:3 video is zoomed to fill 16:9 frame).                                           
    dsVIDEO_ZOOM_PILLARBOX_4_3,     ///< Pillarbox 4:3 (4:3 video is placed in a 16:9 frame with a pillarbox effect)                   
    dsVIDEO_ZOOM_WIDE_4_3,          ///< Wide 4:3 (4:3 video is stretched to fill 16:9 frame).                                         
    dsVIDEO_ZOOM_MAX                ///< Out of range                                                         
}dsVideoZoom_t;

/**
 * @brief Video screen zoom validation check.
 */

#define dsVideoPortDFC_isValid(t)  (((t) >= dsVIDEO_ZOOM_NONE ) && ((t) < dsVIDEO_ZOOM_MAX))

/**
 * @ingroup DSHAL_VIDEOPORT_TYPES
 * @brief Structure that defines video port resolution settings of output video device.
 * @todo Check how the name is used in the actual code
 */

typedef struct _dsVideoPortResolution_t {
    char name[32];                                  ///< Name the resolution. 
    dsVideoResolution_t  pixelResolution;           ///< The resolution associated with the name.               
    dsVideoAspectRatio_t  aspectRatio;              ///< The associated aspect ratio.                           
    dsVideoStereoScopicMode_t  stereoScopicMode;    ///< The associated stereoscopic mode.                      
    dsVideoFrameRate_t  frameRate;                  ///< The associated frame rate.                             
    bool interlaced;                                ///< The associated scan mode(@a true if interlaced, @a false if progressive).
}dsVideoPortResolution_t;

/**
 * @ingroup DSHAL_VIDEOPORT_TYPES
 * @brief Structure that defines port id associated with video port.
 */

typedef struct _dsVideoPortPortId_t {
    dsVideoPortType_t type; ///< Video port type.
    int32_t index;          ///< Port ID/number.
} dsVideoPortPortId_t;

/**
 * @ingroup DSHAL_VIDEOPORT_TYPES
 * @brief Structure that defines the video output port configuration.
 */

typedef struct _dsVideoPortTypeConfig_t {
    dsVideoPortType_t typeId;                       ///< The video output type.             
    const char *name;                               ///< Name of the video output port.     
    bool dtcpSupported;                             ///< Is DTCP supported?                 
    bool hdcpSupported;                             ///< Is HDCP supported?                 
    int32_t restrictedResollution;                  ///< Any restricted resolution; -1 if no.
    size_t numSupportedResolutions;                 ///< Number of supported resolutions.   
    dsVideoPortResolution_t *supportedResolutions;  ///< List of supported resolutions.     
} dsVideoPortTypeConfig_t;

/**
 * @brief Max Key size.
 */
#define HDCP_KEY_MAX_SIZE  (4*1024)


/**
 * @brief Enumeration defines all of the standard HDR types.
 * Each bit of uint32_t represent a standard. 
 * If a device supports multiple standards, the capability is the bitwise OR
 * of the standards.
 */

typedef enum _dsHDRStandard_t {
    dsHDRSTANDARD_NONE = 0x0,               ///< When No video format is decoded
    dsHDRSTANDARD_HDR10 = 0x01,             ///< Video Format HDR
    dsHDRSTANDARD_HLG = 0x02,               ///< Video Format HLG
    dsHDRSTANDARD_DolbyVision = 0x04,       ///< Video Format Dolby Vision
    dsHDRSTANDARD_TechnicolorPrime = 0x08,  ///< Video Format Techinicolor Prime
    dsHDRSTANDARD_Invalid = 0x80,           ///< When invalid value observed
    dsHDRSTANDARD_MAX                       ///< Out of range 
} dsHDRStandard_t;


/**
 * @ingroup DSHAL_VIDEOPORT_TYPES
 * @brief Structure that defines video port configuration settings.
 */

typedef struct _dsVideoPortPortConfig_t {
    dsVideoPortPortId_t id;         ///< Port ID.             
    dsAudioPortId_t connectedAOP;   ///< Connected audio port.
    const char *defaultResolution;  ///< Default resolution's name.
} dsVideoPortPortConfig_t;

/* End of DSHAL_VIDEOPORT_TYPES doxygen group.
/**
 * @}
 */

/** @addtogroup DSHAL_VIDEODEVICE_TYPES HAL VideoDevice Type Definitions
 *  @ingroup DSHAL_VIDEODEVICE
 *  @{
 */

/**
 * @brief Structure that defines video device configuration for the output.
 */

typedef struct _dsVideoConfig_t {
    size_t numSupportedDFCs;            ///< Number of zoom modes supported.
    const dsVideoZoom_t *supportedDFCs; ///< List of zoom modes supported. 
    dsVideoZoom_t defaultDFC;           ///< The default zoom mode.        
} dsVideoConfig_t;

/* End of DSHAL_VIDEODEVICE_TYPES doxygen group.
/**
 * @}
 */

/** @addtogroup DSHAL_FPD_TYPES HAL Front Panel Display (FPD) Type Definitions
 *  @ingroup DSHAL_FPD
 *  @{
 */

/**
 * @brief dsFPDColor_t is an 4-byte integer that is composed of RGB32 value in the
 * following pattern:
 *
 * FPD_COLOR = (((R8)<<16) | ((G8)<< 8) | ((B8) << 0))
 *
 * The Most Significant 8 bit is reserved.
 *
 * Please use the following macros to manipulate FPD_COLOR.
 */

typedef uint32_t dsFPDColor_t;

/**
 * @brief Defines the color values in RGB format.
*/

#define dsFPDColor_Make(R8,G8,B8)  (((R8)<<16) | ((G8)<< 8) | ((B8) )) ///< combine Red Green Blue value to a single Hex value
#define dsFPDColor_R(RGB32)    (((RGB32) >> 16) & 0xFF)                ///< Extract Red value form RGB value
#define dsFPDColor_G(RGB32)    (((RGB32) >>  8) & 0xFF)                ///< Extract Green value form RGB value
#define dsFPDColor_B(RGB32)    (((RGB32)      ) & 0xFF)                ///< Extract Blue value form RGB value

/**
 * @brief Define a set of common colors, for backward compatibility 
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
 */

#define dsFPDColor_isValid(t)  (((t) & 0xFF000000) == 0)

/**
 * @brief dsFPDIndicator_t is an ID number that  uniquely identifies a HAL
 * LED entity on the front panel.  Each MFR implementation is free
 * to assign any number to its LEDs. The mapping of LED ID to its
 * display name (such as "Record LED") is done outside MFR library.
 */

typedef int32_t dsFPDIndicator_t;

/**
 * @brief This enumeration pre-defines common front panel indicators.
 * Implementation may not have to use these enumerators.
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

/** @addtogroup DSHAL_DISPLAY_TYPES HAL Display Type Definitions
 *  @ingroup DSHAL_DISPLAY
 *  @{
 */

/**
 * @brief Maximum Value  video modes are described in CEA specifictaion
 */

#define dsEEDID_MAX_VIDEO_CODE  64  ///< Maximum Value EEDID Video COde .
/**
 * @brief Maximum length for for Connected Display Monitor names.
*/

#define dsEEDID_MAX_MON_NAME_LENGTH 14  ///< Maximum Length of Connected Display Monitor Name .

/**
 * @brief Maximum length for EDID data.
*/

#define MAX_EDID_BYTES_LEN  (1024)  ///< Maximum Byte length of EDID data 

/**
 * @brief HDCP status validation check.
*/

#define dsHdcpStatus_isValid(t)  (((t) >= dsHDCP_STATUS_UNPOWERED ) && ((t) < dsHDCP_STATUS_MAX))


/**
 * @ingroup DSHAL_DISPLAY_TYPES
 * @brief Defines the structure that is used to get the EDID information of the video display.
 *
 */

/**
 * @brief This enumeration defines HDCP protocol version types 
 */

typedef enum _dsHdcpProtocolVersion_t {
    dsHDCP_VERSION_1X = 0,  ///< HDCP Protocol version 1.x 
    dsHDCP_VERSION_2X,      ///< HDCP Protocol version 2.x 
    dsHDCP_VERSION_MAX      ///< Out of range 
} dsHdcpProtocolVersion_t;

/** 
 * @brief This enumeration defines all HDCP Authentication Status 
*/

typedef enum _dsHdcpStatus_t {
    dsHDCP_STATUS_UNPOWERED = 0,            ///< Connected Sink Device does not support HDCP
    dsHDCP_STATUS_UNAUTHENTICATED,          ///< HDCP Authentication Process is not initiated
    dsHDCP_STATUS_AUTHENTICATED,            ///< HDCP Authentication Process is initiated and Passed
    dsHDCP_STATUS_AUTHENTICATIONFAILURE,    ///< HDCP Authentication Failure or Link Integroty Failure
    dsHDCP_STATUS_INPROGRESS,               ///< HDCP Authentication in Progress
    dsHDCP_STATUS_PORTDISABLED,             ///< HDMI output port disabled
    dsHDCP_STATUS_MAX                       ///< Out of range 
} dsHdcpStatus_t;

typedef struct _dsDisplayEDID_t {
    int32_t productCode;               ///< Product code of the display device.      
    int32_t serialNumber;              ///< Serial number of the display device.     
    int32_t manufactureYear;           ///< Year of manufacture of the display device.
    int32_t manufactureWeek;           ///< Week of manufacture of the display device.
    bool hdmiDeviceType;               ///< Device type (@ true if HDMI, @a false if DVI).
    bool  isRepeater;                  ///<  Receiver is a repeater  (@ true if Repeater, @a false if connected Receiver is not a repeater).
    uint8_t physicalAddressA;          ///<  Physical Address for HDMI node A
    uint8_t physicalAddressB;          ///<  Physical Address for HDMI node B
    uint8_t physicalAddressC;          ///<  Physical Address for HDMI node C
    uint8_t physicalAddressD;          ///<  Physical Address for HDMI node D
    int32_t numOfSupportedResolution;  ///<  Number of Supported Resolution
    dsVideoPortResolution_t suppResolutionList [dsEEDID_MAX_VIDEO_CODE * dsVIDEO_SSMODE_MAX];   ///<  EDID Supported Resoultion List
    char monitorName[dsEEDID_MAX_MON_NAME_LENGTH];  ///<  Connected Display Monitor Name
} dsDisplayEDID_t;

/**
 * @brief This enumeration defines the type of sleep modes.
 */

typedef enum _dsSleepMode_t{
    dsHOST_SLEEP_MODE_LIGHT,    ///< Light sleep mode.                              
    dsHOST_SLEEP_MODE_DEEP,     ///< Deep sleep mode.                               
    dsHOST_SLEEP_MODE_MAX,      ///< Out of range                 
} dsSleepMode_t;

/**
 * @brief This enumeration defines the types of powerstate
 */
typedef enum _dsPowerState_t{
    dsPOWER_ON =1,      ///< Host Power-on state   
    dsPOWER_STANDBY,    ///< Host Standby state.   
    dsPOWER_OFF,        ///< Host Power-off state. 
    dsPOWER_MAX,        ///< Out of range 
}dsPowerState_t;

/**
 * @brief This enumeration defines the type of Matrix coefficients.
 */
typedef enum _dsDisplayMatrixCoefficients_t
{
    dsDISPLAY_MATRIXCOEFFICIENT_UNKNOWN = 0,   ///< Unknown Matrix Coefficient.
    dsDISPLAY_MATRIXCOEFFICIENT_BT_709,        ///< ITU BT 709 Matrix Coefficient.
    dsDISPLAY_MATRIXCOEFFICIENT_BT_470_2_BG,   ///< ITU BT 470_2_BG Matrix Coefficient.
    dsDISPLAY_MATRIXCOEFFICIENT_SMPTE_170M ,   ///< SMPTE 170M Matrix Coefficient.
    dsDISPLAY_MATRIXCOEFFICIENT_XvYCC_709,     ///< XvYCC_709 Matrix Coefficient.
    dsDISPLAY_MATRIXCOEFFICIENT_eXvYCC_601,    ///< XvYCC_601 Matrix Coefficient.
    dsDISPLAY_MATRIXCOEFFICIENT_BT_2020_NCL,   ///< ITU BT 2020 non constant luminance Matrix Coefficient.
    dsDISPLAY_MATRIXCOEFFICIENT_BT_2020_CL,    ///< ITU BT 2020 constant luminance Matrix Coefficient.
    dsDISPLAY_MATRIXCOEFFICIENT_eDVI_FR_RGB,   ///< eDVI Full Range RGB Matrix Coefficient.
    dsDISPLAY_MATRIXCOEFFICIENT_eHDMI_RGB,     ///< eHDMI RGB Matrix Coefficient.
    dsDISPLAY_MATRIXCOEFFICIENT_eFCC,          ///< eFCC Matrix Coefficient.
    dsDISPLAY_MATRIXCOEFFICIENT_eSMPTE_240M,   ///< eSMPTE 240M Matrix Coefficient.
    dsDISPLAY_MATRIXCOEFFICIENT_eHDMI_FR_YCbCr ///< eHDMI Full Range YcbCr Matrix Coefficient.
    dsDISPLAY_MATRIXCOEFFICIENT_MAX            ///< Out of range 
} dsDisplayMatrixCoefficients_t;
/**
 * @brief This enumeration defines the type of display colorimetry
 */

typedef enum _dsDisplayColorimetryInfo_t
{
    dsDISPLAY_COLORIMETRY_INFO_UNKNOWN = 0,        ///< Unknown Colorimetry
    dsDISPLAY_COLORIMETRY_INFO_XVYCC601 = 0x01,    ///< Standard Definition Colorimetry based on IEC 61966-2-4
    dsDISPLAY_COLORIMETRY_INFO_XVYCC709 = 0x02,    ///< High Definition Colorimetry based on IEC 61966-2-4
    dsDISPLAY_COLORIMETRY_INFO_SYCC601 = 0x04,     ///< Colorimetry based on IEC 61966-2-1/Amendment 1
    dsDISPLAY_COLORIMETRY_INFO_ADOBEYCC601 = 0x08, ///< Colorimetry based on IEC 61966-2-5 [32], Annex A
    dsDISPLAY_COLORIMETRY_INFO_ADOBERGB = 0x10,    ///< Colorimetry based on IEC 61966-2-5
    dsDISPLAY_COLORIMETRY_INFO_BT2020CL = 0x20,    ///< Colorimetry based on ITU-R BT.2020 [39] Y’cC’BCC’RC
    dsDISPLAY_COLORIMETRY_INFO_BT2020NCL = 0x40,   ///< Colorimetry based on ITU-R BT.2020 [39] Y’C’BC’R
    dsDISPLAY_COLORIMETRY_INFO_BT2020RGB = 0x80,   ///< Colorimetry based on ITU-R BT.2020 [39] R’G’B’
    dsDISPLAY_COLORIMETRY_INFO_DCI_P3 = 0x100,     ///< Colorimetry based on DCI-P3 */
    dsDisplay_COLORIMETRY_INFO_MAX                 ///< Out of range 
} dsDisplayColorimetryInfo_t;
/**
 * @brief This enumeration defines the type of display color spaces supported
 */

typedef enum _dsDisplayColorSpace_t
{
    dsDISPLAY_COLORSPACE_UNKNOWN = 0,   ///< Unknown color space
    dsDISPLAY_COLORSPACE_RGB = 1,       ///< RGB color space
    dsDISPLAY_COLORSPACE_YCbCr422 = 2,  ///< YCbCr4.2.2 color space
    dsDISPLAY_COLORSPACE_YCbCr444 = 3,  ///< YCbCr4.4.4 color space
    dsDISPLAY_COLORSPACE_YCbCr420 = 4,  ///< YCbCr4.2.0 color space
    dsDISPLAY_COLORSPACE_AUTO = 5,      ///< Automatic color space
    dsDISPLAY_COLORSPACE_MAX            ///< Out of range 
} dsDisplayColorSpace_t;
/**
 * @brief This enumeration defines the type of display quantization ranges
 */

typedef enum _dsDisplayQuantizationRange_t
{
    dsDISPLAY_QUANTIZATIONRANGE_UNKNOWN = 0,    ///< Unknown quantization range
    dsDISPLAY_QUANTIZATIONRANGE_LIMITED = 1,    ///< Limited quantization range
    dsDISPLAY_QUANTIZATIONRANGE_FULL = 2,       ///< Full quantization range
    dsDISPLAY_QUANTIZATIONRANGE_MAX             ///< Out of range 
} dsDisplayQuantizationRange_t;
/**
 * @brief This enumeration defines the type of display Color depth.
 */

typedef enum _dsDisplayColorDepth_t
{
    dsDISPLAY_COLORDEPTH_UNKNOWN = 0x0, ///< Unknown color depth
    dsDISPLAY_COLORDEPTH_8BIT = 0x01,   ///< 8 bit color depth
    dsDISPLAY_COLORDEPTH_10BIT = 0x02,  ///< 10 bit color depth
    dsDISPLAY_COLORDEPTH_12BIT = 0x04,  ///< 12 bit color depth
    dsDISPLAY_COLORDEPTH_AUTO = 0x08,   ///< Automatic color depth
    dsDISPLAY_COLORDEPTH_MAX            ///< Out of range 
} dsDisplayColorDepth_t;

/**
 * @brief Sleep mode validation check.
 */

#define dsSleepMode_isValid(t)  (((t)  >= dsHOST_SLEEP_MODE_LIGHT) && ((t) < dsHOST_SLEEP_MODE_MAX))

/* End of DSHAL_DISPLAY_TYPES doxygen group */
/**
 * @}
 */

 /** @addtogroup DSHAL_HDMI_IN_TYPES HAL HDMI IN Type Definitions
 *  @ingroup DSHAL_HDMI_IN
 *  @{
 */
/**
 * @brief This enumeration defines the type of HDMI ports.
 */

typedef enum _dsHdmiInPort_t
{
    dsHDMI_IN_PORT_NONE = -1,  ///< HDMI input port index for NONE
    dsHDMI_IN_PORT_0,          ///< HDMI input port index for PORT 0
    dsHDMI_IN_PORT_1,          ///< HDMI input port index for PORT 1
    dsHDMI_IN_PORT_2,          ///< HDMI input port index for PORT 2
    dsHDMI_IN_PORT_MAX         ///< Out of range 
} dsHdmiInPort_t;

/**
 * @brief This enumeration defines the type of HDMI siganl status.
 * @todo update the description on the signal status
 */
typedef enum _dsHdmiInSignalStatus_t
{
    dsHDMI_IN_SIGNAL_STATUS_NONE = -1,    ///< HDMI input signal status NONE
    dsHDMI_IN_SIGNAL_STATUS_NOSIGNAL,     ///< HDMI input No signal signal status
    dsHDMI_IN_SIGNAL_STATUS_UNSTABLE,     ///< HDMI input Unstable signal status
    dsHDMI_IN_SIGNAL_STATUS_NOTSUPPORTED, ///< HDMI input Not supported signal status
    dsHDMI_IN_SIGNAL_STATUS_STABLE,       ///< HDMI input Stable signal status are presented on plane
    dsHDMI_IN_SIGNAL_STATUS_MAX           ///< Out of range 
} dsHdmiInSignalStatus_t;

/**
 * @brief Structure type for HDMI input status.
 * 
 */
typedef struct _dsHdmiInStatus_t
{
    bool             isPresented;                           ///< Boolean flag indicating HDMI input is presenting for the activePort
    bool             isPortConnected[dsHDMI_IN_PORT_MAX];   ///< Boolean flag indicating HDMI source connected to this HDMI input port 
    dsHdmiInPort_t   activePort;                            ///< HDMI input Port selected as the currently active port (to the set-top)
                                                            ///<   - note that only one HDMI input port can be active at a time 
} dsHdmiInStatus_t;
/**
 * @brief Structure type for HDMI input ARC Capability.
 */
typedef struct _dsHdmiInCap_t
{
    bool             isPortArcCapable[dsHDMI_IN_PORT_MAX]; ///< Boolean flag indicating HDMI source is ARC capable 
} dsHdmiInCap_t;

/**
 * @brief This enumeration defines the AVI Content Types
 */
typedef enum dsAviContentType {
  dsAVICONTENT_TYPE_GRAPHICS,   ///< Content type Graphics.
  dsAVICONTENT_TYPE_PHOTO,      ///< Content type Photo
  dsAVICONTENT_TYPE_CINEMA,     ///< Content type Cinema
  dsAVICONTENT_TYPE_GAME,       ///< Content type Game
  dsAVICONTENT_TYPE_INVALID,    ///< Content type Invalid
  dsAVICONTENT_TYPE_MAX,        ///< Out of range
}dsAviContentType_t;

/* End of DSHAL_HDMI_IN_TYPES doxygen group */
/**
 * @}
 */

/** @addtogroup DSHAL_COMPOSITE_IN_STATUS HAL Composite IN Signal Status Definitions
 *  @ingroup DSHAL_COMPOSITE_IN
 *  @{
 */
/**
 * @brief This enumeration defines the type composite signal status.
 */

typedef enum _dsCompInSignalStatus_t
{
    dsCOMP_IN_SIGNAL_STATUS_NONE = -1,    ///< Composite input signal status NONE
    dsCOMP_IN_SIGNAL_STATUS_NOSIGNAL,     ///< Composite input No Signal status
    dsCOMP_IN_SIGNAL_STATUS_UNSTABLE,     ///< Composite input Unstable signal status
    dsCOMP_IN_SIGNAL_STATUS_NOTSUPPORTED, ///< Composite input Not supported signal status
    dsCOMP_IN_SIGNAL_STATUS_STABLE,       ///< Composite input Stable signal status
    dsCOMP_IN_SIGNAL_STATUS_MAX           ///< Out of range 
} dsCompInSignalStatus_t;

/**
 * @brief This enumeration defines the type of composite ports.
 */

typedef enum _dsCompositeInPort_t
{
    dsCOMPOSITE_IN_PORT_NONE = -1,  ///< No composite port.
    dsCOMPOSITE_IN_PORT_0,          ///< Composite port index 0.
    dsCOMPOSITE_IN_PORT_1,          ///< Composite port index 1.
    dsCOMPOSITE_IN_PORT_MAX         ///< Out of range 
} dsCompositeInPort_t;
/**
 * @brief Structure type for Composite input status.
 */
typedef struct _dsCompositeInStatus_t
{
    bool    isPresented;                               ///< Boolean flag indicating Composite input is enabled for presentation by client
    bool    isPortConnected[dsCOMPOSITE_IN_PORT_MAX];  ///< Boolean flag indicating Composite source connected to this Composite input port
    dsCompositeInPort_t   activePort;                  ///< Composite input Port selected as the currently active port (to the set-top)
                                                       ///<     - note that only one COMPOSITE input port can be active at a time
} dsCompositeInStatus_t;

/* End of DSHAL_COMPOSITE_IN doxygen group */
/**
 * @}
 */

/**
 * @brief List of video compression formats that may be supported by the decoder. 
 * **/

typedef enum
{
    dsVIDEO_CODEC_MPEGHPART2 = (0x01 << 0),     ///< Also known HEVC, H.265
    dsVIDEO_CODEC_MPEG4PART10 = (0x01 << 1),    ///< Also known as H.264, MPEG4 AVC
    dsVIDEO_CODEC_MPEG2 = (0x01 << 2),          ///< Also known as H.222/H.262
    dsVIDEO_CODEC_MAX                           ///< Out of range 
} dsVideoCodingFormat_t;

/* HEVC version 1 profiles are listed. More may be added to it as the support becomes available.*/
/**
 * @brief List of HEVC Profiles. 
 * **/

typedef enum
{
    dsVIDEO_CODEC_HEVC_PROFILE_MAIN = (0x01 << 0),              ///< 8-bit HEVC video profile.
    dsVIDEO_CODEC_HEVC_PROFILE_MAIN10 = (0x01 << 1),            ///< 10-bit HEVC video profile.
    dsVIDEO_CODEC_HEVC_PROFILE_MAINSTILLPICTURE = (0x01 << 2),  ///< HECV Main Still Picture profile.
    dsVIDEO_CODEC_HEVC_MAX                                      ///< Out of range 
} dsVideoCodecHevcProfiles_t;
/**
 * @brief Structure type for HEVC profiles.
 */
typedef struct
{
   dsVideoCodecHevcProfiles_t profile;  ///< HEVC Profiles. See dsVideoCodecHevcProfiles_t
   float level;                         ///< level for the specieis HEVC profile.
} dsVideoCodecProfileSupport_t;
/**
 * @brief Structure type for Video codec info.
 */
typedef struct
{
    unsigned int num_entries;                  ///< Number of entries
    dsVideoCodecProfileSupport_t entries[10];  ///< Contains a list of the supported Codex profiles.
} dsVideoCodecInfo_t;
/**
 * @brief Structure type for spd info frame.
 */
struct dsSpd_infoframe_st {
    uint8_t pkttype;            ///< Package type
    uint8_t version;            ///< Version
    uint8_t length;             ///< length=25
    uint8_t rsd;                ///< Repetition of statis data
    uint8_t checksum;           ///< Checksum for spd info frame
    uint8_t vendor_name[8];     ///< Vendor Name Character
    uint8_t product_des[16];    ///< Product Description Character
    uint8_t source_info;        ///< byte 25
} ;

/**
 * @brief List of HDMI EDID versions. 
 * **/
typedef enum tv_hdmi_edid_version_e {
    HDMI_EDID_VER_14 = 0,   ///< EDID version 1.4
    HDMI_EDID_VER_20,       ///< EDID version 2.0
    HDMI_EDID_VER_MAX,      ///< Out of range 
} tv_hdmi_edid_version_t;

/**
 * @brief Structure that captures Supported Game Features list
 * @todo list all possible values
 */

#define MAX_FEATURE_LIST_BUFFER_LEN 1024

typedef struct _dsSupportedGameFeatureList_t {
    char gameFeatureList[MAX_FEATURE_LIST_BUFFER_LEN]; ///< buffer containing the list of comma separated supported game features (e.g: "allm")
    int gameFeatureCount;                              ///< Total number of supported game features
} dsSupportedGameFeatureList_t;

/**
 * @brief List of Audio port state. 
 * **/
typedef enum _dsAudioPortState {
   dsAUDIOPORT_STATE_UNINITIALIZED, ///< Audio port unintialized.
   dsAUDIOPORT_STATE_INITIALIZED,   ///< Audio port initialized.
   dsAUDIOPORT_STATE_MAX            ///< Out of range 
} dsAudioPortState_t;

  /** @addtogroup DSHAL_VERSION_TYPES HAL VERSION Definitions
 *  @ingroup DSHAL_VERSION
 *  @{
 */

/**
 * @brief HAL version number.
*/

#define dsHAL_APIVER(major, minor) (uint32_t)((major << 16) | (minor & 0xFFFF)) 
    ///< Return 4 Bytes version value

/**
 * @brief HAL Major version number.
*/

#define dsHAL_APIVER_MAJOR(x)   ((x) >> 16) & (0x7FFF) 
    ///< Return the two Most Significant Byte value

/**
 * @brief HAL Minor version number.
*/

#define dsHAL_APIVER_MINOR(x)   (x & 0xFFFF) ///< Return the two Least Significant Byte value

/* End of DSHAL_VERSION_TYPES  doxygen group */
/**
 * @}
 */
#endif

/** @} */ // End of DeviceSettings_Module
/** @} */ // End of DSHAL_API HAL Data Types
/** @} */ // End of HPK