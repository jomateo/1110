/*
 Johanny Mateo
 CISC 1110
 Assignment 6B
 */

#include <iostream>
using namespace std;

//prototypes
void initialize(int&, int&, int&);
//add arrays to be received for functions
void placeOrder(int &, int &, int &, int [], bool [], double []);
void restock(int&, int&);
void totalPrice (int [], int &);
void maxItems (int [], int &);
int ordersBackordered (bool [], int [], int [], int &);
const int SIZE = 1000;

int main() {
    int quantityOnHand, orderNum, backOrdered,
        itemsArray[SIZE], countBOArray [SIZE], count;
    double priceArray[SIZE];
    bool inStockArray [SIZE];
    
    initialize(quantityOnHand, orderNum, backOrdered);
    
    placeOrder(orderNum, quantityOnHand, backOrdered, itemsArray, inStockArray, priceArray);
    
    cout << endl << orderNum << " orders processed.\n";
    
    totalPrice(itemsArray, orderNum);
    
    maxItems(itemsArray, orderNum);
    
    count = ordersBackordered(inStockArray, itemsArray, countBOArray, orderNum);
    
    cout << "There were " << count << " orders backordered. These is the amount ordered for each order that had a back order:\n";
    
    for (int i = 0; i < count; i++) {
        cout << countBOArray[i] << endl;
    }
    return 0;
}

//initialize variables
void initialize (int &quantityOnHand, int &orderNum, int &backOrdered) {
    quantityOnHand = 100, orderNum = 0,  backOrdered = 0;
    return;
}

//place orders
void placeOrder (int &orderNum, int &quantityOnHand, int &backOrdered, int itemsArray[], bool inStockArray[], double priceArray[]) {
    int items;
    
    cout << "How many items do you want to order? Enter 0 to stop ordering: ";
    cin >> items;
    
    while (items > 0) {
        
        itemsArray[orderNum] = items;
        
        //if more items are ordered than what is available
        if (items > quantityOnHand) {
            
            //the difference between how many items are available and how many are wanted is the backorder
            backOrdered = items - quantityOnHand;
            
            //cout << "Your total is: " << total << ". " << backOrdered << " items in back order.\n";
            cout << backOrdered << " items in backorder.\n";
            
            //keep track if quantity on hand is 0, or less than 0 (items that are waiting to be sold from backorder)
            quantityOnHand -= items;
            
            //there are items on backorder, replenish stock by 100
            restock(quantityOnHand, backOrdered);
            
            //there isnt enough items in stock for the whole order, set this to false in bool backorder
            inStockArray[orderNum] = false;
            
            
        }
        
        //the amount of items wanted is on hand
        else {
            
            //set backorder to 0, all items can be sold
            backOrdered = 0;
            
            //subtract items sold from inventory
            quantityOnHand -= items;
            
            //all the items are in stock, set bool array to true
            inStockArray[orderNum] = true;
        }
        
        orderNum++;     //orderNum/index counter
        
        cout << "\nHow many items do you want to order: ";
        cin >> items;
    }
    return;
}

void restock (int &quantityOnHand, int &backOrdered) {
    
    //add 100 items to the quantity
    quantityOnHand += 100;
    return;
}

void totalPrice (int itemsArray[], int &orderNum){
    double  total = 0,
            price = 19.95;
    for (int i = 0; i < orderNum; i++){
        total = total + (itemsArray[i]*price);
    }
    
    cout << "Your total price is: $" << total << endl;
    return;
}

void maxItems (int itemsArray[], int &orderNum){
    int max;
    max = itemsArray[0];
    
    for (int i = 1; i < orderNum; i++){
        if (itemsArray[i] > max){
            max = itemsArray[i];
        }
    }
    
    cout << "The maximum amount ordered is: " << max << endl;
    return;
}

int ordersBackordered (bool inStockArray[], int itemsArray[], int countBOArray[], int &orderNum) {
    int count = 0, j = 0;   //j is the index for the array with the backordered items count
    
    for (int i = 0; i < orderNum; i++){
        if (inStockArray[i] == false){
            countBOArray[j] = itemsArray[i];
            count++;
            j++;
        }
    }
    return count;
}