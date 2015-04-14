CC = g++
OBJS = Core/start.o Npc/class_npc.o
TARGET = start
DEFS = -Wno-deprecated

.SUFFIXES : .c .o

all : $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(DEFS) -o $@ $(OBJS)

clean:
	rm -f $(OBJS) $(TARGET)
