INT = src/$(wildcard *.h)
SRC = $(INT:.h=.cpp) src/main.cpp
OBJ = $(INT:.h=.o) main.o
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
#Catalogue.o : Catalogue.cpp Catalogue.h Trajet.h TrajetSimple.h TrajetCompose.h ListeTrajet.h Node.h
#main.o : main.cpp Catalogue.h TrajetSimple.h TrajetCompose.h

$(OBJ) :
	echo $(OBJ)
	g++ -c $(CPPFLAGS) $<

clean :
	$(RM) -f $(EXE) $(OBJ) core