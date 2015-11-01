//
//  main.c
//  Strings
//
//  Created by Serhii Kopach on 01.11.15.
//  Copyright (c) 2015 Serhii Kopach. All rights reserved.
//

#include <stdio.h>
#include <string.h>

char *process (char *resultStr, const char *textLines [], int linesNum, const char *extraStr) {
    int maxCounter = 0;
    int maxIndex = 0;
    
    for (int i = 0; i < linesNum; i++) {
        int counter = 0;
        for (int j = 0; j < linesNum; j++) {
            if (strcmp(textLines[i], textLines[j]) == 0) {
                counter++;
            }
        }
        if (counter > maxCounter) {
            maxCounter = counter;
            maxIndex = i;
        }
    }
    
    char tempResult[100];
    sprintf(tempResult, "%d, %s", maxCounter, textLines[maxIndex]);
    resultStr = tempResult;
    return resultStr;
}

int main () {
    const char *textLines [] = {"Hello", "Hello", "Hello", "world", "world", "world", "hi", "world"};
    int linesNum = 8;
    char *resultStr = "";
    resultStr = process(resultStr, textLines, linesNum, NULL);
    
    printf("%s\n", resultStr);
    
    return 0;
}
