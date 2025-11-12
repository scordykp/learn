#include <iostream>
#include <limits>
#include <vector>

void foo(unsigned int) {}

int main() {
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

  std::cout << "Maximum value of signed short: "
            << std::numeric_limits<signed short>::max() << std::endl;

  // Overflow in signed integers results in undefined behavior in C++,
  // meaning the program's behavior is not guaranteed by the standard and can
  // vary across compilers and platforms. This often leads to "wraparound" where
  // the value unexpectedly becomes negative
  ss = 32769;
  std::cout << "check ss: " << ss << "\n";

  // BEST PRACTICE
  // Favor signed numbers over unsigned numbers for holding quantities (even
  // quantities that should be non-negative) and mathematical operations. Avoid
  // mixing signed and unsigned numbers.

  // WHEN SHOULD YOU use unsigned numbers?
  // There are still a few cases in C++ where it’s okay / necessary to use
  // unsigned numbers. First, unsigned numbers are preferred when dealing with
  // bit manipulation. They are also useful when well-defined wrap-around
  // behavior is required (useful in some algorithms like encryption and random
  // number generation). Second, use of unsigned numbers is still unavoidable in
  // some cases, mainly those having to do with array indexing.

  // FOLLOWING require C++11 or later
  [[maybe_unused]]
  int x1 = 5;
  // narrowing conversion of ‘x1’ from ‘int’ to ‘unsigned int is ill-formed
  // unsigned int x2{x1}; // list initialization check conversion

  constexpr int y1{5}; // now constexpr
  // ok: y1 is constexpr and can be converted safely, not a narrowing conversion
  [[maybe_unused]] unsigned int y2{y1};

  std::cout << "Max value of std::size_t: "
            << std::numeric_limits<std::size_t>::max() << "\n";
  std::cout << "Max value of unsigned long: "
            << std::numeric_limits<unsigned long>::max() << "\n";
  std::cout << "Max value of long: " << std::numeric_limits<long>::max()
            << "\n";

  // T::size_type is almost always an alias for std::size_t
  std::vector<int> prime{2, 3, 5, 7, 11};
  // returns length as type `size_type` (alias for `std::size_t`)
  std::cout << "length: " << prime.size() << '\n';
  // std::cout << "length: " << std::size(prime); // C++17 can use std::size

  // C++20 introduces the std::ssize() non-member function, which returns the
  // length as a large signed integral type (usually std::ptrdiff_t, which is
  // the type normally used as the signed counterpart to std::size_t)
  // std::ptrdiff_t is from C++11

  // C++20, returns length as a large signed integral type
  std::cout << "length: " << std::ssize(prime) << '\n';
  // static_cast return value to int
  int length{static_cast<int>(std::ssize(prime))};
  // use auto to deduce signed type, as returned by std::ssize()
  // auto length{std::ssize(prime)};
  std::cout << "length: " << length << "\n";

  // Accessing array elements using operator[] does no bounds checking
  std::cout << prime[9] << "\n"; // invalid index (undefined behavior)
  // Accessing array elements using the at() member function does runtime bounds
  // checking
  // std::cout << prime.at(9) << "\n"; // invalid index (throws exception)

  // non-constexpr, possible warning narrowing converted to std::size_t
  // int index{3};
  // constexpr int index{3}; // constexpr, no warning
  std::size_t index{3}; // explicit
  std::cout << prime[index] << '\n';

  // Another way to access array elements is to use the data() member function
  int idx{3};
  std::cout << prime.data()[idx] << '\n';

  std::vector<int> arr{4, 6, 7, 3, 8, 2, 1, 9};

  // size_t index is unsigned, so index >= 0 is always true
  // for (std::size_t index{arr.size() - 1}; index >= 0; --index) {
  //   std::cout << arr[index] << ' ';
  // }
  // std::cout << '\n';

  // Fix by using static_cast to convert arr.size() to int
  int len{static_cast<int>(arr.size())};
  for (int index{len - 1}; index >= 0; --index) {
    std::cout << arr[static_cast<std::size_t>(index)] << ' ';
  }
  std::cout << '\n';

  // OR using
  for (std::vector<int>::size_type index{0}; index < arr.size(); ++index)
    std::cout << arr[index] << ' ';
  std::cout << '\n';

  // signed/unsigned conversion warnings are often disabled by default
  // Every time we subscript a standard library container using a signed index,
  // a sign conversion warning will be generated

  // MORE technique at
  // https://www.learncpp.com/cpp-tutorial/arrays-loops-and-sign-challenge-solutions/

  return 0;
}