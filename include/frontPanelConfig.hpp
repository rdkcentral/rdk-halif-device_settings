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


#ifndef _DS_FRONTPANELCONFIG_HPP_
#define _DS_FRONTPANELCONFIG_HPP_

#include "frontPanelIndicator.hpp"
#include "frontPanelTextDisplay.hpp"

#include <string>


/**
 * @file frontPanelConfig.hpp
 * @brief Structures and classes to manage front panel are defined here.
 * @ingroup frontPanelConfig
 */
using namespace std;

namespace device {


/**
 * @class FrontPanelConfig
 * @brieif To manage front panel text display and indicators
 * @ingroup devicesettingsclass
 */
class FrontPanelConfig {
private:

    std::vector<FrontPanelIndicator> 			_indicators;    //!< Container to hold all the FrontPanelIndicator instances.
    std::vector<FrontPanelTextDisplay> 			_textDisplays;  //!< Container to hold all the FrontPanelTextDisplay instances.
    std::vector<FrontPanelIndicator::Color> 	_colors;                //!< Container to hold all the Color instances.

    FrontPanelConfig();
	virtual ~FrontPanelConfig();

	void load();

public:
	static FrontPanelConfig & getInstance();

	FrontPanelIndicator::Color &getColor(int id);
	FrontPanelIndicator 	   &getIndicator(int id);
	FrontPanelTextDisplay 	   &getTextDisplay(int id);

	FrontPanelIndicator::Color &getColor(const string &name);
	FrontPanelIndicator 	   &getIndicator(const string &name);
	FrontPanelTextDisplay 	   &getTextDisplay(const string &name);

	List<FrontPanelIndicator::Color> getColors();
	List<FrontPanelIndicator> 		 getIndicators();
	List<FrontPanelTextDisplay> 	 getTextDisplays();

        /* Initialize Front Panel */
        void fPInit();
        /* Terminate Front Panel */
        void fPTerm();

};

}

#endif /* _DS_FRONTPANELCONFIG_HPP_ */


/** @} */
/** @} */
