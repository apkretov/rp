/*
#include "stdafx.h"
#include <fstream> //std::filesystem::recursive_directory_iterator @ https://en.cppreference.com/w/cpp/filesystem/recursive_directory_iterator
#include <iostream>
#include <filesystem>
//namespace fs = std::filesystem;
namespace fs = std::experimental::filesystem;

int main() {
	fs::create_directories("sandbox/a/b");
	std::ofstream("sandbox/file1.txt");
	fs::create_symlink("a", "sandbox/syma");
	for (auto& p : fs::recursive_directory_iterator("sandbox"))
		std::cout << p << '\n';
	fs::remove_all("sandbox");
	return 0;
}
*/