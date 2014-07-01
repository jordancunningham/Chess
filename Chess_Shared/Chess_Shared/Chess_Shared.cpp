///***************************************************///
///                      CHESS!                       ///
///                                                   ///
///                        by                         ///
///                Jordan Cunningham                  ///
///             Arizona State University              ///
///                                                   ///
/// Please feel free to use or redistribute my crappy ///
///             code at your own peril.               ///
///                                                   ///
///                                                   ///
///***************************************************///

#include<iostream>
#include "Piece.h"
#include "Square.h"
#include <sstream>
#include <ctype.h>
#include <cmath>
#include <Windows.h>

using namespace std;

void playGame();
bool validateMoveFormat(string);
bool validateMoveRules(string, Square [8][8], int);
void Display(Square [8][8]);
int main(){




	playGame();





}

void playGame(){

	//*************************************************//
	//*****************Game Setup**********************//
	//*************************************************//

	Square board[8][8];	//declare the chess board (an array of Squares)

	Piece k10("King", 1);		 //the first digit indicates which player's piece it is followed by the piece's unique number
	Piece q10("Queen", 1);
	Piece r10("Rook", 1);
	Piece r11("Rook", 1);		//the pieces are designated solely by their name; a string. 
	Piece b10("Bishop", 1);	//string comparisons must be used to figure out which piece is which.
	Piece b11("Bishop", 1);
	Piece kn10("Knight", 1);
	Piece kn11("Knight", 1);
	Piece p10("Pawn", 1);
	Piece p11("Pawn", 1);
	Piece p12("Pawn", 1);
	Piece p13("Pawn", 1);
	Piece p14("Pawn", 1);
	Piece p15("Pawn", 1);
	Piece p16("Pawn", 1);
	Piece p17("Pawn", 1);


	Piece k20("King", 2);		 
	Piece q20("Queen", 2);
	Piece r20("Rook", 2);
	Piece r21("Rook", 2);		
	Piece b20("Bishop", 2);	
	Piece b21("Bishop", 2);
	Piece kn20("Knight", 2);
	Piece kn21("Knight", 2);
	Piece p20("Pawn", 2);
	Piece p21("Pawn", 2);
	Piece p22("Pawn", 2);
	Piece p23("Pawn", 2);
	Piece p24("Pawn", 2);
	Piece p25("Pawn", 2);
	Piece p26("Pawn", 2);
	Piece p27("Pawn", 2);

	//placing the pieces on the board
	board[0][0].piece = &r10;
	board[0][1].piece = &kn10;
	board[0][2].piece = &b10;
	board[0][3].piece = &q10;
	board[0][4].piece = &k10;
	board[0][5].piece = &b11;
	board[0][6].piece = &kn11;
	board[0][7].piece = &r11;

	board[1][0].piece = &p10;
	board[1][1].piece = &p11;
	board[1][2].piece = &p12;
	board[1][3].piece = &p12;
	board[1][4].piece = &p13;
	board[1][5].piece = &p14;
	board[1][6].piece = &p15;
	board[1][7].piece = &p16;

	//player2's pieces...
	board[7][0].piece = &r20;
	board[7][1].piece = &kn20;
	board[7][2].piece = &b20;
	board[7][3].piece = &q20;
	board[7][4].piece = &k20;
	board[7][5].piece = &b21;
	board[7][6].piece = &kn21;
	board[7][7].piece = &r21;

	board[6][0].piece = &p20;
	board[6][1].piece = &p21;
	board[6][2].piece = &p22;
	board[6][3].piece = &p22;
	board[6][4].piece = &p23;
	board[6][5].piece = &p24;
	board[6][6].piece = &p25;
	board[6][7].piece = &p26;

	//*************************************************//
	//*************************************************//
	//*************************************************//

	//supposed to resize window but doesn't work for some reason...
	SMALL_RECT windowSize = {0, 0, 400, 400};
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize);



	int currentPlayer = 2;	//start at 2 so that the switch makes it p1's turn first...

	int p1Pieces = 16;	//these will be used to determine when the game is over (# of pieces = 0 for either player)
	int p2Pieces = 16;

	string move;	//move to be parsed

	/**********///MAIN GAME LOOP///**********/
	while(true){	

		//after every move we switch the player...
		
		if(currentPlayer == 1)
			currentPlayer = 2;
		else
			currentPlayer = 1;
			

		//currentPlayer = 1;	//CHANGE FOR REAL THING...

		system("cls");

		Display(board);
		
		//cout<<"For help enter \'h\'"<<endl<<endl;
		cout<<"P"<<currentPlayer<<" please enter your move: ";
		getline(cin, move);
	
		while(validateMoveFormat(move) == false){
		
			cout<<"Invalid move. Please re-enter."<<endl;
			getline(cin, move);
		
		}	

		while(validateMoveRules(move, board, currentPlayer) == false){
		
			cout<<"Please re-enter your move."<<endl;
			getline(cin, move);
		
		}
	}
}

