//
//  main.c
//  eightQueens - onlyOneVariable
//
//  Created by Benjamin.Field on 16/5/15.
//  Copyright © 2016年 Benjamin.Field. All rights reserved.
//

#include <stdio.h>

void creatChessBoard(void);
int isItRight(void);
void printChessBoard(void);
char * Chess(unsigned long int line,int num);

#define LINE_A (chessBoard>>56&255)
#define LINE_B (chessBoard>>48&255)
#define LINE_C (chessBoard>>40&255)
#define LINE_D (chessBoard>>32&255)
#define LINE_E (chessBoard>>24&255)
#define LINE_F (chessBoard>>16&255)
#define LINE_G (chessBoard>>8&255)
#define LINE_H (chessBoard&255)

#define CHESS_BOARD_INITIAL 72057594037927936

#define LINE_A_INITIAL 72057594037927936
#define LINE_B_INITIAL 281474976710656
#define LINE_C_INITIAL 1099511627776
#define LINE_D_INITIAL 4294967296
#define LINE_E_INITIAL 16777216
#define LINE_F_INITIAL 65536
#define LINE_G_INITIAL 256
#define LINE_H_INITIAL 1
/* 长整型数字有8字节即64位，一位代表棋盘上的一个格子正好够，整个程序只有一个变量 */
unsigned long int chessBoard=CHESS_BOARD_INITIAL;

int main(void) {
    creatChessBoard();
    return 0;
}

void creatChessBoard(void){
    while (LINE_A!=0) {
        chessBoard=chessBoard+LINE_B_INITIAL;
        while (LINE_B!=0) {
            chessBoard=chessBoard+LINE_C_INITIAL;
            while (LINE_C!=0) {
                chessBoard=chessBoard+LINE_D_INITIAL;
                while (LINE_D!=0) {
                    chessBoard=chessBoard+LINE_E_INITIAL;
                    while (LINE_E!=0) {
                        chessBoard=chessBoard+LINE_F_INITIAL;
                        while (LINE_F!=0) {
                            chessBoard=chessBoard+LINE_G_INITIAL;
                            while (LINE_G!=0) {
                                chessBoard=chessBoard+LINE_H_INITIAL;
                                while (LINE_H!=0) {
                                    if (isItRight())
                                        printChessBoard();
                                    chessBoard=chessBoard+(LINE_H*2-LINE_H);
                                }
                                chessBoard=chessBoard-LINE_G_INITIAL;
                                chessBoard=chessBoard+((LINE_G*2-LINE_G)<<8);
                            }
                            chessBoard=chessBoard-LINE_F_INITIAL;
                            chessBoard=chessBoard+((LINE_F*2-LINE_F)<<16);
                        }
                        chessBoard=chessBoard-LINE_E_INITIAL;
                        chessBoard=chessBoard+((LINE_E*2-LINE_E)<<24);
                    }
                    chessBoard=chessBoard-LINE_D_INITIAL;
                    chessBoard=chessBoard+((LINE_D*2-LINE_D)<<32);
                }
                chessBoard=chessBoard-LINE_C_INITIAL;
                chessBoard=chessBoard+((LINE_C*2-LINE_C)<<40);
            }
            chessBoard=chessBoard-LINE_B_INITIAL;
            chessBoard=chessBoard+((LINE_B*2-LINE_B)<<48);
        }
        chessBoard=chessBoard-LINE_A_INITIAL;
        chessBoard=chessBoard+((LINE_A*2-LINE_A)<<56);
    }
}

