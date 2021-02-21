//
//  main.c
//  CountingInversions
//
//  Created by changnam hong on 2021/02/18.
//

#include <stdio.h>
#include <stdlib.h>

void printArray(int64_t A[], int64_t size) {
    int64_t i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int64_t countInversionWhileMerge(int64_t arr[], int64_t startIndex, int64_t leftEndIndex, int64_t endIndex) {

    int64_t leftLength = leftEndIndex - startIndex + 1;
    int64_t rightLength = endIndex - (leftEndIndex + 1) + 1;

    // 1. left/right element 복사
    int64_t left[leftLength], right[rightLength];

    for(int64_t i = 0; i < leftLength; i++) {
        left[i] = arr[startIndex + i];
    }

    for(int64_t i = 0; i < rightLength; i++) {
        right[i] = arr[leftEndIndex + 1 + i];
    }

    // 2-1. merge 수행
    // 2-2. sort된 2개의 array를 머지할 때,
    // right의 element가 arr로 copy되어야 할 때, count += (leftEndIndex - i + 1)

//    printf("left ");
//    printArray(left, leftLength);
//    printf("right ");
//    printArray(right, rightLength);

    int64_t numberOfInversions = 0;

    int64_t leftIndex = 0;
    int64_t rightIndex = 0;
    int64_t k = startIndex;

    while(leftIndex < leftLength && rightIndex < rightLength) {
        if (left[leftIndex] > right[rightIndex]) {
            arr[k] = right[rightIndex];
            rightIndex++;
            numberOfInversions += (leftLength - leftIndex);
        } else {
            arr[k] = left[leftIndex];
            leftIndex++;
        }
        k++;
    }

    while(leftIndex < leftLength) {
        arr[k] = left[leftIndex];
        leftIndex++;
        k++;
    }

    while(rightIndex < rightLength) {
        arr[k] = right[rightIndex];
        rightIndex++;
        k++;
    }

    return numberOfInversions;
}

int64_t countingInversions(int64_t arr[], int64_t startIndex, int64_t endIndex) {

    int64_t length = endIndex - startIndex + 1;

    if (length < 2) {
        return 0;
    }

    int64_t leftEndIndex = ((endIndex - startIndex) / 2) + startIndex;
    int64_t rightStartIndex = leftEndIndex + 1;

//    printf("======\n");
//    printf("Length %d\nstartIndex %d, leftEndIndex %d\nrightStartIndex %d, endIndex %d\n", length, startIndex, leftEndIndex, rightStartIndex, endIndex);

    int64_t left = countingInversions(arr, startIndex, leftEndIndex);
    int64_t right = countingInversions(arr, rightStartIndex, endIndex);

    int64_t splitInversion = countInversionWhileMerge(arr, startIndex, leftEndIndex, endIndex);

    return left + right + splitInversion;
}

void testInversion(int64_t arr[], int64_t size) {

    printf("Given array is \n");
    printArray(arr, size);

    int64_t inversion = countingInversions(arr, 0, size - 1);
    printArray(arr, size);
    printf("Result %lld\n", inversion);
}

int main(int argc, const char * argv[]) {

    int64_t arr1[] = { 1, 2, 3, 4, 5, 6 };
    int64_t arr_size1 = sizeof(arr1) / sizeof(arr1[0]);
    int64_t arr2[] = { 3, 8, 1, 5, 6, 7, 2, 4, 9};
    int64_t arr_size2 = sizeof(arr2) / sizeof(arr2[0]);
    int64_t arr3[] = { 4, 5, 6, 1, 2, 3 };
    int64_t arr_size3 = sizeof(arr3) / sizeof(arr3[0]);
    int64_t arr4[] = { 1, 2, 3, 5, 6, 4, 8, 7, 9};
    int64_t arr_size4 = sizeof(arr4) / sizeof(arr4[0]);
    int64_t arr5[] = { 1, 3, 5, 2, 4, 6};
    int64_t arr_size5 = sizeof(arr5) / sizeof(arr5[0]);

    testInversion(arr1, arr_size1);
    testInversion(arr2, arr_size2);
    testInversion(arr3, arr_size3);
    testInversion(arr4, arr_size4);
    testInversion(arr5, arr_size5);

    FILE *fp;

    fp = fopen("/Users/changnamhong/dev-personal/QuizGround/CountingInversions/CountingInversions/IntegerArray.txt", "r");

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

    testInversion(input, 100000);

    return 0;
}
