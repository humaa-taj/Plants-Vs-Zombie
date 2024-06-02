#pragma once

class grid
{
public:
	int rows, x;
	int columns, y;
	int boxpixelsX;
	int boxpixelsY;
	float gr[5][9][5];
	bool zombiep, plantp, bulletp;
	grid()
	{
		rows = 5;
		columns = 9;
		boxpixelsX = 80;
		boxpixelsY = 98;
		x = 0; y = 1; zombiep = 2; plantp = 3; bulletp = 4;
		for (int i = 0; i < rows; i++)
		{

			for (int j = 0; j < columns; j++)
			{
				gr[i][j][x] = 220 + (boxpixelsX * j);
				gr[i][j][y] = 65 + (boxpixelsY * i);
				gr[i][j][zombiep] = false;
				gr[i][j][bulletp] = false;
				gr[i][j][plantp] = false;
				//cout << gr[i][j][plantp] << "  ";

			}
		//	cout << endl;
		}
		//cout << "~~~~~~~~" << endl;

	}
	bool getgrid(int x, int y, int index)
	{
		/*if (x >= 220 && x <= 860 && y >= 0 && y <= 457)
		{*/
		return gr[(x - 220) / boxpixelsX][(y - 65) / boxpixelsY][index];
		/*}
		else
			return false;*/
	}
	/*void setgrid(int x, int y, int index,bool b)
	{

			gr[((x - 220) / boxpixelsX)][((y - 65) / boxpixelsY)][index] = b;


	}*/

};
