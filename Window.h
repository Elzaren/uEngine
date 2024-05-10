#ifndef UENGINE_WINDOW_H
#define UENGINE_WINDOW_H

#include <GLFW/glfw3.h>
#include <stdexcept>

namespace Window {
    GLFWwindow *create(int width, int height, const char *title, int swapInterval = 1);

    void update(GLFWwindow *);

    void destroy(GLFWwindow *);
};

//-------------------------- WINDOWMANAGERSYSTEM--------------------- Delete?
enum WindowType {
    mainW, assets
};//----------------ADD TYPES WHEN NEEDED, remember to change num of types and creation


struct windowData {
    GLFWwindow *window = nullptr;
    WindowType windowType = mainW;
};

class WindowManagerSystem {
private:
    GLFWwindow *pm_main = nullptr;
    windowData *pm_windowData = nullptr;
    int m_currentWindows = 0;
    const int m_maxWindows = 5;//------------------------MAX WINDOWS

public:
    WindowManagerSystem();

    ~WindowManagerSystem();

    GLFWwindow *getMain();

    void createWindow(WindowType);

    void updateWindows();

    void destroyWindow(GLFWwindow *);
};


#endif //UENGINE_WINDOW_H
