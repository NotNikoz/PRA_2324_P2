cambio.o: cambio.cpp
	g++ -o cambio.o cambio.cpp

testCambio: cambio.o
	./cambio.o




clean:
	rm -r *.o *.gch 
