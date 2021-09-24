#include <iostream>
#include <sstream>

bool replace(std::string& str, const std::string& from, const std::string& to) {
    size_t start_pos = str.find(from);
    if(start_pos == std::string::npos)
        return false;
    str.replace(start_pos, from.length(), to);
    return true;
}

void runner(std::string instructions) {
	std::stringstream test(instructions);
	std::string segment;

	while(std::getline(test, segment, '\n')) {
   	std::string command = segment.substr(0, segment.find(" "));
	 	if (command == "write") {
			replace(segment, "write ", "");
			std::cout << segment << std::endl;
	 	}
	}
}