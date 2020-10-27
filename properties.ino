int getRxFifoLength(){

  return cc1101.readConfigReg(CC1101_RXFIFO);
  
  }
