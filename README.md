# Candy Crush (C++ / SFML)

A desktop Candy Crush clone built in C++ with the SFML graphics library. Match-three gameplay rendered in an 800×600 window.

## What it does

A grid of colored candies the player swaps to form matching rows or columns, which clear and score points. Rendering, input handling, and the game loop are built directly on SFML's window and graphics modules.

## Tech stack

- C++
- [SFML](https://www.sfml-dev.org/) (Graphics + Window modules)

## How to run

Requires SFML installed and linked. Compile `Source.cpp` against the SFML libraries:

```bash
g++ Source.cpp -o candycrush -lsfml-graphics -lsfml-window -lsfml-system
./candycrush
```

## Status

Early C++ coursework project — single-file implementation kept for reference.
