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
 * @file dsAudio.h
 */

/**
* @defgroup devicesettings Device Settings
* @{
* @defgroup hal Device Settings HAL
* @{
**/

#ifndef _DS_AUDIOOUTPORT_H_
#define _DS_AUDIOOUTPORT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <sys/types.h>
#include "dsError.h"
#include "dsTypes.h"

/**
 * @brief Callback function is used to notify the Audio port connection status change to the upper layer modules.
 *
 * HAL Implementation should call this method to deliver updated Audio port connection event
 * to the application
 * @param[in] portType : Type of the audio port where connection status is changed.
 * @param[in] uiPortNo : Port number in which the connection status changed.
 * @param[in] isPortCon : Current connection status of the port.
 */

typedef void (*dsAudioOutPortConnectCB_t)(dsAudioPortType_t portType, unsigned int uiPortNo, bool isPortCon);

/**
 * @brief Callback function used to notify applications of Audio Format change
 *
 * HAL Implementation should call this method to deliver updated Audio Format event
 * to the application
 * @param[in] audioFormat : New audio format.
 */

typedef void (*dsAudioFormatUpdateCB_t)(dsAudioFormat_t audioFormat);

/** @addtogroup DSHAL_AUDIO_API Device Settings HAL Audio Public API
 *  @ingroup devicesettingshalapi
 *
 *  Described herein are the DeviceSettings HAL types and functions that are part of the
 *  Audio subsystem. The Audio subsystem manages audio hardware operations.
 *
 *  @{
 */

/**
 * @brief Initialize the underlying Audio Port sub-system.
 * 
 * This function must initialize all the audio specific output ports. It must return
 * ::dsERR_OPERATION_NOT_SUPPORTED when no audio port is present in the device (e.g. a 
 * headless gateway device).
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @warning  This API is Not thread safe.
 */

dsError_t  dsAudioPortInit();

/**
 * @brief Get the audio port handle.
 * 
 * This function returns the handle for the type of audio port requested. Must return
 * ::dsERR_OPERATION_NOT_SUPPORTED if an unavailable audio port is requested.
 *
 * @param[in] type       Indicates the type of audio port (HDMI, SPDIF and so on).
 * @param[in] index      Index of audio port depending on the ports available for the specific platform. (0, 1, ...).
 * @param[out] handle    Indicates pointer to hold the handle of the specified audio port.
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful. 
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t  dsGetAudioPort(dsAudioPortType_t type, int index, int *handle);

/**
 * @brief Get the encoding type of an audio port.
 *
 * This function returns the current audio encoding setting for the specified audio port.
 *
 * @param[in] handle Handle for the output audio port.
 * @param[out] encoding Pointer to hold the encoding setting of the audio port.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_OPERATION_NOT_SUPPORTED Indicates this call is not supported.
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetAudioEncoding()
 */

dsError_t  dsGetAudioEncoding(int handle, dsAudioEncoding_t *encoding);

/**
 * @brief Get the current audio format.
 *
 * This function returns the current audio format..
 *
 * @param[in] handle  Handle for the output audio port
 * @param[out] audioFormat Pointer to hold the audio format.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_OPERATION_NOT_SUPPORTED Indicates dsGetAudioFormat call is not supported.
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t  dsGetAudioFormat(int handle, dsAudioFormat_t *audioFormat);

/**
 * @brief Get the audio compression of an audio port.
 *
 * This function returns the audio compression setting used in the specified audio port.
 *
 * @param[in] handle Handle for the output audio port.
 * @param[out] compression Pointer to hold the compression value of the specified audio port. Value range from 0 to 10
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_OPERATION_NOT_SUPPORTED Indicates this call is not supported.
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetAudioCompression()
 */

dsError_t  dsGetAudioCompression(int handle, int *compression);

/**
 * @brief Get the Dialog Enhancement level of an audio port.
 *
 * This function returns the audio compression setting used in the specified audio port.
 *
 * @param[in] handle Handle for the output audio port.
 * @param[out] level Dialog Enhancement level. Value range from 0 to 16
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_OPERATION_NOT_SUPPORTED Indicates this call is not supported.
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetDialogEnhancement()
 */

dsError_t  dsGetDialogEnhancement(int handle, int *level);

