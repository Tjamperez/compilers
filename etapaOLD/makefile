IDIR =./include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=./obj
LDIR =./

_DEPS = tokens.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o lex.yy.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: scanner etapa1

scanner: scanner.l
	flex scanner.l

etapa1: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -ll

.PHONY: clean clean_comments

#This is the function to clean comments, to add more files to be not cleaned append them where lex.yy.c is and continue accordingly

clean_comments:
	for file in $(filter-out main.c lex.yy.c, $(wildcard *.c)); do \
		sed -i -E '/\/\/.*|\/\*.*|printf\s*\(/d' $$file; \
	done



clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~
