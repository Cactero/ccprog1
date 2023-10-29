#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
	exitGame() - A function that prints a message to the console indicating that the game is exiting.
 */ 
void exitGame(){
	printf("Now exiting. Thank you for playing!\n");
}

/*
	nRandomizer() - generates a random integer within a given range

	This function takes in two integer parameters, nLower and nUpper, and returns a random integer within the range [nLower, nUpper].
 
	@param: nLower - the lower bound of the range (inclusive)
	@param: nUpper - the upper bound of the range (inclusive)

	@return: An integer value within the range [nLower, nUpper]
 */
int nRandomizer(int nLower, int nUpper){
	int nRand = (rand() % (nUpper-nLower+1)) + nLower;
	return nRand;
}

/*
	Sets the player's current tile to the new tile.

	@param: *currentPTile - Pointer to the current tile of the player.
	@param: newPTile - The new tile to set as the player's current tile.
*/
void setPlayerPosition(int *currentPTile, int newPTile){
	*currentPTile = newPTile; // Sets the player's current tile
}

/*
	rollDie() This function rolls a die and sets the player's current tile based on the result of the roll.

	@param: *currentPTile - A pointer to the player's current tile.
	@param *roll - A pointer to the result of the die roll.
 
 	The function generates a random number between 0 and 6 (inclusive) using the nRandomizer function.
 	It then prompts the user to enter 'R' to roll the die.
	Once the user enters 'R', the function prints the result of the roll and sets the player's current tile
 	by calling the setPlayerPosition function with the updated position.
 */
void rollDie(int *currentPTile, int *roll){
	int nDie = nRandomizer(0, 6); // Rolls the die
	printf("Enter R to roll the die: ");
	char enter = ' ';
	while (enter != 'R'){
		scanf("%c", &enter); 
	}
	printf("You rolled a %d!\n", nDie);
	*roll = nDie;
	setPlayerPosition(currentPTile, *currentPTile + nDie); // Sets the player's current tile
}

/*
	printTile()- Prints a tile depending on the tile type

	@param: tileType - type of tile (player, normal, special, sabotage)
*/
void printTile(char tileType){
	printf("| %-4c", tileType); // Prints the tile with the player's character
	printf("\033[0m"); // Resets the color to default
}

/*
	checkSpecialTile() - Adds an up or down tile by checking if the player lands on a tile
	@param: *p1Tile - player 1
	@param: *p2Tile - player 2
	@param: originTile - starting point of the special tile
	@param: destinationTile - ending point of the special tile
*/
void checkSpecialTile(int *p1Tile, int *p2Tile, int originTile, int destinationTile){
	if(*p1Tile == originTile){ // Checks if the player 1 is on the origin tile
		setPlayerPosition(p1Tile, destinationTile); // Sets the player 1 and "teleports" to the destination tile
	}
	else if(*p2Tile == originTile){ // Checks if the player 2 is on the origin tile
		setPlayerPosition(p2Tile, destinationTile); // Sets the player 2 and "teleports" to the destination tile
	}
}

/*
	checkSabotageTile() - Adds a down tile for the opposing player
	@param: *pTile - opposing player
	@param: originTile - starting point of the sabotage tile
	@param: destinationTile - ending point of the sabotage tile
*/
void checkSabotageTile(int *pTile, int originTile, int destinationTile){
	if(*pTile == originTile){ // Checks if the player is on the origin tile
		*pTile = destinationTile; // Sets the player and "teleports" to the destination tile
	}
}

/*
	checkSabotageDuplicate() - Crosschecks if the inputted sabotage tile is currently occupied by a special tile
	@param: sabotageTile - user-inputted sabotage tile
	@param: tile1 - first origin/destination tile
	@param: tile2 - second origin/destination tile
	@param: tile3 - third origin/destination tile
	@param: tile4 - fourth origin/destination tile
	@param: tile5 - fifth origin/destination tile
	@param: tile6 - sixth origin/destinationt ile
*/
int checkSabotageDuplicate(int sabotageTile, int tile1, int tile2, int tile3, int tile4, int tile5, int tile6){
	if(sabotageTile == tile1 || sabotageTile == tile2 || sabotageTile == tile3 || sabotageTile == tile4 || sabotageTile == tile5 || sabotageTile == tile6)
		return 1; // 1 = Duplicates found
	else
		return 0; // 0 = Duplicates not found
}

