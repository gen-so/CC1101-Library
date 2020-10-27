//int calculateRssi(char raw)
//{
//    uint8_t rssi_dec;
//    // TODO: This rssi_offset is dependent on baud and MHz; this is for 38.4kbps and 433 MHz.
//    uint8_t rssi_offset = 74;
//    rssi_dec = (uint8_t)raw; //change hex to dec
//    if (rssi_dec >= 128)
//        return ((int)(rssi_dec - 256) / 2) - rssi_offset;
//    else
//        return (rssi_dec / 2) - rssi_offset;
//}
//
//int getBit(byte b, int bitNumber) {
//   return ((b >> bitNumber) & 0x01);
//}
//
////gets a bits from a byte, and return a byte of the new bits
//byte getBitRange(byte data, int start, int _end){
//
//    //shift binary to starting point of range
//    byte shifted = (data >> start);
//
//    //calculate range length (+1 for 0 index)
//    int rangeLength = (_end-start)+1;
//
//    //get binary mask based on range length 
//    byte maskBinary;
//     
//    switch (rangeLength){
//    case 1: maskBinary = 0b00000001; break;
//    case 2: maskBinary = 0b00000011; break;
//    case 3: maskBinary = 0b00000111; break;
//    case 4: maskBinary = 0b00001111; break;
//    case 5: maskBinary = 0b00011111; break;
//    case 6: maskBinary = 0b00111111; break;
//    case 7: maskBinary = 0b01111111; break;
//    case 8: maskBinary = 0b11111111; break;
//    default:
//      // default statements
//      Serial.println("Error: Range length too long!!");
//    }
//    
//    //cancel out 
//    byte finalByte = (shifted & maskBinary);
//
//    return finalByte;
//  }
//
//int getRssi(){
//    //read raw rssi
//    char rssiRaw = cc1101.readStatusReg(CC1101_RSSI);
//    return calculateRssi(rssiRaw);
//  }
