#ifndef COSTCOMEMBER_H
#define COSTCOMEMBER_H

#include <string>
using namespace std;

class CostcoMember {
public:
    enum Kind { BUSINESS, EXECUTIVE, GOLDSTAR };

    CostcoMember(string name, string number, Kind kind);
    
    string getName() const;
    string getNumber() const;
    Kind getKind() const;

    int getTripCount() const;
    void incrementTripCount();
    void clearTripCount();

    double getPurchaseTotal() const;
    void incrementPurchaseTotal(double amount);
    void decrementPurchaseTotal(double amount);
    void clearPurchaseTotal();

private:
    string mName;
    string mNumber;
    Kind mKind;
    int mTripCount;
    double mPurchaseTotal;
};

#endif
