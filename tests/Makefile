CXX = g++

GTEST_HOME = C:\Users\b.karjoo\Documents\gtest-1.7.0
INC = -I $(GTEST_HOME) -I $(GTEST_HOME)/include -I . -I ../include -I ../src
LDLIBS = $(GTEST_HOME)/lib/libgtest.a
LDFLAGS =
CXXFLAGS = -std=c++14 -pthread

TARGET = unit_tests

BUILD_DIR = ./build
SRCS = $(wildcard *.cpp)
OBJ = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)
DEPS = $(OBJ:%.o=%.d)

$(TARGET) : $(BUILD_DIR)/$(TARGET)

$(BUILD_DIR)/$(TARGET) : $(OBJ)
	$(CXX) -c ../src/cap_char_receiver_interface.cpp -o ./build/cap_char_receiver_interface.o -I ../include
	$(CXX) -c ../src/cap_char_receiver.cpp -o ./build/cap_char_receiver.o -I ../include
	$(CXX) -c ../src/cap_file.cpp -o ./build/cap_file.o -I ../include
	$(CXX) $(CXXFLAGS) build/cap_file.o build/cap_char_receiver_interface.o build/cap_char_receiver.o $^ -o $@ $(LDFLAGS) $(LDLIBS)

-include $(DEPS)

$(BUILD_DIR)/%.o : %.cpp
	$(CXX) -static $(CXXFLAGS) -MMD -c $< -o $@ $(INC)

.PHONY: all clean tests

all: clean $(TARGET)

clean:
	rm -fr $(BUILD_DIR)

tests: $(TARGET)
	$(BUILD_DIR)/$(TARGET)
