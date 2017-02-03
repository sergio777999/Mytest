#include<iostream>
#include"functions.h"
#include<cassert>

using std::cout;
using std::endl;

int main()
{
 int i{5}, j{20};
 int (*pfun[])(int, int){fun::sum, fun::product, fun::difference};

 cout << pfun[0](3, 4) << endl;
 cout << pfun[1](5, 9) << endl;
 cout << pfun[2](10, 7) << endl;
 cout << pfun[0](i, j) << endl;
 i = 15;
 j = 25;
 cout << pfun[0](i, j) << endl;

 cout << pfun[3](5, 7) << endl;
// assert(5<3);
 
 return 0;
}
