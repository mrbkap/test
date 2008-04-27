#include <iostream>
#include <sstream>
using namespace std;

int
main(int argc, const char *argv[])
{
    ostringstream os;

    os << "HI THERE";

    const char *str = os.str().c_str();
    return 0;
}
