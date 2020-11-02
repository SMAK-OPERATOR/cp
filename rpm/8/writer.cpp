#include "writer.h"

Writer::Writer(std::istream &c_in)
{
    while (c_in)
    {
        char c;
        c_in.read(&c, 1);
        switch (c)
        {
        case '>':
            content += "&gt;";
            break;
        case '<':
            content += "&lt;";
            break;
        case '"':
            content += "&quot;";
            break;

        default:
            content.push_back(c);
            break;
        }
    }
}

void Writer::write(std::ofstream &m_sout)
{
    m_sout << content;
}
