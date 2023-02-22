//
//  IService.h
//  NemaTode
//
//  Created by Artem Pyatyshev on 21/02/2023.
//

#ifndef IService_h
#define IService_h

#include <nmeaparse/GPSFix.h>
#include <nmeaparse/Event.h>

namespace nmea {

class NMEASentence;
class NMEAParser;

class IService {
protected:

    IService(const std::string &prefix);
    
    void read_PSRF150(const NMEASentence& nmea);
    void read_XXGGA    (const NMEASentence& nmea);
    void read_XXGSA    (const NMEASentence& nmea);
    void read_XXGSV    (const NMEASentence& nmea);
    void read_XXRMC    (const NMEASentence& nmea);
    void read_XXVTG    (const NMEASentence& nmea);
    void read_XXGST    (const NMEASentence& nmea);
    
    std::string getTag(const std::string &tag) const ;

    std::string m_prefix;
public:
    GPSFix fix;

//    GPSService(NMEAParser& parser);
//    virtual ~GPSService();
//
    Event<void(bool)> onLockStateChanged;        // user assignable handler, called whenever lock changes
    Event<void()> onUpdate;                        // user assignable handler, called whenever fix changes
//
    void attachToParser(NMEAParser& parser);            // will attach to this parser's nmea sentence events
};


}

#endif /* IService_h */
