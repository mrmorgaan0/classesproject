#ifndef COSTCOWAREHOUSE_H
#define COSTCOWAREHOUSE_H

#include "CostcoMember.h"
#include <string>

class CostcoWarehouse {
public:
    CostcoWarehouse(std::string location, int number);

    std::string getLocation() const;
    int getNumber() const;

    void shopForStuff(CostcoMember &member, double amount);
    void returnStuff(CostcoMember &member, double amount);
    double calculateReward(const CostcoMember &member) const;
    double issueReward(CostcoMember &member);

private:
    std::string mLocation;
    int mNumber;
};

#endif
