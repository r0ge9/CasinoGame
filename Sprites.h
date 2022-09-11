#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Button
{
public:
	Texture texture;
	Sprite sprite;
	String file = "images/";
	int x = 0;
	int y = 0;

	Button(String texture_file, int x, int y)
	{
		this->texture.loadFromFile(this->file + texture_file);
		this->sprite.setTexture(texture);
		this->x = x;
		this->y = y;
		sprite.setPosition(this->x, this->y);
	}

};

class text
{
	Text nn;
	Font font;
	int x = 0;
	int y = 0;
public:
	

	text()
	{
		font.loadFromFile("unispace bd.ttf");
		nn.setFont(font);
		nn.setOutlineColor(Color::Black);
		nn.setOutlineThickness(3);
		nn.setCharacterSize(26);
		
	}

	void set_text(string s)
	{
		nn.setString( s);
	}

	void set_pos(int x, int y)
	{
		nn.setPosition(x, y);
	}

	void draw_user(RenderWindow& win)
	{
		win.draw(nn);
	}
};