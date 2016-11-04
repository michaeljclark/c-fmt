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
c++ -std=c++14 test-fmt.cc -o test-fmt
```
