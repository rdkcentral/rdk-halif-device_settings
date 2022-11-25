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
 * @file illegalArgumentException.hpp
 * @brief This file defines IllegalArgumentException class to handle exceptions
 * caused due to illegal argum.
 */



/**
* @defgroup devicesettings
* @{
* @defgroup ds
* @{
**/


#ifndef _DS_ILLEGALARGUMENTEXCEPTION_HPP_
#define _DS_ILLEGALARGUMENTEXCEPTION_HPP_

#include "exception.hpp"
#include <iostream>

namespace device {


/**
 * @class IllegalArgumentException
 * @brief This class extends Exception class to manage the expections caused due to
 * illegal arguments.
 * @ingroup devicesettingsclass
 */
class IllegalArgumentException : public device::Exception {
public:


/**
 * @fn IllegalArgumentException::IllegalArgumentException(const char *msg = "Illegal Argument")
 * @brief This function is a parameterised constructor of IllegalArgumentException class. It
 * initializes the instance with the message passed as input parameter.
 *
 * @param[in] msg Indicates the exception message string to be updated.
 *
 * @return None
 */
	IllegalArgumentException(const char *msg = "Illegal Argument") throw (): device::Exception(msg) {
	};


/**
 * @fn IllegalArgumentException::~IllegalArgumentException()
 * @brief This function is a default destructor of the class IllegalArgumentException.
 *
 * @return None
 */
	virtual ~IllegalArgumentException() throw(){};
};

}

#endif /* ILLEGALARGUMENTEXCEPTION_HPP_ */


/** @} */
/** @} */
