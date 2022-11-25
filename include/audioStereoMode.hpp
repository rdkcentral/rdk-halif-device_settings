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
 * @file audioStereoMode.hpp
 * @brief This file defines AudioStereoMode class for managing audio mode types.
 */



/**
* @defgroup devicesettings
* @{
* @defgroup ds
* @{
**/


#ifndef _DS_AUDIOSTEREOMODE_HPP_
#define _DS_AUDIOSTEREOMODE_HPP_

#include "dsConstant.hpp"
#include <string>

namespace device {


/**
 * @class AudioStereoMode
 * @brief This class extends DSConstant to implement AudioStereoMode.
 * It manages the information related to audio mode types like stereo, mono
 * and so on.
 * @ingroup devicesettingsclass
 */
class AudioStereoMode : public DSConstant {

public:
	static const int kMono;       //!< Indicates audio mode of type mono.
	static const int kStereo;     //!< Indicates audio mode of type stereo.
	static const int kSurround;   //!< Indicates audio mode of type surround.
	static const int kPassThru;   //!< Indicates audio mode of type pass through.
	static const int kDD;         //!< Indicates audio mode of type dolby digital.
	static const int kDDPlus;     //!< Indicates audio mode of type dolby digital plus.
	static const int kMax;        //!< Indicates maximum number of audio modes supported.

	static const AudioStereoMode & getInstance(int id);
	static const AudioStereoMode & getInstance(const std::string &name);

	AudioStereoMode(int id);
	virtual ~AudioStereoMode();

};

}

#endif /* _DS_AUDIOSTEREOMODE_HPP_ */


/** @} */
/** @} */
