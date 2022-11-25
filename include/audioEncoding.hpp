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
 * @file audioEncoding.hpp
 * @brief This file defines AudioEncoding class for managing audio encoding types.
 */



/**
* @defgroup devicesettings
* @{
* @defgroup ds
* @{
**/


#ifndef _DS_AUDIOENCODING_HPP_
#define _DS_AUDIOENCODING_HPP_

#include "dsConstant.hpp"
#include <string>

namespace device {


/**
 * @class AudioEncoding
 * @brief This class extends DSConstant to implement AudioEncoding which manages
 * audio encodings.
 * @ingroup devicesettingsclass
 */
class AudioEncoding : public DSConstant {

public:
	static const int kNone;    //!< Value indicating encoding type None.
	static const int kDisplay; //!< Value indicating digital audio encoding format.
	static const int kPCM;     //!< Value indicating PCM digital audio encoding format.
	static const int kAC3;     //!< Value indicating AC3 digital audio encoding format.
	static const int kMax;     //!< Indicates the maximum encoding formats supported.

	static const AudioEncoding & getInstance(int id);
	static const AudioEncoding & getInstance(const std::string &name);

	AudioEncoding(int id);
	virtual ~AudioEncoding();

};

}

#endif /* _DS_AUDIOENCODING_HPP_ */


/** @} */
/** @} */
