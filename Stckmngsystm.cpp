#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Product {
public:
	string name;
	int stock;
	double price;


	Product(string n, int s, double p) : name(n), stock(s), price(p) {}
};

class StockManagementSystem {
private:
	vector<Product> products;

public:

	void addProduct(string name, int stock, double price) {
		products.push_back(Product(name, stock, price));
		cout << "Product added successfully!" << endl;
	}


	void displayProducts() {
		if (products.empty()) {
			cout << "No products available in the stock." << endl;
			return;
		}

		cout << "\nProduct List:" << endl;
		cout << "---------------------------------" << endl;
		cout << "Name\tStock\tPrice" << endl;
		cout << "---------------------------------" << endl;
		for (const auto& product : products) {
			cout << product.name << "\t" << product.stock << "\t" << product.price << endl;
		}
	}


	void updateStock(string name, int newStock) {
		for (auto& product : products) {
			if (product.name == name) {
				product.stock = newStock;
				cout << "Stock updated successfully!" << endl;
				return;
			}
		}
		cout << "Product not found!" << endl;
	}


	void deleteProduct(string name) {
		for (auto it = products.begin(); it != products.end(); ++it) {
			if (it->name == name) {
				products.erase(it);
				cout << "Product deleted successfully!" << endl;
				return;
			}
		}
		cout << "Product not found!" << endl;
	}


	void searchProduct(string name) {
		for (const auto& product : products) {
			if (product.name == name) {
				cout << "Product Found: " << product.name << ", Stock: " << product.stock << ", Price: " << product.price << endl;
				return;
			}
		}
		cout << "Product not found!" << endl;
	}
};

int main() {
	StockManagementSystem sms;
	int choice;

	while (true) {
		cout << "\nStock Management System" << endl;
		cout << "1. Add Product" << endl;
		cout << "2. Display Products" << endl;
		cout << "3. Update Stock" << endl;
		cout << "4. Delete Product" << endl;
		cout << "5. Search Product" << endl;
		cout << "6. Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		string name;
		int stock;
		double price;

		switch (choice) {
		case 1:
			cout << "Enter product name: ";
			cin.ignore();
			getline(cin, name);
			cout << "Enter stock quantity: ";
			cin >> stock;
			cout << "Enter product price: ";
			cin >> price;
			sms.addProduct(name, stock, price);
			break;

		case 2:
			sms.displayProducts();
			break;

		case 3:
			cout << "Enter product name to update stock: ";
			cin.ignore(); // Ignor
			getline(cin, name);
			cout << "Enter new stock quantity: ";
			cin >> stock;
			sms.updateStock(name, stock);
			break;

		case 4:
			cout << "Enter product name to delete: ";
			cin.ignore();
			getline(cin, name);
			sms.deleteProduct(name);
			break;

		case 5:
			cout << "Enter product name to search: ";
			cin.ignore();
			getline(cin, name);
			sms.searchProduct(name);
			break;

		case 6:
			cout << "Exiting the program." << endl;
			return 0;

		default:
			cout << "Invalid choice, please try again." << endl;
		}
	}

	return 0;
}
