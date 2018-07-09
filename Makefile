objects = main.o list.o sort.o utils.o heap.o
src = main.c list.c sort.c utils.c heap.c

main: $(objects)
	clang -o main $(objects)

$(objects): $(src)
	clang -c $(src)

clean:
	rm main $(objects)