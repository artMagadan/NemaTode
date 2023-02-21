/*
 * NumberConversion.h
 *
 *  Created on: Aug 14, 2014
 *      Author: Cameron Karlsson
 *
 *  See the license file included with this source.
 */

#pragma once


#include <cstdint>
#include <string>
#include <sstream>
#include <exception>


namespace nmea {

class NumberConversionError : public std::exception {
public:
	std::string message;
	NumberConversionError(std::string msg):std::exception(),message(msg)
	{};

	virtual ~NumberConversionError(){};

    virtual const char* what() const noexcept override{
        return message.c_str();
    }
};




double parseDouble(std::string s);
int64_t parseInt(std::string s, int radix = 10);

//void NumberConversion_test();

}
