#include <stdio.h>
#include <string.h>
union Device
{
    char str[9];
    double data;
};

int main(int argc, char const *argv[])
{
    union Device device;

    device.data = 100;
    printf("device.data: %f\n", device.data);

    strcpy(device.str, "hzsssss");
    printf("device.str: %s\n", device.str);

    return 0;
}
