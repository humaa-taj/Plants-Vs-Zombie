#include"level.h"


level::level()
{

}

level::level(RenderWindow& window, int ll) : zf(ll)
{
	l = ll;

	for (int i = 0; i < 5; i++)
	{
		c[i].setcar(65 + (i * 98));
	}
	levelwon = true;/////////
	returned = 100;
}
int level::getlevel()
{
	return l;
}

void level::setlevel(int ll)
{
	l = ll;
}



void level::plantzombie(RenderWindow& window)
{
	int size = pf.getsize();
	for (int j = 0; j < size; j++)
	{
		if (pf.p[j]->getcherry())
		{
			int cherryGridX = (pf.p[j]->getpx() - 220) / 80; 
			int cherryGridY = (pf.p[j]->getpy() - 65) / 98; 

			for (int l = 0; l < 13; l++)
			{
				if (zf.z[l]->name == "dancing")
				{
					partnercollisons(window, l, 3, cherryGridX, cherryGridY,j,window);
				}
					if (zf.z[l]->getlife() > 0)
					{
						int zombieGridX = (zf.z[l]->getx() - 220) / 80;
						int zombieGridY = (zf.z[l]->gety() - 65) / 98;

						// Check if zombie is in the same grid box as the cherry or adjacent
						if (zombieGridX == cherryGridX - 1 && zombieGridY == cherryGridY)

						{
							
							zf.z[l]->setkiller(true);
							zf.z[l]->setlife(0);
						}
						if (zombieGridX == cherryGridX  && zombieGridY == cherryGridY)

						{
							
							zf.z[l]->setkiller(true);
							zf.z[l]->setlife(0);
						}
						if (zombieGridX == cherryGridX + 1 && zombieGridY == cherryGridY)
						{
							
							zf.z[l]->setkiller(true);
							zf.z[l]->setlife(0);
						}
						if (zombieGridY == cherryGridY - 1 && zombieGridX == cherryGridX)
						{
							
							zf.z[l]->setkiller(true);
							zf.z[l]->setlife(0);
						}
						if (zombieGridY == cherryGridY + 1 && zombieGridX == cherryGridX)
						{
							
							zf.z[l]->setkiller(true);
							zf.z[l]->setlife(0);
						}
					}
				
			}
		}
		else if (pf.p[j]->getcherry() == false)
		{
			int wx = (pf.p[j]->getpx() - 220) / 80;
			int wy = (pf.p[j]->getpy() - 65) / 98;
			for (int i = 0; i < 13; i++)
			{

			   partnercollisons(window, i, 4,wx, wy,j,window);

				if (pf.p[j]->getpx() + 80 > zf.z[i]->getx()
					&& pf.p[j]->getpx() < zf.z[i]->getx() + 80
					&& pf.p[j]->getpy() + 98 > zf.z[i]->gety()
					&& pf.p[j]->getpy() < zf.z[i]->gety() + 98)
                {

					if (pf.p[j]->getnut() == true && pf.p[j]->getpx()<=940)
					{

						if (zf.z[i]->getlife() > 0 && zf.z[i]->name !="flying" )
						{
							pf.p[j]->setmove(false);
							pf.p[j]->diagnal_up(window);
							zf.z[i]->setlife((zf.z[i]->getlife()) / 2);
						}
					}
						else if (pf.p[j]->getlife() > 0 && pf.p[j]->getnut() == false)
						{
							zf.z[i]->seteating(true);
							pf.p[j]->startdeath();
						}
						if (pf.p[j]->getlife() <= 0)
						{
							gri.gr[(zf.z[i]->gety() - 65) / 98][(zf.z[i]->getx() - 220) / 80][3] = false;
							zf.z[i]->seteating(false);
						}

					
				}



				
			}
		}

	}
	
}


