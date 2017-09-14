runSorts: runSorts.o bubbleSort.o quickSort.o
	g++ -Wall -o runSorts runSorts.o bubbleSort.o quickSort.o
runSorts.o: runSorts.cpp
	g++ -Wall -c runSorts.cpp
bubbleSort: bubbleSort.cpp
	g++ -Wall -c bubbleSort.cpp
quickSort: quickSort.cpp
	g++ -Wall -c quickSort.cpp
clean:
	rm -rf *.o 
