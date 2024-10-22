# Makefile

Compiler = Native Compiler
TARGET = writer
CFLAGS = -Wall
OBJ = writer.o
SRC = writer.c
CC = gcc

ifeq ($(CROSS_COMPILE), aarch64-none-linux-gnu-gcc)
	Compiler = $(CROSS_COMPILE)
	CC = $(CROSS_COMPILE)
endif

# Default target
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	@echo --------- Start build ----------
	@echo Compiler: $(Compiler)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo --------- Finished build -----------
	@echo

clean:
	@echo --------- Start clean Project ----------
	@rm -f $(TARGET) *.o 2>/dev/null
	@echo ---------- Finished Cleaning -----------
	@echo