//this function makes sure that the user has entered a potentially correct move based on formatting alone
bool validateMoveFormat(string move){

		//a valid move has 8 characters
		if(move.length() != 8){
			
			return false;
		
		}

		//this basically just checkes each of the characters in the 3 sections of the move
		//format to ensure that the user has entered a valid range of inputs
		if(move[0] != 'a' && move[0] != 'b' && move[0] != 'c' && move[0] != 'd' && 
			move[0] != 'e' && move[0] != 'f' && move[0] != 'g' && move[0] != 'h'){
		
			return false;
		
		
		
		}
			
		//make sure the number of the board index is valid	
		if(move[1] != '0' && move[1] != '1' && move[1] != '2' && move[1] != '3' && move[1] != '4'
			&& move[1] != '5' && move[1] != '6' && move[1] != '7'){
			
			return false;
				
		}
			
		//this is sort of unecessary...but I think it adds consistency to the game	
		if(move[3] != 't' || move[4] != 'o'){
			
			return false;
			
			}

		//valid ranger of letters for destination index
		if(move[6] != 'a' && move[6] != 'b' && move[6] != 'c' && move[6] != 'd' && move[6] != 'e' 
			&& move[6] != 'f' && move[6] != 'g' && move[6] != 'h'){
			
			return false;
			
			}
			
		//valid range of numbers for destination index
		if(move[7] != '0' && move[7] != '1' && move[7] != '2' && move[7] != '3' && move[7] != '4'
			&& move[7] != '5' && move[7] != '6' && move[7] != '7'){

			return false;
		
		}

		else return true;
}

