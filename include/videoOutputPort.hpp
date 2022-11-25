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


#ifndef _DS_VIDEOOUTPUTPORT_H_
#define _DS_VIDEOOUTPUTPORT_H_

#include "enumerable.hpp"
#include "aspectRatio.hpp"
#include <string>
#include <vector>
#include <stdint.h>

#include "dsTypes.h"

/**
 * @file videoOutputPort.hpp
 * @brief It contains class and structure refrenced by the videooutputport.cpp file.
 */
using namespace std;

namespace device {
class VideoOutputPortType;
class AudioOutputPort;
class VideoResolution;


/**
 * @class VideoOutputPort
 * @brief Class extending enumerable to implement the videoooutputport interface.
 * @ingroup devicesettingsclass
 */
class  VideoOutputPort : public Enumerable {
	int _type; //!< VideooOtputPortType
	int _index; //!< Index of the video
	int  _id; //!< Port id.

	int _handle;
	std::string _name;

	bool _enabled; //!< Method variable to check whether VideoPort is enabled or not.
	bool _contentProtected; //!< Method variable tO check whether videoport is content protected or not.
	bool _displayConnected; //!< Method variable to check whether the video display is connected or not.
	int _aPortId;

	std::string _defaultResolution;
	std::string _resolution;

	static const char * kPropertyResolution;


public:

    class Display {
    	friend class VideoOutputPort;
    	 int _handle;
    	 int _productCode; //!< Product code of the EDID video display device.
    	 int _serialNumber; //!< Serial number of the EDID video display device.
    	 int _manufacturerYear; //!< Year of manufacture of the EDID video display device.
    	 int _manufacturerWeek; //!< Week of manufacture of the EDID video display device.
    	 int _aspectRatio;
		 bool _hdmiDeviceType;
		 bool _isSurroundCapable;
		 bool _isDeviceRepeater;
		 uint8_t _physicalAddressA; //!<  Physical Address for HDMI node A
		 uint8_t _physicalAddressB; //!< Physical Address for HDMI node B
		 uint8_t _physicalAddressC; //!<  Physical Address for HDMI node C
		 uint8_t _physicalAddressD; //!<  Physical Address for HDMI node D
    public:


/**
 * @fn Display()
 * @brief This function is default constructor and it is used to initialize the display handle
 * and EDID information of the video display with the default values.
 *
 * @return None.
 */
    	Display() :_handle(0), _productCode(0), _serialNumber(0), _manufacturerYear(0), _manufacturerWeek(0),_aspectRatio(0),_hdmiDeviceType(true), _isSurroundCapable(false), _isDeviceRepeater(false),
		_physicalAddressA(1),_physicalAddressB(0),_physicalAddressC(0),_physicalAddressD(0){};
    	Display(VideoOutputPort &vPort);
    	virtual ~Display();


/**
 * @fn int getProductCode() const
 * @brief This function returns the product code of the EDID video display device.
 *
 * @retval _productCode Product code of the display device.
 */
    	int getProductCode() const {return _productCode;};


/**
 * @fn int getSerialNumber() const
 * @brief This function returns the serial number of the EDID video display device.
 *
 * @retval _serialNumber Serial number of the display device.
 */
    	int getSerialNumber() const {return _serialNumber;};


/**
 * @fn int getManufacturerYear() const
 * @brief This function returns the year of manufacture of the EDID video display device.
 *
 * @retval _manufacturerYear Year of manufacture of the display device.
 */
    	int getManufacturerYear() const {return _manufacturerYear;};


/**
 * @fn int getManufacturerWeek() const
 * @brief This function returns the week of manufacture of the EDID video display device.
 *
 * @retval _manufacturerWeek Week of manufacture of the display device.
 */
    	int getManufacturerWeek() const {return _manufacturerWeek;};


/**
 * @fn int getConnectedDeviceType() const
 * @brief This function returns the device type of the EDID video display device.
 *
 * @return _hdmiDeviceType
 * @retval True If device type is HDMI.
 * @retval False If device type is DVI.
 */
        int getConnectedDeviceType() const {return _hdmiDeviceType;};
        bool isConnectedDeviceRepeater() const {return _isDeviceRepeater;};
        void getEDIDBytes(std::vector<uint8_t> &edid) const;

/**
 * @fn int hasSurround() const
 * @brief This function returns true if connected display supports surround audio 
 *
 * @retval true/false 
 */
        bool hasSurround() const;

/**
 * @fn int getSurroundMode() const
 * @brief This function returns surround mode supported by connected display
 *
 * @retval int
 */
        int getSurroundMode() const;


/**
 * @fn const AspectRatio& getAspectRatio()
 * @brief This function returns the instance of the aspect ratio that is used currently in connected display device.
 *
 * @return _aspectRatio Indicates the aspect ration of the videooutputport.
 */
    	const AspectRatio& getAspectRatio() const {return AspectRatio::getInstance(_aspectRatio);};


/**
 * @fn void getPhysicallAddress(uint8_t &physicalAddressA,uint8_t &physicalAddressB,uint8_t &physicalAddressC,uint8_t &physicalAddressD) const
 * @brief This function gets the physical address of the HDMI node of the video display device.
 *
 * @param[out] physicalAddressA Physical Address for HDMI node A
 * @param[out] physicalAddressB Physical Address for HDMI node B
 * @param[out] physicalAddressC Physical Address for HDMI node C
 * @param[out] physicalAddressD Physical Address for HDMI node D
 *
 * @return None.
 */
		void getPhysicallAddress(uint8_t &physicalAddressA,uint8_t &physicalAddressB,uint8_t &physicalAddressC,uint8_t &physicalAddressD) const
		{physicalAddressA = _physicalAddressA;physicalAddressB = _physicalAddressB;
		 physicalAddressC = _physicalAddressC;physicalAddressD = _physicalAddressD;};
    };

