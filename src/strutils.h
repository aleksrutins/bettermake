#include <string.h>
#include <stdlib.h>
#include "bool.h"

BOOL startsWith(char *str, char *start) {
	int strLen = strlen(str);
	int startLen = strlen(start);
	register int i;
	if(startLen > strLen) return FALSE;
	for(i = 0; i < startLen; i++) {
		if(*(str + i) != *(start + i)) return FALSE;
	}
	return TRUE;
}