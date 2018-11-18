#include <stdio.h>
#include <assert.h>
#include <limits.h>
int computer = 1;
int human = -1;

int win(int *board,int player){
	if((board[0]+board[1]+board[2])==3*player||(board[3]+board[4]+board[5])==3*player||(board[6]+board[7]+board[8])==3*player||(board[0]+board[3]+board[6])==3*player||(board[1]+board[4]+board[7])==3*player||(board[2]+board[5]+board[8])==3*player||(board[0]+board[4]+board[8])==3*player||(board[2]+board[4]+board[6])==3*player){
		return 1;
}
	return 0;
}

int boardfull(int *board){
	for(int x = 0; x<9; x++){
		if(board[x]==0){
			return 0;
		}
	}
	return 1;

}

int winpts(int *board, int turn, int * depth ){
	if(win(board,turn*-1)==1){
				return 10*turn*-1;
	}
	if(boardfull(board)==1){
				return 0;
	}
	int min = INT_MAX;
	int max = INT_MIN;
	int d_max_c = INT_MAX;
	int d_min_c = INT_MAX;
		for(int x = 0; x<9; x++){
			
			
			if(board[x]==0){
				board[x] = turn;
			}else{
				continue;
			}
			int d_n = *depth + 1;
			int g = winpts(board,turn*-1,&d_n);
			if(max==g){
				if(d_n<d_max_c){
					d_max_c = d_n;
				}
			}
			if(min==g){
				if(d_n<d_min_c){
					d_min_c = d_n;
				}
			}
			if(min>g){
				min = g;
				d_min_c = d_n;
			}
			if(max<g){
				max = g;
				d_max_c = d_n;
			}
			board[x] = 0;

		}



	if(turn==human){
		*depth = d_min_c;
		return min;
	}
	*depth = d_max_c;
	return max;

}

void computerdecision(int* board){
	int max_pos = 0;
	
	int max_pts = INT_MIN;
	int depth = INT_MAX;
	for(int x = 0; x<9; x++){
		if(board[x]==0){
			board[x]= computer;
		}else{
			continue;
		}
		int d = 1;
		int p = winpts(board,human,&d);
		if(p==max_pts){
			if(depth>d){
				depth = d;
				max_pos = x;
			}
		}
		if(p>max_pts){
			max_pts = p;
			max_pos = x;
			depth = d;
		}
		board[x]=0;

	}
	board[max_pos] = computer;

}
void printboard(int*board){
	printf("|");
	for(int x = 0; x<3; x++){
		if(board[x]==computer){printf("O|");} else if(board[x]==human) {printf("X|");}else{printf("%d|",x+1);}}
	printf("\n--------\n");
printf("|");
	for(int x = 3; x<6; x++){
		if(board[x]==computer){printf("O|");} else if(board[x]==human) {printf("X|");}else{printf("%d|",x+1);}}
	printf("\n--------\n");
	 printf("|");
	for(int x = 6; x<9; x++){
		if(board[x]==computer){printf("O|");} else if(board[x]==human) {printf("X|");}else{printf("%d|",x+1);}}
	printf("\n");
}
void humandecision(int *board){
	int x = 0;
	while(x>9||x<1||board[x-1]!=0){
	printf("enter: \n");
	scanf("%d",&x);
	}
	board[x-1]= human;
}
//int end(char player);
int game(int turn){
	int x[] = {0,0,0,0,0,0,0,0,0};
	
	if(turn!=1&&turn!=2){
		printf("Goodbye\n");
		return 0;
	}
	if(turn == 2){
		computerdecision(x);
		printboard(x);
	}else{
		printboard(x);
	}
	while((win(x,computer)!=1&&win(x,human)!=1)&&boardfull(x)!=1){
		humandecision(x);
		printboard(x);
			if(win(x,computer)==1){
				printf("computer wins\n");
				return 0;
			}else if(win(x,human)==1){
				printf("human wins\n");
				return 0;
			}else if(boardfull(x)==1){

				printf("it's a draw\n");
				return 0;
			}

		printf("\n\n");
		computerdecision(x);
		printboard(x);

	}
	if(win(x,computer)==1){
		printf("computer wins\n");
		return 0;
	}
 if(win(x,human)==1){
		printf("human wins\n");
		return 0;
	}
		printf("its a draw\n");
	
	return 0;
}
int main(){
		printf("Press 1, first turn will be  yours or 2, first turn will be the computer's\n");
		int x = 0;
		scanf("%d",&x);

		game(x);
	return 0;
}


