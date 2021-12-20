CPP=g++ --std=c++11
CFLAGS= -Wall

#JEU_SRC=Jeu/*.cpp
#JEU_HEADERS=Jeu/*.hpp
#JEU_OBJ=$(JEU_SRC:.cpp=.o)

#MAP_SRC=Jeu/Map/*.cpp
#MAP_HEADERS=Jeu/Map/*.hpp
#MAP_OBJ=$(MAP_SRC:.cpp=.o)

#OBJETS_SRC=Objets/*.cpp
#OBJETS_HEADERS=Objets/*.hpp
#OBJETS_OBJ=$(OBJETS_SRC:.cpp=.o)

PERSONNAGES_SRC=$(wildcard ./Personnages/*.cpp)
PERSONNAGES_HEADERS=$(wildcard ./Personnages/*.hpp)
PERSONNAGES_OBJ=$(PERSONNAGES_SRC:.cpp=.o)

all:$(PERSONNAGES_OBJ)

$(PERSONNAGES_OBJ):$(PERSONNAGES_SRC)
	$(CPP) $(CFLAGS) -c $<