/**
 * @brief Get the dolby audio mode status.
 *
 * This function returns the dolby audio mode status used in the specified audio port.
 *
 * @param[in] handle Handle for the output audio port.
 * @param[out] mode Dolby volume mode true if enabled, and false if disabled.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_OPERATION_NOT_SUPPORTED Indicates this call is not supported.
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetDolbyVolumeMode()
 */

dsError_t  dsGetDolbyVolumeMode(int handle, bool *mode);

/**
 * @brief Get the Intelligent Equalizer Mode.
 *
 * This function returns the Intelligent Equalizer Mode setting used in the specified audio port.
 *
 * @param[in] handle Handle for the output audio port.
 * @param[out] mode Intelligent Equalizer mode: 0 = Off, 1 = Open, 2 = Rich, 3 = focused,
 * 4 = balanced, 5 = warm, 6 = detailed
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_OPERATION_NOT_SUPPORTED Indicates this call is not supported.
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetIntelligentEqualizerMode()
 */

dsError_t  dsGetIntelligentEqualizerMode(int handle, int *mode);

/**
 * @brief To get the Dolby volume leveller settings.
 *
 * This function will get the Volume leveller value used in a given audio port
 *
 * @param[in] handle       Handle for the output Audio port
 * @param[out] volLeveller  Volume Leveller setting
 * 
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetVolumeLeveller()
 */

dsError_t  dsGetVolumeLeveller(int handle, dsVolumeLeveller_t* volLeveller);

/**
 * @brief To get the audio Bass
 *
 * This function will get the Bass used in a given audio port
 *
 * @param[in] handle  Handle for the output Audio port
 * @param[out] boost   Bass Enhancer boost value from 0 to 100
 * 
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetBassEnhancer()
 */

dsError_t  dsGetBassEnhancer(int handle, int *boost);

/**
 * @brief To get the audio Surround Decoder
 *
 * This function will get enable/disable status of surround decoder
 *
 * @param[in] handle   Handle for the output Audio port
 * @param[out] enabled  Surround Decoder enable/disable
 * 
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsEnableSurroundDecoder()
 */

dsError_t  dsIsSurroundDecoderEnabled(int handle, bool *enabled);

/**
 * @brief To get the DRC Mode
 *
 * This function will get the Dynamic Range Control used in a given audio port
 *
 * @param[in] handle   Handle for the output Audio port
 * @param[out] mode     0 for DRC line mode and 1 for DRC RF mode
 * 
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetDRCMode()
 */

dsError_t  dsGetDRCMode(int handle, int *mode);

/**
 * @brief To get the audio Surround Virtualizer level
 *
 * This function will get the Surround Virtualizer level used in a given audio port
 *
 * @param[in] handle       Handle for the output Audio port
 * @param[out] virtualizer  Surround virtualizer setting
 * 
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetSurroundVirtualizer()
 */

dsError_t  dsGetSurroundVirtualizer(int handle, dsSurroundVirtualizer_t *virtualizer);

/**
 * @brief To get the audio Media intelligent Steering
 *
 * This function will get the Media Intelligent Steering
 *
 * @param[in] handle       Handle for the output Audio port
 * @param[out] enabled      Enable/disable MI Steering
 * 
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetMISteering()
 */

dsError_t  dsGetMISteering(int handle, bool *enabled);

/**
 * @brief Get the Graphic Equalizer Mode.
 *
 * This function returns the Graphic Equalizer Mode setting used in the specified audio port.
 *
 * @param[in] handle Handle for the output audio port.
 * @param[out] mode   Graphic Equalizer Mode. 0 for EQ OFF, 1 for EQ Open, 2 for EQ Rich and 3 for EQ Focused 
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetGraphicEqualizerMode()
 */

dsError_t  dsGetGraphicEqualizerMode(int handle, int *mode);

/**
 * @brief To get the supported MS12 audio profiles
 *
 * This function will get the list of supported ms12 audio profiles
 *
 * @param[in] handle       Handle for the output Audio port
 * @param[out] profiles     List of supported audio profiles
 * 
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetMS12AudioProfile()
 */

dsError_t  dsGetMS12AudioProfileList(int handle, dsMS12AudioProfileList_t* profiles);

/**
 * @brief To get current audio profile selection
 *
 * This function will get the current audio profile configured
 *
 * @param[in] handle     Handle for the output Audio port
 * @param[out] profile    Audio profile configured currently
 * 
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetMS12AudioProfile()
 */

