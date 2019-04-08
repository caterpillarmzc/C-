#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int menu(){
	printf("=========================\n");
	printf("1.开始游戏\n");
	printf("0.结束游戏\n");
	printf("=========================\n");
	printf("请输入您的选择:");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

//宏定义行和列,可读性高,方便改参数
#define MAX_ROW 9
#define MAX_COL 9
#define MINE_COUNT 10
void Init(char show_map[MAX_ROW][MAX_COL],
	char mine_map[MAX_ROW][MAX_COL]){
//对于show来说,都设为*
	for (int row = 0; row < MAX_ROW;++row){
		for (int col = 0; col < MAX_COL;++col){
			show_map[row][col] = '*';
	    }
	}
	//对于mine_map,需要随机生成若干个地雷
	//0表示不是地雷,1表示是地雷
	for (int row = 0; row < MAX_ROW;++row){
		for (int col = 0; col < MAX_COL;++col){
			mine_map[row][col] = '0';
	    }
	}
	int n = MINE_COUNT;
	while (n>0)
	{
		int row=rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mine_map[row][col]=='1')
		{//表示该位置已经是地雷了,需要重新生成
			continue;
		}
		mine_map[row][col] = '1';
		--n;
	}
}
void PrintMap(char map[MAX_ROW][MAX_COL]){
//打印地图和坐标
	//第一行
	printf("    ");
	for (int i = 0; i < MAX_COL;i++){
		printf("%d ", i);
	}
	printf("\n");
	for (int col = 0; col < MAX_COL-2;++col){
		printf("---");
	}
	printf("\n");
	//打印其他行
	for (int row = 0; row < MAX_ROW;++row){
		printf(" %d| ",row);
		//打印本行的每一列
		for (int col = 0; col < MAX_COL;++col){
			printf("%c ",map[row][col]);
		}
		printf("\n");
	}
}
void UpdateShowMap(int row,int col,
	char show_map[MAX_ROW][MAX_COL], 
	char mine_map[MAX_ROW][MAX_COL]){
	//根据当前的位置判定周围有几个地雷
	//并且将这个数字更新到show_map

}
void game(){
	//创建地图(玩家看到的和显示位置的)
	char show_map[MAX_ROW][MAX_COL];
	char mine_map[MAX_ROW][MAX_COL];
	Init(show_map, mine_map);
	//已经翻开的空格数(非地雷数)
	int blank_count_already_show = 0;
	while (1){
		//打印地图
		PrintMap(show_map);
		//输入坐标并合法性检测
		printf("请输入一组坐标(row,col):");
		int row = 0;
		int col = 0;
		scanf("%d,%d", &row, &col);
		if (row < 0 || row >= MAX_ROW ||
			col < 0 || col >= MAX_COL){
			printf("输入有误,请重新输入");
			continue;
		}
		if (show_map[row][col]!='*'){
			printf("您输入的位置已经被翻开了\n");
			continue;
		}
		//判定是否是地雷
		if (mine_map[row][col] == '1'){
			printf("游戏结束\n");
			PrintMap(mine_map);
			break;
		}
		//判定游戏是否胜利
		//判定所有非地雷位置都翻开了
		++blank_count_already_show;
		if (blank_count_already_show==
			MAX_ROW*MAX_COL-MINE_COUNT){
			printf("游戏胜利\n");
			PrintMap(mine_map);
			break;
		}
		//统计周围雷的个数
		UpdateShowMap(row,col,show_map,mine_map);
	}
}
int main(){
	while (1){
		int choice = menu();
		if (choice == 1){
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