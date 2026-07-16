#include "InputReader.h"
#include <sstream>
#include <algorithm>

std::vector<std::string> InputReader::Tokenize(const std::string& line)
{
	std::vector<std::string> tokens;
	std::stringstream strstr(line);
	std::string word;

	while (strstr >> word)
	{
		//always convert the input to lowercase to make it case-insensitive
		std::transform(word.begin(), word.end(), word.begin(), ::tolower);
		tokens.push_back(word);
	}
	return tokens;
}