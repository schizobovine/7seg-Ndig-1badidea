#ifndef __7SEG_NDIG_1BADIDEA_H
#define __7SEG_NDIG_1BADIDEA_H

#include<Arduino.h>
#include<TinyWireS.h>

#define Wire TinyWireS

// Define buffersize for receiving i2c data
#ifndef TWI_RX_BUFFER_SIZE
#define TWI_RX_BUFFER_SIZE (16)
#endif

// Address where the i2c address should be stored in EEPROM
define EEPROM_I2C_ADDR 0x00

// Default i2c address if one has not been stored yet
// TODO

// I2C commands
// TODO

// Pin mappings
// TODO

#endif
