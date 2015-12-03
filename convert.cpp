#include "sdt.h"
#include "convert.h"

double convert(double temperature, Scale from, Scale to) //Объявление функции
{
    switch(from)
    {
    case K:
        if (temperature>=0)
        {
            switch(to)
            {
            case K:
            {
                temperature=temperature;
                return temperature;
                break;
            }
            case C:
            {
                temperature=temperature-273.15;
                return temperature;
                break;
            }
            case F:
            {
                temperature=1.8*(temperature-273.15)+32;
                return temperature;
                break;
            }
            default:
            {
                throw invalid_argument("Unknown scale");
                break;
            }
            }
        }
        else
        {
            throw logic_error("Temperature is below absolute zero");
            break;
        }
    case C:
        if (temperature>=-273.15)
        {
            switch(to)
            {
            case C:
            {
                temperature=temperature;
                return temperature;
                break;
            }
            case K:
            {
                temperature=temperature+273.15;
                return temperature;
                break;
            }
            case F:
            {
                temperature=((temperature*9)/5)+32;
                return temperature;
                break;
            }
            default:
            {
                throw invalid_argument("Unknown scale");
                break;
            }
            }
        }
        else
        {
            throw logic_error("Temperature is below absolute zero");
            break;
        }
    case F:
        if (temperature>=-459.67)
        {
            switch(to)
            {
            case F:
            {
                temperature=temperature;
                return temperature;
                break;
            }
            case K:
            {
                temperature=(((temperature-32)*5)/9+273.15);
                return temperature;
                break;
            }
            case C:
            {
                temperature=(((temperature-32)*5)/9);
                return temperature;
                break;
            }
            default:
                throw invalid_argument("Unknown scale");
                break;
            }
        }
        else
        {
            throw logic_error("Temperature is below absolute zero");
            break;
        }
    default:
    {
        throw invalid_argument("Unknown scale");
        break;
    }
    }
    return temperature;
}
