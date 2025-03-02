#ifndef LAPTOP_H
#define LAPTOP_H

#include <stdbool.h>

#define N 30

// enum используется для того чтобы создать одну универсальную
// функцию для изменения поля структуры с учетом того что в структуре
// разные типы данных
typedef enum {
    VENDOR,
    PROCESSOR_MODEL,
    GAMING_VIDEO_CHIP,
    DISPLAY_WIDE,
    PRICE
} FieldType;

struct Laptop {
    char vendor[N];
    char processorModel[N];
    bool hasGamingVideoChip;
    float displayWide;
    float price;
};

int isCorrectStruct(const struct Laptop* m);
int structInit(struct Laptop* m, const char* vendor, const char* processorModel, bool hasGamingVideoChip, float displayWide, float price);
void structCopy(struct Laptop* dst, const struct Laptop* src);
void printStruct(const struct Laptop* m);
int changeField(struct Laptop* laptop, FieldType field, void* value);
struct Laptop* initDynamicStruct(const char *vendor, const char *processorModel, bool hasGamingVideoChip, float displayWide, float price);
void removeStruct(struct Laptop* laptop);

#endif // LAPTOP_H