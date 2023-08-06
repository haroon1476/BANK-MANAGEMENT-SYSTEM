

        // ------------------------------------------------------------------------------------ //
       // ----------------  BANK MANAGEMENT SYSTEM IN C++ BY HAROON UR RASHEED  -------------- //
      // ------------------------------------------------------------------------------------ //


// INCLUDING HEADER FILES

#include <iostream>
#include <string>
#include <stdlib.h>


using namespace std;

// -------------------------------------------------------------  //
// -----  Declaring a user-defined variable(structure) here  ---  //
// -------------------------------------------------------------  //


struct customerInfo {

    string name;
    string city;
    int pin;
    string cnic;
    double balance;
};


// --------------------------------------------------------- //
// ---------------  FUNCTIONS DECLERATION  ----------------- //
// --------------------------------------------------------- // 

double depositAmount(customerInfo* structPtr, double amount);
double withdrawAmount(customerInfo* structPtr, double amount);
int CheckPinLength(customerInfo* structPtr, int pinCode);
void checkPinCode(customerInfo* structPtr, int pinCode);
int changePinCode(customerInfo* structPtr, int pinCode);
void displayMenu();
// In each function above , a referenced structured pointer is used as an argument



// ---------------------------------------------------------- //
// --------------------  MAIN FUNCTION  --------------------- //
// ---------------------------------------------------------- // 

int main() {


    // Declared my structure object
    customerInfo myCustomer;

    // making a pointer structure and storing the address of my initialized structure to it
    customerInfo* customerPtr = nullptr;
    customerPtr = &myCustomer;


    // VARIBLES DEFINING SECTION
    string name;
    int pinCode , prev_pin, new_pin , opt;
    double dep_amnt , with_amnt;
    char tryAgain;


    // ----------------------------------------------------------------- //
    // -------------------------  MAIN BODY OF CODE  ------------------- // 
    // ----------------------------------------------------------------- //


    cout << "\n\n\n";
    cout << "\n\n\t\t -------------------------------------------------------------------------------\n";
    cout << "\n                                                                                        ";
    cout << "\n\n\t\t\t\t       WELCOME TO BANK MANAGEMENT SYSTEM IN C++                               ";
    cout << "\n\t\t\t                     BY HAROON UR RASHEED                                         ";
    cout << "\n                                                                                        ";
    cout << "\n\n\n\t\t ------------------------------------------------------------------------------ \n";



    // Setting initials
    cout << "\n\nWelcome dear user! Please enter your name : ";
    getline(cin, customerPtr->name);

    cout << "\nPlease enter city of your residence : ";
    getline(cin, customerPtr->city);

    cout << "\nWelcome Mr " << customerPtr->name << " Please set your five digit pincode : ";
    cin >> pinCode;
    customerPtr->pin = CheckPinLength(customerPtr, pinCode);

    // Clearing screen
    system("CLS");

    cout << "\nYour pin has been set succesfully. \n";

    // Initial balance of customer is set to default 0
    customerPtr->balance = 0.0;


    do
    {
        displayMenu();
        cin >> opt;

        switch (opt)
        {

        case 1:

            // Depositing amount here
            cout << "\nEnter amount you want to deposit in your account : ";
            cin >> dep_amnt;
            while (dep_amnt < 0.0)
            {
                cout << "Invalid amount entered. Enter correct amount : ";
                cin >> dep_amnt;
            }
            customerPtr->balance = depositAmount(customerPtr, dep_amnt);
            cout << "\nAmount deposited successfully. New account balance is " << customerPtr->balance << "\n";

            break;


        case 2:

            // Widthdrawing amount here
            cout << "\nEnter amount you want to withdraw in your account : ";
            cin >> with_amnt;
            while (with_amnt < 0.0)
            {
                cout << "\nInvalid amount entered. Enter correct amount : ";
                cin >> with_amnt;
            }
            while (with_amnt > customerPtr->balance)
            {
                cout << "\nYou donot have enough balance in your account. Enter amount again : ";
                cin >> with_amnt;
            }
            customerPtr->balance = withdrawAmount(customerPtr, with_amnt);
            cout << "\nAmount withdawn successfully. New account balance is " << myCustomer.balance << "\n";

            break;


        case 3:

            // Displaying account info here

            cout << "\nYour account details are \n\n";
            cout << "--------------------------------------------------------\n";
            cout << " Account Holder Name : " << customerPtr->name << "\n";
            cout << " CNIC : 42000-******41-5 \n";
            cout << " City : " << customerPtr->city << "\n";
            cout << " Account Balance : " << customerPtr->balance << "\n\n";
            cout << "--------------------------------------------------------\n";

            break;


        case 4:

            // Changing pincode here
            cout << "\nEnter your previous pincode : ";
            cin >> prev_pin;

            // Checking if the user has entered correct password (through checkPinCode function) 
            // to proceed towards password changing process.
            checkPinCode(customerPtr, prev_pin);

            cout << "\nEnter new pincode : ";
            cin >> new_pin;

            // Changing password through below function
            customerPtr->pin = changePinCode(customerPtr, new_pin);

            cout << "\nPassword changed successfully. New pincode is " << customerPtr->pin << "\n";

            break;
           

        case 5:

            // Displaying balance here
            cout << "\nYour account balance is " << customerPtr->balance << "\n";

            break;


        case 6:

            // Exiting here
            cout << "\nThank you Mr " << customerPtr->name << " for visiting. \n";

            exit(1);
            break;


        default:

            cout << "\nInvalid option selected.\n";

            break;
        }

        // Checking if the user wants to make another transaction or not
        cout << "\nDo you want to make another transaction ? (Y \ N) : ";
        cin >> tryAgain;

        while (tryAgain != 'y' && tryAgain != 'Y' && tryAgain != 'n' && tryAgain != 'N')
        {
            cout << "\nInvalid option selected. Enter (Y\N) : ";
            cin >> tryAgain;
        }

    } while (tryAgain == 'Y' || tryAgain == 'y');




    return 0;
}



