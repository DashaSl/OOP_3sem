all: MyGame

MyGame: main.o controller.o player.o cell.o field.o
	g++ main.o player.o controller.o cell.o field.o -o MyGame
main.o: main.cpp controller.h player.h cell.h field.h
	g++ -c main.cpp
controller.o: controller.cpp controller.h player.h field.h
	g++ -c controller.cpp
player.o: player.cpp player.h
	g++ -c player.cpp
cell.o: cell.h cell.cpp
	g++ -c cell.cpp
field.o: field.cpp field.h
	g++ -c field.cpp
clean:
	rm -rf *.o MyGame
