#include "sdt.h"
#include "convert.h"

int main()
{
    using namespace std;
    double degrees,total;
    Scale TekScale;
    vector <double> temp_tran;
    while (cout << "Please enter the temperature = ",
            cin >> degrees,
            cin >> (char&) TekScale)
    {
        try
        {
            double total = convert(degrees,TekScale,K);
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

