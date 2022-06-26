#include "func.cpp"
#include <doctest.h>

TEST_CASE("Checking balance management.")
{
    DataPlayer dp;
    dp.bal = 40;
    REQUIRE(not dp.checkBal());
    dp.bal = 60;
    REQUIRE(dp.checkBal());
}

TEST_CASE("Checking level choosing.")
{
    DataPlayer dp;
    dp.bal = 40;
    dp.level = 1;
            REQUIRE(dp.checkLevel());
    dp.level = 2;
            REQUIRE(not dp.checkLevel());
    dp.level = 3;
            REQUIRE(not dp.checkLevel());
    dp.bal = 160;
    dp.level = 1;
            REQUIRE(dp.checkLevel());
    dp.level = 2;
            REQUIRE(dp.checkLevel());
    dp.level = 3;
            REQUIRE(not dp.checkLevel());
    dp.bal = 550;
    dp.level = 1;
            REQUIRE(dp.checkLevel());
    dp.level = 2;
            REQUIRE(dp.checkLevel());
    dp.level = 3;
            REQUIRE(dp.checkLevel());
}

TEST_CASE("Checking bet.")
{
    DataPlayer dp;
    dp.bal = 40;
    dp.bet = 60;
    REQUIRE(not dp.checkBet());
    dp.bal = 80;
    dp.bet = 60;
    REQUIRE(dp.checkBet());
}
