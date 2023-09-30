#include <bits/stdc++.h>

using namespace std;

class ItemDetails {
protected:
    string name;
    int itemNumber;
    float price;

public:
    void getDetails() {
        cin.ignore();
        getline(cin, name);
        cin >> itemNumber >> price;
    }
};

class DiscountedItem : public ItemDetails {
protected:
    float discountPercent;
    double discountedPrice;

public:
    void calculateDiscount() {
        cin >> discountPercent;
        discountedPrice = price - (price * discountPercent / 100);
    }

    void displayBill() {
        cout << "Item name: " << name << endl;
        cout << "Item number: " << itemNumber << endl;
        cout << "Item price: " << fixed << setprecision(0) << price << endl;
        cout << "Discount percent: " << discountPercent << "%" << endl;
        cout << "Discounted price: ";
        if (discountedPrice == floor(discountedPrice)) {
    // Print the number as an int.
    cout << discountedPrice << endl;
  } else {
    // Print the number as a float.
    cout <<fixed<<setprecision(1)<<discountedPrice << endl;
  }
    }

    float getPrice() {
        return price;
    }

    float getDiscount() {
        return price - discountedPrice;
    }
};

int main() {
    int n;
    cin >> n;

    vector<DiscountedItem> items(n);

    for (int i = 0; i < n; i++) {
        items[i].getDetails();
        items[i].calculateDiscount();
    }

    cout << "Item-wise bill:" << endl;

    float totalPrice = 0, totalDiscount = 0;

    for (int i = 0; i < n; i++) {
        items[i].displayBill();
        totalPrice += items[i].getPrice();
        totalDiscount += items[i].getDiscount();
    }
    cout<<endl;
    cout << "Total price: " << totalPrice << endl;
    cout << "Total discount: " << fixed << setprecision(1) << totalDiscount << endl;

    return 0;
}

