#
# makefile for RetroBASIC
#
#
# various setup
LEX = flex
LFLAGS = -lfl
YAC = bison
YFLAGS =-dtv
CC = gcc
DEBUG ?= 0
CFLAGS ?=
ifeq ($(DEBUG),1)
  CFLAGS += -g -DYYDEBUG=1
endif
CLIBS = -ly -ll

rm=/bin/rm -f
mv=/bin/mv -f

# our program name
TARGET = retrobasic
SRC_DIR = src

# the final program has three inputs: generated lex/yacc sources and the interpreter source
$(TARGET): $(wildcard $(SRC_DIR)/*.c) $(SRC_DIR)/parse.tab.c $(SRC_DIR)/lex.yy.c
	$(CC) $(CFLAGS) -I$(SRC_DIR) $^ -o $(TARGET) -lm

# if the lex or .tab.h file is changed, run lex again
$(SRC_DIR)/lex.yy.c: $(SRC_DIR)/scan.l $(SRC_DIR)/parse.tab.h
	$(LEX) -o $@ $<

# If the yacc file is changed, run yacc again.
$(SRC_DIR)/parse.tab.c $(SRC_DIR)/parse.tab.h: $(SRC_DIR)/parse.y
	$(YAC) $(YFLAGS) -o $(SRC_DIR)/parse.tab.c $<
	cp $(SRC_DIR)/parse.tab.h $(SRC_DIR)/parse.h
	cp $(SRC_DIR)/parse.tab.h parse.h

clean:
	$(rm) $(TARGET) $(TARGET).o
	$(rm) src/parse.tab.c src/parse.tab.h src/lex.yy.c
	$(rm) parse.tab.c parse.tab.h lex.yy.c parse.h
	$(rm) *.lex.c *.yy.c parse.output
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

.PHONY: install uninstall all debug

debug:
	$(MAKE) DEBUG=1 all

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
