#include <iostream>

using namespace std;

void factorial();
int num_factorial(int val);
void fibonacci();
int num_fib(int val);

int main()
{
    int choice=-1;

    for (;choice!=0&&choice!=1&&choice!=2;) {
        cout << "Please select an option: \n1-Factorial\n2-Fibonacci\n0-Exit\n\n";
        choice=-1;
        cin >> choice;
    }

    switch (choice) {
    case 1:
        factorial();
        break;
    case 2:
        fibonacci();
        break;
    }

    return 0;
}

void factorial() {

    int num=0;

    cout << "Please enter a number.\n";
    cin >> num;

    int result = num_factorial(num);

    cout << "The result is: " << result << "\n\n";
}

int num_factorial(int val) {
    if (val==0)
        return 1;

    return val * num_factorial(val-1);
}

void fibonacci() {

    int num=0;

    cout << "Please enter a number.\n";
    cin >> num;

    int result = num_fib(num);

    cout << "The result is: " << result << "\n\n";

    cout << "The sequence is:\n";
    for (int x=0; x<=num; x++)
        cout << num_fib(x) << " ";
    cout << "\n\n";
}

int num_fib(int val) {
    if (val==0)
        return val;
    else if (val==1)
        return val;
    else
        return num_fib(val-1)+num_fib(val-2);
}
