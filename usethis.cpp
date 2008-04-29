#include <iostream>
#include <set>
using namespace std;

int
main(int argc, const char *argv[])
{
    set<int> s;

    s.insert(4);
    s.insert(5);
    s.insert(2);
    s.insert(1);
    s.insert(9);

    for (set<int>::const_iterator i = s.begin(); i != s.end(); ++i)
        cout << *i << "\n";
    return 0;
}
