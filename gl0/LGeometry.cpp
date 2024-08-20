#include"LGeometry.hpp"
namespace LG
{
    LPoint::LPoint(vec2<float> position_, vec4<float> color_,float size_)
    {
        glGenVertexArrays(Vaos,Vao);
        glGenBuffers(Vbos,Vbo);
        glUseProgram(Program[0]);
        glBindVertexArray(Vao[0]);
        glBindBuffer(GL_ARRAY_BUFFER,Vbo[0]);
        vec4<float> position(position_,0.0f,0.0f);
        glBufferData(GL_ARRAY_BUFFER,sizeof(position),&position.x,GL_STATIC_DRAW);
        glBindBuffer(GL_ARRAY_BUFFER,Vbo[1]);
        glBufferData(GL_ARRAY_BUFFER,sizeof(color_),&color_.x,GL_STATIC_DRAW);
        size=size_;
    }
    void LPoint::draw()
    {

    }
}