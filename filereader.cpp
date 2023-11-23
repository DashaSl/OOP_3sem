#include "filereader.h"

FileReader::FileReader(std::string path){
	file.open(path);
}
std::map<std::string, char> FileReader::get_keys(){
	std::map<std::string, char> mapa //used if error occurred
	{
		{"up", 'w'}, {"right", 'd'}, {"down", 's'}, {"left", 'a'}, {"exit", 'q'}, {"new", 'e'}
	};
	std::map<std::string, char> actual_mapa; //what we gonna get
	std::set<char> used_keys;
	std::set<std::string> allowed_names {"up", "down", "left", "right", "exit", "new"};
	char tmp;
	if(!file){
		return mapa;
	}
	std::string action;
	std::string key;
	while(!file.eof()){
		file >> action;

		if(file.eof()){
			return mapa;
		}

		file >> key;

		if(key.size() != 1){
			return mapa;
		}

		tmp = key[0];

		if(used_keys.count(tmp) || !allowed_names.count(action) || actual_mapa.count(action)){
			return mapa;
		}

		actual_mapa[action] = tmp;
		used_keys.insert(tmp);
		allowed_names.erase(action);

	}

	if(actual_mapa.size() != mapa.size()){
		return mapa;
	}
	return actual_mapa;

}
FileReader::~FileReader(){
	file.close();
}
