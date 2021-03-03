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

  void GetBeverage(std::string& _return, BeverageType::type btype) override;
};

// Constructor
BeverageServiceHandler::BeverageServiceHandler() {

}

// Remote Procedure "PlaceOrder"

void BeverageServiceHandler::GetBeverage(std::string& _return, BeverageType::type btype) {
    printf("GetBeverage\n");
    
    std::string bev_cold [3] = {"cappuccino", "latte", "espresso"};
    std::string bev_hot [3] = {"lemonade", "ice tea", "soda"};

    if (btype == BeverageType::type::HOT)
    {
        _return = bev_cold[rand() % 3];
    }
    else
    {
        _return = bev_hot[rand() % 3];
    }
}

} // namespace vending_machine


#endif //VENDING_MACHINE_MICROSERVICES_BeverageHANDLER_H

