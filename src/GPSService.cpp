/*
 * GPSService.cpp
 *
 *  Created on: Aug 14, 2014
 *      Author: Cameron Karlsson
 *
 *  See the license file included with this source.
 */


#include <nmeaparse/GPSService.h>
#include <nmeaparse/NumberConversion.h>

#include <string>
#include <chrono>
#include <functional>
#include <iostream>
#include <cmath>

using namespace std::chrono;

using namespace nmea;

// ------------- GPSSERVICE CLASS -------------




GPSService::GPSService(NMEAParser& parser) : IService("GP") {
	attachToParser(parser);		// attach to parser in the GPS object
}

GPSService::~GPSService() {
	// TODO Auto-generated destructor stub
}
