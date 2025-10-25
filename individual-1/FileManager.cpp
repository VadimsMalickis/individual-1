#include <iostream>
#include <fstream>
#include <string>
#include "FileManager.h"

bool FileManager::writeStudent(std::string stStr)
{
	std::ofstream file;
	file.open(FileManager::stFileName, std::ios::app);
	if (file.is_open())
	{
		file << stStr << std::endl;
		file.close();
		return true;
	}
	return false; 
}

void FileManager::readAllStudents()
{
	std::ifstream file;
	file.open(FileManager::stFileName);
	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			std::cout << line << std::endl;
		}
		file.close();
	}
}
