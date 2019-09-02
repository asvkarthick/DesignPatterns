#include <iostream>

class Hal
{
public:
    virtual void request() = 0;
};

class Hal1
{
public:
    void takePicture()
    {
        std::cout << __func__ << std::endl;
    }
};

class Hal3 : public Hal, Hal1
{
public:
    void request()
    {
        std::cout << __func__ << std::endl;
        takePicture();
    }
};

int main(void)
{
    Hal *h = new Hal3();
    h->request();

    return 0;
}
