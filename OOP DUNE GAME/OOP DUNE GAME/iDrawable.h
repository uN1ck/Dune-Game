#pragma once
#include <SFML\Graphics.hpp>
class iDrawable
{
public:		virtual sf::Sprite getSprite() = 0;
public:		virtual sf::Texture getTexture() = 0;
public:		virtual sf::IntRect getTextureRectangle() = 0;
};

