/*
 * 7seg-Ndig-1badidea.ino - Firmware to 7 segment displays
 *
 * Author: schizobovine <sean@yak.net>
 */

#include <Arduino.h>
#include <TinyWireS.h>
#include <EEPROM.h>
#include "7seg-Ndig-1badidea.h"

void recv_handler(uint8_t num_bytes) {

  // TODO Somehow inform user of buffer overflow?
  if (num_bytes < 1 || num_bytes > TWI_RX_BUFFER_SIZE) {
    return;
  }

  byte a = TinyWireS.receive();
  num_bytes--;

  if (a < 0 || a >= REG_MAX) {
    return;
  } else {
    my_reg_addr = a;
  }

  // If there's only a single byte, that was an address set, so go ahead and
  // return
  if (!num_bytes) {
    return;
  }

  //
  // TODO Dispatch code based on address. Cases to handle:
  //
  // 1. Read/write display buffer. If write, set some flag to check to push the
  //    data to the display next chance we get in the main loop.
  // 2. Read/write brightness level. Changes PWM rate of current sinking.
  // 3. Read/write individual digit.
  // 4. Read/write individual segments (maybe?)
  // 5. (Optional) Read/write i2c address.
  // 6. (Optional) Read display size
  //

}

void req_handler() {

  // Allow master to read display buffer
  if (my_reg_addr >= REG_LINE1 && my_reg_addr < REG_BRIGHT) {
    TinyWireS.send(display_buff[my_reg_addr - REG_LINE1]);

  // Allow master to read display brightness level
  } else if (my_reg_addr == REG_BRIGHT) {
    TinyWireS.send(brightness);
  }

  // Increment register pointer, wrapping around if we're at the end
  my_reg_addr++;
  if (my_reg_addr >= REG_MAX) {
    my_reg_addr = 0x00;
  }

}

void setup() {

  // Get i2c address from EEPROM
  //my_i2c_addr = EEPROM.read(EEPROM_I2C_ADDR);
  //if (my_i2c_addr > 127) {
  //  my_i2c_addr = DEFAULT_I2C_ADDR;
  //  EEPROM.write(EEPROM_I2C_ADDR, my_i2c_addr);
  //}

  // Setup i2c as a slave and register request handlers
  //Wire.begin(my_i2c_addr);
  //Wire.onRequest(req_handler);
  //Wire.onReceive(recv_handler);

}

void loop() {
  delay(1000);
}