//this function performs all chess rules validation of the previously correctly-formatted move
bool validateMoveRules(string move, Square board[8][8], int currentPlayer){

	//first things first: convert move sections to useable format (actual ints n' stuff)

	stringstream stream;

	int l1;	//l1 is the number equivalent of the letter they enter...see the switch statements below
	int n1;

	stream<<move[1];	//this should convert the char number to an int number
	stream>>n1;

	stream.clear();	//clear that bish

	int l2;
	int n2;

	stream<<move[7];
	stream>>n2;
	
	//these "ifs" just convert the letter to a number so it can be used
	//as an index
	if(move[0] == 'a')
		l1 = 0;
	else if(move[0] == 'b')
		l1 = 1;
	else if(move[0] == 'c')
		l1 = 2;
	else if(move[0] == 'd')
		l1 = 3;
	else if(move[0] == 'e')
		l1 = 4;
	else if(move[0] == 'f')
		l1 = 5;
	else if(move[0] == 'g')
		l1 = 6;
	else
		l1 = 7;

	
	if(move[6] == 'a')
		l2 = 0;
	else if(move[6] == 'b')
		l2 = 1;
	else if(move[6] == 'c')
		l2 = 2;
	else if(move[6] == 'd')
		l2 = 3;
	else if(move[6] == 'e')
		l2 = 4;
	else if(move[6] == 'f')
		l2 = 5;
	else if(move[6] == 'g')
		l2 = 6;
	else
		l2 = 7;
		


	if(board[n1][l1].piece == nullptr){
	
		cout<<"There's no piece at the specified location."<<endl<<endl;
		return false;
	
	}

	//checks to see if the piece the player is trying to move is actually theirs (current player must match piece's player)
	if(board[n1][l1].piece != nullptr && currentPlayer != board[n1][l1].piece->player){

		cout<<"That's not your piece, bro."<<endl<<endl;

		return false;

	}

	//checks to see if the player has a friendly piece at the desired move location
	if(board[n2][l2].piece != nullptr && currentPlayer == board[n2][l2].piece->player){

		cout<<"You already have a piece there."<<endl<<endl;

		return false;
	}

	//X AND Y DIFFERENCES
	int rowDiff = n1-n2;
	int colDiff = l1-l2;
	//IMPORTANT

	//P1'S PAWN MOVEMENT RULES (YES, THEY ARE DIFFERENT DEPENDING ON THE PLAYER)
	if(board[n1][l1].piece->name.compare("Pawn") == 0 && currentPlayer == 1){

		//this is to take into account that pawns can move 2 spaces on their first move, but not after
		if(n1 != 1 && rowDiff <= -2){
		
			cout<<"Pawns can't move like that."<<endl<<endl;
			return false;	//false indicates invalid move...just in case I didn't specify that already...

		}

		//if it is the pawn's first move and they try to move like 12 spaces...
		else if(n1 == 1 && rowDiff < -2){
		
			cout<<"Pawns may move 2 spaces forward their first move."<<endl<<endl;
			return false;
		
		}

		//rowDiff must ALWAYS be negative...no backwards or side to side movement for pawns
		else if(rowDiff >= 0){
		
			cout<<"Pawns can't move like that."<<endl<<endl;
			return false;
		
		}
		
		//no matter what pawns can only move a maximum of one column over at a time
		else if(abs(colDiff) > 1){
		
			cout<<"Pawns can't move like that."<<endl<<endl;
			return false;
		
		}

		//if they try to move diagonally without there being an enemy piece there
		else if(abs(colDiff) == 1 && rowDiff == -1 && board[n2][l2].piece == nullptr){
		
			cout<<"There must be an enemy piece at "<<l2<<n2<<" for you to move there."<<endl<<endl;
			return false;

		}

		//if they try to move 1 space forward but there's an enemy there...
		else if(rowDiff == -1 && colDiff == 0 && board[n2][l2].piece != nullptr && board[n2][l2].piece->player == 2){
		
			cout<<"An enemy piece is blocking your move!"<<endl<<endl;
			return false;
		
		}

		//if they try to move diagonally to a space and there's an enemy piece there...
		else if(rowDiff == -1 && abs(colDiff) == 1 && board[n2][l2].piece->player == 2){

			cout<<"You have taken the enemy's "<<board[n2][l2].piece->name<<"!"<<endl<<endl;

			board[n2][l2].piece = board[n1][l1].piece;	//piece taken
			board[n1][l1].piece = nullptr;

			Sleep(2000);

			return true;
		
		}

		//valid forward move with no enemy pieces in the way...
		else{
		
			cout<<"Move successful!"<<endl<<endl;
			board[n2][l2].piece = board[n1][l1].piece;
			board[n1][l1].piece = nullptr;

			Sleep(2000);

			return true;
		
		}
	}

	//P2'S PAWN MOVEMENT RULES 
	else if(board[n1][l1].piece->name.compare("Pawn") == 0 && currentPlayer == 2){

		//this is to take into account that pawns can move 2 spaces on their first move, but not after
		if(n1 != 6 && rowDiff >= 2){
		
			cout<<"Pawns can't move like that."<<endl<<endl;
			return false;	//false indicates invalid move...just in case I didn't specify that already...

		}

		//if it is the pawn's first move and they try to move like 12 spaces...
		else if(n1 == 6 && rowDiff > 2){
		
			cout<<"Pawns may move 2 spaces forward their first move."<<endl<<endl;
			return false;
		
		}

		//rowDiff must ALWAYS be negative...no backwards or side to side movement for pawns
		else if(rowDiff <= 0){
		
			cout<<"Pawns can't move like that."<<endl<<endl;
			return false;
		
		}
		
		//no matter what pawns can only move a maximum of one column over at a time
		else if(abs(colDiff) > 1){
		
			cout<<"Pawns can't move like that."<<endl<<endl;
			return false;
		
		}

		//if they try to move diagonally without there being an enemy piece there
		else if(abs(colDiff) == 1 && rowDiff == 1 && board[n2][l2].piece == nullptr){
		
			cout<<"There must be an enemy piece at "<<l2<<n2<<" for you to move there."<<endl<<endl;
			return false;

		}

		//if they try to move 1 space forward but there's an enemy there...
		else if(rowDiff == 1 && colDiff == 0 && board[n2][l2].piece != nullptr && board[n2][l2].piece->player == 1){
		
			cout<<"An enemy piece is blocking your move!"<<endl<<endl;
			return false;
		
		}

		//if they try to move diagonally to a space and there's an enemy piece there...
		else if(rowDiff == 1 && abs(colDiff) == 1 && board[n2][l2].piece->player == 1){

			cout<<"You have taken the enemy's "<<board[n2][l2].piece->name<<"!"<<endl<<endl;

			board[n2][l2].piece = board[n1][l1].piece;	//piece taken
			board[n1][l1].piece = nullptr;

			Sleep(2000);

			return true;
		
		}

		//valid forward move with no enemy pieces in the way...
		else{
		
			cout<<"Move successful!"<<endl<<endl;
			board[n2][l2].piece = board[n1][l1].piece;
			board[n1][l1].piece = nullptr;

			Sleep(2000);

			return true;
		
		}
	}

	else if(board[n1][l1].piece->name.compare("King") == 0){
	
		//if they try to move more than one space at a time...
		if(abs(rowDiff) > 1 || abs(colDiff) > 1){
		
			cout<<"Kings may only move one space at a time."<<endl<<endl;
			return false;
		
		}
	
	
		if(board[n2][l2].piece != nullptr && board[n2][l2].piece->player != currentPlayer){
		
			cout<<"You have taken the enemy's "<<board[n2][l2].piece->name<<"!"<<endl<<endl;

			board[n2][l2].piece = board[n1][l1].piece;	//piece taken
			board[n1][l1].piece = nullptr;

			Sleep(2000);

			return true;
		
		}

		else{
		
			cout<<"Move successful!"<<endl<<endl;
			board[n2][l2].piece = board[n1][l1].piece;
			board[n1][l1].piece = nullptr;

			Sleep(2000);

			return true;
		
		}
	}


	else if(board[n1][l1].piece->name.compare("Queen") == 0){

		//cout<<"Inside the queen's if statement..."<<endl;

		//if they just try to move to some random spot
		if(abs(rowDiff) != abs(colDiff) && rowDiff != 0 && colDiff != 0){
		
			cout<<"Queens can do a lot of things, but they can't apparate."<<endl<<endl;
			return false;
		
		}

		//COLLISION CHECKING IF STATEMENTS//
		if(rowDiff > 0 && colDiff > 0){

			//cout<<"rowDiff > 0 && colDiff > 0"<<endl<<endl;
		
			for(int i = n1-1; i > n2; i--){
			
				for(int j = l1-1; j > l2; j --){
				
					if(board[i][j].piece != nullptr){
					
						cout<<"There's a piece blocking your move!"<<endl<<endl;
						return false;
					
					}
				}
			}
		}

		else if(rowDiff < 0 && colDiff < 0){

			//cout<<"rowDiff < 0 && colDiff < 0"<<endl<<endl;
		
			for(int i = n1+1; i < n2; i++){
			
				for(int j = l1+1; j < l2; j ++){
				
					if(board[i][j].piece != nullptr){
					
						cout<<"There's a piece blocking your move!"<<endl<<endl;
						return false;
					
					}
				}
			}
		}

		else if(rowDiff > 0 && colDiff < 0){

			//cout<<"rowDiff > 0 && colDiff < 0"<<endl<<endl;
		
			for(int i = n1-1; i > n2; i--){
			
				for(int j = l1+1; j < l2; j ++){
				
					if(board[i][j].piece != nullptr){
					
						cout<<"There's a piece blocking your move!"<<endl<<endl;
						return false;
					
					}
				}
			}
		}

		else if(rowDiff < 0 && colDiff > 0){

			//cout<<"rowDiff < 0 && colDiff > 0"<<endl<<endl;
		
			for(int i = n1+1; i < n2; i++){
			
				for(int j = l1-1; j > l2; j --){
				
					if(board[i][j].piece != nullptr){
					
						cout<<"There's a piece blocking your move!"<<endl<<endl;
						return false;
					
					}
				}
			}
		}

		else if(rowDiff == 0 && colDiff > 0){

			//cout<<"rowDiff == 0 && colDiff > 0"<<endl<<endl;
		
			for(int i = l1-1; i > l2; i--){
			
				if(board[n1][i].piece != nullptr){
				
					cout<<"There's a piece blocking your move!"<<endl<<endl;
					return false;
				
				}
			}
		}

		else if(rowDiff == 0 && colDiff < 0){

			//cout<<"rowDiff == 0 && colDiff < 0"<<endl<<endl;
		
			for(int i = l1+1; i < l2; i++){
			
				if(board[n1][i].piece != nullptr){
				
					cout<<"There's a piece blocking your move!"<<endl<<endl;
					return false;
				
				}
			}
		}

		else if(rowDiff > 0 && colDiff == 0){

			//cout<<"rowDiff > 0 && colDiff == 0"<<endl;
		
			for(int i = n1-1; i > n2; i--){
			
				if(board[i][l1].piece != nullptr){
				
					cout<<"There's a piece blocking your move!"<<endl<<endl;
					return false;
				
				}
			}
		}

		else if(rowDiff < 0 && colDiff == 0){

			//cout<<"rowDiff < 0 && colDiff == 0"<<endl<<endl;
		
			for(int i = n1+1; i < n2; i++){
			
				if(board[i][l1].piece != nullptr){
				
					cout<<"There's a piece blocking your move!"<<endl<<endl;
					return false;
				
				}
			}
		}

		//Sleep(5000);


		if(board[n2][l2].piece != nullptr && board[n2][l2].piece->player != currentPlayer){
		
			cout<<"You have taken the enemy's "<<board[n2][l2].piece->name<<"!"<<endl<<endl;

			board[n2][l2].piece = board[n1][l1].piece;	//piece taken
			board[n1][l1].piece = nullptr;

			Sleep(2000);

			return true;
		
		}

		else{
		
			cout<<"Move successful!"<<endl<<endl;
			board[n2][l2].piece = board[n1][l1].piece;
			board[n1][l1].piece = nullptr;

			Sleep(2000);

			return true;

		}
	}

	else if(board[n1][l1].piece->name.compare("Knight") == 0){
	
		//I think I'm rather clever for figuring this out...
		if(abs(rowDiff)*abs(colDiff) != 2){
		
			cout<<"Knights can't move like that."<<endl<<endl;
			return false;
		
		
		}
	
		if(board[n2][l2].piece != nullptr && board[n2][l2].piece->player != currentPlayer){
		
			cout<<"You have taken the enemy's "<<board[n2][l2].piece->name<<"!"<<endl<<endl;

			board[n2][l2].piece = board[n1][l1].piece;	//piece taken
			board[n1][l1].piece = nullptr;

			Sleep(2000);

			return true;

		}

		else{
		
			cout<<"Move successful!"<<endl<<endl;
			board[n2][l2].piece = board[n1][l1].piece;
			board[n1][l1].piece = nullptr;

			Sleep(2000);

			return true;
	
		}
	}

	else if(board[n1][l1].piece->name.compare("Bishop") == 0){
	
		//just specifying diagonal movmement only
		if(abs(rowDiff) != abs(colDiff)){
			
			cout<<"Bishops can't move like that."<<endl;
			return false;
		
		}

		//COLLISION CHECKING IF STATEMENTS
		if(rowDiff > 0 && colDiff > 0){
		
			for(int i = n1-1; i > n2; i--){
			
				for(int j = l1-1; j > l2; j --){
				
					if(board[i][j].piece != nullptr){
					
						cout<<"There's a piece blocking your move!"<<endl<<endl;
						return false;
					
					}
				}
			}
		}

		else if(rowDiff < 0 && colDiff < 0){
		
			for(int i = n1+1; i < n2; i++){
			
				for(int j = l1+1; j < l2; j ++){
				
					if(board[i][j].piece != nullptr){
					
						cout<<"There's a piece blocking your move!"<<endl<<endl;
						return false;
					
					}
				}
			}
		}

		else if(rowDiff > 0 && colDiff < 0){
		
			for(int i = n1-1; i > n2; i--){
			
				for(int j = l1+1; j < l2; j ++){
				
					if(board[i][j].piece != nullptr){
					
						cout<<"There's a piece blocking your move!"<<endl<<endl;
						return false;
					
					}
				}
			}
		}

		else if(rowDiff < 0 && colDiff > 0){
		
			for(int i = n1+1; i < n2; i++){
			
				for(int j = l1-1; j > l2; j --){
				
					if(board[i][j].piece != nullptr){
					
						cout<<"There's a piece blocking your move!"<<endl<<endl;
						return false;
					
					}
				}
			}
		}

		//STANDARD PIECE TAKING CODE (SAME FOR ALL PIECES FOR P1)
		if(board[n2][l2].piece != nullptr && board[n2][l2].piece->player != currentPlayer){
		
			cout<<"You have taken the enemy's "<<board[n2][l2].piece->name<<"!"<<endl<<endl;

			board[n2][l2].piece = board[n1][l1].piece;	//piece taken
			board[n1][l1].piece = nullptr;

			Sleep(2000);

			return true;
		
		
		}

		else{
		
			cout<<"Move successful!"<<endl<<endl;
			board[n2][l2].piece = board[n1][l1].piece;
			board[n1][l1].piece = nullptr;

			Sleep(2000);

			return true;
		
		
		}
	}

	else if(board[n1][l1].piece->name.compare("Rook") == 0){
	
		if(rowDiff != 0 && colDiff != 0){
		
			cout<<"Rooks can't move like that."<<endl<<endl;
			return false;
		
		}

		//COLLISION CHECKING IF STATEMENTS
		if(rowDiff == 0 && colDiff > 0){
		
			for(int i = l1-1; i > l2; i--){
			
				if(board[n1][i].piece != nullptr){
				
					cout<<"There's a piece blocking your move!"<<endl<<endl;
					return false;
				
				}
			}
		}

		else if(rowDiff == 0 && colDiff < 0){
		
			for(int i = l1+1; i < l2; i++){
			
				if(board[n1][i].piece != nullptr){
				
					cout<<"There's a piece blocking your move!"<<endl<<endl;
					return false;
				
				}
			}
		}

		else if(rowDiff > 0 && colDiff == 0){
		
			for(int i = n1-1; i > n2; i--){
			
				if(board[i][l1].piece != nullptr){
				
					cout<<"There's a piece blocking your move!"<<endl<<endl;
					return false;
				
				}
			}
		}

		else if(rowDiff < 0 && colDiff == 0){
		
			for(int i = n1+1; i < n2; i++){
			
				if(board[i][l1].piece != nullptr){
				
					cout<<"There's a piece blocking your move!"<<endl<<endl;
					return false;
				
				}
			}
		}
	
		if(board[n2][l2].piece != nullptr && board[n2][l2].piece->player != currentPlayer){
		
			cout<<"You have taken the enemy's "<<board[n2][l2].piece->name<<"!"<<endl<<endl;

			board[n2][l2].piece = board[n1][l1].piece;	//piece taken
			board[n1][l1].piece = nullptr;

			Sleep(2000);

			return true;
		
		}

		else{
		
			cout<<"Move successful!"<<endl<<endl;
			board[n2][l2].piece = board[n1][l1].piece;
			board[n1][l1].piece = nullptr;

			Sleep(2000);

			return true;
		
		
		}
	}

	else return false;	

}


