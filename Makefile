CXXFLAGS = -Wall -O3 -std=c++14

all: test-fmt bench-fmt

clean:
	rm -f test-fmt bench-fmt

test-fmt: test-fmt.cc

bench-fmt: bench-fmt.cc
