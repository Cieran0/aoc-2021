#include <clibstr.h>
#include <clibio.h>

size_t singleLen;
size_t sumLen;

struct StrArr
{
    clib::string* strings;
    size_t size;

    StrArr(clib::string input, char splitChar) 
    {
        strings = input.split(splitChar,size);
    }

    clib::string operator[](size_t pos) { return strings[pos]; }

};

StrArr getInput()
{
    StrArr input = StrArr(clib::FileReadAllText("input.txt"),'\n');
    return input;
}

long* getNums(StrArr input) 
{
    long* nums = (long*)malloc(sizeof(long)*input.size);
    for (size_t i = 0; i < input.size; i++)
    {
        nums[i] = std::stoll((char*)input[i]);
    }
    singleLen = input.size;
    return nums;
}

size_t countBigger(long* nums, size_t len){
    size_t bigger = 0;
    for (size_t i = 0; i < len-1; i++)
    {
        if (nums[i+1] > nums[i]) bigger++;
    }
    return bigger;
}

long* getSums(long* nums)
{
    sumLen = singleLen-2;
    long* sums = (long*)malloc(sizeof(long)*sumLen);
    for (size_t i = 0; i < sumLen; i++)
    {
        sums[i] = nums[i] + nums[i+1] + nums[i+2]; 
    }
    return sums;
}

int main()
{
    long* nums = getNums(getInput());
    size_t bigger = countBigger(nums,singleLen);
    long* sums = getSums(nums);
    size_t biggerSums = countBigger(sums,sumLen);
    std::cout << bigger << std::endl;
    std::cout <<  biggerSums<< std::endl;
    return 0;
}