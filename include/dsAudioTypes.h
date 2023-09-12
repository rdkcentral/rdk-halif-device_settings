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
 * @todo Check to see where is used.
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
    dsMS12FEATURE_DE = 0x1,     ///< Dialogue Enhancement
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

/**
 * @brief List of Audio port state. 
 * @todo check to see where this is used
 * **/
typedef enum _dsAudioPortState {
   dsAUDIOPORT_STATE_UNINITIALIZED, ///< Audio port unintialized.
   dsAUDIOPORT_STATE_INITIALIZED,   ///< Audio port initialized.
   dsAUDIOPORT_STATE_MAX            ///< Out of range 
} dsAudioPortState_t;

/* End of DSHAL_AUDIO_TYPES doxygen group */
/**
 * @}
 */
/** @} */ // End of DSHAL_API HAL Data Types
/** @} */ // End of HPK