

#pragma once
#include"level.h"

class level1 : public level
{
public:
	level1(RenderWindow& window, int level);
	void startgame(RenderWindow& window, Event event);
};
