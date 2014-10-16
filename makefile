horseRace: horse.o race.o player.o bookkeeper.o main.o
	g++ horse.o race.o player.o bookkeeper.o main.o -o horseRace
horse.o: horse.cpp horse.h
	g++ -c horse.cpp
race.o: race.cpp race.h
	g++ -c race.cpp
player.o: player.cpp player.h
	g++ -c player.cpp
bookkeeper.o: bookkeeper.cpp bookkeeper.h
	g++ -c bookkeeper.cpp
main.o: main.cpp horse.h race.h player.h
	g++ -c main.cpp
clean:
	rm -f *.o
uninstall:
	rm horseRace