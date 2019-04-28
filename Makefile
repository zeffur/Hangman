FLAGS := -std=99
BIN_DIR := ./bin
BUILD_DIR := ./build
SRC_DIR := ./src
CC := g++ -Wall -Werror
.PHONY: clean

all: $(BIN_DIR)/main
$(BIN_DIR)/main: $(BUILD_DIR)/main.o $(BUILD_DIR)/menu.o $(BUILD_DIR)/output.o
	$(CC) $(BUILD_DIR)/main.o $(BUILD_DIR)/menu.o $(BUILD_DIR)/output.o -o $(BIN_DIR)/main $(FLAG)

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/main.o $(FLAG)

$(BUILD_DIR)/menu.o: $(SRC_DIR)/menu.cpp
	$(CC) -c $(SRC_DIR)/menu.cpp -o $(BUILD_DIR)/menu.o $(FLAG)

$(BUILD_DIR)/output.o: $(SRC_DIR)/output.cpp
	$(CC) -c $(SRC_DIR)/output.cpp -o $(BUILD_DIR)/output.o $(FLAG)



clean:
	rm -rf $(BIN_DIR)/main
	rm -rf $(BUILD_DIR)/*.o
