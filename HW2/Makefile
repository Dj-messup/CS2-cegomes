# Compiler name
CXX = g++

# C++ compiler flags
# -c : compile and assemble into object files
# -g : adds debugging information
# -Wall : turns on most compiler warnings
# -std=c++17 : uses the C++17 standard
CXXFLAGS = -c -g -Wall -std=c++17

OBJS = main.o Media.o Movie.o TvShows.o Music.o Database.o

TARGET = mediadb

$(TARGET): $(OBJS)
	$(CXX) $(OBJS) -o $(TARGET)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Media.o: Media.cpp Media.h
	$(CXX) $(CXXFLAGS) -c Media.cpp

Movie.o: Movie.cpp Movie.h
	$(CXX) $(CXXFLAGS) -c Movie.cpp

TvShows.o: TvShows.cpp TvShows.h
	$(CXX) $(CXXFLAGS) -c TvShows.cpp

Music.o: Music.cpp Music.h
	$(CXX) $(CXXFLAGS) -c Music.cpp

Database.o: Database.cpp Database.h
	$(CXX) $(CXXFLAGS) -c Database.cpp

# Clean rule to delete object and binary files
clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean
# Run rule to execute the program
run:
	./$(PROGRAM)

