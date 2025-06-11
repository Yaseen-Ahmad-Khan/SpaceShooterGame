#include<iostream>
#include"help.h"
#include<fstream>
#include<string>
#pragma comment(lib, "winmm.lib") 
using namespace std;
void setConsoleToFullScreen()
{
	HWND consoleWindow = GetConsoleWindow();
	ShowWindow(consoleWindow, SW_MAXIMIZE);
}
int main()
{
	//graphic selector
	PlaySound(L"GOT.wav", NULL, SND_FILENAME | SND_ASYNC);
	int boost;
	int alienBulletSpeed;
	int pausef = -1;
	int gameflag = 0;
	int musicflag;
	int graphicflag = 0;
	setConsoleToFullScreen();
	Sleep(100);
	{
		myRect(630, 180, 1450, 320, 255, 0, 0, 0, 255, 255);
		drawText(50, 650, 200, 255, 0, 0, "Select graphics");
		myRect(840, 380, 1050, 480, 255, 0, 0, 0, 100, 255);
		while (true)
		{
			drawText(30, 870, 400, 255, 255, 255, "High");
			drawText(20, 1100, 380, 255, 255, 0, " May cause flickering");
			drawText(20, 1100, 420, 255, 0, 0, "only use if high end pc");
			drawText(20, 1100, 460, 255, 0, 0, "or charger connected to        laptop");
			drawText(30, 800, 550, 255, 255, 255, "Low + circle");
			drawText(30, 800, 700, 255, 255, 255, "Low + rect");
			int whichkey;
			bool keypressed = isKeyPressed(whichkey);
			if (keypressed)
			{
				if ((whichkey == 4) && (graphicflag == 0))
				{
					myRect(840, 380, 1050, 480, 0, 0, 0, 0, 0, 0);
					myRect(780, 530, 1200, 630, 255, 0, 0, 0, 100, 255);
					graphicflag = 1;
					continue;
				}
				if ((whichkey == 2) && (graphicflag == 1))
				{
					myRect(780, 530, 1200, 630, 0, 0, 0, 0, 0, 0);
					myRect(840, 380, 1050, 480, 255, 0, 0, 0, 100, 255);
					graphicflag = 0;
					continue;
				}
				if ((whichkey == 4) && (graphicflag == 1))
				{
					myRect(780, 530, 1200, 630, 0, 0, 0, 0, 0, 0);
					myRect(780, 680, 1200, 780, 255, 0, 0, 0, 100, 255);
					graphicflag = 2;
					continue;
				}
				if ((whichkey == 2) && (graphicflag == 2))
				{
					myRect(780, 680, 1200, 780, 0, 0, 0, 0, 0, 0);
					myRect(780, 530, 1200, 630, 255, 0, 0, 0, 100, 255);
					graphicflag = 1;
					continue;
				}
				if ((whichkey == 5) && (graphicflag == 0))
				{
					system("cls");
					break;
				}
				if ((whichkey == 5) && (graphicflag == 1))
				{
					system("cls");
					break;
				}
				if ((whichkey == 5) && (graphicflag == 2))
				{
					system("cls");
					break;
				}
			}
		}
	}
	//this is the main menu
a:myEllipse(60, 50, 520, 250, 0, 0, 0, 255, 0, 0); //rectangle for spac ++
	myRect(95, 530, 400, 610, 255, 255, 255, 255, 0, 0); //rectangle for start new game
	/*myRect(95, 620, 225, 700, 255, 255, 255, 255, 0, 0); rectangle for resume*/
	/*myRect(95, 710, 325, 800, 255, 255, 255, 255, 0, 0); rectangle for high score*/
	myRect(1200, 100, 1700, 200, 255, 0, 0, 0, 255, 0); //alien
	myRect(1200, 200, 1250, 300, 255, 0, 0, 0, 255, 0);
	myRect(1650, 200, 1700, 300, 255, 0, 0, 0, 255, 0);
	myRect(1425, 200, 1475, 240, 255, 0, 0, 0, 255, 0);
	myRect(1415, 170, 1485, 190, 255, 0, 0, 255, 0, 0);
	myEllipse(1330, 120, 1380, 160, 255, 0, 0, 255, 0, 0);
	myEllipse(1530, 120, 1580, 160, 255, 0, 0, 255, 0, 0);
	myRect(1200, 840, 1700, 930, 0, 0, 0, 0, 0, 255); //spaceship
	myEllipse(1170, 875, 1200, 895, 255, 255, 255, 255, 255, 255);
	myEllipse(1700, 875, 1730, 895, 255, 255, 255, 255, 255, 255);
	myRect(1300, 760, 1600, 840, 0, 0, 0, 255, 100, 0);
	myRect(1430, 710, 1470, 760, 0, 0, 0, 255, 100, 0);
	myEllipse(1430, 690, 1470, 715, 255, 255, 0, 255, 255, 0);
	myRect(1300, 855, 1400, 915, 0, 0, 0, 0, 0, 0);
	myRect(1500, 855, 1600, 915, 0, 0, 0, 0, 0, 0);
	myRect(1300, 795, 1600, 810, 0, 0, 0, 0, 0, 0);
	int initial_x = 1200;
	int initial_y = 350;
	int final_x = 1210;
	int final_y = 380;
	//bullets
	myRect(initial_x, initial_y, final_x, final_y, 255, 255, 0, 255, 255, 0);
	myRect(initial_x + 100, initial_y + 100, final_x + 100, final_y + 100, 255, 255, 0, 255, 255, 0);
	myRect(initial_x + 200, initial_y + 200, final_x + 200, final_y + 200, 255, 255, 0, 255, 255, 0);
	myRect(initial_x, initial_y + 200, final_x, final_y + 200, 255, 255, 0, 255, 255, 0);
	myRect(initial_x + 100, initial_y + 300, final_x + 100, final_y + 300, 255, 255, 0, 255, 255, 0);
	myRect(initial_x + 500, initial_y, final_x + 500, final_y, 255, 255, 0, 255, 255, 0);
	myRect(initial_x + 400, initial_y + 100, final_x + 400, final_y + 100, 255, 255, 0, 255, 255, 0);
	myRect(initial_x + 250, initial_y + 100, final_x + 250, final_y + 100, 255, 255, 0, 255, 255, 0);
	myRect(initial_x + 250, initial_y - 20, final_x + 250, final_y - 20, 255, 255, 0, 255, 255, 0);
	myRect(initial_x + 350, initial_y + 200, final_x + 350, final_y + 200, 255, 255, 0, 255, 255, 0);
	myRect(initial_x + 500, initial_y + 200, final_x + 500, final_y + 200, 255, 255, 0, 255, 255, 0);
	myRect(initial_x + 400, initial_y + 300, final_x + 400, final_y + 300, 255, 255, 0, 255, 255, 0);
	int flag = 0;
	while (true)
	{
		drawText(50, 100, 100, 255, 255, 255, "Space ++");
		drawText(20, 100, 260, 255, 255, 255, "A space invader game based on c++");
		drawText(15, 100, 400, 255, 0, 0, "A group of aliens have invaded your planet");
		drawText(15, 100, 428, 255, 0, 0, "Get your spaceship and kill them or be killed!!!");
		drawText(20, 100, 550, 0, 255, 0, "Start new game");
		drawText(20, 100, 650, 0, 255, 0, "Resume");
		drawText(20, 100, 750, 0, 255, 0, "High Scores");
		int whichkey;
		bool keypressed = isKeyPressed(whichkey);
		if (keypressed)
		{
			if ((whichkey == 4) && (flag == 0))
			{
				myRect(95, 530, 400, 610, 0, 0, 0, 0, 0, 0);
				myRect(95, 620, 225, 700, 255, 255, 255, 255, 0, 0);
				flag = 1;
				continue;
			}
		}
		if (keypressed)
		{
			if ((whichkey == 4) && (flag == 1))
			{
				myRect(95, 620, 225, 700, 0, 0, 0, 0, 0, 0);
				myRect(95, 710, 325, 800, 255, 255, 255, 255, 0, 0);
				flag = 2;
				continue;
			}
		}
		if (keypressed)
		{
			if ((whichkey == 2) && (flag == 2))
			{
				myRect(95, 710, 325, 800, 0, 0, 0, 0, 0, 0);
				myRect(95, 620, 225, 700, 255, 255, 255, 255, 0, 0);
				flag = 1;
				continue;
			}
		}
		if (keypressed)
		{
			if ((whichkey == 2) && (flag == 1))
			{
				myRect(95, 620, 225, 700, 0, 0, 0, 0, 0, 0);
				myRect(95, 530, 400, 610, 255, 255, 255, 255, 0, 0);
				flag = 0;
				continue;
			}
		}
		if (keypressed)
		{
			if ((whichkey == 5) && (flag == 0))
			{
				break;
			}
		}
		if (keypressed)
		{
			if ((whichkey == 5) && (flag == 1))
			{
				break;
			}
		}
		if (keypressed)
		{
			if ((whichkey == 5) && (flag == 2))
			{
				break;
			}
		}
	}
	system("cls");
	//level
	if (flag == 0)
	{
		int levelflag = 0;
		myRect(840, 380, 1050, 480, 255, 0, 0, 0, 100, 255);
		drawText(30, 850, 400, 255, 255, 255, "easy");
		drawText(30, 850, 550, 255, 255, 255, "medium");
		drawText(30, 850, 700, 255, 255, 255, "hard");
		while (true)
		{
			drawText(30, 850, 400, 255, 255, 255, "easy");
			drawText(30, 850, 550, 255, 255, 255, "medium");
			drawText(30, 850, 700, 255, 255, 255, "hard");
			int whichkey;
			bool keypressed = isKeyPressed(whichkey);
			if (keypressed)
			{
				if ((whichkey == 4) && (levelflag == 0))
				{
					myRect(800, 380, 1050, 480, 0, 0, 0, 0, 0, 0);
					myRect(840, 530, 1100, 630, 255, 0, 0, 0, 100, 255);
					levelflag = 1;
					continue;
				}
				if ((whichkey == 2) && (levelflag == 1))
				{
					myRect(800, 530, 1100, 630, 0, 0, 0, 0, 0, 0);
					myRect(840, 380, 1050, 480, 255, 0, 0, 0, 100, 255);
					levelflag = 0;
					continue;
				}
				if ((whichkey == 4) && (levelflag == 1))
				{
					myRect(840, 530, 1100, 630, 0, 0, 0, 0, 0, 0);
					myRect(840, 680, 1050, 780, 255, 0, 0, 0, 100, 255);
					levelflag = 2;
					continue;
				}
				if ((whichkey == 2) && (levelflag == 2))
				{
					myRect(840, 680, 1050, 780, 0, 0, 0, 0, 0, 0);
					myRect(840, 530, 1100, 630, 255, 0, 0, 0, 100, 255);
					levelflag = 1;
					continue;
				}
				if (whichkey == 5)
				{
					if (levelflag == 0)
					{
						musicflag = 0;
						boost = 0;
						alienBulletSpeed = 40;
					}
					else if (levelflag == 1)
					{
						musicflag = 0;
						boost = 5;
						alienBulletSpeed = 55;
					}
					else if (levelflag == 2)
					{
						musicflag = 1;
						boost = 15;
						alienBulletSpeed = 70;
					}
					system("cls");
					break;
				}
			}
		}
	}
	PlaySound(NULL, NULL, 0);
	//game
	if ((flag == 0) || (flag == 1))
	{
		ifstream save("save.txt");
		int scores[5];
		ifstream in("highscore.txt");
		for (int i = 0; i < 5; i++)
		{
			in >> scores[i];
		}
		int initial_x = 400;
		int initial_y = 400;
		//bullet
		bool bulletActive = false;
		float bullet_x = 0, bullet_y = 0;
		float bullet_speed = 40;
		//alienbullet
		int alienBullet_x = 0;
		int alienBullet_y = 0;
		bool AlienBulletActive = false;
		//int alienBulletSpeed;
		//score
		int score = 10;
		/*myRect(780, 40, 1000, 100, 255, 255, 255, 255, 0, 0);*/
		//lives
		int lives = 5;
		/*myRect(100, 40, 600, 100, 255, 255, 255, 255, 0, 0);*/
		//alien
		int startx;
		if (graphicflag == 0)
		{
			startx = 1400;
		}
		else
		{
			startx = 1500;
		}
		float starty = 150;
		int row = 10;
		int col = 5;
		bool a[10][5];
		int x;
		int y;
		int width = 35;
		int height = 60;
		//mark
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				a[i][j] = true;
			}
		}
		//read
		if (flag == 1)
		{
			save >> score;
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					save >> a[i][j];
				}
			}
			save >> alienBulletSpeed;
			save >> boost;
			save >> startx;
			save >> starty;
			save >> lives;
			save >> musicflag;
			save.close();
		}
		if (musicflag == 0)
		{
			PlaySound(L"mario.wav", NULL, SND_FILENAME | SND_ASYNC);
		}
		else
		{
			PlaySound(L"death.wav", NULL, SND_FILENAME | SND_ASYNC);
		}
		float direction = 4;
		int distance = 10;
		int whichkey;
	r:myRect(100, 100, 1800, 950, 255, 0, 0, 0, 0, 255);
		myRect(780, 40, 1000, 100, 255, 255, 255, 255, 0, 0);
		myRect(100, 40, 600, 100, 255, 255, 255, 255, 0, 0);
		while (true)
		{
			pausef = 0;
			drawText(20, 800, 50, 255, 255, 255, "Score ", true, score);
			drawText(20, 250, 50, 255, 255, 255, "lIVES ", true, lives);
			//spaceship
			myRect(initial_x + 30, initial_y + 20, initial_x + 60, initial_y + 80, 255, 0, 0, 0, 0, 0);
			myRect(initial_x, initial_y + 90, initial_x - 40, initial_y + 80, 0, 255, 0, 255, 165, 0);
			myRect(initial_x, initial_y + 10, initial_x - 40, initial_y + 20, 0, 255, 0, 255, 165, 0);
			myRect(initial_x, initial_y, initial_x + 30, initial_y + 100, 255, 0, 0, 0, 255, 0);
			myRect(initial_x + 10, initial_y, initial_x + 15, initial_y + 100, 255, 0, 0, 0, 0, 0);
			myEllipse(initial_x + 35, initial_y + 30, initial_x + 55, initial_y + 70, 255, 255, 255, 255, 255, 255);
			//alien according to graphics selected
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					if (a[i][j])
					{
						int x;
						if (graphicflag == 0)
						{
							x = startx + (j * (width + 50));
						}
						else
						{
							x = startx + (j * (width + distance));
						}
						int y = starty + (i * (height + distance));
						if (graphicflag == 2)
						{
							myRect(x, y, x + width, y + height, 0, 0, 255, 0, 0, 255);
						}
						else if (graphicflag == 1)
						{
							myEllipse(x, y, x + width, y + height, 0, 0, 255, 0, 0, 255);
						}
						else if (graphicflag == 0)
						{
							myRect(x, y, x + width, y + height, 0, 0, 255, 0, 0, 255);
							myRect(x, y + 2, x - 35, y + 15, 0, 0, 255, 0, 0, 255);
							myRect(x, y + height - 2, x - 35, y + height - 15, 0, 0, 255, 0, 0, 255);
						}
						if ((initial_y + 50 > y) && (initial_y + 50 < y + height) && AlienBulletActive == false)
						{
							AlienBulletActive = true;
							alienBullet_x = x;
							alienBullet_y = (y + (height / 2));
						}
					}
				}
			}
			starty = starty + direction;
			//switch direction
			if (((starty + (row * (height + distance))) > 900) || (starty < 110))
			{
				startx = startx - (10 + boost);
				direction = direction * -1;
			}
			for (int i = 0; i < row; i++)
			{
				for (int j = 0; j < col; j++)
				{
					if (a[i][j])
					{
						if (graphicflag == 0)
						{
							x = startx + (j * (width + 50));
						}
						else
						{
							x = startx + (j * (width + distance));
						}
						y = starty + (i * (height + distance));
						if (graphicflag == 2)
						{
							myRect(x, y, x + width, y + height, 0, 255, 0, 255, 0, 0);
						}
						else if (graphicflag == 1)
						{
							myEllipse(x, y, x + width, y + height, 0, 255, 0, 255, 0, 0);
						}
						else if (graphicflag == 0)
						{
							myRect(x, y, x + width, y + height, 0, 255, 0, 255, 0, 0);
							myRect(x, y + 2, x - 35, y + 15, 255, 0, 0, 0, 255, 0);
							myRect(x, y + height - 2, x - 35, y + height - 15, 255, 0, 0, 0, 255, 0);
						}
						//collision detection
						if (bullet_x + 10 > x && bullet_x < x + width &&
							bullet_y + 10 > y && bullet_y < y + height)
						{
							bulletActive = false;
							if (graphicflag == 2)
							{
								myRect(x, y, x + width, y + height, 0, 0, 255, 0, 0, 255);
							}
							else if (graphicflag == 1)
							{
								myEllipse(x, y, x + width, y + height, 0, 0, 255, 0, 0, 255);
							}
							else if (graphicflag == 0)
							{
								myRect(x, y, x + width, y + height, 0, 0, 255, 0, 0, 255);
								myRect(x, y + 2, x - 35, y + 15, 0, 0, 255, 0, 0, 255);
								myRect(x, y + height - 2, x - 35, y + height - 15, 0, 0, 255, 0, 0, 255);
							}
							myRect(bullet_x, bullet_y, bullet_x + 10, bullet_y + 10, 0, 0, 255, 0, 0, 255);
							bullet_x = -5;
							bullet_y = -5;
							a[i][j] = false;
							myRect(780, 40, 1000, 100, 255, 255, 255, 255, 0, 0);
							score = score + 10;
						}
					}
				}
			}
			Sleep(20);
			//bullet firing
			if (bulletActive)
			{
				myRect(bullet_x, bullet_y, bullet_x + 10, bullet_y + 10, 0, 0, 255, 0, 0, 255);
				bullet_x = bullet_x + bullet_speed;
				if (graphicflag == 0)
				{
					if (bullet_x > startx + (col * (width + 50)))
					{
						bulletActive = false;
					}
					else
					{
						myRect(bullet_x, bullet_y, bullet_x + 10, bullet_y + 10, 255, 255, 0, 255, 255, 0);
					}
				}
				else
				{
					if (bullet_x > startx + (col * (width + distance)))
					{
						bulletActive = false;
					}
					else
					{
						myRect(bullet_x, bullet_y, bullet_x + 10, bullet_y + 10, 255, 255, 0, 255, 255, 0);
					}
				}
			}
			if (AlienBulletActive)
			{
				myRect(alienBullet_x, alienBullet_y, alienBullet_x + 10, alienBullet_y + 10, 0, 0, 255, 0, 0, 255);
				alienBullet_x = alienBullet_x - alienBulletSpeed;
				if (alienBullet_x < initial_x + 55)
				{
					AlienBulletActive = false;
					if ((alienBullet_y > initial_y) && (alienBullet_y < initial_y + 100))
					{
						myRect(100, 40, 600, 100, 255, 255, 255, 255, 0, 0);
						lives--;
					}
				}
				else
				{
					myRect(alienBullet_x, alienBullet_y, alienBullet_x + 10, alienBullet_y + 10, 255, 255, 0, 255, 255, 0);

				}
			}
			bool keypressed = isKeyPressed(whichkey);
			if (keypressed)
			{
				//our spaceship movement
				if (whichkey == 3)
				{
					myRect(initial_x + 30, initial_y + 20, initial_x + 60, initial_y + 80, 0, 0, 255, 0, 0, 255);
					myRect(initial_x, initial_y + 90, initial_x - 40, initial_y + 80, 0, 0, 255, 0, 0, 255);
					myRect(initial_x, initial_y + 10, initial_x - 40, initial_y + 20, 0, 0, 255, 0, 0, 255);
					myRect(initial_x, initial_y, initial_x + 30, initial_y + 100, 0, 0, 255, 0, 0, 255);
					if (initial_x + 20 < 1600)
					{
						initial_x = initial_x + 20;
						myRect(initial_x + 30, initial_y + 20, initial_x + 60, initial_y + 80, 255, 0, 0, 0, 0, 0);
						myRect(initial_x, initial_y + 90, initial_x - 40, initial_y + 80, 0, 255, 0, 255, 165, 0);
						myRect(initial_x, initial_y + 10, initial_x - 40, initial_y + 20, 0, 255, 0, 255, 165, 0);
						myRect(initial_x, initial_y, initial_x + 30, initial_y + 100, 0, 255, 0, 0, 255, 0);
					}
				}
				if (whichkey == 1)
				{
					myRect(initial_x + 30, initial_y + 20, initial_x + 60, initial_y + 80, 0, 0, 255, 0, 0, 255);
					myRect(initial_x, initial_y + 90, initial_x - 40, initial_y + 80, 0, 0, 255, 0, 0, 255);
					myRect(initial_x, initial_y + 10, initial_x - 40, initial_y + 20, 0, 0, 255, 0, 0, 255);
					myRect(initial_x, initial_y, initial_x + 30, initial_y + 100, 0, 0, 255, 0, 0, 255);
					if (initial_x - 20 > 200)
					{
						initial_x = initial_x - 20;
						myRect(initial_x + 30, initial_y + 20, initial_x + 60, initial_y + 80, 255, 0, 0, 0, 0, 0);
						myRect(initial_x, initial_y + 90, initial_x - 40, initial_y + 80, 0, 255, 0, 255, 165, 0);
						myRect(initial_x, initial_y + 10, initial_x - 40, initial_y + 20, 0, 255, 0, 255, 165, 0);
						myRect(initial_x, initial_y, initial_x + 30, initial_y + 100, 0, 255, 0, 0, 255, 0);
					}
				}
				if (whichkey == 2)
				{
					myRect(initial_x + 30, initial_y + 20, initial_x + 60, initial_y + 80, 0, 0, 255, 0, 0, 255);
					myRect(initial_x, initial_y + 90, initial_x - 40, initial_y + 80, 0, 0, 255, 0, 0, 255);
					myRect(initial_x, initial_y + 10, initial_x - 40, initial_y + 20, 0, 0, 255, 0, 0, 255);
					myRect(initial_x, initial_y, initial_x + 30, initial_y + 100, 0, 0, 255, 0, 0, 255);
					if (initial_y - 20 > 100)
					{
						initial_y = initial_y - 20;
						myRect(initial_x + 30, initial_y + 20, initial_x + 60, initial_y + 80, 255, 0, 0, 0, 0, 0);
						myRect(initial_x, initial_y + 90, initial_x - 40, initial_y + 80, 0, 255, 0, 255, 165, 0);
						myRect(initial_x, initial_y + 10, initial_x - 40, initial_y + 20, 0, 255, 0, 255, 165, 0);
						myRect(initial_x, initial_y, initial_x + 30, initial_y + 100, 0, 255, 0, 0, 255, 0);
					}
				}
				if (whichkey == 4)
				{
					myRect(initial_x + 30, initial_y + 20, initial_x + 60, initial_y + 80, 0, 0, 255, 0, 0, 255);
					myRect(initial_x, initial_y + 90, initial_x - 40, initial_y + 80, 0, 0, 255, 0, 0, 255);
					myRect(initial_x, initial_y + 10, initial_x - 40, initial_y + 20, 0, 0, 255, 0, 0, 255);
					myRect(initial_x, initial_y, initial_x + 30, initial_y + 100, 0, 0, 255, 0, 0, 255);
					if (initial_y + 20 < 850)
					{
						initial_y = initial_y + 20;
						myRect(initial_x + 30, initial_y + 20, initial_x + 60, initial_y + 80, 255, 0, 0, 0, 0, 0);
						myRect(initial_x, initial_y + 90, initial_x - 40, initial_y + 80, 0, 255, 0, 255, 165, 0);
						myRect(initial_x, initial_y + 10, initial_x - 40, initial_y + 20, 0, 255, 0, 255, 165, 0);
						myRect(initial_x, initial_y, initial_x + 30, initial_y + 100, 0, 255, 0, 0, 255, 0);
					}
				}
				if (whichkey == 6)
				{
					if (!bulletActive)
					{
						bulletActive = true;
						bullet_x = initial_x + 60;
						bullet_y = initial_y + 45;
						myRect(bullet_x, bullet_y, bullet_x + 10, bullet_y + 10, 255, 255, 0, 255, 255, 0);
					}
				}
				if (whichkey == 7)
				{
					PlaySound(NULL, NULL, 0);
					pausef = 1;
					break;
				}
			}
			//gameover
			if (((score == 510) || (initial_x + 30 >= startx)) || (lives < 1))
			{
				PlaySound(NULL, NULL, 0);
				PlaySound(L"Breaking.wav", NULL, SND_FILENAME | SND_ASYNC);
				gameflag = 1;
				myRect(0, 0, 2000, 2000, 0, 0, 0, 0, 0, 0);
				for (int i = 0; i < 5; i++)
				{
					if (score > scores[i])
					{
						for (int j = 4; j > i; j--)
						{
							scores[j] = scores[j - 1];
						}
						scores[i] = score;
						break;
					}
				}
				ofstream out("highscore.txt");
				for (int i = 0; i < 5; i++)
				{
					out << scores[i] << endl;
				}
				if ((initial_x + 30 >= startx) || (lives < 1))
				{
					drawText(100, 500, 400, 255, 0, 0, "Game Over");
				}
				else if (score == 510)
				{
					drawText(100, 500, 400, 255, 0, 0, "You Won");
				}
				break;
			}
		}
		if (pausef == 1)
		{
			system("cls");
			//this is the pause menu
			myRect(200, 20, 1700, 200, 255, 0, 0, 255, 0, 0);
			drawText(50, 600, 40, 255, 255, 255, "GAme    paused");
			myRect(840, 380, 1050, 480, 255, 0, 0, 0, 100, 255); //resume
			int pauseflag = 0;
			int initial_x = 1200;
			int initial_y = 350;
			int final_x = 1210;
			int final_y = 380;
			//bullets
			myRect(initial_x, initial_y, final_x, final_y, 255, 255, 0, 255, 255, 0);
			myRect(initial_x + 100, initial_y + 100, final_x + 100, final_y + 100, 255, 255, 0, 255, 255, 0);
			myRect(initial_x + 200, initial_y + 200, final_x + 200, final_y + 200, 255, 255, 0, 255, 255, 0);
			myRect(initial_x, initial_y + 200, final_x, final_y + 200, 255, 255, 0, 255, 255, 0);
			myRect(initial_x + 100, initial_y + 300, final_x + 100, final_y + 300, 255, 255, 0, 255, 255, 0);
			myRect(initial_x + 500, initial_y, final_x + 500, final_y, 255, 255, 0, 255, 255, 0);
			myRect(initial_x + 400, initial_y + 100, final_x + 400, final_y + 100, 255, 255, 0, 255, 255, 0);
			myRect(initial_x + 250, initial_y + 100, final_x + 250, final_y + 100, 255, 255, 0, 255, 255, 0);
			myRect(initial_x + 250, initial_y - 20, final_x + 250, final_y - 20, 255, 255, 0, 255, 255, 0);
			myRect(initial_x + 350, initial_y + 200, final_x + 350, final_y + 200, 255, 255, 0, 255, 255, 0);
			myRect(initial_x + 500, initial_y + 200, final_x + 500, final_y + 200, 255, 255, 0, 255, 255, 0);
			myRect(initial_x + 400, initial_y + 300, final_x + 400, final_y + 300, 255, 255, 0, 255, 255, 0);
			//bullets
			initial_x = 200;
			initial_y = 350;
			final_x = 210;
			final_y = 380;
			myRect(initial_x, initial_y, final_x, final_y, 255, 255, 0, 255, 255, 0);
			myRect(initial_x + 100, initial_y + 100, final_x + 100, final_y + 100, 255, 255, 0, 255, 255, 0);
			myRect(initial_x + 200, initial_y + 200, final_x + 200, final_y + 200, 255, 255, 0, 255, 255, 0);
			myRect(initial_x, initial_y + 200, final_x, final_y + 200, 255, 255, 0, 255, 255, 0);
			myRect(initial_x + 100, initial_y + 300, final_x + 100, final_y + 300, 255, 255, 0, 255, 255, 0);
			myRect(initial_x + 500, initial_y, final_x + 500, final_y, 255, 255, 0, 255, 255, 0);
			myRect(initial_x + 400, initial_y + 100, final_x + 400, final_y + 100, 255, 255, 0, 255, 255, 0);
			myRect(initial_x + 250, initial_y + 100, final_x + 250, final_y + 100, 255, 255, 0, 255, 255, 0);
			myRect(initial_x + 250, initial_y - 20, final_x + 250, final_y - 20, 255, 255, 0, 255, 255, 0);
			myRect(initial_x + 350, initial_y + 200, final_x + 350, final_y + 200, 255, 255, 0, 255, 255, 0);
			myRect(initial_x + 500, initial_y + 200, final_x + 500, final_y + 200, 255, 255, 0, 255, 255, 0);
			myRect(initial_x + 400, initial_y + 300, final_x + 400, final_y + 300, 255, 255, 0, 255, 255, 0);
			while (true)
			{
				drawText(30, 850, 400, 255, 255, 255, "Resume");
				drawText(30, 810, 550, 255, 255, 255, "save game");
				drawText(30, 880, 700, 255, 255, 255, "Exit");
				int whichkey;
				bool keypressed = isKeyPressed(whichkey);
				if (keypressed)
				{
					if ((whichkey == 4) && (pauseflag == 0))
					{
						myRect(840, 380, 1050, 480, 0, 0, 0, 0, 0, 0);
						myRect(800, 530, 1100, 630, 255, 0, 0, 0, 100, 255);
						pauseflag = 1;
						continue;
					}
					if ((whichkey == 2) && (pauseflag == 1))
					{
						myRect(800, 530, 1100, 630, 0, 0, 0, 0, 0, 0);
						myRect(840, 380, 1050, 480, 255, 0, 0, 0, 100, 255);
						pauseflag = 0;
						continue;
					}
					if ((whichkey == 4) && (pauseflag == 1))
					{
						myRect(800, 530, 1100, 630, 0, 0, 0, 0, 0, 0);
						myRect(870, 680, 1050, 780, 255, 0, 0, 0, 100, 255);
						pauseflag = 2;
						continue;
					}
					if ((whichkey == 2) && (pauseflag == 2))
					{
						myRect(870, 680, 1050, 780, 0, 0, 0, 0, 0, 0);
						myRect(800, 530, 1100, 630, 255, 0, 0, 0, 100, 255);
						pauseflag = 1;
						continue;
					}
					if ((whichkey == 5) && (pauseflag == 0))
					{
						system("cls");
						if (musicflag == 0)
						{
							PlaySound(L"mario.wav", NULL, SND_FILENAME | SND_ASYNC);
						}
						else
						{
							PlaySound(L"death.wav", NULL, SND_FILENAME | SND_ASYNC);
						}
						goto r;
					}
					//save
					if ((whichkey == 5) && (pauseflag == 1))
					{
						drawText(20, 850, 900, 150, 50, 255, "game saved");
						ofstream out("save.txt");
						out << score << endl;
						for (int i = 0; i < row; i++)
						{
							for (int j = 0; j < col; j++)
							{
								out << a[i][j] << endl;
							}
						}
						out << alienBulletSpeed << endl;
						out << boost << endl;
						out << startx << endl;
						out << starty << endl;
						out << lives << endl;
						out << musicflag;
						out.close();
					}
					if ((whichkey == 5) && (pauseflag == 2))
					{
						system("cls");
						PlaySound(L"GOT.wav", NULL, SND_FILENAME | SND_ASYNC);
						goto a;
					}
				}
			}
		}
		//indicates that game is over
		else if (gameflag == 1)
		{
			while (true)
			{
				int whichkey;
				bool keypressed = isKeyPressed(whichkey);
				if (keypressed)
				{
					if (whichkey == 7)
					{
						system("cls");
						PlaySound(L"GOT.wav", NULL, SND_FILENAME | SND_ASYNC);
						goto a;
					}
				}
			}
		}
	}
	//highscore
	else if (flag == 2)
	{
		PlaySound(L"inter.wav", NULL, SND_FILENAME | SND_ASYNC);
		drawText(50, 700, 300, 255, 255, 0, "highscores");
		int score;
		int y = 450;
		ifstream in("highscore.txt");
		for (int i = 0; i < 5; i++)
		{
			in >> score;
			drawText(20, 925, y, 255, 255, 255, "", true, score);
			y = y + 50;
		}
		while (true)
		{
			int whichkey;
			bool keypressed = isKeyPressed(whichkey);
			if (keypressed)
			{
				if (whichkey == 7)
				{
					system("cls");
					PlaySound(L"GOT.wav", NULL, SND_FILENAME | SND_ASYNC);
					goto a;
				}
			}
		}
	}
}
