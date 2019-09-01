#include <iostream>

class Interface
{
public:
    virtual void capture() = 0;
    virtual ~Interface() {}
};

class Camera: public Interface
{
public:
    Camera()
    {
        std::cout << "Loading camera" << std::endl;
    }

    void capture()
    {
        std::cout << "Capturing image" << std::endl;
    }
};

class CameraProxy: public Interface
{
public:
    CameraProxy() : mCamera(nullptr) {}

    void setup()
    {
        if(mCamera == nullptr) {
            mCamera = new Camera();
        } else {
            std::cout << "Camera setup already done" << std::endl;
        }
    }

    void capture()
    {
        if(mCamera == nullptr) {
            std::cout << "Please call setup before capture()" << std::endl;
            return;
        }

        mCamera->capture();
    }

private:
    Camera *mCamera;
};

int main(void)
{
    CameraProxy *p = new CameraProxy();

    p->capture();
    p->setup();
    p->capture();
    p->setup();

    return 0;
}
