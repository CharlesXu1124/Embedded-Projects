#include "Motor.h"
#include "mbed.h"
#include "emic2.h"
#include "XNucleo53L0A1.h"
#include <stdio.h>
#include "rtos.h"


Serial pc(USBTX, USBRX);
DigitalOut shdn(p26);
AnalogOut led(p18);
//I2C sensor pins
#define VL53L0_I2C_SDA   p28
#define VL53L0_I2C_SCL   p27


static XNucleo53L0A1 *board=NULL;
emic2 myTTS(p13, p14);
Serial xbee1(p9, p10);
DigitalOut rst1(p11);

Motor B(p23, p6, p5); // pwm, fwd, rev, can brake, right
Motor A(p24, p7, p8); // left motor

char input;
int counter;
int direction;
int main() {
    //initialize distance sensor
    int status;
    uint32_t distance;
    DevI2C *device_i2c = new DevI2C(VL53L0_I2C_SDA, VL53L0_I2C_SCL);
    /* creates the 53L0A1 expansion board singleton obj */
    board = XNucleo53L0A1::instance(device_i2c, A2, D8, D2);
    shdn = 0; //must reset sensor for an mbed reset to work
    wait(0.1);
    shdn = 1;
    wait(0.1);
    /* init the 53L0A1 board with default values */
    status = board->init_board();
    while (status) {
        pc.printf("Failed to init board! \r\n");
        status = board->init_board();
    }
    
    
    
    counter = 0;
    // reset the xbees (at least 200ns)
    rst1 = 0;
    wait_ms(1); 
    rst1 = 1;
    wait_ms(1); 
    input = 'I';
    
    A.speed(0);
    B.speed(0);
    wait(2);
    direction = 1;
    while(1) {
        if(xbee1.readable()) {
            input = xbee1.getc();
            wait(0.2);
        }
        status = board->sensor_centre->get_distance(&distance);
        if (status == VL53L0X_ERROR_NONE) {
            pc.printf("D=%ld mm\r\n", distance);
            
        }
        
        while (distance < 200) {
                direction = rand()*100;
                if (direction > 50)
                {
                    A.speed(-0.5);
                    B.speed(-0.5);
                    led = 0;
                    wait(0.1);
                } else
                {
                    
                    A.speed(0.5);
                    B.speed(0.5);
                    led = 1;
                    wait(0.1);
                }
                status = board->sensor_centre->get_distance(&distance);
                led = 0;
                A.speed(0);
                B.speed(0);
        }
        if (input == 'A')
        {
            //myTTS.speakf("S");//Speak command starts with "S"
            //myTTS.speakf("forward");
            //myTTS.speakf("\r"); //marks end of speak command
            //myTTS.ready();
            A.speed(-0.5);
            B.speed(0.5);
            wait(0.2);
        } else if (input == 'B')
        {
            //myTTS.speakf("S");//Speak command starts with "S"
            //myTTS.speakf("back");
            //myTTS.speakf("\r"); //marks end of speak command
            //myTTS.ready();
            A.speed(0.5);
            B.speed(-0.5);
            wait(0.2);
        } else if (input == 'C')
        {
            myTTS.speakf("S");//Speak command starts with "S"
            myTTS.speakf("left");
            myTTS.speakf("\r"); //marks end of speak command
            myTTS.ready();
            A.speed(0.5);
            B.speed(0.5);
            wait(0.2);
        } else if (input == 'D')
        {
            myTTS.speakf("S");//Speak command starts with "S"
            myTTS.speakf("right");
            myTTS.speakf("\r"); //marks end of speak command
            myTTS.ready();
            A.speed(-0.5);
            B.speed(-0.5);
            wait(0.2);
        } else if (input == 'E')
        {
            myTTS.speakf("S");//Speak command starts with "S"
            myTTS.speakf("stop");
            myTTS.speakf("\r"); //marks end of speak command
            myTTS.ready();
            A.speed(0);
            B.speed(0);
            wait(0.2);
        }
    }
}
