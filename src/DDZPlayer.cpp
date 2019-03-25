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

bool DDZPlayer::legal(vector<Card> &cards) {
	// 通过上家打出的牌prePlay和手牌hand判断cards作为打出牌是否合法
	// TODO：（第二题）请补全这个函数
	//首先判断hand是不是包含cards
	if (cards[0] == "YAO")
	{
		//要不起这个牌
		cards.clear();
		return true;
	}
	vector<Card> handCopy = hand;//创建一个手牌的Copy，用于检测cards是否合法
	for (auto i = cards.begin(); i != cards.end(); ++i)
	{
		auto CardPosition = find(handCopy.begin(), handCopy.end(), *i);
		if (CardPosition != handCopy.end())
			//找到了cards之一，删除并继续寻找
			handCopy.erase(CardPosition, CardPosition + 1);
		else
			return false;
	}
	//其次判断prePlay和hand是不是同一种类型的牌
	vector<string> prePlay_String;
	vector<string> cards_String;
	for (auto i = prePlay.begin(); i != prePlay.end(); ++i)
		prePlay_String.push_back(*i);
	for (auto i = cards.begin(); i != cards.end(); ++i)
		cards_String.push_back(*i);
	PokerAnalysis preplayAnalysis(prePlay_String, prePlay_String.size());
	PokerAnalysis cardsAnalysis(cards_String, cards_String.size());
	if (prePos == position || prePos == -1)
	//出任意牌即可，但是要保证出的牌是符合斗地主规则的
	{
		PokerAnalysis New(cards_String, cards_String.size());
		if(New.CardsNature == 0)
			return false;
		return true;
	}
	if (prePlay.size() != cards.size())
		return false;
	if (preplayAnalysis.CardsNature != cardsAnalysis.CardsNature)
		return false;
	//两种牌牌型相同，判断是否cards比prePlay大！
	int nature = preplayAnalysis.CardsNature;
	int Bigger = 0;
	switch (nature)
	{
	case 1: Bigger = cards[0] > prePlay[0]; break;
	case 2: Bigger = cards[0] > prePlay[0]; break;
	case 3: Bigger = cards[0] > prePlay[0]; break;
	case 4: Bigger = cards[1] > prePlay[1]; break;
	case 5: Bigger = cards[2] > prePlay[2]; break;
	case 6: Bigger = cards[0] > prePlay[0]; break;
	case 7: Bigger = cards[0] > prePlay[0]; break;
	case 8: Bigger = cards[2] > prePlay[2]; break;
	case 9: Bigger = cards[0] > prePlay[0]; break;
	case 10: Bigger = cards[1] > prePlay[1]; break;
	case 11: Bigger = cards[2] > prePlay[2]; break;
	case 12: Bigger = cards[0] > prePlay[0]; break;
	default:
		break;
	}
	if (!Bigger)
		return false;
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
	if (cards.size() == 0) return;
	prePos = pos;
	prePlay = cards;
}

vector<Card> DDZPlayer::play() {
	// 轮到你出牌，返回打出的牌。
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
	// 将打出的牌从手牌中删去
	substractFromHand(cards);
	return cards;
}

bool DDZPlayer::leftNoCard() {
	// 返回当前手牌为空
	return hand.empty();
}
