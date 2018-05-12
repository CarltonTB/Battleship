COMPILER := g++
COMPILE_ARGS := -Wall
SRC_EXT := cpp
SRC_DIR := src
BUILD_DIR := build
SOURCES := $(shell find $(SRC_DIR) -type f -name *.$(SRC_EXT))
OBJECTS := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(SOURCES:.$(SRC_EXT)=.o))
INC := -I include

main:
	$(COMPILER) $(COMPILE_ARGS) $(INC) -o battleship $(SOURCES)

clean:
	rm -f battleship
	rm -r battleship.dSYM
