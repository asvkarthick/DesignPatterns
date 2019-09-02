#include <iostream>

enum hal_type
{
    HAL1,
    HAL3
};

class Hal
{
public:
    virtual void print() = 0;
    static Hal* create(hal_type t);
};

class Hal1 : public Hal
{
public:
    void print()
    {
        std::cout << "HAL1" << std::endl;
    }
};

class Hal3 : public Hal
{
public:
    void print()
    {
        std::cout << "HAL3" << std::endl;
    }
};

Hal* Hal::create(hal_type t)
{
    if(t == HAL1)
        return new Hal1();
    else if(t == HAL3)
        return new Hal3();
    else
        return nullptr;
}

int main(void)
{
    Hal *h = Hal::create(HAL3);
    h->print();

    return 0;
}
