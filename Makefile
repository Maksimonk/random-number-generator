CXX = g++
CXXFLAGS = -std=c++11

SRC = $(wildcard src/*.cpp)

TARGET = generator.exe

all: clean $(TARGET) run

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	del generator.exe file_output.txt