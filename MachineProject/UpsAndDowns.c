#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int exitGame(){
	printf("Now exiting. Thank you for playing!\n");
	return 0;
}

int nRandomizer(int nLower, int nUpper){
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

int showTile(int p1Tile, int p2Tile, int p1SabotageOrigin, int p1SabotageDest, int p2SabotageOrigin, int p2SabotageDest, int tile,
			int upOriginA, int upDestA, int upOriginB, int upDestB, int upOriginC, int upDestC, int upOriginD, int upDestD, int upOriginE, int upDestE, int upOriginF, int upDestF,
			int downOriginA, int downDestA, int downOriginB, int downDestB, int downOriginC, int downDestC, int downOriginD, int downDestD, int downOriginE, int downDestE, int downOriginF, int downDestF){


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
	else if(tile == upOriginD || tile == upDestD){ // Checks if the tile is an origin or destination tile
		printf("\033[0;32m");
		printTile('D');
	}
	else if(tile == upOriginE || tile == upDestE){ // Checks if the tile is an origin or destination tile
		printf("\033[0;32m");
		printTile('E');
	}
	else if(tile == upOriginF || tile == upDestF){ // Checks if the tile is an origin or destination tile
		printf("\033[0;32m");
		printTile('F');
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
	else if(tile == downOriginD || tile == downDestD){
		printf("\033[0;31m");
		printTile('d');
	}
	else if(tile == downOriginE || tile == downDestE){
		printf("\033[0;31m");
		printTile('e');
	}
	else if(tile == downOriginF || tile == downDestF){
		printf("\033[0;31m");
		printTile('f');
	}

	else{
		printf("| %-4d", tile); // Prints the tile with the player's character
	}
	return 0;
}


int showBoard(int p1Tile, int p2Tile, int p1SabotageOrigin, int p1SabotageDest, int p2SabotageOrigin, int p2SabotageDest,
			  int upOriginA, int upDestA, int upOriginB, int upDestB, int upOriginC, int upDestC, int upOriginD, int upDestD, int upOriginE, int upDestE, int upOriginF, int upDestF,
			  int downOriginA, int downDestA, int downOriginB, int downDestB, int downOriginC, int downDestC, int downOriginD, int downDestD, int downOriginE, int downDestE, int downOriginF, int downDestF){
	for (int row=10;row>0;row--){
		if(row%2==0){
			for (int tile=row*10-1;tile>row*10-11;tile--){
				showTile(p1Tile, p2Tile, p1SabotageOrigin, p1SabotageDest, p2SabotageOrigin, p2SabotageDest, tile, 
						 upOriginA, upDestA, upOriginB, upDestB, upOriginC, upDestC, upOriginD, upDestD, upOriginE, upDestE, upOriginF, upDestF,
						 downOriginA, downDestA, downOriginB, downDestB, downOriginC, downDestC, downOriginD, downDestD, downOriginE, downDestE, downOriginF, downDestF);
			}
		}
		else{
			for (int tile=row*10-10;tile<row*10;tile++){
				showTile(p1Tile, p2Tile, p1SabotageOrigin, p1SabotageDest, p2SabotageOrigin, p2SabotageDest, tile,
						 upOriginA, upDestA, upOriginB, upDestB, upOriginC, upDestC, upOriginD, upDestD, upOriginE, upDestE, upOriginF, upDestF,
						 downOriginA, downDestA, downOriginB, downDestB, downOriginC, downDestC, downOriginD, downDestD, downOriginE, downDestE, downOriginF, downDestF);
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

void generateUpDownTiles(int row, int *upOrigin, int *upDest, int *downOrigin, int *downDest){
	int temp1 = 0, temp2 = 0, temp3 = 0, temp4 = 0;
	do{
		temp1 = nRandomizer(row*10, row*10+9);
		temp2 = nRandomizer(row*10, row*10+9);
		temp3 = nRandomizer((row+1)*10, (row+1)*10+9);
		temp4 = nRandomizer((row+1)*10, (row+1)*10+9);
	} while (temp1 == temp2 || temp1 == temp3 || temp1 == temp4 || temp2 == temp3 || temp2 == temp4 || temp3 == temp4);
	if(temp1 < temp3){
		*upOrigin = temp1;
		*upDest = temp3;
	}
	else{
		*upDest = temp1;
		*upOrigin = temp3;
	}

	if(temp2 < temp4){
		*downOrigin = temp4;
		*downDest = temp2;
	}
	else{
		*downDest = temp4;
		*downOrigin = temp2;
	}
}


void checkTiles(int row, int *upOrigin, int *upDest, int *downOrigin, int *downDest){
	do{
		generateUpDownTiles(row, upOrigin, upDest, downOrigin, downDest);
	} while(*upOrigin == *downOrigin || *upDest == *downDest || *upOrigin == *downDest || *upDest == *downOrigin);
}

int startGame(){
	printf("Starting game...\n");
	
	int p1Tile = 0;
	int p2Tile = 0;

	int nCurrentPlayer = 1;
	int roll = 0;
	int nWinner = 0;

	int p1SabotageOrigin;
	int p1SabotageDest;
	int p2SabotageOrigin;
	int p2SabotageDest;

	int upOriginA, upDestA;
	int upOriginB, upDestB;
	int upOriginC, upDestC;
	int upOriginD, upDestD;
	int upOriginE, upDestE;
	int upOriginF, upDestF;

	int downOriginA, downDestA;
	int downOriginB, downDestB;
	int downOriginC, downDestC;
	int downOriginD, downDestD;
	int downOriginE, downDestE;
	int downOriginF, downDestF;

	for (int i = 1; i<=6; i++){
		switch(i){
			case 1:
				do{
					checkTiles(i, &upOriginA, &upDestA, &downOriginA, &downDestA);
				} while (upOriginA == upOriginB || upOriginA == upOriginC || upOriginA == upOriginD || upOriginA == upOriginE || upOriginA == upOriginF);
				break;
			case 2:
				do{
					checkTiles(i, &upOriginB, &upDestB, &downOriginB, &downDestB);
				} while (upOriginB == upOriginC || upOriginB == upOriginD || upOriginB == upOriginE || upOriginB == upOriginF);
				break;
			case 3:
				do{
					checkTiles(i, &upOriginC, &upDestC, &downOriginC, &downDestC);
				} while (upOriginC == upOriginD || upOriginC == upOriginE || upOriginC == upOriginF);
				break;
			case 4:
				do{
					checkTiles(i, &upOriginD, &upDestD, &downOriginD, &downDestD);
				} while (upOriginD == upOriginE || upOriginD == upOriginF);
				break;
			case 5:
				do{
					checkTiles(i, &upOriginE, &upDestE, &downOriginE, &downDestE);
				} while (upOriginE == upOriginF);
				break;
			case 6:
				checkTiles(i, &upOriginF, &upDestF, &downOriginF, &downDestF);
				break;
		}
	}

	printf("Up tiles:\n");
	printf("A: %d %d\n", upOriginA, upDestA);
	printf("B: %d %d\n", upOriginB, upDestB);
	printf("C: %d %d\n", upOriginC, upDestC);
	printf("D: %d %d\n", upOriginD, upDestD);
	printf("E: %d %d\n", upOriginE, upDestE);
	printf("F: %d %d\n", upOriginF, upDestF);

	printf("Down tiles:\n");
	printf("A: %d %d\n", downOriginA, downDestA);
	printf("B: %d %d\n", downOriginB, downDestB);
	printf("C: %d %d\n", downOriginC, downDestC);
	printf("D: %d %d\n", downOriginD, downDestD);
	printf("E: %d %d\n", downOriginE, downDestE);
	printf("F: %d %d\n", downOriginF, downDestF);

	do{
		printf("Player 1: You may place a down tile and its link anywhere on the board.\n");
		scanf("%d %d", &p1SabotageOrigin, &p1SabotageDest);
	} while (p1SabotageDest <= 9 || p1SabotageDest >= 100);

	do{
		printf("Player 2: You may place a down tile and its link anywhere on the board.\n");
		scanf("%d %d", &p2SabotageOrigin, &p2SabotageDest);
	} while (p2SabotageDest <= 9 || p2SabotageDest >= 100);

	showBoard(p1Tile, p2Tile, p1SabotageOrigin, p1SabotageDest, p2SabotageOrigin, p2SabotageDest, 
			  upOriginA, upDestA, upOriginB, upDestB, upOriginC, upDestC, upOriginD, upDestD, upOriginE, upDestE, upOriginF, upDestF,
			  downOriginA, downDestA, downOriginB, downDestB, downOriginC, downDestC, downOriginD, downDestD, downOriginE, downDestE, downOriginF, downDestF);

	do{	
		printf("\e[1;1H\e[2J"); // Clears the screen
		if(nCurrentPlayer == 1){
			printf("Player 1's turn!\n");
			rollDie(&p1Tile, &roll);
			showBoard(p1Tile, p2Tile, p1SabotageOrigin, p1SabotageDest, p2SabotageOrigin, p2SabotageDest, 
					  upOriginA, upDestA, upOriginB, upDestB, upOriginC, upDestC, upOriginD, upDestD, upOriginE, upDestE, upOriginF, upDestF,
					  downOriginA, downDestA, downOriginB, downDestB, downOriginC, downDestC, downOriginD, downDestD, downOriginE, downDestE, downOriginF, downDestF);
			while(roll == 1){
				rollDie(&p1Tile, &roll);
				showBoard(p1Tile, p2Tile, p1SabotageOrigin, p1SabotageDest, p2SabotageOrigin, p2SabotageDest, 
						  upOriginA, upDestA, upOriginB, upDestB, upOriginC, upDestC, upOriginD, upDestD, upOriginE, upDestE, upOriginF, upDestF,
						  downOriginA, downDestA, downOriginB, downDestB, downOriginC, downDestC, downOriginD, downDestD, downOriginE, downDestE, downOriginF, downDestF);
			}
			nCurrentPlayer = 2;
		}
		else{
			printf("Player 2's turn!\n");
			rollDie(&p2Tile, &roll);
			showBoard(p1Tile, p2Tile, p1SabotageOrigin, p1SabotageDest, p2SabotageOrigin, p2SabotageDest, 
					  upOriginA, upDestA, upOriginB, upDestB, upOriginC, upDestC, upOriginD, upDestD, upOriginE, upDestE, upOriginF, upDestF,
					  downOriginA, downDestA, downOriginB, downDestB, downOriginC, downDestC, downOriginD, downDestD, downOriginE, downDestE, downOriginF, downDestF);
			while(roll == 1){
				rollDie(&p2Tile, &roll);
				showBoard(p1Tile, p2Tile, p1SabotageOrigin, p1SabotageDest, p2SabotageOrigin, p2SabotageDest, 
						  upOriginA, upDestA, upOriginB, upDestB, upOriginC, upDestC, upOriginD, upDestD, upOriginE, upDestE, upOriginF, upDestF,
						  downOriginA, downDestA, downOriginB, downDestB, downOriginC, downDestC, downOriginD, downDestD, downOriginE, downDestE, downOriginF, downDestF);
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
	srand(time(0));
	mainMenu();
	return 0;
}