 	static VideoOutputPort & getInstance(int id);
 	static VideoOutputPort & getInstance(const std::string &name);
 	VideoOutputPort(const int type, const int index, const int id, int audioPortId, const std::string &resolution);
	virtual ~VideoOutputPort();

	const VideoOutputPortType &getType() const;


/**
 * @fn int getId()
 * @brief This function returns the video output port id.
 *
 * @return id Video Output port id.
 */
 	int getId() const {return _id; };


/**
 * @fn VideoOutputPort::getName() const
 * @brief This API gets the name of the VideoOutputPort. The VideoOutputPort names can be HDMI, RF, Component etc...
 * which are created and used by the implementation to uniquely identify them
 *
 * @return _name Indicates the name of the VideoOutputPort
 */
 	const std::string &getName() const {return _name;};


/**
 * @fn int getIndex()
 * @brief This function returns the index of the video output port.
 *
 * @return index Index of the video output port.
 */
	int getIndex() const {return _index; };

	AudioOutputPort &getAudioOutputPort();
	const VideoResolution &getResolution() ;
	const VideoResolution &getDefaultResolution() const;

    	const VideoOutputPort::Display &getDisplay();
	bool isDisplayConnected() const;
	bool isContentProtected() const;
	bool isEnabled() const;
	bool isActive() const;
	bool isDynamicResolutionSupported() const;


/**
 * @fn void setAudioPort(int id)
 * @brief This function set the audio output port id.
 *
 * @param[in] id Audio Output port id.
 * @return None.
 */
	void setAudioPort(int id) { _aPortId = id; };
	void setResolution(const std::string &resolution, bool persist = true, bool isIgnoreEdid=false);
	void setDisplayConnected(const bool connected);
	void enable();
	void disable();
	int getHDCPStatus();
	int getHDCPProtocol();
	int getHDCPReceiverProtocol();
	int getHDCPCurrentProtocol();
	void getTVHDRCapabilities(int *capabilities) const;
	void getSupportedTvResolutions(int *resolutions) const;
	int forceDisable4KSupport(bool disable);
	bool setForceHDRMode(dsHDRStandard_t status);
        bool IsOutputHDR();
        void ResetOutputToSDR();
        bool SetHdmiPreference(dsHdcpProtocolVersion_t hdcpProtocol);
        int GetHdmiPreference();

	bool setScartParameter(const std::string parameter, const std::string value);
	int getVideoEOTF() const;
	int getMatrixCoefficients() const;
	int getColorSpace() const;
	int getColorDepth() const;
        int getQuantizationRange() const;
        void getCurrentOutputSettings(int &videoEOTF, int &matrixCoefficients, int &colorSpace, int &colorDepth, int &quantizationRange) const;
	const unsigned int getPreferredColorDepth(bool persist = true) ;
	void setPreferredColorDepth(const unsigned int colordepth, bool persist = true);
	void getColorDepthCapabilities (unsigned int *capabilities) const;

private:
	Display _display;


};

}

#endif /* _DS_VIDEOOUTPUTPORT_H_ */


/** @} */
/** @} */
