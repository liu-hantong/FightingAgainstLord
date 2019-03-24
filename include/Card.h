#pragma once
#include"include.h"
class Card : public std::string
{
public:
	static const int N_CARD_VALUES;
	static const int N_CARD_SUITS;
	static const string CARD_VALUES[];
	static const string CARD_SUITS[];

	Card(const char* str) :string(str) {};
	Card() :string() {};
	Card(string str) :string(str) {};

	static vector<Card> get_new_deck();

	// 重载操作符，使得牌面可以比较大小
	bool operator <(const Card &other) const;
	bool operator >(const Card &other) const;
};
