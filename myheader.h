// color automation
#define BLACK			0
#define BLUE			1
#define GREEN			2
#define CYAN			3
#define RED				4
#define MAGENTA			5
#define BROWN			6
#define LIGHTGRAY		7
#define DARKGRAY		8
#define LIGHTBLUE		9
#define LIGHTGREEN		10
#define LIGHTCYAN		11
#define LIGHTRED		12
#define LIGHTMAGENTA	13
#define YELLOW			14
#define WHITE			15


// cursor move to coordination
void printmid(double x, double y, char text[]) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
	printf("%s\n", text);
}

// cursor move to coordination
void cursor(double x, double y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}



// flashing banner
void flashing () {		
	int f;
	for (f=0; f<=2; f++) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), RED);
		printmid(50,3,"Let the battle begin");
		cursor(60,3);
		Sleep(400);
		system("cls");
		cursor(60,3);
		Sleep(400);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WHITE);
	}
}





char* delchar(char *tiles2, char rmvchr) {
	char *tiles;
	tiles = malloc(sizeof(char)*10);
//	tiles = malloc(sizeof(tiles)*10);
	strcpy(tiles,tiles2);
	char *m;
	m = strchr(tiles,rmvchr);
	if (m){
		int position = m - tiles;
		strcpy(&tiles[position], &tiles[position+1]);
		return tiles;
	}
	else return tiles2;
	return 0;
}




//char *delchrinstr(int rmv) {
//	
//char tiles[]="abcdefghi";
//int toBeRemoved=rmv;                     // rmv=2 , digit of character to remove
//memmove(&tiles[toBeRemoved],&tiles[toBeRemoved+1],strlen(tiles)-toBeRemoved);
//puts(tiles);
//
////return tiles;
//}