#include "CostcoMember.h"

CostcoMember::CostcoMember(std::string name, std::string number, Kind kind)
    : mName(name), mNumber(number), mKind(kind), mTripCount(0), mPurchaseTotal(0.0) {}

string CostcoMember::getName() const { return mName; }
string CostcoMember::getNumber() const { return mNumber; }
CostcoMember::Kind CostcoMember::getKind() const { return mKind; }

int CostcoMember::getTripCount() const { return mTripCount; }
void CostcoMember::incrementTripCount() { mTripCount++; }
void CostcoMember::clearTripCount() { mTripCount = 0; }

double CostcoMember::getPurchaseTotal() const { return mPurchaseTotal; }
void CostcoMember::incrementPurchaseTotal(double amount) { mPurchaseTotal += amount; }
void CostcoMember::decrementPurchaseTotal(double amount) { mPurchaseTotal -= amount; }
void CostcoMember::clearPurchaseTotal() { mPurchaseTotal = 0.0; }
