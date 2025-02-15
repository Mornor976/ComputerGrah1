//¬¿–»¿Õ“ 22
//ÿ≈—“»”√ŒÀ‹Õ» 
//÷¬≈“ ‘»√”–€: (0.4, 1.0, 0.4)
//÷¬≈“ ‘ŒÕ¿: (1.0, 0.2, 0.3)

#define GLEW_DLL
#define GLFW_DLL
#include <glew.h>
#include <glfw3.h>
#include <iostream>

int main() {
    if (!glfwInit()) {
        fprintf(stderr, "ERROR: could not start GLFW3.\n");
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

    GLFWwindow* window = glfwCreateWindow(512, 512, "Mainwindow", NULL, NULL);

    if (!window) {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    glewExperimental = GL_TRUE;

    GLenum ret = glewInit();
    if (ret != GLEW_OK) {
        fprintf(stderr, "Error initializing GLEW: %s\n", glewGetErrorString(ret));
        return -1;
    }

    glClearColor(1.0f, 0.2f, 0.3f, 0.0f);

    while (!glfwWindowShouldClose(window)) {

        glClear(GL_COLOR_BUFFER_BIT);
        glBegin(GL_TRIANGLE_FAN);

        //ËÒÛÂÏ ¯ÂÒÚËÛ„ÓÎ¸ÌËÍ
        glColor3f(0.4f, 1.0f, 0.4f); 
        glVertex2f(-0.5f, 0.8f);     
        glVertex2f(0.5f, 0.8f);      
        glVertex2f(1.0f, 0.0f);      
        glVertex2f(0.5f, -0.8f);     
        glVertex2f(-0.5f, -0.8f);    
        glVertex2f(-1.0f, 0.0f);     

        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    const GLubyte* version_str = glGetString(GL_VERSION);
    const GLubyte* device_str = glGetString(GL_RENDERER);

    fprintf(stdout, "Status: Using GLEW %s\n", glewGetString(GLEW_VERSION));
    printf("This version OpenGL running is %s\n", version_str);
    printf("This device OpenGL running is %s\n", device_str);

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}
