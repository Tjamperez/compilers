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
_DEPS = $(IDIR)/parser.tab.h $(IDIR)/val_lex.h $(IDIR)/tree.h $(IDIR)/sym_stack.h $(IDIR)/sym_table.h
DEPS = $(patsubst %,$(LDIR)/%,$(_DEPS))

# Object files
_OBJ = main.o lex.yy.o parser.tab.o val_lex.o tree.o sym_table.o sym_stack.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

# Rule to compile source files to object files
$(ODIR)/%.o: %.c $(DEPS) | $(ODIR)
	$(CC) -c -o $@ $< $(CFLAGS)

# Default target to execute make
all: etapa5

etapa5: $(OBJ)
	$(CC) -g -o $@ $^ $(CFLAGS)

# Rule to generate parser using Bison
$(LDIR)/parser.tab.c $(IDIR)/parser.tab.h: $(LDIR)/parser.y
	bison -d -o $(LDIR)/parser.tab.c --header=$(IDIR)/parser.tab.h $(LDIR)/parser.y
	touch $@

# Rule to generate lexer using Flex
$(LDIR)/lex.yy.c: $(LDIR)/scanner.l
	flex -o $(LDIR)/lex.yy.c $(LDIR)/scanner.l
	touch $@

$(ODIR)/val_lex.o: $(LDIR)/val_lex.c $(IDIR)/val_lex.h | $(ODIR)
	$(CC) -c -o $@ $(LDIR)/val_lex.c $(CFLAGS)

$(ODIR)/tree.o: $(LDIR)/tree.c $(IDIR)/tree.h | $(ODIR)
	$(CC) -c -o $@ $(LDIR)/tree.c $(CFLAGS)

$(ODIR)/sym_table.o: $(LDIR)/sym_table.c $(IDIR)/sym_table.h | $(ODIR)
	$(CC) -c -o $@ $< $(CFLAGS)

$(ODIR)/sym_stack.o: $(LDIR)/sym_stack.c $(IDIR)/sym_stack.h | $(ODIR)
	$(CC) -c -o $@ $< $(CFLAGS)

# Create object directory if it doesn't exist
$(ODIR):
	mkdir -p $(ODIR)

# Create include directory if it doesn't exist
$(IDIR):
	mkdir -p $(IDIR)

move_headers: $(wildcard *.h) | $(IDIR)
	if [ -n "$^" ] && [ -d "$(IDIR)" ]; then \
		mv $^ $(IDIR)/; \
	fi

.PHONY: clean clean_comments

# Clean comments from source files
clean_comments:
	for file in $(filter-out main.c lex.yy.c, $(wildcard *.c)); do \
		sed -i -E '/\/\/.*|\/\*.*|printf\s*\(/d' $$file; \
	done

# Clean build artifacts
clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~ etapa5 lex.yy.c $(LDIR)/parser.tab.c $(IDIR)/parser.tab.h

