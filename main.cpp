#include "sdt.h"
#include "convert.h"

int main()
{
    using namespace std;
    Temperature data {0,K};
    Temperature minimum {0,K};
    Temperature maximum {0,K};
    Temperature average {0,K};
    vector <Temperature> temp_tran;
    while (cout << "Please enter the temperature = ",
            cin >> data)
    {
        try
        {
            temp_tran.push_back(Temperature(convert(data.value,data.symbol,K),K));
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
    cout.precision(2);
    ofstream output ("file.txt");
    for (Temperature x:temp_tran)
    {
        cout << "Kelvin = " << convert(x.value,K,K)<< "\t Celsius = " << convert(x.value,K,C) <<"\t Fahrenheit = " << convert(x.value,K,F) <<endl;
        output << "Result: " << x << '\n';

    }
    cout << endl;
    minimax(temp_tran,minimum,maximum,average);
    cout << "Minimum=" << minimum << "\t Maximum=" << maximum <<"\t Average=" << average <<endl;
}
