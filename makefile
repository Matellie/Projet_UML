INT = $(wildcard src/*.h)
SRC = $(INT:.h=.cpp) src/main.cpp
OBJ = $(INT:src/%.h=obj/%.o) obj/main.o
LIBS = -lm
CPPFLAGS = -ansi -pedantic -Wall -std=c++11 -g #-DMAP
LDFLAGS = 
RM = rm
ECHO = echo
EXE = airwatcher

$(EXE) : $(OBJ)
	g++ $(LDFLAGS) -o $(EXE) $(OBJ)

# Add dependencies for obj files
# Follow the examples
obj/main.o : src/main.cpp
obj/Concentration.o : src/Concentration.cpp src/Concentration.h
obj/Measurement.o : src/Measurement.cpp src/Measurement.h src/Concentration.h
obj/CsvReader.o: src/CsvReader.cpp src/CsvReader.h
obj/Data.o: src/Data.cpp src/Data.h

$(OBJ) :
	echo $(OBJ)
	g++ -c -o $@ $(CPPFLAGS) $<

clean :
	$(RM) -f $(EXE) $(OBJ) core