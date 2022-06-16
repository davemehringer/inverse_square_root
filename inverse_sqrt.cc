#include <math.h>
#include <string.h>
#include <sstream>
#include <iostream>

using namespace std;

float inv_sqrt(float number) {
    long i;
    float x2, y;
    const float threehalfs = 1.5F;

    x2 = number * 0.5F;
    y  = number;
    i  = * ( long * ) &y;                       // evil floating point bit level hacking
    i  = 0x5f3759df - ( i >> 1 );               // what the fuck? 
    y  = * ( float * ) &i;
    y  = y * ( threehalfs - ( x2 * y * y ) );   // 1st iteration
    y  = y * ( threehalfs - ( x2 * y * y ) );   // 2nd iteration, this can be removed

    return y;
}

int main(int argc, char *argv[]) {
	float number;
    string x(argv[1]);
    stringstream y(x);
    y >> number;
	auto inv = 1/inv_sqrt(number);
	auto actual = sqrt(number);
	cout << "inv " << inv << " actual " << actual << endl;
    cout << "rel error " << abs(1 - inv/actual) << endl;
}
