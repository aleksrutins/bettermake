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
	try {
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
			buildcfg << "default: helloworld" << endl
					 << "env: \"\"" << endl
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
		} else {
			cout << "\e[1;32mUsage: \e[1;33m" << argv[0] << "\e[0m <\e[31mcommand\e[0m> [\e[33margs\e[0m...]" << endl
				 << "---------" << endl
				 << "\e[1;32mAvailable commands:\e[0m" << endl
				 << "---------" << endl
				 << "\e[1;33mbuild\e[0m [\e[33mtask\e[0m...]" << endl
				 << "With no arguments, builds the default task." << endl
				 << "With one or more arguments, builds the tasks specified by the arguments, in order." << endl
				 << "---------" << endl
				 << "\e[1;33minstall\e[0m" << endl
				 << "Installs the latest Makefile helpers into \e[31m/opt/bettermake\e[0m." << endl
				 << "---------" << endl
				 << "\e[1;33minit\e[0m" << endl
				 << "Initializes \e[31mbuildconf.yml\e[0m in the current directory." << endl
				 << "---------" << endl
				 << "\e[1;33mlist\e[0m" << endl
				 << "Lists the targets and their descriptions in \e[31mbuildconf.yml\e[0m." << endl
				 << "---------" << endl
				 << "\e[1;33mFor more comprehensive documentation, see \e[0;31mhttps://munchkinhalfling.github.io/bettermake\e[1;33m.\e[0m" << endl;
		}
	} catch(logic_error e) {
		cout << "\e[1;32mUsage: \e[1;33m" << argv[0] << "\e[0m <\e[31mcommand\e[0m> [\e[33margs\e[0m...]" << endl
			 << "---------" << endl
			 << "\e[1;32mAvailable commands:\e[0m" << endl
			 << "---------" << endl
			 << "\e[1;33mbuild\e[0m [\e[33mtask\e[0m...]" << endl
			 << "With no arguments, builds the default task." << endl
			 << "With one or more arguments, builds the tasks specified by the arguments, in order." << endl
			 << "---------" << endl
			 << "\e[1;33minstall\e[0m" << endl
			 << "Installs the latest Makefile helpers into \e[31m/opt/bettermake\e[0m." << endl
			 << "---------" << endl
			 << "\e[1;33minit\e[0m" << endl
			 << "Initializes \e[31mbuildconf.yml\e[0m in the current directory." << endl
			 << "---------" << endl
			 << "\e[1;33mlist\e[0m" << endl
			 << "Lists the targets and their descriptions in \e[31mbuildconf.yml\e[0m." << endl
			 << "---------" << endl
			 << "\e[1;33mFor more comprehensive documentation, see \e[0;31mhttps://munchkinhalfling.github.io/bettermake\e[1;33m.\e[0m" << endl;
	}
	return 0;
}
