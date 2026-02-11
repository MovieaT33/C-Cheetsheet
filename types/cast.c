// Syntax:
// (type) expression

struct Car {
    int year;
    float price;
};

int main() {
    int a = 5;

    float b = a;            // Automatic
    float c = (float)a;     // Manual

    struct Car myCar = {2020, 25000.0f}; // Automatic
    struct Car anotherCar = (struct Car){2018, 20000.0f}; // Manual
}