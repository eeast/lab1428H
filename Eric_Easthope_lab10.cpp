#include <iostream>

using namespace std;

bool prime_no(int num);
bool happy_no(int num);
bool cycle_contains (int sum, int cycle[], int cap);
void add_to_cycle (int sum, int cycle[]);

int main()
{
    int number;
    bool prime, happy;

    cout << "Please enter a number.\n";
    cin >> number;

    prime = prime_no(number);
    happy = happy_no(number);

    cout << "Prime: " << prime << endl;
    cout << "Happy: " << happy << endl;

    if (prime==true) {
        if (happy==true)
            cout << "The number is both Happy and Prime!";
        else
            cout << "The number is Prime, but not Happy.";
    }
    else if (happy==true)
        cout << "The number is Happy, but not Prime.";
    else
        cout << "The number is not Happy or Prime. :(";

    return 0;
}

bool prime_no (int num) {

    if (num>0) {
        for (int x=2; x<num; x++) {
            int y;
            y = num%x;
            if (y==0) {
                return false;
            }
        }
        return true;
    }
    else {
        cout << "Number must be greater than 0.\n\n";
        return false;
    }
}

bool happy_no (int num) {
    int x, y, z, sum;
    int cycle[20];

    for (int c=0;c<20&&num!=1;c++) {
        x = num%10;
        y = (num/10)%10;
        z = (num/100)%10;

    cout << "100s 10s 1s: " << z << " " << y << " " << x << endl;

        sum = (x*x)+(y*y)+(z*z);

    cout << "SUM: " << sum << endl;

        bool repeat = cycle_contains(sum, cycle, c);
        if (repeat==false) {
            add_to_cycle(sum, cycle);
            num = sum;
        }
        else
            return false;
    }

    if (num==1)
        return true;
    else
        return false;
}

bool cycle_contains(int sum, int cycle[], int cap) {

    for (int x=0; x<cap; x++) {
        if (cycle[x]==sum) {
            return true;
        }
    }
    return false;
}

void add_to_cycle(int sum, int cycle[]) {
    static int x;
    cycle[x]=sum;
}
