#
# makefile for RetroBASIC
#
#
# various setup
LEX = flex
LFLAGS = -lfl
YAC = bison
YFLAGS =-dtv
CC = gcc -g
CFLAGS = -DYYDEBUG=1
CLIBS = -ly -ll

rm=/bin/rm -f
mv=/bin/mv -f

# our program name
TARGET = retrobasic

# the final program has three inputs, the lex/yacc and the interpreter source
$(TARGET): $(wildcard src/*.c) parse.tab.c lex.yy.c
	$(CC) -Isrc $^ -o $(TARGET) -lm

# if the lex or .tab.h file is changed, run lex again
lex.yy.c: src/scan.l parse.tab.h
	$(LEX) $(LEXFLAGS) $<

# If the yacc file is changed, run yacc again.
parse.tab.c parse.tab.h: src/parse.y
	$(YAC) $(YFLAGS) $<

clean:
	$(rm) $(TARGET) $(TARGET).o
	$(rm) *.tab.h *.tab.c *.lex.c *.yy.c parse.output
	$(rm) -r *.dSYM 

# Detect platform for install behavior
ifeq ($(OS),Windows_NT)
    PREFIX ?= $(PROGRAMFILES)\RetroBASIC
    BINDIR := $(PREFIX)\bin
    DOCDIR := $(PREFIX)\doc
    MANDIR := $(PREFIX)\man
else
    PREFIX ?= /usr/local
    BINDIR ?= $(PREFIX)/bin
    MANDIR ?= $(PREFIX)/share/man
    DOCDIR ?= $(PREFIX)/share/doc/retrobasic
endif

.PHONY: install uninstall

install: $(TARGET)
ifeq ($(OS),Windows_NT)
	@echo Installing RetroBASIC to $(PREFIX)...
	@if not exist "$(BINDIR)" mkdir "$(BINDIR)"
	@if not exist "$(DOCDIR)" mkdir "$(DOCDIR)"
	@if not exist "$(MANDIR)" mkdir "$(MANDIR)"
	copy /Y "$(TARGET)" "$(BINDIR)\"
	copy /Y "docs\retrobasic.1" "$(MANDIR)\" 2>nul || true
	@echo Installation complete!
else
	@echo "Installing RetroBASIC to $(PREFIX)..."
	mkdir -p $(BINDIR) $(MANDIR)/man1 $(DOCDIR)
	install -m 755 $(TARGET) $(BINDIR)/
	install -m 644 docs/retrobasic.1 $(MANDIR)/man1/ 2>/dev/null || true
	cp -r docs $(DOCDIR)/
	@echo "Installation complete!"
endif

uninstall:
ifeq ($(OS),Windows_NT)
	@echo Uninstalling RetroBASIC from $(PREFIX)...
	@if exist "$(BINDIR)\$(TARGET).exe" del /Q "$(BINDIR)\$(TARGET).exe"
	@if exist "$(MANDIR)\retrobasic.1" del /Q "$(MANDIR)\retrobasic.1"
	@if exist "$(DOCDIR)" rmdir /S /Q "$(DOCDIR)"
	@echo Uninstall complete!
else
	@echo "Uninstalling RetroBASIC from $(PREFIX)..."
	rm -f $(BINDIR)/$(TARGET)
	rm -f $(MANDIR)/man1/retrobasic.1
	rm -rf $(DOCDIR)
	@echo "Uninstall complete!"
endif

all: retrobasic
