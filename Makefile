all: MyGame

MyGame: main.o Lab1_player_controller.o
	g++ main.o Lab1_player_controller.o -o MyGame
main.o: main.cpp Lab1_player_controller.h
	g++ -c main.cpp
Lab1.o: Lab1_player_controller.h Lab1_player_controller.cpp
	g++ -c Lab1_player_controller.cpp
clean:
	rm -rf *.o MyGame
