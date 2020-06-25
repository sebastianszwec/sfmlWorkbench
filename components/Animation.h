#pragma once
#include "SFML/Graphics.hpp"

class Animation
{
public: 
	Animation(sf::Texture& texture, sf::Vector2u nrOfFrames, float frameTime);
	~Animation();

	void Update(sf::IntRect& textureRect, sf::Texture& texture, sf::Vector2u nrOfFrames, float frameTime);

public:
	sf::IntRect m_TextureRect;

private:
	sf::Vector2u m_NrOfFrames;
	sf::Vector2u m_CurrentFrame;

	float m_FrameTime;
};