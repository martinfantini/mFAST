#include "catch.hpp"
#include <mfast.h>

#include "fast_test_coding_case_v2.hpp"
#include "byte_stream.h"

#include "simple18.h"

using namespace test::coding;

TEST_CASE("set data type basic test with default value")
{
    fast_test_coding_case_v2<simple18::templates_description> test_case;
    simple18::Test_1 test_1;

    {
        simple18::Test_1_mref test_1_mref = test_1.mref();
        auto TradeCondition = test_1_mref.set_TradeCondition();
        TradeCondition.set_OpeningPrice();
        TradeCondition.set_OfficialClosingPrice();
    }

    {
        simple18::Test_1_cref test_1_cref = test_1.cref();
        auto TradeCondition = test_1_cref.get_TradeCondition();

        REQUIRE(TradeCondition.value() == (0x00 | simple18::TradeConditionSet::ExchangeLast | simple18::TradeConditionSet::OpeningPrice | simple18::TradeConditionSet::OfficialClosingPrice));

        REQUIRE(TradeCondition.has_ExchangeLast());
        REQUIRE(TradeCondition.has_OpeningPrice());
        REQUIRE(TradeCondition.has_OfficialClosingPrice());
        REQUIRE(!TradeCondition.has_Retail());
    }
}

TEST_CASE("set data type basic test")
{
    fast_test_coding_case_v2<simple18::templates_description> test_case;
    simple18::Test_3 test_3;

    {
        simple18::Test_3_mref test_3_mref = test_3.mref();
        auto TradeCondition = test_3_mref.set_TradeCondition();
        TradeCondition.set_OpeningPrice();
        TradeCondition.set_OfficialClosingPrice();
    }

    {
        simple18::Test_3_cref test_3_cref = test_3.cref();
        auto TradeCondition = test_3_cref.get_TradeCondition();

        REQUIRE(TradeCondition.value() == (0x00 | simple18::TradeConditionSet::OpeningPrice | simple18::TradeConditionSet::OfficialClosingPrice));

        REQUIRE(!TradeCondition.has_ExchangeLast());
        REQUIRE(TradeCondition.has_OpeningPrice());
        REQUIRE(TradeCondition.has_OfficialClosingPrice());
        REQUIRE(!TradeCondition.has_Retail());
    }
}
