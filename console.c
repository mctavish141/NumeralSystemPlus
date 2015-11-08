//
//  console.c
//  Console
//
//  Created by Serhii Kopach on 08.11.15.
//  Copyright (c) 2015 Serhii Kopach. All rights reserved.
//

#include <stdio.h>

void gotoxy (int x, int y) {
    printf ("\033[%d;%df", x+1, y+1);
}

void clrscr () {
    printf ("\033[2J");
    printf ("\033[0;0f");
}

void setAttribute (int attribute) {
    printf ("\033[%dm", attribute);
}

void setColors (int mainColor, int backgroundColor) {
    printf ("\033[%d;%dm", mainColor, backgroundColor);
}

int main () {
    gotoxy(5, 10);
    
    return 0;
}
