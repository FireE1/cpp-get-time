#include <ctime>
#include <iostream>
#include <map>
#include <string>
// #pragma warning(disable : 4996) // To prevent conflicts

const std::map<std::string, int> arguments_table = {
    {"now", 1}, {"zero", 2}, {"from_now", 3}};

void PrintTime(const std::time_t &time) {
  std::cout << "time_t: " << time << "\n";
  std::cout << "ctime: " << ctime(&time) << std::endl;
}

void UsageMessage() {
  std::cout << "Usage: pass as argument one of (now, zero, from_now)"
            << std::endl;
}

void TimeNow_modif(const bool mod) {
  std::time_t t = std::time(nullptr);
  std::tm tm = *std::localtime(&t);

  if (mod) {
    int plus_hour = 0;
    int plus_minute = 0;
    int plus_days = 0;

    std::cout << "plus days: ";
    std::cin >> plus_days;
    std::cout << "plus hours: ";
    std::cin >> plus_hour;
    std::cout << "plus minutes: ";
    std::cin >> plus_minute;
    std::cout << "\n";

    tm.tm_mday += plus_days;
    tm.tm_hour += plus_hour;
    tm.tm_min += plus_minute;
  }

  std::time_t time = mktime(&tm);
  PrintTime(time);
}

void ZeroTime() {
  std::time_t time = 0;
  PrintTime(time);
}

int main(int argc, char *argv[]) {
  if (argc != 2 || !arguments_table.count(std::string(argv[1]))) {
    UsageMessage();
    return 1;
  }

  switch (arguments_table.at(std::string(argv[1]))) {
  case 1:
    TimeNow_modif(false);
    break;
  case 2:
    ZeroTime();
    break;
  case 3:
    TimeNow_modif(true);
    break;
  default:
    return 1;
  }

  return 0;
}
