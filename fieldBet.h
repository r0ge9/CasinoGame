#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstring>

#define DELETE_KEY 8

using namespace sf;
using namespace std;

class fieldBetBox
{
public:
	Text fieldBet;
	int fieldValue = NULL;
	string textField;
	


	void inputField(Event input, bool Enable)
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
			else if (fieldValue > 0 && charTyped == DELETE_KEY)
			{
				deleteLastChar();
			}
		}
	}

	void drawFieldBar(RenderWindow& window)
	{
		Font font;
		font.loadFromFile("unispace bd.ttf");
		fieldBet.setFont(font);
		fieldBet.setOutlineColor(Color::Black);
		fieldBet.setOutlineThickness(2);
		fieldBet.setPosition(0, 550);
		fieldBet.setCharacterSize(30);
		textField = "Number: " + to_string(fieldValue);
		fieldBet.setString(textField);
		window.draw(fieldBet);
	}
	void addButton(int num)
	{
		fieldValue += num;
	}

private:
	void add(int value)
	{
		fieldValue = fieldValue * 10 + value;
	}
	void deleteLastChar()
	{
		fieldValue /= 10;
	}
};
