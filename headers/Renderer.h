#pragma once

#define WIN32_LEAN_AND_MEAN

#include "GLee/GLee.h"	// GL header file, including extensions
#include "Game.h"

namespace Renderer
{
	// Size of shadow map
	extern const int shadowMapSize;

	// Textures
	extern GLuint shadowMapTexture;

	// Called for initiation
	extern bool Init(void);

	extern void Render(void);

};