#include "filewriter.h"

FileWriter::FileWriter(std::string path){
	file.open(path);
}

void FileWriter::write(EventMessage& mes){
	file << mes;
}

FileWriter::~FileWriter(){
	std::cout << "FILE CLOSED!\n";
	file.close();
}