void Display(Square board[8][8]){

	char displayBoard[38][53] = {

	{' ', ' ', ' ', ' ', ' ', ' ', ' ', 'A', ' ', ' ', ' ', ' ', ' ', 'B', ' ', ' ', ' ', ' ', ' ', 'C', ' ', ' ', ' ', ' ', ' ', 'D', ' ', ' ', ' ', ' ', ' ', 'E', ' ', ' ', ' ', ' ', ' ', 'F', ' ', ' ', ' ', ' ', ' ', 'G', ' ', ' ', ' ', ' ', ' ', 'H', ' ', ' ', ' '},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}, 
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', '7', ' ', '#', ' ', ' ', 'R', ' ', ' ', '#', ' ', ' ', 'N', ' ', ' ', '#', ' ', ' ', 'B', ' ', ' ', '#', ' ', ' ', 'Q', ' ', ' ', '#', ' ', ' ', 'K', ' ', ' ', '#', ' ', ' ', 'B', ' ', ' ', '#', ' ', ' ', 'N', ' ', ' ', '#', ' ', ' ', 'R', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}, 
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', '6', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}, 
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', '5', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}, 
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', '4', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}, 
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', '3', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}, 
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', '2', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}, 
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', '1', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#', ' ', ' ', 'P', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}, 
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', '0', ' ', '#', ' ', ' ', 'R', ' ', ' ', '#', ' ', ' ', 'N', ' ', ' ', '#', ' ', ' ', 'B', ' ', ' ', '#', ' ', ' ', 'Q', ' ', ' ', '#', ' ', ' ', 'K', ' ', ' ', '#', ' ', ' ', 'B', ' ', ' ', '#', ' ', ' ', 'N', ' ', ' ', '#', ' ', ' ', 'R', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#'},
	{' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'}, 


};

	//"displayRow"...converts the standard board coordinates to display coordinates
	//i.e. the 0th row of the real board is equivalent to the 31st row of the display board just by how I've set it up
	int dR0 = 31;
	int dR1 = 27;
	int dR2 = 23;
	int dR3 = 19;
	int dR4 = 15;
	int dR5 = 11;
	int dR6 = 7;
	int dR7 = 3;

	//"displayColumn"
	int dC0 = 7;
	int dC1 = 13;
	int dC2 = 19;
	int dC3 = 25;
	int dC4 = 31;
	int dC5 = 37;
	int dC6 = 43;
	int dC7 = 49;

	int tempRow = 0;
	int tempColumn = 0;

	//updates real piece locations on the "display board"
	for(int i = 0; i < 8; i++){

		if(i == 0)
			tempRow = dR0;
		else if(i == 1)
			tempRow = dR1;
		else if(i == 2)
			tempRow = dR2;
		else if(i == 3)
			tempRow = dR3;
		else if(i == 4)
			tempRow = dR4;
		else if(i == 5)
			tempRow = dR5;
		else if(i == 6)
			tempRow = dR6;
		else
			tempRow = dR7;
		
		
	
	for(int j = 0; j < 8; j++){
		
		if(j == 0)
			tempColumn = dC0;
		else if(j == 1)
			tempColumn = dC1;
		else if(j == 2)	
			tempColumn = dC2;
		else if(j == 3)
			tempColumn = dC3;
		else if(j == 4)
			tempColumn = dC4;
		else if(j == 5)
			tempColumn = dC5;
		else if(j == 6)
			tempColumn = dC6;
		else
			tempColumn = dC7;
			
		//update display board pieces to match the real board
		if(board[i][j].piece == nullptr)
			displayBoard[tempRow][tempColumn] = ' ';
		
		else if(board[i][j].piece->name.compare("Pawn") == 0)
			displayBoard[tempRow][tempColumn] = 'P';

		else if(board[i][j].piece->name.compare("King") == 0)
			displayBoard[tempRow][tempColumn] = 'K';

		else if(board[i][j].piece->name.compare("Queen") == 0)
			displayBoard[tempRow][tempColumn] = 'Q';

		else if(board[i][j].piece->name.compare("Bishop") == 0)
			displayBoard[tempRow][tempColumn] = 'B';

		else if(board[i][j].piece->name.compare("Knight") == 0)
			displayBoard[tempRow][tempColumn] = 'N';

		else 
			displayBoard[tempRow][tempColumn] = 'R';
			
		}
	}




	for(int i = 0; i < 34; i++){

		cout<<endl;
	
		for(int j = 0; j < 53; j++){
		
			cout<<displayBoard[i][j];
		
		}
	}

	cout<<endl<<endl;

}

