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
	showInstructions() - Shows the instructions and mecehanics
*/
void showInstructions(){
	printf(">>=================================================<<\n");
	printf("|| _____         _               _   _             ||\n");
	printf("|||     |___ ___| |_ ___ _ _ ___| |_|_|___ ___ ___ ||\n");
	printf("|||-   -|   |_ -|  _|  _| | |  _|  _| | . |   |_ -|||\n");
	printf("|||_____|_|_|___|_| |_| |___|___|_| |_|___|_|_|___|||\n");
	printf(">>=================================================<<\n");
	printf("\n");
	printf("""Ups and Downs"" is a turn-based two-player board game.\n");
	printf("The goal of eeach player is to reach the end point of the board.\n");
	printf("The first one to reach the end point wins the game.\n");
	printf("\n");
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
	char enter = ' ';
	while (enter != 'R' && enter != 'r'){
		scanf("%c", &enter); 
	}
	printf("\n");
	printf(">>=====================<<\n");
	printf("||   You rolled a %d!   ||\n", nDie);
	printf(">>=====================<<\n");
	printf("\n");
	*roll = nDie;
	setPlayerPosition(currentPTile, *currentPTile + nDie); // Sets the player's current tile
}

/*
	printTile()- Prints a tile depending on the tile type

	@param: tileType - type of tile (player, normal, special, sabotage)
*/
void printTile(char tileType){
	printf(" %c ", tileType); // Prints the tile with the player's character
	printf("\033[0m"); // Resets the color to default
}

/*
	checkSpecialTile() - Adds an up or down tile by checking if the player lands on a tile
	@param: *p1Tile - player 1
	@param: *p2Tile - player 2
	@param: originTile - starting point of the special tile
	@param: destinationTile - ending point of the special tile

	@return: 1 if the player is on the origin tile, 0 if not
*/
int checkSpecialTile(int *p1Tile, int *p2Tile, int originTile, int destinationTile){
	if(*p1Tile == originTile){ // Checks if the player 1 is on the origin tile
		setPlayerPosition(p1Tile, destinationTile); // Sets the player 1 and "teleports" to the destination tile
		return 1;
	}
	else if(*p2Tile == originTile){ // Checks if the player 2 is on the origin tile
		setPlayerPosition(p2Tile, destinationTile); // Sets the player 2 and "teleports" to the destination tile
		return 1;
	}
	return 0;
}

/*
	checkSabotageTile() - Adds a down tile for the opposing player
	@param: *pTile - opposing player
	@param: originTile - starting point of the sabotage tile
	@param: destinationTile - ending point of the sabotage tile

	@return: 1 if the player is on the origin tile, 0 if not
*/
int checkSabotageTile(int *pTile, int originTile, int destinationTile){
	if(*pTile == originTile){ // Checks if the player is on the origin tile
		setPlayerPosition(pTile, destinationTile); // Sets the player and "teleports" to the destination tile
		return 1;
	}
	else
		return 0;
}

/*
	checkDuplicates() - Crosschecks if the inputted tile is currently occupied by a special tile
	@param: tile - user-inputted tile
	@param: tile1 - first origin/destination tile
	@param: tile2 - second origin/destination tile
	@param: tile3 - third origin/destination tile
	@param: tile4 - fourth origin/destination tile
	@param: tile5 - fifth origin/destination tile
	@param: tile6 - sixth origin/destinationt ile
*/
int checkDuplicates(int tile, int tile1, int tile2, int tile3, int tile4, int tile5, int tile6){
	if(tile == tile1 || tile == tile2 || tile == tile3 || tile == tile4 || tile == tile5 || tile == tile6)
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
		printf(" %c ", 254); // Prints the tile with the player's character
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

	if(checkSabotageTile(&p2Tile, p1SabotageOrigin, p1SabotageDest) == 1)
		printf("Player 2 has been sabotaged!\n");

	
	if(checkSabotageTile(&p1Tile, p2SabotageOrigin, p2SabotageDest) == 1)
		printf("Player 1 has been sabotaged!\n");

	if(checkSpecialTile(&p1Tile, &p2Tile, upOriginA, upDestA) == 1 || checkSpecialTile(&p1Tile, &p2Tile, upOriginB, upDestB) == 1 || checkSpecialTile(&p1Tile, &p2Tile, upOriginC, upDestC) == 1)
		printf("You have climbed up an up tile!\n");

	if(checkSpecialTile(&p1Tile, &p2Tile, downOriginA, downDestA) == 1 || checkSpecialTile(&p1Tile, &p2Tile, downOriginB, downDestB) == 1 || checkSpecialTile(&p1Tile, &p2Tile, downOriginC, downDestC) == 1){
		printf("You have climbed down a down tile!\n");
	}
	printf(">>==============================<<\n");
	for (row=10; row>0; row--){
		printf("||");
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
		printf("||");
		printf("\n");
	}
	printf(">>==============================<<\n");

}
/*
  initializeTiles() - Initializes the tiles for the game.
  
  This function generates random values for the tiles and assigns them to the corresponding variables.
  The generated values must meet certain conditions to ensure the game is playable.
  
  @param: upOriginA - Pointer to the variable storing the origin value of the first upward tile.
  @param: upDestA - Pointer to the variable storing the destination value of the first upward tile.
  @param: downOriginA - Pointer to the variable storing the origin value of the first downward tile.
  @param: downDestA - Pointer to the variable storing the destination value of the first downward tile.
  @param: upOriginB - Pointer to the variable storing the origin value of the second upward tile.
  @param: upDestB - Pointer to the variable storing the destination value of the second upward tile.
  @param: downOriginB - Pointer to the variable storing the origin value of the second downward tile.
  @param: downDestB - Pointer to the variable storing the destination value of the second downward tile.
  @param: upOriginC - Pointer to the variable storing the origin value of the third upward tile.
  @param: upDestC - Pointer to the variable storing the destination value of the third upward tile.
  @param: downOriginC - Pointer to the variable storing the origin value of the third downward tile.
  @param: downDestC - Pointer to the variable storing the destination value of the third downward tile.
 */

void initializeTiles(int *upOriginA, int *upDestA, int *downOriginA, int *downDestA, 
					int *upOriginB, int *upDestB, int *downOriginB, int *downDestB, 
					int *upOriginC, int *upDestC, int *downOriginC, int *downDestC){
	int temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8, temp9, temp10, temp11, temp12;
	int row;
	int upTileRowCount, downTileRowCount;
	int lowRange, highRange;
	int regenerate;
	do{
		regenerate = 0;

		temp1 = nRandomizer(10,98);
		temp2 = nRandomizer(10,98);
		temp3 = nRandomizer(10,98);
		temp4 = nRandomizer(10,98);
		temp5 = nRandomizer(10,98);
		temp6 = nRandomizer(10,98);
		temp7 = nRandomizer(10,98);
		temp8 = nRandomizer(10,98);
		temp9 = nRandomizer(10,98);
		temp10 = nRandomizer(10,98);
		temp11 = nRandomizer(10,98);
		temp12 = nRandomizer(10,98);
		
		
		for(row = 1; row<10; row++){
			if(regenerate == 0){
				lowRange = row*10;
				highRange = row*10+9;
				upTileRowCount = 0;
				downTileRowCount = 0;
				if ((temp1 >= lowRange && temp1 <= highRange)) {
					upTileRowCount++;
				}
				if ((temp2 >= lowRange && temp2 <= highRange)) {
					upTileRowCount++;
				}
				if ((temp3 >= lowRange && temp3 <= highRange)) {
					downTileRowCount++;
				}
				if ((temp4 >= lowRange && temp4 <= highRange)) {
					downTileRowCount++;
				}
				if ((temp5 >= lowRange && temp5 <= highRange)) {
					upTileRowCount++;
				}
				if ((temp6 >= lowRange && temp6 <= highRange)) {
					upTileRowCount++;
				}
				if ((temp7 >= lowRange && temp7 <= highRange)) {
					downTileRowCount++;
				}
				if ((temp8 >= lowRange && temp8 <= highRange)) {
					downTileRowCount++;
				}
				if ((temp9 >= lowRange && temp9 <= highRange)) {
					upTileRowCount++;
				}
				if ((temp10 >= lowRange && temp10 <= highRange)) {
					upTileRowCount++;
				}
				if ((temp11 >= lowRange && temp11 <= highRange)) {
					downTileRowCount++;
				}
				if ((temp12 >= lowRange && temp12 <= highRange)) {
					downTileRowCount++;
				}
				if(upTileRowCount >= 2 || downTileRowCount >= 2 || upTileRowCount + downTileRowCount > 2){
					regenerate = 1;
				}
			}
		}
		
	} while(temp1 == temp2 || temp1 == temp3 || temp1 == temp4 || temp1 == temp5 || temp1 == temp6 || temp1 == temp7 || temp1 == temp8 || temp1 == temp9 || temp1 == temp10 || temp1 == temp11 || temp1 == temp12 ||
			temp2 == temp3 || temp2 == temp4 || temp2 == temp5 || temp2 == temp6 || temp2 == temp7 || temp2 == temp8 || temp2 == temp9 || temp2 == temp10 || temp2 == temp11 || temp2 == temp12 ||
			temp3 == temp4 || temp3 == temp5 || temp3 == temp6 || temp3 == temp7 || temp3 == temp8 || temp3 == temp9 || temp3 == temp10 || temp3 == temp11 || temp3 == temp12 ||
			temp4 == temp5 || temp4 == temp6 || temp4 == temp7 || temp4 == temp8 || temp4 == temp9 || temp4 == temp10 || temp4 == temp11 || temp4 == temp12 ||
			temp5 == temp6 || temp5 == temp7 || temp5 == temp8 || temp5 == temp9 || temp5 == temp10 || temp5 == temp11 || temp5 == temp12 ||
			temp6 == temp7 || temp6 == temp8 || temp6 == temp9 || temp6 == temp10 || temp6 == temp11 || temp6 == temp12 ||
			temp7 == temp8 || temp7 == temp9 || temp7 == temp10 || temp7 == temp11 || temp7 == temp12 ||
			temp8 == temp9 || temp8 == temp10 || temp8 == temp11 || temp8 == temp12 ||
			temp9 == temp10 || temp9 == temp11 || temp9 == temp12 ||
			temp10 == temp11 || temp10 == temp12 ||
			temp11 == temp12 || regenerate);
			
	if(temp1 < temp2){
		*upOriginA = temp1;
		*upDestA = temp2;
	}
	else{
		*upDestA = temp1;
		*upOriginA = temp2;
	}

	if(temp3 < temp4){
		*downOriginA = temp4;
		*downDestA = temp3;
	}
	else{
		*downOriginA = temp3;
		*downDestA = temp4;
	}

	if(temp5 < temp6){
		*upOriginB = temp5;
		*upDestB = temp6;
	}
	else{
		*upDestB = temp5;
		*upOriginB = temp6;
	}

	if(temp7 < temp8){
		*downOriginB = temp8;
		*downDestB = temp7;
	}
	else{
		*downOriginB = temp7;
		*downDestB = temp8;
	}

	if(temp9 < temp10){
		*upOriginC = temp9;
		*upDestC = temp10;
	}
	else{
		*upDestC = temp9;
		*upOriginC = temp10;
	}

	if(temp11 < temp12){
		*downOriginC = temp12;
		*downDestC = temp11;
	}
	else{
		*downOriginC = temp11;
		*downDestC = temp12;
	}
}
/*
	startGame() - Starts the game by initializing the tiles and the players' positions.
*/
void startGame(){

	printf(">>=====================================<<\n");
	printf("|| _____ _           _   _             ||\n");
	printf("|||   __| |_ ___ ___| |_|_|___ ___     ||\n");
	printf("|||__   |  _| .'|  _|  _| |   | . |_ _ ||\n");
	printf("|||_____|_| |__,|_| |_| |_|_|_|_  |_|_|||\n");
	printf("||                            |___|    ||\n");
	printf(">>=====================================<<\n");

	int p1Tile = 0;
	int p2Tile = 0;

	int nCurrentPlayer = 1;
	int roll = 0;
	int previousRoll1 = 0;
	int previousRoll2 = 0;
	int nWinner = 0;

	int prevP1 = 0;
	int prevP2 = 0;

	int p1SabotageOrigin, p1SabotageDest;
	int p2SabotageOrigin, p2SabotageDest;

	int upOriginA, upDestA;
	int upOriginB, upDestB;
	int upOriginC, upDestC;

	int downOriginA, downDestA;
	int downOriginB, downDestB;
	int downOriginC, downDestC;

	initializeTiles(&upOriginA, &upDestA, &downOriginA, &downDestA, &upOriginB, &upDestB, &downOriginB, &downDestB, &upOriginC, &upDestC, &downOriginC, &downDestC);

	printf("\n");
	printf("     .		A: %d %d      ;;;;;\n", upOriginA, upDestA);
 	printf("   .:;:.	B: %d %d      ;;;;;\n", upOriginB, upOriginC);
 	printf(" .:;;;;;:.	C: %d %d      ;;;;;\n", upOriginC, upDestC);
	printf("   ;;;;;                      ;;;;;\n");
	printf("   ;;;;;	a: %d %d    ..;;;;;..\n", downOriginA, downDestA);
	printf("   ;;;;;	b: %d %d     ':::::'\n", downOriginB, downOriginB);
	printf("   ;;;;;	c: %d %d       ':`\n", downOriginC, downOriginC);
	printf("\n");
	do{
			printf(">>======================================<<\n");
			printf("||  ___                                 ||\n");
			printf("|| |_  |    Player 1:                   ||\n");
			printf("||  _| |_   You may place a down tile   ||\n");
			printf("|| |_____|  and its link on the board.  ||\n");
			printf("||          Ex: 85 42                   ||\n");
			printf(">>======================================<<\n");
			printf(": ");
		scanf("%d %d", &p1SabotageOrigin, &p1SabotageDest);
		if (checkDuplicates(p1SabotageOrigin, upOriginA, upOriginB, upOriginC, downOriginA, downOriginB, downOriginC) ||
			checkDuplicates(p1SabotageDest, upDestA, upDestB, upDestC, downDestA, downDestB, downDestC))
				printf("You may not place a down tile on this tile as it is occupied by a special tile. Try again! \n");
		else if (p1SabotageOrigin <= 9 || p1SabotageDest <= 9)
			printf("You may not place a down tile on the first row and below 0. Try again! \n");
		else if (p1SabotageOrigin >= 99 || p1SabotageDest >= 99)
			printf("You may not place a down tile on the 99th tile and above. Try again! \n");
		else if (p1SabotageOrigin == p1SabotageDest)
			printf("You may not place a down tile in the same tile. Try again! \n");
		else if(p1SabotageDest > p1SabotageOrigin)
			printf("You may not place a down tile with a destination tile that is higher than the origin tile. Try again! \n");
	} while (p1SabotageOrigin <= 9 || p1SabotageOrigin >= 99 || p1SabotageDest <= 9 || p1SabotageDest >= 99 || p1SabotageOrigin == p1SabotageDest || 
			checkDuplicates(p1SabotageOrigin, upOriginA, upOriginB, upOriginC, downOriginA, downOriginB, downOriginC) ||
			checkDuplicates(p1SabotageDest, upDestA, upDestB, upDestC, downDestA, downDestB, downDestC) || p1SabotageDest > p1SabotageOrigin);



	do{
		printf(">>======================================<<\n");
		printf("||  ___                               ||\n");
		printf("|| |_  |  Player 2:                   ||\n");
		printf("|| |  _|  You may place a down tile   ||\n");
		printf("|| |___|  and its link on the board.  ||\n");
		printf("||        Ex: 85 42                   ||\n");
		printf(">>======================================<<\n");
		printf(": ");
		scanf("%d %d", &p2SabotageOrigin, &p2SabotageDest);
		
		if (checkDuplicates(p2SabotageOrigin, upOriginA, upOriginB, upOriginC, downOriginA, downOriginB, downOriginC) ||
			checkDuplicates(p2SabotageDest, upDestA, upDestB, upDestC, downDestA, downDestB, downDestC))
				printf("You may not place a down tile on this tile as it is occupied by a special tile. Try again! \n");
		else if (p2SabotageOrigin <= 9 || p2SabotageDest <= 9)
			printf("You may not place a down tile on the first row and below 0. Try again! \n");
		else if (p2SabotageOrigin >= 99 || p2SabotageDest >= 99)
			printf("You may not place a down tile on the 99th tile and above. Try again! \n"); 
		else if (p2SabotageOrigin == p1SabotageOrigin || p2SabotageOrigin == p1SabotageDest || p2SabotageDest == p1SabotageOrigin || p2SabotageDest == p1SabotageDest)
			printf("You may not place a down tile in the same tile or the same tile as player 1. Try again! \n");
		else if(p2SabotageDest > p2SabotageOrigin)
			printf("You may not place a down tile with a destination tile that is higher than the origin tile. Try again! \n");
	} while (p2SabotageOrigin <= 9 || p2SabotageOrigin >= 99 || p2SabotageDest <= 9 || p2SabotageDest >= 100 || p2SabotageOrigin == p1SabotageOrigin || 
			p2SabotageOrigin == p1SabotageDest || p2SabotageDest == p1SabotageOrigin || p2SabotageDest == p1SabotageDest ||
			checkDuplicates(p2SabotageOrigin, upOriginA, upOriginB, upOriginC, downOriginA, downOriginB, downOriginC) ||
			checkDuplicates(p2SabotageDest, upDestA, upDestB, upDestC, downDestA, downDestB, downDestC) || p2SabotageDest > p2SabotageOrigin);

	showBoard(p1Tile, p2Tile, p1SabotageOrigin, p1SabotageDest, p2SabotageOrigin, p2SabotageDest, 
			  upOriginA, upDestA, upOriginB, upDestB, upOriginC, upDestC,
			  downOriginA, downDestA, downOriginB, downDestB, downOriginC, downDestC);

	do{	
		printf("\e[1;1H\e[2J"); // Clears the screen
		if(nCurrentPlayer == 1){
			prevP1 = p1Tile;
			printf(">>======================================<<\n");
			printf("||  ___                                  ||\n");
			printf("|| |_  |    Player 1: Tile %d             ||\n", p1Tile);
			printf("||  _| |_   Enter R to roll the die!     ||\n");
			printf("|| |_____|                               ||\n");
			printf(">>======================================<<\n");
			printf(": ");
			rollDie(&p1Tile, &roll);
			showBoard(p1Tile, p2Tile, p1SabotageOrigin, p1SabotageDest, p2SabotageOrigin, p2SabotageDest, 
					  upOriginA, upDestA, upOriginB, upDestB, upOriginC, upDestC,
					  downOriginA, downDestA, downOriginB, downDestB, downOriginC, downDestC);
				printf("\n");
				printf(">>===========================<<\n");
				printf("||   Moving from %d to %d      ||\n", prevP1, p1Tile);
				printf(">>===========================<<\n");
				printf("\n");
			
						
				printf("Enter c to continue: ");
				char enter = 0;
				while (enter != 'C' && enter != 'c'){
					scanf("%c", &enter); 
				}
				
			if(roll == 1 && previousRoll1 == 1){
				prevP1 = p1Tile;
				rollDie(&p1Tile, &roll);
				showBoard(p1Tile, p2Tile, p1SabotageOrigin, p1SabotageDest, p2SabotageOrigin, p2SabotageDest, 
						  upOriginA, upDestA, upOriginB, upDestB, upOriginC, upDestC,
						  downOriginA, downDestA, downOriginB, downDestB, downOriginC, downDestC);

				printf(">>=========================<<\n");
				printf("||   Moving from %d to %d    ||\n", prevP1, p1Tile);
				printf(">>=========================<<\n");
				printf("\n");

							
				printf("Enter c to continue: ");
				char enter = 0;
				while (enter != 'C' && enter != 'c'){
					scanf("%c", &enter); 
				}
			}

			
			nCurrentPlayer = 2;
			previousRoll1 = roll;
		}
		else{
			prevP2 = p2Tile;
			printf(">>======================================<<\n");
			printf("||  ___                                 ||\n");
			printf("|| |_  |  Player 2: Tile %d              ||\n", p2Tile);
			printf("|| |  _|  Enter R to roll the die!      ||\n");
			printf("|| |___|                                ||\n");
			printf(">>======================================<<\n");
			printf(": ");
			rollDie(&p2Tile, &roll);
			
			showBoard(p1Tile, p2Tile, p1SabotageOrigin, p1SabotageDest, p2SabotageOrigin, p2SabotageDest, 
					  upOriginA, upDestA, upOriginB, upDestB, upOriginC, upDestC,
					  downOriginA, downDestA, downOriginB, downDestB, downOriginC, downDestC);
			printf("\n");
			printf(">>=========================<<\n");
			printf("||   Moving from %d to %d  ||\n", prevP2, p1Tile);
			printf(">>=========================<<\n");
			printf("\n");

					
			printf("Enter c to continue: ");
			char enter = 0;
			while (enter != 'C' && enter != 'c'){
				scanf("%c", &enter); 
			}
			
			if(roll == 1 && previousRoll2 == 1){
				prevP2 = p2Tile;
				rollDie(&p2Tile, &roll);
				showBoard(p1Tile, p2Tile, p1SabotageOrigin, p1SabotageDest, p2SabotageOrigin, p2SabotageDest, 
						  upOriginA, upDestA, upOriginB, upDestB, upOriginC, upDestC,
						  downOriginA, downDestA, downOriginB, downDestB, downOriginC, downDestC);
				printf("\n");
				printf(">>=========================<<\n");
				printf("||   Moving from %d to %d  ||\n", prevP1, p1Tile);
				printf(">>=========================<<\n");
				printf("\n");
							
				printf("Enter c to continue: ");
				char enter = 0;
				while (enter != 'C' && enter != 'c'){
					scanf("%c", &enter); 
				}
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

int main(){
	int userInput;
	srand(time(0));
		do{
			printf(">>============================================================<<\n");
			printf("||                                                         __ ||\n");
			printf("|| _____                      _    ____                   |  |||\n");
			printf("|||  |  |___ ___    ___ ___ _| |  |    \\ ___ _ _ _ ___ ___|  |||\n");
			printf("|||  |  | . |_ -|  | .'|   | . |  |  |  | . | | | |   |_ -|__|||\n");
			printf("|||_____|  _|___|  |__,|_|_|___|  |____/|___|_____|_|_|___|__|||\n");
			printf("||      |_|                                                   ||\n");
			printf(">>============================================================<<\n");	
			printf("                 Welcome to Ups and Downs!\n");
			printf("                  Please select an option:\n");
			printf(">>============================================================<<\n");

			printf("                    [1] Start Game\n");
			printf("                    [2] Instructions\n");
			printf("                    [3] Exit\n");
			printf("                    : ");
			scanf("%d", &userInput);
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
					showInstructions();
					printf("Start game or back to the main menu?\n");
					printf("[1] Yes\n");
					printf("[2] No (Exit)\n");
					scanf("%d", &userInput);
					break;
				case 3:
					exitGame();
					break;

		}
	} while(userInput != 3);

	return 0;
}
