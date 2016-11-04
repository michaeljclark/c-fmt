# c+fmt

C++14 sprintf like string formatter with append mode.
c+fmt is a header only library that use variadic templates
and bounded C++ std::string to implement an snprintf
and stringstream replacement.

- does not use varargs
- has a fixed stack frame
- implements SFINAE type boxing
- inline variadiac parameter packing
- accepts temporary references to std::string
- has a fixed stack frame and single ABI entry point
- appends to buffer to obviate the need for stringstream
- currently uses std::string for buffering

The follow types are handled:

- C strings       - printf style C string formatting
- std::string     - has a simpler argument format
- double (dtoa)   - printf style double formatting
- double (hdtoa)  - printf style double hex formatting
- integer (itoa)  - printf style integer formatting

This code has been tested on:

- Linux with GCC 6.1.1 and libstdc++
- Linux with Clang 3.6.2 and libstdc++ or libc++
- macOS with Apple LLVM version 8.0.0 and libstdc++ or libc++

## Benchmarks

Linux 4.6.3 on Intel(R) Core(TM) i7-5557U CPU @ 3.10GHz

method    | format    | time (ns)
:-------  | --------: | -------:
snprintf  |    (%20s) |   93.250
snprintf  |   (%7.5f) |  158.280
snprintf  | (%17.15f) |  240.950
c+fmt     |    (%20s) |   66.340
c+fmt     |   (%7.5f) |  424.850
c+fmt     | (%17.15f) |  615.570

Note: during porting, the bigint code was simplified to remove
a custom allocation cache, to keep the code simple and thread
safe. `c+bigint.h` and `c+dtoa.h` can be further optimized.

## Headers

Name       | Description
:---       | :---
c+bigint.h | C++ bigint (big integer) derived from netlib gdtoa
c+dtoa.h   | C++ dtoa (double to ASCII) derived from netlib gdtoa
c+hdtoa.h  | C++ hdtoa (double to Hex ASCII) derived from FreeBSD hdtoa
c+itoa.h   | C++ itoa (integer to ASCII) derived from FreeBSD ultoa
c+fmt.h    | C++ io_printf formatter derived from FreeBSD vfprintf
c+types.h  | C++ argument types and type holder used for type boxing
c+pack.h   | C++ variadia template type boxing sprintf interface

## Example

```
c++ -Wall -O3 -std=c++14 test-fmt.cc -o test-fmt
c++ -Wall -O3 -std=c++14 bench-fmt.cc -o bench-fmt
```

or

```
c++ -Wall -Os -std=c++14 -stdlib=libc++ -fno-rtti -fno-exceptions test-fmt.cc -o test-fmt
c++ -Wall -Os -std=c++14 -stdlib=libc++ -fno-rtti -fno-exceptions bench-fmt.cc -o bench-fmt
```
