#define TESTFUNCTION

#ifdef TESTFUNCTION
#include<iostream>
#endif

#include"functions.h"

int fun::sum(int x, int y)
{
 #ifdef TESTFUNCTION
 std::cout << "function sum called." << std::endl;
 #endif

 return x+y;
}

int fun::product(int x, int y)
{
 #ifdef TESTFUNCTION
 std::cout << "function product called." << std::endl;
 #endif
 
 return x*y;
}

int fun::difference(int x, int y)
{
 #ifdef TESTFUNCTION
 std::cout << "function difference called." << std::endl;
 #endif

 return x-y;
} 
			 
