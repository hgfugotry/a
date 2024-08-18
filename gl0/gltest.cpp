#include"LWindow.h"
#include"../loadBmp.h"

#define Vaos 1
#define Vbos 2
using namespace std;

void display();

int main()
{
    float v[]=
    {
        1.0f,1.0f,0.0f,0.0f,//右上角
        -1.0f,1.0f,0.0f,0.0f//左上角
        -1.0f,-1.0f,0.0f,0.0f,//左下角
        1.0f,-1.0f,0.0f,0.0f,//右下角
    };
    uint32_t i[]=
    {
        0,1,2,
        2,3,0,
    };
    GLuint Vao[Vaos],Vbo[Vbos],Texture;
    glGenVertexArrays(Vaos,Vao);
    glGenBuffers(Vbos,Vbo);
    glBindVertexArray(Vao[0]);
    glBindBuffer(GL_ARRAY_BUFFER,Vbo[0]);
    glBufferData(GL_ARRAY_BUFFER,sizeof(v),v,GL_STATIC_DRAW);
    glBindTexture(GL_TEXTURE_2D,Texture);
    std::ifstream fin("1.bmp");
    BMP bmp(fin);
    glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,bmp.width,bmp.height,0,GL_RGB,GL_UNSIGNED_BYTE,bmp.color);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,Vbo[1]);
    LWindow window(600,600,"second",vec4<float>(0.5f,0.7f,0.5f,1.0f));
    window.draw(display);
}

void display()
{
    
}