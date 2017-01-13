#include <thread>
#include <string>
#include <functional>
#include <iostream>

void func1()
{
 int x = 5;
}

void func(std::string str, int& x)
{
 str = "Hello";
 x = 10;
}
void do_something()
{
 std::cout << "Inside do_something" << std::endl;
}

int main()
{
 std::string str = "Test";
 int x = 5; 
 std::cout << "Str before: " << str << ", x: " << x << std::endl;

 std::thread t(func1); //(func, str, std::ref(x));
 t.join(); 
 do_something();
 
 //t.join(); 
 
 std::cout << "Str: " << str << ", x: " << x << std::endl;

 return 0;
 }
