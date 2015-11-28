#include "sdt.h"
#include "convert.h"

double convert(double temperature, Scale from, Scale to) //Объявление функции
{
    switch(from)
    {
    case K:
        if (temperature>=0)
        {
            temperature=temperature;
            break;
        }
        else
        {
            throw logic_error("Temperature is below absolute zero");
            break;
        }
    case C:
        if (temperature>=-273.15)
        {
            temperature=temperature+273.15;
            break;
        }
        else
        {
            throw logic_error("Temperature is below absolute zero");
            break;
        }
    case F:
        if (temperature>=-459.67)
        {
            temperature=(((temperature-32)*5)/9+273.15);
            break;
        }
        else
        {
            throw logic_error("Temperature is below absolute zero");
            break;
        }
    default:
        throw invalid_argument("Unknown scale");
    }
    return temperature;
}