dsError_t  dsGetMS12AudioProfile(int handle, char *profile);

/**
 * @brief Get the supported ARC types of the connected ARC/eARC device
 *
 * This function gets the supported ARC types of the connected device on ARC/eARC port.
 *
 * @param[in] handle Handle for the HDMI ARC/eARC port.
 * @param[out] types Value of supported ARC types as per the enum dsAudioARCTypes_t
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsGetSupportedARCTypes(int handle, int *types);

/**
 * @brief Set Short Audio Descriptor retrieved from CEC for the connected ARC device
 *
 * This function sets the Short Audio Descriptor based on best available options
 * of Audio capabilities supported by connected ARC device. Required when ARC output
 * mode is Auto
 *
 * @param[in] handle Handle for the HDMI ARC/eARC port.
 * @param[in] sad_list All SADs retrieved from CEC for the connected ARC device.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsAudioSetSAD(int handle, dsAudioSADList_t sad_list);

/**
 * @brief enable/disable ARC/EARC and route audio to connected device
 *
 * This function enables/disables ARC/EARC and routes audio to connected device.
 *
 * @param[in] handle Handle for the HDMI ARC/eARC port.
 * @param[in] arcStatus to enable/disable ARC/eARC feature
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsAudioEnableARC(int handle, dsAudioARCStatus_t arcStatus);

/**
 * @brief Get the stereo mode of an audio port.
 * 
 * This function gets the stereo mode setting for a specified audio port.
 *
 * @param[in] handle Handle for the output audio port.
 * @param[out] stereoMode Pointer to hold the stereo mode setting of the
 * specified audio port.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetStereoMode()
 */

dsError_t  dsGetStereoMode(int handle, dsAudioStereoMode_t *stereoMode);

/**
 * @brief This function is used to get the current auto mode setting of the specified
 * audio port.
 *
 * @param[in] handle Handle for the output audio port.
 * @param[out] autoMode Pointer to hold the auto mode setting (0 for Disabled, 1 for Enabled ) of the specified audio port.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetStereoAuto()
 */	

dsError_t  dsGetStereoAuto(int handle, int *autoMode);

/**
 * @brief Get the audio gain of an audio port.
 * 
 * This function returns the current audio gain for the specified audio port.
 *
 * @param[in] handle Handle for the output audio port.
 * @param[out] gain Pointer to hold the gain value from -2080 to 480 of the specified audio port. 
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetAudioGain()
 */

dsError_t  dsGetAudioGain(int handle, float *gain);

/**
 * @brief Get the current audio dB level of an audio port.
 * 
 * This function returns the current audio dB level for the specified audio port. 
 *
 * @param[in] handle Handle for the output audio port.
 * @param[out] db Pointer to hold the dB value from 0 to 10 of the specified audio port.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetAudioDB()
 */

dsError_t  dsGetAudioDB(int handle, float *db);

/**
 * @brief Get the current audio volume level of an audio port.
 * 
 * This function returns the current audio volume level for the specified audio port.
 *
 * @param[in] handle Handle for the output audio port.
 * @param[out] level Pointer to hold the audio level value from 0 to 100 of the specified audio port.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetAudioLevel()
 */

dsError_t  dsGetAudioLevel(int handle, float *level);

/**
 * @brief Get the maximum audio dB level of an audio port.
 * 
 * This function returns the maximum audio dB level supported by the specified audio port.
 *
 * @param[in] handle Handle for the output audio port.
 * @param[out] maxDb Pointer to hold the maximum audio dB value supported by the specified audio port as float value.e.g:10.0
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t  dsGetAudioMaxDB(int handle, float *maxDb);

/**
 * @brief Get the minimum audio dB level of an audio port.
 * 
 * This function returns the minimum audio dB level supported by the specified audio port.
 *
 * @param[in] handle Handle for the output audio port.
 * @param[out] minDb Pointer to hold the minimum audio dB value supported by the specified audio port in float. e.g: 0.0
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t  dsGetAudioMinDB(int handle, float *minDb);

/**
 * @brief Get the optimal audio level of an audio port.
 * 
 * This function returns the optimal audio level (dB) for the specified audio port.
 *
 * @param[in] handle Handle for the output audio port.
 * @param[out] optimalLevel Pointer to hold the optimal level value of the specified audio port in float value between 0 and 10. e:g 2.5
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t  dsGetAudioOptimalLevel(int handle, float *optimalLevel);

/**
 * @brief Get the audio delay in milliseconds
 *
 * This function will get the audio delay in milliseconds.
 *
 * @param[in] handle       Handle for the output Audio port
 * @param[out] audioDelayMs Audio delay in milliseconds
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetAudioDelay()
 */

