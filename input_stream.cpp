#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>

int main()
{
 std::istringstream stream{"This stream\n"
 														"contains many\n"
															"lines.\n"};
 std::string line;
 while (std::getline(stream, line)) 
 {
  // Process line
	std::cout << line << std::endl;
 }

 std::ifstream inFile{ R"(./stat.txt)" };
 if(!inFile)
 {
  std::cout << "File's could not be open. Exiting..." << std::endl;
	return 1;
 }
 else
 {
  while(std::getline(inFile, line))
			std::cout << line << std::endl;
 }

 inFile.close();
 
 std::istringstream stream_1{ "1 2 3 5 7 89 8 90 12" };
 std::vector<int> v{};
 int i{};
 while(!stream_1.eof())
 {
  stream_1 >> i;
	v.push_back(i);
 }
 for(auto& it : v)
 		std::cout << it << " ";

 std::cout << std::endl;
 
 std::istringstream stream_2{"Chief Executive Officer\n"
 															"John Smith\n"
																	"32"};
 std::string position;
 std::string first_name;
 std::string family_name;
 int age;
 getline(stream_2, position);
 stream_2 >> first_name >> family_name >> age;
 std::cout << position << " " << first_name << " " << family_name << " " << age << std::endl;
 
return 0; 
}
