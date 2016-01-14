#include <iostream>
using namespace std;

template <class B>
class C : public B
{
public:
    C() : mN(N++) { cout << "C(" << mN << ")\n"; }
    ~C() { cout << "~C(" << mN << ")\n"; }
    C(const C& c) : mN(N++) { cout << "C(const C& " << c.mN << ") = " << mN << "\n"; }
    C(C&& c) : mN(N++) { cout << "C(C&& " << c.mN << ") = " << mN << "\n"; }

    C& operator =(C&& c) {
        cout << "C::operator = (C&& " << c.mN << ") = " << mN << "\n";
        return *this;
    }

private:
    int32_t mN;
    static int32_t N;
};

template<class B>
int32_t
C<B>::N = 0;

class O {};

int
main(int argc, char *argv[])
{
    C<O> c;
    return 0;
}
