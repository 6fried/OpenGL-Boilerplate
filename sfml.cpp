/**
 * @file sfml.cpp
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2022-09-20
 *
 * @copyright Copyright (c) 2022
 *
 * Compile -flags:
 * 		-lsfml-system -lsfml-window
 *
 */

#define GLEW_STATIC
#include <GL/glew.h>

#include <SFML/Window.hpp>

int main(){
	// Context Creation Settings
	sf::ContextSettings settings;
	settings.depthBits = 24;
	settings.stencilBits = 8;
	settings.antialiasingLevel = 2;

	// Request OpenGL  version 3.2
	settings.majorVersion = 3;
	settings.minorVersion = 2;
	settings.attributeFlags = sf::ContextSettings::Core;

	// Create Window
	sf::Window window(sf::VideoMode(600, 600), "OpenGL", sf::Style::Close, settings);

	// Initialize glew
	glewExperimental = GL_TRUE;
	glewInit();

	// Make sure you've set up your project correctly
	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);

	printf("%u\n", vertexBuffer);

	bool running = true;
	while (running)
	{
		sf::Event windowEvent;
		while (window.pollEvent(windowEvent)){
			switch(windowEvent.type){
				case sf::Event::Closed:
					running = false;
					break;
				
				case sf::Event::KeyPressed:
					if(windowEvent.key.code == sf::Keyboard::Escape)
						running = false;
					break;
				}
		}
	}

	return 0;
}