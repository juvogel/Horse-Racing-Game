horseRace: horse.o race.o main.o
	g++ horse.o race.o main.o -o horseRace
horse.o: horse.cpp horse.h
	g++ -c horse.cpp
race.o: race.cpp race.h
	g++ -c race.cpp
main.o: main.cpp horse.h race.h
	g++ -c main.cpp
clean:
	rm -f *.o
uninstall:
	rm horseRace