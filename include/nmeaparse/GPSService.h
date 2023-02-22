/*
 * GPSService.h
 *
 *  Created on: Aug 14, 2014
 *      Author: Cameron Karlsson
 *
 *  See the license file included with this source.
 */

#ifndef GPSSERVICE_H_
#define GPSSERVICE_H_

#include <nmeaparse/IService.h>
#include <nmeaparse/NMEAParser.h>

namespace nmea {

class GPSService : public IService {
public:
    
	GPSService(NMEAParser& parser);
	virtual ~GPSService();
};


}

#endif /* GPSSERVICE_H_ */
