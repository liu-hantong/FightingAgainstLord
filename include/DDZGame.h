#pragma once
#include"DDZPlayer.h"
class DDZGame {
private:
	friend class DDZPlayer;
	static int my_random(int i);  // ϴ��ʱ�õ����������
	vector<DDZPlayer*> players;  // ����������ҵ�ָ��
	void showCards(vector<Card> cards);  // ���һ����
public:
	DDZGame(DDZPlayer *p1, DDZPlayer *p2, DDZPlayer *p3);  // ���캯��
	void run();  // ִ����Ϸ����
};
