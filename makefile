INT = $(wildcard src/*.h)
SRC = $(INT:.h=.cpp) src/main.cpp
OBJ = $(INT:src/%.h=obj/%.o) obj/main.o
CC = g++
LIBS = -lm
CPPFLAGS = -ansi -pedantic -Wall -std=c++11 -g #-DMAP
COMPILEDEFINE = #	-DPERFORMANCE_EVALUATION
LDFLAGS = 
DEPFLAGS = -MT $@ -MMD -MP -MF deps/$*.d
RM = rm
ECHO = echo
EXE = airwatcher

default: $(EXE)

# Add dependencies for obj files
# Follow the examples
# obj/main.o : src/main.cpp
# obj/Concentration.o : src/Concentration.cpp src/Concentration.h
# obj/CsvReader.o: src/CsvReader.cpp src/CsvReader.h src/Data.h
# obj/Data.o: src/Data.cpp src/Data.h src/User.h src/Sensor.h src/Measurement.h
# obj/Measurement.o : src/Measurement.cpp src/Measurement.h src/Concentration.h
# obj/Position.o: src/Position.cpp src/Position.h
# obj/Sensor.o: src/Sensor.cpp src/Sensor.h src/Position.h src/Measurement.h src/User.h
# obj/User.o: src/User.cpp src/User.h
# obj/Analyse.o: src/Analyse.cpp src/Analyse.h src/Data.h
# obj/InterfaceConsole.o: src/InterfaceConsole.cpp src/InterfaceConsole.h

obj/%.o : src/%.cpp
obj/%.o : src/%.cpp deps/%.d | deps
	$(CC) -c -o $@ $(DEPFLAGS) $(CPPFLAGS) $<


DEPFILES := $(SRC:src/%.cpp=deps/%.d)
$(DEPFILES):
include $(wildcard $(DEPFILES))

# $(OBJ) :
# 	@echo $<
# 	g++ -c -o $@ $(CPPFLAGS) $<

$(EXE) : $(OBJ)
	$(CC) $(LDFLAGS) -o $(EXE) $(OBJ)

clean :
	$(RM) -f $(EXE) $(OBJ) core

test :
	@echo $(DEPFILES)