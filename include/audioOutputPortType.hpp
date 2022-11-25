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


#ifndef _DS_AUDIOOUTPUTPORTTYPE_H_
#define _DS_AUDIOOUTPUTPORTTYPE_H_

#include <vector>
#include <list>

#include "dsConstant.hpp"
#include "audioEncoding.hpp"
#include "audioCompression.hpp"
#include "audioStereoMode.hpp"
#include "audioOutputPort.hpp"
#include <string>


/**
 * @file audioOutputPortType.hpp
 * @brief It contain variables,stuctures,class and functions referenced by audiooutputportType code.
 */

namespace device {


/**
 * @class  AudioOutputPortType
 * @brief Class extending DSConstant to implement the audiooutputport interface.
 * @ingroup devicesettingsclass
 */
class AudioOutputPortType : public DSConstant {

private:
	List<AudioEncoding>    _encodings; //!< List of encoding types.
	List<AudioCompression> _compressions; //!< List of compression types.
	List<AudioStereoMode>  _stereoModes; //!< List of stereo modes.
    List<AudioOutputPort>  _aPorts; //!< List of audio ports.

public:
	static const int kIDLR;
	static const int kHDMI;
	static const int kSPDIF;
        static const int kSPEAKER;
	static const int kARC;
	static const int kHEADPHONE;    

	static AudioOutputPortType & getInstance(int id);
	static AudioOutputPortType & getInstance(const std::string &name);

	AudioOutputPortType(int id);
	virtual ~AudioOutputPortType();

	const List<AudioEncoding> getSupportedEncodings() const;
	const List<AudioCompression> getSupportedCompressions() const;
	const List<AudioStereoMode> getSupportedStereoModes() const;
	const List<AudioOutputPort> getPorts() const;
	AudioOutputPort &getPort(int index);

	void addEncoding(const AudioEncoding & encoding);
	void addCompression(const AudioCompression & compression);
	void addStereoMode(const AudioStereoMode & stereoMode);
	void addPort(const AudioOutputPort & port);
	bool isModeSupported(int newMode);

};
}

#endif /* AUDIOOUTPUTPORTTYPE_H_ */


/** @} */
/** @} */
