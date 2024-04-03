#include <iostream>
#include <cstring>
class Currency {
private:
    std::string nume; // Currency code (e.g., EUR, USD)
    double cursvalutar; // Exchange rate against RON
public:
    Currency(std::string nume, double cursvalutar){
        this->nume = nume;
        this->cursvalutar = cursvalutar;
    }
    // Function to convert from RON to this currency
    double conversie(double lei) const {
        return lei / cursvalutar;
    }
    // Function to convert from this currency to RON
    double conversieInvers(double bani) const {
        return bani * cursvalutar;
    }
    // Getter for currency code
    std::string getnume() const {
        return nume;
    }
};

class Baniclient {
private:
    double suma; // Amount in RON
    Currency currency; // Currency object
public:
    Baniclient(double suma, const Currency& currency) : suma(suma), currency(currency) {}

    // Function to convert the money to another currency
    double tranzactie(const Currency& moneda) const {
        return moneda.conversie(suma);
    }

    // Function to convert the money from another currency to RON
    double tranzactieInvers(const Currency& moneda) const {
        return moneda.conversieInvers(suma);
    }

    // Getter for amount in RON
    double getbani() const {
        return suma;
    }

    // Getter for currency code
    std::string getNumeMoneda() const {
        return currency.getnume();
    }
};

int main() {
    Currency euro("eur", 5);
    Currency usd("usd", 4.5);

    // Input validation for the amount in RON
    double lei;
    char moneda[10];
    std::cout << "Nr bani:";
    std::cin >> lei;
    std::cout << "Moneda:";
    std::cin >> moneda;
    Baniclient client(lei, euro); // Client's money in RO
     if(strcmp("RON",moneda)==0){
        // Convert the client's money to Euro
        double euro1 = client.tranzactie(euro);
        std::cout << lei << " RON = " << euro1 << " " << euro.getnume() << '\n';
        // Convert the client's money to USD
        double usd1 = client.tranzactie(usd);
        std::cout << lei << " RON = " << usd1 << " " << usd.getnume() << '\n';
     }
     else
     {
        // Convert the client's money from Euro back to RON
        double lei1 = client.tranzactieInvers(euro);
        std::cout << lei1 << '\n';
     }
    return 0;
}