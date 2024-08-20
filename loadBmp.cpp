#include"loadBmp.h"
#include<fstream>
#include<iostream>
#include<new>

#define NODEBUG

#ifdef DEBUG
int main()
{
    std::ifstream fin("../1.bmp");
    BMP clr(fin);
    unsigned char* temp=(unsigned char*)clr.color;
    std::cout<<clr.width<<" "<<clr.height<<std::endl;
    //for(int i=0;i<clr.sizeImage/1.5;i+=3)
    //{
        //temp[i]=200;
        //temp[i+1]=255;
        //temp[i+2]=255;/
    //
    fin.close();
    //std::fstream finout("1.bmp",std::ios_base::in|std::ios_base::out);
    //finout.seekp(clr.bfh.bfOffbits);
    //finout.write((char*)temp,clr.sizeImage);
    //finout.close();
}
#endif

BMPFileHeader::BMPFileHeader(std::ifstream &fin)
{
    fin.seekg(0,std::ios_base::beg);
    fin.read((char*)(&bfType),sizeof(bfType));
    fin.read((char*)(&bfSize),sizeof(bfSize));
    fin.read((char*)(&bfReserved),sizeof(bfReserved));
    fin.read((char*)(&bfOffbits),sizeof(bfOffbits));
}

BMPInfoHeader::BMPInfoHeader(std::ifstream &fin)
{
    fin.seekg(14,std::ios_base::beg);
    fin.read((char*)(&biSize),sizeof(biSize));
    fin.read((char*)(&biWidth),sizeof(biWidth));
    fin.read((char*)(&biHeight),sizeof(biHeight));
    fin.read((char*)(&biPlanes),sizeof(biPlanes));
    fin.read((char*)(&biBitCount),sizeof(biBitCount));
    fin.read((char*)(&biCompression),sizeof(biCompression));
    fin.read((char*)(&biSizeImage),sizeof(biSizeImage));
    fin.read((char*)(&biXPelsPerMeter),sizeof(biXPelsPerMeter));
    fin.read((char*)(&biYPelsPerMeter),sizeof(biYPelsPerMeter));
    fin.read((char*)(&biClrUsed),sizeof(biClrUsed));
    fin.read((char*)(&biClrImportant),sizeof(biClrImportant));
}

void BMP::disposeColorInfo(std::ifstream & fin)
{
    color=new uint8_t[(uint32_t)bih.biSizeImage];
    fin.seekg((uint32_t)bfh.bfOffbits);
    fin.read((char*)color,bih.biSizeImage);
}

BMP::BMP(std::ifstream &fin)
{
    if(!fin.is_open()||bih.biBitCount==1||bih.biBitCount==4||bih.biBitCount==8||bih.biCompression==1||bih.biCompression==2)
        std::cout<<"Failed to load the image file"<<std::endl;
    bfh=BMPFileHeader(fin);
    bih=BMPInfoHeader(fin);
    disposeColorInfo(fin);
    width=bih.biWidth;
    height=bih.biHeight;
}

BMP::~BMP()
{
    delete[]color;
}