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
    bool    isPortArcCapable[dsHDMI_IN_PORT_MAX]; ///< Boolean flag indicating HDMI source is ARC capable 
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


/* End of DSHAL_HDMI_IN_TYPES doxygen group */
/**
 * @}
 */
/** @} */ // End of DSHAL_API HAL Data Types
/** @} */ // End of HPK