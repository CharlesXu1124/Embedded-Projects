// uLCD graphics and animation 

#include "mbed.h"
#include "uLCD_4DGL.h"


DigitalOut myled(LED1);
uLCD_4DGL uLCD(p9,p10,p11); // serial tx, serial rx, reset pin;
#define length_sprite 128
#define width_sprite 128
#define Q 0x808000 //OLIVE
#define I 0x008000 //GREEN
#define S 0xC0C0C0 //SILVER
#define R 0xF1C40F //YELLOW
#define O 0xF39C12 //ORANGE
#define X 0xFFFFFF //WHITE
#define B 0x0000FF //BLUE
#define G 0xAAB7B8 //GREY
#define D 0x797D7F //DARK GREY
#define L 0x00FF00 //LIME
#define P 0xFF00FF //K
#define _ 0x000000 //BLACK
#define r 0xFF0000 //RED

// make 3 different sprites
// decrease the sprite dimensions to increasing processing speed
// for the glove sprite appearing in the beginning
int Glove[length_sprite*width_sprite] = {
};


// for the based sprite appearing in the beginning right after glove
int based[length_sprite*width_sprite] = {
    
};



// for the motor-car sprite appearing in the beginning
int motor_car[length_sprite*width_sprite] = {
    
};





int i = 0;
int main() {
    // uLCD.printf("Hello World");
    // uLCD.background_color(0xf0ff00);
    //uLCD.line(0, 0, 127, 0, WHITE);
    
    /*
     for(int i = 0; i < 120; i+5){
     
     uLCD.filled_circle(63,63,i, 16711810);
     
     }
     */
    for (unsigned int j = 0; j <= 128; j+=7){
        // DRAW ----  animation of walls
        uLCD.line(j,127,j+7,0,RED); // horizontal  animation
        uLCD.line(127 - j, 0, 127 - (j+7), 127, BLUE);
        
        // Erase
        wait(.1);
        uLCD.line(j,127,j+7,0,BLACK);
        uLCD.line(127 - j, 0, 127 - (j+7), 127, BLACK);  // vertical  animation
    }
    
    uLCD.cls();
    while(1) {
        
        uLCD.filled_circle(63,63,63, 16711810);
        
        uLCD.baudrate(3000000);
        //uLCD.set_font_size(3,3);
        /*
         uLCD.text_char('B', 9, 8, BLACK);
         uLCD.text_char('I',10, 8, BLACK);
         uLCD.text_char('G',11, 8, BLACK);
         uLCD.text_italic(ON); */
        if (i == 0){
            uLCD.locate(40,40);
            uLCD.text_italic(ON);
            uLCD.text_string("Welcome to ECE4180", 0, 5, FONT_7X8, WHITE);
            uLCD.text_italic(ON);
            uLCD.text_string("Final Project", 2, 6, FONT_7X8, WHITE);
            wait(2.0);
            i++;
            uLCD.cls();
            uLCD.filled_circle(63,63,63, 16711810);
        }
        //uLCD.printf("Welcome to ECE 4180 Final Project");
        wait(2);
        myled = 1;
        wait(0.2);
        myled = 0;
        wait(0.2);
    }
}

