#include <cctype>
#include <iostream>
using namespace std;

int
main(int argc, const char *argv[])
{
    int i = EOF;

    cout << "Answer: " << boolalpha << static_cast<bool>(isspace(i)) << '\n';

    i = ' ';
    cout << "Answer: " << boolalpha << static_cast<bool>(isspace(i)) << '\n';
    return 0;
}
