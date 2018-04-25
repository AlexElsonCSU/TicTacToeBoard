/**
 * Unit Tests for TicTacToeBoard
**/

#include <gtest/gtest.h>
#include "TicTacToeBoard.h"
 
class TicTacToeBoardTest : public ::testing::Test
{
	protected:
		TicTacToeBoardTest(){} //constructor runs before each test
		virtual ~TicTacToeBoardTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

//EXAMPLE TEST FORMAT
TEST(TicTacToeBoardTest, sanityCheck)
{
	TicTacToeBoard ttt;
	ASSERT_TRUE( ttt.toggleTurn() );
}

TEST(TicTacToeBoardTest, PlaceOutOfBounds)
{
	TicTacToeBoard ttt;
	ASSERT_TRUE( ttt.placePiece(4,-1) == Invalid );
}

TEST(TicTacToeBoardTest, PlaceOutOfBounds2)
{
	TicTacToeBoard ttt;
	ASSERT_TRUE( ttt.placePiece(1,-10) == Invalid );
}


TEST(TicTacToeBoardTest, GetOutOfBounds)
{
	TicTacToeBoard ttt;
	ASSERT_FALSE( ttt.placePiece(4,-1) != Invalid );
}

TEST(TicTacToeBoardTest, SwitchTurn)
{
	TicTacToeBoard ttt;
	ttt.placePiece(1,1);
	ttt.placePiece(1,2);
	ASSERT_FALSE( ttt.toggleTurn() == X );
}

TEST(TicTacToeBoardTest, NotOver)
{
	TicTacToeBoard ttt;
	ASSERT_TRUE( ttt.getWinner() == Invalid );
}

TEST(TicTacToeBoardTest, PlaceOnTop)
{
	TicTacToeBoard ttt;
	ttt.placePiece(0,0); //X
	ttt.placePiece(0,0); //O
	ASSERT_TRUE( ttt.placePiece(0,0) == X );
}

TEST(TicTacToeBoardTest, GetPiece)
{
	TicTacToeBoard ttt;
	ttt.placePiece(0,0); //X
	ASSERT_TRUE( ttt.getPiece(0,0) == X );
}

TEST(TicTacToeBoardTest, GetPieceOutOfBounds)
{
	TicTacToeBoard ttt;
	ttt.placePiece(-1,0); //X
	ASSERT_FALSE( ttt.getPiece(-1,0) == X );
}

TEST(TicTacToeBoardTest, WinnerX)
{
	TicTacToeBoard ttt;
	ttt.placePiece(0,0); //X
	ttt.placePiece(0,1); //O
	ttt.placePiece(1,0); //X
	ttt.placePiece(1,1); //O
	ttt.placePiece(2,0); //X
	ASSERT_TRUE( ttt.getWinner() == X );
}

TEST(TicTacToeBoardTest, WinnerVertical)
{
	TicTacToeBoard ttt;
	ttt.placePiece(0,0); //X
	ttt.placePiece(1,0); //O
	ttt.placePiece(0,1); //X 
	ttt.placePiece(2,0); //O
	ttt.placePiece(0,2); //X
	ASSERT_TRUE( ttt.getWinner() == X );
}

TEST(TicTacToeBoardTest, WonNoMoreChangeTurn)
{
	TicTacToeBoard ttt;
	ttt.placePiece(0,0); //X
	ttt.placePiece(0,1); //O
	ttt.placePiece(1,0); //X 
	ttt.placePiece(1,1); //O
	ttt.placePiece(2,0); //X
	
	ttt.placePiece(2,0); //X
	ASSERT_FALSE( ttt.toggleTurn() == X );
}


TEST(TicTacToeBoardTest, DiagonalWin)
{
	TicTacToeBoard ttt;
	ttt.placePiece(0,0); //X
	ttt.placePiece(2,0); //O
	ttt.placePiece(1,0); //X 
	ttt.placePiece(1,1); //O
	ttt.placePiece(2,2); //X
	ttt.placePiece(0,2); //O
	ASSERT_TRUE( ttt.getWinner() == O );
}

TEST(TicTacToeBoardTest, WinnerDiagonalRightToLeft)
{
	TicTacToeBoard ttt;
	ttt.placePiece(0,0); //X
	ttt.placePiece(1,0); //O
	ttt.placePiece(0,1); //X 
	ttt.placePiece(2,0); //O
	ttt.placePiece(0,2); //X
	ASSERT_TRUE( ttt.getWinner() == X );
}



TEST(TicTacToeBoardTest, FilledBoardNoWinner)
{
	TicTacToeBoard ttt;
	ttt.placePiece(0,0);
	ttt.placePiece(1,0);
	ttt.placePiece(2,0);
	
	ttt.placePiece(0,1);
	ttt.placePiece(1,1);
	ttt.placePiece(0,2);
	
	ttt.placePiece(1,2);
	ttt.placePiece(2,2);
	ttt.placePiece(2,1);
	ASSERT_TRUE( ttt.getWinner() == Blank );
}


TEST(TicTacToeBoardTest, AlmostFilled)
{
	TicTacToeBoard ttt;
	ttt.placePiece(0,0);
	ttt.placePiece(1,0);
	ttt.placePiece(2,0);
	
	ttt.placePiece(0,1);
	ttt.placePiece(1,1);
	ttt.placePiece(0,2);
	
	ttt.placePiece(1,2);
	ttt.placePiece(2,2);
	//ttt.placePiece(2,1);
	ASSERT_FALSE( ttt.getWinner() == Blank );
}
