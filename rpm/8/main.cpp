#include "decorators.h"
void q()
{
    return;
}
int main()
{
    std::ofstream FileToWrite("file.html");
    std::ifstream FileToRead("main.cpp");
    Writer *write = new Writer(FileToRead);
    HtmlDecorator html(write);
    LineDecorator ld(write);
    CPPDecorator cpp(write);
    cpp.change();
    html.change();
    ld.change();
    write->write(FileToWrite);
    return 0;

}