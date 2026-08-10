CC := $(CROSS_COMPILE)gcc
CFLAGS := -Wall -Werror

TARGET := writer
OBJS := writer.o

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) *.o
