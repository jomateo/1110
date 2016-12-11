/*
 Johanny Mateo
 CISC 1110
 Assignment 6A
 */

#include <iostream>
using namespace std;

//prototypes
void initialize(int&, int&, int&);
void placeOrder(int &, int &, int &);
void restock(int&, int&);


int main()
{
    int quantityOnHand, orderNum, backOrdered;
    
    initialize(quantityOnHand, orderNum, backOrdered);
    placeOrder(orderNum, quantityOnHand, backOrdered);
    
    cout << orderNum << " orders processed.\n";
    
    return 0;
}

//initialize variables
void initialize (int &quantityOnHand, int &orderNum, int &backOrdered)
{
    quantityOnHand = 100, orderNum = 0,  backOrdered = 0;
    return;
}

//place orders
void placeOrder (int &orderNum, int &quantityOnHand, int &backOrdered)
{
    int items;
    double total, price = 19.95;
    
    
    cout << "How many items do you want to order? Enter 0 to stop ordering: ";
    cin >> items;
    
    while (items > 0)
    {
        
        orderNum++;     //orderNum processed counter
                        //cout << "-- ORDER NUM: " << orderNum << endl;
        
        //if more items are ordered than what is available
        if (items > quantityOnHand)
        {
            /*cout  << "-- SHORTAGE BEGIN STOCK: " << quantityOnHand
                    << " back order: " << backOrdered << " --\n";*/
            
            //there is some inventory, total is price * inventory
            if (quantityOnHand > 0)
                total = price * quantityOnHand;
            
            //there is no inventory, total is 0
            else
                total = 0;
            
            //the difference between how many items are available and
            //how many are wanted is the backorder
            backOrdered = items - quantityOnHand;
            
            cout    << "Your total is: " << total << ". " << backOrdered
                    << " items in back order.\n";
            
            //keep track if quantity on hand is 0, or less than 0
            //(items that are waiting to be sold from backorder)
            quantityOnHand -= items;
            
            /*cout  << "-- SHORTAGE B4 RESTOCK: " << quantityOnHand
                    << " back order: " << backOrdered << " --\n";*/
            
            //there are items on backorder, replenish stock by 100
            restock(quantityOnHand, backOrdered);
            
            
        }
        
        //the amount of items wanted is on hand
        else
        {
            /*cout  << "-- NO SHORT STOCK BEGIN: " << quantityOnHand
                    << " back order: " << backOrdered << " --\n";*/
            
            //set backorder to 0, all items can be sold
            backOrdered = 0;
            
            total = items * price;
            cout << items << " items ordered. Your total is: " << total << endl;
            
            //subtract items sold from inventory
            quantityOnHand -= items;
            
            /*cout  << "-- NO SHORT STOCK END: " << quantityOnHand
                    << " back order: " << backOrdered << " --\n";*/
        }
        
        /*cout  << "-- END stock: " << quantityOnHand << " back order: "
                << backOrdered << " --\n";*/
        
        cout    << "\nHow many items do you want to order: ";
        cin     >> items;
    }
    return;
}

void restock (int &quantityOnHand, int &backOrdered)
{
    
    //add 100 items to the quantity
    quantityOnHand += 100;
    
    /*cout  << "-- RESTOCK AFTER 100: " << quantityOnHand << " back order: "
            << backOrdered << " --\n";*/
    return;
}
