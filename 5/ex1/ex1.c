#include <stdio.h>

struct Time
{
    int hour;
    int min;
    int sec;
};

int main(){
    struct Time time1;
    struct Time time2;
    int day, hour, min, sec;

    day = 0;

    printf("input first time (HH MM SS):"); scanf("%d %d %d", &time1.hour, &time1.min, &time1.sec);
    printf("input second time (HH MM SS):"); scanf("%d %d %d", &time2.hour, &time2.min, &time2.sec);
    
    hour = time1.hour + time2.hour;
    min = time1.min + time2.min;
    sec = time1.sec + time2.sec;

    while (sec >= 60){
        ++min;
        sec -= 60;
    }
    while (min >= 60){
        ++hour;
        min -= 60;
    }
    while (hour >= 24){
        ++day;
        hour -= 24;
    }
    printf("\nThe sum of the times is %dD %dH %dM %dS\n", day, hour, min, sec);
}