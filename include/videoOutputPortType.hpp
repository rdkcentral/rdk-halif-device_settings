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


#ifndef _DS_VIDEOOUTPUTPORTTYPE_H_
#define _DS_VIDEOOUTPUTPORTTYPE_H_

#include "dsConstant.hpp"
#include <string>

#include <vector>
#include <map>
#include <list>
#include <string>
#include "list.hpp"

#include "videoResolution.hpp"
#include "videoOutputPort.hpp"
#include "dsTypes.h"


/**
 * @file videoOutputPortType.hpp
 * @brief It contains structures and class referenced by the videoOutputportTypes.cpp file.
 */
namespace device {


/**
 * @class VideoOutputPortType
 * @brief Class extending DSConstant to implement the VideoOutputporttype interface.
 * @ingroup devicesettingsclass
 */
class VideoOutputPortType : public DSConstant {

	bool _dtcpSupported; //!< Method variable to check whether dtcp is supported or not.
	bool _hdcpSupported; //!< Method variable to check whether hdcp is supported o rnot.
	bool _dynamic; //!< Method variable to check whether dynamic resolution is supported or not.
	int  _restrictedResolution;
	List<VideoResolution> _supportedResolutions;
	List<VideoOutputPort> _vPorts;
	//std::map<VideoResolution , VideoResolution> _dynamicResolutionMappins;

public:
	static const int kRF;
	static const int kBaseband;
	static const int kSVideo;
	static const int k1394;
	static const int kDVI;
	static const int kComponent;
	static const int kHDMI;
	static const int kInternal;
	static const int kScart;
	static const int kMax;


	static VideoOutputPortType & getInstance(const int id);
	static VideoOutputPortType & getInstance(const std::string &name);


	VideoOutputPortType(const int id);
	virtual ~VideoOutputPortType();

	int  getTypeId() const;
	bool isDTCPSupported() const;
	bool isHDCPSupported() const;
	bool isDynamicResolutionsSupported() const;
	int getRestrictedResolution() const ;
	const List<VideoResolution>  getSupportedResolutions() const;
    const VideoResolution & getOutputResolution(const VideoResolution &inputResolution) const;
	const List<VideoOutputPort> getPorts() const;

	void enabledDTCP();
	void enabledHDCP(bool contentProtect = true, char *dhcpKey = 0, size_t keySize = 0);
	void setRestrictedResolution(int resolution);
	void addResolution(const VideoResolution &resolution);
	void addPort( const VideoOutputPort &port);

};

}

#endif /* VIDEOOUTPUTPORTTYPE_H_ */


/** @} */
/** @} */
