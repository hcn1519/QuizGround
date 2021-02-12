//
//  StringExtensions.c
//  Extensions
//
//  Created by changnam hong on 2021/02/12.
//

#include "StringExtensions.h"

#define MAX_SIZE 10000

int toInt(char c) {
    return c - '0';
}

char toChar(int i) {
    return i + '0';
}

char* reverse(const char *input) {
    char *reversed = malloc(sizeof(char) * 10000);
    unsigned long len = strlen(input);

    for(int i = 0; i < len; i++) {
        reversed[i] = input[len - i - 1];
    }
    reversed[len] = '\0';
    return reversed;
}

void divide(char *div1, char *div2, char *input) {
    unsigned long inputLength = strlen(input);
    unsigned long firstHalf = inputLength / 2;

    if (inputLength % 2 != 0) {
        firstHalf++;
    }

    unsigned long extraHalf = inputLength - firstHalf;

    strncpy(div1, input, firstHalf);
    strncpy(div2, input + firstHalf, inputLength - firstHalf);
    div1[firstHalf] = '\0';
    div2[extraHalf] = '\0';
}

char* multiplyIntString(char *input1, char *input2) {

    int input1Int = atoi(input1);
    int input2Int = atoi(input2);
    int resultInt = input1Int * input2Int;

    char *result = malloc(MAX_SIZE * sizeof(char));

    sprintf(result, "%d", resultInt);
    return result;
}
