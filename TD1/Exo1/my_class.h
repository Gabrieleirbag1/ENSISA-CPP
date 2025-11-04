#ifndef MY_CLASS_H
#define MY_CLASS_H

#include <string>

class MyClass
{
    public:
        MyClass() {};
        
        MyClass(std::string str_value);
        void print_my_element(std::string str_value);
    private:
        std::string t_str_value;
};

#endif