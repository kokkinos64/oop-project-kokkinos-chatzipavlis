# Declaration of variables
CC = g++
CC_FLAGS = -w

# File names
EXEC = run
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.c=.o)

# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

# To obtain object files
%.o: %.cpp
	$(CC) -c $(CC_FLAGS) $< -o $@

# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)

# Run and show execution time
time: $(EXEC)
	time ./$(EXEC)

# Check for leaks
valgrind: $(EXEC)
	valgrind --leak-check=full --track-origins=yes -s ./$(EXEC)
