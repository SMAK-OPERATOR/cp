#include "decorators.h"
#include <sstream>

std::string StoI(int i) // String to integer
{
    std::ostringstream StoI; //s
    StoI << i;
    return StoI.str();
}

IDecorator::IDecorator(Writer *c_writer) : writer(c_writer)
{
}

HtmlDecorator::HtmlDecorator(Writer *c_writer) : IDecorator(c_writer)
{
}

void HtmlDecorator::change()
{
    writer->content.insert(0, "<html>\n<body>\n<pre>\n", 0, 20);
    writer->content += "\n</pre>\n</body>\n</html>\n";
}

LineDecorator::LineDecorator(Writer *c_writer) : IDecorator(c_writer)
{
}

void LineDecorator::change()
{
    int i;
    std::string::size_type n, content_size;
    content_size = writer->content.size();
    n = writer->content.find('#');
    if (n == std::string::npos)
    {
        return;
    }
    if (n == 0)
    {
        writer->content.insert(0, "0| ", 0, 3);
        i = 1;
    }
    else
    {
        n--;
        i = 0;
    }
    while (n < content_size)
    {
        n = writer->content.find('\n', n);
        auto temp = StoI(i);
        temp.append("| ");
        writer->content.insert(n + 1, temp, 0, temp.size());
        n++;
        i++;
    }
}

CPPDecorator::CPPDecorator(Writer *c_writer) : IDecorator(c_writer)
{
}

std::vector<std::string> FromSpaceToSpace(std::string &str) // split a string by spaces
{
    std::vector<std::string> vect;
    int count = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ' || str[i] == '\n')
        {
            vect.push_back(str.substr(count, i - count));
            count = i;
        }
    }
    return vect;
}

void CPPDecorator::change()
{
    std::string::size_type n, content_size, count, check;
    std::vector<std::string> types = {"int", "void", "float", "double", "bool", "HtmlDecorator", "LineDecorator", "CPPDecorator", "Writers"};
    content_size = writer->content.size();
    n = writer->content.find('#');
    std::cout << content_size;
    while (n < content_size*2)
    {
        count = writer->content.find('\n', n);
        std::string temp = writer->content.substr(n, count + 1 - n);
        for (auto j : types)
        {
            check = temp.find(j);
            if (check != std::string::npos)
            {
                std::string font("<font color=0000FF>");
                writer->content.insert(n + check, font, 0, font.size());
                writer->content.insert(n + check + font.size() + j.size(), "</font>", 0, 7);
            }
        }
        check = temp.find("return");
        if (check != std::string::npos)
        {
            std::string font("<font color=FF0000>");
            writer->content.insert(n + check, font, 0, font.size());
            writer->content.insert(n + check + font.size() + 6, "</font>", 0, 7);
        }
        n = count + 1 ;
    }
}

// for(auto i : FromSpaceToSpace(temp))
// {
//     std::cout << i;
//     for(auto j : types)
//     {
//         if(i == j)
//         {
//             std::cout << "ssdads" << std::endl;
//             std::string font("<font color=0000FF>");
//             writer->content.insert(writer->content.find(j,n), font, 0, font.size());
//             writer->content.insert(writer->content.find(j,n)+j.size(), "</font>", 0, 7);
//         }
//     }
//     // std::cout << i << " ";
// }
// std::cout << std::endl;