#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int menu(){
	printf("=========================\n");
	printf("1.开始游戏\n");
	printf("0.结束游戏\n");
	printf("=========================\n");
	printf("请输入您的选择:");
	int choice = 0;
	scanf("%d",&choice);
	return choice;
}
//宏定义行和列,可读性高,方便改参数
#define MAX_ROW 3
#define MAX_COL 3
char chess_board[MAX_ROW][MAX_COL];


//自顶下式的程序开发方法
void Init(){
	for (int row = 0; row < MAX_ROW; row++){
		for (int col = 0; col < MAX_COL; col++){
			chess_board[row][col] = ' ';
		}
	}
	//设置随机种子
	srand((unsigned int)time(0));
}

void Print(){
	for (int row = 0; row < MAX_ROW; ++row){
		printf("%c|%c|%c\n", chess_board[row][0],
			chess_board[row][1],chess_board[row][2]);
		if ("row!= MAX_ROW-1"){
			printf(" --- --- --- \n");
		}
	}
	//system("pause");
}

void PlayerMove(){
	printf("玩家落子!\n");
	while (1){
		printf("请输入落子位置的坐标(row,col):");
		int row = 0;
		int col = 0;
		scanf("%d,%d", &row, &col);
		//检查输入是否合法
		if (row < 0 || row >= MAX_ROW ||
			col < 0 || col >= MAX_COL){
			printf("坐标非法,重新输入\n");
			continue;
		}
		if (chess_board[row][col] != ' '){
			printf("坐标已被占用!\n");
			continue;
		}
		chess_board[row][col] = 'x';
		break;
	}
	printf("玩家落子完毕!\n");
}

void ComputerMove(){
	printf("电脑落子!\n");
	while (1){
		int row = rand() % 3;
		int col = rand() % 3;
		if (chess_board[row][col] != ' '){
			continue;
		}
		chess_board[row][col] = 'o';
		break;
	}
	printf("电脑落子完毕!\n");
}

//如果棋盘满了,返回1,否则返回0
int IsFull(){
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; col++){
			if (chess_board[row][col] == ' '){
				//未满
				return 0;
			}
		}
	}return 1;
}
//返回值表示胜利者是谁
//x表示玩家胜利
//o表示电脑胜利
//q表示和棋
//' '表示未分胜负
char  CheckWinner(){
	{
		//检查所有行是否连城一条线
		for (int row = 0; row < MAX_ROW; ++row){
			if (chess_board[row][0] == chess_board[row][1]
				&& chess_board[row][0] == chess_board[row][2])
				return chess_board[row][0];
		}
	}
	//检查所有列是否连城一条线
	for (int col = 0; col = MAX_COL; ++col){
		if (chess_board[0][col]== chess_board[1][col]
			&& chess_board[0][col]== chess_board[2][col]){
			return chess_board[0][col];
		}
	}
	//检查所有对角线是否连城一条线
	if (chess_board[0][0] == chess_board[1][1] &&
		chess_board[0][0] == chess_board[2][2]){
		return chess_board[0][0];
	}
	if (chess_board[0][2] == chess_board[1][1] &&
		chess_board[0][2] == chess_board[2][0]){
		return chess_board[0][2];
	}
	//棋盘满并且未分出胜负
	if (IsFull()){
		return'q';
	}
	return ' ';

}
void game(){
//1.初始化棋盘
	Init();
	char winner = ' ';
	while (1){
		// 2.打印棋盘
		Print();
		//3.玩家落子
		PlayerMove();
		//4.检测胜负
		winner =CheckWinner();
		if (winner != ' '){
		//胜负已分
			break;
		}
		//5.电脑落子
		ComputerMove();
		//6.检测胜负后返回到2继续循环
		winner = CheckWinner();
		if (winner != ' '){
			//胜负已分
			break;
		}
	}
	Print();
	if (winner == 'x'){
		printf("您赢了!\n");
	}
	else if (winner == 'o'){
		printf("您真菜,连电脑都打不过\n");
	}
	else if (winner == 'q'){
		printf("您和电脑五五开!\n");
	}
	else{
		printf("代码好像bug了!\n");
	}
}




int main(){
	while (1){
		int choice = menu();
		if (choice ==1){
			game();
		} 
		else if (choice == 0)
		{
			printf("good bye!");
			break;
		}
		else{
			printf("您的输入有误!");
		}
	}
	
	system("pause");
	return 0;
}