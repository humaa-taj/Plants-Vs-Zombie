#pragma once
#include"level.h"

class level2 : public level
{
public:
	level2(RenderWindow& window, int level);
	void startgame(RenderWindow& window, Event event);
};