void level::carzombie(RenderWindow& window)
{
	bool moved;
	int size = pf.getsize();
	for (int i = 0; i < 13; i++)
	{
		if (zf.z[i]->name == "dancing")
		{
			partnercollisons(window, i,1,0,0,0,window);
			if (zf.z[i]->getlife() > 0)
			{
				if (zf.z[i]->getx() <= 220)
				{
					if (!gri.getgrid(220, zf.z[i]->gety(), 3))
					{
						for (int k = 0; k < 5; k++)
						{
							if (c[k].px >= zf.z[i]->getx() && c[k].py == zf.z[i]->gety() && c[k].gete())
							{
								zf.z[i]->setlife(0);
								c[k].setmoving(true);

							}
						}

					}
				}
			}
			
		}
    	else if (zf.z[i]->getlife() >0 )
		{
			
			if (zf.z[i]->getx() <= 220)
			{
				if (!gri.getgrid(220, zf.z[i]->gety(), 3))
				{

					
					for (int k = 0; k < 5; k++)
					{

						if (c[k].px >= zf.z[i]->getx() && c[k].py == zf.z[i]->gety() && c[k].gete())
						{
							
							zf.z[i]->setlife(0);
							c[k].setmoving(true);

						}
					}

				}
			}
		}
	}
}

void level::zombie_bullet_collision(RenderWindow& w)
{
	for (int i = 0; i < 13; i++)
	{
		for (int j = 0; j < pf.getsize(); j++)
		{

			if (zf.z[i]->name == "dancing")

			{
				partnercollisons(w, i, 2,0,0,0,w);
				if (zf.z[i]->getlife() > 0 && pf.p[j]->b != NULL)
				{


					if (((pf.p[j]->b->temp + 80) > zf.z[i]->getx()) &&
						(pf.p[j]->b->temp < (zf.z[i]->getx() + 80)) &&
						((pf.p[j]->b->getpy() + 98) > zf.z[i]->gety()) &&
						(pf.p[j]->b->getpy() < (zf.z[i]->gety() + 98)))

					{
						//cout << "bcz of other zombie" << endl;
						zf.z[i]->setlife((zf.z[i]->getlife()) - (pf.p[j]->b->getdamage()));
						if (zf.z[i]->getlife() <= 0)
						{
							zf.z[i]->setalive(false);
						}
						pf.p[j]->b->setexist(false);
						pf.p[j]->b->movebullet();
					}
				}

			}


			else if (zf.z[i]->getlife() > 0 && pf.p[j]->b != NULL)
			{

				if (((pf.p[j]->b->temp + 80) > zf.z[i]->getx()) &&
					(pf.p[j]->b->temp < (zf.z[i]->getx() + 80)) &&
					((pf.p[j]->b->getpy() + 98) > zf.z[i]->gety()) &&
					(pf.p[j]->b->getpy() < (zf.z[i]->gety() + 98)))

				{
					//cout << "bcz of other zombie" << endl;
					zf.z[i]->setlife((zf.z[i]->getlife()) - (pf.p[j]->b->getdamage()));
					if (zf.z[i]->getlife() <= 0)
					{
						zf.z[i]->setalive(false);
					}
					pf.p[j]->b->setexist(false);
					pf.p[j]->b->movebullet();
				}
			}

		}
	}
}


void level::setsuns()///////////
{
	sunscollected = 100;
	for (int j = 0; j < pf.getsize(); j++)
	{
		sunscollected += pf.p[j]->getprice();
	}
	

}
int level::getsuns()
{
	return sunscollected;
}

void level::setindsuns(int y)
{

	sunscollected += y;
}

int level::changelevel()
{
	
	levelwon = true;
	for (int i = 0; i < 13; i++)
	{
		
		for(int j=0;j<5;j++)

		{
			if (zf.z[i]->name == "dancing")
			{
				if (zf.z[i]->getback())
				{
					levelwon = false;
				}
				if (zf.z[i]->getfront())
				{
					levelwon = false;
				}
				if (zf.z[i]->getup())
				{
					levelwon = false;
				}
				if (zf.z[i]->getdown())
				{
					levelwon = false;
				}
				if (zf.z[i]->getup() && zf.z[i]->getx() < 200 && !c[j].gete())
				{
					levelwon = false;
					return l;
				}
				if (zf.z[i]->getdown() && zf.z[i]->getx() < 200 && !c[j].gete())
				{
					levelwon = false;
					return l;
				}
				if (zf.z[i]->getfront() && zf.z[i]->getx()-80 < 200 && !c[j].gete())
				{
					levelwon = false;
					return l;
				}
				if (zf.z[i]->getback() && zf.z[i]->getx() + 80 < 200 && !c[j].gete())
				{
					levelwon = false;
					return l;
				}
			}

			if (zf.z[i]->getlife() > 0 && zf.z[i]->getx() < 200 && !c[j].gete())
			{

				return l;
			}

			if (zf.z[i]->getlife() > 0)
			{

				levelwon = false;
			}

		}
	}
	if ( levelwon == true)
	{
		
		return 20;
	}
	
	return 100;

}

