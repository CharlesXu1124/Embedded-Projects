// Servo code

#include "mbed.h"
#include "Servo.h"


/// SERVO Functions added

DigitalOut myled(LED1); // Flashes when the picture is taken on the left side
DigitalOut myled2(LED2);

DigitalOut myled3(LED3);  // Flashes when the picture is taken on the right side
DigitalOut myled4(LED4);

// ADD SOME graphical SPRITES in the uLCD file
// add mini challenges


Servo myservo(p21);
int a = 0;
int main() {
    
    // LED
    while(1) {
        
        for (float i = 0; i <= 4.0; i+=2){
            myservo = i;
            
            // Left side picture
            if (a == 0){
                
                myled = 1; myled2 = 1;
                wait(0.2);
                myled = 0; myled2 = 0;
                wait(2.7);
                a = 1;
                wait(0.1);
                
                //wait(2.8);
            }
            
            // center side picture
            else if (a == 1){
                
                myled2 = 1; myled3 = 1;
                wait(0.2);
                myled2 = 0; myled3 = 0;
                //wait(0.1);
                wait(2.7);
                a = 2;
                wait(0.1);
            }
            
            else {
                myled3 = 1; myled4 = 1;
                wait(0.2);
                myled3 = 0; myled4 = 0;
                // wait(0.1)
                wait(2.7)
                a = 0;
                wait(0.1)
                
                
            } // end of for loop
            
            
        } // end of while
        
    } // end of program
