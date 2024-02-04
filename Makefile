CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -lm -ldl -g
GTK_FLAGS = $(shell pkg-config --cflags gtk4 )
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

UI_DIR = ./src/gui
OBJ_DIR = ./obj
TEST_DIR = ./test
TEST_OBJ_DIR = ./obj/test
BUILD_PATH = ./build

PROJECT = SmC
TEST = test_${PROJECT}

LIBS = $(shell pkg-config --libs gtk4 )

PROJECT_DIRS = $(shell find ./src/ -type d)
PROJECT_SRC = $(notdir $(shell find $(PROJECT_DIRS) -maxdepth 1 -name "*.c"))
PROJECT_DEPS = $(shell find ./src/ -maxdepth 1 -name "*.h")
PROJECT_OBJ = $(PROJECT_SRC:%.c=%.o)

ALL_PROJECT_FILES = $(shell find ./ -type f | grep "\.(c|h)$$" -E)

vpath %.c $(PROJECT_DIRS)
vpath %.o $(OBJ_DIR)

all: $(PROJECT)

$(PROJECT): $(PROJECT_DEPS) $(OBJ_DIR) $(PROJECT_OBJ)
	@$(CC) $(CFLAGS) $(GTK_FLAGS) $(addprefix $(OBJ_DIR)/, $(PROJECT_OBJ)) -o $(BUILD_PATH)/$(PROJECT).out $(LIBS)

test: $(OBJ_DIR) $(TEST_OBJ_DIR)
	make -C ./test

%.o: %.c $(PROJECT_DEPS)
	@$(CC) $(CFLAGS) $(GTK_FLAGS)  -c -o $(addprefix $(OBJ_DIR)/, $@) $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(TEST_OBJ_DIR):
	mkdir -p $(OBJ_DIR)/test

clang-format:
	clang-format --style=Google -n $(ALL_PROJECT_FILES)

leaks: $(PROJECT)
	leaks -atExit -- ./$(PROJECT).out

valgrind: test
	valgrind --track-origins=yes --leak-check=full -s ./build/$(TEST).out

open: $(BUILD_PATH)/$(PROJECT).out
	$(shell $(BUILD_PATH)/$(PROJECT).out)

clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf ./test/*.a *.a *.o

rebuild:
	$(MAKE) clean
	@rm -rf $(BUILD_PATH)/$(PROJECT).out
	$(MAKE) all

test_rebuild:
	$(MAKE) clean
	@rm -rf $(BUILD_PATH)/test_$(PROJECT).out
	$(MAKE) test
