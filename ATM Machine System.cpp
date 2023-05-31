#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
using namespace std;

int Account_Balance = 250000;

class Login {
public:
    string ID_1, ID_2, pass_2, current_pass, new_pass, new_pass_2, pass_1, acc_balance_1, acc_balance_2, ID, pass;
    void Thank_you_Title ();

    bool signup() {
        string username, password;

        cout << "Choose a Username: ";
        cin.clear();
        getline(cin,username);
        cout << "Choose a Password: ";
        getline(cin,password);

        ofstream file(username + ".txt");
        if (file.is_open()) {
            file << username << endl;
            file << password << endl;
            file << Account_Balance << endl;
            file.close();
            cout << "Signup Successful!" << endl;
            return true;
        }
        else {
            cout << "Error: Failed to create user file." << endl;
            return false;
        }
    }

    bool login_function() {
        system("cls");
        login_page();

        bool loginSuccess = false;
        do {
            cout << "\nEnter Your Username: ";
            getline(cin, ID);

            ifstream userFile(ID + ".txt");
            if (!userFile) {
                cout << "User does not exist. Please try again." << endl;
                continue;
            }

            string storedID, storedPass;
            getline(userFile, storedID);
            getline(userFile, storedPass);
            userFile.close();

            cout << "Enter Your Password: ";
            getline(cin, pass);

            if (pass != storedPass) {
                cout << "Incorrect password. Please try again." << endl;
                continue;
            }

            loginSuccess = true;
        } while (!loginSuccess);

        cout << "Login Successful!" << endl;
        return true;
    }


    void login_page() {
        cout << "============================================\n";
        cout << "              LOGIN PAGE          \n";
        cout << "============================================\n\n";
    }

};

class Bank : virtual public Login {
public:
    int choice, Fast_cash_choice, withdraw_Account, Withraw_money, C_Payments, school_fees, School_Name, School_ID, wanna_pay;
    int flag=0;
    string mini="Your Mini Statement is: ",mini_cash1,mini_cash2,mini_cash3,mini_cash4,mini_cash5,mini_cash6,mini_cash7;
    string mini_cash8,mini_gas,mini_water,mini_electric,mini_city,mini_allied,mini_beacon,mini_smart;
public:
    void Main_Menu();
    void Fast_cash_Title();
    void Cash_Withdrwal_Title();
    void Balance_Inquiry_Title();
    void Mini_statement_Title();
    void Funds_transfer_Title();
    void Payment_Title();
    void sing_out_Title();
    void Thank_you_Title();
};

class PIN_change : public Login {
public:
	void Pin_change_Title();
    bool pin_change() {
        system("cls");
        login_page();
        string new_Pass;
        bool flag = false;

        flag = login_function();

        if (flag) {
            cout << "Enter New Password: ";
            getline(cin, new_Pass);

            string filePath = ID + ".txt";

            ofstream write(filePath);
            if (!write) {
                cout << "Error: Failed to open file." << endl;
                return false;
            }

            write << ID << endl;
            write << new_Pass << endl;
            write.close();

            cout << "Password changed successfully!" << endl;
            return true;
        }
        return false;
    }

    void login_page() {
        cout << "============================================\n";
        cout << "              LOGIN PAGE          \n";
        cout << "============================================\n\n";
    }
};

