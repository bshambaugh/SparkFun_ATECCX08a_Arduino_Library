
/*
  Using the SparkFun Cryptographic Co-processor Breakout ATECC508a (Qwiic)
  By: Pete Lewis
  SparkFun Electronics
  Date: August 5th, 2019
  License: This code is public domain but you can buy me a beer if you use this and we meet someday (Beerware license).

  Feel like supporting our work? Please buy a board from SparkFun!
  https://www.sparkfun.com/products/15573

  This example shows how to setup your Cryptographic Co-processor with SparkFun's standard settings.
  ***Configurations settings are PERMENANT***
  We highly encourage advanced users to do their own configuration settings.

  Hardware Connections and initial setup:
  Install artemis in boards manager: http://boardsmanager/All#Sparkfun_artemis
  Plug in your controller board (e.g. Artemis Redboard, Nano, ATP) into your computer with USB cable.
  Connect your Cryptographic Co-processor to your controller board via a qwiic cable.
  Select TOOLS>>BOARD>>"SparkFun Redboard Artemis"
  Select TOOLS>>PORT>> "COM 3" (note, yours may be different)
  Click upload, and follow configuration prompt on serial monitor at 115200.

*/

/* Brent Shambaugh: I modified this code to print the info, write the config, and print the info again */

#include <SparkFun_ATECCX08a_Arduino_Library.h> //Click here to get the library: http://librarymanager/All#SparkFun_ATECCX08a
#include <Wire.h>

ATECCX08A atecc;

void setup() {
  Wire.begin();
  Serial.begin(115200);
  if (atecc.begin() == true)
  {
    Serial.println("Successful wakeUp(). I2C connections are good.");
  }
  else
  {
    Serial.println("Device not found. Check wiring.");
    while (1); // stall out forever
  }

  printInfo(); // see function below for library calls and data handling

  Serial.println("Would you like to configure your Cryptographic Co-processor with SparkFun Standard settings? (y/n)");
  Serial.println("***Note, this is PERMANENT and cannot be changed later***");
  Serial.println("***If you do not want to do this, type an 'n' or unplug now.***");

 // simple dirty hack to write 4 bytes at a time (uncomment one at a time, and fill in mising slots "...." 26 - 49 and 104 - 123)
 // slot [16 - 19]
//   uint8_t data1[] = {0xB0, 0x00, 0x55, 0x00}; // 0x3300 sets the keyconfig.keyType, see datasheet pg 20
//   atecc.write(0x00, (16 / 4), data1, 4);

  // slot [20 - 51]
  // uint8_t data1[] = {0x84, 0x67, 0x84, 0x67}; // 0x3300 sets the keyconfig.keyType, see datasheet pg 20
  // atecc.write(0x00, (20 / 4), data1, 4);
  
  // uint8_t data1[] = {0x84, 0x67, 0x84, 0x67}; // 0x3300 sets the keyconfig.keyType, see datasheet pg 20
  // atecc.write(0x00, (22 / 4), data1, 4);
  // .....
  // uint8_t data1[] = {0x84, 0x67, 0x8F, 0x0F}; // 0x3300 sets the keyconfig.keyType, see datasheet pg 20
  // atecc.write(0x00, (50 / 4), data1, 4);

  // slot [96 - 127]
  // uint8_t data1[] = {0x73, 0x00, 0x53, 0x00}; // 0x3300 sets the keyconfig.keyType, see datasheet pg 20
  // atecc.write(0x00, (96 / 4), data1, 4);

  // uint8_t data1[] = {0x53, 0x00, 0x53, 0x00}; // 0x3300 sets the keyconfig.keyType, see datasheet pg 20
  // atecc.write(0x00, (100 / 4), data1, 4);
  // ....
  // uint8_t data1[] = {0x53, 0x00, 0x3C, 0x00}; // 0x3300 sets the keyconfig.keyType, see datasheet pg 20
  // atecc.write(0x00, (124 / 4), data1, 4);

 // uint8_t data2[] = {0x83,0x20,0x87,0x20,0x8F,0x20,0xC4,0x8F,0x8F,0x8F,0x8F,0x8F,0x9F,0x8F,0xAF,0x8F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xAF,0x8F};
 // atecc.write(0x00,(20 / 33),data2,32);

  // slot [20 - 23]
 //   uint8_t data1[] = {0x83,0x20,0x87,0x20};
  //  atecc.write(0x00, (20 / 4), data1, 4);

    // slot [24 - 27]
  //  uint8_t data1[] = {0x8F,0x20,0xC4,0x8F};
  //  atecc.write(0x00, (24 / 4), data1, 4);

    // slot [28 - 31] 
  //  uint8_t data1[] = {0x8F,0x8F,0x8F,0x8F};
  //  atecc.write(0x00, (28 / 4), data1, 4);

    // slot [32 - 35] 
  //  uint8_t data1[] = {0x9F,0x8F,0xAF,0x8F};
  //  atecc.write(0x00, (32 / 4), data1, 4);

   // slot [36 - 39]
 //   uint8_t data1[] = {0x00,0x00,0x00,0x00};
 //   atecc.write(0x00, (36 / 4), data1, 4);

   // slot [40 - 43]
 //  uint8_t data1[] = {0x00,0x00,0x00,0x00};
 //  atecc.write(0x00, (40 / 4), data1, 4);

   // slot [44 - 47]
 //  uint8_t data1[] = {0x00,0x00,0x00,0x00};
 //  atecc.write(0x00, (44 / 4), data1, 4);

   // slot [48 - 51]
  // uint8_t data1[] = {0x00,0x00,0xAF,0x8F};
  // atecc.write(0x00, (48 / 4), data1, 4);

   // slot [96 - 99]
 //  uint8_t data1[] = {0x33,0x00,0x33,0x00};
 //  atecc.write(0x00, (96 / 4), data1, 4);

   // slot [100 - 103]
  // uint8_t data1[] = {0x33,0x00,0x1C,0x00};
 //  atecc.write(0x00, (100 / 4), data1, 4);

   // slot [104 - 107]
  // uint8_t data1[] = {0x1C,0x00,0x1C,0x00};
  // atecc.write(0x00, (104 / 4), data1, 4);

   // slot [108 - 111]
  //  uint8_t data1[] = {0x1C,0x00,0x1C,0x00};
  //  atecc.write(0x00, (108 / 4), data1, 4);

    // slot [112 - 115]
   // uint8_t data1[] = {0x3C,0x00,0x3C,0x00};
   // atecc.write(0x00, (112 / 4), data1, 4);

    // slot [116 - 119]
 //   uint8_t data1[] = {0x3C,0x00,0x3C,0x00};
  //  atecc.write(0x00, (116 / 4), data1, 4);

    // slot [120 - 123]
   // uint8_t data1[] = {0x3C,0x00,0x3C,0x00};
   // atecc.write(0x00, (120 / 4), data1, 4);

    // slot [124 - 127]
  //  uint8_t data1[] = {0x3C,0x00,0x1C,0x00};
  //   atecc.write(0x00, (124 / 4), data1, 4);

     // slot [16 - 19]
     uint8_t data1[] = {0xC0, 0x00, 0x55, 0x00};
     atecc.write(0x00, (16 / 4), data1, 4);
    

  printInfo(); // Print info again to see lock statuses. And if all is good, print the generated public key!
}

