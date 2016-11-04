//
//  test-fmt.cc
//

#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <cctype>
#include <cwchar>
#include <climits>
#include <cfloat>
#include <cfenv>
#include <limits>
#include <array>
#include <string>
#include <vector>
#include <type_traits>

#include "c+types.h"
#include "c+bigint.h"
#include "c+itoa.h"
#include "c+dtoa.h"
#include "c+hdtoa.h"
#include "c+fmt.h"
#include "c+pack.h"

using namespace cplus;

#define test_printf(fmt, x...) \
	buf.clear(); \
	printf(fmt, x); \
	sprintf(buf, fmt, x); \
	printf("%s", buf.c_str());

int main()
{
	std::string buf;

	// sprintf test
	test_printf("%s world %p\n", "Hello", (void*)-1);
	test_printf("%-20s %d %u %f\n", "No pad", 123, 0U, 1.1f);
	test_printf("%-20s %8d %u %9f\n", "Right pad", 123, 0U, 1.1f);
	test_printf("%-20s %-8d %u %9f\n", "Left pad", 123, 0U, 1.1f);
	test_printf("%-20s %08d %u %17f\n", "Zero pad", 123, 0U, 1.1f);
	test_printf("%-20s %a\n", "Hex Float", 3.141592653589793);
	test_printf("%-20s %17f\n", "Double 17f", 3.141592653589793);
	test_printf("%-20s %17.15f\n", "Double 17.15f", 3.141592653589793);

	// sprintf append test
	buf.clear();
	std::string b("B");
	sprintf(buf, "%s", std::string("a"));
	sprintf(buf, "%s", b);
	sprintf(buf, "%c", 'c');
	sprintf(buf, "%s", std::to_string(123));
	printf("%s\n", buf.c_str());
	printf("aBc123\n");

	return 0;
}
