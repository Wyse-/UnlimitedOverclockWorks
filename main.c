#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "ini.h"

typedef struct
{
    const int* Time1;
    const int* Time2;
    const int* WhiteBackground;
    const int* Deliner;
    const char* WhiteBackgroundPath;
    const char* DelinerPath;
    const char* RR1;
    const char* RR2;
    const int* RR1Num;
    const int* RR2Num;


} configuration;

static int handler(void* Timings, const char* section, const char* Time1,
                   const char* value)
{
    configuration* pconfig = (configuration*)Timings;

    #define MATCH(s, n) strcmp(section, s) == 0 && strcmp(Time1, n) == 0
    if (MATCH("Extras", "WhiteBackground")) {
        pconfig->WhiteBackground = (int*)atoi(value);
    } else if (MATCH("Extras", "Deliner")) {
        pconfig->Deliner = (int*)atoi(value);
    } else if (MATCH("Paths", "WhiteBackgroundPath")) {
        pconfig->WhiteBackgroundPath = strdup(value);
    } else if (MATCH("Paths", "DelinerPath")) {
        pconfig->DelinerPath = strdup(value);
    } else if (MATCH("Timings", "Time1")) {
        pconfig->Time1 = (int*)atoi(value);
    } else if (MATCH("Timings", "Time2")) {
        pconfig->Time2 = (int*)atoi(value);
    } else if (MATCH("Paths", "RR1")) {
        pconfig->RR1 = strdup(value);
    } else if (MATCH("Paths", "RR2")) {
        pconfig->RR2 = strdup(value);
    } else if (MATCH("RefreshRates", "RR1Num")) {
        pconfig->RR1Num = (int*)atoi(value);
    } else if (MATCH("RefreshRates", "RR2Num")) {
        pconfig->RR2Num = (int*)atoi(value);
    } else {
        return 0;  /* unknown section/Time1, error */
    }
    return 1;
}

int main()
{
    system("cls");
    system("COLOR 09");
    printf("================================================================================");
    printf("=================    ==  ====  ====    ====  ====  ====  ==    =================");
    printf("=================  ====  ====  ===  ==  ===  ====  ====  ====  =================");
    printf("=================  ====  ====  ==  ====  ==  ====  ====  ====  =================");
    printf("=================  ====  ====  ==  ====  ==  ====  ====  ====  =================");
    printf("=================  ====  ====  ==  ====  ==   ==    ==  =====  =================");
    printf("=================  ====  ====  ==  ====  ===  ==    ==  =====  =================");
    printf("=================  ====  ====  ==  ====  ===  ==    ==  =====  =================");
    printf("=================  ====   ==   ===  ==  =====    ==    ======  =================");
    printf("=================    ===      =====    =======  ====  =====    =================");
    printf("================================================================================");

    /*
    Ini parsing initialization
    */
    configuration config;
    int flag = 1;
    int rrCheck = 0;
    int time2;
    int i;
    while(flag != 0){
        flag = ini_parse("config.ini", handler, &config);
    }

    /*
    UOW Main code
    */
    printf("\n");

    for(i = 0; i < (((int)config.Time1)/1000); i++){
        printf("[Waiting %2ds...]\r", ((int)config.Time1/1000) - i);
        Sleep(1000);
    }
    system(config.RR1);
    printf("\n\n[Applied %dHz]\n", (int)config.RR1Num);

    if((int)config.WhiteBackground == 1){
        system(config.WhiteBackgroundPath);
        printf("\n[Applied white background]");
    }

    printf("\n");

    for(i = 0; i < (((int)config.Time2)/60000); i++){
        printf("[Waiting %2dm...]\r", ((int)config.Time2/60000) - i);
        Sleep(60000);
    }
    system(config.RR2);
    printf("\n[Applied %dHz]\n", (int)config.RR2Num);


    if((int)config.Deliner == 1){
        system(config.DelinerPath);
        printf("\n[Started deliner]\n");
    }

    printf("\n[Exiting program]");

    Sleep(3000);

    return 0;
}
