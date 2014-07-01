#pragma once
#include "Piece.h"

class Square
{
public:
	Square(void);
	~Square(void);

	Piece *piece;	//pointer to piece on the square. void if no piece is present.

	Square(Piece *);
};

