#include <iostream>
#include <type_traits>
using std::ostream;
using std::cout;

template<class E>
void
F(const E& e)
{
    static_assert(std::is_enum<E>::value, "E should be an enum");
    if (e == E::A) {
        cout << "It's an A!\n";
    } else {
        cout << "it isn't an A!\n";
    }
}

enum class Enum { A, B, C } c;

ostream&
operator <<(ostream& lhs, const Enum& e)
{
    switch (e) {
        case Enum::A:
            lhs << 'A';
            break;
        case Enum::B:
            lhs << 'B';
            break;
        case Enum::C:
            lhs << 'C';
            break;
        default:
            // Possible via static_cast!
            lhs << '?';
            break;
    }

    return lhs;
}

int
main()
{
    Enum c = static_cast<Enum>(2);
    cout << c << '\n';
    F(c);
    F<Enum>(Enum::A);
    return 0;
}
