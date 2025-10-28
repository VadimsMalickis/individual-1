#include <iostream>
#include <fstream>
#include <string>
#include "FileManager.h"

size_t FileManager::lineCount(const char* fileName)
{
	size_t count = 0;
	std::ifstream file;
	file.open(fileName);
	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			count++;
		}
		file.close();
	}
	return count;
}

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

std::string* FileManager::readAllStudents()
{
	const size_t lines = lineCount(FileManager::stFileName);
	if (lines == 0) {
		return nullptr;
	}
	std::string* students = new std::string[lines];

	std::ifstream file;
	file.open(FileManager::stFileName);
	
	if (file.is_open())
	{
		std::string line;
		for (size_t i = 0; i < lines && std::getline(file, line); i++) {
			students[i] = line;
		}
		file.close();
		return students;
	}
	delete[] students;
	return nullptr;
}
