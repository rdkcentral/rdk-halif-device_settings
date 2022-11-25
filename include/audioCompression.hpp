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
 * @file audioCompression.hpp
 * @brief This file defines AudioCompression class for managing audio compression levels.
 */


/**
* @defgroup devicesettings
* @{
* @defgroup ds
* @{
**/


#ifndef _DS_AUDIOCOMPRESSION_HPP_
#define _DS_AUDIOCOMPRESSION_HPP_

#include "dsConstant.hpp"
#include <string>

namespace device {

/**
 * @class AudioCompression
 * @brief This class extends DSConstant for implementing AudioCompression.
 * It helps to maintain different audio compressions.
 * @ingroup devicesettingsclass
 */
class AudioCompression : public DSConstant {

public:
	static const int kNone;     //!< Indicates audio compression None.
	static const int kLight;    //!< Indicates light audio compression.
	static const int kMedium;   //!< Indicates medium audio compression.
	static const int kHeavy;    //!< Indicates heavy audio compression.
	static const int kMax;      //!< Indicates number of audio compression supported.

	static const AudioCompression & getInstance(int id);
	static const AudioCompression & getInstance(const std::string &name);

	AudioCompression(int id);
	virtual ~AudioCompression();

};

}

#endif /* _DS_AUDIOCOMPRESSION_HPP_ */


/** @} */
/** @} */
