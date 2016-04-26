#ifndef FILEUTIL_H
#define FILEUTIL_H

#include <string>
#include <vector>

class FileUtil {
public:
	struct DirEnt {
		std::string name;
		bool isdir = false;
	};

	static std::string getcwd();
	static void mkdir(std::string const &dir, int perm = 0777);
	static void rmdir(const std::string &dir);
	static void chdir(std::string const &dir);
	static void rmfile(const std::string &path);
	static void rmtree(const std::string &path);
	static void mv(const std::string &src, const std::string &dst);
	static void getdirents(std::string const &loc, std::vector<DirEnt> *out);
	static std::string which(const std::string &name);
};

#endif // FILEUTIL_H
