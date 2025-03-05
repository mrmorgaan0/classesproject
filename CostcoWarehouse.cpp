#include "CostcoWarehouse.h"
#include <iostream>
#include <string>

using namespace std;

CostcoWarehouse::CostcoWarehouse(string location, int number)
    : mLocation(location), mNumber(number) {}

string CostcoWarehouse::getLocation() const { return mLocation; }
int CostcoWarehouse::getNumber() const { return mNumber; }

void CostcoWarehouse::shopForStuff(CostcoMember &member, double amount) {
    member.incrementTripCount();
    member.incrementPurchaseTotal(amount);
}

void CostcoWarehouse::returnStuff(CostcoMember &member, double amount) {
    member.decrementPurchaseTotal(amount);
}

double CostcoWarehouse::calculateReward(const CostcoMember &member) const {
    if (member.getKind() == CostcoMember::EXECUTIVE) {
        return member.getPurchaseTotal() * 0.02;
    }
    return 0.0;
}

double CostcoWarehouse::issueReward(CostcoMember &member) {
    double reward = calculateReward(member);
    if (reward > 0) {
        member.clearPurchaseTotal();
    }
    return reward;
}
