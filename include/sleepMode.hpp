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
 * @file sleepMode.hpp
 * @brief This file defines SleepMode class for device settings.
 */



/**
* @defgroup devicesettings
* @{
* @defgroup ds
* @{
**/


#ifndef _DS_SLEEPMODE_HPP_
#define _DS_SLEEPMODE_HPP_

#include "dsConstant.hpp"
#include "list.hpp"
#include <string>

namespace device {

/**
 * @class SleepMode
 * @brief This class extends DSConstant to implement SleepMode. It is used
 * to manage the sleep modes for device settings.
 * @ingroup devicesettingsclass
 */
class SleepMode : public DSConstant {

public:
	static const int kLightSleep;  //!< Indicates light sleep mode.
	static const int kDeepSleep;   //!< Indicates deep sleep mode.
	static const int kMax;         //!< Indicates maximum number of sleep modes supported.

	static SleepMode & getInstance(int id);
	static SleepMode & getInstance(const std::string &name);
	List<SleepMode> getSleepModes();
	SleepMode(int id);
	virtual ~SleepMode();

};

}

#endif /* _DS_SLEEPMODE_HPP_ */


/** @} */
/** @} */
