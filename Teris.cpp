#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#define BLOCK_BODY_SOLID	"■"
#define BLOCK_BODY_HOLLOW	"□"
#define MAP_WIDTH 12
#define MAP_HEIGH 22
#define SCORE_X 13
#define SCORE_Y 8
#define __N__ 0
#define __T__ 1000

struct Block {
	//起始坐标和形状
	int posX, posY, shape, angle;
	/*
	*二进制表示图形
	*	0 0 0 0
	*	0 1 0 0
	*	0 1 0 0
	*	0 1 1 0
	* 可表示为 0000 0100 0100 0110
	*/
	unsigned int binary;


};
//各种已经压缩过的旋转形状
const unsigned int WholeBlocks[7][4] = {
	{17476, 15, 17476, 15},
	{1094, 116, 1570, 46},
	{102, 102, 102, 102},
	{198, 612, 198, 612},
	{54, 1122, 54, 1122},
	{78, 2248, 228, 610},
	{550, 71, 1604, 226}
};

int map[MAP_HEIGH][MAP_WIDTH] = { 0 };
int score = 0, KEY_V = 0;
bool isGameOver = false;

int Getkey(int N, int T)
{
	int start = clock();
	//if (KEY_V == 115) { return 115; }
	do {
		if (kbhit()) {
			KEY_V = (int)(getch());
			if (KEY_V < 97) { KEY_V += 32; }
			return KEY_V;
		}
		for (int i = 0; i <= N; i++);
	} while ((clock() - start) < T);
	return -1;
}
bool getBinaryOfI(int binary, int i) {
	return (((binary >> i) & 1) == 1);
}
void gotoxy(int x, int y) {
	//note that x as Y, y as X
	COORD coord;
	coord.Y = y;
	coord.X = x * 2;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void DrawMap() {
	for (int i = 0; i < MAP_HEIGH; i++) {
		for (int j = 0; j < MAP_WIDTH; j++) {
			if (i == 0 || i == MAP_HEIGH - 1)
				printf(BLOCK_BODY_SOLID);
			else if (j == 0 || j == MAP_WIDTH - 1)
				printf(BLOCK_BODY_SOLID);
			else map[i][j] == 1 ? printf(BLOCK_BODY_SOLID) : printf(BLOCK_BODY_HOLLOW);
		}
		if (i != MAP_HEIGH - 1) printf("\n");
	}
}
Block CreatBlock() {
	Block ans;
	ans.posX = MAP_WIDTH / 2;
	ans.posY = -3;
	ans.shape = rand() % 7;
	ans.angle = rand() % 4;
	ans.binary = WholeBlocks[ans.shape][ans.angle];

	return ans;
}
void findCoordinate(const Block &block, int i, int& x, int& y) {
	x = block.posX + 3, y = block.posY + 3;
	x -= i % 4;
	while (i - 4 >= 0) {
		i -= 4;
		y--;
	}
}

void printSingle(int x, int y){
	gotoxy(x, y);
	printf(BLOCK_BODY_SOLID);
}
void clearSingle(int x, int y) {
	gotoxy(x, y);
	printf(BLOCK_BODY_HOLLOW);
}
void printBlock(const Block &block) {
	int x, y;
	for (int i = 0; i < 16; i++) {
		findCoordinate(block, i, x, y);
		gotoxy(x, y);

		if (x <= 0 || x >= MAP_WIDTH - 1 ||
			y <= 0 || y >= MAP_HEIGH - 1)
			continue;

		if (getBinaryOfI(block.binary, i))
			printf(BLOCK_BODY_SOLID);
		//else printf(BLOCK_BODY_HOLLOW);
	}
}
void clearBlock(const Block &block) {
	int x, y;
	for (int i = 0; i < 16; i++) {
		findCoordinate(block, i, x, y);
		gotoxy(x, y);

		if (x <= 0 || x >= MAP_WIDTH - 1 ||
			y <= 0 || y >= MAP_HEIGH - 1 )
			continue;
		printf(BLOCK_BODY_HOLLOW);
	}
}
void spinBlock(Block& block) {
	Block temp = block;
	temp.angle = (temp.angle + 1) % 4;
	temp.binary = WholeBlocks[temp.shape][temp.angle];
	int x, y;
	for (int i = 0; i < 16; i++) {
		findCoordinate(block, i, x, y);

		if (x <= 0 || x >= MAP_WIDTH - 1 ||
			y <= 0 || y >= MAP_HEIGH - 1 ||
			((map[y][x] == 1) && getBinaryOfI(block.binary, i)));
		else {
			clearBlock(block);
			block = temp;
			printBlock(block);
		}
	}
}
void UpdataScore(int score) {
	gotoxy(SCORE_X, SCORE_Y);
	printf("score : %d", score);
}

void SolidWindowShape() {
	
	SetWindowLongPtrA(

		GetConsoleWindow(),

		GWL_STYLE,

		GetWindowLongPtrA(GetConsoleWindow(), GWL_STYLE)

		& ~WS_SIZEBOX & ~WS_MAXIMIZEBOX & ~WS_MINIMIZEBOX

	);
}

bool checkCollisionExited(const Block& block) {
	int x, y;
	for (int i = 0; i < 16; i++) {
		if (getBinaryOfI(block.binary, i)) {
			findCoordinate(block, i, x, y);
			if (map[y][x] == 1 && getBinaryOfI(block.binary, i));
				return true;
		}
	}
	return false;
}
void HideCursor() {
	CONSOLE_CURSOR_INFO curo;
	curo.bVisible = FALSE;
	curo.dwSize = sizeof(curo);
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorInfo(handle, &curo);
}

void init(){
	system("mode con cols=38 lines=22");
	HideCursor();
	SolidWindowShape();
	DrawMap();

	srand((unsigned)time(NULL));
}
void move(Block &block, int direction) {
	block.posX += direction;
	if (checkCollisionExited(block))
		block.posX -= direction;
}
bool checkDrop(Block& block) {
	int x, y;
	for (int i = 0; i < 16; i++) {
		if (getBinaryOfI(block.binary, i)) {
			findCoordinate(block, i, x, y);
			if (map[y + 1][x] == 1)
				return false;
		}
	}
	return true;
}
void drop(Block& block) {
	block.posY++;
	if (checkCollisionExited(block))
		block.posY--;
}
bool checkIsGameOver(Block &block) {
	int x, y;
	for (int i = 0; i < 16; i++) {
		findCoordinate(block, i, x, y);
		if (y <= 0 && getBinaryOfI(block.binary, i))
			return true;
	}

	return false;
}
void clearTheLastLine() {



	for (int i = MAP_HEIGH - 2; i >= 1; i--) {
		for (int j = 1; j < MAP_WIDTH - 2; j++) {
			if (i == 1)
				map[i][j] = 0;
			else {
				map[i][j] = map[i - 1][j];
			}
		}
	}

	DrawMap();
}
void newTurn(Block &block) {
	while (checkDrop(block))
	{
		printBlock(block);


		Getkey(__N__, __T__);
		clearBlock(block);
		switch (KEY_V){
		case 'w' :
			spinBlock(block); break;
		case 's' :
			while (checkDrop(block)) drop(block); break;
		case 'a' :
			move(block, -1); break;
		case 'd' :
			move(block, 1); break;
		default : break;
		}
	}

	int x, y;
	for (int i = 0; i < 16; i++) {
		findCoordinate(block, i, x, y);
		if (getBinaryOfI(block.binary, i))
			map[y][x] = 1;
	}

	DrawMap();
}

int main() {
	init();
	while (!isGameOver) {
		Block item = CreatBlock();
		newTurn(item);
		
	}
	getchar();
	return 0;
}