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
#include <chrono>

#include "c+types.h"
#include "c+bigint.h"
#include "c+itoa.h"
#include "c+dtoa.h"
#include "c+hdtoa.h"
#include "c+fmt.h"
#include "c+args.h"

using namespace cplus;

int main()
{
	const int ITERS = 100000;

	{
		std::chrono::time_point<std::chrono::system_clock> s1 = std::chrono::system_clock::now();
		for (size_t i = 0; i < ITERS; i ++) {
			char buf[128];
			snprintf(buf, sizeof(buf), "%-20s %17.15f\n", "Double 17.15f", 3.141592653589793);
		}
		std::chrono::time_point<std::chrono::system_clock> s2 = std::chrono::system_clock::now();
		double test_1_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(s2-s1).count() / (double)ITERS;
		printf("snprintf : %lf nanoseconds\n", test_1_ns);
	}

	{
		std::chrono::time_point<std::chrono::system_clock> s1 = std::chrono::system_clock::now();
		for (size_t i = 0; i < ITERS; i ++) {
			std::string buf;
			sprintf(buf, "%-20s %17.15f\n", "Double 17.15f", 3.141592653589793);
		}
		std::chrono::time_point<std::chrono::system_clock> s2 = std::chrono::system_clock::now();
		double test_1_ns = std::chrono::duration_cast<std::chrono::nanoseconds>(s2-s1).count() / (double)ITERS;
		printf("c+fmt    : %lf nanoseconds\n", test_1_ns);
	}

	return 0;
}