void level::partnercollisons(RenderWindow& w, int i,int which, int cherryGridX, int cherryGridY,int pi,RenderWindow & window)
{
	if(which==1)
	{
		for (int k = 0; k < 5; k++)
		{


			if (c[k].px >= (zf.z[i]->getx() - 80) && c[k].py == zf.z[i]->gety() && !gri.getgrid(220, zf.z[i]->gety(), 3) && zf.z[i]->getfront() && c[k].gete())
			{
				
				zf.z[i]->checkpartner(w, 1);
				c[k].setmoving(true);

			}
			if (c[k].px >= (zf.z[i]->getx()) && c[k].py == (zf.z[i]->gety() - 98) && !gri.getgrid(220, zf.z[i]->gety() - 98, 3) && zf.z[i]->getup() && c[k].gete())
			{
				
				zf.z[i]->checkpartner(w, 3);
				c[k].setmoving(true);

			}
			if (c[k].px >= (zf.z[i]->getx()) && c[k].py == (zf.z[i]->gety() + 98) && !gri.getgrid(220, zf.z[i]->gety() + 98, 3) && zf.z[i]->getdown() && c[k].gete())
			{
				
				zf.z[i]->checkpartner(w, 4);
				c[k].setmoving(true);

			}
			if (c[k].px >= (zf.z[i]->getx() + 80) && c[k].py == (zf.z[i]->gety()) && !gri.getgrid(220, zf.z[i]->gety(), 3) && zf.z[i]->getback() && c[k].gete())
			{
				
				zf.z[i]->checkpartner(w, 2);
				c[k].setmoving(true);

			}
		}
	}
	else if (which == 2)
	{
		for (int j = 0; j < pf.getsize(); j++)
		{
			if (pf.p[j]->b != NULL && zf.z[i]->getfront())
			{
				if (((pf.p[j]->b->temp + 80) > (zf.z[i]->getx() - 80)) &&
					(pf.p[j]->b->temp < (zf.z[i]->getx() - 80 + 80)) &&
					((pf.p[j]->b->getpy() + 98) > zf.z[i]->gety()) &&
					(pf.p[j]->b->getpy() < (zf.z[i]->gety() + 98)))
				{
					zf.z[i]->checkpartner(w, 1);
					pf.p[j]->b->setexist(false);
					pf.p[j]->b->movebullet();
				}
			}
			if (pf.p[j]->b != NULL && zf.z[i]->getback())
			{
				if (((pf.p[j]->b->temp + 80) > (zf.z[i]->getx() + 80)) &&
					(pf.p[j]->b->temp < (zf.z[i]->getx() + 80 + 80)) &&
					((pf.p[j]->b->getpy() + 98) > zf.z[i]->gety()) &&
					(pf.p[j]->b->getpy() < (zf.z[i]->gety() + 98)))
				{
					zf.z[i]->checkpartner(w, 2);
					pf.p[j]->b->setexist(false);
					pf.p[j]->b->movebullet();
				}
			}
			if (pf.p[j]->b != NULL && zf.z[i]->getup())
			{
				if (((pf.p[j]->b->temp + 80) > (zf.z[i]->getx())) &&
					(pf.p[j]->b->temp < (zf.z[i]->getx() + 80)) &&
					((pf.p[j]->b->getpy() + 98) > (zf.z[i]->gety() - 98)) &&
					(pf.p[j]->b->getpy() < (zf.z[i]->gety() + 98 - 98)))
				{
					zf.z[i]->checkpartner(w, 3);
					pf.p[j]->b->setexist(false);
					pf.p[j]->b->movebullet();
				}
			}
			if (pf.p[j]->b != NULL && zf.z[i]->getdown())
			{
				if (((pf.p[j]->b->temp + 80) > (zf.z[i]->getx())) &&
					(pf.p[j]->b->temp < (zf.z[i]->getx() + 80)) &&
					((pf.p[j]->b->getpy() + 98) > (zf.z[i]->gety() + 98)) &&
					(pf.p[j]->b->getpy() < (zf.z[i]->gety() + 98 + 98)))
				{
					zf.z[i]->checkpartner(w, 4);
					pf.p[j]->b->setexist(false);
					pf.p[j]->b->movebullet();
				}
			}
		}
	}
	else if (which == 3)
	{
		if (zf.z[i]->getdown())
		{
			int zombieGridX = (zf.z[i]->getx() - 220) / 80;
			int zombieGridY = (zf.z[i]->gety()+98 - 65) / 98;

			// Check if zombie is in the same grid box as the cherry or adjacent
			if (zombieGridX == cherryGridX - 1 && zombieGridY == cherryGridY)

			{

				
				zf.z[i]->checkpartner(w, 4);
			}
			if (zombieGridX == cherryGridX  && zombieGridY == cherryGridY)

			{

				
				zf.z[i]->checkpartner(w, 4);
			}
			if (zombieGridX == cherryGridX + 1 && zombieGridY == cherryGridY)
			{
				
				zf.z[i]->checkpartner(w, 4);
			}
			if (zombieGridY == cherryGridY - 1 && zombieGridX == cherryGridX)
			{
				
				zf.z[i]->checkpartner(w, 4);
			}
			if (zombieGridY == cherryGridY + 1 && zombieGridX == cherryGridX)
			{
				
				zf.z[i]->checkpartner(w, 4);
			}
		}
		if (zf.z[i]->getup())
		{
			int zombieGridX = (zf.z[i]->getx() - 220) / 80;
			int zombieGridY = (zf.z[i]->gety()-98 - 65) / 98;

			// Check if zombie is in the same grid box as the cherry or adjacent
			if (zombieGridX == cherryGridX - 1 && zombieGridY == cherryGridY)

			{

				zf.z[i]->checkpartner(w, 3);
			}
			if (zombieGridX == cherryGridX  && zombieGridY == cherryGridY)

			{
				zf.z[i]->checkpartner(w, 3);
			}
			if (zombieGridX == cherryGridX + 1 && zombieGridY == cherryGridY)
			{
				zf.z[i]->checkpartner(w, 3);
			}
			if (zombieGridY == cherryGridY - 1 && zombieGridX == cherryGridX)
			{
				zf.z[i]->checkpartner(w, 3);
			}
			if (zombieGridY == cherryGridY + 1 && zombieGridX == cherryGridX)
			{
				zf.z[i]->checkpartner(w, 3);
			}
		}
		if (zf.z[i]->getfront())
		{
			int zombieGridX = (zf.z[i]->getx()-80 - 220) / 80;
			int zombieGridY = (zf.z[i]->gety() - 65) / 98;

			// Check if zombie is in the same grid box as the cherry or adjacent
			if (zombieGridX == cherryGridX - 1 && zombieGridY == cherryGridY)

			{
				zf.z[i]->checkpartner(w, 1);
			}
			if (zombieGridX == cherryGridX  && zombieGridY == cherryGridY)

			{
				zf.z[i]->checkpartner(w, 1);
			}

			if (zombieGridX == cherryGridX + 1 && zombieGridY == cherryGridY)
			{
				zf.z[i]->checkpartner(w, 1);
			}
			if (zombieGridY == cherryGridY - 1 && zombieGridX == cherryGridX)
			{
				zf.z[i]->checkpartner(w, 1);
			}
			if (zombieGridY == cherryGridY + 1 && zombieGridX == cherryGridX)
			{
				zf.z[i]->checkpartner(w, 1);
			}
		}
		if (zf.z[i]->getback())
		{
			int zombieGridX = (zf.z[i]->getx()+80 - 220) / 80;
			int zombieGridY = (zf.z[i]->gety() - 65) / 98;

			// Check if zombie is in the same grid box as the cherry or adjacent
			if (zombieGridX == cherryGridX - 1 && zombieGridY == cherryGridY)

			{
				zf.z[i]->checkpartner(w, 2);
			}
			if (zombieGridX == cherryGridX  && zombieGridY == cherryGridY)

			{
				zf.z[i]->checkpartner(w, 2);
			}
			if (zombieGridX == cherryGridX + 1 && zombieGridY == cherryGridY)
			{
				zf.z[i]->checkpartner(w, 2);
			}
			if (zombieGridY == cherryGridY - 1 && zombieGridX == cherryGridX)
			{
				zf.z[i]->checkpartner(w, 2);
			}
			if (zombieGridY == cherryGridY + 1 && zombieGridX == cherryGridX)
			{
				zf.z[i]->checkpartner(w, 2);
			}
		}
	}
	else if (which == 4 && zf.z[i]->name == "dancing")
	{
		int z1x = ((zf.z[i]->getx()  - 220) / 80)-1;
		int z1y = (zf.z[i]->gety() - 65) / 98;
		int z2x = ((zf.z[i]->getx() - 220) / 80) + 1;
		int z2y = (zf.z[i]->gety() - 65) / 98;
		int z3x = (zf.z[i]->getx()  - 220) / 80;
		int z3y = (zf.z[i]->gety()+98 - 65) / 98;
		int z4x = (zf.z[i]->getx() - 220) / 80;
		int z4y = (zf.z[i]->gety()-98 - 65) / 98;
        if(pf.p[pi]->getnut() && pf.p[pi]->getpx() <= 940)
		{
			if (zf.z[i]->getback() && z2x == cherryGridX && z2y == cherryGridY)
			{
				pf.p[pi]->setmove(false);
				pf.p[pi]->diagnal_up(window);
				zf.z[i]->checkpartner(w, 2);
			}
			if (zf.z[i]->getfront() && z1x == cherryGridX && z1y == cherryGridY)
			{
				pf.p[pi]->setmove(false);
				pf.p[pi]->diagnal_up(window);

				zf.z[i]->checkpartner(w, 1);

			}
			if (zf.z[i]->getup() && z4x == cherryGridX && z4y == cherryGridY)
			{
				pf.p[pi]->setmove(false);
				pf.p[pi]->diagnal_up(window);

				zf.z[i]->checkpartner(w, 3);
			}
			if (zf.z[i]->getdown() && z3x == cherryGridX && z3y == cherryGridY)
			{
				pf.p[pi]->setmove(false);
				pf.p[pi]->diagnal_up(window);
				zf.z[i]->checkpartner(w, 4);
			}
		}
		if (!pf.p[pi]->getnut() && !pf.p[pi]->getcherry() && pf.p[i]!=NULL && pf.p[i]->getlife()>0)
		{

			if (zf.z[i]->getback() && z2x == cherryGridX && z2y == cherryGridY)
			{
				zf.z[i]->seteating(true);
				pf.p[pi]->startdeath();
				if (pf.p[pi]->getlife() <= 0)
				{
					gri.gr[z2y][z2x][3] = false;
					zf.z[i]->seteating(false);
				}
			}
			if (zf.z[i]->getfront() && z1x == cherryGridX && z1y == cherryGridY)
			{
				zf.z[i]->seteating(true);
				pf.p[pi]->startdeath();
				if (pf.p[pi]->getlife() <= 0)
				{
					gri.gr[z1y][z1x][3] = false;
					zf.z[i]->seteating(false);
				}
				

			}
			if (zf.z[i]->getup() && z4x == cherryGridX && z4y == cherryGridY)
			{
				zf.z[i]->seteating(true);
				pf.p[pi]->startdeath();
				if (pf.p[pi]->getlife() <= 0)
				{
					gri.gr[z4y][z4x][3] = false;
					zf.z[i]->seteating(false);
				}
				
			}
			if (zf.z[i]->getdown() && z3x == cherryGridX && z3y == cherryGridY)
			{
				
				zf.z[i]->seteating(true);
				pf.p[pi]->startdeath();
				if (pf.p[pi]->getlife() <= 0)
				{
					gri.gr[z3y][z3x][3] = false;
					zf.z[i]->seteating(false);
				}
			}
		}

	}
}


bool level::getwon()
{
	return levelwon;
}