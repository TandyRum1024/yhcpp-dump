/*
    OOP Bank management system v1.0

    @ MjölkforDunk
*/

#include <iostream> // cout, cin and whatever!
#include <string>   // String
using namespace std;


/// function pre-decl
void drawFancyLine (int length, string name = "", bool thin = false);
void clearConsole ();
void showTitle ();
// account related
void newAccount ();
void deposit ();
void withdraw ();
void dumpAll ();
void dumpAccount ( int index );
int findAccount  ( int codeToFind );

/// vars
enum MENU_TYPE { NEW_ACCOUNT = 1, DEPOSIT, WITHDRAW, VIEW_ALL, QUIT };

// struct for account
typedef struct ST_ACCOUNT
{
    int code;
    int money;
    string name;
}Account;

// Array for holding accounts
Account accountArray[100];
int accountIdx;


///
/// MAIN
/// ==================================================================
int main (int argc, char const *argv[])
{
    int menuInput;
    bool success;

    while (1)
    {
        // clearConsole();
        // A - Show menu
        showTitle();
        cin >> menuInput;

        switch ( menuInput )
        {
            case NEW_ACCOUNT: // NEW ACCOUNT
                newAccount();
                break;

            case DEPOSIT:
                deposit();
                break;

            case WITHDRAW:
                withdraw();
                break;

            case VIEW_ALL:
                dumpAll();
                break;

            case QUIT:
                return 0xDEAD;
                break;

            
            default:
                clearConsole();
                cout << "Enter valid selection plz!! (" << menuInput << ')' << endl;
                menuInput = 0;
                cin.clear();
                cin.ignore(1000, '\n');
                break;
        }
    }
    return 0;
}


///
/// FUNCS
/// ==================================================================
/// Helper function
void drawFancyLine (int length, string name, bool thin)
{
    int ctr     = 0;
    int halfLen = (length >> 1);

    char drawChar = (thin) ? '-' : '=';

    while (ctr++ < halfLen)
    {
        cout << drawChar;
    }
    cout << name;
    while (ctr++ <= length)
    {
        cout << drawChar;
    }
    cout << endl;
}

void clearConsole ()
{
    int ctr = 0;
    while (ctr++ < 80)
    {
        cout << endl;
    }
}

/// Account related
//  =================

void newAccount ()
{
    clearConsole();
    drawFancyLine(8, "[ Account Creation ]");
    cout << "Account code : ";
    cin  >> accountArray[accountIdx].code;
    
    cout << "Account name : ";
    cin  >> accountArray[accountIdx].name;
    accountIdx++;
    clearConsole();

    cout << "Success!" << endl << "Created new account [" << accountArray[accountIdx - 1].name << "]!" << endl;
}

void deposit ()
{
    clearConsole();
    drawFancyLine(8, "[ Deposit ]");
    
    int code;
    int foundIdx;
    cout << "Account code : ";
    cin  >> code;
    foundIdx = findAccount(code);

    if (foundIdx == -1)
    {
        clearConsole();
        cout << endl << "INVALID ACCOUNT CODE! (" << code << ')' << endl;
        return;
    }

    drawFancyLine(12);

    int moneyToDeposit;
    cout << "How much : ";
    cin  >> moneyToDeposit;

    accountArray[foundIdx].money += moneyToDeposit;
    clearConsole();

    return;
}

void withdraw ()
{
    clearConsole();
    drawFancyLine(8, "[ Withdraw money ]");

    int code, foundIdx;
    cout << "Account code : ";
    cin  >> code;
    foundIdx = findAccount(code);

    if (foundIdx == -1)
    {
        clearConsole();
        cout << endl << "INVALID ACCOUNT CODE! (" << code << ')' << endl;
        return;
    }


    // set temp account pointer
    Account* currentAccount = &accountArray[foundIdx];

    int moneyToWithdraw;
    cout << "You have " << currentAccount->money << "$ left in your balance." << endl;
    cout << "How much do you want to Withdraw? : ";
    cin  >> moneyToWithdraw;

    // check if there's enough money
    if (currentAccount->money >= moneyToWithdraw)
    {
        clearConsole();
        currentAccount->money -= moneyToWithdraw;

        cout << "Withdrawed " << moneyToWithdraw << "$ from [" << currentAccount->name << "]!" << endl;
        cout << "(" << currentAccount->money << "$ left in balance...)" << endl;
    }
    else // Ho damn, You're broke as fuck!
    {
        clearConsole();
        cout << "NOT ENOUGH MONEY!! D:" << endl;
    }

    return;
}

void dumpAll ()
{
    clearConsole();
    drawFancyLine(8, "[ View all account ]");
    
    for (int i=0; i<accountIdx; i++)
    {
        dumpAccount( i );
        cout << endl;
    }

    return;
}

int findAccount ( int codeToFind )
{
    int foundIdx = 0;

    while ( foundIdx < accountIdx )
    {
        if (accountArray[foundIdx].code == codeToFind)
            return foundIdx;
        
        foundIdx++;
    }

    return -1;
}

void dumpAccount ( int index )
{
    Account* currentAccount = &accountArray[index];

    drawFancyLine(8, '['+currentAccount->name+']');
    cout << "Name : " << currentAccount->name << endl;
    cout << "Money : " << currentAccount->money << endl;
    cout << "Code : " << currentAccount->code << endl;
    drawFancyLine(10 + (int)currentAccount->name.length(), "", true);
}

/// Drawing function
void showTitle ()
{
    // fancy line
    drawFancyLine(14, "Hewwo");
    cout << endl;

    // contents
    cout << "1] New account" << endl;
    cout << "2] Deposit" << endl;
    cout << "3] Withdrawal" << endl;
    cout << "4] View all" << endl;
    cout << "5] Shutdown" << endl;
    
    drawFancyLine(19, "", true);
    cout << "Selection : ";
}