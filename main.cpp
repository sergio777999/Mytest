#include "./func.h"
#include<string>
#include<iostream>

int main()
{
 std::string str("Hello world");
 func(str);

 int i = 0;
 for(int j = 0; j < 10; ++j)
 {
  i += (j * j);
	std::cout << "i is: " << i << " and j is: " << j << std::endl; 
 }
 return 0;
}
