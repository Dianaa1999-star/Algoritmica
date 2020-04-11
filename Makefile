CC=g++
CFLAGS = -Wall
SRC1 = sala.cpp
SRC11 = gard.cpp
EXE = sala
EXE1 = gard
EXE2 = bomboane
SRC2 = bomboane.cpp
EXE3 = bani
SRC3 = bani.cpp

build: sala.cpp gard.cpp bomboane.cpp
	$(CC) -o $(EXE3) $(SRC3) $(CFLAGS)
	$(CC) -o $(EXE) $(SRC1) $(CFLAGS)
	$(CC) -o $(EXE1) $(SRC11) $(CFLAGS)
	$(CC) -o $(EXE2) $(SRC2) $(CFLAGS)
run-p1:
	./$(EXE3)
run-p4:
	./$(EXE)
run-p2:
	./$(EXE1)
run-p3:
	./$(EXE2)


.PHONY : clean
clean :
	rm -f $(EXE) *~
	rm -f $(EXE1) *~
