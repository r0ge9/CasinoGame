#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>

#define DELETE_KEY 8

using namespace sf;
using namespace std;

class textBox
{
public:
	Text balanceBet;
	int betValue = 0000;
	string h;
	

	void input(Event input, bool Enable)
	{
		if (Enable == true)
		{
			int charTyped = input.text.unicode;
			if (charTyped <= 57 && charTyped >= 48)
			{
				if (charTyped == 48)
				{
					add(0);
					sleep(seconds(0.1));
				}
				if (charTyped == 49)
				{
					add(1);
					sleep(seconds(0.1));
				}
				if (charTyped == 50)
				{
					add(2);
					sleep(seconds(0.1));
				}
				if (charTyped == 51)
				{
					add(3);
					sleep(seconds(0.1));
				}
				if (charTyped == 52)
				{
					add(4);
					sleep(seconds(0.1));
				}
				if (charTyped == 53)
				{
					add(5);
					sleep(seconds(0.1));
				}
				if (charTyped == 54)
				{
					add(6);
					sleep(seconds(0.1));
				}
				if (charTyped == 55)
				{
					add(7);
					sleep(seconds(0.1));
				}
				if (charTyped == 56)
				{
					add(8);
					sleep(seconds(0.1));
				}
				if (charTyped == 57)
				{
					add(9);
					sleep(seconds(0.1));
				}
			}
			else if (betValue > 0 && charTyped == DELETE_KEY)
			{
				deleteLastChar();
				sleep(seconds(0.1));
			}
		}
	}

	void drawBetBar(RenderWindow& window)
	{
		Font font;
		font.loadFromFile("unispace bd.ttf");
		balanceBet.setFont(font);
		balanceBet.setOutlineColor(Color::Black);
		balanceBet.setOutlineThickness(2);
		balanceBet.setPosition(0, 600);
		balanceBet.setCharacterSize(30);
		h = "Bet value: " + to_string(betValue);
		balanceBet.setString(h);
		window.draw(balanceBet);
	}
	void addButton(int num)
	{
		betValue += num;
	}
private:
	void add(int value)
	{
		betValue = betValue * 10 + value;
	}
	void deleteLastChar()
	{
		betValue /= 10;
	}
};