IDIR =../include
CC=g++

CFLAGS=-I$(IDIR) -g -ftest-coverage -fprofile-arcs

ODIR=obj
LDIR =../lib

#SLIBS indica bibliotecas estaticas na pasta lib, enquanto LIBS sao bibliotecas instaladas no sistema
_SLIBS= libgtest.a
SLIBS = $(patsubst %,$(LDIR)/%,$(_SLIBS))
LIBS = -pthread

_DEPS = romanos.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJC = romanos.o test_romanos.o
OBJC = $(patsubst %,$(ODIR)/%,$(_OBJC))

$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

#-Wno-write-strings eh a flag para suprimir warnings a respeito de inicializacao de string em c++

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS) -Wno-write-strings 

test_romanos: $(OBJC)
	$(CC) -o $@ $^ $(CFLAGS) $(SLIBS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 