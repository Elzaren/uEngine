#include "Window.h"
#include <GLFW/glfw3.h>

int main() {

    /* Initialize the library */
    if (!glfwInit()){
        throw std::runtime_error("Failed to initialize GLFW");
    }

    WindowManagerSystem windowManagerSystem;

    int state=0;
    while (!glfwWindowShouldClose(windowManagerSystem.getMain())) {
        windowManagerSystem.updateWindows();
        state = glfwGetKey(windowManagerSystem.getMain(), GLFW_KEY_E);
        if (state == GLFW_PRESS)
        {
            windowManagerSystem.createWindow(assets);
        }
    }

    /* Cleanup */
    glfwTerminate();

    return 0;
}