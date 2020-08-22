#include "targets.h"
#include "cyaml-defs.h"
#include "command.h"
#include <string.h>
#include "strutils.h"

int runStep(struct build_config *config, char *name) {
	register int i;
	register int j;
	int res;
	char *cmd;
	for(i = 0; i < config->steps_count; i++) {
		if(!strcmp(config->steps[i]->name, name)) {
			if(config->steps[i]->hasRun) {
				printf("\e[1;32mTask \e[0;31m%s\e[1;32m has already been run.\e[0m\n", name);
				return 0;
			}
			if(config->steps[i]->dependencies_count > 0) {
				printf("\e[1;32mLoading dependencies for \e[0;31m%s\e[1;32m: \e[0;31m", name);
				for(j = 0; j < config->steps[i]->dependencies_count; j++) {
					printf("%s ", config->steps[i]->dependencies[j]);
				}
				printf("\e[0m\n");
			}
			for(j = 0; j < config->steps[i]->dependencies_count; j++) {
				res = runStep(config, config->steps[i]->dependencies[j]);
				if(res != 0) return res;
			}
			if(config->steps[i]->dependencies_count > 0) printf("\e[1;32mCompleted dependencies for task \e[0;31m%s\e[0m\n", name);
			printf("\e[1;32mRunning task \e[0;31m%s\e[1;32m...\e[0m\n", name);
			puts("\e[1;31m------------\e[0m");
			printf("[\e[4;34m%s\e[0m] \e[0;33m%s\e[0m\n", config->steps[i]->name, config->steps[i]->description);
			for(j = 0; j < config->steps[i]->commands_count; j++) {
				cmd = config->steps[i]->commands[j];
				if(startsWith(cmd, "/detail ")) {
					printf("\e[1;34m%s [detail]: \e[0;31m%s\e[0m\n", name, (cmd + 8));
				} else {
					res = command_env(cmd, config->env);
					if(res != 0) {
						printf("\e[1;31mFailed at command %i\e[0m\n", j + 1);
						return res;
					};
				}
			}
			puts("\e[1;31m------------\e[0m");
			printf("\e[1;32mTask \e[0;31m%s\e[1;32m completed successfully\e[0m\n", name);
			config->steps[i]->hasRun = 1;
			return 0;
		}
	}
	printf("\e[1;31mTask \e[0;31m%s\e[1;31m does not exist.\e[0m\n", name);
	return 1;
}
int runDefault(struct build_config *config) {
	return runStep(config, config->defaultStep);
}
int hasStep(struct build_config *config, char *step) {
	register int i;
	for(i = 0; i < config->steps_count; i++) {
		if(!strcmp(config->steps[i]->name, step)) {
			return 1;
		}
	}
	return 0;
}