dsError_t dsGetAudioDelay(int handle, uint32_t *audioDelayMs);

/**
 * @brief Get the audio delay offset in milliseconds
 *
 * This function will get the audio delay offset in milliseconds.
 *
 * @param[in] handle             Handle for the output Audio port
 * @param[out] audioDelayOffsetMs Audio delay offset in milliseconds
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetAudioDelayOffset()
 */

dsError_t dsGetAudioDelayOffset(int handle, uint32_t *audioDelayOffsetMs);

/**
 * @brief Set the audio ATMOS outout mode
 *
 * This function will set the Audio Atmos output mode 
 *
 * @param[in] handle    Handle for the output Audio port
 * @param[in] enable    set audio ATMOS output mode
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsSetAudioAtmosOutputMode(int handle, bool enable);
  
/**
 * @brief Get the sink device ATMOS capability
 *
 * This function will get the sink device ATMOS capability
 *
 * @param[in] handle      Handle for the output Audio port
 * @param[out] capability  sink device ATMOS capability
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsGetSinkDeviceAtmosCapability(int handle, dsATMOSCapability_t *capability);

/**
 * @brief Get the loop-through mode of an audio port.
 * 
 * This function is used to check if the audio port is configured for loop-through.
 *
 * @param[in] handle     Handle for the output audio port.
 * @param[out] loopThru   Pointer to hold the loop-through setting of the specified audio.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t  dsIsAudioLoopThru(int handle, bool *loopThru);

/**
 * @brief Get the audio mute status of an audio port.
 * 
 * This function is used to check whether the audio on a specified port is muted or not.
 *
 * @param[in] handle     Handle for the output audio port.
 * @param[out] muted      Pointer to hold the mute setting of the specified audio port.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetAudioMute()
 */

dsError_t  dsIsAudioMute(int handle, bool *muted);

/**
 * @brief This function indicates whether the specified Audio port is enabled or not.
 *
 * @param[in] handle     Handle of the output audio port.
 * @param[out] enabled    The address of a location to hold the audio port enable state
 *                          on return (@a true when port is enabled, @a false otherwise).
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsEnableAudioPort()
 */

dsError_t  dsIsAudioPortEnabled(int handle, bool *enabled);

/**
 * @brief This function is used to enable or disable the specified Audio port.
 *
 * @param[in] handle     Handle of the output audio port.
 * @param[in] enabled    Flag to control the Audio port state
 *                         (@a true to enable, @a false to disable)
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsIsAudioPortEnabled()
 */

dsError_t  dsEnableAudioPort(int handle, bool enabled);

/**
 * @brief This function is used to enable or disable MS12 DAPV2 and DE feature.
 *
 * @param[in] handle     Handle of the output audio port.
 * @param[in] feature    Enums for MS12 features
 * @param[in] enable     Flag to control the MS12 features
 *                         (@a true to enable, @a false to disable)
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetMS12AudioProfileList(), dsGetMS12AudioProfile()
 */

dsError_t  dsEnableMS12Config(int handle, dsMS12FEATURE_t feature,const bool enable);

/**
 * @brief This function is used to enable or disable Loudness Equivalence feature.
 *
 * @param[in] handle     Handle of the output audio port.
 * @param[in] enable     Flag to control the LE features
 *                         (@a true to enable, @a false to disable)
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetLEConfig()
 */

dsError_t  dsEnableLEConfig(int handle, const bool enable);

/**
 * @brief To Get LE configuration
 *
 * This function is used to Get LE features
 *
 * @param[in] handle    Handle for the output Audio port
 * @param[out] enable    true if LE is enabled else False
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsEnableLEConfig()
 */

dsError_t dsGetLEConfig(int handle, bool *enable);

/**
 * @brief Set the encoding type of an audio port.
 * 
 * This function sets the audio encoding type to be used on the specified audio port.
 *
 * @param[in] handle    Handle for the output audio port.
 * @param[in] encoding  The encoding type to be used on the audio port.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetAudioEncoding()
 */

