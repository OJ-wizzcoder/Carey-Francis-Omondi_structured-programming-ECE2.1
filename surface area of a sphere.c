#include <stdio.h>
int main() {
float radius,area;
//data input
printf("enter the radius of the sphere: ");
scanf("%f", &radius);

//area calculation
area= 4*3.142*radius*radius;

//data output
printf("the area of the sphere is: %f\n", area);

return 0;

}