/*
	showTile() - This function shows the tile based on the given parameters. 
	It takes in the player tiles, sabotage origins and destinations, tile number, and up/down origins and destinations. 
	
	@param p1Tile: integer value representing player 1's tile
	@param p2Tile: integer value representing player 2's tile
	@param p1SabotageOrigin: integer value representing player 1's sabotage origin
	@param p1SabotageDest: integer value representing player 1's sabotage destination
	@param p2SabotageOrigin: integer value representing player 2's sabotage origin
	@param p2SabotageDest: integer value representing player 2's sabotage destination
	@param tile: integer value representing the tile number
	@param upOriginA: integer value representing the origin of the first up tile
	@param upDestA: integer value representing the destination of the first up tile
	@param upOriginB: integer value representing the origin of the second up tile
	@param upDestB: integer value representing the destination of the second up tile
	@param upOriginC: integer value representing the origin of the third up tile
	@param upDestC: integer value representing the destination of the third up tile
	@param downOriginA: integer value representing the origin of the first down tile
	@param downDestA: integer value representing the destination of the first down tile
	@param downOriginB: integer value representing the origin of the second down tile
	@param downDestB: integer value representing the destination of the second down tile
	@param downOriginC: integer value representing the origin of the third down tile
	@param downDestC: integer value representing the destination of the third down tile

*/
void showTile(int p1Tile, int p2Tile, int p1SabotageOrigin, int p1SabotageDest, int p2SabotageOrigin, int p2SabotageDest, int tile,
			int upOriginA, int upDestA, int upOriginB, int upDestB, int upOriginC, int upDestC,
			int downOriginA, int downDestA, int downOriginB, int downDestB, int downOriginC, int downDestC){

	checkSabotageTile(&p2Tile, p1SabotageOrigin, p1SabotageDest);
	checkSabotageTile(&p1Tile, p2SabotageOrigin, p2SabotageDest);

	checkSpecialTile(&p1Tile, &p2Tile, upOriginA, upDestA);
	checkSpecialTile(&p1Tile, &p2Tile, upOriginB, upDestB);
	checkSpecialTile(&p1Tile, &p2Tile, upOriginC, upDestC);
	
	checkSpecialTile(&p1Tile, &p2Tile, downOriginA, downDestA);
	checkSpecialTile(&p1Tile, &p2Tile, downOriginB, downDestB);
	checkSpecialTile(&p1Tile, &p2Tile, downOriginC, downDestC);

	if(p1Tile == tile && p2Tile == tile){ // Checks if both players are on the same tile
		printf("\033[0;33m");
		printTile('@');
	}
	else if(p1Tile == tile){ //	Checks if player 1 is on the tile
		printf("\033[0;34m");
		printTile('$');
	}
	else if(p2Tile == tile){ // Checks if player 2 is on the tile
		printf("\033[0;35m");
		printTile('#');
	}

	else if(tile == p1SabotageOrigin || tile == p1SabotageDest){
		printf("\033[0;34m");
		printTile('y');
	}

	else if(tile == p2SabotageOrigin || tile == p2SabotageDest){
		printf("\033[0;35m");
		printTile('z');
	}

	else if(tile == upOriginA || tile == upDestA){ // Checks if the tile is an origin or destination tile
		printf("\033[0;32m");
		printTile('A');
	}
	else if(tile == upOriginB || tile == upDestB){ // Checks if the tile is an origin or destination tile
		printf("\033[0;32m");
		printTile('B');
	}
	else if(tile == upOriginC || tile == upDestC){ // Checks if the tile is an origin or destination tile
		printf("\033[0;32m");
		printTile('C');
	}

	else if(tile == downOriginA || tile == downDestA){
		printf("\033[0;31m");
		printTile('a');
	}
	else if(tile == downOriginB || tile == downDestB){
		printf("\033[0;31m");
		printTile('b');
	}
	else if(tile == downOriginC || tile == downDestC){
		printf("\033[0;31m");
		printTile('c');
	}

	else{
		printf("| %-4d", tile); // Prints the tile with the player's character
	}
}


