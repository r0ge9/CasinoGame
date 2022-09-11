#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Roulette
{
	Clock started;
	float time=0;
	bool stop=false;
	int red[8] = { 16,1,18,9,32,19,7,30 };
	int black[7] = { 24,33,20,28,35,22,17 };
	int firstCol[3] = { 1,7,9 };
	int secondCol[6] = { 16,17,18,19,22,24 };
	int thirdCol[4] = { 28,30,32,33 };
	int firstRow[5] = { 9,18,24,30,33 };
	int secondRow[3] = { 17,20,32 };
	int thirdRow[6] = { 1,7,16,19,22,28 };
	int firstHalf[6] = { 1,7,9,16,17,18 };
	int secondHalf[9] = { 19,20,22,24,28,30,32,33,35 };

	Clock get_timer(Clock Started)
	{
		started.restart();
		return started;
	}

	float random()
	{
		return (float)4 + rand() % 7;
	}

	float update()
	{
		return time = started.getElapsedTime().asSeconds();
	}
public:

	float timer()
	{
		get_timer(started);
		return time =  started.getElapsedTime().asSeconds();
	}

	bool stop_rol()
	{
		if (update() == random())
		{
			return  true;
		}
	}

	bool check_red(int nums[16], int ind)
	{
		for (int i = 0;i < 8;i++)
		{
			if (red[i] == nums[ind])
				return true;
		}
	}

	bool check_black(int nums[16], int ind)
	{
		for (int i = 0;i < 7;i++)
		{
			if (black[i] == nums[ind])
				return true;
		}
	}
	
	bool check_firstC(int nums[16], int ind)
	{
		for (int i = 0;i < 3;i++)
		{
			if (firstCol[i] == nums[ind])
				return true;
		}
	}

	bool check_secondC(int nums[16], int ind)
	{
		for (int i = 0;i < 6;i++)
		{
			if (secondCol[i] == nums[ind])
				return true;
		}
	}

	bool check_thirdC(int nums[16], int ind)
	{
		for (int i = 0;i < 4;i++)
		{
			if (thirdCol[i] == nums[ind])
				return true;
		}
	}

	bool check_firstR(int nums[16], int ind)
	{
		for (int i = 0;i < 5;i++)
		{
			if (firstRow[i] == nums[ind])
				return true;
		}
	}

	bool check_secondR(int nums[16], int ind)
	{
		for (int i = 0;i < 3;i++)
		{
			if (secondRow[i] == nums[ind])
				return true;
		}
	}

	bool check_thirdR(int nums[16], int ind)
	{
		for (int i = 0;i < 6;i++)
		{
			if (thirdRow[i] == nums[ind])
				return true;
		}
	}

	bool check_firstH(int nums[16], int ind)
	{
		for (int i = 0;i < 6;i++)
		{
			if (nums[ind] == firstHalf[i])
				return true;
		}
	}

	bool check_secondH(int nums[16], int ind)
	{
		for (int i = 0;i < 9;i++)
		{
			if (nums[ind] == secondHalf[i])
				return true;
		}
	}

	bool check_even(int nums[16],int ind)
	{
		for (int i = 0;i < 16;i++)
		{
			if (nums[ind]%2==0)
				return true;
		}
	}

	bool check_odd(int nums[16], int ind)
	{
		for (int i = 0;i < 16;i++)
		{
			if (nums[ind]%2!=0)
				return true;
		}
	}


};