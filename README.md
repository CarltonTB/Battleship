AUTHOR: Carlton Brady

DESCRIPTION:
This project lets you play battleship on the command line against a smart opponent or a dumb opponent. The dumb opponent takes random guesses and the smart opponent makes guesses that are smart given the state of the board. For example, the smart opponent will take shots 1 space away from previous shots that were a hit.

CONFIGURATION:
The list of ships available in the game can be configured in the ships.txt file.
The format is as follows: ship_name, ship_length.

BUILD and RUN:
The project is built using a simple makefile. On a linux machine with the clang++ compiler, run the following commands in the same directory as the Makefile:

COMMANDS:
make
./battleship
