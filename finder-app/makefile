# Makefile

TARGET = writer
OBJ = writer.o
SRC = writer.c

ifeq ($(CROSS_COMPILE),)
	CC = gcc
endif

# Default target
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	@echo --------- Start build ----------
	@echo Compiler: $(CC)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	@echo --------- Finished build -----------
	@echo

clean:
	@echo --------- Start clean Project ----------
	@rm -f $(TARGET) *.o 2>/dev/null
	@echo ---------- Finished Cleaning -----------
	@echo