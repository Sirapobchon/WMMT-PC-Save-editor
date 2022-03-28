/*
    DetectType.h
    Detect which type of save file in use which can be either
        Teknoparrort file or JConfig file
*/

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
    file_count = -2;
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
            cars[i].carID = dir->d_name;
            printf("%s\n", dir->d_name);
        }
        closedir(dirp);
    }
}

int Jconfig(){

}
