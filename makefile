exe.play: main.o
	g++ main.o -o exe.play -Iinclude -lpthread -Llib -lSDL2 -lSDL2main  -lSDL_gfx

main.o: main.cpp
	gcc -c main.cpp -Iinclude -lpthread -Llib -lSDL2 -lSDL2main  -lSDL_gfx
clean:
	rm *.o exe.play