#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int command_env(char *cmd, char *env) {
	char *full_cmd = malloc((strlen(cmd) + strlen(env) + 2) * sizeof(char));
	printf("\e[1;32m%\e[0m \e[4;33m%s\e[0m\n", cmd);
	sprintf(full_cmd, "%s %s", env, cmd);
	return system(full_cmd);
}

int command(char *cmd) {
	return command_env(cmd, " ");
}