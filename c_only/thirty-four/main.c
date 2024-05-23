#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include <stdbool.h>
#include <time.h> 
#include <math.h> 
#include <ctype.h> 

static int w = 1;

typedef struct PIXEL {
    int x, y;
    char name[20];
}Pixel;

typedef struct POINT
{
 float x, y;
}Point;

void pixelDisplay(Pixel p)
{
    printf("\nPixel:\n\tX: %d\n\tY: %d\n\tColor: %s\n", p.x, p.y, p.name);
}

void pointDisplay(Point p)
{
    printf("\nPoint %d: \t{ %f : %f }\n", w, p.x, p.y);
    w++;
}

float pointDistance(Point ptA, Point ptB)
{
    return sqrt(pow(ptB.x-ptA.x, 2) + pow(ptB.y-ptA.y, 2));
}


int main()
{
    Pixel p1 = {12,3,"Red"};
    Pixel p2 = {24,5,"Green"};

    Point point1 = {11.2,22.88};
    Point point2 = {17.8,42.2};

    pixelDisplay(p1);
    pixelDisplay(p2);

    pointDisplay(point1);
    pointDisplay(point2);
    float res = pointDistance(point1, point2);
    printf("Distance AB: %f\n", res);

    return 0;
}