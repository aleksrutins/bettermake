#ifndef CYAML_TYPES_H
#define CYAML_TYPES_H 1
struct step {
	char *name;
	char *description;
	char **commands;
	char **dependencies;
	unsigned commands_count;
	unsigned dependencies_count;
	int hasRun;
	char *runIf;
};

struct build_config {
	char *defaultStep;
	char *env;
	struct step **steps;
	unsigned steps_count;
};
#endif