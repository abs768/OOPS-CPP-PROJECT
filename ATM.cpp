                                                      /* MINI PROJECT : ATM */

/*PROBLEM STATEMENT:

Write a C++ program showing ATM Functionalities using oops.

FORMAT:
        1). Check Balance.
        2). Cash WithDraw.
        3). UserDetails.
        4). Update MobileNo.

*/


#include<conio.h>
#include<iostream>
#include<string>
using namespace std;

/*

Mini Project - ATM
    -> Check Balance
    -> Cash Withdraw
    -> User Details
    ->Update Mobile No.

*/
class atm                                                //class atm
{        
    private:                                            //private member variables.
    long int account_No;
    string name;
    int PIN;
    double balance;
    string mobile_no;

    public:                                            // public member functions.

    //setData() function is used here to access the Data Members from private section.

    void setData(long int account_No_a,string name_a,int PIN_a,double balance_a,string mobile_no_a)
    {
        account_No=account_No_a;                      // assigning the formal arguments to the private members.
        name=name_a;
        PIN=PIN_a;
        balance=balance_a;
        mobile_no=mobile_no_a;
    }
    
    //getAccountNo() function is returning the user's account no.

    long int getAccountNo(){
        return account_No;
    }

    //getName() function is returning the user's Name.

    string getName(){
        return name;
    }

    //getPIN() function is returning the user's PIN.
    int getPIN(){
        return PIN;
    }

    //getBalance() function is returning the user's Bank Balance.

    double getBalance(){
        return balance;
    }

    //getMobileNo() function is returning the user's Mobile No.
    string getMobileNo(){
        return mobile_no;
    }

    //setMobile() function is updating the user mobile no

    void setMobile(string mob_prev,string mob_new)
    {
        if(mob_prev==mobile_no)                                // It will check Old Mobile No.
        {                          
        mobile_no==mob_new;                                   // and Update with New, If Old.                   
        cout<<endl<<"Sucessfully Updated Mobile No . ";
        _getch();                                            // getch() is to hold the screen(untill user press any key)
        }
        else                                                 // Does not update if Old Mobile No does not matches with the current Mobile No.
        {
        cout<<endl<<"Incorrect!!! Old Mobile No .";       
        _getch();                                            // getch() is to hold the screen(untill user presses any key)
        }
    }
    
    //CashWithDraw() function is used to withdraw money from ATM.

    void CashWithDraw(int amount_a)
    {
        if(amount_a>0 && amount_a<balance)                  // check entered amount validity.
        {
        balance-=amount_a;                                  // balance= balance-amount_a.
        cout<<endl<<"Please Collect your Cash";
        cout<<endl<<"Available Balance is : "<<balance;
        _getch();                                           // getch() is to hold the screen(untill user presses any key)
        }
        else
        {
        cout<<"Inavlid Input Or Insufficient Balance ";
        _getch();                                           // getch() is to hold the screen(untill user presses any key)
        }
    }

};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    int choice=0,enterPIN;                                 // enterPIN and enterAccountNo.---> user authentication
    long int enterAccountNo;

    system("cls");

    // created User (object)

    atm user1;                                            // object instantiation.

    // Set User Details (into object)xxxxxxxxxxxxxxxxxx(Setting Default Data)

    user1.setData(1234567,"Michael",1331,350000.90,"9920948812");
    do
    {
        system("cls");
        cout<<endl<<"**** Welcome To ATM ****"<<endl;
        cout<<endl<<"Enter Your Account No : ";          // Asking User to enter account no.
        cin>>enterAccountNo;
        cout<<endl<<"Enter Your PIN : ";                 // Asking User to enter PIN no.
        cin>>enterPIN;

        // check whether entered values matches with the User's details

        if((enterAccountNo==user1.getAccountNo() && (enterPIN==user1.getPIN())))
        {
            do
            {
                int amount=0;
                string old_Mobile_No, new_Mobile_No;
                system("cls");

                // user Interface

                cout<<endl<<"**** Welcome To ATM ****"<<endl;
                cout<<endl<<"Select Options";
                cout<<endl<<"1.Check Balance";
                cout<<endl<<"2.Cash Withdraw";
                cout<<endl<<"3.Show User Details";
                cout<<endl<<"4.Update Mobile.No";
                cout<<endl<<"5.Exit"<<endl;
                cin>>choice;                                 // Taking User's choice.

                switch(choice)                               // Switch Case Condition.
                {
                    case 1:                                  // If User presses 1
                            cout<<endl<<"Your Bank Balance is : "<<user1.getBalance();
                                                            // getBalance() is ... printing the users bank balance
                                                        
                            _getch();
                            break;

                    case 2:                                   // If User presses 2
                            cout<<endl<<"Enter the amount : ";
                            cin>>amount;
                            user1.CashWithDraw(amount);       // Calling CashWithDraw().
                                                              // Passing the Withdrawn Amount.
                            break;
                    
                    case 3:                                   // If User presses 3
                            cout<<endl<<"*** User Details are :- ";
                            cout<<endl<<"->Account No "<<user1.getAccountNo();
                            cout<<endl<<"->Name "<<user1.getName();
                            cout<<endl<<"->Balance "<<user1.getBalance();
                            cout<<endl<<"-> Mobile No "<<user1.getMobileNo();
                                                              // getting and printing User Details.
                            _getch();
                            break;

                    case 4:                                    // If User presses 4
                            cout<<endl<<"Enter Old Mobile No : ";
                            cin>>old_Mobile_No;                     // Input Old Mobile No.
                            cout<<endl<<"Enter New Mobile No : ";      
                            cin>>new_Mobile_No;                     // Input New Mobile No.
                            user1.setMobile(old_Mobile_No,new_Mobile_No);
                            break;

                    case 5:                                   // If User presses 5
                            exit(0);                          // exit application.
                        
                    default :                                 // handle invalid User Inputs.
                                cout<<endl<<"Enter Valid Data !!! ";
                }
            }while(1);                                          // MENU     //condition will always be TRUE and loop is capable of running infinite times.
        }
        else
        {
            cout<<endl<<"User Details are Invalid !!!";
            _getch();
        }
    }while(1);                                                  // LOGIN     //condition will always be TRUE and loop is capable of running infinite times.
    
    return 0;
}