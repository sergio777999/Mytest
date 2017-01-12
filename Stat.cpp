#include <sys/stat.h>
#include<iostream>
#include<string>

using namespace std;
/**
* Get the size of a file.
* @param filename The name of the file to check size for
* @return The filesize, or 0 if the file does not exist.
*/
size_t getFilesize(const std::string& filename) {
	struct stat st;
	if (stat(filename.c_str(), &st) != 0) {
		return 0;
	}
	return st.st_size;
}

int main()
{
	const string filename{ R"(./stat.txt)" };
	size_t size = getFilesize(filename);
	cout << "The file size is: " << size << endl;

	return 0;
}
