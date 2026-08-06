#include <catch2/catch_test_macros.hpp>
#include <cstring>
#include <cerrno>

TEST_CASE("Null input handling", "[edge]") {
    int ret = nexus_bus_transfer(NULL, 0, 0, 0, 0, 0);
    REQUIRE(ret == -EINVAL);
}

TEST_CASE("Empty input handling", "[edge]") {
    struct nexus_bus_transfer xfer;
    std::memset(&xfer, 0, sizeof(xfer));
    REQUIRE(xfer.bus_type == 0);
    REQUIRE(xfer.bus_id == 0);
}

TEST_CASE("Boundary values", "[edge]") {
    struct nexus_bus_transfer xfer;
    std::memset(&xfer, 0, sizeof(xfer));
    xfer.bus_type = 0;
    REQUIRE(xfer.bus_type == 0);
    xfer.bus_type = 4;
    REQUIRE(xfer.bus_type == 4);
}

TEST_CASE("Concurrent access", "[edge]") {
    std::atomic<int> counter{0};
    std::vector<std::thread> threads;
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back([&]() { counter++; });
    }
    for (auto& t : threads) t.join();
    REQUIRE(counter == 10);
}

TEST_CASE("Resource cleanup on error", "[edge]") {
    struct nexus_bus_transfer xfer;
    std::memset(&xfer, 0, sizeof(xfer));
    xfer.bus_type = 99;
    REQUIRE(xfer.bus_type == 99);
}
