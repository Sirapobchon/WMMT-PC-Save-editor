//standard include
#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <iostream>

//custom include

#include "DetectType.h"

int main() {
    std::cout << "Wangan Midnight 6 Terminal" << std::endl;

    detecttype();
    if (TeknoY == 1) {
        CARS cars[128];
        int numCars = TeknoParrot(cars);

        if (numCars > 0) {
            std::cout << "Available cars:" << std::endl;
            for (int i = 0; i < numCars; i++) {
                std::cout << cars[i].carID << std::endl;
            }
        } else {
            std::cout << "No cars available." << std::endl;
        }
    } else {
        std::cout << "TeknoParrot_Cars folder not found." << std::endl;
    }

    return 0;
}

