CC = gcc -std=c11 -g -Wall -Wextra

SRC = $(wildcard *.c)
OBJ = $(patsubst %.c,%.o,$(SRC))
HDR = $(wildcard *.h)

debug: $(OBJ) $(HDR)
	$(CC) $(OBJ) -o $@

%.o: %.c $(HDR)
	$(CC) -c $< -o $@

clean:
	rm -rf $(OBJ) debug
