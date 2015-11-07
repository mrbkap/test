#include <iostream>
using namespace std;

int
main()
{
    char c = 'a';
    cout << *reinterpret_cast<uint8_t*>(&c) << '\n';
    return 0;
}
