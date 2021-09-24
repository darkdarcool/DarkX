#include <stdio.h>
#include <fstream>
#include <iostream>
#include "./lexer/lexer.hpp"
#include "./runner/runner.hpp"
#include <string.h>

using namespace std;

int main(int argc, char *argv[]) {
  if (argc == 1) {
		printf("Help command!\n");
		return 0;
	}
	std::ifstream ifs(argv[1]);
  std::string content((std::istreambuf_iterator<char>(ifs) ),(std::istreambuf_iterator<char>()));
	// TODO: Make a header checker to check an application, this is important for security
	runner(lexer(content)); // parse code, run it
}