#include <stdio.h>
#include <math.h>
int main(int argc, char *argv[])
{
    int a = 6427 +1725 ;
    int b = (6971 * 3925) - 95;
    double c = 79 + 12 / 5;
    double d = 3640.0 / 107.9;
    int e = (22 / 3) * 3;
    int f = (22 / (3*3));
    double g = 22 / (3*3);
    double h  = 22 / 3 * 3;
    double i = (22.0 / 3) * 3.0;
    int j = 22.0 / (3 * 3.0);
    double k = 22.0 / 3.0 * 3.0;

    printf("a is %d\n", a);
    printf("b is %d\n", b);
    printf("c is %lf\n", c);
    printf("d is %lf\n", d);
    printf("e is %d\n", e);
    printf("f is %d\n", f);
    printf("g is %lf\n", g);
    printf("h is %lf\n", h);
    printf("i is %lf\n", i);
    printf("j is %d\n", j);
    printf("k is %lf\n", k);


    double circumfrence = 23.567;
    double radius;
    double area;


    radius = circumfrence / 2 / M_PI;
    area = radius * radius * M_PI;
    printf("The area of the circle is %lf\n", area);




    double feet = 14.0;
    double meters; 

    meters = feet / 3.048;
    printf("There are these many meters %lf\n", meters);




    double fahrenheit = 76;
    double celsius;

    celsius = (fahrenheit - 32) / 1.8;

    printf("In celsius it is %lf degrees\n", celsius);





}