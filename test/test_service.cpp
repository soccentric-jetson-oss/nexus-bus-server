#include <catch2/catch_test_macros.hpp>
#include <nexus_bus.grpc.pb.h>

TEST_CASE("ReadRequest validation", "[server]") {
    nexusbus::ReadRequest req;
    req.set_address(0x42);
    req.set_length(4);
    REQUIRE(req.address() == 0x42);
    REQUIRE(req.length() == 4);
}

TEST_CASE("WriteRequest validation", "[server]") {
    nexusbus::WriteRequest req;
    req.set_address(0x100);
    req.set_data("test");
    REQUIRE(req.address() == 0x100);
    REQUIRE(req.data() == "test");
}
