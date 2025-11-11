#include <iostream>
#include <vector>

int main()
{
  std::cout << "4.5 - Unsigned integers" << "\n";

  unsigned short us;
  unsigned int ui;
  unsigned long ul;
  unsigned long long ull;

  std::cout << "size unsigned short: " << sizeof(us) << "\n";
  std::cout << "size unsigned interger: " << sizeof(ui) << "\n";
  std::cout << "size unsigned long: " << sizeof(ul) << "\n";
  std::cout << "size unsigned long long: " << sizeof(ull) << "\n";

  return 0;
}