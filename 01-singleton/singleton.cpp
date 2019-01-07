// Compile the program with
// g++ singleton.cpp -o singleton

// Run the program with
// ./singleton

#include <iostream>

class Singleton
{
public:
    static Singleton* getInstance()
    {
        if(instance == nullptr)
            instance = new Singleton();

        return instance;
    }

private:
    static Singleton *instance;
    Singleton() {}
};

Singleton* Singleton::instance = nullptr;

int main(void)
{
    Singleton *one = Singleton::getInstance();
    Singleton *two = Singleton::getInstance();

    if(one != two)
        std::cout << "Error in Singleton class implementation" << std::endl;
    else
        std::cout << "Singleton implementation is correct" << std::endl;

    return 0;
}
