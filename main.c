#include <stdio.h>
#include <stdlib.h>
#define MAX 20

int makeList(int array[MAX]);
void printList(int array[MAX], int num);
void searching(int array[MAX], int num);
void sorting(int array[MAX], int num);
int linear(int array[MAX], int num, int key);
int binary(int array[MAX], int num, int key);
void bubble(int array[MAX], int num);
void selection(int array[MAX], int num);
void insertion(int array[MAX], int num);
void swap (int * a, int * b);
int partition (int array[MAX], int low, int high, int * count);
void quick(int array[MAX], int low, int high, int * count);
void mergeSort(int array[MAX], int left, int right, int * count);
void merge(int array[MAX], int left, int middle, int right, int * count);

int main(void)
{
    int input;
    int output;
    int array[MAX];

    do
    {
        printf("1. Searching\n2. Sorting\n3. Exit\nChoice: ");
        scanf("%d", &input);
        switch(input)
        {
            case 1:
                output = makeList(array);
                printList(array, output);
                searching(array, output);
                break;
            case 2:
                output = makeList(array);
                printList(array, output);
                sorting(array, output);
                printList(array, output);
                break;
            case 3:
                break;
            default:
                printf("Invalid\n");
                break;
        }
    } while (input != 3);

    return 0;
}

void printList(int array[MAX], int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int makeList(int array[MAX])
{
    int input;
    printf("How many integers will your array contain\n");
    scanf("%d", &input);
    for (int i = 0; i < input; i++)
    {
        printf("integer %d: ", i+1);
        scanf("%d", &array[i]);
    }
    return input;
}

int linear(int array[MAX], int num, int key)
{
    int count = 0;
    for (int i = 0; i < num; i++)
    {
        count++;
        if (array[i] == key)
        {
            printf("Comparisons: %d\n", count);
            return i;
        }
    }
    printf("Comparisons: %d\n", count);
    return -1;
}

int binary(int array[MAX], int num, int key)
{
    int left = 0;
    int right = num-1;
    int middle;
    int count = 0;

    while (left <= right)
    {
        middle = (left+right)/2;

        if (key == array[middle])
        {
            count++;
            printf("Comparisons: %d\n", count);
            return middle;
        }
        else if (key > array[middle])
        {
            count += 2;
            left = middle+1;
        }
        else
        {
            count += 3;
            right = middle-1;
        }
    }
    printf("Comparisons: %d\n", count);
    return -1;
}

void bubble(int array[MAX], int num)
{
    int temp;
    int count = 0;

    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num-i-1; j++)
        {
            count++;
            if (array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    printf("Comparisons: %d\n", count);
}

void selection(int array[MAX], int num)
{
    int minVal, minPos;
    int temp;
    int count = 0;

    for (int i = 0; i < num; i++)
    {
        minVal = array[i];
        minPos = i;
        for (int j = i+1; j < num; j++)
        {
            count++;
            if (array[j] < minVal)
            {
                minPos = j;
                minVal = array[j];
            }
        }
        temp = array[i];
        array[i] = array[minPos];
        array[minPos] = temp;
    }
    printf("Comparisons: %d\n", count);
}

void insertion(int array[MAX], int num)
{
    int i, current, j;
   
    for (i = 0; i < num; i++) {
        current = array[i];
        j = i - 1;
        
        while (j >= 0 && array[j] > current) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = current;
    }
}

void swap (int * a, int * b) {
    
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition (int array[MAX], int low, int high, int * count) {
    
    int pivot, pIndex, i;
    pivot = array[high];
    
    pIndex = low;
    
    for (i = low; i < high; i++) {
        (*count)++;
        if (array[i] <= pivot) {
            swap (&array[i], &array[pIndex]);
            pIndex++;
        }
    }
    swap (&array[pIndex], &array[high]);
    return pIndex;
}

void quick(int array[MAX], int low, int high, int * count) {
    count++;
    if (low < high)
    {
        int pivotIndex = partition (array, low, high, count);
        quick(array, low, pivotIndex-1, count);
        quick(array, pivotIndex+1, high, count);
    }
}

void merge(int array[MAX], int left, int middle, int right, int * count)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int leftTemp[n1], rightTemp[n2];
    
    for (i = 0; i < n1; i++) {
        leftTemp[i] = array[left + i];
    }
    
    for (j = 0; j < n2; j++) {
        rightTemp[j] = array[middle + 1 + j];
    }
    
    i = 0;
    j = 0;
    k = left;
    
    while (i < n1 && j < n2) {
        if (leftTemp[i] <= rightTemp[j]) {
            (*count)++;
            array[k] = leftTemp[i];
            i++;
        }
        else {
            (*count)+=2;
            array[k] = rightTemp[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        array[k] = leftTemp[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        array[k] = rightTemp[j];
        j++;
        k++;
    }
}

void mergeSort(int array[MAX], int left, int right, int * count)
{   
    (*count)++;
    if (left < right) {
        int middle = left+(right-left)/2;
        mergeSort(array, left, middle, count);
        mergeSort(array, middle+1, right, count);
        merge(array, left, middle, right, count);
    }
}

void searching(int array[MAX], int num)
{
    int input;
    int key;
    int output;
    do
    {
        printf("1. Linear search\n2. Binary search\n3. Back\nChoice: ");
        scanf("%d", &input);
        printf("Select an integer to search for: ");
        scanf("%d", &key);
        switch(input)
        {
            case 1:
                output = linear(array, num, key);
                printf("i = %d", output);
                break;
            case 2:
                output = binary(array, num, key);
                printf("i = %d", output);
                break;
            case 3:
                break;
            default:
                printf("Invalid\n");
                break;
        }
    } while (input > 3 || input < 1);
}

void sorting(int array[MAX], int num)
{
    int input;
    int count;
    do
    {
        printf("1. Bubble sort\n2. Selection sort\n3. Insertion sort\n4. Quicksort\n5. Mergesort\n6. Back\nChoice: ");
        scanf("%d", &input);
        switch(input)
        {
            case 1:
                bubble(array, num);
                break;
            case 2:
                selection(array, num);
                break;
            case 3:
                insertion(array, num);
                break;
            case 4:
                count = 0;
                quick(array, 0, num-1, &count);
                printf("Comparisons: %d\n", count);
                break;
            case 5:
                count = 0;
                mergeSort(array, 0, num-1, &count);
                printf("Comparisons: %d\n", count);
                break;
            case 6:
                break;
            default:
                printf("Invalid\n");
                break;
        }
    } while (input > 6 || input < 1);
}