dsError_t  dsSetAudioEncoding(int handle, dsAudioEncoding_t encoding);

/**
 * @brief Set the audio compression of an audio port.
 * 
 * This function sets the audio compression type to be used on the specified audio port.
 *
 * @param[in] handle      Handle for the output audio port.
 * @param[in] compression Indicates the compression leveler value from 0 to 10 to be used on the audio port.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetAudioCompression()
 */

dsError_t  dsSetAudioCompression(int handle, int compression);

/**
 * @brief Get the Dialog Enhancement level of an audio port.
 * 
 * This function returns the audio compression setting used in the specified audio port.
 *
 * @param[in] handle     Handle for the output audio port.
 * @param[in] level      Dialog Enhancement level. Level ranges from 0 1o 16.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetDialogEnhancement()
 */

dsError_t  dsSetDialogEnhancement(int handle, int level);

/**
 * @brief Get the dolby audio mode status.
 * 
 * This function returns the dolby audio mode status used in the specified audio port.
 *
 * @param[in] handle     Handle for the output audio port.
 * @param[in] mode      Dolby volume mode. 0 for OFF, 1 for ON and 2 for AUTO mode.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetDolbyVolumeMode()
 */

dsError_t  dsSetDolbyVolumeMode(int handle, bool mode);

/**
 * @brief Set the Intelligent Equalizer Mode.
 * 
 * This function returns the Intelligent Equalizer Mode setting used in the specified audio port.
 *
 * @param[in] handle     Handle for the output audio port.
 * @param[in] mode       Intelligent Equalizer mode: 0 = Off, 1 = Open, 2 = Rich, 3 = focused,
 *                       4 = balanced, 5 = warm, 6 = detailed
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetIntelligentEqualizerMode()
 */

dsError_t  dsSetIntelligentEqualizerMode(int handle, int mode);

/**
 * @brief To set the Dolby volume leveller
 *
 * This function will set the Volume leveller value used in a given audio port
 *
 * @param[in] handle      Handle for the output Audio port
 * @param[in] volLeveller Volume Leveller setting
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetVolumeLeveller()
 */

dsError_t  dsSetVolumeLeveller(int handle, dsVolumeLeveller_t volLeveller);

/**
 * @brief To set the audio Bass
 *
 * This function will set the Bass used in a given audio port
 *
 * @param[in] handle    Handle for the output Audio port
 * @param[in] boost     Bass Enhancer boost value from 0 10 100
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetBassEnhancer()
 */

dsError_t  dsSetBassEnhancer(int handle, int boost);

/**
 * @brief To set the audio Surround Decoder
 *
 * This function will enable/disable surround decoder
 *
 * @param[in] handle    Handle for the output Audio port
 * @param[in] enabled   Surround Decoder enable/disable
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsIsSurroundDecoderEnabled()
 */

dsError_t  dsEnableSurroundDecoder(int handle, bool enabled);

/**
 * @brief To set the DRC Mode
 *
 * This function will set the Dynamic Range Control used in a given audio port
 *
 * @param[in] handle    Handle for the output Audio port
 * @param[in] mode      0 for DRC Line Mode 1 for DRC RF mode.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetDRCMode()
 */

dsError_t  dsSetDRCMode(int handle, int mode);

/**
 * @brief To set the audio Surround Virtualizer level
 *
 * This function will set the Surround Virtualizer level used in a given audio port
 *
 * @param[in] handle      Handle for the output Audio port
 * @param[in] virtualizer Surround virtualizer setting
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetSurroundVirtualizer()
 */

dsError_t  dsSetSurroundVirtualizer(int handle, dsSurroundVirtualizer_t virtualizer);

/**
 * @brief To set the audio Media intelligent Steering
 *
 * This function will set the Media Intelligent Steering
 *
 * @param[in] handle    Handle for the output Audio port
 * @param[in] enabled   enable/disable MI Steering
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetMISteering()
 */

dsError_t  dsSetMISteering(int handle, bool enabled);

/**
 * @brief Get the Graphic Equalizer Mode.
 *
 * This function returns the Graphic Equalizer Mode setting used in the specified audio port.
 *
 * @param[in] handle     Handle for the output audio port.
 * @param[in] mode      Graphic Equalizer mode. 0 for EQ OFF, 1 for EQ Open, 2 for EQ Rich and 3 for EQ Focused
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetGraphicEqualizerMode()
 */

