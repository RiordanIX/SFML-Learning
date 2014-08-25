#include "Aircraft.hpp"

Textures::ID toTextureID(Aircraft::Type type)
{
	switch (type)
	{
	case Aircraft::Raptor:
		return Textures::Raptor;
	case Aircraft::Airplane:
		return Textures::Airplane;
	}
}

Aircraft::Aircraft(Type type, const TextureHolder& textures)
: m_Type(type)
, m_Sprite(textures.get(toTextureID(type)))
{
	sf::FloatRect bounds = m_Sprite.getLocalBounds();
	m_Sprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}

void Aircraft::drawCurrent(sf::RenderTarget& target,
						   sf::RenderStates states) const
{
	target.draw(m_Sprite, states);
}
