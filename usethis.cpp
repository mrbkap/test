#include <iostream>
#include "foo.h"
using namespace std;

int
main()
{
    if (foo::has_flag(0x6, 0x2)) {
        cout << "has\n";
    } else {
        cout << "doesn't\n";
    }

    cout << foo::baz << '\n';
    bar();

    return 0;
}
