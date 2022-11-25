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
 * @file pixelResolution.hpp
 * @brief This file defines PixelResolution class for managing video resolution types.
 */



/**
* @defgroup devicesettings
* @{
* @defgroup ds
* @{
**/


#ifndef _DS_PIXELRESOLUTION_HPP_
#define _DS_PIXELRESOLUTION_HPP_

#include "dsConstant.hpp"
#include <string>

namespace device {


/**
 * @class PixelResolution
 * @brief This class extends DSConstant to manages the pixel resolution of the video.
 * @ingroup devicesettingsclass
 */
class PixelResolution : public DSConstant {

public:

    static const int k720x480;    //!< Indicates 720x480 video resolution.
    static const int k720x576;    //!< Indicates 720x576 video resolution.
    static const int k1280x720;   //!< Indicates 1280x720 video resolution.
    static const int k1920x1080;  //!< Indicates 1920x1080 video resolution.

    static const int k3840x2160; //!< Indicates 3840x2160 video resolution.
    static const int k4096x2160; //!< Indicates 4096x2160 video resolution.

    static const int kMax;      //!< Indicates the maximum number of video resolutions supported.

    static const PixelResolution & getInstance(int id);
    static const PixelResolution & getInstance(const std::string &name);

    PixelResolution(int id);
    virtual ~PixelResolution();
};

}

#endif /* _DS_PIXELRESOLUTION_HPP_ */


/** @} */
/** @} */
