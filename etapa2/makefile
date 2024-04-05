# Directory containing header files
IDIR = ./include

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -I$(IDIR)

# Directory containing object files
ODIR = ./obj

# Directory containing lexer and parser files
LDIR = ./

# Header file dependencies
_DEPS = parser.tab.h
DEPS = $(patsubst %,$(LDIR)/%,$(_DEPS))

# Object files
_OBJ = main.o lex.yy.o parser.tab.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# Rule to compile source files to object files
$(ODIR)/%.o: %.c $(DEPS) | $(ODIR)
	$(CC) -c -o $@ $< $(CFLAGS)

# Default target to execute make
all: etapa2

etapa2: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

# Rule to generate parser using Bison
$(LDIR)/parser.tab.c $(LDIR)/parser.tab.h: $(IDIR)/parser.y
	bison -d -o $(LDIR)/parser.tab.c --header=$(LDIR)/parser.tab.h $(IDIR)/parser.y

# Rule to generate lexer using Flex
$(LDIR)/lex.yy.c: $(LDIR)/scanner.l
	flex -o $(LDIR)/lex.yy.c $(LDIR)/scanner.l

# Create object directory if it doesn't exist
$(ODIR):
	mkdir -p $(ODIR)

.PHONY: clean clean_comments

# Clean comments from source files
clean_comments:
	for file in $(filter-out main.c lex.yy.c, $(wildcard *.c)); do \
		sed -i -E '/\/\/.*|\/\*.*|printf\s*\(/d' $$file; \
	done

# Clean build artifacts
clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~ etapa2 lex.yy.c parser.tab.c parser.tab.h