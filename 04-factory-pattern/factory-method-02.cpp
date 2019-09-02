#include <iostream>

enum codec_type
{
    AVC,
    HEVC
};

class Codec
{
public:
    virtual void encode() = 0;
    virtual void decode() = 0;
    static Codec* create(codec_type t);
};

class H264 : public Codec
{
public:
    void encode()
    {
        std::cout << "H264 Encode" << std::endl;
    }

    void decode()
    {
        std::cout << "H264 Decode" << std::endl;
    }
};

class H265 : public Codec
{
public:
    void encode()
    {
        std::cout << "H265 Encode" << std::endl;
    }

    void decode()
    {
        std::cout << "H265 Decode" << std::endl;
    }
};

Codec* Codec::create(codec_type t)
{
    if(t == AVC)
        return new H264();
    else if(t == HEVC)
        return new H265();
    else
        return nullptr;
}

int main(void)
{
    Codec *c = Codec::create(HEVC);
    c->encode();
    c->decode();

    return 0;
}
