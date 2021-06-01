﻿
#include <iostream>

//----1-----<<
short s_i = INT16_MAX;
unsigned short us_i = UINT16_MAX;
int i = INT32_MAX;
unsigned int ui = UINT32_MAX;
long long ll_i = INT64_MAX;
unsigned long long ull_i = UINT64_MAX;
char c = CHAR_MAX;
unsigned char uc = UCHAR_MAX;
bool b = true;
float f = FLT_MAX;
double d = DBL_MAX;
//----1----->>

//----2-----<<
enum cellValue
{
    empty
    ,nought
    ,cross
};
//----2----->>

//----3-----<<
cellValue gameCells[3][3] = 
    {
        {empty,empty,empty}
        ,{empty,empty,empty}
        ,{empty,empty,empty}
    };
//----3----->>

//----4-----<<
typedef struct playingField
{
    enum index
    {
        first
        , second
    };
    typedef struct player
    {
        char name[100];
        short score;
        cellValue marker;
        //index index;
    } Player;
    Player Players[2];
    short move;
    index nextMove;
    cellValue cells[3][3];
} PlayingField;
//----4----->>

//----5-----<<
typedef struct variant
{
    union variable {
        int i;
        float f;
        char c;
    } value;
    unsigned short isInt : 1;
    unsigned short isFlt : 1;
    unsigned short isChr : 1;
    Variant operator=(int val) {
        i = val;
        isInt = true;
        isFlt = isChr = !isInt;
    }
    Variant operator=(float val) {
        f = val;
        isFlt = true;
        isInt = isChr = !isFlt;
    }
    Variant operator=(char val) {
        c = val;
        isChr = true;
        isInt = isFlt = !isChr;
    }
} Variant;
//----5----->>

int main()
{
    //Variant myVariant = 'A';
    /*myVariant.value.c = 'A';
    myVariant.isChr = true;*/
}
