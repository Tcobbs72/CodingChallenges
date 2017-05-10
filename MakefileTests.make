GTEST_DIR = ThirdParty/googletest

CC = g++

CPPFLAGS = -DDebug \
		   -g \
		   -std=gnu++0x \
		   -I. \
		   -I${GTEST_DIR}/googletest/include \
		   -I${GTEST_DIR}/googlemock/include

SRCS = \
	DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/StringMatchMethod.cpp \
	DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/RegExMethod.cpp \
	DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/IndexedMethod.cpp \
	DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine.Tests/SampleTest.cpp \
	DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine.Tests/Main.cpp

OBJS = $(addprefix obj/, $(patsubst %.cpp,%.o,$(SRCS)))

targetTestName = CodingChallengeTests

.PHONY: all

all: $(OBJS)
	@echo Creating CodingChallenge Tests
	$(CC) -Wall -g \
		-o $(targetTestName) $(OBJS) \
		${GTEST_DIR}/googletest/libgtest.a

$(OBJS): obj/%.o: %.cpp
	@echo Compiling $<
	@mkdir -p $(dir $@)
	$(CC) -c $(CPPFLAGS) $< -o $@

clean:
	rm -rf *.exe
	rm -rf obj/*