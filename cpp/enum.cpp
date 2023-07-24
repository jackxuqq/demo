#include <iostream>

enum FileType
{
    FileTypeAscii = 1,
    FileTypeBinaray,
};


void func(FileType ft)
{
    std::cout << "ft:=" << ft << std::endl;
}

int main(){
    FileType ft;
    ft = FileType(100);
    func(ft);
}
