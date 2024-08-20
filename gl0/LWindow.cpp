#include"LWindow.hpp"
#include"LShaderLoader.hpp"
#include<cstdlib>
namespace LG
{
    const int Programs=1;
    GLuint Program[Programs];
    LWindow::LWindow(const int& width,const int& height,const char* title,const vec4<float>& background_color)
    {
        if(!glfwInit()){exit(EXIT_FAILURE);}
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
        window_=glfwCreateWindow(width,height,title,nullptr,nullptr);
        glfwMakeContextCurrent(window_);
        if(glewInit()!=GLEW_OK){exit(EXIT_FAILURE);}
        glfwSwapInterval(1);
        backgroundColor=background_color;
        Program[0]=LShaderLoader::create_shader_program("vs.glsl","fs.glsl");
    }

    LWindow::operator GLFWwindow *()const
    {
        return window_;
    }

    GLFWwindow *LWindow::window() const
    {
        return window_;
    }

    void LWindow::draw(void (*display)(void))const
    {
        while(shouldOpen&&(!glfwWindowShouldClose(window_)))
        {
            glClearColor(backgroundColor.x,backgroundColor.y,backgroundColor.z,backgroundColor.w);
            glClear(GL_COLOR_BUFFER_BIT);
            display();
            glfwSwapBuffers(window_);
            glfwWaitEvents();
        }
    }

    void LWindow::close()
    {
        shouldOpen=false;
    }
}