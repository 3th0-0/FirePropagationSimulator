#pragma once

#include <vector>

#include <SFML/Graphics.hpp>

#include "Tree.h"

// Field.h : Ce fichier va configurer l'état du terrain va le générer.

class Field
{
private:
	int _field_size_x;
	int _field_size_y;

	std::vector<int> field_organization;
	std::vector<Tree> standart_field;
	std::vector<Tree> random_field;

public:
	Field(int, int);
	~Field();

	std::vector<Tree> getSTDField() const;
	int getSizeX() const;
	int getSizeY() const;

};

