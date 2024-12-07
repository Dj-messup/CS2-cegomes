# Compiler name
CXX = g++

# C++ compiler flags
# -c : compile and assemble into object files
# -g : adds debugging information
# -Wall : turns on most compiler warnings
# -std=c++17 : uses the C++17 standard
CXXFLAGS = -c -g -Wall -std=c++17

# The build target executable file; .exe is not required
PROGRAM = movie_database.out

# List all .cpp files separated by space
CPPFILES = main.cpp Movie.cpp Database.cpp

# Default rule to build the executable
all:
	# Compile all the .cpp files into .o object files
	$(CXX) $(CXXFLAGS) $(CPPFILES)
	# Link all object files into the final executable
	$(CXX) -o $(PROGRAM) *.o

# Clean rule to delete object and binary files
clean:
	rm -f $(PROGRAM) *.o

# Run rule to execute the program
run:
	./$(PROGRAM)

