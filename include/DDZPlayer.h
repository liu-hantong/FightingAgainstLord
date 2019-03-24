#pragma once
#include"include.h"
#include"Card.h"
#include"PokerAnalysis.h"
#include"MyPoker.h"
#include"DDZGame.h"
class DDZPlayer {
protected:
	string name;  // 玩家名
	int position;  // 你的位置编号，0为地主，1为地主下家，2为地主上家
	vector<Card> hand;  // 手牌

	int prePos;  //上一个出牌的人位置编号，-1表示还没有人出过牌
	vector<Card> prePlay;  // 上一个出牌的人出了什么牌？

	bool legal(vector<Card> cards);  // 判断当前打出cards是否合法
	void substractFromHand(vector<Card> cards);  // 从当前手牌中删去cards中的牌
public:
	DDZPlayer(string name);  // 构造函数，初始化玩家名
	string getName();
	virtual void draw(Card card);  // 将cards中的牌加入手牌
	virtual void draw(vector<Card> cards);  // 将cards中的牌加入手牌
	virtual void setPosition(int pos);  // 初始化用，决定地主后设置
	virtual void showHand();  // 打印手牌
	virtual void observed(int pos, vector<Card> cards);  // 观测到玩家出牌
	virtual vector<Card> play();  // 轮到自己时决定出什么牌
	vector<string> OriginOut(vector<string>);  //选择一个原始的出牌
	bool leftNoCard();  // 返回是否打完了牌？
};
