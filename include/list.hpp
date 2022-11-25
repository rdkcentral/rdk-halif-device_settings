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
 * @file list.hpp
 * @brief This file defines List class and implements it.
 */



/**
* @defgroup devicesettings
* @{
* @defgroup ds
* @{
**/


#ifndef _DS_LIST_HPP_
#define _DS_LIST_HPP_

#include <vector>

namespace device {

template <class T>

/**
 * @class List
 * @brief This class is implemented using templates and it is used to maintain
 * a container with the list of supported ID's.
 * @ingroup devicesettingsclass
 */
class List {
	typedef typename std::vector<int>::iterator iterator;  //!< An iterator for the container.

	std::vector <int> _container;   //!< Vector container for integers to maintain the id's.

	public:

/**
 * @fn List::List()
 * @brief This function is the default constructor of class List.
 *
 * @return None
 */
	List() {};

/**
 * @fn List::~List()
 * @brief This function is the default destructor of class List and is a virtual function.
 */
	virtual ~List() {};

/**
 * @fn List::at(size_t i)
 * @brief This is a template function to get the instance of the calling class against
 * the value at the position i of the container.
 *
 * @param[in] i Specifies the container index.
 *
 * @return Returns an instance of the class calling this function. The return value is
 * const and cannot be modified.
 */
	const T &  at(size_t i) const {
		return T::getInstance(_container.at(i));
	}

/**
 * @fn List::at(size_t i)
 * @brief This is a template function to get the instance of the calling class against
 * the value at the position i of the container.
 *
 * @param[in] i Specifies the container index.
 *
 * @return Returns an instance of the class calling this function.
 */
	T & at(size_t i) {
		return T::getInstance(_container.at(i));
	}

/**
 * @fn List::push_back(const T& x)
 * @brief This is a template function used to push/store the ID
 * of an instance x into the container.
 *
 * @param[in] x Indicates an instance whose ID needs to be stored.
 *
 * @return None
 */
	void push_back(const T& x) {
		_container.push_back(x.getId());
	}

/**
 * @fn List::size()
 * @brief This function gets the size of the container.
 *
 * @return Returns the size of the container.
 */
	size_t size() { return _container.size(); };

/**
 * @fn List::size()
 * @brief This function gets the size of the container.
 *
 * @return Returns the size of the container.
 */
	size_t size() const{ return _container.size(); };

};

}

#endif /* LIST_H_ */


/** @} */
/** @} */
