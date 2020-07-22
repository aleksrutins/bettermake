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
	./bin/header header test
	./bin/detail 'Test detail'
	./bin/command 'echo hello'
	./bin/command nonexistent-command
