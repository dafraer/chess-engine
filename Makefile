all: build

build:
	gcc -o engine main.c
clean:
	rm engine