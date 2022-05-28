#include "utils.hpp"
#include "error_message.hpp"

bool	isValidFilename(std::string file)
{
	size_t	haveDot = file.find(".txt");
	if (haveDot == std::string::npos || file.length() != (haveDot + 4) || file[0] == '.') {
		return false;
	}
	return true;
}

size_t	parseFile(int argc, char *argv[])
{
	if (argc < 2) {
        throw ErrorMessage ("\n\t[File ERROR]: No path file from which to read the Graph!");
    } else if (argc < 3) {
        throw ErrorMessage ("\n\t[Input ERROR]: No length of simple cycles was specified!");
    }
	std::string file = argv[2];
    if (!isValidFilename(file)){
        throw ErrorMessage("\n\t[Extension ERROR]: Not valid file extension. MUST BE [.txt]");
    }

	size_t  len = atoi(argv[1]);
    if (!len) {
        throw ErrorMessage("\n\t[Input ERROR]: Not valid length of simple cycles specified!");
    }

	return len;
}
