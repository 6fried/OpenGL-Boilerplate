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
 * 		-lSDL2
 *
 */

#define GLEW_STATIC
#include <GL/glew.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <stdio.h>

int main(int argc, char *argv[]){
	// OpenGL window and Context settings
	SDL_Init(SDL_INIT_VIDEO);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

	// Creae Window
	SDL_Window* window = SDL_CreateWindow("OpenGL", 100, 100, 800, 600, SDL_WINDOW_OPENGL);

	// Create OpenGL context
	SDL_GLContext context = SDL_GL_CreateContext(window);

	//Initialize glew
	glewExperimental = GL_TRUE;
	glewInit();

	// Make sure your project is well set up
	GLuint vertexBuffer;
	glGenBuffers(1, &vertexBuffer);

	printf("%u\n", vertexBuffer);

	SDL_Event windowEvent;
	while(true){
		if(SDL_PollEvent(&windowEvent)){
			if(windowEvent.type == SDL_QUIT)
				break;
			if(windowEvent.type == SDL_KEYUP && 
				windowEvent.key.keysym.sym == SDLK_ESCAPE)
				break;
		}

		SDL_GL_SwapWindow(window);
	}

	SDL_GL_DeleteContext(context);
	SDL_Quit();
	return 0;
}