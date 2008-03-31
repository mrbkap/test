#include <iostream>
#include <set>
#include <iterator>
#include <string>
using namespace std;

void
parse(int cur, set<int> &s)
{
    char ch;
    cin >> ch;
    if (ch != '(')
        throw string("malformed input: ") + ch;

    while (isspace(cin.peek()))
        cin.get();

    // Empty?
    if (cin.peek() == ')') {
        cin.get();
        s.insert(cur);
        return;
    }

    int n;
    cin >> n;

    // No, parse the kids.
    parse(cur + n, s);
    parse(cur + n, s);

    // Collect our close paren.
    cin >> ch;
}

void
process()
{
    int find;
    if (!(cin >> find))
        return;

    set<int> s;
    parse(0, s);

    if (s.find(find) != s.end())
        cout << "yes\n";
    else
        cout << "no\n";
}

int
main()
{
    try {
        while (cin)
            process();
    } catch (const string &s) {
        cout << "Error: " << s << '\n';
    }
    return 0;
}
