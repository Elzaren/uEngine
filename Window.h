#ifndef UENGINE_WINDOW_H
#define UENGINE_WINDOW_H

#include <GLFW/glfw3.h>
#include <stdexcept>
#include "string"

namespace Window {
    GLFWwindow* create(int width, int height, const char* title, int swapInterval = 1);
    void update(GLFWwindow*);
    void destroy(GLFWwindow*);
};

//-------------------------- WINDOWMANAGERSYSTEM--------------------- Delete?
enum WindowType{mainW, assets};//----------------ADD TYPES WHEN NEEDED, remember to change num of types and creation

struct windowData{
    GLFWwindow* window = nullptr;
    WindowType windowType= mainW;
};

class WindowManagerSystem {
private:
    GLFWwindow *pm_main = nullptr;
    windowData *pm_windowData = nullptr;
    int m_windowDataSize = 0;
    int m_windowTypes = 1;//------------------------CHANGE WHEN MORE TYPES ARE ADDED
public:
    WindowManagerSystem();
    ~WindowManagerSystem();
    GLFWwindow* getMain();
    GLFWwindow* createWindow(WindowType);
    void updateWindows();
    void destroyWindow(GLFWwindow*);
};

#endif //UENGINE_WINDOW_H
