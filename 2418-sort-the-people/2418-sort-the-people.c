#include <stdlib.h>

typedef struct {
    int height;
    int index;
} Person;

int compare(const void* a, const void* b)
{
    Person* p1 = (Person*)a;
    Person* p2 = (Person*)b;
    
    return p2->height - p1->height;  // descending
}

char** sortPeople(char** names, int namesSize, int* heights, int heightsSize, int* returnSize) {
    
    *returnSize = namesSize;

    Person arr[namesSize];

    for(int i = 0; i < namesSize; i++)
    {
        arr[i].height = heights[i];
        arr[i].index = i;
    }

    qsort(arr, namesSize, sizeof(Person), compare);

    char** result = (char**)malloc(sizeof(char*) * namesSize);

    for(int i = 0; i < namesSize; i++)
    {
        result[i] = names[arr[i].index];
    }

    return result;
}