#ifndef FILE_READER
#define FILE_READER
#include <fstream>
#include <map>
#include <set>
class FileReader{
	std::ifstream file;
public:
	FileReader(std::string path);
	std::map<std::string, char> get_keys();
	~FileReader();
};
#endif
