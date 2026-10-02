#include <stdio.h>
#include <stdlib.h>

int main()
{
    double area;
    const double pi= 3.142;
    double r;
    //capture the input from the user;
    printf("enter the radius of the circle:");
    scanf("%lf", &r);
    area= pi*r*r;
    printf("area of the circle is: %.2f\n", area);
    return 0;
}
