.PHONY: all
all: bin/mk-command bin/mk-detail bin/mk-header
bin/mk-command: command.cpp
	$(CXX) command.cpp  -o bin/mk-command
bin/mk-detail: detail.cpp
	$(CXX) detail.cpp   -o bin/mk-detail
bin/mk-header: header.cpp
	$(CXX) header.cpp   -o bin/mk-header

test: all
	./bin/mk-header header test
	./bin/mk-detail 'Test detail'
	./bin/mk-command 'echo hello'