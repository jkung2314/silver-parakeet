CC      = c++
FLAGS   = -Wall -Wextra
LIB     = -lpthread
SOURCES = benchmark.cc
OBJECTS = benchmark.o
EXEBIN  = benchmark

all: $(EXEBIN)

$(EXEBIN): $(OBJECTS)
	$(CC) -o $(EXEBIN) $(OBJECTS) $(LIB)

$(OBJECTS): $(SOURCES)
	$(CC) -c $(FLAGS) $(SOURCES)

run: all
	./$(EXEBIN)

clean:
	rm -f $(EXEBIN) $(OBJECTS)