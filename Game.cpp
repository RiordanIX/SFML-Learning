#include "Game.hpp"

Game::Game()
: PlayerSpeed(150.f)
, m_Window(sf::VideoMode(640, 480), "SFML Application")
, m_TimePerFrame(sf::seconds(1.f/60.f))
, m_PlayerPlane(Aircraft::Airplane, textures)
, textures(Textures::Airplane, "Plane.png")
{
	m_PlayerPlane.setPosition(0.f,0.f);
}



void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (m_Window.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > m_TimePerFrame)
		{
			timeSinceLastUpdate -= m_TimePerFrame;
			processEvents();
			update(m_TimePerFrame);
		}
		render();
	}
}



void Game::processEvents()
{
	sf::Event event;
	while (m_Window.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed:
			m_Window.close();
			break;
		default:
			break;
		}
	}
}



void Game::update(sf::Time deltaTime)
{
	sf::Vector2f movement(0.f, 0.f);
	if (m_IsMovingUp)
		movement.y -= PlayerSpeed;
	if (m_IsMovingDown)
		movement.y += PlayerSpeed;
	if (m_IsMovingLeft)
		movement.x -= PlayerSpeed;
	if (m_IsMovingRight)
		movement.x += PlayerSpeed;
	if (m_IsRotatingLeft)
		m_PlayerPlane.rotate(-2.f);
	if (m_IsRotatingRight)
		m_PlayerPlane.rotate(2.f);

	m_PlayerPlane.move(movement * deltaTime.asSeconds());
}



void Game::render()
{
	m_Window.clear();
	m_Window.draw(m_PlayerPlane);
	m_Window.display();
}



void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key==sf::Keyboard::W)
		m_IsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		m_IsMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		m_IsMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		m_IsMovingRight = isPressed;
	else if (key == sf::Keyboard::Left)
		m_IsRotatingLeft = isPressed;
	else if (key == sf::Keyboard::Right)
		m_IsRotatingRight = isPressed;
}
