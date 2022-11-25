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
 * @file dsConstant.hpp
 * @brief This file defines DSConstant class which is inherited by most of
 * the device settings classes.
 */


/**
* @defgroup devicesettings
* @{
* @defgroup ds
* @{
**/


#ifndef DSCONSTANTS_HPP_
#define DSCONSTANTS_HPP_

#include "enumerable.hpp"
#include <string>
namespace device {


/**
 * @class DSConstant
 * @brief This class is used to store and manage the names and id's. It is derived
 * by many classes like VideoResolution, VideoOutputPortType, stereoScopicMode and so on.
 * And it is also stores information whether the derived class instances indicating the port
 * or port attributes are enabled or not.
 * @ingroup devicesettingsclass
 */
class DSConstant : public Enumerable  {
private:
	bool enabled;   //!< Indicates the port or port attributes inheriting this class is enabled or not.

protected:
	int _id;        //!< Indicates the id of the instance inheriting this class.
	std::string _name;   //!< Indicates the name string of the instance inheriting this class.


/**
 * @fn DSConstant::isValid(int min, int max, int val)
 * @brief This function checks if the given value lies between min and max values provided.
 *
 * @param[in] min Indicates the minimum value for comparison.
 * @param[in] max Indicates the maximum value for comparison.
 * @param[in] val Indicates the value to be compared with minimum and maximum value.
 *
 * @return Returns true(1) if the specified val lies in between min and max values else returns
 * false(0)
 */
	static bool isValid(int min, int max, int val) {
		return (val >= min && val < max);
	}

public:

/**
 * @fn DSConstant::DSConstant()
 * @brief This function is the default constructor for DSConstant. It initializes the DSConstant
 * instance with default values.
 *
 * @return None
 */
	DSConstant() : enabled(false), _id(0), _name("_UNASSIGNED NAME_"){};


/**
 * @fn DSConstant::DSConstant(const int id, const std::string &name)
 * @brief This function is a parameterised constructor for DSConstant. It initializes the DSConstant
 * instance with the values passed as input parameter.
 *
 * @param[in] id Indicates the id.
 * @param[in] name Indicates the name string.
 *
 * @return None.
 */
	DSConstant(const int id, const std::string &name) : enabled(false), _id(id), _name(name){};


/**
 * @fn DSConstant::~DSConstant()
 * @brief This function is the default destructor for DSConstant.
 *
 * @return None
 */
	virtual ~DSConstant() {};


/**
 * @fn DSConstant::operator==(int id)
 * @brief This function is an operator overloading for == operator. It checks if the id of
 * DSConstant instance is equal to the id passed as input parameter.
 *
 * @param[in] id Indicates the value to be compared against the id of the instance.
 *
 * @return Returns true(1) if the values compared are same else returns false(0).
 */
	virtual bool operator==(int id) const {
		return id == _id;
	}


/**
 * @fn DSConstant::getId()
 * @brief This function is used to get the id.
 *
 * @return _id Returns the id.
 */
	virtual int getId() const {
		return _id;
	};


/**
 * @fn DSConstant::getName()
 * @brief This function is used to the get the data member name.
 *
 * @return _name Returns the name string.
 */
	virtual const std::string & getName() const {
		return _name;
	}


/**
 * @fn DSConstant::toString()
 * @brief This function is used to the get the data member name in string format.
 *
 * @return _name Returns the name string.
 */
	virtual const std::string & toString() const {
		return _name;
	}


/**
 * @fn DSConstant::enable()
 * @brief This function is used to indicate that the port or port attribute calling this function
 * are enabled.
 *
 * @return None
 */
	void enable() {
		enabled = true;
	}


/**
 * @fn DSConstant::isEnabled()
 * @brief This function is used to check if the calling object is enabled or not. The calling
 * object can be an instance of video output port or audio output port or their attributes.
 *
 * @return Returns true if data member enabled is set to true else returns false.
 */
	bool isEnabled() const{
		return enabled;
	}

};

}

#endif /* DSCONSTANT_HPP_ */


/** @} */
/** @} */
