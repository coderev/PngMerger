/*=============================================================================
#     FileName: PngUtils.h
#         Desc: single png file handler
#       Author: bugcode
#        Email: bugcoding@gmail.com
#     HomePage: http://bugcode.com.cn
#      Version: 0.0.1
#   LastChange: 2014-11-27 22:52:45
=============================================================================*/

#ifndef _PNG_UTILS_H_

#define _PNG_UTILS_H_


#include <cstdio>
#include <cassert>
#include <iostream>
#include <vector>
#include <string>

#include "FreeImage.h"


//debug infomation output macro control
#define DEBUG_MODE      1

//costomize debug ouput macro
#define _debug_print(format, ...)    \
        printf("[Debug Info]: " format " >> func[%s] >> line[%d]\n"\
                                ,##__VA_ARGS__, __func__, __LINE__)

//costomize unsigned int type to uint
typedef unsigned int    uint;

/*
 * base struct of png property
 * width, height, bitdepth
 *
 */

typedef struct _basePngInfo
{
    //png file name
    std::string pngfileName;
    //FIBITMAP pointer
    FIBITMAP *bitmapHandler;
    //png width and height
    uint wid, hgt;
    //png bitmap depth
    uint bpp;
    //color type with inner FreeImage enum
    FREE_IMAGE_COLOR_TYPE clrType;

}BasePngPropt;


/* 
 * PngUtils Class
 *
 * use FreeImage API operate single png file
 * read, write, get some png file property etc..
 *
 */

class PngUtils
{
public:
    //default ctor
    PngUtils();
    /*
     * ctor with file name
     * @param : will handling png file's name 
     */
     PngUtils(std::string pngfileName);
    //dtor
    ~PngUtils();

    //get file name from Pngutils instance pointer
    std::string getPngfileName();

    /*
     * read png file special with m_pngfileName
     * and the FIBITMAP pointer with png info returned
     */
    BasePngPropt *getPnginfo();


//private member function
private:
    //error handle function while load image
    static void FreeImageErrorHandler(FREE_IMAGE_FORMAT fif, const char *msg);

private:
    //png file's name
    std::string m_pngfileName;
};



#endif