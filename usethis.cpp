#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdint.h>

int
main()
{
    uint32_t size1 = 0xffffffff;
    const uint16_t size2 = size1;

    void *ptr = malloc(size2);
    assert(ptr);
    memset(ptr, 0, size1);
    free(ptr);
    return 0;
}
