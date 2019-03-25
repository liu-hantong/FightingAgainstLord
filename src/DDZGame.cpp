#pragma once
#include"DDZGame.h"
int DDZGame::my_random(int i) {
	return std::rand() % i;
}

DDZGame::DDZGame(DDZPlayer *p1, DDZPlayer *p2, DDZPlayer *p3) {
	// 牌局类的构造函数，需要接受三个玩家作为参数
	players.push_back(p1);
	players.push_back(p2);
	players.push_back(p3);
}

void DDZGame::showCards(vector<Card> cards) {
	sort(cards.begin(), cards.end(), greater<Card>());
	for (vector<Card>::iterator i = cards.begin(); i != cards.end(); ++i) {
		cout << *i << " ";
	}
	if (cards.size() == 0) cout << "YAO BU QI";
	cout << endl << endl;
}

void DDZGame::run() {
	// 斗地主游戏的主要流程

	// 取一副新牌并洗牌
	vector<Card> deck = Card::get_new_deck();
	random_shuffle(deck.begin(), deck.end(), my_random);

	// 每个玩家抽17张牌，留下三张底牌
	for (int i = 0; i < 54 - 3; ++i)
		players[i % 3]->draw(deck[i]);

	// 随机选取地主，发给地主最后三张牌
	int landlordPos = my_random(3);
	for (int i = 54 - 3; i < 54; ++i)
		players[landlordPos]->draw(deck[i]);
	for (int i = 0; i < 3; ++i)
		players[i]->setPosition((i + 3 - landlordPos) % 3); // 计算与地主的相对位置
	cout << players[landlordPos]->getName() << " is the landlord." << endl;


	int currentPlayer = landlordPos;
	while (true) {
		// 当前玩家打牌
		vector<Card> currentCards = players[currentPlayer]->play();
		cout << players[currentPlayer]->getName() << " plays:";
		showCards(currentCards);
		// 其他玩家看到了打出的牌。（并不是只有下家看到，上家也能看到）
		for (int i = 0; i < 3; ++i) {
			// 玩家看到的位置编号都是从地主为0开始的
			int relativePos = (currentPlayer + 3 - landlordPos) % 3;
			players[i]->observed(relativePos, currentCards);
		}

		// 如果刚出完牌的玩家没有牌了游戏结束
		if (players[currentPlayer]->leftNoCard()) {
			bool landlordwins = (currentPlayer == landlordPos);
			cout << (landlordwins ? "Landlord wins!" : "Farmers win!") << endl;
			break;
		}

		// 计算下一个玩家的下标
		currentPlayer = (currentPlayer + 1) % 3;
	}
}
