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
			for(j = 0; j < config->steps[i]->dependencies_count; j++) {
				res = runStep(config, config->steps[i]->dependencies[j]);
				if(res != 0) return res;
			}
			printf("\e[33m-> (\e[1m%s\e[0;33m)\t\e[4;34m%s\t\e[0;33m<-\e[0m\n", config->steps[i]->name, config->steps[i]->description);
			for(j = 0; j < config->steps[i]->commands_count; j++) {
				cmd = config->steps[i]->commands[j];
				if(startsWith(cmd, "/detail ")) {
					printf("\e[0;33m-> %s <-\e[0m\n", (cmd + 8));
				} else {
					res = command_env(cmd, config->env);
					if(res != 0) {
						printf("\e[1;31mFailed at command %i\e[0m\n", j + 1);
						return res;
					};
				}
			}
			printf("\e[1;32mCompleted successfully\e[0m\n");
		}
	}
	return 0;
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