//
//  main.c
//  eightQueens
//
//  Created by Benjamin.Field on 16/5/15.
//  Copyright © 2016年 Benjamin.Field. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void putChess(int line);
int isItRight(int line);
void printChessBoard(void);

/* 修改CHESSES的值可以解出任意个皇后的摆放问题 */
#define CHESSES 8

int chessBoard[CHESSES];

int main(void) {
    putChess(0);
    return 0;
}

/* 将棋子放入棋盘 */
void putChess(int line){
    int i;
    for (i=0; i<CHESSES; i++) {
        chessBoard[line]=i;
        /* 此时棋子放到第line行，若布局不满足要求，不必继续放子 */
        if (isItRight(line)==1) {
            /* 此时棋盘布局满足要求，如果已经摆放到最后一行，则打印，否则继续往下一行填子 */
            if (line==CHESSES-1)printChessBoard();
            else putChess(line+1);
        }
    }
}

/* 检测第line行与上面的棋子是否符合要求 */
int isItRight(int line){
    int i;
    for (i=0; i<line; i++)
        if (chessBoard[i]==chessBoard[line] || (line-i)==abs(chessBoard[i]-chessBoard[line]))
            return 0;
    return 1;
}

/* 打印解法 */
void printChessBoard(void){
    static int count=0;
    count++;
    printf("第%d种解法：\n",count);
    int i,j;
    for (i=0; i<CHESSES; i++) {
        for (j=0; j<CHESSES; j++) {
            if (chessBoard[i]!=j)printf("[ ]");
            else printf("[Q]");
        }
        printf("\n");
    }
    printf("\n");
}