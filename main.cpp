#include <limits>
#include <iostream>
#include <vector>

void doSomething(unsigned int x)
{
  std::cout << "x is " << x << '\n';
}

int main()
{
  std::cout << "4.5 - Unsigned integers" << "\n";

  unsigned char uc;
  unsigned short us;
  unsigned int ui;
  unsigned long ul;
  unsigned long long ull;

  std::cout << "size unsigned char: " << sizeof(uc) << "\n";
  std::cout << "size unsigned short: " << sizeof(us) << "\n";
  std::cout << "size unsigned interger: " << sizeof(ui) << "\n";
  std::cout << "size unsigned long: " << sizeof(ul) << "\n";
  std::cout << "size unsigned long long: " << sizeof(ull) << "\n";

  std::cout << "Maximum value of unsigned short: " << std::numeric_limits<unsigned short>::max() << std::endl;

  // If an unsigned value is out of range,
  // it is divided by one greater than the largest number of the type, and only the remainder kept.
  us = 65536;
  std::cout << "check us: " << us << "\n";

  // if a mathematical operation has one signed integer and one unsigned integer,
  // the signed integer will usually be converted to an unsigned integer
  unsigned int u = 2;
  signed int s = 3;
  std::cout << u - s << '\n'; // 2 - 3 = 4294967295

  signed int ss = -1;
  unsigned int uu = 1;
  if (ss < uu) // -1 is implicitly converted to 4294967295, and 4294967295 < 1 is false
    std::cout << "-1 is less than 1\n";
  else
    std::cout << "1 is less than -1\n"; // this statement executes

  doSomething(-1);

  // BEST PRACTICE
  // Favor signed numbers over unsigned numbers for holding quantities (even quantities that should be non-negative)
  // and mathematical operations. Avoid mixing signed and unsigned numbers.

  // WHEN SHOULD YOU use unsigned numbers?
  // There are still a few cases in C++ where it’s okay / necessary to use unsigned numbers.
  // First, unsigned numbers are preferred when dealing with bit manipulation. They are also useful when well-defined wrap-around behavior is required (useful in some algorithms like encryption and random number generation).
  // Second, use of unsigned numbers is still unavoidable in some cases, mainly those having to do with array indexing.

  return 0;
}