class FAST_CASH : virtual public Bank {
public:
    void Fast_cash() {
        try {
            cout << "\n\t1. 500               2.1000. " << endl;
            cout << "\n\t3. 3000              4.5000. " << endl;
            cout << "\n\t5. 8000              6.10000. " << endl;
            cout << "\n\t6. 15000             8.20000. " << endl;
            cout << "-------->Enter Your Choice.";

            cin >> Fast_cash_choice;

            while (cin.fail()) {
                cin.clear();
                while (cin.get() != '\n')
                    continue;
                cout << "Invalid input. Please enter a number." << endl;
                cin >> Fast_cash_choice;
            }

            switch (Fast_cash_choice) {
            case 1: {
                Fast_cash_Title();
                if (Account_Balance < 0) {
                    cout << "Not enough balance\n";
                    cout << "Press any key to continue";
                    getch();
                } else {
                    Account_Balance -= 500;
                    cout << "You have Successfully withdrawn 500rs\n\n";
                    mini_cash1 = "\n==>500Rs were withdrawn\n";
                    cout << "Press any key to continue";
                    getch();
                }
                break;
            }
            case 2: {
                system("cls");
                if (Account_Balance < 0) {
                    cout << "Not enough balance\n";
                    cout << "Press any key to continue";
                    getch();
                } else {
                    Account_Balance -= 1000;
                    cout << "You have Successfully withdrawn 1000rs\n\n";
                    mini_cash2 = "\n==>1000Rs were withdrawn\n";
                    cout << "Press any key to continue";
                    getch();
                }
                break;
            }
            case 3: {
                system("cls");
                if (Account_Balance < 0) {
                    cout << "Not enough balance\n";
                    cout << "Press any key to continue";
                    getch();
                } else {
                    Account_Balance -= 3000;
                    cout << "You have Successfully withdrawn 3000rs\n\n";
                    mini_cash3 = "\n==>3000Rs were withdrawn\n";
                    cout << "Press any key to continue";
                    getch();
                }
                break;
            }
            case 4: {
                system("cls");
                if (Account_Balance < 0) {
                    cout << "Not enough balance\n";
                    cout << "Press any key to continue";
                    getch();
                } else {
                    Account_Balance -= 5000;
                    cout << "You have Successfully withdrawn 5000rs\n\n";
                    mini_cash4 = "\n==>5000Rs were withdrawn\n";
                    cout << "Press any key to continue";
                    getch();
                }
                break;
            }
            case 5: {
                system("cls");
                if (Account_Balance < 0) {
                    cout << "Not enough balance\n";
                    cout << "Press any key to continue";
                    getch();
                } else {
                    Account_Balance -= 8000;
                    mini_cash5 = "\n==>8000Rs were withdrawn\n";
                    cout << "You have Successfully withdrawn 8000rs\n\n";
                    cout << "Press any key to continue";
                    getch();
                }
                break;
            }
            case 6: {
                system("cls");
                if (Account_Balance < 0) {
                    cout << "Not enough balance\n";
                    cout << "Press any key to continue";
                    getch();
} else {
Account_Balance -= 10000;
mini_cash6 = "\n==>10000Rs were withdrawn\n";
cout << "You have Successfully withdrawn 10000rs\n\n";
cout << "Press any key to continue";
getch();
}
break;
}
case 7: {
system("cls");
if (Account_Balance < 0) {
cout << "Not enough balance\n";
cout << "Press any key to continue";
getch();
} else {
Account_Balance -= 15000;
mini_cash7 = "\n==>15000Rs were withdrawn\n";
cout << "You have Successfully withdrawn 15000rs\n\n";
cout << "Press any key to continue";
getch();
}
break;
}
case 8: {
system("cls");
Fast_cash_Title();
if (Account_Balance < 0) {
cout << "Not enough balance\n";
cout << "Press any key to continue";
getch();
} else {
Account_Balance -= 20000;
mini_cash8 = "\n==>20000Rs were withdrawn\n";
cout << "You have Successfully withdrawn 20000rs\n\n";
cout << "Press any key to continue";
getch();
}
break;
}
default: {
system("cls");
cout << "Incorrect Input\n\n";
cout << "\nPress any key to continue";
getch();
break;
}
}
} catch (const exception& e) {
cout << "Exception caught: " << e.what() << endl;
cout << "Press any key to continue";
getch();
}
}
};



