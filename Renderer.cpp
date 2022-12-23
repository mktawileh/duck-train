#include "Renderer.h"

namespace Renderer
{
	// Size of shadow map
	const int shadowMapSize = 1024;

	// Textures
	GLuint shadowMapTexture;

	// Called for initiation
	// bool Init(void)
	// {
	// 	// Check for necessary extensions
	// 	if (!GLEE_ARB_depth_texture || !GLEE_ARB_shadow)
	// 	{
	// 		printf("I require ARB_depth_texture and ARB_shadow extensionsn\n");
	// 		return false;
	// 	}

	// 	// Load identity modelview
	// 	glMatrixMode(GL_MODELVIEW);
	// 	glLoadIdentity();

	// 	// Shading states
	// 	glShadeModel(GL_SMOOTH);
	// 	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	// 	glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
	// 	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	// 	// Depth states
	// 	glClearDepth(1.0f);
	// 	glDepthFunc(GL_LEQUAL);
	// 	glEnable(GL_DEPTH_TEST);

	// 	glEnable(GL_CULL_FACE);

	// 	// We use glScale when drawing the scene
	// 	glEnable(GL_NORMALIZE);

	// 	// Create the shadow map texture
	// 	glGenTextures(1, &shadowMapTexture);
	// 	glBindTexture(GL_TEXTURE_2D, shadowMapTexture);
	// 	glTexImage2D(GL_TEXTURE_2D, 0, GL_DEPTH_COMPONENT, shadowMapSize, shadowMapSize, 0,
	// 				 GL_DEPTH_COMPONENT, GL_UNSIGNED_BYTE, NULL);
	// 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	// 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	// 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	// 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);

	// 	// Use the color as the ambient and diffuse material
	// 	glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
	// 	glEnable(GL_COLOR_MATERIAL);

	// 	// White specular material color, shininess 16
	// 	glMaterialfv(GL_FRONT, GL_SPECULAR, Vec4<float>(1, 1, 1, 1));
	// 	glMaterialf(GL_FRONT, GL_SHININESS, 16.0f);

	// 	// Calculate & save matrices
	// 	glPushMatrix();

	// 	glLoadIdentity();
	// 	gluPerspective(45.0f, (float)Game::windowWidth / Game::windowHeight, 1.0f, 500.0f);
	// 	glGetFloatv(GL_MODELVIEW_MATRIX, Game::cameraProjectionMatrix);

	// 	glLoadIdentity();
	// 	gluLookAt(Game::cameraPosition.x, Game::cameraPosition.y, Game::cameraPosition.z,
	// 			  0.0f, 0.0f, 0.0f,
	// 			  0.0f, 1.0f, 0.0f);
	// 	glGetFloatv(GL_MODELVIEW_MATRIX, Game::cameraViewMatrix);

	// 	glLoadIdentity();
	// 	gluPerspective(45.0f, 1.0f, 2.0f, 8.0f);
	// 	glGetFloatv(GL_MODELVIEW_MATRIX, Game::lightProjectionMatrix);

	// 	glLoadIdentity();
	// 	gluLookAt(Game::lightPosition.x, Game::lightPosition.y, Game::lightPosition.z,
	// 			  0.0f, 0.0f, 0.0f,
	// 			  0.0f, 1.0f, 0.0f);
	// 	glGetFloatv(GL_MODELVIEW_MATRIX, Game::lightViewMatrix);

	// 	glPopMatrix();

	// 	Game::InitObjects();

	// 	return true;
	// }

	// void Render(void)
	// {

	// 	// First pass - from light's point of view
	// 	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// 	glMatrixMode(GL_PROJECTION);
	// 	glLoadMatrixf(Game::lightProjectionMatrix);

	// 	glMatrixMode(GL_MODELVIEW);
	// 	glLoadMatrixf(Game::lightViewMatrix);

	// 	// Use viewport the same size as the shadow map
	// 	glViewport(0, 0, shadowMapSize, shadowMapSize);

	// 	// Draw back faces into the shadow map
	// 	glCullFace(GL_FRONT);

	// 	// Disable color writes, and use flat shading for speed
	// 	glShadeModel(GL_FLAT);
	// 	glColorMask(0, 0, 0, 0);

