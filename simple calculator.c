#include <stdio.h>
int main() {
int num1, num2;
//input the two numbers
printf("Enter the first number: ");
scanf("%i", &num1);

printf("enter the second number: ");
scanf("%i", &num2);

//perfoming the operations
printf("addition: %i+%i= %i\n",num1,num2,num1+num2);
printf("subtraction: %i-%i=%i\n",num1,num2,num1-num2);
printf("multiplication: %i*%i=%i\n",num1,num2,num1*num2);
printf("division: %i/%i=%i\n",num1,num2,num1/num2);
printf("modulus: %i%%i=%i\n",num1,num2,num1%num2);

return 0;

}
