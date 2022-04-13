#include <iostream>
#include <string.h>

/*
To mock a private member function, the function has
to be virtual.
*/ 
class ClassA {
public:
    std::string getName(std::string key) {
        int value = 2;
        int code = getCode(value);
        if (code != 2)
            return "Error";
        return "XYZ";
    }

private:
    virtual int getCode(int value) {
        if (value == 2)
            return 2;
        return -1;
    }
};