// Motor working code for the wheel spin

#include "mbed.h"
#include "Motor.h"

Motor left_wheel(p22, p6, p5); // pwm, fwd, rev
Motor right_wheel(p21, p7, p8); // pwm, fwd, rev
DigitalOut myled(LED1);


// variable to set which direction to move the motor
char decision = 'S'; // stop as default

int main() {
    left_wheel.speed(0.0);
    right_wheel.speed(0.0);
    
    while(1) {
        
        switch(decision){
            case 'F': // Forward direction
                
                for (float a = 0.0; a < 1.0; a+=0.02){
                    left_wheel.speed(a);
                    right_wheel.speed(a);
                    wait(0.05);
                }
                break;
                
            case 'B': // Backward
                
                for (float b = 0.0; b >= -1.0; b-=0.02){
                    left_wheel.speed(b);
                    right_wheel.speed(b);
                    wait(0.05);
                }
                break;
                
                
            case 'S': // Stop
                left_wheel.speed(0.0);
                right_wheel.speed(0.0);
                wait(0.05);
                break;
                
            default:  // Stop as default condition
                left_wheel.speed(0.0);
                right_wheel.speed(0.0);
                
                // call an inturrupt to shut down the motors.
        }
        
    }
    
}

