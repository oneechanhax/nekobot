
#include <regex>

#include "strings.hpp"

std::vector<std::string> sepstr(std::string input) {
  // Get our strings
  std::smatch reg_result;
  if (!std::regex_search(input, reg_result, std::regex("[\\w]+"))) // regex is really slow and adds alot to file size, but is really convienient for this purpose
    return std::vector<std::string>();

  std::vector<std::string> ret;
  for (const auto& i : reg_result)
    ret.push_back(i);

  return ret;
}
