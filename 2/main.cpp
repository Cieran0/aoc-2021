#include <clibstr.h>
#include <clibio.h>

size_t size;
size_t x1 = 0;
size_t y1 = 0;
size_t x2 = 0;
size_t y2 = 0;
size_t aim = 0;

clib::string mkString(const char* s){ return clib::string((char*)s);}

struct StrArr
{
    clib::string* strings;
    size_t size;

    StrArr(clib::string input, char splitChar) 
    {
        strings = input.split(splitChar,size);
    }

    StrArr(){}

    StrArr(size_t Size)
    {
        size = Size;
        strings = (clib::string*)malloc(sizeof(clib::string)*Size);
    }

    clib::string operator[](size_t pos) { return strings[pos]; }

};

StrArr directions;
long* magnitude;

StrArr getInput()
{
    StrArr input = StrArr(clib::FileReadAllText("input.txt"),'\n');
    return input;
}

void ParseInput(StrArr input)
{
    magnitude = (long*)malloc(sizeof(long)*input.size);
    directions = StrArr(input.size);
    StrArr temp;
    for (size_t i = 0; i < input.size; i++)
    {
        temp = StrArr(input[i],' ');
        magnitude[i]=std::stoll((char*)temp[1]);
        directions.strings[i] = temp[0];
    }
    
}

void MoveSub1()
{
    for (size_t i = 0; i < directions.size; i++)
    {
        if (directions[i] == mkString("forward"))
        {
            x1 += magnitude[i];
        }
        else if (directions[i] == mkString("up"))
        {
            y1 -= magnitude[i];
        }
        else if (directions[i] == mkString("down"))
        {
            y1 += magnitude[i];
        }
    }
    
}

void MoveSub2()
{
    for (size_t i = 0; i < directions.size; i++)
    {
        if (directions[i] == mkString("forward"))
        {
            x2 += magnitude[i];
            y2 += aim*magnitude[i];
        }
        else if (directions[i] == mkString("up"))
        {
            aim -= magnitude[i];
        }
        else if (directions[i] == mkString("down"))
        {
            aim += magnitude[i];
        }
    }
}

int main() 
{
    ParseInput(getInput());
    MoveSub1();
    std::cout << x1*y1 << std::endl;
    MoveSub2();
    std::cout << x2*y2 << std::endl;
    return 0;
}