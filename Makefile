CC = g++
OBJS = Core/start.o
TARGET = start

.SUFFIXES : .c .o

all : $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)
