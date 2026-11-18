# Makefile for BizLedger C Computational Engine
CC = gcc
CFLAGS = -Wall -Wextra -O3
TARGET_NATIVE = bizledger_core.exe
TARGET_WASM = bizledger_core.wasm

# Default build: native test runner
all: native

native: bizledger_core.c bizledger_core.h
	$(CC) $(CFLAGS) -DNATIVE_RUNNER bizledger_core.c -o $(TARGET_NATIVE)

# Build WebAssembly via Emscripten (if emcc is installed in your environment)
wasm: bizledger_core.c bizledger_core.h
	emcc -O3 -s WASM=1 -s STANDALONE_WASM \
	     -s EXPORTED_FUNCTIONS="['_convert_currency','_calculate_account_balance','_calculate_net_cash_flow','_calculate_capital_growth','_calculate_inflow_ratio']" \
	     bizledger_core.c -o $(TARGET_WASM)

clean:
	rm -f $(TARGET_NATIVE) $(TARGET_WASM)
