CXX = g++
CXXFLAGS = -std=c++14

SRC = $(wildcard src/*.cpp)

TARGET = file_speed_generator.exe

all: clean $(TARGET) run

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	del file_speed_generator.exe numbers.txt bit_numbers.txt testFile.txt final_random.txt bit_final_random.txt