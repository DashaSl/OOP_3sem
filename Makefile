all: MyGame

MyGame: main.o controller.o player.o cell.o field.o teleportevent.o badevent.o goodevent.o event.o fieldgenerator.o game.o stream.o filereader.o read.o gamestalker.o drawer.o
	g++ main.o player.o controller.o cell.o field.o teleportevent.o badevent.o goodevent.o event.o fieldgenerator.o game.o stream.o filereader.o read.o gamestalker.o drawer.o -o MyGame
main.o: main.cpp controller.h player.h cell.h field.h
	g++ -c main.cpp
controller.o: controller.cpp controller.h player.h field.h
	g++ -c controller.cpp
player.o: player.cpp player.h
	g++ -c player.cpp
cell.o: cell.h cell.cpp
	g++ -c cell.cpp
field.o: field.cpp field.h cell.h
	g++ -c field.cpp
event.o: event.cpp event.h
	g++ -c event.cpp	
teleportevent.o: teleportevent.cpp teleportevent.h event.h
	g++ -c teleportevent.cpp
badevent.o: badevent.h badevent.cpp event.h
	g++ -c badevent.cpp
goodevent.o: goodevent.h goodevent.cpp event.h
	g++ -c goodevent.cpp
fieldgenerator.o: fieldgenerator.cpp fieldgenerator.h controller.h
	g++ -c fieldgenerator.cpp
game.o: game.cpp game.h controller.h player.h gamestalker.h
	g++ -c game.cpp
stream.o: stream.cpp stream.h
	g++ -c stream.cpp
filereader.o: filereader.cpp filereader.h
	g++ -c filereader.cpp
read.o: read.h read.cpp
	g++ -c read.cpp
gamestalker.o: gamestalker.h gamestalker.cpp game.h fieldgenerator.h drawer.h
	g++ -c gamestalker.cpp
drawer.o: drawer.h
	g++ -c drawer.cpp
clean:
	rm -rf *.o MyGame
