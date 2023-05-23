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
obj/CsvReader.o: src/CsvReader.cpp src/CsvReader.h src/Data.h
obj/Data.o: src/Data.cpp src/Data.h src/User.h src/Sensor.h src/Measurement.h
obj/Measurement.o : src/Measurement.cpp src/Measurement.h src/Concentration.h
obj/Position.o: src/Position.cpp src/Position.h
obj/Sensor.o: src/Sensor.cpp src/Sensor.h src/Position.h src/Measurement.h src/User.h
obj/User.o: src/User.cpp src/User.h

$(OBJ) :
	@echo $<
	g++ -c -o $@ $(CPPFLAGS) $<

clean :
	$(RM) -f $(EXE) $(OBJ) core