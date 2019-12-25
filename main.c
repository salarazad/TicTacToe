#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <myheader.h>
#include <time.h>


// printing the board layout
void layout() {
	printmid(35,11,"___________________________________________________\n");
	printmid(35,19,"___________________________________________________\n");
	int l;
	for (l=5; l<=26; l++) {
		printmid(50,l,"|");
		printmid(70,l,"|");
	}
}


//printing the tiles letters
void letters () {
	printmid(41.0,10.8,"(A)");
	printmid(59.0,10.8,"(B)");
	printmid(78.0,10.8,"(C)");
	printmid(47.0,16.0,"(D)");
	printmid(59.0,18.8,"(E)");
	printmid(71.0,16.0,"(F)");
	printmid(41.0,20.0,"(G)");
	printmid(59.0,20.0,"(H)");
	printmid(78.0,20.0,"(I)");
}



int main(int argc, char **argv)
{
	flashing();               // fun banner flashing at the beginner, a litlle bit annoying
		
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	printmid(50,1,"\"TicTacToe\" Game By Me");
	

	char move1;                                         // firstplayer move, which tile
	char move2;                                         // second player move
	char firstplayer[255];                              // name of firstplayer, in multiplayer mode
	char secondplayer[255];                             // name of second player
	
	char move;
	char pcname[] = "computer";                                      // name of pc, in single mode
	char playername[255];                                            // name of player, in single mode
//	char tiles[] = {'a','b','c','d','e','f','g','h','i'};                  // another method of defining the string
	char tiles[] = "abcdefghi";                              // tictactoe tiles, a...i
	int randtile;                                            // getting random tile, from tiles and randnum
	int randnum;                                             // finding the randnum 0....8
	char randlimit = 9;                                      // limit the randomness to 9 at beggining, then start decreasing
	
	char replay;                       // play again
	int loop;                          // looping through the 
	char playmode[255];                // choosing play mode, single or multi player
	
	
	do {
		strcpy(&tiles[0], "abcdefghi");                               // resetting the string of tiles when game repeated, single mode game
		char randlimit = 9;                                           // resetting the randlimit when game repeated, for getting random number, single mode game
		system("cls");
		printmid(50,1,"\"TicTacToe\" Game By Me");
		printmid(47,5,"single or multi player: ");
		cursor(71,5);
		scanf("%s",playmode);
		
		if (strcmp(playmode,"multi")==0) {                                     
			// case of multi mode is done here
			printmid(47,7,"First player name: ");
			cursor(66,7);
			scanf("%s", firstplayer);
			printmid(47,8,"Second player name: ");
			cursor(67,8);
			scanf("%s", secondplayer);
			getchar();
			printmid(47,5,"                                          ");
			printmid(47,7,"                                          ");
			printmid(47,8,"                                          ");
			
			layout();
			letters();
			
			printmid(41,8," ");
			printmid(59,8," ");
			printmid(77,8," ");
			printmid(41,15," ");
			printmid(59,15," ");
			printmid(77,15," ");
			printmid(41,23," ");
			printmid(59,23," ");
			printmid(77,23," ");
			printmid(19,5," ");
			printmid(20,6," ");
			printmid(5,10,"                        ");
			int a1=0, b1=0, c1=0, d1=0, e1=0, f1=0, g1=0, h1=0, i1=0;               // reset the tiles values when repeat the game
			int a2=0, b2=0, c2=0, d2=0, e2=0, f2=0, g2=0, h2=0, i2=0;
			int winner = 3;                                                         // 3 is for draw
			printmid(5,5,"                                       ");
			printmid(5,6,"                                       ");
			for (loop=0; loop<5; loop++) {                                          // 9 tiles, 4 loops and a half needed for 2 players
				printmid(5,3,"Players moves...");
				// sketching on the board, Player 1
				printmid(5,5,"First Player: ");
				cursor(19,5);
				move1 = getchar();
				getchar();
				if(move1 == 'a') {
					printmid(41,8,"X");
					a1 = 1;
				}
				else if (move1 == 'b') {
					printmid(59,8,"X");
					b1 = 1;
				}
				else if (move1 == 'c') {
					printmid(77,8,"X");
					c1 = 1;
				}
				else if (move1 == 'd') {
					printmid(41,15,"X");
					d1 = 1;
				}
				else if (move1 == 'e') {
					printmid(59,15,"X");
					e1 = 1;
				}
				else if (move1 == 'f') {
					printmid(77,15,"X");
					f1 = 1;
				}
				else if (move1 == 'g') {
					printmid(41,23,"X");
					g1 = 1;
				}
				else if (move1 == 'h') {
					printmid(59,23,"X");
					h1 = 1;
				}
				else if (move1 == 'i') {
					printmid(77,23,"X");
					i1 = 1;
				}
				
				if ((a1 + e1 + i1)==3 || (c1 + e1 + g1)==3 || (d1 + e1 + f1)==3 || (b1 + e1 + h1)==3 || (a1 + b1 + c1)==3 || (c1 + f1 + i1)==3 || (i1 + h1 + g1)==3 || (g1 + d1 + a1)==3) {
					winner = 1;
					printmid(5,10,strcat(firstplayer," won! cheers mate"));
					break;
				}
				
				if (loop == 4) {                      // if the loop is 4 and no one won, it stops the game, because we have only 9 tiles
				//two tiles per loop so for 4 and a half loop there will be 9 tiles
					break;
				}
				
				// sketching on the board, Player 2
				printmid(5,6,"Second Player: ");
				cursor(20,6);
				move2 = getchar();
				getchar();
				if(move2 == 'a') {
					printmid(41,8,"O");
					a2 = 1;
				}
				else if (move2 == 'b') {
					printmid(59,8,"O");
					b2 = 1;
				}
				else if (move2 == 'c') {
					printmid(77,8,"O");
					c2 = 1;
				}
				else if (move2 == 'd') {
					printmid(41,15,"O");
					d2 = 1;
				}
				else if (move2 == 'e') {
					printmid(59,15,"O");
					e2 = 1;
				}
				else if (move2 == 'f') {
					printmid(77,15,"O");
					f2 = 1;
				}
				else if (move2 == 'g') {
					printmid(41,23,"O");
					g2 = 1;
				}
				else if (move2 == 'h') {
					printmid(59,23,"O");
					h2 = 1;
				}
				else if (move2 == 'i') {
					printmid(77,23,"O");
					i2 = 1;
				}
			
			
				if ((a2 + e2 + i2)==3 || (c2 + e2 + g2)==3 || (d2 + e2 + f2)==3 || (b2 + e2 + h2)==3 || (a2 + b2 + c2)==3 || (c2 + f2 + i2)==3 || (i2 + h2 + g2)==3 || (g2 + d2 + a2)==3) {
					winner = 2;
					printmid(5,10,strcat(secondplayer," won! go have a drink"));
					break;
				}
			
			}
			if(winner == 3) {
				printf("it is a draw folks, you both good!!\n");
			}
			
			
//			yaqub agha
		}
		else if (strcmp(playmode,"single")==0) {
			// case of multi mode is done here
			printmid(47,7,"player name: ");
			cursor(60,7);
			scanf("%s", playername);
			getchar();
			printmid(47,5,"                                          ");
			printmid(47,7,"                                          ");
			
			layout();
			letters();
			
			printmid(41,8," ");
			printmid(59,8," ");
			printmid(77,8," ");
			printmid(41,15," ");
			printmid(59,15," ");
			printmid(77,15," ");
			printmid(41,23," ");
			printmid(59,23," ");
			printmid(77,23," ");
			printmid(19,5," ");
			printmid(20,6," ");
			printmid(5,10,"                        ");
			int a1=0, b1=0, c1=0, d1=0, e1=0, f1=0, g1=0, h1=0, i1=0;               // reset the tiles values when repeat the game
			int a2=0, b2=0, c2=0, d2=0, e2=0, f2=0, g2=0, h2=0, i2=0;
			int winner = 3;                                                        // 3 is for draw
			printmid(5,5,"                                       ");
			printmid(5,6,"                                       ");
			for (loop=0; loop<5; loop++) {                                       // 9 tiles, 4 loops and a half needed for 2 players
				printmid(5,3,"Players moves...");
				// sketching on the board, Player 1
				printmid(5,5,"Player move: ");
				cursor(19,5);
				move = getchar();
				getchar();
				if(move == 'a') {
					printmid(41,8,"X");
					a1 = 1;
//					delchrinstr('a');
					char *pntr = strcpy(&tiles[0], delchar(tiles,'a'));
//					strcpy(&tiles[0], delchar(tiles,'a'));
					randlimit--;
					free(pntr);
				}
				else if (move == 'b') {
					printmid(59,8,"X");
					b1 = 1;
//					delchrinstr('b');
					char *pntr = strcpy(&tiles[0], delchar(tiles,'b'));             // call the function in myheader.h, to remove the character and return the new string
//					strcpy(&tiles[0], delchar(tiles,'b'));
					randlimit--;
					free(pntr);                                                     // freeing the memory allocated for the new string
				}
				else if (move == 'c') {
					printmid(77,8,"X");
					c1 = 1;
//					delchrinstr('c');
					char *pntr = strcpy(&tiles[0], delchar(tiles,'c'));
//					strcpy(&tiles[0], delchar(tiles,'c'));
					randlimit--;
					free(pntr);
				}
				else if (move == 'd') {
					printmid(41,15,"X");
					d1 = 1;
//					delchrinstr('d');
					char *pntr = strcpy(&tiles[0], delchar(tiles,'d'));
//					strcpy(&tiles[0], delchar(tiles,'d'));
					randlimit--;
					free(pntr);
				}
				else if (move == 'e') {
					printmid(59,15,"X");
					e1 = 1;
//					delchrinstr('e');
					char *pntr = strcpy(&tiles[0], delchar(tiles,'e'));
//					strcpy(&tiles[0], delchar(tiles,'e'));
					randlimit--;
					free(pntr);
				}
				else if (move == 'f') {
					printmid(77,15,"X");
					f1 = 1;
//					delchrinstr('f');
					char *pntr = strcpy(&tiles[0], delchar(tiles,'f'));
//					strcpy(&tiles[0], delchar(tiles,'f'));
					randlimit--;
					free(pntr);
				}
				else if (move == 'g') {
					printmid(41,23,"X");
					g1 = 1;
//					delchrinstr('g');
					char *pntr = strcpy(&tiles[0], delchar(tiles,'g'));
//					strcpy(&tiles[0], delchar(tiles,'g'));
					randlimit--;
					free(pntr);
				}
				else if (move == 'h') {
					printmid(59,23,"X");
					h1 = 1;
//					delchrinstr('h');
					char *pntr = strcpy(&tiles[0], delchar(tiles,'h'));
//					strcpy(&tiles[0], delchar(tiles,'h'));
					randlimit--;
					free(pntr);
				}
				else if (move == 'i') {
					printmid(77,23,"X");
					i1 = 1;
//					delchrinstr('i');
					char *pntr = strcpy(&tiles[0], delchar(tiles,'i'));
//					strcpy(&tiles[0], delchar(tiles,'i'));
					randlimit--;
					free(pntr);
				}
				
				if ((a1 + e1 + i1)==3 || (c1 + e1 + g1)==3 || (d1 + e1 + f1)==3 || (b1 + e1 + h1)==3 || (a1 + b1 + c1)==3 || (c1 + f1 + i1)==3 || (i1 + h1 + g1)==3 || (g1 + d1 + a1)==3) {
					winner = 1;
					printmid(5,10,strcat(playername," won! you must be smart"));
					break;
				}
				
				if (loop == 4) {
					break;
				}
				
				// sketching on the board, PC move, creating the randomness (AIshh)
				srand(time(0));
				randnum = rand()%randlimit;
				randtile = tiles[randnum];
				putchar(randnum);
				putchar(randtile);
				
				if(randtile == 'a') {
					printmid(41,8,"O");
					a2 = 1;
//					delchrinstr('a');
					char *pntr = strcpy(&tiles[0], delchar(tiles,'a'));
//					strcpy(&tiles[0], delchar(tiles,'a'));
					randlimit--;
					free(pntr);
				}
				else if (randtile == 'b') {
					printmid(59,8,"O");
					b2 = 1;
//					delchrinstr('b');
					char *pntr = strcpy(&tiles[0], delchar(tiles,'b'));
//					strcpy(&tiles[0], delchar(tiles,'b'));
					randlimit--;
					free(pntr);
				}
				else if (randtile == 'c') {
					printmid(77,8,"O");
					c2 = 1;
//					delchrinstr('c');
					char *pntr = strcpy(&tiles[0], delchar(tiles,'c'));
//					strcpy(&tiles[0], delchar(tiles,'c'));
					randlimit--;
					free(pntr);
				}
				else if (randtile == 'd') {
					printmid(41,15,"O");
					d2 = 1;
//					delchrinstr('d');
					char *pntr = strcpy(&tiles[0], delchar(tiles,'d'));
//					strcpy(&tiles[0], delchar(tiles,'d'));
					randlimit--;
					free(pntr);
				}
				else if (randtile == 'e') {
					printmid(59,15,"O");
					e2 = 1;
//					delchrinstr('e');
					char *pntr = strcpy(&tiles[0], delchar(tiles,'e'));
//					strcpy(&tiles[0], delchar(tiles,'e'));
					randlimit--;
					free(pntr);
				}
				else if (randtile == 'f') {
					printmid(77,15,"O");
					f2 = 1;
//					delchrinstr('f');
					char *pntr = strcpy(&tiles[0], delchar(tiles,'f'));
//					strcpy(&tiles[0], delchar(tiles,'f'));
					randlimit--;
					free(pntr);
				}
				else if (randtile == 'g') {
					printmid(41,23,"O");
					g2 = 1;
//					delchrinstr('g');
					char *pntr = strcpy(&tiles[0], delchar(tiles,'g'));
//					strcpy(&tiles[0], delchar(tiles,'g'));
					randlimit--;
					free(pntr);
				}
				else if (randtile == 'h') {
					printmid(59,23,"O");
					h2 = 1;
//					delchrinstr('h');
					char *pntr = strcpy(&tiles[0], delchar(tiles,'h'));
//					strcpy(&tiles[0], delchar(tiles,'h'));
					randlimit--;
					free(pntr);
				}
				else if (randtile == 'i') {
					printmid(77,23,"O");
					i2 = 1;
//					delchrinstr('i');
					char *pntr = strcpy(&tiles[0], delchar(tiles,'i'));
//					strcpy(&tiles[0], delchar(tiles,'i'));
					randlimit--;
					free(pntr);
				}
			
			
				if ((a2 + e2 + i2)==3 || (c2 + e2 + g2)==3 || (d2 + e2 + f2)==3 || (b2 + e2 + h2)==3 || (a2 + b2 + c2)==3 || (c2 + f2 + i2)==3 || (i2 + h2 + g2)==3 || (g2 + d2 + a2)==3) {
					winner = 2;
					printmid(5,10,strcat(pcname," beat you!"));
					break;
				}
			
			}
			if(winner == 3) {
				printf("you couldn't beat the PC, but you didn't win either!!\n");
			}
			
			// yaqub agha
		}
	
		printf("\n");
		printf("play gain? (y or no) ");
		replay = getchar();
		getchar();
	}
	while(replay == 'y');

	
	
	return 0;
}