#include <iostream>

using namespace std;

class Object
{
private:
    Object() = default;
    ~Object() = default;
public:
    static Object& getInstance()
    {
        static Object instance;
        return instance;
    }
    Object(const Object&) = delete;
    Object(Object&&) = delete;
};

int main()
{
    Object::getInstance();
    return 0;
}