#include <iostream>
#include <inttypes.h>
using namespace std;

template <int N>
struct Fib {
    enum { result = Fib<N - 1>::result + Fib<N - 2>::result };
};

template<>
struct Fib<1> {
    enum { result = 1 };
};

template<>
struct Fib<0> {
    enum { result = 0 };
};

int
main()
{
    cout << Fib<5>::result << '\n';
    return 0;
}
