#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch.hpp>
#include <invoke_default.hpp>

int func_ret_5() { return 5; };

TEST_CASE("Main Test", "[invokedefault]") {
    REQUIRE(idef::invoke_or_noop<int>(nullptr, 10, 20) == 0);
    REQUIRE(idef::invoke_or_noop<int>([] {return 5;}) == 5);
    REQUIRE(idef::invoke_or_noop<int>(func_ret_5) == 5);

    REQUIRE(idef::invoke_or_noop<int>(idef::default_if_nullptr(nullptr, &func_ret_5)) == 5);
    REQUIRE(idef::invoke_or_noop<int>(idef::default_if_nullptr([] {return 3;}, &func_ret_5)) == 3);
}