int isItRight(void){
    if ((LINE_A+LINE_B+LINE_C+LINE_D+LINE_E+LINE_F+LINE_G+LINE_H)==255
        && LINE_H*2!=LINE_G && LINE_G*2!=LINE_H && LINE_H*4!=LINE_F && LINE_F*4!=LINE_H
        && LINE_H*8!=LINE_E && LINE_E*8!=LINE_H && LINE_H*16!=LINE_D && LINE_D*16!=LINE_H
        && LINE_H*32!=LINE_C && LINE_C*32!=LINE_H && LINE_H*64!=LINE_B && LINE_B*64!=LINE_H
        && LINE_H*128!=LINE_A && LINE_A*128!=LINE_H
        
        && LINE_G*2!=LINE_F && LINE_F*2!=LINE_G && LINE_G*4!=LINE_E && LINE_E*4!=LINE_G
        && LINE_G*8!=LINE_D && LINE_D*8!=LINE_G && LINE_G*16!=LINE_C && LINE_C*16!=LINE_G
        && LINE_G*32!=LINE_B && LINE_B*32!=LINE_G && LINE_G*64!=LINE_A && LINE_A*64!=LINE_G
        
        && LINE_F*2!=LINE_E && LINE_E*2!=LINE_F && LINE_F*4!=LINE_D && LINE_D*4!=LINE_F
        && LINE_F*8!=LINE_C && LINE_C*8!=LINE_F && LINE_F*16!=LINE_B && LINE_B*16!=LINE_F
        && LINE_F*32!=LINE_A && LINE_A*32!=LINE_F
        
        && LINE_E*2!=LINE_D && LINE_D*2!=LINE_E && LINE_E*4!=LINE_C && LINE_C*4!=LINE_E
        && LINE_E*8!=LINE_B && LINE_B*8!=LINE_E && LINE_E*16!=LINE_A && LINE_A*16!=LINE_E
        
        && LINE_D*2!=LINE_C && LINE_C*2!=LINE_D && LINE_D*4!=LINE_B && LINE_B*4!=LINE_D
        && LINE_D*8!=LINE_A && LINE_A*8!=LINE_D
        
        && LINE_C*2!=LINE_B && LINE_B*2!=LINE_C && LINE_C*4!=LINE_A && LINE_A*4!=LINE_C
        
        && LINE_B*2!=LINE_A && LINE_A*2!=LINE_B)
        return 1;
    return 0;
}

void printChessBoard(void){
    printf("%s%s%s%s%s%s%s%s\n",Chess(LINE_A, 1),Chess(LINE_A, 2),Chess(LINE_A, 4),Chess(LINE_A, 8),Chess(LINE_A, 16),Chess(LINE_A, 32),Chess(LINE_A, 64),Chess(LINE_A, 128));
    printf("%s%s%s%s%s%s%s%s\n",Chess(LINE_B, 1),Chess(LINE_B, 2),Chess(LINE_B, 4),Chess(LINE_B, 8),Chess(LINE_B, 16),Chess(LINE_B, 32),Chess(LINE_B, 64),Chess(LINE_B, 128));
    printf("%s%s%s%s%s%s%s%s\n",Chess(LINE_C, 1),Chess(LINE_C, 2),Chess(LINE_C, 4),Chess(LINE_C, 8),Chess(LINE_C, 16),Chess(LINE_C, 32),Chess(LINE_C, 64),Chess(LINE_C, 128));
    printf("%s%s%s%s%s%s%s%s\n",Chess(LINE_D, 1),Chess(LINE_D, 2),Chess(LINE_D, 4),Chess(LINE_D, 8),Chess(LINE_D, 16),Chess(LINE_D, 32),Chess(LINE_D, 64),Chess(LINE_D, 128));
    printf("%s%s%s%s%s%s%s%s\n",Chess(LINE_E, 1),Chess(LINE_E, 2),Chess(LINE_E, 4),Chess(LINE_E, 8),Chess(LINE_E, 16),Chess(LINE_E, 32),Chess(LINE_E, 64),Chess(LINE_E, 128));
    printf("%s%s%s%s%s%s%s%s\n",Chess(LINE_F, 1),Chess(LINE_F, 2),Chess(LINE_F, 4),Chess(LINE_F, 8),Chess(LINE_F, 16),Chess(LINE_F, 32),Chess(LINE_F, 64),Chess(LINE_F, 128));
    printf("%s%s%s%s%s%s%s%s\n",Chess(LINE_G, 1),Chess(LINE_G, 2),Chess(LINE_G, 4),Chess(LINE_G, 8),Chess(LINE_G, 16),Chess(LINE_G, 32),Chess(LINE_G, 64),Chess(LINE_G, 128));
    printf("%s%s%s%s%s%s%s%s\n\n",Chess(LINE_H, 1),Chess(LINE_H, 2),Chess(LINE_H, 4),Chess(LINE_H, 8),Chess(LINE_H, 16),Chess(LINE_H, 32),Chess(LINE_H, 64),Chess(LINE_H, 128));
}

char *Chess(unsigned long int line,int num){
    if ((line&num)==0)
        return "[ ]";
    return "[Q]";
}