#include "CostcoMember.h"
#include "CostcoWarehouse.h"
#include <iostream>
#include <cassert>

using namespace std;

int main() {
    
// create members

    CostcoMember pikachu("Pikachu", "025", CostcoMember::GOLDSTAR);
    CostcoMember charizard("Charizard", "006", CostcoMember::EXECUTIVE);
    CostcoMember meowth("Meowth", "052", CostcoMember::BUSINESS);
    
    // create a warehouse name

    CostcoWarehouse pokeMart("Pallet Town", 1998);

    // test the details of a member
    assert(pikachu.getName() == "Pikachu");
    assert(pikachu.getNumber() == "025");
    assert(pikachu.getKind() == CostcoMember::GOLDSTAR);

    // test the initial values of the trips
    assert(pikachu.getTripCount() == 0);
    assert(pikachu.getPurchaseTotal() == 0.0);

    // testing if the increment trip function works
    pikachu.incrementTripCount();
    assert(pikachu.getTripCount() == 1);

    // clearing trips
    pikachu.clearTripCount();
    assert(pikachu.getTripCount() == 0);

    // increments purchases and trips
    pokeMart.shopForStuff(charizard, 500.0); // executive member
    assert(charizard.getTripCount() == 1);
    assert(charizard.getPurchaseTotal() == 500.0);

    // decrements due to returns
    pokeMart.returnStuff(charizard, 200.0);
    assert(charizard.getPurchaseTotal() == 300.0);

    // calculates rewards for executives
    assert(pokeMart.calculateReward(charizard) == 6.0); // 2% of the purchase

    // issuing the reward
    double reward = pokeMart.issueReward(charizard);
    assert(reward == 6.0);
    assert(charizard.getPurchaseTotal() == 0.0);

    // tests if rewards are given to non executives (they shouldn't be)
    pokeMart.shopForStuff(pikachu, 100.0);
    assert(pokeMart.calculateReward(pikachu) == 0.0);
    assert(pokeMart.issueReward(pikachu) == 0.0);
    assert(pikachu.getPurchaseTotal() == 100.0); // no reset since no reward

    cerr << "cases tests passed successfully lfg" << endl;

    return 0;
}
