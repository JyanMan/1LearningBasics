CC = gcc
CFLAGS = -Wall -g

SRCS = main.c somelib.c
OBJS = $(SRCS:.c=.o)
TARGET = main.exe

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)
