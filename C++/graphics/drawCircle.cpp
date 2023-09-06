#include <graphics.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

void drawCircle(){

    int gd = DETECT, gm, color;
    initgraph(&gd, &gm, NULL);

    int x, y;
    int length = 60;
    float angle = 0.0;

    float angle_stepSize = 0.1;

    while(angle < 2* 3.14){
        x = length * cos(angle);
        y = length * sin(angle);

        putpixel(x, y, 255);
        angle = angle + angle_stepSize;
    }
}

int main(){

    drawCircle();
    return 0;
}