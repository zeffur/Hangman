FLAG := -std=c99
FLAGS := -std=c11
BIN_DIR := ./bin
BUILD_DIR := ./build
BUILDTEST_DIR := ./build/test
SRC_DIR := ./src
TEST_DIR := ./test
CC := gcc -Wall -Wextra
C := gcc
SDL := `sdl2-config --libs --cflags` -lSDL2_image
.PHONY: clean all test_run

all: $(BIN_DIR)/main $(BIN_DIR)/testing
$(BIN_DIR)/main: $(BUILD_DIR)/main.o $(BUILD_DIR)/menu.o $(BUILD_DIR)/output.o
	$(CC) $(BUILD_DIR)/main.o $(BUILD_DIR)/menu.o $(BUILD_DIR)/output.o $(FLAG) -o $(BIN_DIR)/main $(SDL)

$(BUILD_DIR)/output.o: $(SRC_DIR)/output.c
	$(CC) -c $(SRC_DIR)/output.c -o $(BUILD_DIR)/output.o $(FLAG)

$(BUILD_DIR)/menu.o: $(SRC_DIR)/menu.c
	$(CC) -c $(SRC_DIR)/menu.c -o $(BUILD_DIR)/menu.o $(FLAG)

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.c
	$(CC) -c $(SRC_DIR)/main.c -o $(BUILD_DIR)/main.o $(FLAG)

$(BIN_DIR)/testing: $(BUILDTEST_DIR)/main.o $(BUILDTEST_DIR)/menu.o $(BUILDTEST_DIR)/output.o $(BUILD_DIR)/output.o $(BUILD_DIR)/menu.o
	$(C) $(BUILDTEST_DIR)/main.o $(BUILDTEST_DIR)/menu.o $(BUILDTEST_DIR)/output.o $(BUILD_DIR)/output.o $(BUILD_DIR)/menu.o  $(FLAGS) -o $(BIN_DIR)/testing $(SDL)

$(BUILDTEST_DIR)/menu.o: $(TEST_DIR)/menu.c
	$(C) -c $(TEST_DIR)/menu.c -o $(BUILDTEST_DIR)/menu.o $(FLAGS)

$(BUILDTEST_DIR)/output.o: $(TEST_DIR)/output.c
	$(C) -c $(TEST_DIR)/output.c -o $(BUILDTEST_DIR)/output.o $(FLAGS)

$(BUILDTEST_DIR)/main.o: $(TEST_DIR)/main.c
	$(C) -c $(TEST_DIR)/main.c -o $(BUILDTEST_DIR)/main.o $(FLAGS)

test: all
	$(BIN_DIR)/testing

play: all
	$(BIN_DIR)/main

clean:
		rm -rf $(BIN_DIR)/main
		rm -rf $(BIN_DIR)/testing
		rm -rf $(BUILD_DIR)/*.o
		rm -rf $(BUILDTEST_DIR)/*.o
