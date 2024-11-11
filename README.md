# custom_backgammon

**Implement custom backgammon in C, which includes the ability to customize the board size, customize single or double matches, and customize the number of winning pieces**

- ### Source file composition

	> It contains a `test.c` file, a `game.c`file, and a `game.h` header file.
	>
	> `test.c`:
	> Contains the main functions, the menu interface, and the core framework of the game.
	>
	> `game.c`:
	> The implementation of the main body of the game, including the judgment process, the detection process, and the initialization and printing of the chessboard.
	>
	> `game.h`:
	> Includes header file references, function declarations, **board size definitions, and number of winning pieces.**

- ### How to customize

  > - ###### Modify the board size
  >
  >   Modify the rows and columns corresponding to ROW and COL in the `game.h` file
  >
  > - ###### Modify the number of winning pieces
  >
  >   The amount after modifying the CHESS_NUM in the `game.h` file
  >
  > - ###### Modify the number of players
  >
  >   After running the game in `2. setting` to set
  
  