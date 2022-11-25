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
 * @file videoDFC.hpp
 * @brief This file defines VideoDFC class for managing video decoder format conversion types.
 */



/**
* @defgroup devicesettings
* @{
* @defgroup ds
* @{
**/


#ifndef _DS_VIDEODFC_HPP_
#define _DS_VIDEODFC_HPP_

#include "dsConstant.hpp"
#include <string>

namespace device {


/**
 * @class VideoDFC
 * @brief This class extends DSConstant to manage the video Decoder Format Conversion.
 * @ingroup devicesettingsclass
 */
class VideoDFC : public DSConstant {

public:
	static const int kUnknown;   //!< Indicates decoder format of type unknown.
	static const int kNone;      //!< Indicates decoder format of type none.
	static const int kFull;      //!< Indicates decoder format of type full.

	static const int kLetterBox_16x9; //!< Indicates decoder format of type letter box with 16:9 aspect ratio.
	static const int kLetterBox_14x9; //!< Indicates decoder format of type letter box with 14:9 aspect ratio.

	static const int kCCO;       //!< Indicates center cut out decoder format.

	static const int kPanScan;   //!< Indicates decoder format of type pan and scan.

	static const int kLetterBox_221x1ON4x3;  //!< Indicates decoder format of type letter box 2:21:1 in a 4:3 video frame.

	static const int kLetterBox_221x1ON16x9;  //!< Indicates decoder format of type letter box 2:21:1 in a 16:9 video frame.

	static const int kPlatform;   //!< Indicates decoding format conversion will be managed by the platform.

	static const int kZoom_16x9; //!< Indicates decoder format of type 16:9 zoom.

	static const int kPillarBox_4x3;         //!< Indicates decoder format of type pillar box 4:3.

	static const int kWideScreen_4x3;        //!< Indicates decoder format of type 4:3 wide.

	static const VideoDFC & getInstance(int id);
	static const VideoDFC & getInstance(const std::string &name);

	VideoDFC(int id);
	virtual ~VideoDFC();
};

}

#endif /* _DS_VIDEODFC_HPP_ */


/** @} */
/** @} */
