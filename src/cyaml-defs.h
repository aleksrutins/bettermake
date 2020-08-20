#include <cyaml/cyaml.h>
#include "cyaml-types.h"
#ifndef DYAML_DEFS_H
#define CYAML_DEFS_H 1
static const cyaml_schema_value_t string_ptr_schema = {
	CYAML_VALUE_STRING(CYAML_FLAG_POINTER, char, 0, CYAML_UNLIMITED)
};

static const cyaml_schema_field_t step_fields_schema[] = {
	CYAML_FIELD_STRING_PTR(
			"name", CYAML_FLAG_POINTER,
			struct step, name, 0, CYAML_UNLIMITED),
	CYAML_FIELD_STRING_PTR(
			"description", CYAML_FLAG_POINTER,
			struct step, description, 0, CYAML_UNLIMITED),
	CYAML_FIELD_SEQUENCE(
			"commands", CYAML_FLAG_POINTER,
			struct step, commands,
			&string_ptr_schema, 0, CYAML_UNLIMITED),
	CYAML_FIELD_SEQUENCE(
			"depends", CYAML_FLAG_POINTER,
			struct step, dependencies,
			&string_ptr_schema, 0, CYAML_UNLIMITED),
	CYAML_FIELD_END
};
static const cyaml_schema_value_t step_schema = {
	CYAML_VALUE_MAPPING(CYAML_FLAG_POINTER,
			struct step, step_fields_schema),
};

static const cyaml_schema_field_t config_fields_schema[] = {
	CYAML_FIELD_SEQUENCE(
				"tasks", CYAML_FLAG_POINTER,
				struct build_config, steps,
				&step_schema, 0, CYAML_UNLIMITED),
	CYAML_FIELD_STRING_PTR(
		"default", CYAML_FLAG_POINTER,
		struct build_config, defaultStep, 0, CYAML_UNLIMITED
		),
	CYAML_FIELD_END
};
static const cyaml_schema_value_t config_schema = {
	CYAML_VALUE_MAPPING(CYAML_FLAG_POINTER,
			struct build_config, config_fields_schema),
};
static const cyaml_config_t cyconfig = {
	.log_level = CYAML_LOG_WARNING, /* Logging errors and warnings only. */
	.log_fn = cyaml_log,            /* Use the default logging function. */
	.mem_fn = cyaml_mem,            /* Use the default memory allocator. */
};
#endif