class CASH_WITHDRAL : virtual public Bank {
public:
    void Cash_withdraw() {
        try {
            cout << "Enter Account Number From You Want To Withdraw: ";
            cin >> withdraw_Account;

            if (cin.fail()) {
                throw runtime_error("Invalid input. Account number should be a number.");
            }

            cout << "\nEnter Amount You Want to Withdraw From Your Account: ";
            cin >> Withraw_money;

            if (cin.fail()) {
                throw runtime_error("Invalid input. Withdrawal amount should be a number.");
            }

            if (Account_Balance >= Withraw_money && Withraw_money > 0) {
                Account_Balance -= Withraw_money;
                cout << "Rs " << Withraw_money << " has been successfully withdrawn from Acc No. " << withdraw_Account << endl;
                cout << "Press any Key to Continue....." << endl;
                getch();
            } else {
                cout << "No Enough Money In Your Account or You entered a wrong amount." << endl;
                cout << "Press any Key to Continue....." << endl;
                getch();
            }
        } catch (const exception& e) {
            cout << "Exception caught: " << e.what() << endl;
            cout << "Press any key to continue";
            getch();
        }
    }
};


class Balance_Inquiry : public Bank {
public:
    void B_Inquiry() {
        cout << "Your account Balance is :" << Account_Balance << endl ;
        getch ();
    }
};
class Funds_Transfer : virtual public Bank {
public:
    void F_Transfer() {
        try {
            int Fund_transfer_acc, FundsTransfer_money;
            cout << "Enter Account Number You Want to transfer Fund: ";
            cin >> Fund_transfer_acc;

            if (cin.fail()) {
                throw runtime_error("Invalid input. Account number should be a number.");
            }

            cout << "Enter Amount of Money You want to Transfer: ";
            cin >> FundsTransfer_money;

            if (cin.fail()) {
                throw runtime_error("Invalid input. Transfer amount should be a number.");
            }

            if (Account_Balance > 0 && FundsTransfer_money <= Account_Balance && FundsTransfer_money > 0) {
                Account_Balance -= FundsTransfer_money;
                cout << "Rs " << FundsTransfer_money << " has been successfully transferred from Acc No. " << Fund_transfer_acc << endl;
                cout << "Press any Key to Continue....." << endl;
                getch();
            } else {
                cout << "Low Account Balance or You entered a negative amount." << endl;
                cout << "Press any Key to Continue....." << endl;
                getch();
            }
        } catch (const exception& e) {
            cout << "Exception caught: " << e.what() << endl;
            cout << "Press any key to continue";
            getch();
        }
    }
};

