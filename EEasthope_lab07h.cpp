#include <iostream>
#include <fstream>

using namespace std;


// Eric Easthope, A 0252123, ESE16

int main()
{
    int inst=0, op_code=0, data0=0, data1=0, data2=0;
    int ram[256]={4,23,10,40,5};

    ifstream fin ("input.txt");

    //cout << "How many instructions would you like to run?\n";
    fin >> inst;
    //cout << "Thank you. Let's begin.\n\n";

    for (int i=inst; i>0; i--) {
        //cout << "\nEnter the op_code:\n";
        fin >> op_code;

        if (op_code<5&&op_code>=0) {
            //cout << "Enter the storage index:\n";
            fin >> data0;
            //cout << "Enter the index for the left number:\n";
            fin >> data1;
            //cout << "Enter the index for the right number:\n";
            fin >> data2;
        }
        else if (op_code==5) {
            //cout << "Enter the index of the cell to be written to:\n";
            fin >> data0;
            //cout << "Enter the new value:\n";
            fin >> data1;
        }
        else if (op_code==6) {
            //cout << "Enter the index of the cell you want to see:\n";
            fin >> data0;
        }


        if (data0>255||data1>255||data2>255) {
            cout << "ERROR! Index requested is outside data range!";

        return -1;
        }

        switch (op_code) {

            case 0:
            {
                ram[data0] = ram[data1]+ram[data2];
                cout << "The sum is: " << ram[data0] << endl;
            }   break;

            case 1: {
                ram[data0] = ram[data1]-ram[data2];
                cout << "The difference is: " << ram[data0] << endl;
            }   break;

            case 2: {
                ram[data0] = ram[data1]*ram[data2];
                cout << "The product is: " << ram[data0] << endl;
            }   break;

            case 3: {
                if (ram[data2]!=0) {
                    ram[data0] = ram[data1]/ram[data2];
                    cout << "The quotient is: " << ram[data0] << endl;
                }
                else
                    cout << "Cannot divide by 0\n\n";
            }   break;

            case 4: {
                ram[data0]=1;
                for (int i=ram[data2]; i>0; i--) {
                    ram[data0] = ram[data0]*ram[data1];
                }
                cout << "The power is: " << ram[data0] << endl;
                }   break;

            case 5: {
                ram[data0]=data1;
                cout << "The new value of cell " << data0 << " is: " << ram[data0] << "\n\n";
            }   break;

            case 6: {
                cout << "The value of cell " << data0 << " is: " << ram[data0] << "\n\n";
            }   break;

            default: {
            cout << "Error! Please check your numbers and/or your operation selector and try again." << endl;
            }
        }
    }
    return 0;
}