/*
	showBoard() - Displays the game board with the current positions of the players and the sabotages, as well as the positions of the ups and downs.
	@param: p1Tile The tile number of player 1.
	@param: p2Tile The tile number of player 2.
	@param: p1SabotageOrigin The origin tile number of player 1's sabotage.
	@param: p1SabotageDest The destination tile number of player 1's sabotage.
 	@param: p2SabotageOrigin The origin tile number of player 2's sabotage.
	@param: p2SabotageDest The destination tile number of player 2's sabotage.
	@param: upOriginA The origin tile number of the first upward ladder.
	@param: upDestA The destination tile number of the first upward ladder.
	@param: upOriginB The origin tile number of the second upward ladder.
	@param: upDestB The destination tile number of the second upward ladder.
	@param: upOriginC The origin tile number of the third upward ladder.
	@param: upDestC The destination tile number of the third upward ladder.
	@param: downOriginA The origin tile number of the first downward ladder.
	@param: downDestA The destination tile number of the first downward ladder.
	@param: downOriginB The origin tile number of the second downward ladder.
	@param: downDestB The destination tile number of the second downward ladder.
	@param: downOriginC The origin tile number of the third downward ladder.
	@param: downDestC The destination tile number of the third downward ladder.
*/
void showBoard(int p1Tile, int p2Tile, int p1SabotageOrigin, int p1SabotageDest, int p2SabotageOrigin, int p2SabotageDest,
			  int upOriginA, int upDestA, int upOriginB, int upDestB, int upOriginC, int upDestC,
			  int downOriginA, int downDestA, int downOriginB, int downDestB, int downOriginC, int downDestC){
	int row;
	int tile;
	for (row=10; row>0; row--){
		if(row%2==0){
			for (tile=row*10-1; tile>row*10-11; tile--){
				showTile(p1Tile, p2Tile, p1SabotageOrigin, p1SabotageDest, p2SabotageOrigin, p2SabotageDest, tile, 
						 upOriginA, upDestA, upOriginB, upDestB, upOriginC, upDestC,
						 downOriginA, downDestA, downOriginB, downDestB, downOriginC, downDestC);
			}
		}
		else{
			for (tile=row*10-10; tile<row*10; tile++){
				showTile(p1Tile, p2Tile, p1SabotageOrigin, p1SabotageDest, p2SabotageOrigin, p2SabotageDest, tile,
						 upOriginA, upDestA, upOriginB, upDestB, upOriginC, upDestC,
						 downOriginA, downDestA, downOriginB, downDestB, downOriginC, downDestC);
			}
		}
		printf("\n");
	}
	printf("Current Player Positions:\n");
	printf("Player 1: %d\n", p1Tile);
	printf("Player 2: %d\n", p2Tile);
	printf("Enter Y to continue: ");
	char enter = 0;
	while (enter != 'Y'){
		scanf("%c", &enter); 
	}
}
/*
	initializeTiles() - Initializes the tiles for the game with the given pair number.
	The function generates four random numbers within the range of the given pair number and the next pair number.
	It then assigns the first two numbers to the upOrigin and upDest pointers, and the last two numbers to the downOrigin and downDest pointers.
	The function ensures that the four numbers are unique and that the up and down tiles do not overlap.

	@param: pair - The pair number for the game.
	@param: *upOrigin - Pointer to the variable that will hold the value of the origin tile for the up pair.
	@param: *upDest - Pointer to the variable that will hold the value of the destination tile for the up pair.
	@param: *downOrigin - Pointer to the variable that will hold the value of the origin tile for the down pair.
	@param: *downDest - Pointer to the variable that will hold the value of the destination tile for the down pair.
 */

void initializeTiles(int pair, int *upOrigin, int *upDest, int *downOrigin, int *downDest){
	do{
		int temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0;
		do{
			temp1 = nRandomizer(pair*10, pair*10+9);
			temp2 = nRandomizer(pair*10, pair*10+9);
			temp3 = nRandomizer((pair+1)*10, (pair+1)*10+9);
			temp4 = nRandomizer((pair+1)*10, (pair+1)*10+9);
		} while (temp1 == temp2 || temp1 == temp3 || temp1 == temp4 || temp2 == temp3 || temp2 == temp4 || temp3 == temp4);
		if(temp1 < temp3){
			*upOrigin = temp1;
			*upDest = temp3;
		}
		else{
			*upDest = temp1;
			*upOrigin = temp3;
		}

		if(temp3 < temp4){
			*downOrigin = temp4;
			*downDest = temp2;
		}
		else{
			*downOrigin = temp2;
			*downDest = temp4;
		}
	} while(*upOrigin == *downOrigin || *upDest == *downDest || *upOrigin == *downDest || *upDest == *downOrigin);
}

