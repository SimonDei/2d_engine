#ifndef _IOUTIL_HPP_
#define _IOUTIL_HPP_

#include <string>
#include <fstream>
#include <algorithm>


namespace sde {
	namespace {

	}

	static bool file_exists(const std::string& path) {
		std::ifstream file{ path };
		bool exists = file.good();
		if (file.is_open()) file.close();
		return exists;
	}

	static std::string get_file_extension(const std::string& path) {
		std::string extension = path.substr(path.find_last_of('.') + 1);
		std::transform(extension.begin(), extension.end(), extension.begin(), toupper);
		return extension;
	}
}

#endif