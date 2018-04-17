
/*
 *
 * Include this in your module file
 *
 */

#include "../src/util/functional.hpp"

// TODO, currently, the status quo is to make a class using the type below, then add your functions and pass it to the module manager.
// We need a better way do do this, maybe init with the functions, or even better, have a dirived of the below and do some virtual func magic?

class CatModule {
  std::vector<CMFunction<bool()>> commands;
  CMEvent<void()> eventMessage;
};
