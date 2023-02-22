//
//  GNSService.h
//  NemaTode
//
//  Created by Artem Pyatyshev on 22/02/2023.
//

#ifndef GNSService_h
#define GNSService_h

#include <nmeaparse/IService.h>
#include <nmeaparse/NMEAParser.h>


namespace nmea {

class GNSService : public IService {
public:
    
    GNSService(NMEAParser& parser);
    virtual ~GNSService();
};


}

#endif /* GNSService_h */
