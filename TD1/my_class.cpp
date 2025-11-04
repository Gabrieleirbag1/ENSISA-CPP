#include <iostream>
#include "my_class.h"

MyClass::MyClass(std::string str_value):
t_str_value(str_value)
{
    t_str_value = str_value;
}

void MyClass::print_my_element(std::string str_value) {
    std::cout << str_value << std::endl;
}