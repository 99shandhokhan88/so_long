# So_Long - 2D Game Development

## Overview
"so_Long" is a 2D maze game in C where players navigate through a maze, collect items, and reach the exit while avoiding obstacles. It features XPM graphics and keyboard controls using the X-Window with MiniLibX, offering a fun programming project for game development enthusiasts.
My so_long is ispired by the space. The player is a comete that goes through blank black space, the walls are the far stars, the enemies are the Sun or simple near stars, the coins are the stardust that the comete collects and the exit is our planet Earth. No sounds because in space there aren't.
The hardest part of the project was the path finder.
I didn't the bonuses but I implemented the enemies.
The core of the project is the manage of the matrix using the MLX library to show on the window the sprites.

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
- The MLX that I use is for Linux, in fact there are specific flags in the Makefile for Linux.

### Installation
1. Clone the repository to your local machine:
   ```sh
   git clone https://github.com/yourusername/so_long.git so_long
   ```

2. Build the project:
   ```sh
   cd mlx_linux
   make
   cd ..
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


### Matrix Management
The matrix management in "So_Long" plays a crucial role in several aspects of the game:

### 1. Map Representation
The game map is represented as a 2D matrix or grid. Each cell in the grid corresponds to a specific element in the game world, such as walls ('1'), open paths ('0'), collectible coins ('C'), the player character ('P'), and the exit ('E').
This matrix management allows you to easily visualize the game world, making it more intuitive for both players and developers.
### 2. Map Validation
One of the key challenges in this project is verifying the validity of the game map. This involves ensuring that the map is properly enclosed by walls ('1'), the player character ('P') exists, there are coins ('C') to collect, and there's an exit ('E') to reach.
Matrix traversal and validation are performed to ensure the map meets these criteria. This validation step showcases your matrix management skills.
### 3. Player Movement
Player movement is determined by matrix navigation. When the player character ('P') moves in a specific direction (up, down, left, or right), the matrix is updated accordingly. You must ensure that the player doesn't collide with walls ('1') and correctly collects coins ('C') or reaches the exit ('E').
### 4. Map Rendering
To display the game visually, you render the game map using the MinilibX library. Matrix management is used to iterate through the 2D array and draw the corresponding images on the screen.
Efficiently updating the game grid during rendering is essential for providing a smooth gaming experience.
### Key Matrix Operations
Several key matrix operations and logical checks are performed throughout the project:

### Matrix Traversal:
Iterating through the 2D array to access and modify elements based on player movement or game events.

### Element Verification:
Checking the type of element (e.g., '1', '0', 'C', 'P', 'E') at a given matrix position to determine game logic, such as collision, collection, or reaching the exit.

### Matrix Modification:
Updating the matrix to reflect changes in the game world, such as collecting coins ('C' becomes '0') or reaching the exit ('E' becomes 'U').

### Matrix Validation:
Ensuring that the map adheres to predefined rules, which is fundamental for fair gameplay.

### Learning Objectives
The "So_Long" project provides an opportunity to enhance your skills in matrix management, logical operations, and game development using C. It tests your ability to manipulate 2D arrays efficiently for game mechanics and rendering, making it an engaging exercise in applying computer science concepts to real-world applications.

In summary, "So_Long" is more than just a game; it's a practical demonstration of how matrix management is used to create and validate game worlds, control player movements, and render the game visually. This project is a valuable learning experience for those looking to strengthen their skills in C programming and matrix manipulation.


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
