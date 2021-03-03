//
//  main.c
//  QuickSort
//
//  Created by changnam hong on 2021/03/03.
//

#include <stdio.h>
#include <stdlib.h>

void printArray(int64_t A[], int64_t size) {
    int64_t i;
    for (i = 0; i < size; i++)
        printf("%lld ", A[i]);
    printf("\n");
}

void swap(int64_t arr[], int64_t lhsIndex, int64_t rhsIndex) {
    int64_t tmp = arr[lhsIndex];
    arr[lhsIndex] = arr[rhsIndex];
    arr[rhsIndex] = tmp;
}

int64_t partition(int64_t arr[], int64_t pivotIndex, int64_t startIndex, int64_t endIndex) {
    int64_t i = startIndex + 1;
    int64_t j = startIndex + 1;

    for(; j <= endIndex; j++) {
        if (arr[j] < arr[pivotIndex]) {
            swap(arr, i, j);
            i++;
        }
    }
    swap(arr, startIndex, i - 1);
    return i - 1;
}

int64_t selectPivot(int64_t arr[], int64_t startIndex, int64_t endIndex) {
    return startIndex;
}

void quickSort(int64_t arr[], int64_t startIndex, int64_t endIndex) {

    if (endIndex - startIndex < 1) {
        return;
    }

    int64_t pivotIndex = selectPivot(arr, startIndex, endIndex);
    int64_t updatedPivotIndex = partition(arr, pivotIndex, startIndex, endIndex);

    int64_t leftHalfStartIndex = startIndex;
    int64_t leftHalfEndIndex = updatedPivotIndex - 1;
    int64_t rightHalfStartIndex = updatedPivotIndex + 1;
    int64_t rightHalfEndIndex = endIndex;

    quickSort(arr, leftHalfStartIndex, leftHalfEndIndex);
    quickSort(arr, rightHalfStartIndex, rightHalfEndIndex);
}

void testQuickSort(int64_t arr[], int64_t size) {

    printf("Given array is \n");
    printArray(arr, size);

    quickSort(arr, 0, size - 1);

    printf("Sorted array is \n");
    printArray(arr, size);
}

int main(int argc, const char * argv[]) {

    int64_t arr1[] = { 1, 2, 3, 4, 5, 6 };
    int64_t arr_size1 = sizeof(arr1) / sizeof(arr1[0]);
    int64_t arr2[] = { 3, 8, 1, 5, 6, 7, 2, 4, 9};
    int64_t arr_size2 = sizeof(arr2) / sizeof(arr2[0]);
    int64_t arr3[] = { 2, 5, 6, 1, 2, 3 };
    int64_t arr_size3 = sizeof(arr3) / sizeof(arr3[0]);
    int64_t arr4[] = { 8, 2, 3, 5, 6, 4, 8, 7, 9};
    int64_t arr_size4 = sizeof(arr4) / sizeof(arr4[0]);
    int64_t arr5[] = { 7, 3, 5, 2, 4, 6};
    int64_t arr_size5 = sizeof(arr5) / sizeof(arr5[0]);

    testQuickSort(arr1, arr_size1);
    testQuickSort(arr2, arr_size2);
    testQuickSort(arr3, arr_size3);
    testQuickSort(arr4, arr_size4);
    testQuickSort(arr5, arr_size5);

    FILE *fp;

    fp = fopen("/Users/changnamhong/dev-personal/QuizGround/QuickSort/QuickSort/IntegerArray.txt", "r");

    int64_t input[110001];
    int64_t index = 0;
    while (1) {
        if (feof(fp)) {
            break;
        }
        char element[10];
        fgets(element, 10, fp);

        int64_t elementInt = atoi(element);
        input[index] = elementInt;
        index++;
    }
    fclose(fp);

    testQuickSort(input, index);

    return 0;
}
