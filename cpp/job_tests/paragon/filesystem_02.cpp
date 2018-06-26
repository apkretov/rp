/*
#include "stdafx.h"
#include <fstream> //std::filesystem::directory_iterator @ https://en.cppreference.com/w/cpp/filesystem/directory_iterator
#include <iostream>
#include <filesystem>
//namespace fs = std::filesystem;
namespace fs = std::experimental;
 
int main() {
    fs::create_directories("sandbox/a/b");
    std::ofstream("sandbox/file1.txt");
    std::ofstream("sandbox/file2.txt");
    for(auto& p: fs::directory_iterator("sandbox"))
        std::cout << p << '\n';
    fs::remove_all("sandbox");
}
*/