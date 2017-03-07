CXX = g++
CXXFLAGS = -std=c++14 -pthread
GTEST_HOME = C:\Users\b.karjoo\Documents\gtest-1.7.0
INC = -I $(GTEST_HOME) -I $(GTEST_HOME)/include -I . -I ../include -I ../src
LDLIBS = $(GTEST_HOME)/lib/libgtest.a
B = build/
OBJ_FILES = \
	$(B)strategy.o $(B)strat_ma_cross.o \
	$(B)message_subject.o $(B)quote.o $(B)message.o $(B)field.o $(B)cap_char_receiver_interface.o  \
	$(B)cap_file.o $(B)cap_char_receiver.o $(B)exchange_time.o $(B)main.o

TARGET = unit_tests

$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $(OBJ_FILES) -o $(B)$(TARGET)  $(LDLIBS)

$(B)%.o: ../src/%.cpp
	$(CXX) -c $< -o $@ $(INC)

build/main.o : main.cpp strategy_tests.hpp
	$(CXX) -c $< -o $@ $(INC)

tests: $(TARGET)
	$(B)/$(TARGET)

clean:
	del build\*.* /Q
