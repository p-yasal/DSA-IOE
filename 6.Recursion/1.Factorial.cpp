/*Find factorial for given number N*/
#include <iostream>
using namespace std;
class fact
{

public:
    int factorial(int n)
    {
        if (n == 0)
            return 1;
        else
            return n * factorial(n - 1);
    }
};
int main()
{
    fact f;
    int n;
    cout << "Enter the non negative integer whose factorial is to be determined:";
    cin >> n;
    cout << f.factorial(n);
    return 0;
}