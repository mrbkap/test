template <class T>
class H
{
public:
    H(T* t) : mT(t) {}
    ~H() { delete mT; }

private:
    T* mT;
};

class A
{
    friend class H<A>;
private:
    virtual ~A();
};

A::~A()
{
}

class B : public A
{
    virtual ~B();
};

B::~B()
{
}

int
main()
{
    H<A> b(new B);
    return 0;
}
