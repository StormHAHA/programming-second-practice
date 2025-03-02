#include "laptop.h"
#include <stdio.h>
#include <string.h>

int main() {

    struct Laptop laptop1, laptop2;
    if (structInit(&laptop1, "Acer", "Intel Core i5 11400", true, 14, 80.600))
    {
        return 1;
    }
    if (structInit(&laptop2, "Asus", "AMD Ryzen 5 3600", false, 15.6, 100.200))
    {
        return 1;
    }
    printStruct(&laptop1);
    printf("------------------------\n");
    printStruct(&laptop2);
    printf("------------------------\n");
    structCopy(&laptop2, &laptop1);
    if (changeField(&laptop1, PROCESSOR_MODEL, "Intel Celeron"))
    {
        return 1;
    }
    printStruct(&laptop1);
    printf("------------------------\n");
    printStruct(&laptop2);
    printf("------------------------\n");

    struct Laptop* laptop3 = initDynamicStruct("Apple", "M1", false, 13, 67.000);
    if (!laptop3)
    {
        return 1;
    }
    struct Laptop* laptop4 =  initDynamicStruct("Lenovo", "Intel Core i3 10400", false, 14.4, 50.000);
    if (!laptop4)
    {
        return 1;
    }
    printStruct(laptop3);
    printf("------------------------\n");
    printStruct(laptop4);
    printf("------------------------\n");
    structCopy(laptop4, laptop3);
    if (changeField(laptop3, PROCESSOR_MODEL, "Intel Celeron"))
    {
        return 1;
    }
    printStruct(laptop3);
    printf("------------------------\n");
    printStruct(laptop4);
    printf("------------------------\n");
    removeStruct(laptop3);
    removeStruct(laptop4);
    return 0;
}