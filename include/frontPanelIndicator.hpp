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


#ifndef _DS_FRONTPANELINDICATOR_HPP_
#define _DS_FRONTPANELINDICATOR_HPP_

#include "dsConstant.hpp"
#include "list.hpp"
#include "frontPanelIndicator.hpp"
#include "dsTypes.h"
#include "dsFPD.h"
#include <string>
#include "dsUtl.h"


/**
 * @file frontPanelIndicator.hpp
 * @brief Structures and classes for front panel indicator are defined here
 * @ingroup frontPanelIndicator
 */
namespace device {


/**
 * @class FrontPanelIndicator
 * @brief This class extents DSConstant to manage front panel indicators color, blink sequence
 * and brightness.
 * @ingroup devicesettingsclass
 */
class FrontPanelIndicator  : public DSConstant {

public:
	static FrontPanelIndicator & getInstance(int id);
	static FrontPanelIndicator & getInstance(const std::string &name);


/**
 * @class FrontPanelIndicator::Color
 * @brief This class extents DSConstant to manage the color of the front panel indicator
 * @ingroup devicesettingsclass
 */
    class Color : public DSConstant {
      public:
        static const int kBlue;    //!< Indicates RGB value of blue color.
        static const int kGreen;   //!< Indicates RGB value of green color.
        static const int kRed;     //!< Indicates RGB value of red color.
        static const int kYellow;  //!< Indicates RGB value of yellow color.
        static const int kOrange;  //!< Indicates RGB value of orange color.
        static const int kWhite;   //!< Indicates RGB value of white color.
        static const int kMax;     //!< Indicates maximum number of pre-defined colors.

    	static const Color & getInstance(int id);
    	static const Color & getInstance(const std::string &name);

        Color(int id);

/**
 * @fn FrontPanelIndicator::Color::~Color()
 * @brief This function is the default destructor of class Color.
 *
 * @return None
 */
        virtual ~Color() {};
    };


/**
 * @class FrontPanelIndicator::Blink
 * @brief This class supports to manage front panel indicator blink sequence.
 * @ingroup devicesettingsclass
 */
    class Blink {
        int _interval;    //!< Indicates the blink interval for front panel indicators.
        int _iteration;   //!< Indicates the blink iteration for front panel indicators.
    public:
        Blink(int interval = 0, int iteration = 0);

/**
 * @fn FrontPanelIndicator::Blink::~Blink()
 * @brief This function is the default destructor of Blink class.
 *
 * @return None
 */
        virtual ~Blink() {};


/**
 * @fn FrontPanelIndicator::Blink::getInterval() const
 * @brief This API is used to get the blink intervals of front panel indicator
 *
 * @return _interval Indicates the blink intervals
 */
        int getInterval() const {return _interval;};


/**
 * @fn FrontPanelIndicator::Blink::getIteration() const
 * @brief This API is used to get the blink iterations of front panel indicator
 *
 * @return _iteration Indicates the blink iterations
 */
        int getIteration() const {return _iteration;};

    };

protected:
    int _maxBrightness;   //!< Indicates maximum brightness value for the FP indicators.
    int _maxCycleRate;    //!< Indicates maximum cycle rate for scrolling of LED.
    int _brightness;      //!< Indicates the brightness of the LED indicator.
    int _levels;          //!< Indicates the brightness level.
    int _colorMode;       //!< Indicates the color mode of the LED indicator (single or multicolor mode).
    int _state;           //!< Indicates the FP indicator is enabled if true.
    Blink _blink;         //!< A Blink instance to control blink iterations and intervals of the LED.
    int _color;
    uint32_t _color_rgb32; //!< Indicates the color id of the LED.

    static const char * kPropertyBrightness;
    static const char * kPropertyColor;

public:

    static const int kMessage;  //!< Indicates id of meassage LED.
    static const int kPower;    //!< Indicates id of power LED.
    static const int kRecord;   //!< Indicates id of record LED.
    static const int kRemote;   //!< Indicates id of remote LED.
    static const int kRFBypass; //!< Indicates id of RF bypass LED.
    static const int kMax;      //!< Indicates the maximum number of LEDS supported.

    int getBrightness();
    void getBrightnessLevels(int &levels, int &min, int &max);
    int getColorMode();


/**
 * @fn Blink getBlink() const
 * @brief This API gets the blink parameters of the front panel display like iterations and interval
 *
 * @param[out] _blink Is filled with the blink parameters set for front panel display
 *
 * @return None
 */
    const Blink getBlink() const {return _blink;};


/**
 * @fn getMaxCycleRate() const
 * @brief This API get the rate at which the LED is rotating/glowing during scrolling
 *
 * @return _maxCycleRate Returns the rate at which LED is rotating/glowing during scrolling
 */
	int getMaxCycleRate() const {return _maxCycleRate;};
    void setBlink(const Blink &blink);
    uint32_t getColor();


    /*Old FP 1/2/3 APIs. - For Backward compatibility */
    void setBrightness(const int &brightness,const bool toPersist = true);
    void setColor(const Color & newColor,const bool toPersist = true);
    
    
    /* Fp4 APIS - set rgb color value*/
     void setColor(const uint32_t color,const bool toPersist = true);
    
    /* we still need this API to toggle the LED Power i.e Remote/Power */
    void setState(const bool &enable);
    /* Get LED ON/OFF state */
    bool getState();

    const List<Color> getSupportedColors() const;;
    FrontPanelIndicator(int id, int maxBrightness, int maxCycleRate, int levels,int colorMode);
    virtual ~FrontPanelIndicator();
};

}

#endif /* _DS_FRONTPANELINDICATOR_HPP_ */


/** @} */
/** @} */
