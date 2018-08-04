CXXFLAGS = -Wall -O3 -std=c++14
INCLUDES = -Isrc

SRC = src
LIB = lib
OBJ = obj
BIN = bin

FMT_SRCS = $(sort $(wildcard $(SRC)/*.cc))
FMT_OBJS = $(addprefix $(OBJ)/,$(patsubst $(SRC)/%.cc,%.o,$(FMT_SRCS)))
FMT_LIBS = $(LIB)/libcplusfmt.a
FMT_TESTS = $(BIN)/test-fmt $(BIN)/bench-fmt

all: $(FMT_LIBS) $(FMT_TESTS)

check:
	$(BIN)/test-fmt

clean:
	rm -fr $(OBJ) $(LIB) $(BIN)

CXX_CMD = @echo CXX $@ ; mkdir -p $(@D) ; $(CXX) $(CXXFLAGS) $(INCLUDES) -c $^ -o $@
AR_CMD = @echo AR $@ ; mkdir -p $(@D) ; $(AR) cr $@ $^
LD_CMD = @echo LD $@ ; mkdir -p $(@D) ; $(CXX) $^ $(LDFLAGS) -o $@

$(OBJ)/%.o: $(SRC)/%.cc
	$(CXX_CMD)

$(OBJ)/test/%.o: test/%.cc
	$(CXX_CMD)

$(LIB)/libcplusfmt.a: $(FMT_OBJS)
	$(AR_CMD)

$(BIN)/%: $(OBJ)/test/%.o $(LIB)/libcplusfmt.a
	$(LD_CMD)
