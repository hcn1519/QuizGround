//
//  main.c
//  KaratsubaMultiplication
//
//  Created by changnam hong on 2021/02/07.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int toInt(char c) {
    return c - '0';
}
char toChar(int i) {
    return i + '0';
}

char* multiplyBaseCase(char *input1, char *input2) {

    int input1Int = atoi(input1);
    int input2Int = atoi(input2);
    int resultInt = input1Int * input2Int;

    char *result = malloc(10000 * sizeof(char));

    sprintf(result, "%d", resultInt);

    return result;
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

void appendDigit(char *input, unsigned long digit) {

    char digits[1000];

    for(int i = 0; i < digit; i++) {
        digits[i] = '0';
    }
    digits[digit] = '\0';
    strcat(input, digits);
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

char *sumChar(const char *lhs, const char *rhs) {

    char *sum = malloc(sizeof(char) * 10000);

    unsigned long lhsLen = strlen(lhs);
    unsigned long rhsLen = strlen(rhs);

    unsigned long longerLen = lhsLen > rhsLen ? lhsLen : rhsLen;

    const char* reversedLhs = reverse(lhs);
    const char* reversedRhs = reverse(rhs);

    int upCount = 0;
    int digit = 0;
    for(digit = 0; digit < longerLen; digit++) {

        int digitSum = upCount;

        if (digit < lhsLen) {
            digitSum += toInt(reversedLhs[digit]);
        }

        if (digit < rhsLen) {
            digitSum += toInt(reversedRhs[digit]);
        }

        upCount = digitSum / 10;
        sum[digit] = toChar(digitSum % 10);
    }

    if (upCount != 0) {
        sum[digit] = toChar(upCount);
    }

    sum[digit + 1] = '\0';
    char *result = reverse(sum);

    return result;
}

char* multiply(char *input1, char *input2) {
    unsigned long inputDigit = strlen(input1);

    if (inputDigit < 4) {
        char *result = multiplyBaseCase(input1, input2);
        return result;
    }

    char div1[10000], div2[10000], div3[10000], div4[10000];

    divide(div1, div2, input1);
    divide(div3, div4, input2);

    char *ac = multiply(div1, div3);
    char *ad = multiply(div1, div4);
    char *bc = multiply(div2, div3);
    char *bd = multiply(div2, div4);

    unsigned long modifiedDigit = inputDigit;
    if (inputDigit % 2 != 0) {
        modifiedDigit--;
    }

    appendDigit(ac, modifiedDigit);

    char* adbc = sumChar(ad, bc);

    appendDigit(adbc, modifiedDigit / 2);

    char *result = sumChar(sumChar(ac, adbc), bd);
    return result;
}

int main(int argc, const char * argv[]) {

    char input1[10000];
    char input2[10000];

    printf("Input1: ");
    scanf("%s", input1);
    printf("Input2: ");
    scanf("%s", input2);

    if (strlen(input1) != strlen(input2)) {
        printf("Length of inputs are different\n");
        return 0;
    }

    const char *result = multiply(input1, input2);

    printf("Input1 %s, %lu\n", input1, strlen(input1));
    printf("Input2 %s, %lu\n", input2, strlen(input2));
    printf("Result %s\n", result);

    return 0;
}

/*
 test case
 x - 1234
 y - 5678
 result - 7006652

 x - 12345
 y - 12345
 result - 152399025

 x - 10101
 y - 10101
 result - 102030201

 x - 123456
 y - 123456
 result - 15241383936

 x - 3141592653589793238462643383279502884197169399375105820974944592
 y - 2718281828459045235360287471352662497757247093699959574966967627
 result - 8539734222673567065463550869546574495034888535765114961879601127067743044893204848617875072216249073013374895871952806582723184
 */
