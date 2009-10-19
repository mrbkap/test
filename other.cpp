#include <iostream>
#include "foo.h"

using namespace std;

namespace foo {

int baz = 4;

}

int
bar()
{
    if (foo::has_flag(0x7, 0x4)) {
        cout << "bar has\n";
    } else {
        cout << "bar doesn't have\n";
    }

    cout << foo::baz << '\n';
    return 0;
}
