#include <stdio.h>
#include <string.h>

int main() {

char name[100];

printf("Enter your full name:  ");
scanf("%s", &name);

printf("Hello %s!!", name);

int length=strlen(name);
printf("The length of your name is: %i\n");
return 0;


}
