#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int exitGame(){
  printf("Now exiting. Thank you for playing!\n");
	return 0;
}

int nRandomizer(int nLower, int nUpper){
	srand(time(0));
	int nRand = (rand() % (nUpper-nLower+1)) + nLower;
	return nRand;
}

int setPlayerPosition(int *currentPTile, int newPTile){
	*currentPTile = newPTile; // Sets the player's current tile
	return 0;
}

int rollDie(int *currentPTile, int *roll){
	int nDie = nRandomizer(0, 6); // Rolls the die
	printf("Enter R to roll the die: ");
	char enter = ' ';
	while (enter != 'R'){
		scanf("%c", &enter); 
	}
	printf("You rolled a %d!\n", nDie);
	*roll = nDie;
	setPlayerPosition(currentPTile, *currentPTile + nDie); // Sets the player's current tile
	return 0;
}

void printTile(char tileType){
	printf("| %-4c", tileType); // Prints the tile with the player's character
	printf("\033[0m"); // Resets the color to default
}

int addSpecialTile(int *p1Tile, int *p2Tile, int originTile, int destinationTile){
	if(*p1Tile == originTile){ // Checks if the player 1 is on the origin tile
		*p1Tile = destinationTile; // Sets the player 1 and "teleports" to the destination tile
	}
	else if(*p2Tile == originTile){ // Checks if the player 2 is on the origin tile
		*p2Tile = destinationTile; // Sets the player 2 and "teleports" to the destination tile
	}
	return 0;
}

int addSabotageTile(int *pTile, int originTile, int destinationTile){
	if(*pTile == originTile){ // Checks if the player is on the origin tile
		*pTile = destinationTile; // Sets the player and "teleports" to the destination tile
	}
	return 0;
}

int tileChecker(int tile1, int tile2){
	if(tile1 == tile2){
		return 1;
	}
	else{
		return 0;
	}
}

int showTile(int p1Tile, int p2Tile, int p1SabotageOrigin, int p1SabotageDest, int p2SabotageOrigin, int p2SabotageDest, int tile){

	int upOriginA = 10, upDestA = 26;
	int upOriginB = 3, upDestB = 38;
	int upOriginC = 50, upDestC = 57;
	int upOriginD = 4, upDestD = 14;
	int upOriginE = 8, upDestE = 20;
	int upOriginF = 28, upDestF = 74;
	
	int downOriginA = 62, downDestA = 52;
	int downOriginB = 30, downDestB = 22;
	int downOriginC = 97, downDestC = 78;
	int downOriginD = 69, downDestD = 42;
	int downOriginE = 88, downDestE = 24;
	int downOriginF = 95, downDestF = 56;

	addSabotageTile(&p2Tile, p1SabotageOrigin, p1SabotageDest);
	addSabotageTile(&p1Tile, p2SabotageOrigin, p2SabotageDest);

	addSpecialTile(&p1Tile, &p2Tile, upOriginA, upDestA);
	addSpecialTile(&p1Tile, &p2Tile, upOriginB, upDestB);
	addSpecialTile(&p1Tile, &p2Tile, upOriginC, upDestC);
	addSpecialTile(&p1Tile, &p2Tile, upOriginD, upDestD);
	addSpecialTile(&p1Tile, &p2Tile, upOriginE, upDestE);
	addSpecialTile(&p1Tile, &p2Tile, upOriginF, upDestF);

	addSpecialTile(&p1Tile, &p2Tile, downOriginA, downDestA);
	addSpecialTile(&p1Tile, &p2Tile, downOriginB, downDestB);
	addSpecialTile(&p1Tile, &p2Tile, downOriginC, downDestC);
	addSpecialTile(&p1Tile, &p2Tile, downOriginD, downDestD);
	addSpecialTile(&p1Tile, &p2Tile, downOriginE, downDestE);
	addSpecialTile(&p1Tile, &p2Tile, downOriginF, downDestF);

	

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
		printf("\033[0;31m");
		printTile('A');
	}
	else if(tile == upOriginB || tile == upDestB){ // Checks if the tile is an origin or destination tile
		printf("\033[0;31m");
		printTile('B');
	}
	else if(tile == upOriginC || tile == upDestC){ // Checks if the tile is an origin or destination tile
		printf("\033[0;31m");
		printTile('C');
	}
	else if(tile == upOriginD || tile == upDestD){ // Checks if the tile is an origin or destination tile
		printf("\033[0;31m");
		printTile('D');
	}
	else if(tile == upOriginE || tile == upDestE){ // Checks if the tile is an origin or destination tile
		printf("\033[0;31m");
		printTile('E');
	}
	else if(tile == upOriginF || tile == upDestF){ // Checks if the tile is an origin or destination tile
		printf("\033[0;31m");
		printTile('F');
	}

	else if(tile == downOriginA || tile == downDestA){
		printf("\033[0;32m");
		printTile('a');
	}
	else if(tile == downOriginB || tile == downDestB){
		printf("\033[0;32m");
		printTile('b');
	}
	else if(tile == downOriginC || tile == downDestC){
		printf("\033[0;32m");
		printTile('c');
	}
	else if(tile == downOriginD || tile == downDestD){
		printf("\033[0;32m");
		printTile('d');
	}
	else if(tile == downOriginE || tile == downDestE){
		printf("\033[0;32m");
		printTile('e');
	}
	else if(tile == downOriginF || tile == downDestF){
		printf("\033[0;32m");
		printTile('f');
	}

	else{
		printf("| %-4d", tile); // Prints the tile with the player's character
	}
	return 0;
}


