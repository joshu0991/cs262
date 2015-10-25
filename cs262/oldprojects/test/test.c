#include <stdio.h>
#include <stdint.h>
int main()
{
    int a[3] = {5, 6, 7};
    int *ptr = a, val;
    val = *((int*)((uintptr_t)ptr + sizeof(int))) - *(ptr + 1);

    printf("%d\n", val);
    return 0;
}
