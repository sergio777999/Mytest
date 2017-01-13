#include <vector>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

std::vector<int> target2(15);
std::vector<int> target3;

template <typename RangeOfInts>
void foo(RangeOfInts source)
{
 std::vector<int> target1{std::begin(source), std::end(source)};
 for (auto& it : target1) 
 					std::cout << it << " ";
 std::cout << std::endl;

 std::copy(std::begin(source), std::end(source), std::begin(target2));
 for(auto& it : target2)
 					std::cout << it << " ";
 std::cout << std::endl;

 std::copy(std::begin(source), std::end(source), std::back_inserter(target3));
 for(auto& it : target3)
 					std::cout << it << " ";

 std::cout << std::endl;
}

int main()
{
 pid_t pid;
 /* get the process id */
 if ((pid = getpid()) < 0) {
      std::cout << std::endl << "Unable to get pid" << std::endl;
 }
 else {
 std::cout << std::endl << "The process id is: " << pid << std::endl;
 }
 std::vector<int> v{23, 65, 3, 94, 398, 3894, 1738, 5};
 foo(v);
 return 0;
}
