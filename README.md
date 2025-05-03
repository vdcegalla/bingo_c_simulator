# Bingo Game  
A simple Bingo game implemented in C where a random 5x5 card is generated and numbers are drawn until a win condition (complete line, column, or diagonal) is met.

## Features
- Generates a valid 5x5 Bingo card.
- Automatically draws unique random numbers from 1 to 75.
- Marks numbers on the card as they are drawn.
- Detects and stops when a winning condition is reached (horizontal, vertical, or diagonal line).
- Displays the card after each draw.

## How to Use
1. Compile and run the C program.
2. The game will:
   - Generate and display a Bingo card.
   - Start drawing numbers randomly.
   - Mark drawn numbers on the card.
   - Display the updated card after each draw.
   - Stop when a "Bingo" (a full line, column, or diagonal of zeros) is achieved.

## Running Locally
1. Clone this repository:
   ```bash
   git clone https://github.com/YOUR_USERNAME/bingo-c.git
   ```
2. Compile the code using a C compiler, for example:
   ```bash
   gcc bingo.c -o bingo
   ```
3. Run the executable:
   ```bash
   ./bingo
   ```

## Next Steps
- Improve the interface with user input options.
- Create a graphical version of the game.

## Technologies Used
- C (Standard Library)
- Terminal I/O (`stdio.h`)
- Random number generation (`stdlib.h`, `time.h`)