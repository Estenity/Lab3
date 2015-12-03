#include "sdt.h"
double convert(double temperature, char from, char to);

int main()
{
    using namespace std;
    double degrees;
    char scale;
    vector <double> temp_tran;
    while (cout << "Please enter the temperature = ",cin >> degrees >> scale)
    {
        temp_tran.push_back(convert(degrees,scale,'K'));
    }
    cout << "       Translation Table      "<< endl;
    cout << fixed;
    cout.precision(1);
    for (double x:temp_tran)
    {
        cout << "Kelvin = " << x << "\t Celsius = " << x-273.15 <<"\t Fahrenheit = " << ((x-273.15)*1.8+32) <<endl;
    }
}
double convert(double temperature, char from, char to) //Объявление функции
{
    switch(from)
    {
    case 'K':
        if (temperature>=0)
        {
            switch(to)
            {
            case 'K':
            {
                temperature=temperature;
                return temperature;
                break;
            }
            case 'C':
            {
                temperature=temperature-273;
                return temperature;
                break;
            }
            case 'F':
            {
                temperature=temperature-459.67;
                return temperature;
                break;
            }
            default:
            {
                cout << "Error! Unknown scale. Please, use C, K or F" << endl;
            }
            }
        }
        else
        {
            cout << "Error! Temperature is below absolute zero" << endl;
            break;
        }
    case 'C':
        if (temperature>=-273.15)
        {
            switch(to)
            {
            case 'C':
            {
                temperature=temperature;
                return temperature;
                break;
            }
            case 'K':
            {
                temperature=temperature+273.15;
                return temperature;
                       break;
            }
            case 'F':
            {
                temperature=((temperature*9)/5)+32;
                return temperature;
                break;
            }
            default:
            {
                cout << "Error! Unknown scale. Please, use C, K or F" << endl;
            }
            }
        }
        else
        {
            cout << "Error! Temperature is below absolute zero" << endl;
            break;
        }
    case 'F':
        if (temperature>=-459.67)
        {
            switch(to)
            {
            case 'F':
            {
                temperature=temperature;
                return temperature;
                break;
            }
            case 'K':
            {
                temperature=(((temperature-32)*5)/9+273.15);
                return temperature;
                break;
            }
            case 'C':
            {
                temperature=(((temperature-32)*5)/9);
                return temperature;
                break;
            }
            default:
                cout << "Error! Unknown scale. Please, use C, K or F" << endl;
            }
        }
        else
        {
            cout << "Error! Temperature is below absolute zero" << endl;
            break;
        }
    default:
    {
        cout << "Error! Unknown scale. Please, use C, K or F" << endl;
    }
    }
//return temperature;
}
