FLAG := -std=c++98
FLAGS := -std=c++11
BIN_DIR := ./bin
BUILD_DIR := ./build
BUILDTEST_DIR := ./build/test
SRC_DIR := ./src
#BINTEST_DIR := ./bin/test
TEST_DIR := ./test
CC := g++ -Wall -Wextra
C := g++
SDL := `sdl2-config --libs --cflags` --std=c99 -lSDL2_image
.PHONY: clean all test_run

all: $(BIN_DIR)/main
$(BIN_DIR)/main: $(BUILD_DIR)/main.o $(BUILD_DIR)/menu.o $(BUILD_DIR)/output.o
	$(CC) $(BUILD_DIR)/main.o $(BUILD_DIR)/menu.o $(BUILD_DIR)/output.o $(SDL) -o $(BIN_DIR)/main $(FLAG)

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp
	$(CC) -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/main.o $(FLAG)

$(BUILD_DIR)/menu.o: $(SRC_DIR)/menu.cpp
	$(CC) -c $(SRC_DIR)/menu.cpp -o $(BUILD_DIR)/menu.o $(FLAG)

$(BUILD_DIR)/output.o: $(SRC_DIR)/output.cpp
	$(CC) -c $(SRC_DIR)/output.cpp -o $(BUILD_DIR)/output.o $(FLAG)

#main `sdl2-config --libs --cflags` --std=c99 -lSDL2_image -lm -o main

$(BIN_DIR)/testing: $(BUILDTEST_DIR)/output.o $(BUILD_DIR)/output.o
	$(C) $(BUILDTEST_DIR)/output.o $(BUILD_DIR)/output.o $(SDL) -o $(BINTEST_DIR)/testing $(FLAGS)
# $(BUILDTEST_DIR)/menu.o $(BUILDTEST_DIR)/main.o $(BUILDTEST_DIR)/menu.o
#$(BUILDTEST_DIR)/main.o: $(TEST_DIR)/main.cpp
#	$(C) -c $(TEST_DIR)/main.cpp -o $(BUILDTEST_DIR)/main.o $(FLAGS)

$(BUILDTEST_DIR)/output.o: $(TEST_DIR)/output.cpp
	$(C) -c $(TEST_DIR)/output.cpp -o $(BUILDTEST_DIR)/output.o $(FLAGS)

#$(BUILDTEST_DIR)/menu.o: $(TEST_DIR)/menu.cpp
#	$(C) -c $(TEST_DIR)/menu.cpp -o $(BUILDTEST_DIR)/menu.o $(FLAGS)


test: all
	$(BIN_DIR)/testing


clean:
		rm -rf $(BIN_DIR)/main
		rm -rf $(BINTEST_DIR)/testing
		rm -rf $(BUILD_DIR)/*.o
		rm -rf $(BUILDTEST_DIR)/*.o
