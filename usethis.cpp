#include <iostream>
int
main(int argc, const char *argv[])
{
    std::cout << static_cast<int>('x' + 'k' + 'c' + 'd') - (4 * 'a' - 4) << '\n';
    return 0;
}
