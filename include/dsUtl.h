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
 * @file
 *
 * @brief Device Settings HAL utilities.
 *
 * This API defines some common utilities for the Device Settings HAL.
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
 * - HAL:     Hardware Abstraction Layer.
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
* @defgroup devicesettings Device Settings HAL
* @{
* @defgroup hal Device Settings HAL
* @{
**/

#ifndef _DS_UTILS_H_
#define _DS_UTILS_H_

#include <stdio.h>

/** @addtogroup DSHAL_UTILS Device Settings HAL Utilities
 *  @ingroup DSHAL_API
 *  @{
 */

/**
 * @brief Device Settings general Assert Failure inline definition.
 */

#define dsUTL_ASSERT(x) do {\
    if (!(x)) printf("ASSERTFAILURE at %s-%d\r\n", __FUNCTION__, __LINE__);\
}\
while(0)

/**
 * @brief Device Settings general Array dimension calculation inline definition.
 */

#define dsUTL_DIM(arr) (sizeof((arr))/sizeof((arr)[0]))

/**
 * @brief Audio output port type validation check.
 * @see dsAudioPortType_t
 */
#define dsAudioType_isValid(t)  (((t) >= dsAUDIOPORT_TYPE_ID_LR ) && ((t) < dsAUDIOPORT_TYPE_MAX))

/**
 * @brief Audio encoding type validation check.
 * @see dsAudioEncoding_t
 */
#define dsAudioEncoding_isValid(t)  (((t) >= dsAUDIO_ENC_NONE ) && ((t) < dsAUDIO_ENC_MAX))

/**
 * @brief Audio compression type validation check.
 * @see dsAudioCompression_t
 */
#define dsAudioCompression_isValid(t)  (((t) >= dsAUDIO_CMP_NONE ) && ((t) < dsAUDIO_CMP_MAX))

/**
 * @brief Audio stereo mode type validation check.
 * @see dsAudioStereoMode_t
 */
#define dsAudioStereoMode_isValid(t)  (((t) >= dsAUDIO_STEREO_UNKNOWN ) && ((t) < dsAUDIO_STEREO_MAX))

/**
 * @brief Video output port type validation check.
 * @see dsVideoPortType_t
 */
#define dsVideoPortType_isValid(t)  (((t) >= dsVIDEOPORT_TYPE_RF ) && ((t) < dsVIDEOPORT_TYPE_MAX))

/**
 * @brief Video output resolutions type validation check.
 * @see dsVideoResolution_t
 */
#define dsVideoPortPixelResolution_isValid(t)  (((t) >= dsVIDEO_PIXELRES_720x480 ) && ((t) < dsVIDEO_PIXELRES_MAX))

/**
 * @brief Video output framerate validation check.
 * @see dsVideoFrameRate_t
 */
#define dsVideoPortFrameRate_isValid(t)  (((t) >= dsVIDEO_FRAMERATE_UNKNOWN ) && ((t) < dsVIDEO_FRAMERATE_MAX))

/**
 * @brief Video scan mode type validation check.
 * @see dsVideoScanMode_t
 */
#define dsVideoPortScanMode_isValid(t)  (((t) >= dsVIDEO_SCANMODE_INTERLACED ) && ((t) < dsVIDEO_SCANMODE_MAX))

/**
 * @brief Video Stereo Scopic modes type validation check.
 * @see dsVideoStereoScopicMode_t
 */
#define dsVideoPortStereoScopicMode_isValid(t)  (((t) >= dsVIDEO_SSMODE_UNKNOWN ) && ((t) < dsVIDEO_SSMODE_MAX))

/**
 * @brief HDCP status validation check.
 * @see dsHdcpStatus_t
*/
#define dsHdcpStatus_isValid(t)  (((t) >= dsHDCP_STATUS_UNPOWERED ) && ((t) < dsHDCP_STATUS_MAX))

/**
 * @brief Video aspect ratio type validation check.
 * @see dsVideoAspectRatio_t
 */
#define dsVideoPortAspectRatio_isValid(t)  (((t)  >= dsVIDEO_ASPECT_RATIO_4x3 ) && ((t) < dsVIDEO_ASPECT_RATIO_MAX))

/**
 * @brief Front panel LED colors validation check.
 * @see dsFPDColor_t
 */
#define dsFPDColor_isValid(t)  (((t) & 0xFF000000) == 0)

/**
 * @brief Front panel LED indicator type validation check.
 * @see dsFPDIndicator_t
 */
#define dsFPDIndicator_isValid(t)  (true)

/**
 * @brief FPD text display type validation check.
 * @see dsFPDTextDisplay_t
 */
#define dsFPDTextDisplay_isValid(t)  (((t)  >= dsFPD_TEXTDISP_TEXT ) && ((t) < dsFPD_TEXTDISP_MAX))

/**
 * @brief Sleep mode validation check.
 * @see dsSleepMode_t
 */

#define dsSleepMode_isValid(t)  (((t)  >= dsHOST_SLEEP_MODE_LIGHT) && ((t) < dsHOST_SLEEP_MODE_MAX))

/**
 * @brief Video screen zoom validation check.
 * @see dsVideoZoom_t
 */
#define dsVideoPortDFC_isValid(t)  (((t) >= dsVIDEO_ZOOM_NONE ) && ((t) < dsVIDEO_ZOOM_MAX))

/* End of DSHAL_UTILS doxygen group */
/**
 * @}
 */

#endif /* _DS_UTILS_H_ */

/** @} */
/** @} */