	// 	// Draw the scene
	// 	Game::RedrawScene();

	// 	// Read the depth buffer into the shadow map texture
	// 	glBindTexture(GL_TEXTURE_2D, shadowMapTexture);
	// 	glCopyTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, 0, 0, shadowMapSize, shadowMapSize);

	// 	// restore states
	// 	glCullFace(GL_BACK);
	// 	glShadeModel(GL_SMOOTH);
	// 	glColorMask(1, 1, 1, 1);

	// 	// 2nd pass - Draw from camera's point of view
	// 	glClear(GL_DEPTH_BUFFER_BIT);

	// 	glMatrixMode(GL_PROJECTION);
	// 	glLoadMatrixf(Game::cameraProjectionMatrix);

	// 	glMatrixMode(GL_MODELVIEW);
	// 	glLoadMatrixf(Game::cameraViewMatrix);

	// 	glViewport(0, 0, Game::windowWidth, Game::windowHeight);

	// 	// Use dim light to represent shadowed areas
	// 	glLightfv(GL_LIGHT1, GL_POSITION, Vec4<float>(Game::lightPosition));
	// 	glLightfv(GL_LIGHT1, GL_AMBIENT, Vec4<float>(0.2f));
	// 	glLightfv(GL_LIGHT1, GL_DIFFUSE, Vec4<float>(0.2f));
	// 	glLightfv(GL_LIGHT1, GL_SPECULAR, Vec4<float>(0, 0, 0, 1));
	// 	glEnable(GL_LIGHT1);
	// 	glEnable(GL_LIGHTING);

	// 	Game::RedrawScene();

	// 	// 3rd pass
	// 	// Draw with bright light
	// 	glLightfv(GL_LIGHT1, GL_DIFFUSE, Vec4<float>(1));
	// 	glLightfv(GL_LIGHT1, GL_SPECULAR, Vec4<float>(1));

	// 	// Calculate texture matrix for projection
	// 	// This matrix takes us from eye space to the light's clip space
	// 	// It is postmultiplied by the inverse of the current view matrix when specifying texgen
	// 	static Matrix4<float> biasMatrix(0.5f, 0.0f, 0.0f, 0.0f,
	// 									 0.0f, 0.5f, 0.0f, 0.0f,
	// 									 0.0f, 0.0f, 0.5f, 0.0f,
	// 									 0.5f, 0.5f, 0.5f, 1.0f); // bias from [-1, 1] to [0, 1]
	// 	Matrix4<float> textureMatrix = biasMatrix * Game::lightProjectionMatrix * Game::lightViewMatrix;

	// 	// Set up texture coordinate generation.
	// 	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	// 	glTexGenfv(GL_S, GL_EYE_PLANE, textureMatrix.GetRow(0));
	// 	glEnable(GL_TEXTURE_GEN_S);

	// 	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	// 	glTexGenfv(GL_T, GL_EYE_PLANE, textureMatrix.GetRow(1));
	// 	glEnable(GL_TEXTURE_GEN_T);

	// 	glTexGeni(GL_R, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	// 	glTexGenfv(GL_R, GL_EYE_PLANE, textureMatrix.GetRow(2));
	// 	glEnable(GL_TEXTURE_GEN_R);

	// 	glTexGeni(GL_Q, GL_TEXTURE_GEN_MODE, GL_EYE_LINEAR);
	// 	glTexGenfv(GL_Q, GL_EYE_PLANE, textureMatrix.GetRow(3));
	// 	glEnable(GL_TEXTURE_GEN_Q);

	// 	// Bind & enable shadow map texture
	// 	glBindTexture(GL_TEXTURE_2D, shadowMapTexture);
	// 	glEnable(GL_TEXTURE_2D);

	// 	// Enable shadow comparison
	// 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_MODE_ARB, GL_COMPARE_R_TO_TEXTURE);

	// 	// Shadow comparison should be true (ie not in shadow) if r<=texture
	// 	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_COMPARE_FUNC_ARB, GL_LEQUAL);

