#include "TicTacToeBoard.h"
#include <iostream>
/**
 * Class for representing a 3x3 Tic-Tac-Toe game board, using the Piece enum
 * to represent the spaces on the board.
**/

//Constructor sets an empty board and specifies it is X's turn first
TicTacToeBoard::TicTacToeBoard()
{
  turn = X;
  gameOver = false;
  for(int i=0; i<BOARDSIZE; i++)
    for(int j=0; j<BOARDSIZE; j++)
      board[i][j] = Blank;

}

/**
 * Switches turn member variable to represent whether it's X's or O's turn
 * and returns whose turn it is
**/
Piece TicTacToeBoard::toggleTurn()
{
  if (turn == X){
    turn = O;
    return turn;
  }
  turn = X;
  return turn;
  //return Invalid;
}

/**
 * Places the piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. placePiece does 
 * NOT allow to place a piece in a location where there is already a piece.
 * In that case, placePiece just returns what is already at that location. 
 * Out of bounds coordinates return the Piece Invalid value. When the game
 * is over, no more pieces can be placed so attempting to place a piece
 * should neither change the board nor change whose turn it is.
**/ 
Piece TicTacToeBoard::placePiece(int row, int column)
{
  if (gameOver == true){
    return Invalid;
  }
  
  if (row > 2 || row < 0 || column > 2 || column < 0){
    return Invalid;
  }
  
  if (board[row][column] != Blank){
    return board[row][column];
  }
    
  board[row][column] = turn;

  for (int n = 0; n < 3; n++){
    if (board[n][0] == turn && board[n][1] == turn && board[n][2] == turn){
      gameOver = true;
    }
  }
  for (int n = 0; n < 3; n++){
    if (board[0][n] == turn && board[1][n] == turn && board[2][n] == turn){
      gameOver = true;
    }
  }
  if (board[0][0] == turn && board[1][1] == turn && board[2][2] == turn){
    gameOver = true;
  }
  if (board[2][0] == turn && board[1][1] == turn && board[0][2] == turn){
    gameOver = true;
  }
  
  
  if (gameOver == false){
    toggleTurn();
  }
    
  return board[row][column];
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece TicTacToeBoard::getPiece(int row, int column)
{
  if (row > 2 || row < 0 || column > 2 || column < 0){
    return Invalid;
  }
  return board[row][column];
  
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won.
**/
Piece TicTacToeBoard::getWinner()
{
  if (gameOver == true){
    return turn;
  }
  int a = 0;
  for(int i=0; i<BOARDSIZE; i++){
    for(int j=0; j<BOARDSIZE; j++){
      if (board[i][j] == Blank){
        a = 1;
      }
    }
  }
  if (a == 0){
    return Blank;
  }
  return Invalid;
}