/*
	startGame() - Starts the game by initializing the tiles and the players' positions.
*/
void startGame(){
	printf("Starting game...\n");
	
	int p1Tile = 0;
	int p2Tile = 0;

	int nCurrentPlayer = 1;
	int roll = 0;
	int previousRoll1 = 0;
	int previousRoll2 = 0;
	int nWinner = 0;

	int p1SabotageOrigin, p1SabotageDest;
	int p2SabotageOrigin, p2SabotageDest;

	int upOriginA, upDestA;
	int upOriginB, upDestB;
	int upOriginC, upDestC;

	int downOriginA, downDestA;
	int downOriginB, downDestB;
	int downOriginC, downDestC;

	int pair;

	for (pair = 0; pair<3; pair++){
		switch(pair){
			case 0:
				initializeTiles(pair+1, &upOriginA, &upDestA, &downOriginA, &downDestA);
				break;
			case 1:
				initializeTiles(pair+3, &upOriginB, &upDestB, &downOriginB, &downDestB);
				break;
			case 2:
				initializeTiles(pair+5, &upOriginC, &upDestC, &downOriginC, &downDestC);
				break;
		}
	}

	printf("Up tiles:\n");
	printf("A: %d %d\n", upOriginA, upDestA);
	printf("B: %d %d\n", upOriginB, upDestB);
	printf("C: %d %d\n", upOriginC, upDestC);

	printf("Down tiles:\n");
	printf("A: %d %d\n", downOriginA, downDestA);
	printf("B: %d %d\n", downOriginB, downDestB);
	printf("C: %d %d\n", downOriginC, downDestC);

	do{
		printf("Player 1: You may place a down tile and its link on the board.\n");
		scanf("%d %d", &p1SabotageOrigin, &p1SabotageDest);
		if (checkSabotageDuplicate(p1SabotageOrigin, upOriginA, upOriginB, upOriginC, downOriginA, downOriginB, downOriginC) ||
			checkSabotageDuplicate(p1SabotageDest, upDestA, upDestB, upDestC, downDestA, downDestB, downDestC))
				printf("You may not place a down tile on this tile as it is occupied by a special tile. Try again! \n");
		else if (p1SabotageOrigin <= 9 || p1SabotageDest <= 9)
			printf("You may not place a down tile on the first row and below 0. Try again! \n");
		else if (p1SabotageOrigin >= 99 || p1SabotageDest >= 99)
			printf("You may not place a down tile on the 99th tile and above. Try again! \n");
		else if (p1SabotageOrigin == p1SabotageDest)
			printf("You may not place a down tile in the same tile. Try again! \n");
	} while (p1SabotageOrigin <= 9 || p1SabotageOrigin >= 99 || p1SabotageDest <= 9 || p1SabotageDest >= 99 || p1SabotageOrigin == p1SabotageDest || 
			checkSabotageDuplicate(p1SabotageOrigin, upOriginA, upOriginB, upOriginC, downOriginA, downOriginB, downOriginC) ||
			checkSabotageDuplicate(p1SabotageDest, upDestA, upDestB, upDestC, downDestA, downDestB, downDestC));



	do{
		printf("Player 2: You may place a down tile and its link on the board.\n");
		scanf("%d %d", &p2SabotageOrigin, &p2SabotageDest);
		if (checkSabotageDuplicate(p2SabotageOrigin, upOriginA, upOriginB, upOriginC, downOriginA, downOriginB, downOriginC) ||
			checkSabotageDuplicate(p2SabotageDest, upDestA, upDestB, upDestC, downDestA, downDestB, downDestC))
				printf("You may not place a down tile on this tile as it is occupied by a special tile. Try again! \n");
		else if (p2SabotageOrigin <= 9 || p2SabotageDest <= 9)
			printf("You may not place a down tile on the first row and below 0. Try again! \n");
		else if (p2SabotageOrigin >= 99 || p2SabotageDest >= 99)
			printf("You may not place a down tile on the 99th tile and above. Try again! \n"); 
		else if (p2SabotageOrigin == p1SabotageOrigin || p2SabotageOrigin == p1SabotageDest || p2SabotageDest == p1SabotageOrigin || p2SabotageDest == p1SabotageDest)
			printf("You may not place a down tile in the same tile. Try again! \n");
	} while (p2SabotageOrigin <= 9 || p2SabotageOrigin >= 99 || p2SabotageDest <= 9 || p2SabotageDest >= 100 || p2SabotageOrigin == p1SabotageOrigin || 
			p2SabotageOrigin == p1SabotageDest || p2SabotageDest == p1SabotageOrigin || p2SabotageDest == p1SabotageDest ||
			checkSabotageDuplicate(p2SabotageOrigin, upOriginA, upOriginB, upOriginC, downOriginA, downOriginB, downOriginC) ||
			checkSabotageDuplicate(p2SabotageDest, upDestA, upDestB, upDestC, downDestA, downDestB, downDestC));

	showBoard(p1Tile, p2Tile, p1SabotageOrigin, p1SabotageDest, p2SabotageOrigin, p2SabotageDest, 
			  upOriginA, upDestA, upOriginB, upDestB, upOriginC, upDestC,
			  downOriginA, downDestA, downOriginB, downDestB, downOriginC, downDestC);

	do{	
		printf("\e[1;1H\e[2J"); // Clears the screen
		if(nCurrentPlayer == 1){
			printf("Player 1's turn!\n");
			rollDie(&p1Tile, &roll);
			showBoard(p1Tile, p2Tile, p1SabotageOrigin, p1SabotageDest, p2SabotageOrigin, p2SabotageDest, 
					  upOriginA, upDestA, upOriginB, upDestB, upOriginC, upDestC,
					  downOriginA, downDestA, downOriginB, downDestB, downOriginC, downDestC);
			


			if(roll == 1 && previousRoll1 == 1){
				rollDie(&p1Tile, &roll);
				showBoard(p1Tile, p2Tile, p1SabotageOrigin, p1SabotageDest, p2SabotageOrigin, p2SabotageDest, 
						  upOriginA, upDestA, upOriginB, upDestB, upOriginC, upDestC,
						  downOriginA, downDestA, downOriginB, downDestB, downOriginC, downDestC);
			}

			
			nCurrentPlayer = 2;
			previousRoll1 = roll;
		}
		else{
			printf("Player 2's turn!\n");
			rollDie(&p2Tile, &roll);

			showBoard(p1Tile, p2Tile, p1SabotageOrigin, p1SabotageDest, p2SabotageOrigin, p2SabotageDest, 
					  upOriginA, upDestA, upOriginB, upDestB, upOriginC, upDestC,
					  downOriginA, downDestA, downOriginB, downDestB, downOriginC, downDestC);
			
			if(roll == 1 && previousRoll2 == 1){
				rollDie(&p2Tile, &roll);
				showBoard(p1Tile, p2Tile, p1SabotageOrigin, p1SabotageDest, p2SabotageOrigin, p2SabotageDest, 
						  upOriginA, upDestA, upOriginB, upDestB, upOriginC, upDestC,
						  downOriginA, downDestA, downOriginB, downDestB, downOriginC, downDestC);
			}

			nCurrentPlayer = 1;
			previousRoll2 = roll;
		}
		if(p1Tile >= 99){
			nWinner = 1;
		}
		else if(p2Tile >= 99){
			nWinner = 2;
		}
	} while (nWinner == 0);

	printf("Player %d wins!\n", nWinner);

}

/*
	mainMenu() - Displays a main menu showing options to start game, exit game, and show the board.
*/
void mainMenu(){
	int userInput;

	printf("This is the main menu!\n");
	printf("[1] Start Game\n");
	printf("[2] Exit\n");
	printf("[3] Show board\n");
	printf(": ");
	scanf("%d", &userInput);
	
	do{
	switch(userInput){
		case 1:
			startGame();
			printf("Do you want to play again?\n");
			printf("[1] Play again\n");
			printf("[2] Back to main menu\n");
			printf("[3] Exit\n");
			scanf("%d", &userInput);
			break;
		case 2:
			exitGame();
			break;
		case 3:
			//showBoard(*p1Tile, *p2Tile);
			break;
		case 4:
			nRandomizer(0, 10);
			break;
	}
	} while(userInput != 2);
}

int main(){
	srand(time(0));

	mainMenu();
	return 0;
}
