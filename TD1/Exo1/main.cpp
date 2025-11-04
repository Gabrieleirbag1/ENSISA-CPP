#include<iostream>
#include<string>
#include "main.h"
#include "my_class.h"

using namespace std;

void myprintf(string str_value) {
    cout << str_value << endl;
}

int main() {
    cout << "Hello World !" << endl; 
    myprintf("Hello World !");
    MyClass myclassobj;
    myclassobj.print_my_element("test");

    return 0;
}


