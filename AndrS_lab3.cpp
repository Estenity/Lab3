#include "sdt.h"

int last_error = 0;
double convert(double temperature, char from, char to);
int get_last_error();
int main()
{
    using namespace std;
    double degrees;
    char scale;
    vector <double> temp_tran;
    while (cout << "Please enter the temperature = ",cin >> degrees >> scale)
    {
        double total = convert(degrees,scale,'K');
        switch(get_last_error())
        {
        case 0:
        {
            temp_tran.push_back(total);
            break;
        }
        case 1:
        {
            cerr << "Error! (Unknown scale or temperature below absolute zero)" << endl;
            break;
        }
        default:
        {
            cerr << "Unknown error!" << endl;
            break;
        }
        }
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
last_error=0;
    switch(from)
    {
    case 'K':
        if (temperature>=0)
        {
            temperature=temperature;
            break;
        }
        else
        {
            last_error=1;
            break;
        }
    case 'C':
        if (temperature>=-273.15)
        {
            temperature=temperature+273.15;
            break;
        }
        else
        {
            last_error=1;
            break;
        }
    case 'F':
        if (temperature>=-459.67)
        {
            temperature=(((temperature-32)*5)/9+273.15);
            break;
        }
        else
        {
            last_error=1;
            break;
        }
    default:
        last_error=1;
    }
    return temperature;
}
int get_last_error()
{
    return last_error;
}

