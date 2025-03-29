#include <iostream>
#include <unordered_map>

using std::cout;
using std::cin;
using std::endl;
using std::unordered_map;
using std::string;

// Function to get a valid currency choice
char get_currency_choice(const string& prompt) {
    unordered_map<char, string> currency_map = {
        {'E', "Euro"}, {'D', "US Dollar"}, {'Y', "Yen"},
        {'L', "Albanian Lek"}, {'V', "Vietnamese Dong"}
    };

    char choice;
    do {
        cout << "\n" << prompt << "\n";
        for (const auto& pair : currency_map) {
            cout << "Press " << pair.first << " for " << pair.second << '\n';
        }
        cout << "Your choice: ";
        cin >> choice;
        choice = toupper(choice);

        if (currency_map.find(choice) == currency_map.end()) {
            cout << "Invalid choice! Please try again.\n";
        }
    } while (currency_map.find(choice) == currency_map.end());

    cout << "You chose " << currency_map[choice] << ".\n";
    return choice;
}

// Function to get a valid amount
double get_conversion_amount() {
    double amount;
    do {
        cout << "\nEnter the amount to convert: ";
        cin >> amount;

        if (amount < 0) {
            cout << "Invalid amount! Please enter a positive value.\n";
        }
    } while (amount < 0);
    
    return amount;
}

// Function to perform currency conversion
double convert_currency(char from, char to, double amount) {
    // Exchange rates (Rates can be outdated)
    unordered_map<char, unordered_map<char, double>> exchange_rates = {
        {'E', {{'D', 1.08}, {'Y', 157.5}, {'L', 107.8}, {'V', 26350.0}}},  // Euro to others
        {'D', {{'E', 0.93}, {'Y', 146.0}, {'L', 100.0}, {'V', 24400.0}}},  // Dollar to others
        {'Y', {{'E', 0.0063}, {'D', 0.0068}, {'L', 0.68}, {'V', 167.2}}},  // Yen to others
        {'L', {{'E', 0.0093}, {'D', 0.01}, {'Y', 1.47}, {'V', 244.0}}},   // Lek to others
        {'V', {{'E', 0.000038}, {'D', 0.000041}, {'Y', 0.0060}, {'L', 0.0041}}} // Dong to others
    };

    // If converting to the same currency, return the same amount
    if (from == to) return amount;

    // Perform conversion using the exchange rate
    return amount * exchange_rates[from][to];
}


//---------------------------------- MAIN -------------------------------------------------------

int main() {
    // Get source currency
    char from_currency = get_currency_choice("Pick the currency you are converting from:");
    
    // Get target currency
    char to_currency;
    do {
        to_currency = get_currency_choice("Pick the currency you are converting to:");
        if (from_currency == to_currency) {
            cout << "You picked the same currency! Choose a different one.\n";
        }
    } while (from_currency == to_currency);

    // Get amount to convert
    double amount = get_conversion_amount();

    // Convert currency
    double converted_amount = convert_currency(from_currency, to_currency, amount);

    // Display result
    cout << "\nConverted Amount: " << converted_amount << " in the selected currency.\n";

    return 0;
}
