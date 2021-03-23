CC=clang
CFLAGS=-I.
DEPS = matrix_io.h matrix_logic.h linear_regression.h
OBJ = main.o matrix_io.o matrix_logic.o linear_regression.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

gauss_jordan: $(OBJ)
	$(CC) -lm -o $@ $^ $(CFLAGS)