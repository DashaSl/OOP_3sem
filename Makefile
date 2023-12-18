all: MyGame

MyGame: enemy.o main.o controller.o player.o cell.o field.o teleportevent.o badevent.o goodevent.o event.o fieldgenerator.o game.o stream.o filereader.o read.o gamestalker.o drawer.o eventmessage.o evemeswin.o evemesdead.o evemesnew.o evemesmove.o evemesfailmove.o filewriter.o messagesend.o terminalwriter.o streamwriterinterface.o movementstalker.o movementrandom.o interactionteleport.o interactionhp.o
	g++ enemy.o main.o player.o controller.o cell.o field.o teleportevent.o badevent.o goodevent.o event.o fieldgenerator.o game.o stream.o filereader.o read.o gamestalker.o drawer.o eventmessage.o evemeswin.o evemesdead.o evemesnew.o evemesmove.o evemesfailmove.o filewriter.o messagesend.o terminalwriter.o streamwriterinterface.o movementstalker.o movementrandom.o interactionteleport.o interactionhp.o -o MyGame
main.o: main.cpp controller.h player.h cell.h field.h enemy.h
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
eventmessage.o: eventmessage.cpp eventmessage.h 
	g++ -c eventmessage.cpp
evemeswin.o: evemeswin.h evemeswin.cpp eventmessage.h player.h
	g++ -c evemeswin.cpp
evemesdead.o: eventmessage.h evemesdead.h evemesdead.cpp controller.h
	g++ -c evemesdead.cpp
evemesnew.o: eventmessage.h evemesnew.cpp evemesnew.h controller.h
	g++ -c evemesnew.cpp
evemesmove.o: eventmessage.h evemesmove.cpp evemesmove.h controller.h 
	g++ -c evemesmove.cpp
evemesfailmove.o: eventmessage.h evemesfailmove.cpp evemesfailmove.h controller.h
	g++ -c evemesfailmove.cpp
messagesend.o: messagesend.cpp messagesend.h filewriter.h
	g++ -c messagesend.cpp
filewriter.o: filewriter.cpp filewriter.h streamwriterinterface.h
	g++ -c filewriter.cpp	
terminalwriter.o: terminalwriter.cpp terminalwriter.h streamwriterinterface.h
	g++ -c terminalwriter.cpp
streamwriterinterface.o: streamwriterinterface.h streamwriterinterface.cpp
	g++ -c streamwriterinterface.cpp
enemy.o: enemy.cpp enemy.h
	g++ -c enemy.cpp
movementstalker.o: movementstalker.h movementstalker.cpp
	g++ -c movementstalker.cpp
movementrandom.o: movementrandom.h movementrandom.cpp
	g++ -c movementrandom.cpp
interactionteleport.o: interactionteleport.h interactionteleport.cpp
	g++ -c interactionteleport.cpp
interactionhp.o: interactionhp.h interactionhp.cpp
	g++ -c interactionhp.cpp
	
clean:
	rm -rf *.o MyGame

	
	