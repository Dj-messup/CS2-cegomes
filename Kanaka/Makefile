CXX = g++
CXXFLAGS = -std=c++11 -Wall

SRC = main.cpp room.cpp player.cpp item.cpp enemy.cpp dungeon.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = game

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm -f $(OBJ) $(EXEC)
