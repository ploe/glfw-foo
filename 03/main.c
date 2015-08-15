#include <GLFW/glfw3.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

enum {
	VIEWPORT_MODE_FULL,
	VIEWPORT_MODE_HALF_CENTER,
	VIEWPORT_MODE_HALF_TOP,
	VIEWPORT_MODE_QUAD,
	VIEWPORT_MODE_RADAR
};

int vmode = VIEWPORT_MODE_FULL;

GLfloat pscale = 1.f;

void KEYBOARD(GLFWwindow *window, int key, int scancode, int action, int mods) {
	if (action != GLFW_PRESS) return;
	switch(key) {
		case GLFW_KEY_Q:
			vmode++;
			if (vmode > VIEWPORT_MODE_RADAR) vmode = VIEWPORT_MODE_FULL;
		break;
	}
}

void render() {
	glClearColor(0.f, 0.f, 0.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();

	//Move to center of the screen
	glTranslatef( SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f, 0.f );
	
	switch(vmode) {
		case VIEWPORT_MODE_FULL:
			glViewport( 0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT );
			glBegin(GL_QUADS);
				glColor3f( 1.f, 0.f, 0.f );
				glVertex2f( -SCREEN_WIDTH / 2.f, -SCREEN_HEIGHT / 2.f );
						glVertex2f(  SCREEN_WIDTH / 2.f, -SCREEN_HEIGHT / 2.f );
 				glVertex2f(  SCREEN_WIDTH / 2.f,  SCREEN_HEIGHT / 2.f );
						glVertex2f( -SCREEN_WIDTH / 2.f,  SCREEN_HEIGHT / 2.f );
			glEnd();
		break;
		case VIEWPORT_MODE_HALF_CENTER:
			glViewport( SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 4.f, SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f );
			glBegin(GL_QUADS);
				glColor3f( 0.f, 1.f, 0.f );
   				glVertex2f( -SCREEN_WIDTH / 2.f, -SCREEN_HEIGHT / 2.f );
				glVertex2f(  SCREEN_WIDTH / 2.f, -SCREEN_HEIGHT / 2.f );
   				glVertex2f(  SCREEN_WIDTH / 2.f,  SCREEN_HEIGHT / 2.f );
   				glVertex2f( -SCREEN_WIDTH / 2.f,  SCREEN_HEIGHT / 2.f );
			glEnd();
		break;
		case VIEWPORT_MODE_HALF_TOP:
			glViewport( SCREEN_WIDTH / 4.f, SCREEN_HEIGHT / 2.f, SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f );
			glBegin( GL_QUADS );
				glColor3f( 0.f, 0.f, 1.f );
 				glVertex2f( -SCREEN_WIDTH / 2.f, -SCREEN_HEIGHT / 2.f );
				glVertex2f(  SCREEN_WIDTH / 2.f, -SCREEN_HEIGHT / 2.f );
				glVertex2f(  SCREEN_WIDTH / 2.f,  SCREEN_HEIGHT / 2.f );
				glVertex2f( -SCREEN_WIDTH / 2.f,  SCREEN_HEIGHT / 2.f );
			glEnd();
		break;
		case VIEWPORT_MODE_QUAD:
			glViewport( 0.f, 0.f, SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f );
				glBegin( GL_QUADS );
				glColor3f( 1.f, 0.f, 0.f );
				glVertex2f( -SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
				glVertex2f(  SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
				glVertex2f(  SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
				glVertex2f( -SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
			glEnd();

			glViewport( SCREEN_WIDTH / 2.f, 0.f, SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f );
			glBegin( GL_QUADS );
				glColor3f( 0.f, 1.f, 0.f );
				glVertex2f( -SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
				glVertex2f(  SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
				glVertex2f(  SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
				glVertex2f( -SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
			glEnd();

			glViewport( 0.f, SCREEN_HEIGHT / 2.f, SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f );
			glBegin( GL_QUADS );
				glColor3f( 0.f, 0.f, 1.f );
				glVertex2f( -SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
				glVertex2f(  SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
				glVertex2f(  SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
				glVertex2f( -SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
			glEnd();

			glViewport( SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f, SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f );
			glBegin( GL_QUADS );
				glColor3f( 1.f, 1.f, 0.f );
					glVertex2f( -SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
					glVertex2f(  SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
					glVertex2f(  SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
					glVertex2f( -SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
				glEnd();
		break;
		case VIEWPORT_MODE_RADAR:
			glViewport( 0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT );
			glBegin( GL_QUADS );
				glColor3f( 1.f, 1.f, 1.f );
				glVertex2f( -SCREEN_WIDTH / 8.f, -SCREEN_HEIGHT / 8.f );
				glVertex2f(  SCREEN_WIDTH / 8.f, -SCREEN_HEIGHT / 8.f );
				glVertex2f(  SCREEN_WIDTH / 8.f,  SCREEN_HEIGHT / 8.f );
				glVertex2f( -SCREEN_WIDTH / 8.f,  SCREEN_HEIGHT / 8.f );
 
				glColor3f( 0.f, 0.f, 0.f );
				glVertex2f( -SCREEN_WIDTH / 16.f, -SCREEN_HEIGHT / 16.f );
				glVertex2f(  SCREEN_WIDTH / 16.f, -SCREEN_HEIGHT / 16.f );
				glVertex2f(  SCREEN_WIDTH / 16.f,  SCREEN_HEIGHT / 16.f );
				glVertex2f( -SCREEN_WIDTH / 16.f,  SCREEN_HEIGHT / 16.f );
			glEnd();

			glViewport( SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f, SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f );
			glBegin( GL_QUADS );
				glColor3f( 1.f, 1.f, 1.f );
				glVertex2f( -SCREEN_WIDTH / 8.f, -SCREEN_HEIGHT / 8.f );
				glVertex2f(  SCREEN_WIDTH / 8.f, -SCREEN_HEIGHT / 8.f );
				glVertex2f(  SCREEN_WIDTH / 8.f,  SCREEN_HEIGHT / 8.f );
				glVertex2f( -SCREEN_WIDTH / 8.f,  SCREEN_HEIGHT / 8.f );
				glColor3f( 0.f, 0.f, 0.f );
				glVertex2f( -SCREEN_WIDTH / 16.f, -SCREEN_HEIGHT / 16.f );
				glVertex2f(  SCREEN_WIDTH / 16.f, -SCREEN_HEIGHT / 16.f );
				glVertex2f(  SCREEN_WIDTH / 16.f,  SCREEN_HEIGHT / 16.f );
				glVertex2f( -SCREEN_WIDTH / 16.f,  SCREEN_HEIGHT / 16.f );
			glEnd();
		break;
	}
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

	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "The Viewport", NULL, NULL);
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
