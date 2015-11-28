#include "sdt.h"

double convert(double temperature, char from, char to);
int main()
{
    using namespace std;
    double degrees,total;
    char scale;
    vector <double> temp_tran;
    while (cout << "Please enter the temperature = ",cin >> degrees >> scale)
    {
        try
        {
            double total = convert(degrees,scale,'K');
            temp_tran.push_back(total);
        }
        catch (const invalid_argument& e)
        {
            cerr << e.what() << endl;
        }
        catch (const logic_error& le)
        {
            cerr << le.what() << endl;
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
            throw logic_error("Temperature is below absolute zero");
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
            throw logic_error("Temperature is below absolute zero");
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
            throw logic_error("Temperature is below absolute zero");
            break;
        }
    default:
        throw invalid_argument("Unknown scale");
    }
    return temperature;
}
