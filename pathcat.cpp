
#ifdef WIN32
#pragma warning(disable:4996)
#endif

#include "pathcat_.h"

std::string pathcat(char const *left, char const *right)
{
	std::vector<char> vec;
	pathcat_(left, right, &vec);
	return std::string(&vec[0], vec.size());
}

std::string pathcat(std::string const &left, std::string const &right)
{
	char const *lb = left.c_str();
	char const *le = lb + left.size();
	char const *rb = right.c_str();
	char const *re = rb + right.size();
	std::vector<char> vec;
	pathcat_(lb, le, rb, re, &vec);
	return std::string(&vec[0], vec.size());
}
