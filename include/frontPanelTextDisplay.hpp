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


#ifndef _DS_FRONTPANELTEXTDISPLAY_HPP_
#define _DS_FRONTPANELTEXTDISPLAY_HPP_

#include "dsConstant.hpp"
#include "list"
#include "frontPanelIndicator.hpp"


/**
 * @file frontPanelTextDisplay.hpp
 * @brief Classes and structures for front panel text display are defined here.
 * @ingroup frontPanelTextDisplay
 */
using namespace std;

namespace device {


/**
 * @class FrontPanelTextDisplay
 * @brief This class extents FrontPanelIndicator to manage front panel text display mode,
 * scrolling and its brightness.
 * @ingroup devicesettingsclass
 */
class FrontPanelTextDisplay : public FrontPanelIndicator {
public:


/**
 * @class FrontPanelTextDisplay::Mode
 * @brief This class extents DSConstant to mange the front panel text display mode like time display mode or text display mode etc...
 * @ingroup devicesettingsclass
 */
    class Mode : public DSConstant{
    public:
        Mode (int id);
        ~Mode ();
    };


/**
 * @class FrontPanelTextDisplay::Scroll
 * @brief To manage front panel text display scrolling.
 * @ingroup devicesettingsclass
 */
    class Scroll {
        int _vIterations;   //!< Indicates vertical iterations of scrolling for text display.
        int _hIterations;   //!< Indicates horizontal iterations of scrolling for text display.
        int _holdDuragion;  //!< Indicates the hold duration for LED while scrolling.
    public:


/**
 * @fn FrontPanelTextDisplay::Scroll::Scroll (int vIterations = 0, int hIterations = 0, int holdDuration = 0)
 * @brief This function is a parameterised constructor of Scroll class. It initializes the scroll parameters
 * with the specified values. If the values are not passed then it sets the scroll parameters of the instance
 * to 0.
 *
 * @param[in] vIterations Indicates the vertical iterations for scrolling.
 * @param[in] hIterations Indicates the horizontal iterations for scrolling.
 * @param[in] holdDuration Indicates the hold duration of LED while scrolling.
 *
 * @return None
 */
        Scroll (int vIterations = 0, int hIterations = 0, int holdDuration = 0) {
                _vIterations = vIterations;
                _hIterations = hIterations;
                _holdDuragion = holdDuration;
        }


/**
 * @fn FrontPanelTextDisplay::Scroll::getVerticalIteration() const
 * @brief This API gets the vertical iterations for front panel text display scrolling
 *
 * @return _vIterations Indicates the vertical iterations for scrolling
 */
        int getVerticalIteration() const {return _vIterations;};


/**
 * @fn FrontPanelTextDisplay::Scroll::getHorizontalIteration() const
 * @brief This API gets the horizontal iterations for front panel text display scrolling
 *
 * @return _hIterations Indicates the horizontal iterations for scrolling
 */
        int getHorizontalIteration() const {return _hIterations;};


/**
 * @fn FrontPanelTextDisplay::Scroll::getHoldDuration() const
 * @brief This API gets the hold duration for front panel text display scrolling
 *
 * @return _holdDuragion Indicates the hold duration for scrolling
 */
        int getHoldDuration() const {return _holdDuragion;};
    };

private:
    Scroll _scroll;              //!< Indicates scroll properties.
    int _timeFormat;             //!< Indicates time format for the clock display.
    int _TextBrightness;         //!< Indicates text brightness.
    static const char * kPropertyBrightness;

public:
    static const int kModeClock12Hr;  //!< Indicates 12 hour time format.
    static const int kModeClock24Hr;  //!< Indicates 24 hour time format.
    static const int kModeString;     //!< Indicates text string.
    static FrontPanelTextDisplay & getInstance(int id);
    static FrontPanelTextDisplay & getInstance(const string &name);

    int getTextBrightness();
    void getTextBrightnessLevels(int &levels, int &min, int &max);
    int getTextColorMode();
    void setTextBrightness(const int &brightness);
    void enableDisplay(const int enable);


/**
 * @fn Scroll getScroll() const
 * @brief This API gets the scroll parameters for front panel display like vertical & horizontal iterations and hold duration
 *
 * @return _scroll Returns scroll parameters for front panel display
 */
    const Scroll getScroll() const {return _scroll;};


/**
 * @fn getCurrentTimeFormat () 
 * @brief  This API gets the currently set time format for front panel display
 *
 * @return _timeFormat Indicates the time format
 * @retval 0 Indicates 12hr format
 * @retval 1 Indicates 24hr format
 */
    int getCurrentTimeFormat ()  ;

    void setScroll(const Scroll & scroll);
    void setText(const std::string &text);
    void setTimeFormat(const int iTimeFormat);
    void setTime(const int uiHours, const int uiMinutes);


/**
 * @fn setMode(int mode)
 * @brief This API sets the display mode of the LED display to any, text only or clock only.
 *
 * @param[in] mode Indicates display mode.
 * <ul>
 * <li>  0 indicates both text and clock are supported (default mode).
 * <li>  1 indicates only text mode is supported (trying to set clock results in no change).
 * <li>  2 indicates only clock mode is supported (trying to set text results in no change).
 * </ul>
 *
 * @return None
 */
    void setMode(int mode);


    FrontPanelTextDisplay(int id, int maxBrightness, int maxCycleRate, int levels,
                          int maxHorizontalIterations, int maxVerticalIterations,
                          const std::string &supportedCharacters,int colorMode);

    virtual ~FrontPanelTextDisplay();


};

}

#endif /* _DS_FRONTPANELTEXTDISPLAY_HPP_ */


/** @} */
/** @} */
