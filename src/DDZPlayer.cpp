#pragma once
#include"DDZPlayer.h"
vector<string> DDZPlayer::OriginOut(vector<string> PokersNneedToOut)
{
	int i = 1;
	//select random pokers to out
	for (; i < 21; ++i)
	{
		reverse(MinPokers[i].begin(), MinPokers[i].end());
		PokerAnalysis currentMin(MinPokers[i], MinPokers[i].size());
		MyPoker CurrentOrigin(PokersNneedToOut, PokersNneedToOut.size(), currentMin);
		if (!CurrentOrigin.MyOut.empty())
			return CurrentOrigin.MyOut;
	}
	//if doesn't find proper pokers, return the single poker
	vector<string> result;
	result.push_back(PokersNneedToOut[PokersNneedToOut.size() - 1]);
	return result;
}

DDZPlayer::DDZPlayer(string name) : name(name) {
	// 玩家类的构造函数
	prePos = -1;
}

string DDZPlayer::getName() {
	return name;
}

bool DDZPlayer::legal(vector<Card> cards) {
	// 通过上家打出的牌prePlay和手牌hand判断cards作为打出牌是否合法
	// TODO：（第二题）请补全这个函数
	return true;
}

void DDZPlayer::substractFromHand(vector<Card> cards) {
	// 这个函数从hand中删除cards。假设cards中的牌hand可以拿得出来（否则会出错）。
	sort(hand.begin(), hand.end(), greater<Card>());
	sort(cards.begin(), cards.end(), greater<Card>());
	vector<Card>::iterator i = hand.begin(), k = cards.begin();
	for (vector<Card>::iterator j = hand.begin(); j != hand.end(); ++j) {
		if (k == cards.end() || *k != *j) *(i++) = *j;
		else if (k != cards.end()) ++k;
	}
	hand.erase(i, hand.end());
}

void DDZPlayer::showHand() {
	// 输出玩家名和手牌。
	cout << name << " holds: ";
	for (vector<Card>::iterator i = hand.begin(); i != hand.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;
}

void DDZPlayer::draw(Card card) {
	// 将card加入手牌
	hand.push_back(card);
	sort(hand.begin(), hand.end(), greater<Card>());
}

void DDZPlayer::draw(vector<Card> cards) {
	// 将cards中的牌加入手牌
	hand.insert(hand.end(), cards.begin(), cards.end());
	sort(hand.begin(), hand.end(), greater<Card>());
}

void DDZPlayer::setPosition(int pos) {
	position = pos;
}

void DDZPlayer::observed(int pos, vector<Card> cards) {
	// 将上一个出牌的人和出了什么牌记录下来。
	// 如果你想记录更多的信息供你的策略使用，可以改动这个函数。
	// 例如，记录已经有哪些牌被打出（记牌器），以推测场上是否可能还存在炸弹。
	if (cards.size() == 0) return;
	prePos = pos;
	prePlay = cards;
}

vector<Card> DDZPlayer::play() {
	// 轮到你出牌，返回打出的牌。
	// TODO：（第一题）请完善这个函数
	// 如果你使用不同的数据结构进行处理，你可以现将hand变量转换为你使用的结构，
	// 处理过后再将打出的牌转换为vector<Card>，存入card变量。
	vector<Card> cards;
	//将vector<Card>转化为vector<string>以方便调用原始数据结构
	vector<string> hand_String;
	for (auto i = hand.begin(); i != hand.end(); ++i)
		hand_String.push_back(*i);
	vector<string> MyOut;
	if (prePos == position || prePos == -1) {
		// 出任意牌
		MyOut = OriginOut(hand_String);
	}
	else {
		// 位于prePos的玩家打出了prePlay的牌，你需要出什么牌？
		//将preplay转化为vector<string>
		vector<string> prePlay_String;
		for (auto i = prePlay.begin(); i != prePlay.end(); ++i)
			prePlay_String.push_back(*i);
		//选择合适的出牌
		PokerAnalysis CurrentBiggest(prePlay_String, prePlay_String.size());
		MyPoker CurrentPlayer(hand_String, (int)hand_String.size(), CurrentBiggest);
		MyOut = CurrentPlayer.MyOut;
	}
	//将MyOut转化为vector<Cards>类型
	if (!MyOut.empty())
	{
		for (auto i = MyOut.begin(); i != MyOut.end(); ++i)
			cards.push_back(*i);
	}
	// 你需要保证打出的牌是合法的
	// assert函数在参数为false的时候会使程序报错退出。
	// 这样做的好处是，如果你有没注意到的错误导致程序在此报错退出，
	// 你就知道是在出牌的合法性上出了问题，而不用排查程序的其他部分。
	// assert(legal(cards));

	// 将打出的牌从手牌中删去
	substractFromHand(cards);
	return cards;
}

bool DDZPlayer::leftNoCard() {
	// 返回当前手牌为空
	return hand.empty();
}
