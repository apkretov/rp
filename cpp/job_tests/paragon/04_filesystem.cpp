/*
//#include "stdafx.h"
//#include "targetver.h"
//#include <stdio.h>
//#include <tchar.h>
#include <string>
#include <iostream>
//#include <filesystem>
//#include <experimental/filesystem>
#include <experimental/filesystem>

using namespace std;
namespace fs = experimental::filesystem;

int main04() {
	//string path = /"c:";
	string path = "/home/alex/";
	for (auto & p : fs::directory_iterator(path))
		cout << p << endl;
	int n;
	cin >> n;
	return 0;
}
*/
