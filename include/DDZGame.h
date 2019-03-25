#pragma once
#include"DDZPlayer.h"
class DDZGame {
private:
	friend class DDZPlayer;
	static int my_random(int i);  // 洗牌时用到的随机函数
	vector<DDZPlayer*> players;  // 保存三个玩家的指针
	void showCards(vector<Card> cards);  // 输出一组牌
public:
	DDZGame(DDZPlayer *p1, DDZPlayer *p2, DDZPlayer *p3);  // 构造函数
	void run();  // 执行游戏流程
};
