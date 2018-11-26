#include <string>
#include <fstream>
#include <string>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "openFile.hpp"

const std::string openFile::tmpfileName = "tmpfile.txt";

openFile::openFile(std::string fileName)
{
	fileDesc = open(fileName.c_str(), O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	nameOfFileDesc = fileName;
}

openFile::~openFile()
{
	close(fileDesc);
}

int openFile::getFileDesc()
{
	return fileDesc;
}

std::string openFile::getFileContent()
{
	return getThisFileContent(nameOfFileDesc);
}

std::string openFile::getThisFileContent(std::string fileName)
{
	std::ifstream file(fileName, std::ios::in | std::ios::binary);
	if (file.is_open())
	{
		std::string content;
		file.seekg(0, std::ios::end);
		content.resize(file.tellg(), ' ');
		file.seekg(0, std::ios::beg);
		file.read(&(content[0]), content.size());
		file.close();
		return(content);
	}
	else
	{
		return "";
	}
}

std::string openFile::getTmpfileContent()
{
	return getThisFileContent(tmpfileName);
}
