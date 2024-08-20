#ifndef LButton_h_
#define LButton_h_
#include<GL/glew.h>
#include<GLFW/glfw3.h>
#include"LDefine.hpp"
namespace LG
{
    class LButton
    {
    private:
        float left;
        float top;
        float right;
        float buttom;
    public:
        LButton(float left_,float top_,float right_,float buttom_);
        LButton(){}
        void dispose(void (*pf)(void));
    };
}
#endif