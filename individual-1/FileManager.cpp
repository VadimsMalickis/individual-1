#include <iostream>
#include <fstream>
#include <string>
#include <vector>

size_t StudentManager::lineCount(const char* fileName)
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




