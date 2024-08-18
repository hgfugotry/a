#ifndef LWindow_h_
#define LWindow_h_
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include"LDefine.h"
class LWindow
{
private:
    GLFWwindow* window_;
    bool shouldOpen=true;
    vec4<float> backgroundColor;
public:
    explicit LWindow(const int& width,const int& height,const char* title,const vec4<float>& background_color);
    operator GLFWwindow*()const;
    GLFWwindow* window()const;
    void draw(void (*display)(void))const;
    void close();
};
#endif