
#include <stdio.h>
#include "FileUtil.h"

int main(int argc, char **argv)
{
	if (argc >= 2) {
		std::string path = FileUtil::which(argv[1]);
		if (!path.empty()) {
			puts(path.c_str());
		}
	}
	return 0;
}

