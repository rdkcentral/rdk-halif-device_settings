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
 * @file enumerable.hpp
 * @brief This file defines Enumerable class.
 */



/**
* @defgroup devicesettings
* @{
* @defgroup ds
* @{
**/


#ifndef _DS_ENUMERABLE_HPP_
#define _DS_ENUMERABLE_HPP_

namespace device {

/**
 * @class Enumerable
 * @brief This class is inherited by many classes in DS for getting the ID.
 * @ingroup devicesettingsclass
 */
class Enumerable {

/**
 * @fn Enumerable::getId()
 * @brief This function is used to get the id and it is
 * implemented by the classes inheriting it.
 *
 * @return Returns id value.
 */
	int getId() const;
};

}

#endif /* _DS_ENUMERABLE_HPP_ */


/** @} */
/** @} */
