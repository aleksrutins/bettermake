#include <cyaml/cyaml.h>
#include <stdio.h>
#include "command.h"
#include "cyaml-defs.h"
#include "targets.h"

int genBuild(int argc, char const *argv[]) {
	struct build_config *config;
	cyaml_err_t err;
	register int i;
	int res;

	err = cyaml_load_file("buildconf.yml", &cyconfig,
			&config_schema, (void **) &config, NULL);

	if(err != CYAML_OK) {
		printf("\e[1;31mError:\e[0;31m %s\e[0m\n", cyaml_strerror(err));
		return 1;
	}
	if(argc < 2) {
		return runDefault(config);
	} else {
		for(i = 1; i < argc; i++) {
			if(hasStep(config, argv[i])) {
				res = runStep(config, argv[i]);
				if (res != 0) {
					printf("\e[1;31mError:\e[0;31m Target %s failed with %i\e[0m\n", argv[i], res);
					return res;
				}
			} else {
				printf("\e[1;31mError:\e[0;31m No such target: %s\e[0m\n", argv[i]);
				return 1;
			}
		}
	}
};
