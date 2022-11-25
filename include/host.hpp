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


#ifndef _DS_HOST_HPP_
#define _DS_HOST_HPP_

#include <iostream>
#include "powerModeChangeListener.hpp"
#include "displayConnectionChangeListener.hpp"
#include "audioOutputPort.hpp"
#include "videoOutputPort.hpp"
#include "videoDevice.hpp"
#include "sleepMode.hpp"
#include  "list.hpp"

#include  <list>
#include <string>


/**
 * @file host.hpp
 * @brief It contains class,structures referenced by host.cpp file.
 */
using namespace std;

namespace device {


/**
 * @class Host
 * @brief Class to implement the Host interface.
 * @ingroup devicesettingsclass
 */
class Host {
public:
    static const int kPowerOn;
    static const int kPowerOff;
    static const int kPowerStandby;

	bool setPowerMode(int mode);
	int getPowerMode();
    SleepMode getPreferredSleepMode();
    int setPreferredSleepMode(const SleepMode);
    List <SleepMode> getAvailableSleepModes();
	void addPowerModeListener(PowerModeChangeListener *l);
    void removePowerModeChangeListener(PowerModeChangeListener *l);
    void addDisplayConnectionListener(DisplayConnectionChangeListener *l);
    void removeDisplayConnectionListener(DisplayConnectionChangeListener *l);

	static Host& getInstance(void);

    List<VideoOutputPort> getVideoOutputPorts();
    List<AudioOutputPort> getAudioOutputPorts();
    List<VideoDevice> getVideoDevices();
    VideoOutputPort &getVideoOutputPort(const std::string &name);
    VideoOutputPort &getVideoOutputPort(int handle);
    AudioOutputPort &getAudioOutputPort(const std::string &name);
    AudioOutputPort &getAudioOutputPort(int handle);
    void notifyPowerChange(const  int mode);
    float getCPUTemperature();
    uint32_t  getVersion(void);
    void setVersion(uint32_t versionNumber);
    void getHostEDID(std::vector<uint8_t> &edid) const;
    std::string getSocIDFromSDK();
    void getSinkDeviceAtmosCapability(dsATMOSCapability_t & atmosCapability);
    void setAudioAtmosOutputMode(bool enable);
    void setAssociatedAudioMixing(const bool mixing);
    void getAssociatedAudioMixing(bool *mixing);
    void setFaderControl(const int mixerbalance);
    void getFaderControl(int *mixerBalance);
    void setPrimaryLanguage(const std::string pLang);
    void getPrimaryLanguage(std::string &pLang);
    void setSecondaryLanguage(const std::string sLang);
    void getSecondaryLanguage(std::string &sLang);
    bool isHDMIOutPortPresent();
    std::string getDefaultVideoPortName();
    std::string getDefaultAudioPortName();
    void getCurrentAudioFormat(dsAudioFormat_t &audioFormat);

private:
	Host();
	virtual ~Host();
    //To Make the instance as thread-safe, using = delete, the result is, automatically generated methods (constructor, for example) from the compiler will not be created and, therefore, can not be called
    Host (const Host&)= delete;
    Host& operator=(const Host&)= delete;

    std::list < PowerModeChangeListener* > powerEvntListeners;
    std::list < DisplayConnectionChangeListener* > dispEvntListeners;
    void notifyDisplayConnectionChange(int portHandle, bool newConnectionStatus);
};

}

#endif /* _DS_HOST_HPP_ */


/** @} */
/** @} */
