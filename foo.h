#ifndef FOO_H
#define FOO_H

#include <stdint.h>

int bar();

namespace foo {

extern int baz;

inline bool has_flag(uint32_t v, uint32_t flags)
{
    return (v & flags) != 0;
}

inline bool mythrow()
{
    return false;
}

}

#endif
