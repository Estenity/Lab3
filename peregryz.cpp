#include "convert.h"
#include "sdt.h"

 ostream& operator << (ostream& output, const Scale& temp)
    {
        switch(temp)
        {
        case C:
            output << 'C';
            break;
        case K:
            output << 'K';
            break;
        case F:
            output << 'F';
            break;
        }
        return output;
}



  istream& operator>>(istream& input,Scale& temp)
    {
        char name;
        input >> name;
        switch(name)
        {
        case 'C':
            temp=C;
            break;
        case 'K':
            temp=K;
            break;
        case 'F':
            temp=F;
            break;
        default:
            input.setstate(ios_base::failbit);
            break;
        }
    }


    istream& operator >>
    (istream& input, Temperature& data)
    {
        input >> data.value >> data.symbol;
        return input;
    }

    ostream& operator <<
    (ostream& output, const Temperature& data)
    {
        output << data.value << data.symbol;
        return output;
    }




