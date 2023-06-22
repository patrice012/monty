APPLICATION := monty

# Directories 
BUILD_DIR := build
SRC_DIR := .
INC_DIR := .
OBJ_DIR := objects
TEST_DIR := tests
TMP_DIR := .tmp

# Make flags
MAKEFLAGS += -s

# Compiler flags
CC := gcc
CFLAGS := -Wall -Werror -Wextra -pedantic -std=c89 -ggdb3

# Files
SOURCE_FILES := $(wildcard $(SRC_DIR)/*.c)
HEADER_FILES := $(wildcard $(INC_DIR)/*.h)
OBJECT_FILES := $(patsubst %.c, $(OBJ_DIR)/%.o, $(SOURCE_FILES))
DEP_FILES := $(OBJECT_FILES:.o=.d)
EXECUTABLE := $(BUILD_DIR)/$(APPLICATION)

# Tests
INTEGRATION_TESTS_FILES = $(patsubst $(TEST_DIR)/integration/%.py,%,$(wildcard $(TEST_DIR)/integration/*.py))
UNIT_TEST_FILES = $(patsubst %.c, %, $(notdir $(wildcard $(TEST_DIR)/unit/*.c)))

all: clear_screen check_style build run_tests check_memory

build: setup_dirs $(EXECUTABLE)
	@$(MAKE) announce MESSAGE="Compiled successfully"

$(EXECUTABLE): $(OBJECT_FILES)
	$(CC) $(CFLAGS) -I${INC_DIR} -I${SRC_DIR} $^ -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -I${INC_DIR} -I${SRC_DIR} -MMD -c $^ -o $@

-include $(DEPS)

run:
	@$(MAKE) announce MESSAGE="Running $(APPLICATION)"
	@./$(EXECUTABLE) $(TEST_DIR)/bytecodes/00.m

integration_tests: $(INTEGRATION_TESTS_FILES)

$(INTEGRATION_TESTS_FILES): %: $(TEST_DIR)/integration/%.py
	@python $<

unit_tests: $(UNIT_TEST_FILES)

$(UNIT_TEST_FILES): %: $(TEST_DIR)/unit/%.c
	$(CC) $(filter-out ./monty.c, $(SOURCE_FILES)) $< -o $(TMP_DIR)/$@.o
	@if ./$(TMP_DIR)/$@.o 2>&1 >/dev/null; then \
		echo "Test $@ passed"; \
	else \
		echo "Test $@ failed"; \
		./$(TMP_DIR)/$@.o; \
	fi; \

run_tests: setup_dirs
	@$(MAKE) announce MESSAGE="Running unit tests"
	@$(MAKE) -k -j 8 unit_tests
	@$(MAKE) announce MESSAGE="Running integration tests"
	@$(MAKE) -k -j 8 integration_tests

setup_dirs:
	@mkdir -p $(OBJ_DIR)
	@mkdir -p ./$(BUILD_DIR)
	@mkdir -p ./$(TEST_DIR)
	@mkdir -p ./$(TEST_DIR/integration)
	@mkdir -p ./$(TEST_DIR/unit)
	@mkdir -p ./$(TMP_DIR)

announce:
	@echo "------------------------------------------"
	@printf "|%*s%s%*s|\n" $$(expr 20 - $${#MESSAGE} / 2) "" "$(MESSAGE)" $$(expr 20 - $$(($${#MESSAGE} + 1)) / 2) ""
	@echo "------------------------------------------"

clear_screen:
	@clear

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(BUILD_DIR)

check_style:
	@$(MAKE) announce MESSAGE="Checking code style"
	@betty-style --allow-global-variables --no-summary ${SOURCE_FILES} ${HEADER_FILES}
	@betty-doc ${SOURCE_FILES} ${HEADER_FILES} > $(TMP_DIR)/betty-doc.txt && \
		(make announce MESSAGE="No styling issuse found" && exit 0) || \
		(cat $(TMP_DIR)/betty-doc.txt && exit 1)

check_memory:
	@$(MAKE) announce MESSAGE="Checking memory leaks"
	(valgrind --leak-check=full --show-leak-kinds=all --errors-for-leak-kinds=all --track-origins=yes \
	-s --error-exitcode=1 ./$(EXECUTABLE) $(TEST_DIR)/bytecodes/all.m > ${TMP_DIR}/all.vg 2>&1)  && \
	(make announce MESSAGE="No memory leaks found" && exit 0) || \
	(echo "Error: memory leak found" && cat ${TMP_DIR}/all.vg && exit 1) \

setup_stderred:
	git clone https://github.com/sickill/stderred.git $(TMP_DIR)/stderred
	cd $(TMP_DIR)/stderred && make
