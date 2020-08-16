.PHONY: all
all: bin/command bin/detail bin/header
bin/command: command.cpp
	$(CXX) command.cpp  -o bin/command
bin/detail: detail.cpp
	$(CXX) detail.cpp   -o bin/detail
bin/header: header.cpp
	$(CXX) header.cpp   -o bin/header

test: all
	./bin/header header test
	./bin/detail 'Test detail'
	./bin/command 'echo hello'
