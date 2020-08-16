bettermake/compile:
	@echo "Compiling BetterMake..."
	@cd bettermake && ./configure && $(MAKE)
bettermake/test: bettermake/compile
	@echo "Testing BetterMake..."
	@$(MAKE) -C bettermake test
