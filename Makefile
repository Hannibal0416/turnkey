CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		turnkey.o JVMLoader.o SignatureBridge.o GatewayBridge.o

LIBS =

TARGET =	turnkey.exe

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:	$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)
