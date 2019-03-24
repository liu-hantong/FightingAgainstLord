#pragma once
#include"DDZHumanPlayer.h"
vector<Card> DDZHumanPlayer::play() {
	vector<Card> cards;
	string s, c;
	while (true) {
		showHand();
		cout << "Please input the cards you want to play." << endl;
		getline(cin, s);
		istringstream iss(s);
		while (iss >> c) {
			cards.push_back(Card(c));
		}
		// ����cards��һ��vector<Card>���洢���û��������
		// ����Ҫ�����������ǳ��е��ƣ����ҺϷ��������legal������
		if (legal(cards)) {
			break;
		}
		else {
			cout << "Illegal cards. Input again." << endl;
			cards.clear();
		}
	}
	substractFromHand(cards);
	return cards;
}