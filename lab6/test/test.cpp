#include <gtest/gtest.h>
#include "../hdr/func.h"

using ::testing::TestWithParam;
using ::testing::Values;



map<int, vector<int>> Standart(const wstring& text,const vector<wstring>& pattern) {
    initBohr();
    map<int, vector<int>> answrs;
    answrs.clear();
    vector<wstring> patterns;
    for(const auto& patt : pattern) {
       addstrBohr(patt, patterns);
   }
   stand_find_all_pos(text, pattern, answrs);
   for(auto& it: answrs)
        sort(it.second.begin(),it.second.end());
   return answrs;
}


struct Stand_Test
{
    wstring text;
	vector<wstring> pattern;
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
    Stand_Test{L"CCCA", {L"CC"}, {{1,{1}},{2,{1}}}},
    Stand_Test{L"CCCA", {L"CC", L"C",L"CCC"}, {{1,{1,2,3}},{2,{1,2}},{3,{2}}}},
    Stand_Test{L"TGHGRTH", {L"GR", L"TGHG", L"RTH"}, {{1,{2}},{4,{1}},{5,{3}}}},
    Stand_Test{L"AAAAAAAA", {L"R"}, {}},
    Stand_Test{L"CФCФS", {L"Ф"}, {{2,{1}},{4,{1}}}},
	Stand_Test{L"ФФ", {L"Ф"}, {{1,{1}},{2,{1}}}}
));


TEST_P(Stand_Fixture, Stand_Test) {
    ASSERT_EQ(GetParam().expected_answ, answrs);
}




vector<int> Joker(const wstring& text, const wstring& pat, char jok) {
    initBohr();
    wstringstream str_pat(pat);
    vector<int> count(text.size(),0);
    vector<wstring> pattern;
    vector<int> spliter = split(str_pat, jok, pattern);
    joker_find_all_pos(text, count, spliter);
    return getPos(count,text.size()-pat.size()+1,pattern.size());
}

struct Joker_Test
{
    wstring text;
	wstring pat;
	wchar_t jok;
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

INSTANTIATE_TEST_CASE_P(JokerInstantiate, Joker_Fixture,
Values(
	Joker_Test{L"ACT", L"A$", L'$', {1}},
	Joker_Test{L"CCC", L"C$", L'$', {1, 2}},
	Joker_Test{L"BBBBB", L"B***", L'*', {1, 2}},
	Joker_Test{L"TTTTTT", L"!!!T", L'!', {1, 2, 3}},
	Joker_Test{L"SSSSS", L"**S**", L'*', {1}},
	Joker_Test{L"TTTT", L"T#T", L'#', {1, 2}},
	Joker_Test{L"ФФФФ", L"Ф*Ф", L'*', {1, 2}}
));


TEST_P(Joker_Fixture, Joker_Test) {
    ASSERT_EQ(GetParam().expected_poss, poss);
}


int main(int argc, char **argv) {
    setlocale(LC_ALL, "");
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
