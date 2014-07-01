#pragma once
#include<string>

using namespace std;


class Piece
{
public:
	Piece(void);
	~Piece(void);

	string name;
	int player;

	Piece(string, int);	//type constructor
};

