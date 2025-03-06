#include "laptop.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int isCorrectStruct(const struct Laptop* m) {

    if (m -> displayWide < 10 || m -> displayWide > 20) { 
        printf("Поле displayWide имеет недопустимое значение (допустимые значения для диагонали ноутбука 10 - 20 дюймов)\n");
        return 1;
    }
    if (m -> price <= 0 || m -> price > 1000000) { 
        printf("Поле price имеет недопустимое значение (допустимые значения для цены ноутбука 1 - 1.000.000)\n");
        return 1;
    }

    return 0;
}

int structInit(struct Laptop* m, const char* vendor, const char* processorModel, bool hasGamingVideoChip, float displayWide, float price) {
    strncpy(m -> vendor, vendor, N);
    strncpy(m -> processorModel, processorModel, N);
    m -> hasGamingVideoChip = hasGamingVideoChip;
    m -> displayWide = displayWide;
    m -> price = price;
    if (isCorrectStruct(m)) {
        printf("Для инициализации стуктуры использовались некорректные значения полей\n");
        return 1;
    }
    return 0;
}

void structCopy(struct Laptop* dst, const struct Laptop* src) { 
    strncpy(dst -> vendor, src -> vendor, N);
    strncpy(dst -> processorModel, src -> processorModel, N);
    dst -> hasGamingVideoChip = src -> hasGamingVideoChip;
    dst -> displayWide = src -> displayWide;
    dst -> price = src -> price;
}

void printStruct(const struct Laptop* m) {
    printf("Производитель ноутбука: %s\n", m -> vendor);
    printf("Модель процессора: %s\n", m -> processorModel);
    printf("Наличие игровой видеокарты: %s\n", m -> hasGamingVideoChip ? "Да" : "Нет");
    printf("Диагональ экарана ноутбука: %.2f\n", m -> displayWide);
    printf("Цена ноутбука: %.3f\n", m -> price);
}

int changeField(struct Laptop* laptop, FieldType field, void* value) {
    switch (field) {
        case VENDOR:
            strncpy(laptop -> vendor, (char *)value, N);
            break;
        case PROCESSOR_MODEL:
            strncpy(laptop -> processorModel, (char *)value, N);
            break;
        case GAMING_VIDEO_CHIP:
            laptop -> hasGamingVideoChip = *(bool *)value;
            break;
        case DISPLAY_WIDE:
            laptop -> displayWide = *(float *)value;
            break;
        case PRICE:
            laptop -> price = *(float *)value;
            break;
    }
    if (isCorrectStruct(laptop)) {
        printf("Для инициализации стуктуры использовались некорректные значения полей\n");
        return 1;
    }
    return 0;
}

struct Laptop* initDynamicStruct(const char *vendor, const char *processorModel, bool hasGamingVideoChip, float displayWide, float price) {
    struct Laptop* newLaptop = (struct Laptop*)malloc(sizeof(struct Laptop));

    if (!newLaptop) {
        printf("Не удалось выделить память для структуры\n");
        return NULL;
    }

    if (structInit(newLaptop, vendor, processorModel, hasGamingVideoChip, displayWide, price)) {
        return NULL;
    }
    return newLaptop;
}

void removeStruct(struct Laptop* laptop) {
    if (!laptop) return;
    free(laptop);
    printf("Ноутбук %s удален\n", laptop -> vendor);
}
