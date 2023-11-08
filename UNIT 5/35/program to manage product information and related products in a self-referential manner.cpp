#include <iostream>
#include <vector>
#include <unordered_map>
class current{

};

struct Product {
    std::string name;
    float price;
    std::vector<Product*> relatedProducts;
};

void addRelatedProduct(Product* product) {
    char choice;
    // std::cout << "Add related products for " << product->name << "? (y/n): ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore remaining characters in input buffer
    
    while (choice == 'y' && product->relatedProducts.size() < 10) {
        std::string name;
        float price;
        
        // std::cout << "Enter related product name: ";
        std::getline(std::cin, name);
        
        // std::cout << "Enter related product price: ";
        std::cin >> price;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        Product* relatedProduct = new Product{name, price};
        product->relatedProducts.push_back(relatedProduct);
        
        // std::cout << "Add another related product for " << product->name << "? (y/n): ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

void displayFrequentlyBoughtTogether(Product* product) {
    std::cout << "Products frequently bought together with " << product->name << ":\n";
    
    for (Product* relatedProduct : product->relatedProducts) {
        std::cout << "- " << relatedProduct->name << "\n";
    }
    
    std::cout << "\n";
}

int main() {
    int numProducts;
    // std::cout << "Enter the total number of products: ";
    std::cin >> numProducts;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::vector<Product*> products;
    
    for (int i = 0; i < numProducts; i++) {
        std::string name;
        float price;
        
        // std::cout << "Enter product name: ";
        std::getline(std::cin, name);
        
        // std::cout << "Enter product price: ";
        std::cin >> price;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        Product* product = new Product{name, price};
        products.push_back(product);
        
        addRelatedProduct(product);
    }
    
    for (Product* product : products) {
        displayFrequentlyBoughtTogether(product);
    }
    
    // Deallocate memory for products and related products
    for (Product* product : products) {
        for (Product* relatedProduct : product->relatedProducts) {
            delete relatedProduct;
        }
        delete product;
    }
    
    return 0;
}
