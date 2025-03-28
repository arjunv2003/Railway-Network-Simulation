CXX = g++
CXXFLAGS = -std=c++17 -pthread -I include
SOURCES = src/*.cpp
OUTPUT = railway_sim

all: $(OUTPUT)

$(OUTPUT): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) -o $(OUTPUT)

clean:
	rm -f $(OUTPUT)

run: $(OUTPUT)
	./$(OUTPUT)