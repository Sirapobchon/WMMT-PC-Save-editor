#ifndef DETECTTYPE_H
#define DETECTTYPE_H

#include <stdio.h>
#include <dirent.h>
#include <string.h>

typedef struct{
    char carID;
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
    file_count = 0;
    dirp = opendir("TeknoParrot_Cars.");
    if(dirp == NULL){
        TeknoY = 0;
    }
    else{
        while ((dir = readdir(dirp)) != NULL){
            file_count++;
            if(file_count > 1){
                TeknoY = 1;
                break;
            }else{
                TeknoY = 0;
            }
        }
    }
    printf("Tekno is %d\n", TeknoY);
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
}

int TeknoParrot(CARS cars[]){
    int i = 0;
    dirp = opendir("TeknoParrot_Cars.");
    if(dirp){
        while ((dir = readdir(dirp)) != NULL){
            if (strlen(dir->d_name) > 0) { // Check if the name is not empty
                cars[i].carID = dir->d_name[0]; // Extract the first character
                printf("%c\n", cars[i].carID);
                i++;
            }
        }
        closedir(dirp);
    }
}

int Jconfig(){

}

#endif // DETECTTYPE_H