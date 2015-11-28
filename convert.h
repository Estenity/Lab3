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
bool operator < (const Temperature& first,const Temperature& second);
bool operator >(const Temperature& first,const Temperature& second);
Temperature operator + (const Temperature& first,const Temperature& second);
Temperature& operator += (Temperature& first,const Temperature& second);
Temperature operator / (const Temperature& first, double number);
Temperature& operator /= (Temperature& first,double number);

double convert(double temperature, Scale from, Scale to);
void minimax(const vector<Temperature> temp_res, Temperature &minimum, Temperature &maximum, Temperature &average);
