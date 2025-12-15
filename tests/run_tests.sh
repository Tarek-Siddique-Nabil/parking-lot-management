#!/bin/bash
# Run all tests

CFLAGS="-std=c11 -Wall -Wextra -g -I../include"

echo "Building and running tests..."
echo ""

# Compile and run billing tests
echo "=== Running Billing Tests ==="
gcc $CFLAGS -o ../bin/test_billing test_billing.c ../src/billing.c && ../bin/test_billing || echo "Billing test failed"
echo ""

# Compile and run auth tests
echo "=== Running Auth Tests ==="
gcc $CFLAGS -o ../bin/test_auth test_auth.c ../src/auth.c && ../bin/test_auth || echo "Auth test failed"
echo ""

# Compile and run storage tests
echo "=== Running Storage Tests ==="
gcc $CFLAGS -o ../bin/test_storage test_storage.c ../src/storage.c && ../bin/test_storage || echo "Storage test failed"
echo ""

# Compile and run slots tests
echo "=== Running Slots Tests ==="
gcc $CFLAGS -o ../bin/test_slots test_slots.c ../src/slots.c && ../bin/test_slots || echo "Slots test failed"
echo ""

# Compile and run vehicle tests
echo "=== Running Vehicle Tests ==="
gcc $CFLAGS -o ../bin/test_vehicle test_vehicle.c ../src/vehicle.c && ../bin/test_vehicle || echo "Vehicle test failed"
echo ""

echo "All tests completed!"
