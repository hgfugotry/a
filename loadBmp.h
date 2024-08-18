#ifndef loadBmp_h_
#define loadBmp_h_
#include<stdint.h>
#include<fstream>
#include<vector>
#include"gl0/LDefine.h"

using Byte=uint8_t;
class Word
{
public:
    Byte b[2];
public:
    Word(Byte* byte){b[0]=byte[0];b[1]=byte[1];}
    Word(uint16_t u16){b[0]=(uint8_t)u16;b[1]==(uint8_t)(u16>>8);}
    Word(){}
    bool operator==(uint16_t obj){uint16_t i=((uint16_t) b[1]<<8)+b[0];return i==obj;}
    bool operator<=(uint16_t obj){uint16_t i=((uint16_t) b[1]<<8)+b[0];return i<=obj;}
    bool operator>=(uint16_t obj){uint16_t i=((uint16_t) b[1]<<8)+b[0];return i>=obj;}
    bool operator<(uint16_t obj){uint16_t i=((uint16_t) b[1]<<8)+b[0];return i<obj;}
    bool operator>(uint16_t obj){uint16_t i=((uint16_t) b[1]<<8)+b[0];return i>obj;}
    operator uint16_t()const{return ((uint16_t) b[1]<<8)+b[0];}
};
class Dword
{
public:
    Word b[2];
public:
    Dword(Word* word){b[0]=word[0];b[1]=word[1];}
    Dword(uint32_t u32){b[0]=(uint16_t)u32;b[1]=(uint16_t)(u32>>16);}
    Dword(){}
    bool operator==(uint32_t obj){uint32_t i=((uint32_t)((uint16_t)b[1])<<16)+(uint16_t)b[0];return i==obj;}
    bool operator<=(uint32_t obj){uint32_t i=((uint32_t)((uint16_t)b[1])<<16)+(uint16_t)b[0];return i<=obj;}
    bool operator>=(uint32_t obj){uint32_t i=((uint32_t)((uint16_t)b[1])<<16)+(uint16_t)b[0];return i>=obj;}
    bool operator<(uint32_t obj){uint32_t i=((uint32_t)((uint16_t)b[1])<<16)+(uint16_t)b[0];return i<obj;}
    bool operator>(uint32_t obj){uint32_t i=((uint32_t)((uint16_t)b[1])<<16)+(uint16_t)b[0];return i>obj;}
    operator uint32_t()const{return ((uint32_t)((uint16_t)b[1])<<16)+(uint16_t)b[0];}
};

class BMPFileHeader
{
public:
    Word bfType;        //bitmap文件类型，必须为BM（0x424D）
    Dword bfSize;       //bitmap文件大小，单位：byte
    Dword bfReserved;   //保留字，必须为0
    Dword bfOffbits;    //bitmap数据的起始位置
public:
    BMPFileHeader(std::ifstream& fin);
    BMPFileHeader(){};
};

class BMPInfoHeader
{
public:
    Dword biSize;
    Dword biWidth;
    Dword biHeight;
    Word biPlanes;
    Word biBitCount;
    Dword biCompression;
    Dword biSizeImage;
    Dword biXPelsPerMeter;
    Dword biYPelsPerMeter;
    Dword biClrUsed;
    Dword biClrImportant;
public:
    BMPInfoHeader(std::ifstream& fin);
    BMPInfoHeader(){}
};

class BMP
{
public:
    BMPFileHeader bfh;
    BMPInfoHeader bih;
public:
    uint8_t* color;
    uint32_t width;
    uint32_t height;
public:
    BMP(std::ifstream & fin);
    BMP(){}
    BMP(const BMP&);
    BMP& operator=(const BMP&);
    ~BMP();
};

#endif