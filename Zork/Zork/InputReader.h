#pragma once
#include <vector>
#include <string>

class InputReader
{
public:
	static std::vector<std::string> Tokenize(const std::string& line);
};
