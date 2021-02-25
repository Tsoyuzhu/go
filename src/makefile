# the compiler: gcc for C program, define as g++ for C++
  CC = g++
 
  # compiler flags:
  #  -g     - this flag adds debugging information to the executable file
  #  -Wall  - this flag is used to turn on most compiler warnings
  #  -std   - this flag is used to set the version of c++ used by the compiler
  CFLAGS  = -g -Wall -std=c++11
 
  # The build target 
  TARGET = go

go: main.cpp Board.cpp Group.cpp Piece.cpp
	$(CC) $(CFLAGS) -o $(TARGET) main.cpp Board.cpp Group.cpp Piece.cpp

clean:
	rm go