#ifndef loadBmp_h_
#define loadBmp_h_
#include<stdint.h>
#include<fstream>
#include<vector>

using Byte=uint8_t;
using Word=uint16_t;
using Dword=uint32_t;

//位图文件头
class BMPFileHeader
{
//BMP文件为小端字节序
public:
    Word bfType;        //bitmap文件类型，必须为BM（0x424D）--0x0
    Dword bfSize;       //bitmap文件大小，单位：byte--0x2
    Dword bfReserved;   //保留字，必须为0--0x6
    Dword bfOffbits;    //bitmap数据的起始位置--0xA
public:
    BMPFileHeader(std::ifstream& fin);
    BMPFileHeader(){};
};

//位图信息头
class BMPInfoHeader
{
public:
    Dword biSize;           //占用字节数--0xE
    Dword biWidth;          //图像宽度（px）--0x12
    Dword biHeight;         //图像高度（px）--0x16
    Word biPlanes;          //目标设备级别，必须为1--0x1A
    Word biBitCount;        //每像素位数，1（双色）或4（16色）或8（256色）或24（16777216色）或32（4294967296色）--0x1C
    Dword biCompression;    //位图压缩类型，0（不压缩），1（BL_RLE8压缩类型），2（BL_RLE4压缩类型）--0x1E
    Dword biSizeImage;      //位图大小（byte）--0x22
    Dword biXPelsPerMeter;  //位图水平分辨率（px/meter）--0x26
    Dword biYPelsPerMeter;  //位图垂直分辨率（px/meter）--0x2A
    Dword biClrUsed;        //位图实际使用的颜色表中的颜色数--0x2E
    Dword biClrImportant;   //位图显示过程中重要的颜色数--0x32
public:
    BMPInfoHeader(std::ifstream& fin);
    BMPInfoHeader(){}
};

class BMP//只支持24位真彩色,不压缩
{
private:
    void disposeColorInfo(std::ifstream & fin);
public:
    BMPFileHeader bfh;
    BMPInfoHeader bih;
public:
    uint8_t* color;//数据
    uint32_t width;//==bih.biWidth
    uint32_t height;//==bih.biHeight
public:
    BMP(std::ifstream & fin);
    BMP(){}
    BMP(const BMP&);
    BMP& operator=(const BMP&);
    ~BMP();
};

#endif