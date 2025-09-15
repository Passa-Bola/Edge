CC = gcc
CFLAGS = -Wall -I/usr/local/include
LDFLAGS = -L/usr/local/lib -lpaho-mqtt3cs

TARGET = simulator
SOURCES = simulator.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

