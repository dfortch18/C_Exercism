GCC = gcc

SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
BUILD_DIR = build

SRCS = $(shell find $(SRC_DIR) -name *.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))
CFLAGS = -I$(INCLUDE_DIR) -Wall -Wextra

TARGET = $(BUILD_DIR)/c_exercism

all: $(TARGET)

$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(GCC) $(CFLAGS) -o $(TARGET) $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(GCC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR) $(BUILD_DIR) $(PREPROCESS_DIR)

clean-obj:
	rm -rf $(OBJ_DIR)/*.o
