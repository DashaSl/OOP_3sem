all: MyGame

MyGame: main.o controller.o player.o
	g++ main.o player.o controller.o -o MyGame
main.o: main.cpp
	g++ -c main.cpp
controller.o: controller.cpp controller.h
	g++ -c controller.cpp
player.o: player.cpp player.h
	g++ -c player.cpp
clean:
	rm -rf *.o MyGame
