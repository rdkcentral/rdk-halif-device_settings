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
* @defgroup devicesettings
* @{
* @defgroup ds
* @{
**/


#ifndef _DS_VIDEORESOLUTION_H_
#define _DS_VIDEORESOLUTION_H_

#include "dsTypes.h"
#include "aspectRatio.hpp"
#include "pixelResolution.hpp"
#include "stereoScopicMode.hpp"
#include "frameRate.hpp"
#include "dsConstant.hpp"

#include <string>
#include <vector>


/**
 * @file videoResolution.hpp
 * @brief It contains class and structure refrenced by the videoResolution.cpp file.
 */
namespace device {


/**
 * @calss VideoResolution
 * @brief Class extending DSConstant to implement the videoResolution interface.
 * @ingroup devicesettingsclass
 */
class VideoResolution : public DSConstant {

	int _pixelResolutionId;   //!< Indicates the video resolution.
	int _aspectRatioId;       //!< Indicates aspect ratio type of the video.
	int _stereoScopicModeId;  //!< Indicates the stereoscopic mode of the video.
	int _frameRateId;         //!< Indicates frame rate of the video.

	bool _interlaced;         //!< TRUE indicates interlaced scan and FALSE indicates progressive scan.
	bool _enabled;            //!< TRUE indicates this video resolution is enabled otherwise disabled.


public:

	static const VideoResolution & getInstance(int id);
	static const VideoResolution & getInstance(const std::string &name, bool isIgnoreEdid=false);


	VideoResolution(const int id, const std::string &name,
					int resolutionId, int ratioid, int ssModeId,
					int frameRateId, bool interlacedId, bool enabled = true);
	virtual ~VideoResolution();
	const PixelResolution & getPixelResolution() const;
	const AspectRatio & getAspectRatio() const;
	const StereoScopicMode & getStereoscopicMode()const;
	const FrameRate & getFrameRate() const;
	bool isInterlaced() const;
	bool isEnabled() const;
};

}

#endif /* VIDEORESOLUTION_H_ */


/** @} */
/** @} */
