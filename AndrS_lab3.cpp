#include "sdt.h"
enum error {er_temp,er_scale,no_er};
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
            return temperature;
            break;
        }
        else
        {
            cout << "Error! Temperature is below absolute zero" << endl;
            break;
        }
    case 'C':
        if (temperature>=-273.15)
        {
            temperature=temperature+273.15;
            return temperature;
            break;
        }
        else
        {
            cout << "Error! Temperature is below absolute zero" << endl;
            break;
        }
    case 'F':
        if (temperature>=-459.67)
        {
            temperature=(((temperature-32)*5)/9+273.15);
            return temperature;
            break;
        }
        else
        {
            cout << "Error! Temperature is below absolute zero" << endl;
            break;
        }
    default:
        cout << "Error! Unknown scale. Please, use C, K or F" << endl;
    }
}
