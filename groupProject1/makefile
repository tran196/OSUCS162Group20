###
### 
###  Tuan Tran
###  Group Project 

# output: main.o CritterClassForTestingBoard.o board.o
# 	g++ -std=c++11 main.o CritterClassForTestingBoard.o board.o -o output

output: main.o CritterClassForTestingBoard.o 
	g++ -std=c++11 main.o CritterClassForTestingBoard.o -o output

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

CritterClassForTestingBoard.o: CritterClassForTestingBoard.cpp
	g++ -std=c++11 -c CritterClassForTestingBoard.cpp

# board.o: board.cpp
# 	g++ -std=c++11 -c board.cpp

clean:
	rm *.o output
