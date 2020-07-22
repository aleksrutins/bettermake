CC := clang++
CFLAGS := -O2
.PHONY: all
all: bin/command bin/detail bin/header
bin/command: command.cpp
	$(CC) command.cpp -o bin/command
bin/detail: detail.cpp
	$(CC) detail.cpp -o bin/detail
bin/header: header.cpp
	$(CC) header.cpp -o bin/header

check:
	./bettermake/bin/header header test
	./bettermake/bin/detail 'Test detail'
	./bettermake/bin/command 'echo hello'
	./bettermake/bin/command nonexistent-command
