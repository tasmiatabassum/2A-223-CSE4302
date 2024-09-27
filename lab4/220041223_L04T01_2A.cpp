#include <iostream>
#include <string>

using namespace std;

class Product{
    private:
        string name;
        string id;
        float price;
        int quantity;
        int max_quantity;
        
    public:
        Product(string n, string i, float p, int q, int max): name(n), id(i), price(p), quantity(q), max_quantity(max){}
        
        
        void addToInventory(int addedq){
            if(quantity+addedq<=max_quantity){
                quantity = quantity+addedq;
                cout<<"Inventory updated, Current quantity: "<<quantity<<endl;
            }
            else{
                cout<<"Maximum quantity reached"<<endl;
            }
        }
        
        bool isAvailable(){
            if(quantity>0) return true;
            else return false;
        }
        
        void purchase(int purchasedQuantity){
            if(isAvailable() && purchasedQuantity<= quantity){
                quantity = quantity - purchasedQuantity;
                cout<<"Item purchased, Current quantity: "<<quantity<<endl;
            }
            else{
                cout<<"Insufficient inventory for purchase"<<endl;
            }
        }
        
        void updatePrice(int discountPercent){
            float discountdec = float(discountPercent/100.00);
            //cout<<discountdec<<endl;
            float discount = float(price*discountdec);
            //cout<<discount<<endl;
            price = price - discount;
            cout<<"New price with discount is "<<price<<endl;
        }
        
        void displayInventoryValue(){
            float total= quantity*price;
            cout<<"Total inventory value is "<<total<<endl;
        }
        
        void displayDetails(){
            cout<<"Product name: "<<name<<endl;
            cout<<"Product ID: "<<id<<endl;
            cout<<"Product Price: "<<price<<endl;
            cout<<"Product Quantity: "<<quantity<<endl;
            if(isAvailable()) cout<<"Product In stock"<<endl;
            else cout<<"Product Out of stock"<<endl;
        }
        
        float getvalue(){
            return quantity*price;
        }
        
        void displayTotalInventoryValue(Product prod[], int size){
            float total = 0.0;
            for(int i=0; i<size;i++){
                total = total + prod[i].getvalue();
            }
            cout<<"Total inventory of all products is "<<total<<endl;
        }
};


int main() {
    Product p1("Lotion", "000", 1000.34, 23, 50);
    //p1.displayDetails();
    p1.addToInventory(10);
    p1.purchase(5);
    p1.updatePrice(10);
    p1.displayInventoryValue();
    p1.displayDetails();
    
   Product p2("Sunscreen", "001", 5000.45, 12, 15);
    //p2.displayDetails();
   p2.addToInventory(5);
    p2.purchase(1);
   p2.updatePrice(5);
    p2.displayInventoryValue();
    p2.displayDetails();
    
    Product p3("Toner", "002", 400.67, 16, 23);
    //p3.displayDetails();
   p3.addToInventory(4);
   p3.purchase(2);
   p3.updatePrice(6);
    p3.displayInventoryValue();
    p3.displayDetails();
    

    return 0;
}
