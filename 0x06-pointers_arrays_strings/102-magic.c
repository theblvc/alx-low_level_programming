#include <stdio.h>

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int a[5];
    int *p;

    a[2] = 1024;
    p = &a[2];

    /* Add the new line of code here */
    *((int *)((char *)p + sizeof(int))) = 98;

    printf("a[2] = %d\n", a[2]);
    return (0);
}
