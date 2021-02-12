//
//  StringExtensions.h
//  Extensions
//
//  Created by changnam hong on 2021/02/12.
//

#ifndef StringExtensions_h
#define StringExtensions_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int toInt(char c);
char toChar(int i);

/// Reverse String
char* reverse(const char *input);

/// Divide String
void divide(char *div1, char *div2, char *input);

/// Multiply Int String using atoi
char* multiplyIntString(char *input1, char *input2);

#endif /* StringExtensions_h */
