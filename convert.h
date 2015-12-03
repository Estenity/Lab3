#include "sdt.h"


enum Scale
{
C,
K,
F
};

struct Temperature{
   Temperature (double value, Scale symbol);
   double value;
   Scale symbol;
};


istream& operator >> (istream& input,Scale& temp);
ostream& operator << (ostream& output, const Scale& temp);
istream& operator >> (istream& input, Temperature& data);
ostream& operator << (ostream& output, const Temperature& data);


double convert(double temperature, Scale from, Scale to);

