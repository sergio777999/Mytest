#include "./func.h"
#include<iostream>
#include<string>

void func(std::string& s)
{
 std::cout << "Original string: " << s << std::endl;
 s += " + new text";
 std::cout << "Modified string: " << s << std::endl;
}

/////////

///////
