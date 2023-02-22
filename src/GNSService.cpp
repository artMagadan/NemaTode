//
//  GNSService.cpp
//  NemaTode
//
//  Created by Artem Pyatyshev on 22/02/2023.
//

#include <nmeaparse/GNSService.h>
#include <nmeaparse/NumberConversion.h>

#include <string>
#include <chrono>
#include <functional>
#include <iostream>
#include <cmath>

using namespace std::chrono;

using namespace nmea;

// ------------- GPSSERVICE CLASS -------------




GNSService::GNSService(NMEAParser& parser) : IService("GN") {
    attachToParser(parser);        // attach to parser in the GPS object
}

GNSService::~GNSService() {
    // TODO Auto-generated destructor stub
}

//void GNSService::attachToParser(NMEAParser& _parser){
//
//
//    // http://www.gpsinformation.org/dale/nmea.htm
//    /* used sentences...
//    $GPGGA        - time,position,fix data
//    $GPGSA        - gps receiver operating mode, satellites used in position and DOP values
//    $GPGSV        - number of gps satellites in view, satellite ID, elevation,azimuth, and SNR
//    $GPRMC        - time,date, position,course, and speed data
//    $GPVTG        - course and speed information relative to the ground
//    $GPZDA        - 1pps timing message
//    $PSRF150    - gps module "ok to send"
//    */
//    _parser.setSentenceHandler("PSRF150", [this](const NMEASentence& nmea){
//        this->read_PSRF150(nmea);
//    });
//    _parser.setSentenceHandler("GPGGA", [this](const NMEASentence& nmea){
//        this->read_GPGGA(nmea);
//    });
//    _parser.setSentenceHandler("GPGSA", [this](const NMEASentence& nmea){
//        this->read_GPGSA(nmea);
//    });
//    _parser.setSentenceHandler("GPGSV", [this](const NMEASentence& nmea){
//        this->read_GPGSV(nmea);
//    });
//    _parser.setSentenceHandler("GPRMC", [this](const NMEASentence& nmea){
//        this->read_GPRMC(nmea);
//    });
//    _parser.setSentenceHandler("GPVTG", [this](const NMEASentence& nmea){
//        this->read_GPVTG(nmea);
//    });
//
//}
//
//
//void GNSService::read_GPGGA(const NMEASentence& nmea){
//    /* -- EXAMPLE --
//    $GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47
//
//    $GPGGA,205630.945,3346.1070,N,08423.6687,W,0,03,,30.8,M,-30.8,M,,0000*73        // ATLANTA!!!!
//    */
//    this->read_XXGGA(nmea);
//}
//
//void GNSService::read_GPGSA(const NMEASentence& nmea){
//    /*  -- EXAMPLE --
//    $GPGSA,A,3,04,05,,09,12,,,24,,,,,2.5,1.3,2.1*39
//
//    $GPGSA,A,3,18,21,22,14,27,19,,,,,,,4.4,2.7,3.4*32
//
//    Where:
//    GSA      Satellite status
//    [0] A        Auto selection of 2D or 3D fix (M = manual)
//    [1] 3        3D fix - values include: 1 = no fix
//    2 = 2D fix
//    3 = 3D fix
//    [2-13] 04,05... PRNs of satellites used for fix (space for 12)
//    [14] 2.5      PDOP (dilution of precision)
//    [15] 1.3      Horizontal dilution of precision (HDOP)
//    [16] 2.1      Vertical dilution of precision (VDOP)
//    [16] *39      the checksum data, always begins with *
//    */
//
//
//    this->read_XXGSA(nmea);
//}
//
//void GNSService::read_GPGSV(const NMEASentence& nmea){
//    /*  -- EXAMPLE --
//    $GPGSV,2,1,08,01,40,083,46,02,17,308,41,12,07,344,39,14,22,228,45*75
//
//
//    $GPGSV,3,1,12,01,00,000,,02,00,000,,03,00,000,,04,00,000,*7C
//    $GPGSV,3,2,12,05,00,000,,06,00,000,,07,00,000,,08,00,000,*77
//    $GPGSV,3,3,12,09,00,000,,10,00,000,,11,00,000,,12,00,000,*71
//
//    Where:
//    GSV          Satellites in view
//    [0] 2            Number of sentences for full data
//    [1] 1            sentence 1 of 2
//    [2] 08           Number of satellites in view
//
//    [3] 01           Satellite PRN number
//    [4] 40           Elevation, degrees
//    [5] 083          Azimuth, degrees
//    [6] 46           SNR - higher is better
//    [...]   for up to 4 satellites per sentence
//    [17] *75          the checksum data, always begins with *
//    */
//
//    this->read_XXGSV(nmea);
//}
//
//void GNSService::read_GPRMC(const NMEASentence& nmea){
//    /*  -- EXAMPLE ---
//    $GPRMC,123519,A,4807.038,N,01131.000,E,022.4,084.4,230394,003.1,W*6A
//    $GPRMC,235957.025,V,,,,,,,070810,,,N*4B
//    $GPRMC,061425.000,A,3346.2243,N,08423.4706,W,0.45,18.77,060914,,,A*47
//
//    Where:
//    RMC          Recommended Minimum sentence C
//    [0] 123519       Fix taken at 12:35:19 UTC
//    [1] A            Status A=active or V=Void.
//    [2-3] 4807.038,N   Latitude 48 deg 07.038' N
//    [4-5] 01131.000,E  Longitude 11 deg 31.000' E
//    [6] 022.4        Speed over the ground in knots
//    [7] 084.4        Track angle in degrees True
//    [8] 230394       Date - 23rd of March 1994
//    [9-10] 003.1,W      Magnetic Variation
//    [10] *6A          The checksum data, always begins with *
//    // NMEA 2.3 includes another field after
//    */
//
//    this->read_XXGGA(nmea);
//}
//
//void GNSService::read_GPVTG(const NMEASentence& nmea){
//    /*
//    $GPVTG,054.7,T,034.4,M,005.5,N,010.2,K*48
//
//    where:
//    VTG          Track made good and ground speed
//    [0-1]    054.7,T      True track made good (degrees)
//    [2-3]    034.4,M      Magnetic track made good
//    [4-5]    005.5,N      Ground speed, knots
//    [6-7]    010.2,K      Ground speed, Kilometers per hour
//    [7]    *48          Checksum
//    */
//
//    this->read_XXVTG(nmea);
//}
