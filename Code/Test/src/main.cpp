#include "mbed.h"

// define the Serial object
Serial pc(USBTX, USBRX);

DigitalOut led1(LED1);

int main() {
    while (true) {
        led1 = !led1;

        // Print something over the serial connection
        pc.printf("Blink! LED is now %d\r\n", led1.read());

        wait(0.5);
    }
}