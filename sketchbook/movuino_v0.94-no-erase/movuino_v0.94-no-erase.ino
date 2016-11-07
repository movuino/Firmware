// This includes are needed because otherwise the Arduino cannot find the headers
// for internal use of the libs
#include "I2Cdev.h"
#include "MPU6050.h"
#include "MS5611.h"
#include "Wire.h"
#include "SPI.h"

#include "MvCore.h"
#include "SerialMvCom.h"
#include "Storage.h"

#include <SerialFlash.h>

#define RED_LED 10
#define BLUE_LED 13
#define GREEN_LED 9
#define BUTTON_PIN 8
#define WRITE_LED 13
#define VIBRATE_PIN A5 //not working for now
#define BLE_DISABLE_PIN 4
#define FLASH_DISABLE_PIN 12

MvCore g_core;

void setup()
{
    int i;
    MvCom *com[2];

    Serial.begin(38400);
    Serial1.begin(9600);

    com[0] = new SerialMvCom(&Serial);
    com[1] = new SerialMvCom(&Serial1);

    MvFrameHandler *fhandler = new MvFrameHandler(com, 2);

    Storage *storage = new Storage();

    /* Initialize the core app */
    g_core.setup(storage, fhandler, MPU6050_ADDRESS_AD0_HIGH, BUTTON_PIN, VIBRATE_PIN,BLE_DISABLE_PIN,FLASH_DISABLE_PIN);
    /*this function let configure logicON  : HIGH (normal) LOW (led pin sink current) */
    g_core.setupLed(BLUE_LED, LOW);
}

void loop()
{
    g_core.loop();
}
