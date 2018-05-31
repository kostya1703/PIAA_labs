#include <gtest/gtest.h>
#include "../hdr/func.h"

using ::testing::TestWithParam;
using ::testing::Values;



map<int, vector<int>> Standart(const string& text,const vector<string>& pattern) {
    initBohr();
    map<int, vector<int>> answrs;
    answrs.clear();
    vector<string> dop;
    for(const auto& patt : pattern) {
       addstrBohr(patt, dop);
   }
   stand_find_all_pos(text, pattern, answrs);
   for(auto& it: answrs)
        sort(it.second.begin(),it.second.end());
   return answrs;
}


struct Stand_Test
{
    string text;
	vector<string> pattern;
	map<int, vector<int>> expected_answ;
};

class Stand_Fixture : public TestWithParam<Stand_Test>
{
public:
	virtual void SetUp() {
	    answrs = Standart(GetParam().text, GetParam().pattern);
	}
    virtual void TearDown() { }

protected:
    map<int, vector<int>> answrs;
};

INSTANTIATE_TEST_CASE_P(StandartInstantiate, Stand_Fixture,
Values(
    Stand_Test{"CCCA", {"CC"}, {{1,{1}},{2,{1}}}},
    Stand_Test{"CCCA", {"CC", "C","CCC"}, {{1,{1,2,3}},{2,{1,2}},{3,{2}}}},
    Stand_Test{"TGHGRTH", {"GR", "TGHG", "RTH"}, {{1,{2}},{4,{1}},{5,{3}}}},
    Stand_Test{"AAAAAAAA", {"R"}, {}}
));

TEST_P(Stand_Fixture, Stand_Test) {
    ASSERT_EQ(GetParam().expected_answ, answrs);
}




vector<int> Joker(const string& text, const string& pat, char razd) {
    initBohr();
    stringstream str_pat(pat);
    vector<int> count(text.size(),0);
    vector<string> pattern;
    vector<int> spliter = split(str_pat, razd, pattern);
    joker_find_all_pos(text, count, spliter);
    return getPos(count,text.size()-pat.size()+1,pattern.size());
}

struct Joker_Test
{
    string text;
	string pat;
	char jok;
	vector<int> expected_poss;
};

class Joker_Fixture : public TestWithParam<Joker_Test>
{
public:
	virtual void SetUp() {
	    poss = Joker(GetParam().text, GetParam().pat, GetParam().jok);
	}
    virtual void TearDown() { }

protected:
	vector<int> poss;
};

INSTANTIATE_TEST_CASE_P(DjokerInstantiate, Joker_Fixture,
Values(
	Joker_Test{"ACT", "A$", '$', {1}},
	Joker_Test{"CCC", "C$", '$', {1, 2}},
	Joker_Test{"BBBBB", "B***", '*', {1, 2}},
	Joker_Test{"TTTTTT", "!!!T", '!', {1, 2, 3}},
	Joker_Test{"SSSSS", "**S**", '*', {1}},
	Joker_Test{"TTTT", "T#T", '#', {1, 2}}

));


TEST_P(Joker_Fixture, Joker_Test) {
    ASSERT_EQ(GetParam().expected_poss, poss);
}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
