#include "utils.hpp"

bool	isValidFilename(std::string file)
{
	size_t	haveDot = file.find(".txt");
	if (haveDot == std::string::npos || file.length() != (haveDot + 4) || file[0] == '.') {
		return false;
	}
	return true;
}
