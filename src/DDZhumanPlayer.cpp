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
		// 你需要检测输入的牌是持有的牌，并且合法。请完成legal函数。
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