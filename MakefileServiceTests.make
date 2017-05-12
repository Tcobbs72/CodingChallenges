GTEST_DIR = ThirdParty/googletest

CC = g++

CPPFLAGS = -DDebug \
		   -g \
		   -std=gnu++0x \
		   -I. \
		   -I${GTEST_DIR}/googletest/include \
		   -I${GTEST_DIR}/googlemock/include

SRCS = \
	DocumentParser/DocumentParser.Business/DocumentParser.Business.Service/ConfigLoader.cpp \
	DocumentParser/DocumentParser.Business/DocumentParser.Business.Service/DocumentLoader.cpp \
	DocumentParser/DocumentParser.Business/DocumentParser.Business.Service.Tests/ConfigLoaderTests.cpp \
	DocumentParser/DocumentParser.Business/DocumentParser.Business.Service.Tests/DocumentLoaderTests.cpp \
	DocumentParser/DocumentParser.Business/DocumentParser.Business.Service.Tests/Main.cpp

OBJS = $(addprefix obj/, $(patsubst %.cpp,%.o,$(SRCS)))

targetTestName = CodingChallengeServiceTests

.PHONY: all

all: $(OBJS)
	@echo Creating CodingChallenge Service Tests
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