#ifndef MY_CLASS_H
#define MY_CLASS_H

#include <string>

class MyClass
{
    private:
        std::string t_str_value;

    public:
        MyClass(std::string t_str_value);
        void print_my_element(std::string t_str_value);
};

#endif