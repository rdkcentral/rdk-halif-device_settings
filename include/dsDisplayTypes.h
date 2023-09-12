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
 * @ingroup DSHAL_DISPLAY_TYPES
 * @brief Defines the structure that is used to get the EDID information of the video display.
 *
 */



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
 * @brief This enumeration defines the types of powerstate
 * @todo check to see where this is used. Seems unused.
 */
typedef enum _dsPowerState_t{
    dsPOWER_ON =1,      ///< Host Power-on state   
    dsPOWER_STANDBY,    ///< Host Standby state.   
    dsPOWER_OFF,        ///< Host Power-off state. 
    dsPOWER_MAX,        ///< Out of range 
}dsPowerState_t;

/**
 * @brief This enumeration defines the type of display colorimetry
 * @todo see where this is used. May not be used anywhere.
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

/* End of DSHAL_DISPLAY_TYPES doxygen group */
/**
 * @}
 */
/** @} */ // End of DSHAL_API HAL Data Types
/** @} */ // End of HPK