int showBoard(int p1Tile, int p2Tile, int p1SabotageOrigin, int p1SabotageDest, int p2SabotageOrigin, int p2SabotageDest){
	for (int row=10;row>0;row--){
		if(row%2==0){
			for (int tile=row*10-1;tile>row*10-11;tile--){
				showTile(p1Tile, p2Tile, p1SabotageOrigin, p1SabotageDest, p2SabotageOrigin, p2SabotageDest, tile);
			}
		}
		else{
			for (int tile=row*10-10;tile<row*10;tile++){
				showTile(p1Tile, p2Tile, p1SabotageOrigin, p1SabotageDest, p2SabotageOrigin, p2SabotageDest, tile);
			}
		}
		printf("\n");
	}
	printf("Enter Y to continue: ");
	char enter = 0;
	while (enter != 'Y'){
		scanf("%c", &enter); 
	}
	return 0;
}

int startGame(){
	printf("Starting game...\n");
	
	int p1Tile = 0;
	int p2Tile = 0;

	int nCurrentPlayer = 1;
	int roll = 0;
	int nWinner = 0;

	int p1SabotageOrigin = 0;
	int p1SabotageDest = 0;
	int p2SabotageOrigin = 0;
	int p2SabotageDest = 0;

	do{
		printf("Player 1: You may place a down tile and its link anywhere on the board.\n");
		scanf("%d %d", &p1SabotageOrigin, &p1SabotageDest);
	} while (p1SabotageDest <= 9 || p1SabotageDest >= 100);

	do{
		printf("Player 2: You may place a down tile and its link anywhere on the board.\n");
		scanf("%d %d", &p2SabotageOrigin, &p2SabotageDest);
	} while (p2SabotageDest <= 9 || p2SabotageDest >= 100);

	showBoard(p1Tile, p2Tile, p1SabotageOrigin, p1SabotageDest, p2SabotageOrigin, p2SabotageDest);

	do{	
		printf("\e[1;1H\e[2J"); // Clears the screen
		if(nCurrentPlayer == 1){
			printf("Player 1's turn!\n");
			rollDie(&p1Tile, &roll);
			showBoard(p1Tile, p2Tile, p1SabotageOrigin, p1SabotageDest, p2SabotageOrigin, p2SabotageDest);
			while(roll == 1){
				rollDie(&p1Tile, &roll);
				showBoard(p1Tile, p2Tile, p1SabotageOrigin, p1SabotageDest, p2SabotageOrigin, p2SabotageDest);
			}
			nCurrentPlayer = 2;
		}
		else{
			printf("Player 2's turn!\n");
			rollDie(&p2Tile, &roll);
			showBoard(p1Tile, p2Tile, p1SabotageOrigin, p1SabotageDest, p2SabotageOrigin, p2SabotageDest);
			while(roll == 1){
				rollDie(&p2Tile, &roll);
				showBoard(p1Tile, p2Tile, p1SabotageOrigin, p1SabotageDest, p2SabotageOrigin, p2SabotageDest);
			}
			nCurrentPlayer = 1;
	}
	} while (nWinner == 0);

	return 0;
}

int mainMenu(){
	int userInput;

	printf("This is the main menu!\n");
	printf("[1] Start Game\n");
	printf("[2] Exit\n");
	printf("[3] Show board\n");
	printf(": ");
	scanf("%d", &userInput);
	
	switch(userInput){
		case 1:
			startGame();
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
	return 0;
}

int main(){
	mainMenu();
	return 0;
}
