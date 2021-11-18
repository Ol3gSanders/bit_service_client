INCLUDES = -Iinclude -I__unittests
UNITS = main.cc src/*.cc
TEST_UNITS = src/*.cc __unittests/*.cc

all: win

win:
	mkdir -p __bin
	g++ -std=c++11 $(INCLUDES) $(UNITS) -o __bin/bit_service

win_test:
	mkdir -p __bin
	g++ -std=c++11 $(INCLUDES) $(TEST_UNITS) -o __bin/bit_service_test_runner
	
rebuild: clean all

clean:
	rm -rf __bin/*
