CC = gcc
C++ = g++

CCFLAGES = -g -c
CxxLAGES = -g -c

TARGET = test

SRCS_C :=$(wildcard *.c) 
SRCS_CPP :=$(wildcard *.cpp) 

OBJS_C :=$(patsubst %.c, %.o, $(SRCS_C)) 
OBJS_CPP :=$(patsubst %.cpp, %.o, $(SRCS_CPP)) 
OBJS := $(OBJS_C) $(OBJS_CPP)

%.o: %.c
	$(CC) $(CCFLAGES) $< 

%.o:%.cpp
	$(C++) $(CxxLAGES) $< 

$(TARGET):$(OBJS) 
	$(CC) $(CFLAGES) -o $@ $(OBJS) -lstdc++
	# g++ .\test.cpp ..\Array\array.cpp ..\Llink\llink.cpp

.PHONY:clean clean_all
clean: 
	rm -rf *.o

clean_all:
	rm -rf *.o $(TARGET)