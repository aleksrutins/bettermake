#include <iostream>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include "gen-build.h"
#include <fstream>
using namespace std;
int command(string cmd) {
	cout << "\e[1;32m% \e[2;33m" << cmd << "\e[0m" << endl;
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
	} else if(cmd == "build") {
		return genBuild((argc - 1), (argv + 1));
	} else if(cmd == "init") {
		cout << "\e[1;33mInitializing buildconf.yml...\e[0m" << endl;
		ofstream buildcfg("buildconf.yml");
		buildcfg << "default: helloworld"
				 << "tasks:" << endl
				 << "  - name: helloworld" << endl
				 << "    depends: []" << endl
				 << "    description: Print hello world" << endl
				 << "    commands:" << endl
				 << "      - echo hello" << endl;
		buildcfg.close();
		// cout << "\e[1;33mDownloading newest bettermake...\e[0m" << endl;
		// command("wget -O bettermake.gz https://raw.githubusercontent.com/munchkinhalfling/bettermake/master/dist/bettermake.gz");
		// cout << "\e[1;33mUnzipping...\e[0m" << endl;
		// command("gunzip bettermake.gz");
		// cout << "\e[1;32mDone!\e[0m" << endl;
	} else if(cmd == "list") {
		return listTargets();
	}
	return 0;
}