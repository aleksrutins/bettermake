#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
using namespace std;
int command(string cmd) {
	cout << "\e[1;32m% \e[3;33m" << cmd << "\e[0m" << endl;
	return system(cmd.c_str());
}
int main(int argc, char const *argv[])
{
	string cmd = *(argv+1);
	if(cmd == "install") {
		cout << "\e[1;33mInstalling Bettermake...\e[0m" << endl;
		cout << "\e[3;32mDownloading...\e[0m" << endl;
		command("mkdir -p /opt/bettermake");
		command("wget -O /opt/bettermake/tools.tar.gz https://raw.githubusercontent.com/munchkinhalfling/bettermake/master/dist/tools.tar.gz");
		cout << "\e[3;32mUnzipping...\e[0m" << endl;
		command("tar -C /opt/bettermake -xzf /opt/bettermake/tools.tar.gz");
		cout << "\e[1;32mDone!\e[0;32m Run this command again to update.\e[0m" << endl;
	}
	return 0;
}