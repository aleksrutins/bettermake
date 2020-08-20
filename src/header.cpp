#include <cstdio>

int main(int argc, char **argv) {
	printf("\e[33m-> (\e[1m%s\e[0;33m)\t\e[4;34m%s\e[0m\t\e[33m<-\e[0m\n", argv[1], argv[2]);
	return 0;
}
