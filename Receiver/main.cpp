// basic xbee example
// - take chars from the terminal, push them out xbee1
// - listen on xbee2, and print value + 1 to terminal
#include "Motor.h"
#include "mbed.h"
#include "emic2.h"
emic2 myTTS(p13, p14);
Serial xbee1(p9, p10);
DigitalOut rst1(p11);

Motor B(p23, p6, p5); // pwm, fwd, rev, can brake, right
Motor A(p24, p7, p8); // left motor

char input;
int counter;

int main() {
    
    myTTS.volume(2);
    myTTS.voice(3);
    counter = 0;
    // reset the xbees (at least 200ns)
    rst1 = 0;
    wait_ms(1); 
    rst1 = 1;
    wait_ms(1); 
    input = 'I';
    A.speed(0);
    B.speed(0);
    while(1) {
        if(xbee1.readable()) {
            input = xbee1.getc();
        }
        A.speed(0);
        B.speed(0);
        
        if (input == 'A')
        {
            myTTS.speakf("S");//Speak command starts with "S"
            myTTS.speakf("forward");
            myTTS.speakf("\r"); //marks end of speak command
            myTTS.ready();
            A.speed(0.5);
            B.speed(-0.5);
            wait(0.5);
        } else if (input == 'B')
        {
            myTTS.speakf("S");//Speak command starts with "S"
            myTTS.speakf("back");
            myTTS.speakf("\r"); //marks end of speak command
            myTTS.ready();
            A.speed(-0.5);
            B.speed(0.5);
            wait(0.5);
        } else if (input == 'C')
        {
            myTTS.speakf("S");//Speak command starts with "S"
            myTTS.speakf("left");
            myTTS.speakf("\r"); //marks end of speak command
            myTTS.ready();
            A.speed(0.5);
            B.speed(0.5);
            wait(0.5);
        } else if (input == 'D')
        {
            myTTS.speakf("S");//Speak command starts with "S"
            myTTS.speakf("right");
            myTTS.speakf("\r"); //marks end of speak command
            myTTS.ready();
            A.speed(-0.5);
            B.speed(-0.5);
            wait(0.5);
        } else if (input == 'E')
        {
            myTTS.speakf("S");//Speak command starts with "S"
            myTTS.speakf("stop, open vicinity warning system");
            myTTS.speakf("\r"); //marks end of speak command
            myTTS.ready();
            A.speed(0);
            B.speed(0);
            wait(0.5);
            
        }
    }
}