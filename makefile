exe.play: main.o
	g++ main.o -o exe.play -Iinclude -lpthread -Llib -lSDL2 -lSDL2main  -freg-struct-return -ffast-math -fno-finite-math-only

main.o: main.cpp
	gcc -c main.cpp -Iinclude -lpthread -Llib -lSDL2 -lSDL2main  -freg-struct-return -ffast-math -fno-finite-math-only

clean:
	rm *.o exe.play