	// 	// Shadow comparison should generate an INTENSITY result
	// 	glTexParameteri(GL_TEXTURE_2D, GL_DEPTH_TEXTURE_MODE_ARB, GL_INTENSITY);

	// 	// Set alpha test to discard false comparisons
	// 	glAlphaFunc(GL_GEQUAL, 0.99f);
	// 	glEnable(GL_ALPHA_TEST);

	// 	Game::RedrawScene();

	// 	// Disable textures and texgen
	// 	glDisable(GL_TEXTURE_2D);

	// 	glDisable(GL_TEXTURE_GEN_S);
	// 	glDisable(GL_TEXTURE_GEN_T);
	// 	glDisable(GL_TEXTURE_GEN_R);
	// 	glDisable(GL_TEXTURE_GEN_Q);

	// 	// Restore other states
	// 	glDisable(GL_LIGHTING);
	// 	glDisable(GL_ALPHA_TEST);

	// 	// reset matrices
	// 	glMatrixMode(GL_PROJECTION);
	// 	glPopMatrix();
	// 	glMatrixMode(GL_MODELVIEW);
	// 	glPopMatrix();

	// 	glFlush();
	// 	// glFinish();

	// 	glutSwapBuffers();

	// 	// TODO: frame rating
	// 	glutPostRedisplay();
	// }

	bool Init()
	{
		// glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT1);
		glEnable(GL_LIGHT2);

		// Depth states
		glClearDepth(1.0f);
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_NORMALIZE);

		// Calculate & save matrices

		// Projection Matricx
		glViewport(0, 0, Game::windowWidth, Game::windowHeight);
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(60.0f, (float)Game::windowWidth / Game::windowHeight, 1.0f, 600.0f);

		// Model-view Matrix
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glPushMatrix();
		gluLookAt(Game::cameraPosition.x, Game::cameraPosition.y, Game::cameraPosition.z,
				  Game::lookingAt.x, Game::lookingAt.y, Game::lookingAt.z,
				  0.0f, 1.0f, 0.0f);
		glGetFloatv(GL_MODELVIEW_MATRIX, Game::cameraViewMatrix);
		glPopMatrix();

		glEnable(GL_TEXTURE_2D);

		Game::InitObjects();

		return true;
	}

	void Render()
	{

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glLoadMatrixf(Game::cameraViewMatrix);

		glLightfv(GL_LIGHT1, GL_POSITION, Vec4<float>(Game::lightPosition));
		// glLightfv(GL_LIGHT1, GL_AMBIENT, Vec3<float>(0.2));
		glLightfv(GL_LIGHT1, GL_DIFFUSE, Vec3<float>(1));
		glLightfv(GL_LIGHT1, GL_SPECULAR, Vec3<float>(0.8));

		// GLfloat light1_ambient[] = { 1.0, 0.85, 0.09, 0.2 };
		GLfloat light1_diffuse[] = {1.0, 0.85, 0.09, 1.0};
		GLfloat light1_specular[] = {1.0, 0.95, 0.39, 1.0};
		GLfloat spot_direction[] = {0.0, -1.0, 0.0};

		// glLightfv(GL_LIGHT2, GL_AMBIENT, light1_ambient);
		glLightfv(GL_LIGHT2, GL_DIFFUSE, light1_diffuse);
		glLightfv(GL_LIGHT2, GL_SPECULAR, light1_specular);
		glLightfv(GL_LIGHT2, GL_POSITION, Game::lightPosition2);
		glLightf(GL_LIGHT2, GL_CONSTANT_ATTENUATION, 0.1);
		glLightf(GL_LIGHT2, GL_LINEAR_ATTENUATION, 0.05);
		glLightf(GL_LIGHT2, GL_QUADRATIC_ATTENUATION, 0.01);

		glLightf(GL_LIGHT2, GL_SPOT_CUTOFF, 70.0f);
		glLightfv(GL_LIGHT2, GL_SPOT_DIRECTION, spot_direction);
		// glLightf(GL_LIGHT2, GL_SPOT_EXPONENT, 2.0);

		Game::RedrawScene();

		glutSwapBuffers();
		std::cout << glutGetWindow() << '\n';
		glutPostRedisplay();
	}
};