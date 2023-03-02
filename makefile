UNIT_TEST = src/unit_test.cpp
HW1 = src/hw1.cpp
MAIN = src/main.cpp

GCC = g++ -Wall -std=c++11 

T = main

$(T): $(UNIT_TEST) $(HW1) $(MAIN)
	$(GCC) $^ -o $@  -lgtest -lpthread


.PHONY:clean

clean:
	rm  $(T)