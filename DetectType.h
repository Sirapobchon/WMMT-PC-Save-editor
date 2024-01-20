#ifndef DETECTTYPE_H
#define DETECTTYPE_H

#include <stdio.h>
#include <dirent.h>
#include <string.h>

typedef struct{
    char carID[12];
    char carName[128];
}CARS;

FILE* inFile = NULL;
DIR *dirp = NULL;
struct dirent *dir;
int TeknoY = 0;
int JConY = 0;

int detecttype(){
    int file_count;

    //TeknoParrot_Cars
    file_count = -2;
    dirp = opendir("TeknoParrot_Cars.");
    if(dirp == NULL){
        TeknoY = 0;
    }
    else{
        while ((dir = readdir(dirp)) != NULL){
            file_count++;
            if(file_count > 0){
                TeknoY = 1;
                break;
            }else{
                TeknoY = 0;
            }
        }
    }
    printf("TeknoParrort is");
    if (TeknoY) {
        printf(" Present\n");
    } else {
        printf(" not Present\n");
    }
    closedir(dirp);

    /*JConfig
    dirp = opendir("sv.");
    file_count = 0;
    while ((dir = readdir(dirp)) != NULL){
        file_count++;
        if(file_count > 1){
            JConY = 1;
            break;
        }
    }
    closedir(dirp);
    */

    //return Type

    return 0;
}

int TeknoParrot(CARS cars[]) {
    int i = 0;
    dirp = opendir("TeknoParrot_Cars.");
    if (dirp) {
        while ((dir = readdir(dirp)) != NULL) {
            if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0) {
                continue; // Skip "." and ".." entries
            }
            if (strlen(dir->d_name) > 0) {
                strncpy(cars[i].carID, dir->d_name, sizeof(cars[i].carID));
                cars[i].carName[sizeof(cars[i].carID) - 1] = '\0'; // Ensure null-termination
                //printf("%s\n", cars[i].carID);
                i++;
            }
        }
        closedir(dirp);
    }
    return i; // Return the number of cars processed
}

int Jconfig(){
    return 0;
}

#endif // DETECTTYPE_H