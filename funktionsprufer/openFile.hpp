#ifndef OPENFILE_HPP
#define OPENFILE_HPP

#include <string>

class openFile
{
public:
	openFile(std::string fileName);
	~openFile();
	int getFileDesc();
	std::string getFileContent();
	static std::string getThisFileContent(std::string fileName);
	static std::string getTmpfileContent();
public:
	static const std::string tmpfileName;
private:
	int fileDesc;
	std::string nameOfFileDesc;
};

#endif
