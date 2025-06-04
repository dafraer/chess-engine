all: run

build:
	gcc -I. -o engine-out main.c ./engine/engine.c ./helpers/helpers.c ./bitboard/bitboard.c 
run:
	gcc -I. -o engine-out main.c ./engine/engine.c ./helpers/helpers.c ./bitboard/bitboard.c 
	./engine-out
clean:
	rm engine-out