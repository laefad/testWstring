//#include <fmt/color.h>

#include <string>

#include <locale>
#include <codecvt>

#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

std::wstring readFile(const char* filename)
{
    std::wifstream wif(filename);
    wif.imbue(locale(wif.getloc(), new codecvt_utf16<wchar_t, 0x10ffff>()));
    std::wstringstream wss;
    wss << wif.rdbuf();
    return wss.str();
}


void writeToFile(const char* filename, std::wstring& wstr)
{
    std::wofstream wof(filename);
    wof.imbue(locale(wof.getloc(), new codecvt_utf16<wchar_t, 0x10ffff>()));
    wof << wstr;
}

int main () {

    setlocale(LC_ALL, "");

    wstring wstr = readFile("./test.txt");
    wcout << wstr << endl;
    writeToFile("./result.txt", wstr);


    const wchar_t* a = L"пароль))";
    wcout << L"Your password:" << endl;
    wcout << L"" - 25 << endl;


    // fmt::print(fg(fmt::color::crimson) | fmt::emphasis::bold,
    //            "Hello, {}!\n", "world");
    // fmt::print(fg(fmt::color::floral_white) | bg(fmt::color::slate_gray) |
    //            fmt::emphasis::underline, "Hello, {}!\n", "мир");
    // fmt::print(fg(fmt::color::steel_blue) | fmt::emphasis::italic,
    //            "Hello, {}!\n", "世界");
               
}