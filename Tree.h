#pragma once

#include <SFML/Graphics.hpp>

#include "Cells.h"

class Tree : public Cells
{
	using Cells::Cells;

private:

public:
	Tree() = delete;
	Tree(float, float, float);
	~Tree();
};

