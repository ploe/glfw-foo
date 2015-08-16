#include <GLFW/glfw3.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480


typedef struct {
	GLfloat x, y;
} Camera;

Camera camera = {0.f, 0.f};

void KEYBOARD(GLFWwindow *window, int key, int scancode, int action, int mods) {
	if (action != GLFW_PRESS) return;
	switch(key) {
		case GLFW_KEY_W: camera.y -= 16.f; break;
		case GLFW_KEY_S: camera.y += 16.f; break;
		case GLFW_KEY_A: camera.x -= 16.f; break;
		case GLFW_KEY_D: camera.x += 16.f; break;
	}

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();
	glLoadIdentity();

	glTranslatef(-camera.x, -camera.y, 0.f);

	glPushMatrix();
}

void render() {
	glClearColor(0.f, 0.f, 0.f, 1.f);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glPushMatrix();

	glTranslatef(SCREEN_WIDTH / 2.f, SCREEN_HEIGHT / 2.f, 0.f );

	glBegin( GL_QUADS );
	glColor3f( 1.f, 0.f, 0.f );
		glVertex2f( -SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
		glVertex2f(  SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
		glVertex2f(  SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
		glVertex2f( -SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
	glEnd();

	glTranslatef( SCREEN_WIDTH, 0.f, 0.f );
	glBegin( GL_QUADS );
		glColor3f( 0.f, 1.f, 0.f );
		glVertex2f( -SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
		glVertex2f(  SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
		glVertex2f(  SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
		glVertex2f( -SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
	glEnd();

	glTranslatef( 0.f, SCREEN_HEIGHT, 0.f );
	glBegin( GL_QUADS );
		glColor3f( 0.f, 0.f, 1.f );
		glVertex2f( -SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
		glVertex2f(  SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
		glVertex2f(  SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
		glVertex2f( -SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
	glEnd();

	glTranslatef( -SCREEN_WIDTH, 0.f, 0.f );

	glBegin( GL_QUADS );
		glColor3f( 1.f, 1.f, 0.f );
		glVertex2f( -SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
		glVertex2f(  SCREEN_WIDTH / 4.f, -SCREEN_HEIGHT / 4.f );
		glVertex2f(  SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
		glVertex2f( -SCREEN_WIDTH / 4.f,  SCREEN_HEIGHT / 4.f );
	glEnd();
}

void init() {
	glViewport(0.f, 0.f, SCREEN_WIDTH, SCREEN_HEIGHT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho( 0.0, SCREEN_WIDTH, SCREEN_HEIGHT, 0.0, 1.0, -1.0 );


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();

	GLenum error = glGetError();
	if (error != GL_NO_ERROR) {
//		printf("Error initialising OpenGL: %s\n", gluErrorString(error));
	//	return -1;
	}
}

int main() {

	GLFWwindow *window;
	if (!glfwInit()) return -1;

	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Scrolling and the Matrix Stack", NULL, NULL);
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
