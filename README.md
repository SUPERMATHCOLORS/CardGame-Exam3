# Card Game

## What the program does

This is a terminal-based card game that uses multiple different derivitaves of position and also somewhat displacement. The goal is to reach at least
2500 displacement within 10 turns.

## Build and Run

From the project directory, build and run the game:

```sh
make
./card-game
```

Remove the executable and object files:

```sh
make clean
```

## Required Feature

The requried feature that I used was std::vector in deck to manage the deck, hand and the discard pile. (though currently the discard pile doesn't do anything except for collect cards maybe in a future version I could do somthing with it but right now it does nothing)

## How to play the game

when you start up the game you are shown the basic goal of the game and what cards you drew on your first turn.
each turn you draw 1 card and can play up to 3.
also to note before that you will move an amount by your velocity and each higher derivitave of position/motion/displacement or whatever it is called will alter the one below it in the sequence pop->crackle->snap->jerk->acceleration->velocity->displacement.
