#include <stdio.h>
#include <time.h>

int main (void) {
    time_t raw_time;
    struct tm * time_info;

    time(&raw_time);
    time_info = localtime(&raw_time);

    printf("Current time and date: %s", asctime(time_info));
    return 0; 
}