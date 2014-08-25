#ifndef AIRCRAFT_HPP
#define AIRCRAFT_HPP

#include "Entity.hpp"

class Aircraft : public Entity
{

public:
	enum Type
	{
		Airplane,
		Raptor
	};

public:
	explicit		Aircraft(Type type, const TextureHolder& textures);
	virtual void	drawCurrent(sf::RenderTarget& target,
								sf::RenderStates states) const;

private:
	Type			m_Type;
	sf::Sprite		m_Sprite;
};

#endif // AIRCRAFT_HPP
