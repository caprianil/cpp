// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>


template<typename T>
T *get_temporary_address(T &&x) {
    return &x;
}

int bar() { return 42; }

class Base {
    public:
    Base()
    {
        std::cout << "Base::Base() constructor" << std::endl;
    }

    Base(Base &&arg)
    {
        std::cout << "Base::Move Constructor" << std::endl;
    }

    Base& operator=(Base&& rhs)
    {
        std::cout << "Base::operator=(&&)" << std::endl;
        return *this;
    }
};

class Derived: public Base {
  public:
    Derived()
    {
        std::cout << "Derived::Derived() constructor" << std::endl;
    }

    Derived(Derived &&arg):
        Base(std::move(arg))
    {
        std::cout << "Derived::Move Constructor" << std::endl;
    }

    Derived& operator=(Derived &&rhs)
    {
        Base::operator=(std::move(rhs));
        std::cout << "Derived::operator =" << std::endl;
        return *this;
    }

};

int main() {

    Derived d1;
    Derived d2 = std::move(d1);

    // Write C++ code here
    std::cout << "Hello world!  " << &d1 << std::endl ;
    std::cout << (const void *)get_temporary_address(std::move(d1)) << std::endl;
    return 0;
}