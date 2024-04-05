IDIR =./include
CC = gcc
CFLAGS = -I$(IDIR)

ODIR = ./obj
LDIR = ./

_DEPS = tokens.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o lex.yy.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.c $(DEPS) | $(ODIR)
	$(CC) -c -o $@ $< $(CFLAGS)

all: etapa1

etapa1: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) -ll

lex.yy.c: scanner.l
	flex -o $@ $<

main.o: lex.yy.c
	$(CC) -c -o $(ODIR)/$@ $< $(CFLAGS)

$(ODIR):
	mkdir -p $(ODIR)

.PHONY: clean clean_comments

clean_comments:
	for file in $(filter-out main.c lex.yy.c, $(wildcard *.c)); do \
		sed -i -E '/\/\/.*|\/\*.*|printf\s*\(/d' $$file; \
	done

clean:
	rm -f $(ODIR)/*.o *~ core $(IDIR)/*~ etapa1 lex.yy.c
