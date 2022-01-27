CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
NAME = hls

.PHONY: all clean oclean flcean re

all: ls_h.h $(OBJ)
	$(CC) $(OBJ) -o $(NAME)