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
 * @file aspectRatio.hpp
 * @brief This file defines AspectRatio class for managing aspect ratio types.
 */


/**
* @defgroup devicesettings
* @{
* @defgroup ds
* @{
**/


#ifndef _DS_ASPECTRATIO_HPP_
#define _DS_ASPECTRATIO_HPP_

#include "dsConstant.hpp"
#include <string>

namespace device {


/**
 * @class AspectRatio
 * @brief This class extends DSConstant to implement AspectRatio. It manages
 * the aspect ratios of the videos.
 * @ingroup devicesettingsclass
 */
class AspectRatio : public DSConstant {

public:
	static const int k4x3;    //!< Indicates 4x3 aspect ratio.
	static const int k16x9;   //!< Indicates 16x9 aspect ratio.
	static const int kMax;    //!< Indicates maximum number of aspect ratios supported.

	static const AspectRatio & getInstance(int id);
	static const AspectRatio & getInstance(const std::string &name);

	AspectRatio(int id);
	virtual ~AspectRatio();

};

}

#endif /* _DS_ASPECTRATIO_HPP_ */


/** @} */
/** @} */
