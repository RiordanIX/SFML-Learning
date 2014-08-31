#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "SceneNode.hpp"
#include "ResourceHolder.hpp"
#include <SFML/Graphics.hpp>

typedef ResourceHolder<sf::Texture, Textures::ID> TextureHolder;

class Entity : public SceneNode
{
public:
	void			setVelocity(sf::Vector2f velocity);
	void			setVelocity(float vx, float vy);
	sf::Vector2f	getVelocity() const;

private:
	sf::Vector2f	m_Velocity;
	virtual void	updateCurrent(sf::Time dt);
};


#endif // ENTITY_HPP
