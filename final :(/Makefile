CXX = g++
CXXFLAGS = -g -Wall -std=c++17

SOURCES = main.cpp item.cpp enemy.cpp game.cpp room.cpp
OBJECTS = $(SOURCES:.cpp=.o)
TARGET = game.out

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $(OBJECTS)

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)