#include <iostream>
#include <cmath>

#include <GL/glew.h>
#ifdef __APPLE__
#define GLFW_INCLUDE_GLCOREARB
#endif

#include <GLFW/glfw3.h>
extern "C"
{
#include <nanovg.h>
#define NANOVG_GL3_IMPLEMENTATION
#include <nanovg_gl.h>
}
using namespace std;

int main()
{
	std::cout << "Hello World!\n";
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;
    #ifndef _WIN32 // don't require this on win32, and works with more cards
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    #endif
    glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, 1);

	window = glfwCreateWindow(1000, 600, "NanoVG", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;
	if(glewInit() != GLEW_OK) {
		printf("Could not init glew.\n");
		return -1;
	}
	// GLEW generates GL error because it calls glGetString(GL_EXTENSIONS), we'll consume it here.
	glGetError();

    NVGcontext* vg = nvgCreateGL3(NVG_ANTIALIAS | NVG_STENCIL_STROKES | NVG_DEBUG);
    size_t t = 0;
    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        t++;
        // Update and render
		glViewport(0, 0, 1000, 600);
        glClearColor(0,0,0,0);
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT|GL_STENCIL_BUFFER_BIT);

		nvgBeginFrame(vg, 1000, 600, 1);
        /* Render here */
        nvgBeginPath(vg);
        nvgRect(vg, 100,100, 120,30*sin(float(t)/10));
        nvgFillColor(vg, nvgRGBA(255,192,0,255));
        nvgFill(vg);
        nvgEndFrame(vg);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
