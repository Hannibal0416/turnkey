CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		trunkey.o JVMLoader.o JVMService.o TurnkeyBridge.o

LIBS =

TARGET =	trunkey.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
