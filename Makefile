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

### VARIABLES Répertoire ./Utilities/ ###
OBJ_DIR_UTILITIES = ./Utilities/obj/

UTILITIES_SRC = ./Utilities/
UTILITIES_SRCS = $(wildcard $(UTILITIES_SRC)*.cpp)
OBJ_UTILITIES = $(notdir $(UTILITIES_SRCS:.cpp=.o))
OBJ_UTILITIES := $(addprefix $(OBJ_DIR_UTILITIES), $(OBJ_UTILITIES))
###

all:main

run:main
	./main

tar:
	tar -czvf ElkoussyKetels.tar.gz Jeu/ Makefile Objets/ Personnages/ README.md Utilities/ main.cpp ProjetLOA-UML.pdf Rapport.pdf

print:
	@echo $(UTILITIES_SRCS)
	@echo $(OBJ_UTILITIES)

main : main.o $(OBJ_UTILITIES) $(OBJ_OBJETS) $(OBJ_PERSONNAGES) $(OBJ_JEU) $(OBJ_MAP)
	$(CPP) $(CFLAGS) -o $@ $^

main.o : main.cpp
	$(CPP) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_PERSONNAGES)%.o : $(PERSONNAGES_SRC)%.cpp | $(OBJ_DIR_PERSONNAGES)
	$(CPP) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_JEU)%.o : $(JEU_SRC)%.cpp | $(OBJ_DIR_JEU)
	$(CPP) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_MAP)%.o : $(MAP_SRC)%.cpp | $(OBJ_DIR_MAP)
	$(CPP) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_OBJETS)%.o : $(OBJETS_SRC)%.cpp | $(OBJ_DIR_OBJETS)
	$(CPP) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_UTILITIES)%.o : $(UTILITIES_SRC)%.cpp | $(OBJ_DIR_UTILITIES)
	$(CPP) $(CFLAGS) -c $< -o $@



$(OBJ_DIR_OBJETS):
	@mkdir -p $(OBJ_DIR_OBJETS)

$(OBJ_DIR_PERSONNAGES):
	@mkdir -p $(OBJ_DIR_PERSONNAGES)

$(OBJ_DIR_JEU):
	@mkdir -p $(OBJ_DIR_JEU)

$(OBJ_DIR_MAP):
	@mkdir -p $(OBJ_DIR_MAP)

$(OBJ_DIR_UTILITIES):
	@mkdir -p $(OBJ_DIR_UTILITIES)

clean:
	rm Personnages/obj/*.o Jeu/obj/*.o Jeu/Map/obj/*.o Objets/obj/*.o main.o main Utilities/obj/*.o
