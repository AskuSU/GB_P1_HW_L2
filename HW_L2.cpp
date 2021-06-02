
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
private:
    union variable {
        int i;
        float f;
        char c;
    } value;
    unsigned short isInt : 1;
    unsigned short isFlt : 1;
    unsigned short isChr : 1;
public :
    variant& operator = (int val) {
        i = val;
        isInt = true;
        isFlt = isChr = !isInt;
        return *this;
    }
    variant& operator = (float val) {
        f = val;
        isFlt = true;
        isInt = isChr = !isFlt;
        return *this;
    }
    variant& operator = (char val) {
        c = val;
        isChr = true;
        isInt = isFlt = !isChr;
        return *this;
    }
    operator int() {
        if (isInt) return i;
        else return 0;
    }
    operator float() {
        if (isFlt) return f;
        else return 0.f;        
    }
    operator char() {
        if (isChr) return c;
        else return 0;
    }
    void init() {
        i = 0;
        isInt = isFlt = isChr = 0;
    }
    void display() {
        if (isInt || isFlt || isChr) {
            std::cout << "В Variant записан";
            if (isInt)
            {
                std::cout << "о целое число i = ";
                std::cout << i;
            }
            else if (isFlt)
            {
                std::cout << "о дробное число f = ";
                std::cout << f;
            }
            else
            {
                std::cout << " символ c = ";
                std::cout << c;
            }
        }
        else
        {
            std::cout << "Variant пуст!";
        }
        std::cout << std::endl;

    }
} Variant;
//----5----->>

int main()
{
    setlocale(LC_ALL, "RU");
    
    Variant myVariant; 
    myVariant.display();
    myVariant.init();
    myVariant.display();

    myVariant = 'A';
    myVariant.display();

    myVariant = 123;
    myVariant.display();

    myVariant = 15.4f;
    myVariant.display();

    std::cout << std::endl;
    int iii = myVariant;
    float fff = myVariant;
    char ccc = myVariant;
    std::cout << "int iii = " << iii << std::endl;
    std::cout << "float fff = " << fff << std::endl;
    std::cout << "char ccc = '" << ccc << "'" << std::endl;

    myVariant = 123;
    std::cout << std::endl;
    iii = myVariant;
    fff = myVariant;
    ccc = myVariant;
    std::cout << "int iii = " << iii << std::endl;
    std::cout << "float fff = " << fff << std::endl;
    std::cout << "char ccc = '" << ccc << "'" << std::endl;

    myVariant = 'A';
    std::cout << std::endl;
    iii = myVariant;
    fff = myVariant;
    ccc = myVariant;
    std::cout << "int iii = " << iii << std::endl;
    std::cout << "float fff = " << fff << std::endl;
    std::cout << "char ccc = '" << ccc << "'" << std::endl;
}
