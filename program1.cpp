#include <iostream>
#include <string>

using namespace std;

ostream& rub(ostream& os) {
    os << " руб.";
    return os;
}

class Shop {
private:
    string name;
    double price;
    string manufacturer;

public:
    void setData(string n, double p, string m) {
        name = n;
        price = p;
        manufacturer = m;
    }

    double getPrice() {
        return price;
    }

    void display() {
        cout << "Товар: " << name << " | Цена: " << price << rub
            << " | Производитель: " << manufacturer << endl;
    }
};

int main() {
    Shop items[3];
    items[0].setData("Смартфон", 55000, "Samsung");
    items[1].setData("Ноутбук", 85000, "Asus");
    items[2].setData("Наушники", 15000, "Sony");

    double limit;
    cout << "Введите минимальную цену: ";
    cin >> limit;

    cout << "\nТовары дороже " << limit << rub << ":" << endl;
    for (int i = 0; i < 3; i++) {
        if (items[i].getPrice() > limit) {
            items[i].display();
        }
    }

    return 0;
}