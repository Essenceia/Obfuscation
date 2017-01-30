CC = gcc
CFLAGS  = -g -Wall
# the build target executable:
TARGET = decoup
all: $(TARGET)
$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	$(RM) $(TARGET)
