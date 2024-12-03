# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++11

# Target executable
TARGET = movie_database

# Source filesSRCS = main.cpp Movie.cpp Database.cpp
OBJS = main.o Movie.o Database.o
SRCS = SRCS = main.cpp Movie.cpp Movie.h MovieDat.cpp Database.h


# Object files (generated from .cpp files)
OBJS = main.o Movie.o Database.o

# Default rule to compile the executable
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile main.cpp into main.o
main.o: main.cpp Movie.h Database.h
	$(CXX) $(CXXFLAGS) -c main.cpp

# Rule to compile Movie.cpp into Movie.o
Movie.o: Movie.cpp Movie.h
	$(CXX) $(CXXFLAGS) -c Movie.cpp

# Rule to compile Database.cpp into Database.o
Database.o: Database.cpp Database.h Movie.h
	$(CXX) $(CXXFLAGS) -c Database.cpp

# Clean rule to remove compiled files
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets (non-file targets)
.PHONY: all clean
