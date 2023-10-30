cambio.o: cambio.cpp
	g++ -o cambio.o cambio.cpp

testCambio: cambio.o
	./cambio.o

mochila.o: mochila.cpp
	g++ -o mochila.o mochila.cpp

testMochila: mochila.o
	./mochila.o




clean:
	rm -r *.o *.gch 