dsError_t  dsSetGraphicEqualizerMode(int handle, int mode);

/**
 * @brief To set the ms12 audio profile
 *
 * This function will configure the user selected ms12 audio profile
 *
 * @param[in] handle    Handle for the output audio port
 * @param[in] profile   Audio profile name
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetMS12AudioProfile(), dsGetMS12AudioProfileList()
 */

dsError_t  dsSetMS12AudioProfile(int handle, const char* profile);

/**
 * @brief Set the stereo mode of an audio port.
 * 
 * This function sets the stereo mode to be used on the specified audio port.
 *
 * @param[in] handle     Handle for the output audio port.
 * @param[in] mode       Indicates the stereo mode to be used on audio port.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetStereoMode()
 */

dsError_t  dsSetStereoMode(int handle, dsAudioStereoMode_t mode);

/**
 * @brief This function sets the auto mode to be used on the specified audio port.
 *
 * @param[in] handle     Handle for the output audio port.
 * @param[in] autoMode   Indicates the auto mode (0 for Disabled, 1 for Enabled ) to be used on audio port.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetStereoAuto()
 */

dsError_t  dsSetStereoAuto(int handle, int autoMode);

/**
 * @brief Set the audio gain of an audio port.
 * 
 * This function sets the gain to be used on the specified audio port.
 *
 * @param[in] handle     Handle for the output audio port.
 * @param[in] gain       The gain to be used on the audio port value from -2080 to 480.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetAudioGain()
 */

dsError_t  dsSetAudioGain(int handle, float gain);

/**
 * @brief This function sets the dB level to be used on the specified audio port.
 *
 * @param[in] handle    Handle for the output audio port.
 * @param[in] db        The dB level from 0 to 10 to be used on the audio port.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetAudioDB()
 */

dsError_t  dsSetAudioDB(int handle, float db);

/**
 * @brief This function sets the audio volume level to be used on the specified audio port.
 *
 * @param[in] handle    Handle for the output audio port.
 * @param[in] level     The volume level value from 0 to 100 to be used on the audio port.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetAudioLevel()
 */

dsError_t  dsSetAudioLevel(int handle, float level);

/**
 * @brief This function sets the audio ducking level to be used on the specified audio port based on the audio output mode.
 *
 * @param[in] handle   Handle for the output audio port.
 * @param[in] action   action type to start or stop ducking.
 * @param[in] type     ducking type is absolute or relative to current volume level.
 * @param[in] level    The volume level value from 0 to 100 to be used on the audio port.If output mode is expert mode, this will mute the audio.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t  dsSetAudioDucking(int handle, dsAudioDuckingAction_t action, dsAudioDuckingType_t type, const unsigned char level);

/**
 * @brief Set loop-through mode of an audio port.
 * 
 * This function enables/disables audio loop-through on the specified audio port.
 *
 * @param[in] handle    Handle for the output audio port.
 * @param[in] loopThru  Boolean flag to enable/disable loop-through.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t  dsEnableLoopThru(int handle, bool loopThru);

/**
 * @brief Mute or un-mute an audio port.
 * 
 * This function mutes or unmutes the specified audio output port.
 *
 * @param[in] handle    Handle for the output audio port.
 * @param[in] mute      Boolean flag to mute/un-mute the audio port.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsIsAudioMute()
 */

dsError_t  dsSetAudioMute(int handle, bool mute);

/**
 * @brief This function is used to check whether the audio port supports Dolby MS11 Multistream Decode
 *
 * @param[in]  handle        Handle for the output audio port.
 * @param[out] HasMS11Decode MS11 Multistream Decode setting is true if enabled and false if disabled for the specified audio port.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t  dsIsAudioMSDecode(int handle, bool *HasMS11Decode);

/**
 * @brief This function is used to check whether the audio port supports Dolby MS12 Multistream Decode
 *
 * @param[in] handle        Handle for the output audio port.
 * @param[out] HasMS12Decode MS12 Multistream Decode setting is true if enabled and false if disabled for the specified audio port.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid prameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t  dsIsAudioMS12Decode(int handle, bool *HasMS12Decode);

/**
 * @brief Set the audio delay in milliseconds
 * 
 * This function will set the audio delay in milliseconds
 *
 * @param[in] handle        Handle for the output Audio port
 * @param[in] audioDelayMs  Amount of milliseconds of delay
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetAudioDelay()
 */

