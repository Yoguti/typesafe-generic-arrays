CC = gcc
CFLAGS = -Wall -Wextra -Werror -Wshadow -Wconversion -Wundef -Wstrict-prototypes \
         -Wcast-align -Wwrite-strings -Wswitch-default -Wswitch-enum -Waggregate-return \
         -Wfloat-equal -Wpointer-arith -Wstrict-overflow=5 -Wcast-qual -Wunreachable-code \
         -Wpadded -Wformat-overflow -Wformat-truncation -O2

SRC_DIR = src
BUILD_DIR = build
TARGET = $(BUILD_DIR)/program

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)
