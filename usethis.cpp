#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
using namespace std;

namespace {
    void expected(int ch, int expected);
    size_t col = 0;
    char next();
}

namespace {

void
expected(int ch, int expected)
{
    if (ch != expected) {
        ostringstream os;
        os << "Unexpected character: " << static_cast<char>(ch) << " (" << ch << ")\n";
        throw os.str();
    }
}

char
next()
{
    int ch = cin.get();
    if (ch == EOF) {
        string error = "Unexpected EOF\n";
        throw error;
    }

    ++col;
    return ch;
}

}

int
main()
{
    try {
        int ch;
        while ((ch = cin.get()) != EOF) {
            ++col;
            while (isspace(ch)) {
                ch = cin.get();
                ++col;
                if (ch == EOF) {
                    return EXIT_SUCCESS;
                }
            }
            expected(ch, '\'');
            ch = next();
            if (ch == '\\') {
                switch (ch = next()) {
                    case 'n':
                        ch = '\n';
                        break;
                    case 't':
                        ch = '\t';
                        break;
                    case '\'':
                        ch = '\'';
                        break;
                    default: {
                        string error = "Unknown escape sequence: ";
                        error += static_cast<char>(ch);
                        error += '\n';
                        throw error;
                    }
                }
            }

            cout << static_cast<char>(ch);
            expected(next(), '\'');
        }
    } catch (const std::string &str) {
        cerr << "Oops " << col << "! " << str;
    }

    return EXIT_SUCCESS;
}
