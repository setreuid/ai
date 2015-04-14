CC = g++
OBJS = Core/start.o Npc/class_npc.o Lib/InitDefine.o
TARGET = start
CFLAGS = -Wno-deprecated -pthread

.SUFFIXES : .c .o

all : $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)