class Payments :public Bank {
public:
    void PAYMENTS() {
        try {
            cout << "\n1.School Fees \n2.Electricity Bills \n3.Water Bill \n4.Gas" << endl ;
            cout << "Enter Your Choice : " ;
            int C_Payments;
            while (!(cin >> C_Payments)) {
                cout << "Invalid choice. Please enter a valid choice: ";
                cin.clear();
                while (cin.get() != '\n') {}
            }

            switch (C_Payments) {
                case 1: {
                    cout << "\n1. City school ";
                    cout << "\n2. Allied school ";
                    cout << "\n3. Beacon house";
                    cout << "\n4. The smart school ";
                    cout << "\nSelect Your school : ";
                    cout << "Enter Choice : ";
                    int School_Name;
                    while (!(cin >> School_Name)) {
                        cout << "Invalid choice. Please enter a valid choice: ";
                        cin.clear();
                        while (cin.get() != '\n') {}
                    }

                    system("cls");
                    switch (School_Name) {
                        case 1: {
                            cout << "Enter ID : ";
                            int School_ID;
                            while (!(cin >> School_ID)) {
                                cout << "Invalid ID. Please enter a valid ID: ";
                                cin.clear();
                                while (cin.get() != '\n') {}
                            }

                            cout << "Your School fees is : 2000.";
                            cout << "Do You Want To Pay fee \n1.YES\n2.NO .";
                            int wanna_pay;
                            while (!(cin >> wanna_pay)) {
                                cout << "Invalid choice. Please enter a valid choice: ";
                                cin.clear();
                                while (cin.get() != '\n') {}
                            }

                            switch (wanna_pay) {
                                case 1:
                                    if (Account_Balance > 2000) {
                                        cout << "Fees Successfully Paid." << endl;
                                        Account_Balance = Account_Balance - 2000;
                                    } else {
                                        throw "Low Account Balance.";
                                    }
                                    break;
                                default:
                                    throw "Invalid choice.";
                            }
                            break;
                        }
                        case 2: {
                            cout << "Enter ID : ";
                            int School_ID;
                            while (!(cin >> School_ID)) {
                                cout << "Invalid ID. Please enter a valid ID: ";
                                cin.clear();
                                while (cin.get() != '\n') {}
                            }

                            cout << "Your School fees is : 2500.";
                            cout << "Do You Want To Pay fee \n1.YES\n2.NO .";
                            int wanna_pay;
                            while (!(cin >> wanna_pay)) {
                                cout << "Invalid choice. Please enter a valid choice: ";
                                cin.clear();
                                while (cin.get() != '\n') {}
                            }

                            switch (wanna_pay) {
                                case 1:
                                    if (Account_Balance > 2500) {
                                        cout << "Fees Successfully Paid." << endl;
                                        Account_Balance = Account_Balance - 2500;
                                    } else {
                                        throw "Low Account Balance.";
                                    }
                                    break;
                                default:
                                    throw "Invalid choice.";
                            }
                            break;
                        }
                        case 3: {
                            cout << "Enter ID : ";
                            int School_ID;
                            while (!(cin >> School_ID)) {
                                cout << "Invalid ID. Please enter a valid ID: ";
                                cin.clear();
                                while (cin.get() != '\n') {}
                            }

                            cout << "Your School fees is : 3000.";
                                                        cout << "Do You Want To Pay fee \n1.YES\n2.NO .";
                            int wanna_pay;
                            while (!(cin >> wanna_pay)) {
                                cout << "Invalid choice. Please enter a valid choice: ";
                                cin.clear();
                                while (cin.get() != '\n') {}
                            }

                            switch (wanna_pay) {
                                case 1:
                                    if (Account_Balance > 3000) {
                                        cout << "Fees Successfully Paid." << endl;
                                        Account_Balance = Account_Balance - 3000;
                                    } else {
                                        throw "Low Account Balance.";
                                    }
                                    break;
                                default:
                                    throw "Invalid choice.";
                            }
                            break;
                        }
                        case 4: {
                            cout << "Enter ID : ";
                            int School_ID;
                            while (!(cin >> School_ID)) {
                                cout << "Invalid ID. Please enter a valid ID: ";
                                cin.clear();
                                while (cin.get() != '\n') {}
                            }

                            cout << "Your School fees is : 2000.";
                            cout << "Do You Want To Pay fee \n1.YES\n2.NO .";
                            int wanna_pay;
                            while (!(cin >> wanna_pay)) {
                                cout << "Invalid choice. Please enter a valid choice: ";
                                cin.clear();
                                while (cin.get() != '\n') {}
                            }

                            switch (wanna_pay) {
                                case 1:
                                    if (Account_Balance > 2000) {
                                        cout << "Fees Successfully Paid." << endl;
                                        cout << "Press any key to continue.." << endl;
                                        Account_Balance = Account_Balance - 2000;
                                        getch();
                                    } else {
                                        throw "Low Account Balance.";
                                    }
                                    break;
                                default:
                                    throw "Invalid choice.";
                            }
                            break;
                        }
                        default:
                            throw "Invalid choice.";
                    }
                    break;
                }
                case 2: {
                    string address;
                    int Option_bills;
                    cout << "Enter Your Home Address: ";
                    cin.ignore();
                    getline(cin, address);
                    cout << "Your Electricity Bill is: Rs 12000." << endl;
                    cout << "Would you want To Pay Your Bill. \n1.Yes \n2.No.";
                    while (!(cin >> Option_bills)) {
                        cout << "Invalid choice. Please enter a valid choice: ";
                        cin.clear();
                        while (cin.get() != '\n') {}
                    }

                    system("cls");
                    switch (Option_bills) {
                        case 1: {
                            if (Account_Balance > 12000) {
                                cout << "Bill Successfully Paid of " << address << endl;
                                cout << "Press any Key to continue..." << endl;
                                Account_Balance = Account_Balance - 12000;
                            } else {
                                throw "Low Account Balance.";
                            }
                            break;
                        }
                        case 2: {
                            cout << "Press any Key to Return to the main Menu..." << endl;
                            break;
                        }
                        default:
                            throw "Invalid choice.";
                    }
                    getch();
                    break;
                }
                case 3: {
                    string Water_Address;
                    int pay_water_bill;
                    cout << "Enter Address: " << endl;
                    cin.ignore();
                    getline(cin, Water_Address);
                    cout << "Water Bill: Rs 500." << endl;
                    cout << "Would You Want to Pay the Bill? \n1.Yes \n2.No" << endl;
                    while (!(cin >> pay_water_bill)) {
                        cout << "Invalid choice. Please enter a valid choice: ";
                        cin.clear();
                        while                        (cin.get() != '\n') {}
                    }

                    system("cls");
                    switch (pay_water_bill) {
                        case 1: {
                            if (Account_Balance > 500) {
                                cout << "Bill Successfully Paid." << endl;
                                cout << "Press any Key to continue..." << endl;
                                Account_Balance = Account_Balance - 500;
                                getch();
                            } else {
                                throw "Low Account Balance.";
                            }
                            break;
                        }
                        case 2: {
                            cout << "Press any Key to Return to the main Menu..." << endl;
                            getch();
                            break;
                        }
                        default:
                            throw "Invalid choice.";
                    }
                    break;
                }
                case 4: {
                    string gas_Address;
                    int pay_gas_bill;
                    cout << "Enter Address: " << endl;
                    cin.ignore();
                    getline(cin, gas_Address);
                    cout << "GAS Bill: Rs 1300." << endl;
                    cout << "Would You Want to Pay the Bill? \n1.Yes \n2.No" << endl;
                    while (!(cin >> pay_gas_bill)) {
                        cout << "Invalid choice. Please enter a valid choice: ";
                        cin.clear();
                        while (cin.get() != '\n') {}
                    }

                    switch (pay_gas_bill) {
                        case 1: {
                            if (Account_Balance > 1300) {
                                cout << "Bill Successfully Paid." << endl;
                                cout << "Press any Key to continue..." << endl;
                                Account_Balance = Account_Balance - 1300;
                                getch();
                            } else {
                                throw "Low Account Balance.";
                            }
                            break;
                        }
                        default:
                            throw "Invalid choice.";
                    }
                    break;
                }
                default:
                    throw "Invalid choice.";
            }
        } catch (char* errorMessage) {
            cout << "Error: " << errorMessage << endl;
            cout << "Press any Key to continue..." << endl;
            getch();
        }
    }
};

