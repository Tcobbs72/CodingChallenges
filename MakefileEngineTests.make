GTEST_DIR = ThirdParty/googletest

CC = g++

CPPFLAGS = -DDebug \
		   -g \
		   -std=gnu++0x \
		   -I. \
		   -I${GTEST_DIR}/googletest/include \
		   -I${GTEST_DIR}/googlemock/include

SRCS = \
	DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/DocumentParser.cpp \
	DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/StringMatchMethod.cpp \
	DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/RegExMethod.cpp \
	DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine/IndexedMethod.cpp \
	DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine.Tests/StringMatchMethodTests.cpp \
	DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine.Tests/RegExMethodTests.cpp \
	DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine.Tests/IndexedMethodTests.cpp \
	DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine.Tests/DocumentParserTests.cpp \
	DocumentParser/DocumentParser.Business/DocumentParser.Business.Engine.Tests/Main.cpp

OBJS = $(addprefix obj/, $(patsubst %.cpp,%.o,$(SRCS)))

targetTestName = CodingChallengeEngineTests

.PHONY: all

all: $(OBJS)
	@echo Creating CodingChallenge Engine Tests
	$(CC) -Wall -g \
		-o $(targetTestName) $(OBJS) \
		${GTEST_DIR}/googletest/libgtest.a \
		${GTEST_DIR}/googlemock/libgmock.a


$(OBJS): obj/%.o: %.cpp
	@echo Compiling $<
	@mkdir -p $(dir $@)
	$(CC) -c $(CPPFLAGS) $< -o $@

clean:
	rm -rf *.exe
	rm -rf obj/*