dsError_t dsSetAudioDelay(int handle, const uint32_t audioDelayMs);

/**
 * @brief Set the audio delay offset in milliseconds
 * 
 * This function will set the audio delay offset in milliseconds
 *
 * @param[in] handle              Handle for the output Audio port
 * @param[in] audioDelayOffsetMs  Amount of milliseconds of delay offset
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetAudioDelayOffset()
 */

dsError_t dsSetAudioDelayOffset(int handle, const uint32_t audioDelayOffsetMs);

/**
 * @brief Terminate the Audio Port sub-system.
 * 
 * This function will terminate the usage of audio output ports by resetting the data
 * structures used within this module and release the audio port specific handles.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t  dsAudioPortTerm();

/**
 * @brief To check if the audio output port is connected
 *
 * This function is used to check if the audio output port is connected
 *
 * @param[in] handle        Handle for the output Audio port
 * @param[out] pisCon        Boolean flag for port if ture port is connected and falsae if not connected 
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsAudioOutIsConnected(int handle, bool* pisCon);

/**
 * @brief Register for the Audio Output Connect Event
 *
 * This function is used to register for the Audio Output Connect Event
 *
 * @param[in] CBFunc Audio output port connect callback function.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsAudioOutRegisterConnectCB(dsAudioOutPortConnectCB_t CBFunc);

/**
 * @brief Register for the Audio Format Update Event
 *
 * This function is used to register for the Audio Format Update Event
 *
 * @param[in] cbFun Audio format update callback function.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsAudioFormatUpdateRegisterCB (dsAudioFormatUpdateCB_t cbFun);

/**
 * @brief To find the Audio Format capabilities provided by SOC
 * 
 * This function is used to check which Audio capabilities the SoC supports
 *
 * @param[in]  handle        Handle for the output audio port 
 * @param[out] capabilities  OR-ed value of supported Audio standards as defined in dsAudioCapabilities_t.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsGetAudioCapabilities(int handle, int *capabilities);

/**
 * @brief To find the MS12 capabilities provided by SoC
 * 
 * This function is used to check which MS12 capabilities the SoC supports
 *
 * @param[in]  handle        Handle for the output audio port
 * @param[out] capabilities  OR-ed value of supported MS12 standards defined as per dsMS12Capabilities_t.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsGetMS12Capabilities(int handle, int *capabilities);

/**
 * @brief to reset the Dialog Enhancement 
 *
 * This function is used to reset the Dialog Enhancement
 *
 * @param[in] handle        Handle for the output audio port
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsResetDialogEnhancement(int handle);

/**
 * @brief to reset the audio Bass Enhancer
 *
 * This function is used to reset the audio Bass Enhancer
 *
 * @param[in] handle        Handle for the output audio port
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsResetBassEnhancer(int handle);

/**
 * @brief to reset the audio Surround Virtualizer level
 *
 * This function is used to reset the audio Surround Virtualizer level
 *
 * @param[in] handle        Handle for the output audio port
 * 
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsResetSurroundVirtualizer(int handle);

/**
 * @brief to reset the Dolby volume leveller
 *
 * This function is used to reset the Dolby volume leveller
 *
 * @param[in] handle        Handle for the output audio port
 * 
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid prameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 */

dsError_t dsResetVolumeLeveller(int handle);

/**
 * @brief To Set/override a specific audio setting in 
 *  a specific profile
 *
 * This function will override a specific audio setting in a
 * specific profile
 *
 * @param[in] handle        Handle for the output Audio port
 * @param[in] profileState  possible values ADD and REMOVE setting from the persistence
 * @param[in] profileName   ProfileName 
 * @param[in] profileSettingsName MS12 property name
 * @param[in] profileSettingValue MS12 property value 
 * 
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetMS12AudioProfileList(), dsGetMS12AudioProfile()
 */

dsError_t  dsSetMS12AudioProfileSetttingsOverride(int handle,const char* profileState,const char* profileName,
                                                   const char* profileSettingsName,const char* profileSettingValue);

