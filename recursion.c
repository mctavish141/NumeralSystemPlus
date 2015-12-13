//
//  main.c
//  Recursion
//
//  Created by Serhii Kopach on 13.12.15.
//  Copyright (c) 2015 Serhii Kopach. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

char recurs (char *str, int i, char firstHexElement, char lastHexElement) {
    // Getting current element
    char currentElement = tolower(str[i]);
    
    // If it is the end of the line – stop recursion
    if (currentElement == '\0') {
        return (firstHexElement < lastHexElement) ? firstHexElement : lastHexElement;
    }
    
    // If it is a hexadecimal element
    if (isxdigit(currentElement)) {
        if (firstHexElement == 0) {
            firstHexElement = currentElement;
        } else {
            lastHexElement = currentElement;
        }
    }
    
    // Continue recursion with next element of the line (i + 1)
    return recurs(str, i + 1, firstHexElement, lastHexElement);
}

int main() {
    char *str = malloc (100 * sizeof(char));
    printf("Enter string: ");
    scanf("%s", str);
    
    char result = recurs(str, 0, 0, 0);
    if (result == 0) {
        printf("There are less than 2 hexadecimal values in the string.\n");
    } else {
        printf("The smaller value is %c\n", result);
    }
    
    return 0;
}
