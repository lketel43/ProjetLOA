CPP = g++ --std=c++11
CFLAGS = -Wall


### VARIABLES Répertoire ./Personnages/ ###
OBJ_DIR_PERSONNAGES = ./Personnages/obj/

PERSONNAGES_SRC = ./Personnages/
PERSONNAGES_SRCS=$(wildcard $(PERSONNAGES_SRC)*.cpp)
OBJ_PERSONNAGES = $(notdir $(PERSONNAGES_SRCS:.cpp=.o))
OBJ_PERSONNAGES := $(addprefix $(OBJ_DIR_PERSONNAGES), $(OBJ_PERSONNAGES))
###

### VARIABLES Répertoire ./Jeu/ ###
OBJ_DIR_JEU = ./Jeu/obj/

JEU_SRC = ./Jeu/
JEU_SRCS = $(wildcard $(JEU_SRC)*.cpp)
OBJ_JEU = $(notdir $(JEU_SRCS:.cpp=.o))
OBJ_JEU := $(addprefix $(OBJ_DIR_JEU), $(OBJ_JEU))
###

### VARIABLES Répertoire ./Jeu/Map/ ###
OBJ_DIR_MAP = ./Jeu/Map/obj/

MAP_SRC = ./Jeu/Map/
MAP_SRCS = $(wildcard $(MAP_SRC)*.cpp)
OBJ_MAP = $(notdir $(MAP_SRCS:.cpp=.o))
OBJ_MAP := $(addprefix $(OBJ_DIR_MAP), $(OBJ_MAP))
###

### VARIABLES Répertoire ./Objets/ ###
OBJ_DIR_OBJETS = ./Objets/obj/

OBJETS_SRC = ./Objets/
OBJETS_SRCS = $(wildcard $(OBJETS_SRC)*.cpp)
OBJ_OBJETS = $(notdir $(OBJETS_SRCS:.cpp=.o))
OBJ_OBJETS := $(addprefix $(OBJ_DIR_OBJETS), $(OBJ_OBJETS))
###

all:main

main : main.o $(OBJ_OBJETS) $(OBJ_PERSONNAGES) $(OBJ_JEU) $(OBJ_MAP)
	$(CPP) $(CFLAGS) -o $@ $^

main.o : main.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_PERSONNAGES)%.o : $(PERSONNAGES_SRC)%.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_JEU)%.o : $(JEU_SRC)%.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_MAP)%.o : $(MAP_SRC)%.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_OBJETS)%.o : $(OBJETS_SRC)%.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

clean:
	rm Personnages/obj/*.o Jeu/obj/*.o Jeu/Map/obj/*.o Objets/obj/*.o main.o main rm Personnages/*.gch
