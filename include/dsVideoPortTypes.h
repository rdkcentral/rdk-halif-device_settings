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
 * @todo Check to see where this is used. Might be unused.
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
 * @brief Structure that defines port id associated with video port.
 */

typedef struct _dsVideoPortPortId_t {
    dsVideoPortType_t type; ///< Video port type.
    int32_t index;          ///< Port ID/number.
} dsVideoPortPortId_t;

/**
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

/**
 * @brief HDCP status validation check.
*/

#define dsHdcpStatus_isValid(t)  (((t) >= dsHDCP_STATUS_UNPOWERED ) && ((t) < dsHDCP_STATUS_MAX))

/**
 * @brief This enumeration defines HDCP protocol version types 
 */
typedef enum _dsHdcpProtocolVersion_t {
    dsHDCP_VERSION_1X = 0,  ///< HDCP Protocol version 1.x 
    dsHDCP_VERSION_2X,      ///< HDCP Protocol version 2.x 
    dsHDCP_VERSION_MAX      ///< Out of range 
} dsHdcpProtocolVersion_t;

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

/* End of DSHAL_VIDEOPORT_TYPES doxygen group.
/**
 * @}
 */
/** @} */ // End of DSHAL_API HAL Data Types
/** @} */ // End of HPK