# So_Long - 2D Game Development

## Table of Contents
- [Overview](#overview)
- [Project Description](#project-description)
- [Getting Started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Installation](#installation)
- [How to Play](#how-to-play)
- [Map Design](#map-design)
- [Code Structure](#code-structure)

## Overview
"so_Long" is a 2D maze game in C where players navigate through a maze, collect items, and reach the exit while avoiding obstacles. It features XPM graphics and keyboard controls using the X-Window with MiniLibX, offering a fun programming project for game development enthusiasts.

## Project Description
"So_Long" is a simple game with the following features:
- A player character ('P') that you control using the keyboard arrow keys.
- Collectible coins ('C') scattered throughout the map.
- An exit ('E') that you need to reach to win the game.
- Walls ('1') that act as barriers and define the map layout.
- The goal is to collect all the coins and reach the exit while avoiding obstacles.

## Getting Started

### Prerequisites
- A C compiler (e.g., GCC).
- MinilibX graphics library (provided in the project files).

### Installation
1. Clone the repository to your local machine:
   ```sh
   git clone https://github.com/yourusername/so_long.git so_long
   ```

2. Build the project:
   ```sh
   make
   ```

3. Run the game with a map file as an argument (example: `map1.ber`):
   ```sh
   ./so_long maps/map1.ber
   ```

## How to Play
- Use the arrow keys or WASD to move the player character ('P').
- Collect all the coins ('C') on the map.
- Reach the exit ('E') to win the game.
- Avoid colliding with walls ('1') and enemies ('N') obstacles.

## Map Design
- Maps are designed using simple text files with specific characters to represent different elements:
  - '1' for walls.
  - '0' for open paths.
  - 'C' for coins.
  - 'E' for the exit.
  - 'P' for the player character.
  - You can create your custom maps by modifying the text files in the `maps` directory.

## Code Structure
- `libft/`: Directory containing some utility functions from my projects "libft", "get_next_line" and "ft_printf".
- `maps/`: Directory containing example map text .ber files.
- `mlx_linux/`: Directory containing the custom implementation by 42 of the LibX library.
- `skins/`: Directory containing the sprites of .xpm files.
- `Makefile`: The Makefile of the project (it compiles also libft and mlx_linux).
- `check_map.c`: Some checks functions for the map.
- `check_map_init.c`: Functions to check the validity of the map.
- `draw_map.c`: Functions for rendering the game and updating the display.
- `main.c`: The main entry point for the game, handling initialization and map loading.
- `path_finder.c`: The check of a valid path in the map.
- `player.c`: The management of the player in the matrix taking the signals from the keyboard.
- `so_long.c`: The creation of the map from the .xpm file.
- `so_long.h`: Header file containing function prototypes and structures.

---
