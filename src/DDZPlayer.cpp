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

bool DDZPlayer::legal(vector<Card> cards) {
	// ͨ���ϼҴ������prePlay������hand�ж�cards��Ϊ������Ƿ�Ϸ�
	// TODO�����ڶ��⣩�벹ȫ�������
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
	// ��������¼�������Ϣ����Ĳ���ʹ�ã����ԸĶ����������
	// ���磬��¼�Ѿ�����Щ�Ʊ�������������������Ʋⳡ���Ƿ���ܻ�����ը����
	if (cards.size() == 0) return;
	prePos = pos;
	prePlay = cards;
}

vector<Card> DDZPlayer::play() {
	// �ֵ�����ƣ����ش�����ơ�
	// TODO������һ�⣩�������������
	// �����ʹ�ò�ͬ�����ݽṹ���д���������ֽ�hand����ת��Ϊ��ʹ�õĽṹ��
	// ��������ٽ��������ת��Ϊvector<Card>������card������
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
		// λ��prePos����Ҵ����prePlay���ƣ�����Ҫ��ʲô�ƣ�
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
	// ����Ҫ��֤��������ǺϷ���
	// assert�����ڲ���Ϊfalse��ʱ���ʹ���򱨴��˳���
	// �������ĺô��ǣ��������ûע�⵽�Ĵ����³����ڴ˱����˳���
	// ���֪�����ڳ��ƵĺϷ����ϳ������⣬�������Ų������������֡�
	// assert(legal(cards));

	// ��������ƴ�������ɾȥ
	substractFromHand(cards);
	return cards;
}

bool DDZPlayer::leftNoCard() {
	// ���ص�ǰ����Ϊ��
	return hand.empty();
}
