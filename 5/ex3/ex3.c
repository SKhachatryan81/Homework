#include <stdio.h>
#include <string.h>

union Sensors
{
    int temp;
    float press;
    float humid;
};



int main(int argc, char *argv[]){
    
    char sens_type[20];
    union Sensors sensor;

     printf("Enter the type of sensor (temperature, pressure, humidity): ");
     scanf("%s", sens_type);
    
    if (strcmp(sens_type, "temperature") == 0) {
        printf("Enter the temperature: ");
        scanf("%d", &sensor.temp);
        printf("Sensor Type: %s\nValue: %d\n", sens_type, sensor.temp);
    } else if (strcmp(sens_type, "pressure") == 0) {
        printf("Enter the pressure: ");
        scanf("%f", &sensor.press);
        printf("Sensor Type: %s\nValue: %.2f\n", sens_type, sensor.press);
    } else if (strcmp(sens_type, "humidity") == 0) {
        printf("Enter the humidity: ");
        scanf("%f", &sensor.humid);
        printf("Sensor Type: %s\nValue: %.2f\n", sens_type, sensor.humid);
    } else {
        printf("Error: Unknown sensor type.\n");
    }


}