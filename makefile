CXX = g++
CXXFLAGS = -g -Wall -Wextra -Wpedantic -std=c++17 -I.

TARGET = card-game
OBJECTS = main.o GameLoop.o user_io.o GameData.o Deck.o Card.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

main.o: main.cpp game.h GameData.h Deck.h Card.h
GameLoop.o: GameLoop.cpp game.h GameData.h Deck.h Card.h
user_io.o: user_io.cpp game.h GameData.h Deck.h Card.h
GameData.o: GameData.cpp GameData.h Deck.h Card.h
Deck.o: Deck.cpp Deck.h Card.h
Card.o: Card.cpp Card.h

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


.PHONY: all clean
clean:
	rm -f $(OBJECTS) $(TARGET)
