#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#define checkQuiet(statement) if(argc > 2) { \
		if(strcmp(argv[2], "quiet")) { \
			 statement ; \
		} \
	} else { \
		statement ; \
	}

int main(int argc, char **argv) {
	if(argc < 2) {
		cout << "\e[1;31mUsage: " << argv[0] << " <command> [flags]\e[0m" << endl
			 << "\e[33m------\e[0m" << endl
			 << "\e[1;32mFlags:\e[0m" << endl
			 << "\e[33m------\e[0m" << endl
			 << "\e[33mquiet:\e[0m Do not print exit code" << endl;
		return 1;
	}
	cout << "\e[32m%\e[33m " << argv[1] << "\e[0m" << endl;
	int ret = system(argv[1]);
	if(ret) {
		checkQuiet(cout << "\e[1;31mExited with code " << ret << "\e[0m" << endl)
		return ret;
	}
	checkQuiet(cout << "\e[1;32mCompleted successfully\e[0m" << endl)
	return 0;
}
