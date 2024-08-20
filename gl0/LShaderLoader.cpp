#include"LShaderLoader.hpp"
#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<cassert>
namespace LG
{
    namespace LShaderLoader
    {
        Shader::Shader(GLenum mode, const char* path)
        {
            std::string shadersource;
            std::ifstream fin;
            fin.exceptions(std::ifstream::failbit | std::ifstream::badbit);
            try
            {
                fin.open(path);
                if (!fin.is_open())
                    std::cout << "ERROR : OPENING " << path << " FAILURE E0004" << std::endl;
                std::stringstream instream;
                instream << fin.rdbuf();
                fin.close();
                shadersource = instream.str();
            }
            catch (std::ifstream::failure e)
            {
                std::cout << "ERROR : READING GLSL SOURCE FILE FAILURE E0005" << std::endl;
            }
            const char* shadercode = shadersource.c_str();
            ID = glCreateShader(mode);
            glShaderSource(ID, 1, &shadercode, nullptr);
            glCompileShader(ID);
            checkOpenGLError();
            GLint shader;
            glGetShaderiv(ID, GL_COMPILE_STATUS, &shader);
            if (shader != 1)
                printShaderLog(ID);
        }

        Shader::~Shader()
        {
            glDeleteShader(ID);
        }

        GLuint create_shader_program(const char* vertex_shader_path, const char* fragment_shader_path)
        {
            GLuint ID;
            Shader vertex_shader(GL_VERTEX_SHADER, vertex_shader_path);
            Shader fragment_shader(GL_FRAGMENT_SHADER, fragment_shader_path);
            ID = glCreateProgram();
            glAttachShader(ID, vertex_shader.id());
            glAttachShader(ID, fragment_shader.id());
            glLinkProgram(ID);
            checkOpenGLError();
            GLint program;
            glGetProgramiv(ID, GL_LINK_STATUS, &program);
            if (program != 1)
                printProgramLog(ID);
            return ID;
        }

        void printShaderLog(GLuint shader)
        {
            int len = 0;
            int chWrittn = 0;
            char* log;
            glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &len);
            if (len > 0)
            {
                log = new char[len];
                glGetShaderInfoLog(shader, len, &chWrittn, log);
                std::cout << "ERROR E0003 : shader error :\n" << log << std::endl;
                delete[]log;
            }
        }

        void printProgramLog(int program)
        {
            int len = 0;
            int chWrittn = 0;
            char* log;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &len);
            if (len > 0)
            {
                log = new char[len];
                glGetProgramInfoLog(program, len, &chWrittn, log);
                std::cout << "ERROR E0002 : program error :\n" << log << std::endl;
                delete[]log;
            }
        }

        bool checkOpenGLError()
        {
            bool foundError = false;
            int glErr = glGetError();
            while (glErr != GL_NO_ERROR)
            {
                std::cout << "glError: " << glErr << std::endl;
                foundError = true;
                glErr = glGetError();
            }
            return foundError;
        }
    }
}