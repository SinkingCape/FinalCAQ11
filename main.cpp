#include "mbed.h"

// Define pins
#define BUTTON_PIN PC_13  // Blue button pin on STM32
#define LED1_PIN PA_5     
#define LED2_PIN PB_14     

// Initialise the button input and LED outputs
DigitalIn button(PC_13);
DigitalOut led1(PA_5);
DigitalOut led2(PB_14);

int main() {
    // LED State: LED1 ON, LED2 OFF
    led1 = 1;
    led2 = 0;

    // Initialise flag
    bool flag = false;

    while (true) {
        
        if (button == 0) {
            
            if (!flag) {
                // Set the flag to 1
                flag = true;

                // Toggle the LEDs
                led1 = !led1;
                led2 = !led2;

                // Small delay to avoid multiple toggles on a single press
                ThisThread::sleep_for(200ms);
            }
        } else {
            // Reset the flag to 0 when the button is released
            flag = false;
        }
    }
}


