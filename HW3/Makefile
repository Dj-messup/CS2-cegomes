CXX = g++
CXXFLAGS = -c -g -Wall -std=c++17
PROGRAM = main.out
CPPFILES = main.cpp stack.cpp

all: $(PROGRAM)

$(PROGRAM): $(CPPFILES)
	$(CXX) $(CXXFLAGS) $(CPPFILES)
	$(CXX) -o $(PROGRAM) *.o

clean:
	rm -f $(PROGRAM) *.o


# Rule to run the program
run:
	./$(PROGRAM)

# Test the program (this is optional based on your needs)
test:
	./$(PROGRAM) test
