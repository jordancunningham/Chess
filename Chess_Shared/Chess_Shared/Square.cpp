#include "Square.h"


Square::Square(void)
{
	piece = nullptr;	//initialize the square to null
}

Square::Square(Piece *p){

	piece = p;

}


Square::~Square(void)
{
}
