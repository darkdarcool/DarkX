#include <iostream>

std::string lexer(std::string content) {
	std::string tokens;
	bool isCommand = false;
	std::string command = ""; // command
	std::string writeText = "";
	for (char i : content) {
		if (i == '\2') { // command start
			isCommand = true;
		}
		else if (isCommand == true) { // is command
			if (i == 'w') { // command = write
				command = "write";
				isCommand = false;
			}
		}
		else if (command != "") {
			if (command == "write") {
				if (i == '\f') { // end command
					tokens.append("write " + writeText + "\n");
					command = ""; // cleanup
					writeText = "";
				}
				else {
					writeText.append(std::string(1, i)); // append char into write text as string
				}
			}
		}
	}
	return tokens;
}