bettermake/compile:
	@echo "Compiling BetterMake..."
	@$(MAKE) -C bettermake
bettermake/test: bettermake/compile
	@echo "Testing BetterMake..."
	./bettermake/header header test
	./bettermake/detail 'Test detail'
	./bettermake/command 'echo hello'
	./bettermake/command nonexistent-command