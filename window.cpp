#include "Window.h"

namespace Window {
    GLFWwindow *create(int width, int height, const char *title, int swapInterval) {

        /* Create a windowed mode window and its OpenGL context */
        GLFWwindow *window = glfwCreateWindow(width, height, title, NULL, NULL);
        if (!window) {
            glfwTerminate();
            throw std::runtime_error("Failed to create GLFW window");
        }

        /* Make the window's context current */
        glfwMakeContextCurrent(window);

        /* Enable or disable v-sync */
        glfwSwapInterval(swapInterval);

        return window;
    }

    void update(GLFWwindow *window) {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    void destroy(GLFWwindow *window) {
        glfwDestroyWindow(window);
    }
}


//-------------------------- WINDOWMANAGERSYSTEM--------------------- Delete?

GLFWwindow* WindowManagerSystem::createWindow(WindowType type){
    //----------------------DEFINE HOW THE WINDOW TYPE IS
    switch (type) {
        case mainW:
            return Window::create(640,640,"main");
        case assets:
            pm_windowData[m_windowDataSize].windowType = assets;
            pm_windowData[m_windowDataSize++].window =  Window::create(640,640,"assets");
            break;
    }
    return nullptr;
};

WindowManagerSystem::WindowManagerSystem() {
        pm_windowData = new windowData[m_windowTypes];
        pm_main = createWindow(mainW);
};
    WindowManagerSystem::~WindowManagerSystem(){
        for(int c = 0; c <m_windowTypes; c++){
            pm_windowData[c].window = nullptr;
        }
    };

    void WindowManagerSystem::updateWindows() {
        Window::update(pm_main);
        for(int c = 0; c<m_windowTypes;c++){
            if(pm_windowData[c].window!= nullptr){
                Window::update(pm_windowData[c].window);
                if(glfwWindowShouldClose(pm_windowData[c].window)){
                    destroyWindow(pm_windowData[c].window);
                }
            }
        }
    };
    void WindowManagerSystem::destroyWindow(GLFWwindow* window){
        for(int c = 0; c<m_windowTypes;c++){
            if(pm_windowData[c].window==window){
                Window::destroy(pm_windowData[c].window);
                pm_windowData[c].window = nullptr;
            }
        }
    };

    GLFWwindow* WindowManagerSystem::getMain() {
        return pm_main;
    }