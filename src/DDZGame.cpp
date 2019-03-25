#pragma once
#include"DDZGame.h"
int DDZGame::my_random(int i) {
	return std::rand() % i;
}

DDZGame::DDZGame(DDZPlayer *p1, DDZPlayer *p2, DDZPlayer *p3) {
	// �ƾ���Ĺ��캯������Ҫ�������������Ϊ����
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
	// ��������Ϸ����Ҫ����

	// ȡһ�����Ʋ�ϴ��
	vector<Card> deck = Card::get_new_deck();
	random_shuffle(deck.begin(), deck.end(), my_random);

	// ÿ����ҳ�17���ƣ��������ŵ���
	for (int i = 0; i < 54 - 3; ++i)
		players[i % 3]->draw(deck[i]);

	// ���ѡȡ�����������������������
	int landlordPos = my_random(3);
	for (int i = 54 - 3; i < 54; ++i)
		players[landlordPos]->draw(deck[i]);
	for (int i = 0; i < 3; ++i)
		players[i]->setPosition((i + 3 - landlordPos) % 3); // ��������������λ��
	cout << players[landlordPos]->getName() << " is the landlord." << endl;


	int currentPlayer = landlordPos;
	while (true) {
		// ��ǰ��Ҵ���
		vector<Card> currentCards = players[currentPlayer]->play();
		cout << players[currentPlayer]->getName() << " plays:";
		showCards(currentCards);
		// ������ҿ����˴�����ơ���������ֻ���¼ҿ������ϼ�Ҳ�ܿ�����
		for (int i = 0; i < 3; ++i) {
			// ��ҿ�����λ�ñ�Ŷ��Ǵӵ���Ϊ0��ʼ��
			int relativePos = (currentPlayer + 3 - landlordPos) % 3;
			players[i]->observed(relativePos, currentCards);
		}

		// ����ճ����Ƶ����û��������Ϸ����
		if (players[currentPlayer]->leftNoCard()) {
			bool landlordwins = (currentPlayer == landlordPos);
			cout << (landlordwins ? "Landlord wins!" : "Farmers win!") << endl;
			break;
		}

		// ������һ����ҵ��±�
		currentPlayer = (currentPlayer + 1) % 3;
	}
}
