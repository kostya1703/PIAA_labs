#include <gtest/gtest.h>
#include "../hdr/func.h"



TEST(PreKMP_Test, all_symbols_dif)
{
	auto result = preKMP("abcdefghijklmnopqrstuvwxyz");
	vector<int> correct = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	EXPECT_EQ(result, correct);
}
TEST(PreKMP_Test, one_symbol_str)
{
	auto result = preKMP("kkkkkkkkkkkkkkkkkk");
	vector<int> correct = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17};
	EXPECT_EQ(result, correct);
}

TEST(KMP_Test, overlay)
{
    int count = 0;
	auto result = KMP("abababab", "abababababababab", count);
	vector<int> correct = {0,2,4,6,8};
	EXPECT_EQ(result, correct);
}

TEST(KMP_Test, string_of_one_symbol)
{
    int count =0;
	auto result = KMP("a", "aaaaaaaaaaaaaaaaaaaa", count);
	vector<int> correct = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
	EXPECT_EQ(result, correct);
}

TEST(Shift_Test, similar)
{
	std::string first = "kkkkk";
	std::string second = "kkkkk";
	auto result = SHIFT(first, second);
	EXPECT_EQ(result, 0);
}
TEST(Shift_Test, string_of_15_symb)
{
	std::string first = "1VkRFipbkyO1ORl";
	std::string second = "kyO1ORl1VkRFipb";
	auto result = SHIFT(first, second);
	EXPECT_EQ(result, 8);
}
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



