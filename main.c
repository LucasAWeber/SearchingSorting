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
int partition (int array[MAX], int low, int high);
void quick(int array[MAX], int low, int high);
void mergeSort(int array[MAX], int left, int right);
void merge(int array[MAX], int left, int middle, int right);

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
    for (int i = 0; i < num; i++)
    {
        if (array[i] == key)
        {
            return i;
        }
    }
    return -1;
}

int binary(int array[MAX], int num, int key)
{
    int left = 0;
    int right = num-1;
    int middle;

    while (left <= right)
    {
        middle = (left+right)/2;
        if (key == array[middle])
        {
            return middle;
        }
        else if (key > array[middle])
        {
            left = middle+1;
        }
        else{
            right = middle-1;
        }
    }
    return -1;
}

void bubble(int array[MAX], int num)
{
    int temp;

    for (int i = 0; i < num - 1; i++)
    {
        for (int j = 0; j < num-i-1; j++)
        {
            if (array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

void selection(int array[MAX], int num)
{
    int minVal, minPos;
    int temp;

    for (int i = 0; i < num; i++)
    {
        minVal = array[i];
        minPos = i;
        for (int j = i+1; j < num; j++)
        {
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

int partition (int array[MAX], int low, int high) {
    
    int pivot, pIndex, i;
    pivot = array[high];
    
    pIndex = low;
    
    for (i = low; i < high; i++) {
        if (array[i] <= pivot) {
            swap (&array[i], &array[pIndex]);
            pIndex++;
        }
    }
    swap (&array[pIndex], &array[high]);
    return pIndex;
}

void quick(int array[MAX], int low, int high) {

    if (low < high)
    {
        int pivotIndex = partition (array, low, high);
        quick(array, low, pivotIndex-1);
        quick(array, pivotIndex+1, high);
    }
}

void merge(int arr[], int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;
    int leftTemp[n1], rightTemp[n2];
    
    for (i = 0; i < n1; i++) {
        leftTemp[i] = arr[left + i];
    }
    
    for (j = 0; j < n2; j++) {
        rightTemp[j] = arr[middle + 1 + j];
    }
    
    i = 0;
    j = 0;
    k = left;
    
    while (i < n1 && j < n2) {
        if (leftTemp[i] <= rightTemp[j]) {
            arr[k] = leftTemp[i];
            i++;
        }
        else {
            arr[k] = rightTemp[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        arr[k] = leftTemp[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        arr[k] = rightTemp[j];
        j++;
        k++;
    }
}

void mergeSort(int array[MAX], int left, int right)
{   
    if (left < right) {
        int middle = left+(right-left)/2;
        mergeSort(array, left, middle);
        mergeSort(array, middle+1, right);
        
        merge(array, left, middle, right);
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
                quick(array, 0, num-1);
                break;
            case 5:
                mergeSort(array, 0, num-1);
                break;
            case 6:
                break;
            default:
                printf("Invalid\n");
                break;
        }
    } while (input > 6 || input < 1);
}