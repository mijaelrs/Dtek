#include <stdio.h>

int a = 2;
int *p;
p = &a;
*p = 3 + *p;
printf("p=0x%x a=%x\n", (unsigned int)p, a);
