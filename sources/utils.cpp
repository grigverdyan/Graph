#include "../includes/utils.hpp"

bool	isValidFilename(string file)
{
	size_t	haveDot = file.find(".txt");
	cout << "\n" << file.length() << " " << haveDot + 4 << endl;
	if (haveDot == string::npos || file.length() != (haveDot + 4) || file[0] == '.') {
		return false;
	}
	return true;
}
