GTEST_DIR = ThirdParty/googletest/

CC = g++

CPPFLAGS = -DDebug \
		   -g \
		   -std=c++11 

LFLAGS = -Wall $(DEBUG)

OBJS = Main.o
SRCS = Main.cpp

targetName = CodingChallenge

.PHONY: all

all: $(targetName)

$(targetName) : $(OBJS)
	@echo Creating CodingChallenge Executable
	$(CC) $(LFLAGS) $(OBJS) -o $(targetName)

Main.o: Main.cpp
	$(CC) $(CPPFLAGS) Main.cpp

clean:
	rm -rf *.o *.exe