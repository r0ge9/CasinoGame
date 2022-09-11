#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <windows.h>

using namespace sf;
using namespace std;

class Button {
private:
    Vector2f position;
    Vector2f size;
    Vector2f normal;
    Vector2i TextureSize;
    Vector2i TextureStart;
    RenderWindow* window;
    Color ButtonColor;
    Color BorderColor;
    bool BorderSet = false, ButtonTextureEnabled = false, BorderTextureEnabled, in = true;
    float BorderSize = 0;
    Texture ButtonTexture;
    Sprite ButtonSprite;
    Mouse::Button MouseClickButton;
public:
    Button(Vector2f pos, Vector2f sizes, RenderWindow* wind) {
        position = pos;
        size = sizes;
        window = wind;
    }

    void setButtonColor(Color col) {
        ButtonColor = col;
        ButtonTextureEnabled = false;
    }

    void setButtonTexture(string name, Vector2i place, Vector2i siz) {
        TextureSize = siz, TextureStart = place;
        if (!ButtonTexture.loadFromFile(name)) MessageBeep;
        ButtonSprite.setTexture(ButtonTexture);
        ButtonTextureEnabled = true;
    }

    void setBorder(int sizew) {
        if (sizew % 2 != 0) { BorderSize = sizew + 1; }
        else BorderSize = sizew;
        BorderSet = true;
    }

    void setBorderColor(Color col) {
        BorderColor = col;
        BorderSet = true;
    }

    void setMouseClickButton(Mouse::Button click) {
        MouseClickButton = click;
    }

    bool draw() {
        if (in) normal = size;
        if (size.x > TextureSize.x || size.y > TextureSize.y) size.x = TextureSize.y; size.y = TextureSize.y;
        if (!BorderSet && !ButtonTextureEnabled) {
            RectangleShape button(size);
            button.setPosition(position);
            button.setFillColor(ButtonColor);
            (*window).draw(button);
        }
        if (!BorderSet && ButtonTextureEnabled) {
            ButtonSprite.setPosition(position);
            (*window).draw(ButtonSprite);
        }
        if (BorderSet && !ButtonTextureEnabled) {
            Vector2f BorderVecSize = { BorderSize, BorderSize };
            Vector2f BorderVecPos = { BorderSize / 2, BorderSize / 2 };

            RectangleShape button(size - BorderVecSize);
            button.setPosition(position + BorderVecPos);
            button.setFillColor(ButtonColor);

            RectangleShape border(size);
            border.setPosition(position);
            border.setFillColor(BorderColor);

            (*window).draw(border);
            (*window).draw(button);
        }
        if (BorderSet && ButtonTextureEnabled) {
            ButtonSprite.setTextureRect(IntRect(TextureStart.x, TextureStart.y, size.x - BorderSize, size.y - BorderSize));
            ButtonSprite.setPosition(position.x + BorderSize / 2, position.x + BorderSize / 2);

            RectangleShape border(normal);
            border.setPosition(position);
            border.setFillColor(BorderColor);


            RectangleShape mask(Vector2f(normal.x - BorderSize, normal.y - BorderSize));
            mask.setPosition(position.x + BorderSize / 2, position.x + BorderSize / 2);
            mask.setFillColor(Color::Black);
            in = false;

            (*window).draw(border);
            (*window).draw(mask);
            (*window).draw(ButtonSprite);
        }

        Vector2i MouseCoords = Mouse::getPosition(*window);
        Vector2u WinSize = (*window).getSize();
        if (MouseCoords.x <= WinSize.x && MouseCoords.y <= WinSize.y && MouseCoords.x >= position.x && MouseCoords.x <= position.x + normal.x && MouseCoords.y >= position.y && MouseCoords.y <= position.x + normal.y && Mouse::isButtonPressed(MouseClickButton)) {
            return TRUE;
        }
        else return FALSE;
    }

};