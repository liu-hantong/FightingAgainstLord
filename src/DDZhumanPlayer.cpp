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
		// 现在cards是一个vector<Card>，存储了用户输入的牌
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