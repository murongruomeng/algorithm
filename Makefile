objects = main.o list.o

main: $(objects)
	clang -o main $(objects)

clean:
	rm main main.o list.o