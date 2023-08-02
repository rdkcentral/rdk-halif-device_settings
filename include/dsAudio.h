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
 * @par Application API Specification
 * Described herein are the DeviceSettings HAL types and functions that are part of
 * the Host subsystem. The Host subsystem manages system-specific HAL operations.
 *  @{
 */

/** @defgroup DSHAL_AUDIO_API Device Settings HAL Audio Public API
 *
 *  Described herein are the DeviceSettings HAL types and functions that are part of the
 *  Audio subsystem. The Audio subsystem manages audio HAL operations.
 *
 *  @{
 */


 
/**
 * @file dsAudio.h
 * 
 * @brief Device Settings HAL error codes.
 *
 * This API defines common error codes used by the Device Settings HAL.
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
 * - cb:      Callback function (suffix).
 * - DS:      Device Settings.
 * - HAL:     Hardware Abstraction Layer.
 * - ARC:     Audio Return Channel.
 * - eARC:    Enhance Audio Return Channel
 * - HDMI:    High-Definition Multimedia Interface.
 * - LE:      Loudness Equivalence.
 * - DRC:     Dynamic Range Control.
 * - RF:      Radio Frequency.
 * - dB:      Decibel.
 * - MS12:    MultiStream 12.
 * - AC4:     Audio Compression 4.
 * - ms:      milliseconds.
 * 
 *
 * @par Implementation Notes
 * -# None
 *
 */

#ifndef _DS_AUDIOOUTPORT_H_
#define _DS_AUDIOOUTPORT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>
#include "dsError.h"
#include "dsTypes.h"

/**
 * @brief HAL must call this function when audio port connection status changes
 *
 * HAL Implementation must call this method to deliver updated Audio port connection event
 * to the caller
 * 
 * @param[in] portType  - Type of the audio port where connection status is changed.
 *                          See dsAudioPortType_t
 * @param[in] uiPortNo  - Port number in which the connection status changed. 
 *                          The max value is platform specific. Min value of 0.
 * @param[in] isPortCon - Current connection status of the port. 
 *                          True if the port is connected, false if it is not.
 */

typedef void (*dsAudioOutPortConnectCB_t)(dsAudioPortType_t portType, unsigned int uiPortNo, bool isPortCon);

/**
 * @brief HAL must call this function when the audio format changes.
 *
 * HAL Implementation must call this method to deliver updated Audio Format event
 * to the caller
 * @param[in] audioFormat   - New audio format. See dsAudioFormat_t
 */

typedef void (*dsAudioFormatUpdateCB_t)(dsAudioFormat_t audioFormat);

/**
 * @brief Initializes the Audio Port Hal.
 *
 * @return dsStatus_t                   - Status
 * @retval dsERR_NONE                   - Success
 * @retval dsERR_ALREADY_INITIALIZED    - Function is already initialized.
 * @retval dsERR_GENERAL                - Underlying undefined platform error
 * 
 * @warning  This API is Not thread safe.
 * 
 * 
 */

dsStatus_t  dsAudioPortInit();

/**
 * @brief This function is used to get the audio port handle.
 * 
 * This function must return ::dsERR_OPERATION_NOT_SUPPORTED if an unavailable port is requested.
 *
 * @param[in] type      - Indicates the type of audio port. See dsAudioPortType_t
 * @param[in] index     - Index of audio port. Max value is platform specific. Min value is 0.
 * @param[out] handle   - The handle used by the caller to uniquely identify the HAL instance
 * 
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsStatus_t  dsGetAudioPort(dsAudioPortType_t type, int index, int *handle);

/**
 * @brief This function is used to get the encoding type of of the specified audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function
 * @param[out] encoding - Encoding setting of the audio port. See dsAudioEncoding_t
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetAudioEncoding()
 * 
 */

dsStatus_t  dsGetAudioEncoding(int handle, dsAudioEncoding_t *encoding);

/**
 * @brief This function is used to get the current audio format of the specified audio port.
 *
 * @param[in] handle        - The handle returned from the dsGetAudioPort() function
 * @param[out] audioFormat  - Audio format of the specified audio port. See dsAudioFormat_t
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsStatus_t  dsGetAudioFormat(int handle, dsAudioFormat_t *audioFormat);

/**
 * @brief This function is used to get the audio compression of of the specified audio port.
 *
 * @param[in] handle        - The handle returned from the dsGetAudioPort() function
 * @param[out] compression  - Compression value of the specified audio port. Range from 0 to 10
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetAudioCompression()
 * 
 */

dsStatus_t  dsGetAudioCompression(int handle, int *compression);

/**
 * @brief This function is used to get the Dialog Enhancement level of the specified audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function
 * @param[out] level    - Dialog Enhancement level of the specified audio port. Range from 0 to 16
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetDialogEnhancement()
 * 
 */

dsStatus_t  dsGetDialogEnhancement(int handle, int *level);

/**
 * @brief This function is used to get the dolby audio mode status of the specified audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function
 * @param[out] mode     - Dolby volume mode of the specified audio port. 
 *                              True if enabled, and false if disabled.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetDolbyVolumeMode()
 * 
 */

dsStatus_t  dsGetDolbyVolumeMode(int handle, bool *mode);

/**
 * @brief This function is used to get the Intelligent Equalizer Mode of the specified audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function
 * @param[out] mode     - Intelligent Equalizer mode of the specified audio port: 
 *                                  0 = Off, 1 = Open, 2 = Rich, 3 = focused,
 *                                  4 = balanced, 5 = warm, 6 = detailed
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetIntelligentEqualizerMode()
 * 
 */

dsStatus_t  dsGetIntelligentEqualizerMode(int handle, int *mode);

/**
 * @brief This function is used to get the Dolby volume leveller 
 *              settings of the specified audio port.
 *
 * @param[in] handle        - The handle returned from the dsGetAudioPort() function
 * @param[out] volLeveller  - Volume Leveller setting of the specified audio port. 
 *                                  See dsVolumeLeveller_t
 * 
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetVolumeLeveller()
 * 
 */

dsStatus_t  dsGetVolumeLeveller(int handle, dsVolumeLeveller_t* volLeveller);

/**
 * @brief This function is used to get the audio Bass of the specified audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function
 * @param[out] boost    - Bass Enhancer boost value of the specified audio port from 0 to 100
 * 
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetBassEnhancer()
 * 
 */

dsStatus_t  dsGetBassEnhancer(int handle, int *boost);

/**
 * @brief This function is used to get the enable/disable status of 
 *                      surround decoder of the specified audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function
 * @param[out] enabled  - Surround Decoder of the specified audio port, 
 *                              true if enabled, false if disabled
 * 
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsEnableSurroundDecoder()
 * 
 */

dsStatus_t  dsIsSurroundDecoderEnabled(int handle, bool *enabled);

/**
 * @brief This function is used to get the DRC Mode of the specified audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function
 * @param[out] mode     - mode of the DRC type of the specified audio port.
 *                          0 for DRC line mode and 1 for DRC RF mode
 * 
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetDRCMode()
 * 
 */

dsStatus_t  dsGetDRCMode(int handle, int *mode);

/**
 * @brief This function is used to get the audio Surround Virtualizer level 
 *              of the specified audio port.
 *
 * @param[in] handle        - The handle returned from the dsGetAudioPort() function
 * @param[out] virtualizer  - Surround virtualizer setting of the specified audio port. 
 *                                  See dsSurroundVirtualizer_t
 * 
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetSurroundVirtualizer()
 * 
 */

dsStatus_t  dsGetSurroundVirtualizer(int handle, dsSurroundVirtualizer_t *virtualizer);

/**
 * @brief This function is used to get the audio Media intelligent Steering status of 
 *              the specified audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function
 * @param[out] enabled  - MI Steering of the specified audio port, 
 *                              true if enabled, false is enabled
 * 
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetMISteering()
 * 
 */

dsStatus_t  dsGetMISteering(int handle, bool *enabled);

/**
 * @brief This function is used to get the Graphic Equalizer Mode of the specified audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function
 * @param[out] mode     - Graphic Equalizer Mode of the specified audio port. 
 *                              0 for EQ OFF, 1 for EQ Open, 2 for EQ Rich and 3 for EQ Focused
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetGraphicEqualizerMode()
 * 
 */

dsStatus_t  dsGetGraphicEqualizerMode(int handle, int *mode);

/**
 * @brief This function is used to get the supported MS12 
 *              audio profiles of the specified audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function
 * @param[out] profiles - List of supported audio profiles of the specified audio port. 
 *                                  See dsMS12AudioProfileList_t
 * 
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetMS12AudioProfile()
 * 
 */

dsStatus_t  dsGetMS12AudioProfileList(int handle, dsMS12AudioProfileList_t* profiles);

/**
 * @brief This function is used to get current audio profile selection of the specified audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function
 * @param[out] profile  - The current audio profile of the specified audio port. 
 *                                  See dsGetMS12AudioProfileList()'s return for valid profiles.
 * 
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetMS12AudioProfile()
 * 
 */

dsStatus_t  dsGetMS12AudioProfile(int handle, char *profile);

/**
 * @brief This function is used to get the supported ARC types of the connected ARC/eARC device
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function
 * @param[out] types    - Value of supported ARC types of the specified audio port. 
 *                              See dsAudioARCTypes_t
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsStatus_t dsGetSupportedARCTypes(int handle, int *types);

/**
 * @brief This function is used to set Short Audio Descriptor retrieved 
 *          from CEC for the connected ARC device
 *
 * This function sets the Short Audio Descriptor based on best available options
 * of Audio capabilities supported by connected ARC device. Required when ARC output
 * mode is Auto
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function
 * @param[in] sad_list  - All SADs retrieved from CEC for the connected ARC device. 
 *                              See dsAudioSADList_t
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsStatus_t dsAudioSetSAD(int handle, dsAudioSADList_t sad_list);

/**
 * @brief This function is used to enable/disable ARC/EARC and route audio to connected device
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function
 * @param[in] arcStatus - To enable/disable ARC/eARC feature. See dsAudioARCStatus_t
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsStatus_t dsAudioEnableARC(int handle, dsAudioARCStatus_t arcStatus);

/**
 * @brief This function is used to get the stereo mode of the specified audio port.
 *
 * @param[in] handle        - The handle returned from the dsGetAudioPort() function
 * @param[out] stereoMode   - Stereo mode setting of the specified audio port. 
 *                                  See dsAudioStereoMode_t
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetStereoMode()
 * 
 */

dsStatus_t  dsGetStereoMode(int handle, dsAudioStereoMode_t *stereoMode);

/**
 * @brief This function is used to get the current auto mode setting of the specified
 * audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function
 * @param[out] autoMode - Auto mode setting of the specified audio port.
 *                              0 for Disabled, 1 for Enabled
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetStereoAuto()
 * 
 */

dsStatus_t  dsGetStereoAuto(int handle, int *autoMode);

/**
 * @brief This function is used to get the audio gain of the specified audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function
 * @param[out] gain     - Gain value from -2080 to 480 of the specified audio port. 
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetAudioGain()
 * 
 */

dsStatus_t  dsGetAudioGain(int handle, float *gain);

/**
 * @brief This function is used to get the current audio dB level of the specified audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function
 * @param[out] db       - dB value of the specified audio port.
 *                           Platform specific, must be between the bounds of min and max dB.
 *                           See dsGetAudioMinDB() and dsGetAudioMaxDB() for bounds.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetAudioDB()
 * 
 */

dsStatus_t  dsGetAudioDB(int handle, float *db);

/**
 * @brief This function is used to get the current audio volume level of the specified audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function
 * @param[out] level    - Audio level value from 0 to 100 of the specified audio port.
 *                      
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetAudioLevel()
 * 
 */

dsStatus_t  dsGetAudioLevel(int handle, float *level);

/**
 * @brief This function is used to get the maximum audio dB level of the specified audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function
 * @param[out] maxDb    - Max audio dB value supported by the specified audio port as float value.
 *                              Platform Specific.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsStatus_t  dsGetAudioMaxDB(int handle, float *maxDb);

/**
 * @brief This function is used to get the minimum audio dB level of the specified audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function
 * @param[out] minDb    - Minimum audio dB value supported by the specified audio port in float. 
 *                              Platform specific.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsStatus_t  dsGetAudioMinDB(int handle, float *minDb);

/**
 * @brief This function is used to get the optimal audio level of the specified audio port.
 *
 * @param[in] handle        - The handle returned from the dsGetAudioPort() function
 * @param[out] optimalLevel - Optimal level value of the specified audio port. 
 *                              Platform specific, must be between the bounds of min and max dB.
 *                              See dsGetAudioMinDB() and dsGetAudioMaxDB() for bounds.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsStatus_t  dsGetAudioOptimalLevel(int handle, float *optimalLevel);

/**
 * @brief This function is used to get the audio delay in ms
 *
 * @param[in] handle        - The handle returned from the dsGetAudioPort() function
 * @param[out] audioDelayMs - Audio delay in ms of the specified audio port.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetAudioDelay()
 * 
 */

dsStatus_t dsGetAudioDelay(int handle, uint32_t *audioDelayMs);

/**
 * @brief This function is used to get the audio delay offset in ms
 *
 * @param[in] handle                - The handle returned from the dsGetAudioPort() function
 * @param[out] audioDelayOffsetMs   - Audio delay offset in ms of the specified audio port.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetAudioDelayOffset()
 * 
 */

dsStatus_t dsGetAudioDelayOffset(int handle, uint32_t *audioDelayOffsetMs);

/**
 * @brief This function is used to set the audio ATMOS outout mode
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function
 * @param[in] enable    - Set audio ATMOS output mode of the specified audio port, 
 *                              true if enabled, false if disabled.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsStatus_t dsSetAudioAtmosOutputMode(int handle, bool enable);
  
/**
 * @brief This function is used to get the sink device ATMOS capability
 *
 * @param[in] handle        - The handle returned from the dsGetAudioPort() function
 * @param[out] capability   - Sink device ATMOS capability of the specified audio port, 
 *                                  see dsATMOSCapability_t.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsStatus_t dsGetSinkDeviceAtmosCapability(int handle, dsATMOSCapability_t *capability);

/**
 * @brief This function is used to get the loop-through mode of the specified audio port.
 *
 * @param[in] handle        - The handle returned from the dsGetAudioPort() function
 * @param[out] loopThru     - Loop-through setting of the specified audio. 
 *                                  True if enabled, false if disabled.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsStatus_t  dsIsAudioLoopThru(int handle, bool *loopThru);

/**
 * @brief This function is used to get the audio mute status of the specified audio port.
 *
 * @param[in] handle        - The handle returned from the dsGetAudioPort() function
 * @param[out] muted        - Mute setting of the specified audio port. 
 *                                  True if enabled, false if disabled.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetAudioMute()
 * 
 */

dsStatus_t  dsIsAudioMute(int handle, bool *muted);

/**
 * @brief This function indicates whether the specified Audio port is enabled or not.
 *
 * @param[in] handle        - The handle returned from the dsGetAudioPort() function.
 * @param[out] enabled      - Audio port enable state of the specified audio port. 
 *                                  True if enabled, false if disabled.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsEnableAudioPort()
 * 
 */

dsStatus_t  dsIsAudioPortEnabled(int handle, bool *enabled);

/**
 * @brief This function is used to enable or disable the specified Audio port.
 *
 * @param[in] handle        - The handle returned from the dsGetAudioPort() function.
 * @param[in] enabled       - Set the enabled status of the specified audio port. 
 *                                  True if enabled, false if disabled.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsIsAudioPortEnabled()
 * 
 */

dsStatus_t  dsEnableAudioPort(int handle, bool enabled);

/**
 * @brief This function is used to enable or disable MS12, Digital Audio Player V2, 
 *                  and Dialog Enhancement feature.
 *
 * @param[in] handle        - The handle returned from the dsGetAudioPort() function.
 * @param[in] feature       - Enums for MS12 features. See dsMS12FEATURE_t
 * @param[in] enable        - MS12 feature to enable or disable.  
 *                              True if enabled, false id disabled.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success 
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetMS12AudioProfileList(), dsGetMS12AudioProfile()
 * 
 */

dsStatus_t  dsEnableMS12Config(int handle, dsMS12FEATURE_t feature,const bool enable);

/**
 * @brief This function is used to enable or disable LE feature.
 *
 * @param[in] handle        - The handle returned from the dsGetAudioPort() function.
 * @param[in] enable        - Set the LE features status of the specified audio port. 
 *                                  True if enabled, false if disabled.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetLEConfig()
 * 
 */

dsStatus_t  dsEnableLEConfig(int handle, const bool enable);

/**
 * @brief This function is used to get LE configuration
 *
 * @param[in] handle        - The handle returned from the dsGetAudioPort() function.
 * @param[out] enable       -  LE status of the specified audio port. 
 *                                  True if enabled, false if disabled.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsEnableLEConfig()
 * 
 */

dsStatus_t dsGetLEConfig(int handle, bool *enable);

/**
 * @brief This function is used to set the encoding type of the specified audio port.
 *
 * @param[in] handle        - The handle returned from the dsGetAudioPort() function.
 * @param[in] encoding      - Encoding type to be used by the audio port. See dsAudioEncoding_t.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetAudioEncoding()
 * 
 */

dsStatus_t  dsSetAudioEncoding(int handle, dsAudioEncoding_t encoding);

/**
 * @brief This function is used to set the audio compression of the specified audio port.
 *
 * @param[in] handle        - The handle returned from the dsGetAudioPort() function.
 * @param[in] compression   - Indicates the compression leveler value. From 0 to 10.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetAudioCompression()
 * 
 */

dsStatus_t  dsSetAudioCompression(int handle, int compression);

/**
 * @brief This function is used to set the Dialog Enhancement level of the specified audio port.
 *
 * @param[in] handle        -  The handle returned from the dsGetAudioPort() function.
 * @param[in] level         -  Dialog Enhancement level of the specified audio port. 
 *                                  Level ranges from 0 1o 16.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetDialogEnhancement()
 * 
 */

dsStatus_t  dsSetDialogEnhancement(int handle, int level);

/**
 * @brief This function is used to set the dolby audio mode status of the specified audio port.
 *
 * @param[in] handle        - The handle returned from the dsGetAudioPort() function.
 * @param[in] mode          - Dolby volume mode of the specified audio port. 
 *                                  True if enabled, false if disabled.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetDolbyVolumeMode()
 * 
 */

dsStatus_t  dsSetDolbyVolumeMode(int handle, bool mode);

/**
 * @brief This function is used to set the Intelligent Equalizer Mode of the specified audio port.
 *
 * @param[in] handle        - The handle returned from the dsGetAudioPort() function.
 * @param[in] mode          - Intelligent Equalizer mode of the specified audio port. 
 *                                  True if enabled, false if disabled.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetIntelligentEqualizerMode()
 * 
 */

dsStatus_t  dsSetIntelligentEqualizerMode(int handle, int mode);

/**
 * @brief This function is used to set the Dolby volume leveller of the specified audio port.
 *
 * @param[in] handle        - The handle returned from the dsGetAudioPort() function.
 * @param[in] volLeveller   - Volume Leveller setting of the specified audio port. 
 *                                  See dsVolumeLeveller_t.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetVolumeLeveller()
 * 
 */

dsStatus_t  dsSetVolumeLeveller(int handle, dsVolumeLeveller_t volLeveller);

/**
 * @brief This function is used to set the audio Bass of the specified audio port.
 *
 * @param[in] handle    The handle returned from the dsGetAudioPort() function.
 * @param[in] boost     Bass Enhancer boost value of the specified audio port from 0 to 100.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetBassEnhancer()
 * 
 */

dsStatus_t  dsSetBassEnhancer(int handle, int boost);

/**
 * @brief This function is used to set the audio Surround Decoder of the specified audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function.
 * @param[in] enabled   - Surround Decoder status of the specified audio port. 
 *                                  True if enabled, false id disabled.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsIsSurroundDecoderEnabled()
 * 
 */

dsStatus_t  dsEnableSurroundDecoder(int handle, bool enabled);

/**
 * @brief This function is used to set the Dynamic Range Control Mode of the specified audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function.
 * @param[in] mode      - Dynamic Range Control mode of the specified audio port. 
 *                              0 for Dynamic Range Control Line Mode, 
 *                              1 for Dynamic Range Control RF mode.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetDRCMode()
 * 
 */

dsStatus_t  dsSetDRCMode(int handle, int mode);

/**
 * @brief This function is used to set the audio Surround Virtualizer 
 *              level of the specified audio port.
 *
 * @param[in] handle        - The handle returned from the dsGetAudioPort() function.
 * @param[in] virtualizer   - Surround virtualizer setting of the specified audio port. 
 *                                  See dsSurroundVirtualizer_t.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetSurroundVirtualizer()
 * 
 */

dsStatus_t  dsSetSurroundVirtualizer(int handle, dsSurroundVirtualizer_t virtualizer);

/**
 * @brief This function is used to set the audio Media intelligent Steering 
 *              enabled status of the specified audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function.
 * @param[in] enabled   - enable/disable MI Steering of the specified audio port. 
 *                              True if enabled, false id disabled.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetMISteering()
 * 
 */

dsStatus_t  dsSetMISteering(int handle, bool enabled);

/**
 * @brief This function is used to get the Graphic Equalizer Mode of the specified audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function.
 * @param[in] mode      - Graphic Equalizer mode of the specified audio port. 
 *                          0 for EQ OFF, 1 for EQ Open, 2 for EQ Rich and 3 for EQ Focused.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetGraphicEqualizerMode()
 * 
 */

dsStatus_t  dsSetGraphicEqualizerMode(int handle, int mode);

/**
 * @brief This function is used to set the MS12 audio profile of the specified audio port
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function.
 * @param[in] profile   - Audio profile name of the specified audio port. 
 *                              All supported profile names can be accessed using 
 *                              dsGetMS12AudioProfileList() function call.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetMS12AudioProfile(), dsGetMS12AudioProfileList()
 * 
 */

dsStatus_t  dsSetMS12AudioProfile(int handle, const char* profile);

/**
 * @brief This function is used to set the stereo mode of the specified audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function.
 * @param[in] mode      - Indicates the stereo mode of the specified audio port. 
 *                              See dsAudioStereoMode_t
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetStereoMode()
 * 
 */

dsStatus_t  dsSetStereoMode(int handle, dsAudioStereoMode_t mode);

/**
 * @brief This function sets the auto mode of the specified audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function.
 * @param[in] autoMode  - Indicates the auto mode of the specified audio port. 
 *                              0 is disabled, 1 is enabled.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetStereoAuto()
 * 
 */

dsStatus_t  dsSetStereoAuto(int handle, int autoMode);

/**
 * @brief This function is used to set the audio gain of the specified audio port. 
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function.
 * @param[in] gain      - The gain to be used by the audio port value from -2080 to 480.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetAudioGain()
 * 
 */

dsStatus_t  dsSetAudioGain(int handle, float gain);

/**
 * @brief This function sets the dB (decibel) level of the specified audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function.
 * @param[in] db        - The dB level from 0 to 10 to be used by the audio port.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetAudioDB()
 * 
 */

dsStatus_t  dsSetAudioDB(int handle, float db);

/**
 * @brief This function sets the audio volume level of the specified audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function.
 * @param[in] level     - The volume level value of the specified audio port. 
 *                              Supported range 0 to 100.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetAudioLevel()
 * 
 */

dsStatus_t  dsSetAudioLevel(int handle, float level);

/**
 * @brief This function sets the audio ducking level of the 
 *              specified audio port based on the specified audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function.
 * @param[in] action    - action type to start or stop ducking. See dsAudioDuckingAction_t.
 * @param[in] type      - ducking type is absolute or relative to current volume 
 *                              level of the specified audio port. See dsAudioDuckingType_t.
 * @param[in] level     - The volume level value of the specified audio port. 
 *                              Suported range is 0 to 100. 
 *                              If output mode is expert mode(dsAUDIO_STEREO_PASSTHR), 
 *                              this will mute the audio. 
 *                              See dsSetStereoMode and dsAudioStereoMode_t 
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsStatus_t  dsSetAudioDucking(int handle, dsAudioDuckingAction_t action, dsAudioDuckingType_t type, const unsigned char level);

/**
 * @brief This function is used to set loop-through mode of the specified audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function.
 * @param[in] loopThru  - Enabled/disable loop-through of the specified audio port. 
 *                              True if enabled, false if enabled.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success 
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsStatus_t  dsEnableLoopThru(int handle, bool loopThru);

/**
 * @brief This function is used to mute or un-mute of the specified audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function.
 * @param[in] mute      - Enabled/disable mute/un-mute of the specified audio port. 
 *                              True if enabled, false if disabled.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsIsAudioMute()
 * 
 */

dsStatus_t  dsSetAudioMute(int handle, bool mute);

/**
 * @brief This function is used to check whether of the specified audio port supports 
 *              Dolby MS11 Multistream Decode 
 *
 * @param[in]  handle           - The handle returned from the dsGetAudioPort() function.
 * @param[out] HasMS11Decode    - MS11 Multistream Decode setting is true if enabled and 
 *                                      false if disabled for the specified audio port.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsStatus_t  dsIsAudioMSDecode(int handle, bool *HasMS11Decode);

/**
 * @brief This function is used to check whether of the specified audio port 
 *              supports Dolby MS12 Multistream Decode
 *
 * @param[in] handle            - The handle returned from the dsGetAudioPort() function.
 * @param[out] HasMS12Decode    - MS12 Multistream Decode setting is true if enabled and false 
 *                                      if disabled for the specified audio port.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsStatus_t  dsIsAudioMS12Decode(int handle, bool *HasMS12Decode);

/**
 * @brief This function is used to set the audio delay in ms of the specified audio port.
 *
 * @param[in] handle            - The handle returned from the dsGetAudioPort() function.
 * @param[in] audioDelayMs      - Delay to apply in ms of the specified audio port.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetAudioDelay()
 * 
 */

dsStatus_t dsSetAudioDelay(int handle, const uint32_t audioDelayMs);

/**
 * @brief This function is used to set the audio delay offset in ms of the specified audio port.
 *
 * @param[in] handle                - The handle returned from the dsGetAudioPort() function.
 * @param[in] audioDelayOffsetMs    - Offset delay to apply in ms of the specified audio port.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetAudioDelayOffset()
 * 
 */

dsStatus_t dsSetAudioDelayOffset(int handle, const uint32_t audioDelayOffsetMs);

/**
 * @brief This function is used to terminate the Audio Port sub-system.
 * 
 * This function will uninitialize the module.@n
 * Term will reset the data structures used within this module and release the 
 * audio port specific handles.
 * Subsequent calls will return dsERR_NONE.
 *
 * @return dsStatus_t           - Status
 * @retval dsERR_NONE           - Success 
 * @retval dsERR_GENERAL        - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsStatus_t  dsAudioPortTerm();

/**
 * @brief This function is used to check if the of the specified audio port is connected
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function.
 * @param[out] pisCon   - Value of current status the audio output port. 
 *                              True if connected, false if not.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsStatus_t dsAudioOutIsConnected(int handle, bool* pisCon);

/**
 * @brief This function is used to register for the Audio Output Connect Event.
 *
 * @param[in] CBFunc    - Audio output port connect callback function. 
 *                                      See dsAudioOutPortConnectCB_t
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsStatus_t dsAudioOutRegisterConnectCB(dsAudioOutPortConnectCB_t CBFunc);

/**
 * @brief This function is used to register for the Audio Format Update Event.
 *
 * @param[in] cbFun     - Audio format update callback function. See dsAudioOutPortConnectCB_t.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsStatus_t dsAudioFormatUpdateRegisterCB (dsAudioFormatUpdateCB_t cbFun);

/**
 * @brief This function is used to find the Audio Format capabilities of the specified audio port.
 *
 * @param[in]  handle           - The handle returned from the dsGetAudioPort() function.
 * @param[out] capabilities     - OR-ed value of supported Audio standards. 
 *                                      See _dsAudioCapabilities_t.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsStatus_t dsGetAudioCapabilities(int handle, int *capabilities);

/**
 * @brief This function is used to find the MS12 capabilities of the specified audio port.
 *
 * @param[in]  handle           - The handle returned from the dsGetAudioPort() function.
 * @param[out] capabilities     - OR-ed value of supported MS12 standards. See sMS12Capabilities_t.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsStatus_t dsGetMS12Capabilities(int handle, int *capabilities);

/**
 * @brief This function is used to reset the Dialog Enhancement of the specified 
 *                      audio port to platform default value. 
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsStatus_t dsResetDialogEnhancement(int handle);

/**
 * @brief This function is used to reset the audio Bass Enhancer of the specified 
 *                      audio port to platform default.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsStatus_t dsResetBassEnhancer(int handle);

/**
 * @brief This function is used to reset the audio Surround Virtualizer level of the 
 *                      specified audio port to platform default.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function
 * 
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsStatus_t dsResetSurroundVirtualizer(int handle);

/**
 * @brief This function is used to reset the Dolby volume leveller of the 
 *                  specified audio port to platform default.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function
 * 
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 */

dsStatus_t dsResetVolumeLeveller(int handle);

/**
 * @brief This function is used to set/override a specific audio setting in.
 *  a specific profile of the specified audio port.
 *
 * @param[in] handle                - The handle returned from the dsGetAudioPort() function.
 * @param[in] profileState          - possible values ADD and REMOVE setting from the persistence.
 * @param[in] profileName           - ProfileName.
 * @param[in] profileSettingsName   - MS12 property name.
 * @param[in] profileSettingValue   - MS12 property value.
 * 
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetMS12AudioProfileList(), dsGetMS12AudioProfile()
 * 
 */

dsStatus_t  dsSetMS12AudioProfileSetttingsOverride(int handle,const char* profileState,const char* profileName,
                                                   const char* profileSettingsName,const char* profileSettingValue);

/**
 * @brief This function is used to enable/disable Associated Audio Mixing 
 *                  of the specified audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function.
 * @param[in] mixing    - mixing enable/disable, true if enabled, false if disabled.
 * 
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetAssociatedAudioMixing()
 * 
 * TODO: Remove unused variable handle.
 * 
 */

dsStatus_t dsSetAssociatedAudioMixing(int handle, bool mixing);

/**
 * @brief This function is used to get the Associated Audio Mixing 
 *                  status of the specified audio port.
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function.
 * @param[out] mixing   - associated Audio Mixing status of the specified audio port. 
 *                              True if enabled and false if disabled.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetAssociatedAudioMixing()
 * 
 * TODO: Remove unused variable handle.
 * 
 */

dsStatus_t  dsGetAssociatedAudioMixing(int handle, bool *mixing);

/**
 * @brief This function is used to set the mixer balance between main and 
 *                      associated audio of the specified audio port.
 *
 * @param[in] handle        - The handle returned from the dsGetAudioPort() function.
 * @param[in] mixerbalance  - int value -32(mute associated) to +32(mute main).
 * 
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetFaderControl()
 * 
 * TODO: Remove unused variable handle.
 * 
* 
 * 
 * 
 */

dsStatus_t  dsSetFaderControl(int handle, int mixerbalance);

/**
 * @brief This function is used to get the mixer balance between main 
 *              and associated audio of the specified audio port.
 *
 * @param[in]  handle           - The handle returned from the dsGetAudioPort() function.
 * @param[out] mixerbalance     - int value -32(mute associated) to +32(mute main).
 * 
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetFaderControl()
 * 
 * TODO: Remove unused variable handle.
 * 
 */

dsStatus_t  dsGetFaderControl(int handle, int* mixerbalance);

/**
 * @brief This function is used to set AC4 Primary language
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function.
 * @param[in] pLang     - char* 3 letter lang code must be used as per ISO 639.
 * 
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetPrimaryLanguage()
 * 
 * TODO: Remove unused variable handle.
 * 
 */

dsStatus_t  dsSetPrimaryLanguage(int handle, const char* pLang);

/**
 * @brief This function is used to get AC4 Primary language
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function.
 * @param[out] pLang    - char* 3 letter lang code must be used as per ISO 639.
 * 
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetPrimaryLanguage()
 * 
 * TODO: Remove unused variable handle.
 * 
 */

dsStatus_t  dsGetPrimaryLanguage(int handle, char* pLang);

/**
 * @brief This function is used to set AC4 Secondary language
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function.
 * @param[in] sLang     - char* 3 letter lang code must be used as per ISO 639.
 * 
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetSecondaryLanguage()
 * 
 * TODO: Remove unused variable handle.
 * 
 */

dsStatus_t  dsSetSecondaryLanguage(int handle, const char* sLang);

/**
 * @brief This function is used to get AC4 Secondary language
 *
 * @param[in] handle    - The handle returned from the dsGetAudioPort() function.
 * @param[out] sLang    - char* 3 letter lang code must be used as per ISO 639.
 * 
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsSetSecondaryLanguage()
 * 
 * TODO: Remove unused variable handle.
 * 
 */

dsStatus_t  dsGetSecondaryLanguage(int handle, char* sLang);

/**
 * @brief This function is used to get the audio HDMI ARC port ID for each platform
 *
 * This function must return ::dsERR_OPERATION_NOT_SUPPORTED if an 
 *              unavailable audio port is requested.
 *
 * @param[in] portId    - Audio HDMI ARC port ID. Min value 0.
 *
 * @return dsStatus_t                       - Status
 * @retval dsERR_NONE                       - Success
 * @retval dsERR_NOT_INITIALIZED            - Module is not initialised
 * @retval dsERR_INVALID_PARAM              - Parameter passed to this function is invalid
 * @retval dsERR_OPERATION_NOT_SUPPORTED    - The attempted operation is not supported
 * @retval dsERR_GENERAL                    - Underlying undefined platform error
 * 
 * @pre  dsAudioPortInit() must be called before calling this API.
 * 
 * @warning  This API is Not thread safe.
 * 
 * @see dsGetSupportedARCTypes()
 * 
 */

dsStatus_t dsGetHDMIARCPortId(int *portId);

/** @} */ // End of DSHAL_AUDIO_API doxygen group 
/** @} */ // End of DS HAL
/** @} */ // End of HPK

#ifdef __cplusplus
}
#endif
#endif /* _DS_AUDIOOUTPORT_H_ */



