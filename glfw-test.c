#include <GLFW/glfw3.h>

void render() {
	glClearColor(0.f, 1.f, 0.f, 0.f);
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(-0.5f, 0.5f);
	glEnd();
}

void init() {
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

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

	window = glfwCreateWindow(640, 480, "hello, world", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}

	init();

	glfwMakeContextCurrent(window);

	while (!glfwWindowShouldClose(window)) {
		render();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