/*class Bank_statement : public FAST_CASH , public CASH_WITHDRAL , public Funds_Transfer , public Payments  {
	public:
	void mini_statement()
{
    cout<<mini<<mini_cash1<<mini_cash2<<mini_cash3<<mini_cash4<<mini_cash5<<mini_cash6<<mini_cash7<<mini_cash8;
    /*if(flag==0){
    if(cash_withdraw>0)
    {
      cout<<"\n==>"<<cash_withdraw<<"Rs were with wihtdrawn\n";
    }
    }   if(flag==0){
    /*if(funds>0)
    {
        cout<<"\n==>"<<funds<<"Rs were transfered to account No. "<<account_number<<"\n";
    }
    }
    cout<<mini_city<<mini_allied<<mini_beacon<<mini_smart<<mini_electric<<mini_gas<<mini_water;
    cout<<"\nPress any key to continue";
    getch();
}
}
}
};*/





/*Int Main () work is done AT middle */
int main () {
    int check;
    int choice;
    Login Obj;
	Obj.Thank_you_Title();
    cout << "1. Login" << endl;
    cout << "2. Signup" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cin.ignore();
    if(choice == 1)
    {
        Obj.login_function();
    }
    else if(choice == 2)
    {
        Obj.signup();
    }
    else {
        cout<<"\nInvald Choice!\n";
    }
    do {
        system("cls");
        cout << "\n\n\t\t\tMain Menu" << endl;
        cout << "\n1. Fast Cash." << endl ;
        cout << "\n2. Cash WithDral." << endl ;
        cout << "\n3. Balance Inquiry." << endl;
        cout << "\n4. Bank Statment. "<< endl ;
        cout << "\n5. Funds Transfer. "<< endl;
        cout << "\n6. Payments. " << endl ;
        cout << "\n7. Pin Change. "<< endl;
        cout << "\n8. Log Out. "<< endl;
        cout << "---------->Enter which Service You Want from Us :" ;
        cout << "\nReminder Please Don't Enter any Negative Value. " << endl ;
        cin >> check ;
        switch(check) {
        case 1:
        {
            system("cls");
            FAST_CASH Obj_1;
            Obj_1.Fast_cash_Title();
            Obj_1.Fast_cash();
            break;
        }
        case 2:
        {
            system("cls");
            CASH_WITHDRAL Obj_2;
            Obj_2.Cash_Withdrwal_Title();
            Obj_2.Cash_withdraw();
            break;
        }
        case 3:
        {
            system("cls");
            Balance_Inquiry Obj_3;
            Obj_3.Balance_Inquiry_Title();
            Obj_3.B_Inquiry();
            break;
        }
        case 4:
        {
            system("cls");
//            Bank_statement OBJ_4;
//            OBJ_4.Mini_statement_Title();
//            OBJ_4.mini_statement();
			getch();
            cout << "Under Working ..." << endl ;
            break;
        }
        case 5:
        {
            Funds_Transfer Obj_5;
            Obj_5.Funds_transfer_Title();
            Obj_5.F_Transfer();
            break;
        }
        case 6:
        {
            system("cls");
            Payments Obj_6;
            Obj_6.Payment_Title();
            Obj_6.PAYMENTS();
            break;
        }
        case 7:
        {
            system("cls");
            PIN_change OBJ_7;
            OBJ_7.pin_change();
            break;
        }

        case 8:
        {
            system("cls");
            main ();
            break;
        }
        default:
        {
            cout << "Incorrect Input Please Try Again." << endl ;
            getch();
            break;
        }
        }
    } while (check > 0);
}
void Bank :: Main_Menu() {
    system("cls");
    cout<<("============================================\n");
    cout<<("                MAIN MENU OF ATM          \n");
    cout<<("============================================\n\n");
}
void Bank ::Fast_cash_Title() {
    system("cls");
    cout<<("============================================\n");
    cout<<("                FAST CASH          \n");
    cout<<("============================================\n\n");
}
void Bank :: Cash_Withdrwal_Title() {
    system("cls");
    cout<<("============================================\n");
    cout<<("            CASH WITHDRAWAL          \n");
    cout<<("============================================\n\n");
}
void Bank ::	Balance_Inquiry_Title() {
    system("cls");
    cout<<("============================================\n");
    cout<<("             BALANCE INQUIRY          \n");
    cout<<("============================================\n\n");
}
void Bank :: Mini_statement_Title() {
    system("cls");
    cout<<("============================================\n");
    cout<<("              MINI STATEMENT          \n");
    cout<<("============================================\n\n");
}
void Bank :: Funds_transfer_Title() {
    system("cls");
    cout<<("============================================\n");
    cout<<("           FUNDS TRANSFER          \n");
    cout<<("============================================\n\n");
}
void Bank :: Payment_Title() {
    system("cls");
    cout<<("============================================\n");
    cout<<("                PAYMENT          \n");
    cout<<("============================================\n\n");
}
void Bank :: sing_out_Title() {
    system("cls");
    cout<<("=======================================================================================================\n");
    cout<<("                                             LOGIN PAGE                                                \n");
    cout<<("=======================================================================================================\n");
}
void Login :: Thank_you_Title() {
    system("cls");
    cout<<("============================================\n");
    cout<<("              WELCOME TO ATM          \n");
    cout<<("============================================\n\n");
}

