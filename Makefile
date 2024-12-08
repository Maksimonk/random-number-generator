CXX = g++
CXXFLAGS = -std=c++14

SRC = $(wildcard src/*.cpp)

TARGET = generator.exe

all: clean $(TARGET) run

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	del generator.exe numbers.txt