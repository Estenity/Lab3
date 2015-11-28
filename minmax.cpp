#include "convert.h"
#include "sdt.h"



void minimax(const vector<Temperature> temp_res, Temperature &minimum, Temperature &maximum, Temperature &average)
{
    using namespace std;
    minimum=temp_res[0];
    maximum=temp_res[0];
    average=temp_res[0];
    for (Temperature x:temp_res)
    {
        if (x < minimum)
        {
            minimum=x;
        }
        else if (x>maximum)
        {
            maximum=x;
        }
        average+=x;
    }
}
