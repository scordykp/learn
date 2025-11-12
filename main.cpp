#include <limits>
#include <iostream>
#include <vector>

int main()
{
  std::cout << "Signed integers" << "\n";

  signed char sc;
  signed short ss;
  signed int si;
  signed long sl;
  signed long long sll;

  std::cout << "size signed char: " << sizeof(sc) << "\n";
  std::cout << "size signed short: " << sizeof(ss) << "\n";
  std::cout << "size signed interger: " << sizeof(si) << "\n";
  std::cout << "size signed long: " << sizeof(sl) << "\n";
  std::cout << "size signed long long: " << sizeof(sll) << "\n";

  std::cout << "Maximum value of signed short: " << std::numeric_limits<signed short>::max() << std::endl;

  // Overflow in signed integers results in undefined behavior in C++,
  // meaning the program's behavior is not guaranteed by the standard and can vary across compilers and platforms.
  // This often leads to "wraparound" where the value unexpectedly becomes negative
  ss = 32769;
  std::cout << "check ss: " << ss << "\n";

  // BEST PRACTICE
  // Favor signed numbers over unsigned numbers for holding quantities (even quantities that should be non-negative)
  // and mathematical operations. Avoid mixing signed and unsigned numbers.

  // WHEN SHOULD YOU use unsigned numbers?
  // There are still a few cases in C++ where it’s okay / necessary to use unsigned numbers.
  // First, unsigned numbers are preferred when dealing with bit manipulation. They are also useful when well-defined wrap-around behavior is required (useful in some algorithms like encryption and random number generation).
  // Second, use of unsigned numbers is still unavoidable in some cases, mainly those having to do with array indexing.

  return 0;
}