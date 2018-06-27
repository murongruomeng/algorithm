objects = main.o list.o sort.o utils.o
src = main.c list.c sort.c utils.c

main: $(objects)
	clang -g -o main $(objects)

$(objects): $(src)
	clang -c -g $(src)

clean:
	rm main $(objects)