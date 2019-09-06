#include <iostream>

class Codec
{
public:
    void readInput()
    {
        std::cout << "Reading input" << std::endl;
    }

    void writeOutput()
    {
        std::cout << "Writing output" << std::endl;
    }

    virtual void encode() = 0;

    virtual void decode() = 0;
};

class H264: public Codec
{
public:
    void encode()
    {
        std::cout << "H.264 Encode" << std::endl;
    }

    void decode()
    {
        std::cout << "H.264 Decode" << std::endl;
    }
};

class H265: public Codec
{
public:
    void encode()
    {
        std::cout << "H.265 Encode" << std::endl;
    }

    void decode()
    {
        std::cout << "H.265 Decode" << std::endl;
    }
};

int main(void)
{
    Codec *h264 = new H264();
    Codec *h265 = new H265();

    h264->readInput();
    h264->encode();
    h264->writeOutput();

    h265->readInput();
    h265->decode();
    h265->writeOutput();

    return 0;
}
