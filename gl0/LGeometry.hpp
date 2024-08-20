#ifndef LGeometry_hpp_
#define LGeometry_hpp_
#include"LDefine.hpp"
#include"LShaderLoader.hpp"
#include<GL/glew.h>
namespace LG
{
    extern GLuint Program[];
    class LPoint
    {
    private:
        enum{Vaos=1,Vbos=2};
        GLuint Vao[1];
        GLuint Vbo[1];
        float size;
    public:
        LPoint(vec2<float> position_,vec4<float> color_,float size_=5.f);
        void draw();
    };
}
#endif