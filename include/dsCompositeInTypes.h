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
/** @} */ // End of DSHAL_API HAL Data Types
/** @} */ // End of HPK