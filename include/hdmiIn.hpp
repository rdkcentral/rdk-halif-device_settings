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

/*
 * If not stated otherwise in this file or this component's Licenses.txt file the
 * following copyright and licenses apply:
 *
 * Copyright ARRIS Enterprises, Inc. 2015.
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
 * limitations under
*/


/**
* @defgroup devicesettings
* @{
* @defgroup ds
* @{
**/


#ifndef _DS_HDMIIN_HPP_
#define _DS_HDMIIN_HPP_

#include <stdint.h>
#include <vector>

#include "dsTypes.h"
/**
 * @file hdmiIn.hpp
 * @brief Structures and classes for HDMI Input are defined here
 * @ingroup hdmiIn
 */

static const int8_t HDMI_IN_PORT_NONE = -1;

namespace device 
{


/**
 * @class HdmiInput
 * @brief This class manages HDMI Input
 */
class HdmiInput  
{

public:
    static HdmiInput & getInstance();

    uint8_t getNumberOfInputs        () const;
    bool    isPresented              () const;
    bool    isActivePort             (int8_t Port) const;
    int8_t  getActivePort            () const;
    bool    isPortConnected          (int8_t Port) const;
    void    selectPort               (int8_t Port) const;
    void    scaleVideo               (int32_t x, int32_t y, int32_t width, int32_t height) const;
    void    selectZoomMode           (int8_t zoomMode) const;
    void    pauseAudio               () const;
    void    resumeAudio              () const;
    std::string  getCurrentVideoMode () const;
    void getCurrentVideoModeObj (dsVideoPortResolution_t& resolution);
    void getEDIDBytesInfo (int iHdmiPort, std::vector<uint8_t> &edid) const;
    void getHDMISPDInfo (int iHdmiPort, std::vector<uint8_t> &data);
    void setEdidVersion (int iHdmiPort, int iEdidVersion);
    void getEdidVersion (int iHdmiPort, int *iEdidVersion);
    void getHdmiALLMStatus (int iHdmiPort, bool *allmStatus);
    void getSupportedGameFeatures (std::vector<std::string> &featureList);

private:
    HdmiInput ();           /* default constructor */
    virtual ~HdmiInput ();  /* destructor */
};


}   /* namespace device */


#endif /* _DS_HDMIIN_HPP_ */


/** @} */
/** @} */
