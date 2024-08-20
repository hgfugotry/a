#ifndef LShaderLoader_hpp_
#define LShaderLoader_hpp_
#include<GL/glew.h>
#include<GLFW/glfw3.h>
namespace LG
{
    namespace LShaderLoader
    {
        class Shader
        {
        private:
            GLuint ID;
        public:
            Shader(GLenum mode, const char* path);
            ~Shader();
            GLuint id() { return ID; }
        };

        GLuint create_shader_program(const char* vertex_shader_path, const char* fragment_shader_path);

        void printShaderLog(GLuint shader);
        void printProgramLog(int program);
        bool checkOpenGLError();
    }
}
#endif