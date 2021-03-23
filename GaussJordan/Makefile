CC=clang
CFLAGS=-I.
DEPS = matrix_io.h matrix_logic.h
OBJ = main.o matrix_io.o matrix_logic.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

gauss_jordan: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)