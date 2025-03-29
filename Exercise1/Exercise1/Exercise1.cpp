#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

void quadratic_formula(int a, int b, int c) {
    double discriminant = (b * b) - (4 * a * c);

    if (discriminant > 0) {
        
        double root1 = (-b + sqrt(discriminant)) / (2.0 * a);
        double root2 = (-b - sqrt(discriminant)) / (2.0 * a);
        cout << "Root 1: " << root1 << '\n';
        cout << "Root 2: " << root2 << '\n';
    }
    else if (discriminant == 0) {
        // One real double root
        double root = -b / (2.0 * a);
        cout << "Double root: " << root << '\n';
    }
    else {
        // Complex roots
        double realPart = -b / (2.0 * a);
        double imaginaryPart = sqrt(-discriminant) / (2.0 * a);
        cout << "Roots are complex and different:\n";
        cout << "Root 1: " << realPart << " + " << imaginaryPart << "i\n";
        cout << "Root 2: " << realPart << " - " << imaginaryPart << "i\n";
    }
}

int main() {
    int a, b, c;
    
    cout << "Enter coefficients a, b, and c separated by spaces: ";
    cin >> a >> b >> c;

    if (a == 0) {
        cout << "Error: 'a' cannot be zero in a quadratic equation.\n";
    } else {
        quadratic_formula(a, b, c);
    }

    return 0;
}
