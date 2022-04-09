#include <stdio.h>
#include <stdlib.h>

int makeList(int ** array);
void printList(int * array, int num);
void searching(int * array, int num);
void sorting(int * array, int num);
void linear(int * array, int num);
void binary(int * array, int num);
void bubble(int * array, int num);

int main(void)
{
    int input;
    int output;
    int * array;

    do
    {
        printf("1. Searching\n2. Sorting\n3. Exit\nChoice: ");
        scanf("%d", &input);
        switch(input)
        {
            case 1:
                output = makeList(&array);
                printList(array, output);
                searching(array, output);
                break;
            case 2:
                output = makeList(&array);
                sorting(array, output);
                break;
            case 3:
                break;
            default:
                printf("Invalid\n");
                break;
        }
        free(array);
    } while (input != 3);

    return 0;
}

void printList(int * array, int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int makeList(int ** array)
{
    array = malloc(sizeof(int*));
    int input;
    printf("How many integers will your array contain\n");
    scanf("%d", &input);
    *array = malloc(sizeof(int)*input);
    for (int i = 0; i < input; i++)
    {
        printf("integer %d: ", i+1);
        scanf("%d", array[i]);
    }
    return input;
}

void linear(int * array, int num)
{

}

void binary(int * array, int num)
{

}

void bubble(int * array, int num)
{

}

void searching(int * array, int num)
{
    int input;
    do
    {
        printf("1. Linear search\n2. Binary search\n3. Exit\nChoice: ");
        scanf("%d", &input);
        switch(input)
        {
            case 1:
                linear(array, num);
                break;
            case 2:
                binary(array, num);
                break;
            case 3:
                break;
            default:
                printf("Invalid\n");
                break;
        }
    } while (input > 3 || input < 1);
}

void sorting(int * array, int num)
{
    int input;
    do
    {
        printf("1. Bubble sort\n2. Selection sort\n3. Insertion sort\n4. Quicksort\n5. Mergesort\n6. Exit\nChoice: ");
        scanf("%d", &input);
    } while (input > 6 || input < 1);
}