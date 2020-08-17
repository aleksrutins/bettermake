bin_PROGRAMS= mk-command mk-header mk-detail bettermake
mk_command_SOURCES= command.cpp
mk_header_SOURCES= header.cpp
mk_detail_SOURCES= detail.cpp
bettermake_SOURCES= bettermake.cpp
OPTDIR = /opt/bettermake

check: all
	./mk-header header test
	./mk-detail 'Test detail'
	./mk-command 'echo hello'
install-binPROGRAMS: $(bin_PROGRAMS)
	$(INSTALL) -m 755 -Dt $(DESTDIR)$(bindir) bettermake
	$(MKDIR_P) $(OPTDIR)
	$(INSTALL) -m 755 -Dt $(OPTDIR) mk-command mk-header mk-detail path.mk
gzip-tools: mk-header mk-detail mk-command
	tar -cf tools.tar mk-header mk-command mk-detail path.mk 
	gzip tools.tar
	mv tools.tar.gz dist/
gzip-bettermake: bettermake
	gzip bettermake
	mv bettermake.gz dist/
gzip-all: $(bin_PROGRAMS)
	tar -cf all.tar mk-header mk-command mk-detail bettermake
	gzip all.tar
	mv all.tar.gz dist/
gzip: gzip-all gzip-tools gzip-bettermake