// ----------------------------------------------------- // 
// ------------  FUNCTIONS DEFINITIONS  ---------------- //
// ----------------------------------------------------- // 


int CheckPinLength(customerInfo* structPtr, int pin) {

    int c = 5;

    while (pin < 10000 || pin > 99999)
    {
        cout << "\nEntered pincode is invalid. Pincode must be exactly five digits long. ";
        c--;
        if (c == 1)
        {
            cout << "This is your last attempt. In case of incorrect pin , your account will be blocked.";
        }
        else if (c == 0)
        {
            cout << "Your card has been blocked. \n";
            exit(0);
        }

        cout << " Enter again : " ;
        cin >> pin;
    }

    return pin;
}



void displayMenu() {

    cout << "\n\n Select one of the following options \n\n";
    cout << "\n 1) Deposit amount \n 2) Widthdraw amount \n 3) Check Account Info \n 4) Change pin \n 5) Checkh Balance \n 6) Exit \n\n";

    return;
}




double depositAmount(customerInfo* structPtr, double amount) {

    structPtr->balance += amount;
    return structPtr->balance;
}




double withdrawAmount(customerInfo* structPtr, double amount) {

    structPtr->balance -= amount;
    return structPtr->balance;
}




void checkPinCode(customerInfo* structPtr, int pinCode) {

    int c = 5;
    while (pinCode != structPtr->pin)
    {
        c--;
        cout << "\nIncorrect pin. ";
        
        if (c == 1)
        {
            cout << "This is your last attempt. In case of incorrect pin , your account will be blocked.";
        }
        else if (c == 0)
        {
            cout << "\nYour card has been blocked. \n";
            exit(0);
        }

        cout << " Enter again : ";
        cin >> pinCode;
    }

    // This fuction will return to main if and only if previous entered password is correct.
    return;
}




int changePinCode(customerInfo* structPtr, int pinCode) {

    int c = 5;

    pinCode = CheckPinLength(structPtr, pinCode);
    while (pinCode == structPtr->pin)
    {
        c--;
        cout << "\nNew password cannot be old password. Enter again : ";
        if (c == 0)
        {
            cout << "\nYour card has been blocked. \n";
            exit(0);
        }

        cin >> pinCode;
        pinCode = CheckPinLength(structPtr, pinCode);
    }


    return pinCode;
}




          // -------------------------------------------------------------------------------- //
         // ------------------------------ THAT'S ALL -------------------------------------- // 
        // -------------------------------------------------------------------------------- //