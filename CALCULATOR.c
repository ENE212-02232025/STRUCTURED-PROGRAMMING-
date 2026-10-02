#include <stdio.h>
#include <stdlib.h>

int main()
{

    float num1, num2;
    printf("enter two numbers:");
    scanf("%f %f",  &num1, &num2);

    printf("sum:%.2f\n",num1 + num2);
    printf("product:%.2f\n",num1 * num2);
    printf("quotient:%.2f\n",num1/num2);

    return 0;
}
