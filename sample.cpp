#include<iostream>

//My 2nd Comment

int main()
{
 std::cout << "Hello\n";
 int i = 0;
 for(int j = 0; j < 10; ++j)
 {
  i += (j * j);
	std::cout << "i is: " << i << " and j is: " << j << std::endl;
 }

 return 0;
}
