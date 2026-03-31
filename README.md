# Terminal 2048

A fully terminal-based implementation of the classic 2048 game, written in C and powered by ncurses-style rendering, with an integrated autonomous bot capable of playing the game, occasionally reaching 2048.

![Demo](assets/0331.gif)

---

## Features

### Core Game Engine

- Full 2048 mechanics:
    - Tile merging
    - Directional shifting
    - Random tile spawning (2 or 4)
- Efficient in-place board updates using 2D arrays

### Terminal UI
- Clean grid rendering using ANSI escape codes
- Color-coded tiles for readability (see ```tile_style()``` in cli.c)

### AI Bot
- Evaluates all 4 possible moves
- Scores resulting board states
- Chooses the optimal move dynamically

### Game loop
- Real-time board updates
- Continuous play until termination (no hard stop condition)

## Architecture

```
                ┌───────────────┐
                │   main.c      │
                │ Game Loop     │
                └──────┬────────┘
                       │
        ┌──────────────┼──────────────┐
        │              │              │
┌──────────────┐ ┌──────────────┐ ┌──────────────┐
│   game.c     │ │    bot.c     │ │    cli.c     │
│ Game Logic   │ │ AI Decision  │ │ Rendering    │
└──────────────┘ └──────────────┘ └──────────────┘
```

## Game Flow

```
Start Game
    ↓
Initialize Board
    ↓
Place Random Tiles
    ↓
──────── LOOP ────────
    ↓
Display Board
    ↓
Get Input (User / Bot)
    ↓
Merge Tiles (add_values)
    ↓
Shift Tiles (shift_values)
    ↓
Spawn New Tile (add_two)
    ↓
Repeat
```

## Bot Strategy

The bot works by simulating all 4 possible moves:
```
for each move:
    copy board
    simulate move
    evaluate board
choose best scoring move
```
(See ```best_move()``` in bot.c)

## Heuristic Evaluation System

The bot assigns a score to each board using:

### Empty Space Reward

Encourages open boards

```
if (board[i][j] == 0) count += 20;
```

### Merge Potential

Rewards adjacent equal tiles

```
if (neighbor == current) count += 2;
```

### Monotonacity (Gradient)

- Encourages descending order rows
- Helps build high-value tiles in one direction

### Max Tile Positioning

Prefers largest tile in a corner

```
if (board[0][0] == MAX) count += 10;
```

## Bot Decision Diagram

```
           Current Board
                 │
     ┌───────────┼───────────┐
     │           │           │
   Move ↑      Move ↓      Move →
     │           │           │
 Evaluate      Evaluate     Evaluate
     │           │           │
     └───────┬───┴───┬───────┘
             │       │
         Compare Scores
             │
         Select Best Move
```

## File Breakdown

### main.c
- Game loop controller
- Handles:
    - Input (user vs bot)
    - Rendering
    - State updates

### cli.c/cli.h
- Terminal rendering layer
- ANSI color styling for tiles

### game.c/game.h
Core Mechanics:
    - Tile Merging --> ```add_values()```
    - Tile shifting --> ```shift_values()```
    - Tile spawning --> ```add_two()```

### bot.c/bot.h

- AI logic and scoring system
- Key function:
    - ```best_move()``` --> selects optimal move
    - ```evaluate()``` --> scores board state
- Uses board simulation + heuristics

## Controls

| Key | Action         |
|-----|----------------|
| ↑   | Merge Up       |
| ↓   | Merge Down     |
| ←   | Merge Left     |
| →   | Merge Right    |
| b   | Enable Bot Mode|


## How to Run

### 1. Install ncurses

macOS (Homebrew)
```
brew install ncurses
```

Ubuntu / Debian
```
sudo apt install libncurses-dev
```

### 2. Build
```
gcc *.c -lncurses
```

### 3. Run
```
./a.out
```
