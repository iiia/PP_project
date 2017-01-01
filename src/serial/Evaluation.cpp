#include <iostream>

using namespace std;

#include "ChessBoard.hpp"

#define WHITE 0
#define BLACK 1

int PieceTable[8][64];

PieceTable[ept_empty]={0}
PieceTable[ept_wpawn]	=	{
						 	   0,   0,   0,   0,   0,   0,   0,   0,
							  50,  50,  50,  50,  50,  50,  50,  50,
							  10,  10,  20,  30,  30,  20,  10,  10,
							   5,   5,  10,  25,  25,  10,   5,   5,
							   0,   0,   0,  20,  20,   0,   0,   0,
							   5,  -5, -10,   0,   0, -10,  -5,   5,
							   5,  10,  10, -20, -20,  10,  10,   5,
							   0,   0,   0,   0,   0,   0,   0,   0  
							}
PieceTable[ept_bpawn]	=	{
						 	   0,   0,   0,   0,   0,   0,   0,   0,
							  50,  50,  50,  50,  50,  50,  50,  50,
							  10,  10,  20,  30,  30,  20,  10,  10,
							   5,   5,  10,  25,  25,  10,   5,   5,
							   0,   0,   0,  20,  20,   0,   0,   0,
							   5,  -5, -10,   0,   0, -10,  -5,   5,
							   5,  10,  10, -20, -20,  10,  10,   5,
							   0,   0,   0,   0,   0,   0,   0,   0  
							}
//PieceTable[epc_bpaen]={0}
PieceTable[ept_knight]	=	{
							-50, -40, -30, -30, -30, -30, -40, -50,
							-40, -20,   0,   0,   0,   0, -20, -40,
							-30,   0,  10,  15,  15,  10,   0, -30,
							-30,   5,  15,  20,  20,  15,   0, -30,
							-30,   0,  15,  20,  20,  15,   0, -30,
							-30,   5,  10,  15,  15,  10,   5, -30,
							-40, -20,   0,   5,   5,   0, -20, -40,
							-50, -40, -30, -30, -30, -30, -40, -50
							}
PieceTable[ept_bishop]	=	{
							-20, -10, -10, -10, -10, -10, -10, -20,
							-10,   0,   0,   0,   0,   0,   0, -10,
							-10,   0,   5,  10,  10,   5,   0, -10,
							-10,   5,   5,  10,  10,   5,   5, -10,
							-10,   0,  10,  10,  10,  10,   0, -10,
							-10,  10,  10,  10,  10,  10,  10, -10,
							-10,   5,   0,   0,   0,   0,   5, -10,
							-20, -10, -10, -10, -10, -10, -10, -20
							}
PieceTable[ept_rook]	=	{
							  0,   0,   0,   0,   0,   0,   0,   0,
							  5,  10,  10,  10,  10,  10,  10,   5,
							 -5,   0,   0,   0,   0,   0,   0,  -5,
							 -5,   0,   0,   0,   0,   0,   0,  -5,
							 -5,   0,   0,   0,   0,   0,   0,  -5,
							 -5,   0,   0,   0,   0,   0,   0,  -5,
							 -5,   0,   0,   0,   0,   0,   0,  -5,
							  0,   0,   0,   5,   5,   0,   0,   0
							}
PieceTable[ept_queen]	=	{
							-20, -10, -10,  -5,  -5, -10, -10, -20,
							-10,   0,   0,   0,   0,   0,   0, -10,
							-10,   0,   5,   5,   5,   5,   0, -10,
							 -5,   0,   5,   5,   5,   5,   0,  -5,
							  0,   0,   5,   5,   5,   5,   0,  -0,
							-10,   5,   5,   5,   5,   5,   0, -10,
							-10,   0,   5,   0,   0,   0,   0, -10,
							-20, -10, -10,  -5,  -5, -10, -10, -20	
							}
//king middle game
PieceTable[ept_king]	=	{
							-30, -40, -40, -50, -50, -40, -40, -30,
							-30, -40, -40, -50, -50, -40, -40, -30,
							-30, -40, -40, -50, -50, -40, -40, -30,
							-30, -40, -40, -50, -50, -40, -40, -30,
							-20, -30, -30, -40, -40, -30, -30, -20,
							-10, -20, -20, -20, -20, -20, -20, -10,
							 20,  20,   0,   0,   0,   0,  20,  20,
							 20,  30,  10,   0,   0,  10,  30,  20
							}

int ChessBoard::eval(int color){
	int eval=0;
	if(color == WHITE){
		for(int i = 0 ; i < 64 ; i++){
			if(boardMap[i] < 8){
				eval += PieceTable[boardMap[i]][i];
			}else {
				eval -= PieceTable[boardMap[i] - 8][i];
			}
		}
	}else if(color == BLACK){
		for(int i = 0 ; i < 64 ; i++){
			if(boardMap[i] < 8){
				eval -= PieceTable[boardMap[i]][i];
			}else {
				eval += PieceTable[boardMap[i] - 8][i];
			}
		}
	}
	return eval;
}
