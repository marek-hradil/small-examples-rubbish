CC=clang
CFLAGS=-I.
DEPS = coeficients.h
OBJ = main.o coeficients.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

regula_falsi: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)