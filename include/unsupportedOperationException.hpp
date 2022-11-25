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
 * @file unsupportedOperationException.hpp
 * @brief This file defines UnsupportedOperationException class.
 */



/**
* @defgroup devicesettings
* @{
* @defgroup ds
* @{
**/


#ifndef _DS_UNSUPPORTEDOPERATIONEXCEPTION_HPP_
#define _DS_UNSUPPORTEDOPERATIONEXCEPTION_HPP_

#include "exception.hpp"
#include <iostream>

namespace device {


/**
 * @class UnsupportedOperationException
 * @brief This class extends Exception class to manage unsupported operations in devicesettings.
 * @ingroup devicesettingsclass
 */
class UnsupportedOperationException : public Exception {
public:

/**
 * @fn UnsupportedOperationException::UnsupportedOperationException(const char *msg = "Unsupported operation")
 * @brief This function is the default constructor of UnsupportedOperationException class. It creates an exception
 * with the message passed as input.
 *
 * @param[in] msg Indicates the message string with which exception needs to be thrown.
 *
 * @return None
 */
	UnsupportedOperationException(const char *msg = "Unsupported operation") throw (): Exception(msg) {};


/**
 * @fn UnsupportedOperationException::~UnsupportedOperationException()
 * @brief This function is the default destructor of UnsupportedOperationException class.
 *
 * @return none
 */
	virtual ~UnsupportedOperationException() throw() {};
};

}

#endif /* UNSUPPORTEDOPERATIONEXCEPTION_HPP_ */


/** @} */
/** @} */
