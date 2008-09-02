#include <stdio.h>
#include <stdint.h>

int
main()
{
    int32_t new_size = 0;

    new_size = 0xff;

    printf("0x%08x\n", new_size);
    return 0;
}
