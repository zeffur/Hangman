FLAGS := -std=c11
BIN_DIR := ./bin
BUILD_DIR := ./build
SRC_DIR := ./src
CC := g++ -Wall -Werror
SDL := `sdl2-config --libs --cflags` --std=c99 -lSDL2_image
.PHONY: clean

all: $(BIN_DIR)/main
	./bin/main
$(BIN_DIR)/main: $(BUILD_DIR)/main.o $(BUILD_DIR)/menu.o $(BUILD_DIR)/output.o
	$(CC) $(BUILD_DIR)/main.o $(BUILD_DIR)/menu.o $(BUILD_DIR)/output.o $(SDL) -o $(BIN_DIR)/main $(FLAG)

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/main.o $(FLAG)

$(BUILD_DIR)/menu.o: $(SRC_DIR)/menu.cpp
	$(CC) -c $(SRC_DIR)/menu.cpp -o $(BUILD_DIR)/menu.o $(FLAG)

$(BUILD_DIR)/output.o: $(SRC_DIR)/output.cpp
	$(CC) -c $(SRC_DIR)/output.cpp -o $(BUILD_DIR)/output.o $(FLAG)

#main `sdl2-config --libs --cflags` --std=c99 -lSDL2_image -lm -o main


clean:
	rm -rf $(BIN_DIR)/main
	rm -rf $(BLD_DIR)/*.o
