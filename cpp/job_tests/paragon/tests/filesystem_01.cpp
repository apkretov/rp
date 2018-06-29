/*
//#include "stdafx.h"
#include <string> // ОБНОВЛЕНИЕ 2017: В С++ 17 теперь есть официальный способ перечислить файлы вашей файловой системы: std::filesystem. Ниже приведен отличный ответ от Shreevardhan с этим исходным кодом: @ http://qaru.site/questions/17239/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c //UPDATE 2017: @ https://stackoverflow.com/questions/612097/how-can-i-get-the-list-of-files-in-a-directory-using-c-or-c
#include <iostream>
#include <filesystem>
//namespace fs = std::filesystem;
namespace fs = std::experimental::filesystem; //c++17 `filesystem` is not a namespace-name @ https://stackoverflow.com/questions/48312460/c17-filesystem-is-not-a-namespace-name

int main() {
    //std::string path = "path_to_directory";
	std::string path = ".";
    for (auto & p : fs::directory_iterator(path))
        std::cout << p << std::endl;
	 return 0;
}
*/
