CC = gcc
CFLAGS = -Wall -g
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
TARGET = main

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf *.o $(TARGET)

.PHONY : clean 	