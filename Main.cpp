//standard include
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <iostream>
#include <conio.h> // Include this header for _getch function

//custom include

#include "DetectType.h"
#include "AsciiArt.h"

int main() {
    std::cout << asciiArt_old << std::endl;
    std::cout << "Wangan Midnight 6 Terminal with C++ code" << std::endl;

    std::cout << "\nDetecting type of " << std::endl;
    detecttype();
    
    if (TeknoY == 1) {
        CARS cars[128];
        int numCars = TeknoParrot(cars);

        if (numCars > 0) {
            std::cout << "\nAvailable cars:" << std::endl;
            for (int i = 0; i < numCars; i++) {
                std::string carID = cars[i].carID;
                // Extract the last two digits from the carID
                std::string lastTwoDigits = carID.substr(carID.length() - 6, 2);
                std::cout << lastTwoDigits ;
            }
        } else {
            std::cout << "No cars available." << std::endl;
        }
    } else {
        std::cout << "TeknoParrot_Cars folder not found." << std::endl;
    }

    while (true) {
        // Check if a key is pressed
        if (kbhit()) {
            int key = _getch(); // Get the key code
            if (key == 13) {    // Enter key
                break;           // Exit the loop
            }else if (key == 27) { // Esc key
                return 0;          // Terminate the program
            }
        }
    }
}

