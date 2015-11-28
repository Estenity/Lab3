enum Scale:char
{
C='C',
K='K',
F='F'
};
double convert (double temperature, Scale from, Scale to);
struct Temperature{
   Temperature (double value, Scale symbol);
   double value;
   Scale symbol;
};


