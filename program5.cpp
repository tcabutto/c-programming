 /* 
Program Name: Program5.cpp 
Programmer: Tyler Cabutto
Class: CS 3335 A 
HW: 05   
Problem: 01 
Date: 12/1/16
*/ 


#include <iostream>
using namespace std;
#include <cstring>

const int MAX_NAME = 20;
const int MAX_SALESMEN = 5;
const int NOT_FOUND = -1;

struct Seller
{
   float sales;               // running total of money he collected
   float time;                // running total of time, in hours
   char name[MAX_NAME + 1];   // name of the salesman
};

struct ListOfSalesmen
{
   int num;                  // number of salesmen in the list
   Seller salesman[MAX_SALESMEN];
};

void InitSeller ( Seller & s, const char name[] );
// Initializes the Salesman's name to name.  
// Initializes the Salesman's sales and time to 0.0.

void UpdateSales ( Seller & s, float sales, float time );
// Adds the money and time to the salesman's accumulated sales and time.

bool SellerHasName ( const Seller & s, const char name[] );
// Returns true if the salesman's name is the same as name; false otherwise.

float SalesValue ( Seller & s );
// Returns sales per hour for the salesman.
// Returns 0.0 if the salesman's time is 0.0.
// It also zeroes the salesman's sales & time when done calculating.

int Search(const ListOfSalesmen list, const char name[]);
//Deterimines whether or not a Salesman with specified name is in the ListOfSalesmen.
//If so, return index of where it is stored.


int main()
{
    char cmd, in[20];
    ListOfSalesmen list;
    list.num = 0;
    int pos = -1;
    float dollars, hrs = 0.0;
    
    
    cin >> cmd;
    if(cmd != 'Q')
        cin >> in;
    while(1)
    {
        switch(cmd)
        {
            case 'A' :
                //Add command
                pos = Search(list, in); 
                if(pos == -1)
                {
                    if(list.num != MAX_SALESMEN)
                    {
                        Seller s;
                        InitSeller(s, in);
                        list.salesman[list.num] = s;
                        cout << in << " is salesman " << list.num << endl;
                        list.num == list.num++;
                    }
                    else
                        cout << "List if full." << endl;
                }
                else
                    cout << "Salesperson already exists in list." << endl;
                break;
            case 'O' :
                //Output command
                pos = Search(list, in);
                
                if(pos != -1)
                {
                    cout << in << ": " << "$" << SalesValue(list.salesman[pos]) << " per hour" << endl;
                }
                else
                    cout << "Salesperson does not exist." << endl;
                break;
            case 'U' :
                //Update command
                cin >> dollars;
                cin >> hrs;
                pos = Search(list, in);
                if(pos != -1)
                {
                    
                    UpdateSales(list.salesman[pos], dollars, hrs);
                    cout << "Salesperson " <<  in << " Sold $" << dollars << " of toys in " << hrs << " Hours" << endl;
                }
                else
                    cout << "Cannot output. " << in << " is not in the list" << endl;
                break;
            case 'Q' :
                //Quit command
                cout << "Normal Termination of Sales Program." << endl;
                return 1;
            default :
                cout << "Invalid command." << endl;
        }
        cin >> cmd;
        if(cmd != 'Q')
        {
            cin >> in;
        }
    }
    
    return 1;
}

void InitSeller(Seller & s, const char name[])
{
    strcpy(s.name, name);
    s.time, s.sales = 0.0;
}

void UpdateSales(Seller & s, float sales, float time)
{
    s.time += time;
    s.sales += sales;
}

bool SellerHasName ( const Seller & s, const char name[] )
{
    if(strcmp(s.name, name) == 0)
    {
        return true;
    }
    else
        return false;
}


float SalesValue(Seller & s)
{
    float retval = 0.0;
    
    if(s.time == 0.0)
    {
        return retval;
    }
    
    retval = s.sales / s.time;
    
    s.sales = 0.0;
    s.time = 0.0;
    
    return retval;
}



int Search(const ListOfSalesmen list, const char name[])
{   

    int i, j = 0;
    int retval = -1;
    int length = list.num;
    for(i = 0; i < length; i++)
    {
        
        if(strcmp(name, list.salesman[i].name) == 0)
        {
            retval = i;
            return retval;
        }
    }
    return retval;
}