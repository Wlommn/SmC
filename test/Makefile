CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -lm -ldl 

BUILD_PATH = ../build

PROJECT = SmC
TEST = test_$(PROJECT)

OBJ_DIR = ../obj/
OBJ_TEST_DIR = ../obj/test

STACK_SRC = $(notdir $(shell find ../src/stack/ -name "*.c"))
STACK_OBJ = $(OBJ_TEST_DIR)/stack.o

TEST_SRC = $(notdir $(shell find ./ -maxdepth 1 -name "*.c"))
TEST_OBJ = $(TEST_SRC:%.c=%.o)

all: test_compile

test_compile: $(TEST_OBJ) $(STACK_OBJ)
	@$(CC) $(CFLAGS) -lcheck $(addprefix $(OBJ_TEST_DIR)/, $(TEST_OBJ)) $(STACK_OBJ) -o $(BUILD_PATH)/$(TEST).out

%.o: %.c
	@$(CC) $(CFLAGS) -c -o $(addprefix $(OBJ_TEST_DIR)/, $@) $<

$(STACK_OBJ): ../src/stack/stack.c
	@$(CC) $(CFLAGS) -c -o $(STACK_OBJ) ../src/stack/stack.c
