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

void WindowManagerSystem::createWindow(WindowType type) {

    //----------------------DEFINE HOW THE WINDOW TYPE IS
    if (type == mainW) {
        pm_main = glfwCreateWindow(640, 640, "main", NULL, NULL);
        return;
    } else if (m_currentWindows != m_maxWindows) {

        m_currentWindows++;
        for (int c = 0; c < m_maxWindows; c++) {
            if (pm_windowData[c].window == nullptr) {

                switch (type) {
                    case mainW:
                        throw std::runtime_error("This shouldnt have happened");
                    case assets:
                        pm_windowData[c].windowType = assets;
                        pm_windowData[c].window = glfwCreateWindow(640, 640, "assets", NULL, NULL);
                        return;

                }

            }
        }
        throw std::runtime_error("Failed to create the window");

    }
    throw std::runtime_error("Failed to create the window, Max number of windows reached");
};

WindowManagerSystem::WindowManagerSystem() {
    pm_windowData = new windowData[m_maxWindows];
    createWindow(mainW);
};

WindowManagerSystem::~WindowManagerSystem() {
    for (int c = 0; c < m_maxWindows; c++) {
        pm_windowData[c].window = nullptr;
    }
};

void WindowManagerSystem::updateWindows() {

    Window::update(pm_main);

    for (int c = 0; c < m_maxWindows; c++) {

        if (pm_windowData[c].window != nullptr) {
            Window::update(pm_windowData[c].window);

            if (glfwWindowShouldClose(pm_windowData[c].window)) {
                destroyWindow(pm_windowData[c].window);
            }

        }
    }
};

void WindowManagerSystem::destroyWindow(GLFWwindow *window) {
    for (int c = 0; c < m_maxWindows; c++) {

        if (pm_windowData[c].window == window) {
            glfwDestroyWindow(pm_windowData[c].window);
            pm_windowData[c].window = nullptr;
            m_currentWindows--;
        }

    }
};

GLFWwindow *WindowManagerSystem::getMain() {
    return pm_main;
}
