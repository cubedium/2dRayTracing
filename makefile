exe:
	g++ main.o -o exe -Iinclude -lpthread -Llib -lSDL2 -lSDL2main

main.o:
	gcc -c main.cpp -Iinclude -lpthread -Llib -lSDL2 -lSDL2main

clean:
	rm *.o exe