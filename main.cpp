#include "Window.h"
#include <GLFW/glfw3.h>

int main() {

    /* Initialize the library */
    if (!glfwInit()){
        throw std::runtime_error("Failed to initialize GLFW");
    }

    WindowManagerSystem windowManagerSystem;

    while (!glfwWindowShouldClose(windowManagerSystem.getMain())) {
        windowManagerSystem.updateWindows();
    }

    /* Cleanup */
    glfwTerminate();

    return 0;
}