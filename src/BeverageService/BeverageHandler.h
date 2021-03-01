#ifndef VENDING_MACHINE_MICROSERVICES_BEVERAGEHANDLER_H
#define VENDING_MACHINE_MICROSERVICES_BEVERAGEHANDLER_H

#include <iostream>
#include <string>
#include <regex>
#include <future>

#include "../../gen-cpp/BeverageService.h"

#include "../ClientPool.h"
#include "../ThriftClient.h"
#include "../logger.h"

namespace vending_machine{

class BeverageServiceHandler : public BeverageServiceIf {
 public:
  BeverageServiceHandler();
  ~BeverageServiceHandler() override=default;

  BeverageType::type GetBeverage(BeverageType::type btype) override;
};

// Constructor
BeverageServiceHandler::BeverageServiceHandler() {

}

// Remote Procedure "PlaceOrder"

BeverageType::type BeverageServiceHandler::GetBeverage(BeverageType::type btype) {
    printf("GetBeverage\n");
    
    if btype == BeverageType::type::HOT
        string bev [3] = {"cappuccino", "latte", "espresso"};
        return bev[rand() % 3];
    else
        string bev [3] = {"lemonade", "ice tea", "soda"};
        return bev[rand() % 3];
}

} // namespace vending_machine


#endif //VENDING_MACHINE_MICROSERVICES_BeverageHANDLER_H

