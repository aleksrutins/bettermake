bettermake/compile:
	@echo "Compiling BetterMake..."
	@$(MAKE) -C bettermake
bettermake/test: bettermake/compile
	@echo "Testing BetterMake..."
	@$(MAKE) -C bettermake check
