#include <GLFW/glfw3.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

enum {
	COLOR_MODE_CYAN,
	COLOR_MODE_MULTI
};

int colormode = COLOR_MODE_CYAN;

GLfloat pscale = 1.f;

void KEYBOARD(GLFWwindow *window, int key, int scancode, int action, int mods) {
	if (action != GLFW_PRESS) return;
	switch(key) {
		case GLFW_KEY_Q:
			if (colormode == COLOR_MODE_CYAN) colormode = COLOR_MODE_MULTI;
			else colormode = COLOR_MODE_CYAN;
		break;
		case GLFW_KEY_E:
			if (pscale == 1.f) pscale = 2.f;
			else if (pscale == 2.f) pscale = 0.5f;
			else if (pscale == 0.5f) pscale = 1.f;

			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			glOrtho(0.0, SCREEN_WIDTH * pscale, SCREEN_HEIGHT * pscale, 0.0, 1.0, -1.0);
		break;
	}
}

void render() {
	glClearColor(0.f, 0.f, 0.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();

	//Move to center of the screen
	glTranslatef( SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f, 0.f );

	glBegin(GL_QUADS);
	if (colormode == COLOR_MODE_CYAN) {
		glColor3f( 0.f, 1.f, 1.f );
		glVertex2f( -50.f, -50.f );
		glVertex2f(  50.f, -50.f );
		glVertex2f(  50.f,  50.f );
		glVertex2f( -50.f,  50.f );	
	}
	else {
		glColor3f( 1.f, 0.f, 0.f ); glVertex2f( -50.f, -50.f );
		glColor3f( 1.f, 1.f, 0.f ); glVertex2f(  50.f, -50.f );
		glColor3f( 0.f, 1.f, 0.f ); glVertex2f(  50.f,  50.f );
		glColor3f( 0.f, 0.f, 1.f ); glVertex2f( -50.f,  50.f );
	}
	glEnd();
}

void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho( 0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0, 1.0, -1.0 );


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	GLenum error = glGetError();
	if (error != GL_NO_ERROR) {
//		printf("Error initialising OpenGL: %s\n", gluErrorString(error));
	//	return -1;
	}
}

int main() {

	GLFWwindow *window;
	if (!glfwInit()) return -1;

	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Matrices and Coloring Polygons", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetKeyCallback(window, KEYBOARD);
	init();


	while (!glfwWindowShouldClose(window)) {
		render();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
