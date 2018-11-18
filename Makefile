CC      := gcc -std=c99                                                                
DEBUG   :=-g                                                                    
LFLAGS :=  -Wall -Werror --pedantic

all: tictactoe.c
	$(CC) $(DEBUG) $(LFLAGS)  tictactoe.c -o tictactoe



