#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void betFunc(int &myMoney, int &bet);
void getRolls(int &compDie1, int &userDie1);
void results(int &compDie1, int &userDie1, int &myMoney, int &betAmount);
bool repeatx(int myMoney);

int main()
{
    int myMoney, bet, compDie, userDie;
    bool repeat=true;

    cout << "Gambling is an addiction...\n\n";

    myMoney = 1000;

    for (;repeat;) {
        betFunc(myMoney, bet);
        getRolls(compDie, userDie);
        results(compDie, userDie, myMoney, bet);
        repeat = repeatx(myMoney);
    }

    cout << "You ended with $" << myMoney << "\n\n";

    return 0;
}

void betFunc(int &myMoney, int&bet){
    cout << "You currently have $" << myMoney << endl;
    cout << "How much do you bet?\n\n";

    for (bet=-1; bet<0||bet>myMoney;) {
        cin >> bet;
        if (bet<0||bet>myMoney) {
            cout << "Bet must be positive and less than your current holdings.\n";
            cout << "Your current balance is $" << myMoney << endl;
            cout << "Please enter a new bet.\n";
        }
    }
}

void getRolls(int &compDie1, int &userDie1){
    srand(time(NULL));
    userDie1 = rand()%6 + 1;
    compDie1 = rand()%6 + 1;

    cout << "You rolled a " << userDie1 << endl;
    cout << "Your opponent rolled a " << compDie1 << endl;
}

void results(int &compDie1, int &userDie1, int &myMoney, int &bet){
    if (compDie1<userDie1) {
        cout << "You gain $" << bet  << endl;
        myMoney+=bet;
        cout << "You now have $" << myMoney << endl;
    }
    else if (compDie1>userDie1) {
        cout << "You lose $" << bet << endl;
        myMoney-=bet;
        cout << "You now have $" << myMoney << endl;
    }
    else if (compDie1==userDie1) {
        cout << "Money is returned\n\n";
    }
}

bool repeatx(int myMoney) {
    char choice='x';

    if (myMoney==0)
        return false;

    for (;choice!='Y' && choice!='N' && choice!='y' && choice!='n';) {
        choice='x';
        cout << "Would you like to continue? ('y' or 'n')\n";
        cin >> choice;
        if (choice=='Y'||choice=='y')
            return true;
        else if (choice=='N'||choice=='n')
            return false;
    }
    cout << "No choice made.";
    return false;
}
