#include "components/Animation.h"

Animation::Animation(sf::Texture& texture, sf::Vector2u nrOfFrames, float frameTime)
	: m_NrOfFrames(nrOfFrames), m_FrameTime(frameTime)
{
	nrOfFrames.x = 0;
	nrOfFrames.y = 0;

	m_TextureRect.width = texture.getSize().x / (float)nrOfFrames.x;
	m_TextureRect.height = texture.getSize().y / (float)nrOfFrames.y;
}

void Animation::Update(sf::IntRect& textureRect, sf::Texture& texture, sf::Vector2u nrOfFrames, float frameTime)
{
	sf::Clock clock;

	if (clock.getElapsedTime().asSeconds() > frameTime)
	{
		if (textureRect.left > textureRect.width - (texture.getSize().x / (float)nrOfFrames.x))
		{
			textureRect.left = 0;
		}
		else
		{
			textureRect.left += (texture.getSize().x / (float)nrOfFrames.x);
		}
		clock.restart();
	}
}

Animation::~Animation()
{

}