void loop()
{
  // do nothing.
}

void printInfo()
{
  // Read all 128 bytes of Configuration Zone
  // These will be stored in an array within the instance named: atecc.configZone[128]
  atecc.readConfigZone(true); // Debug argument false (OFF)

  // Print useful information from configuration zone data
  Serial.println();

  Serial.print("Serial Number: \t");
  for (int i = 0 ; i < 9 ; i++)
  {
    if ((atecc.serialNumber[i] >> 4) == 0) Serial.print("0"); // print preceeding high nibble if it's zero
    Serial.print(atecc.serialNumber[i], HEX);
  }
  Serial.println();

  Serial.print("Rev Number: \t");
  for (int i = 0 ; i < 4 ; i++)
  {
    if ((atecc.revisionNumber[i] >> 4) == 0) Serial.print("0"); // print preceeding high nibble if it's zero
    Serial.print(atecc.revisionNumber[i], HEX);
  }
  Serial.println();

  Serial.print("Config Zone: \t");
  if (atecc.configLockStatus) Serial.println("Locked");
  else Serial.println("NOT Locked");

  Serial.print("Data/OTP Zone: \t");
  if (atecc.dataOTPLockStatus) Serial.println("Locked");
  else Serial.println("NOT Locked");

  Serial.print("Data Slot 0: \t");
  if (atecc.slot0LockStatus) Serial.println("Locked");
  else Serial.println("NOT Locked");

  Serial.println();

  // if everything is locked up, then configuration is complete, so let's print the public key
  if (atecc.configLockStatus && atecc.dataOTPLockStatus && atecc.slot0LockStatus) 
  {
    if(atecc.generatePublicKey() == false)
    {
      Serial.println("Failure to generate This device's Public Key");
      Serial.println();
    }
  }
}
