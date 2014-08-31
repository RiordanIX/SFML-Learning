#ifndef GAME_HPP
#define GAME_HPP

#include "ResourceHolder.hpp"
#include "Entity.hpp"
#include "Aircraft.hpp"
#include "SceneNode.hpp"
#include <SFML/Graphics.hpp>

class Game
{
public:
	Game();
	void run();

private:
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	void processEvents();
	void update(sf::Time);
	void render();

public:
	float PlayerSpeed;

private:
	sf::RenderWindow m_Window;
	sf::Time m_TimePerFrame;
	TextureHolder textures;
	Aircraft m_PlayerPlane;
	bool m_IsMovingUp, m_IsMovingDown,
		 m_IsMovingLeft, m_IsMovingRight = false;
};

#endif // GAME_HPP
