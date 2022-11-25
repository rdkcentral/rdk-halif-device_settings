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
 * @file stereoScopicMode.hpp
 * @brief This file defines StereoScopicMode class to manage the video stereoscopy types.
 */



/**
* @defgroup devicesettings
* @{
* @defgroup ds
* @{
**/


#ifndef _DS_STEREOSCOPICMODE_HPP_
#define _DS_STEREOSCOPICMODE_HPP_

#include "dsConstant.hpp"
#include <string>

namespace device {

/**
 * @class StereoScopicMode
 * @brief This class extentds DSConstant to implement StereoScopicMode.
 * It manages the stereoscopic mode of the video.
 * @ingroup devicesettingsclass
 */
class StereoScopicMode : public DSConstant {

public:
	static const int kUnkown;          //!< Indicates video stereoscopy of unknown type.
	static const int k2D;              //!< Indicates video stereoscopy of type 2D.
	static const int k3DSidebySide;    //!< Indicates video stereoscopy of type 3D Side-by-Side.
	static const int k3dTopAndBottom;  //!< Indicates video stereoscopy of type 3D top and bottom.
	static const int kMax;             //!< Indicates the maximum number of supported stereoscopy types.

	static const StereoScopicMode & getInstance(int id);
	static const StereoScopicMode & getInstance(const std::string &name);

	StereoScopicMode(int id);
	virtual ~StereoScopicMode();
};

}

#endif /* _DS_STEREOSCOPICMODE_HPP_ */


/** @} */
/** @} */
