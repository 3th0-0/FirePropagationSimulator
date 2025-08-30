#pragma once

#include <SFML/Graphics.hpp>

// Cells.h : Classe Parent de chaque cellule du jeu.
class Cells
{
protected:
	sf::RectangleShape _cells_body;

private:
	float _pos_x;
	float _pos_y;

	float _size;

public:
	Cells(float, float, float);
	~Cells();

	sf::RectangleShape getCells();
	float getSize();
	float getPosX();
	float getPosY();
};

