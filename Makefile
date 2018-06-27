objects = main.o list.o

main: $(objects)
	clang -o main $(objects)

clean:
	rm main $(objects)