/**
 * @brief Enable/Disable Associated Audio Mixing
 *
 * This function will Enable/Disable Associated Audio Mixing
 *
 * @param[in] handle        Handle for the output Audio port (Not Used as setting is not port specific)
 * @param[in] mixing        mixing enable/disable
 * 
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetAssociatedAudioMixing()
 */

dsError_t dsSetAssociatedAudioMixing(int handle, bool mixing);

/**
 * @brief To get the Associated Audio Mixing status - enabled/disabled
 *
 * This function will get the Associated Audio Mixing status
 *
 * @param[in] handle        Handle for the output Audio port (Not Used as setting is not port specific)
 * @param[out] mixing        Associated Audio Mixing status is true if enabled and false if disabled.
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetAssociatedAudioMixing()
 */

dsError_t  dsGetAssociatedAudioMixing(int handle, bool *mixing);

/**
 * @brief To set the mixerbalance between main and associated audio
 *
 * This function will set the mixerbalance between main and associated audio
 *
 * @param[in] handle        Handle for the output Audio port (Not Used as setting is not port specific)
 * @param[in] mixerbalance  int value -32(mute associated) to +32(mute main)
 * 
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetFaderControl()
 */

dsError_t  dsSetFaderControl(int handle, int mixerbalance);

/**
 * @brief To get the mixerbalance between main and associated audio
 *
 * This function will get the mixerbalance between main and associated audio
 *
 * @param[in]  handle         Handle for the output Audio port (Not Used as setting is not port specific)
 * @param[out] mixerbalance int value -32(mute associated) to +32(mute main)
 * 
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetFaderControl()
 */

dsError_t  dsGetFaderControl(int handle, int* mixerbalance);

/**
 * @brief To set AC4 Primary language
 *
 * This function will set AC4 Primary language
 *
 * @param[in] handle       Handle for the output Audio port (Not Used as setting is not port specific)
 * @param[in] pLang        char* 3 letter lang code should be used as per ISO 639
 * 
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetPrimaryLanguage()
 */

dsError_t  dsSetPrimaryLanguage(int handle, const char* pLang);

/**
 * @brief To get AC4 Primary language
 *
 * This function will get AC4 Primary language
 *
 * @param[in] handle       Handle for the output Audio port (Not Used as setting is not port specific)
 * @param[out] pLang        char* 3 letter lang code should be used as per ISO 639
 * 
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetPrimaryLanguage()
 */

dsError_t  dsGetPrimaryLanguage(int handle, char* pLang);

/**
 * @brief To set AC4 Secondary language
 *
 * This function will set AC4 Secondary language
 *
 * @param[in] handle       Handle for the output Audio port (Not Used as setting is not port specific)
 * @param[in] sLang        char* 3 letter lang code should be used as per ISO 639
 * 
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetSecondaryLanguage()
 */

dsError_t  dsSetSecondaryLanguage(int handle, const char* sLang);

/**
 * @brief To get AC4 Secondary language
 *
 * This function will get AC4 Secondary language
 *
 * @param[in] handle       Handle for the output Audio port (Not Used as setting is not port specific)
 * @param[out] sLang        char* 3 letter lang code should be used as per ISO 639
 * 
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsSetSecondaryLanguage()
 */

dsError_t  dsGetSecondaryLanguage(int handle, char* sLang);

/**
 * @brief Get the audio HDMI ARC port ID for each platform
 *
 * This function will get audio HDMI ARC port ID
 *
 * @param[in] portId       Get audio HDMI ARC port ID
 *
 * @return dsError_t - Device Settings error code
 * @retval dsERR_NONE Indicates the call was successful.
 * @retval dsERR_GENERAL Indicates error due to general failure. In the HAL side implementation, all of the return values will
 * be initialized with this error code. So that any of the undefined error case scenario in the HAL code, will be report as this error code.
 * @retval dsERR_INVALID_PARAM Indicates error due to invalid parameter value.
 * @retval dsERR_INVALID_STATE Indicates the respective api is called with out calling dsAudioPortInit() or  preceding dsAudioPortInit has failed
 * @pre  dsAudioPortInit() should be called before calling this API.
 * @warning  This API is Not thread safe.
 * @see dsGetSupportedARCTypes()
 */

dsError_t dsGetHDMIARCPortId(int *portId);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif
#endif /* _DS_AUDIOOUTPORT_H_ */


/** @} */
/** @} */
