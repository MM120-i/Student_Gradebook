# Compiler and flags
CC = gcc
CFLAGS = -Wall

# Source files and headers
SRCS = gradebook.c
HDRS = 
OBJS = $(SRCS:.c=.o)

# Executable name
EXEC = gradebook

# Targets
all: $(EXEC)

$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(EXEC)

%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(EXEC)
