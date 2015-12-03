#include "convert.h"
#include "sdt.h"

bool operator <(const Temperature& first,const Temperature& second)
{
    return convert(first.value,first.symbol,K) < convert(second.value,second.symbol,K);
}

bool operator >(const Temperature& first,const Temperature& second)
{
    return convert(first.value,first.symbol,K) > convert(second.value,second.symbol,K);
}



Temperature operator + (const Temperature& first,const Temperature& second)
{
    return{first.value+convert(second.value,second.symbol,first.symbol),first.symbol};
}


Temperature& operator += (Temperature& first,const Temperature& second)
{
    first.value=first.value+convert(second.value,second.symbol,first.symbol);
    return first;
}


Temperature operator / (const Temperature& first,double number)
{
    double val_del;
    val_del=first.value;
    return{val_del/number,first.symbol};
}

Temperature& operator /= (Temperature& first,double number)
{
    double val_del;
    val_del=first.value;
    first.value=val_del/number;
    return first;
}



 ostream& operator << (ostream& output, const Scale& temp)
    {
        char name;
        //output << name;
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
        return input;
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




