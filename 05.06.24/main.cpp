#include <Windows.h>
#include <iostream>
#include <fstream>
#include <string>

struct Product 
{
    std::string name;
    int quantity;
    int price;
};

void writeToFile(const Product& product, const std::string& filename) 
{
    std::ofstream file(filename, std::ios::app); 
    if (file.is_open())
    {
        file << product.name << " " << product.quantity << " " << product.price << "\n";
        file.close();
    }
    else
    {
        std::cout << "Файл не открылся: " << filename << "\n";
    }
}

void readFromFile(const std::string& filename, Product products[], int& count)
{
    std::ifstream file(filename);
    if (file.is_open()) 
    {
        while (file >> products[count].name >> products[count].quantity >> products[count].price) 
        {
            count++;
        }
        file.close();
    }
    else 
    {
        std::cout << "Файл не открылся: " << filename << "\n";
    }
}

void displayProducts(const Product products[], int count) 
{
    std::cout << "Id\tНазвание\tКол-во\tЦена" << "\n";
    for (int i = 0; i < count; i++)
    {
        std::cout << i  << "\t" << products[i].name << "\t" << products[i].quantity << "\t" << products[i].price << "\n";
    }
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int MAX_PRODUCTS = 52;
    Product products[MAX_PRODUCTS];
    int productCount = 0;

    std::string filenames[] = { "product1.txt", "product2.txt", "product3.txt" };

    for (int i = 0; i < 3; i++)
    {
        Product newProduct;
        std::cout << "Название продукта: ";
        std::cin >> newProduct.name;
        std::cout << "Кол-во продукта: ";
        std::cin >> newProduct.quantity;
        std::cout << "Цена: ";
        std::cin >> newProduct.price;

        writeToFile(newProduct, filenames[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        productCount = 0;
        readFromFile(filenames[i], products, productCount);
        displayProducts(products, productCount);
    }

    return 0;
}



 

