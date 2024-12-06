CXX = g++
CXXFLAGS = -std=c++11

SRC = src/generator.cpp

TARGET = generator.exe

all: clean $(TARGET) run

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

run: $(TARGET)
	./$(TARGET)

clean:
	del *.exe
	del *.txt

