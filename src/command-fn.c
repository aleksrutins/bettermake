#include <stdio.h>
#include <stdlib.h>
int command(char *cmd) {
	printf("\e[1;32m% \e[2;33m%s\e[0m\n", cmd);
	return system(cmd);
}