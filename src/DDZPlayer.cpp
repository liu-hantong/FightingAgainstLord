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
	// �����Ĺ��캯��
	prePos = -1;
}

string DDZPlayer::getName() {
	return name;
}

bool DDZPlayer::legal(vector<Card> &cards) {
	// ͨ���ϼҴ������prePlay������hand�ж�cards��Ϊ������Ƿ�Ϸ�
	// TODO�����ڶ��⣩�벹ȫ�������
	//�����ж�hand�ǲ��ǰ���cards
	if (cards[0] == "YAO")
	{
		//Ҫ���������
		cards.clear();
		return true;
	}
	vector<Card> handCopy = hand;//����һ�����Ƶ�Copy�����ڼ��cards�Ƿ�Ϸ�
	for (auto i = cards.begin(); i != cards.end(); ++i)
	{
		auto CardPosition = find(handCopy.begin(), handCopy.end(), *i);
		if (CardPosition != handCopy.end())
			//�ҵ���cards֮һ��ɾ��������Ѱ��
			handCopy.erase(CardPosition, CardPosition + 1);
		else
			return false;
	}
	//����ж�prePlay��hand�ǲ���ͬһ�����͵���
	vector<string> prePlay_String;
	vector<string> cards_String;
	for (auto i = prePlay.begin(); i != prePlay.end(); ++i)
		prePlay_String.push_back(*i);
	for (auto i = cards.begin(); i != cards.end(); ++i)
		cards_String.push_back(*i);
	PokerAnalysis preplayAnalysis(prePlay_String, prePlay_String.size());
	PokerAnalysis cardsAnalysis(cards_String, cards_String.size());
	if (prePos == position || prePos == -1)
	//�������Ƽ��ɣ�����Ҫ��֤�������Ƿ��϶����������
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
	//������������ͬ���ж��Ƿ�cards��prePlay��
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
	// ���������hand��ɾ��cards������cards�е���hand�����õó���������������
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
	// �������������ơ�
	cout << name << " holds: ";
	for (vector<Card>::iterator i = hand.begin(); i != hand.end(); ++i) {
		cout << *i << " ";
	}
	cout << endl;
}

void DDZPlayer::draw(Card card) {
	// ��card��������
	hand.push_back(card);
	sort(hand.begin(), hand.end(), greater<Card>());
}

void DDZPlayer::draw(vector<Card> cards) {
	// ��cards�е��Ƽ�������
	hand.insert(hand.end(), cards.begin(), cards.end());
	sort(hand.begin(), hand.end(), greater<Card>());
}

void DDZPlayer::setPosition(int pos) {
	position = pos;
}

void DDZPlayer::observed(int pos, vector<Card> cards) {
	// ����һ�����Ƶ��˺ͳ���ʲô�Ƽ�¼������
	if (cards.size() == 0) return;
	prePos = pos;
	prePlay = cards;
}

vector<Card> DDZPlayer::play() {
	// �ֵ�����ƣ����ش�����ơ�
	vector<Card> cards;
	//��vector<Card>ת��Ϊvector<string>�Է������ԭʼ���ݽṹ
	vector<string> hand_String;
	for (auto i = hand.begin(); i != hand.end(); ++i)
		hand_String.push_back(*i);
	vector<string> MyOut;
	if (prePos == position || prePos == -1) {
		// ��������
		MyOut = OriginOut(hand_String);
	}
	else {
		//��preplayת��Ϊvector<string>
		vector<string> prePlay_String;
		for (auto i = prePlay.begin(); i != prePlay.end(); ++i)
			prePlay_String.push_back(*i);
		//ѡ����ʵĳ���
		PokerAnalysis CurrentBiggest(prePlay_String, prePlay_String.size());
		MyPoker CurrentPlayer(hand_String, (int)hand_String.size(), CurrentBiggest);
		MyOut = CurrentPlayer.MyOut;
	}
	//��MyOutת��Ϊvector<Cards>����
	if (!MyOut.empty())
	{
		for (auto i = MyOut.begin(); i != MyOut.end(); ++i)
			cards.push_back(*i);
	}
	// ��������ƴ�������ɾȥ
	substractFromHand(cards);
	return cards;
}

bool DDZPlayer::leftNoCard() {
	// ���ص�ǰ����Ϊ��
	return hand.empty();
}
