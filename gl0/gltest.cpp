#include"LWindow.h"
#include"../loadBmp.h"
#include"LShaderLoader.hpp"
#include<cassert>
#include<iostream>

#define Vaos 1
#define Vbos 3
using namespace std;

GLuint Vao[Vaos],Vbo[Vbos],Texture,Program;

void display();

int main()
{
    LWindow window(1920,1080,"second",vec4<float>(0.5f,0.7f,0.5f,1.0f));
    float v[]=
    {
        1.0f,1.0f,0.0f,//右上角
        -1.0f,1.0f,0.0f,//左上角
        -1.0f,-1.0f,0.0f,//左下角
        1.0f,-1.0f,0.0f,//右下角
    };
    float t[]=
    {
        1.0f,1.0f,
        0.0f,1.0f,
        0.0f,0.0f,
        1.0f,0.0f,
    };
    uint32_t i[]=
    {
        0,1,2,
        2,3,0,
    };
    
    glGenVertexArrays(Vaos,Vao);
    glGenBuffers(Vbos,Vbo);
    glBindVertexArray(Vao[0]);
    glBindBuffer(GL_ARRAY_BUFFER,Vbo[0]);
    glBufferData(GL_ARRAY_BUFFER,sizeof(v),v,GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER,Vbo[1]);
    glBufferData(GL_ARRAY_BUFFER,sizeof(t),t,GL_STATIC_DRAW);
    assert(!LShaderLoader::checkOpenGLError());
    glGenTextures(1,&Texture);
    glBindTexture(GL_TEXTURE_2D,Texture);
    assert(!LShaderLoader::checkOpenGLError());
    std::ifstream fin("../../output.bmp",ios_base::in|ios_base::binary);
    BMP bmp(fin);
    glUseProgram(Program);
    std::cout<<bmp.width<<" "<<bmp.height<<std::endl;
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB8,bmp.width,bmp.height,0,GL_BGR,GL_UNSIGNED_BYTE,bmp.color);
    glGenerateMipmap(GL_TEXTURE_2D);
    assert(!LShaderLoader::checkOpenGLError());
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,Vbo[2]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER,sizeof(i),i,GL_STATIC_DRAW);
    Program=LShaderLoader::create_shader_program("vs.glsl","fs.glsl");
    window.draw(display);
}

void display()
{
    glUseProgram(Program);
    glBindVertexArray(Vao[0]);
    glBindBuffer(GL_ARRAY_BUFFER,Vbo[0]);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER,Vbo[1]);
    glVertexAttribPointer(1,2,GL_FLOAT,GL_FALSE,0,0);
    glEnableVertexAttribArray(1);
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D,Texture);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,Vbo[2]);
    glDrawElements(GL_TRIANGLES,6,GL_UNSIGNED_INT,0);
}