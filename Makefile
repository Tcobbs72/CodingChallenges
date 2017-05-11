CC = g++

CPPFLAGS = -DDebug \
		   -g \
		   -std=gnu++0x \
		   -I.

SRCS = \
	DocumentParser/DocumentParser.Business/DocumentParser.Business.Service/ConfigLoader.cpp \
	DocumentParser/DocumentParser.Business/DocumentParser.Business.Service/DocumentLoader.cpp \
	DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/DocumentParser.cpp \
	DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/StringMatchMethod.cpp \
	DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/RegExMethod.cpp \
	DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/IndexedMethod.cpp \
	Main.cpp

OBJS = $(addprefix obj/, $(patsubst %.cpp,%.o,$(SRCS)))

targetName = CodingChallenge

.PHONY: all

all: $(OBJS)
	@echo Creating CodingChallenge Executable
	$(CC) -Wall -g \
		-o $(targetName) $(OBJS)

$(OBJS): obj/%.o: %.cpp
	@echo Compiling $<
	@mkdir -p $(dir $@)
	$(CC) -c $(CPPFLAGS) $< -o $@

clean:
	rm -rf *.exe
	rm -rf obj/*