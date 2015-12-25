#include <iostream>
#include <string>
#include <memory>
#include <unordered_map>
using namespace std;

struct Animal
{
    Animal() { cout << "Animal()\n"; }
    Animal(const Animal&) { cout << "Animal(const Animal&)\n"; }
    virtual ~Animal() { cout << "~Animal()\n"; }
    virtual void talk() const = 0;
};

struct Dog : Animal
{
    Dog() { cout << "Dog()\n"; }
    Dog(const Dog&) { cout << "Dog(const Dog&)\n"; }
    ~Dog() { cout << "~Dog()\n"; }
    virtual void talk() const { cout << "woof\n"; }
};

struct Cat : Animal
{
    Cat() { cout << "Cat()\n"; }
    Cat(const Cat&) { cout << "Cat(const Cat&)\n"; }
    ~Cat() { cout << "~Cat()\n"; }
    virtual void talk() const { cout << "meow\n"; }
};

int main()
{
    unordered_map<string, unique_ptr<Animal>> map;
    uint32_t i = 0;

    string name;
    while (cin >> name) {
        unique_ptr<Animal> a {
            (i++ % 2) ?
                static_cast<Animal*>(new Cat()) :
                static_cast<Animal*>(new Dog())
        };
        map[name] = std::move(a);
    }

    for (auto i = map.cbegin(); i != map.cend(); ++i) {
        cout << i->first << " says ";
        i->second->talk();
    }

    return 0;
}
