#pragma once
#include"include.h"
#include"Card.h"
#include"PokerAnalysis.h"
#include"MyPoker.h"
#include"DDZGame.h"
class DDZPlayer {
protected:
	string name;  // �����
	int position;  // ���λ�ñ�ţ�0Ϊ������1Ϊ�����¼ң�2Ϊ�����ϼ�
	vector<Card> hand;  // ����

	int prePos;  //��һ�����Ƶ���λ�ñ�ţ�-1��ʾ��û���˳�����
	vector<Card> prePlay;  // ��һ�����Ƶ��˳���ʲô�ƣ�

	bool legal(vector<Card> cards);  // �жϵ�ǰ���cards�Ƿ�Ϸ�
	void substractFromHand(vector<Card> cards);  // �ӵ�ǰ������ɾȥcards�е���
public:
	DDZPlayer(string name);  // ���캯������ʼ�������
	string getName();
	virtual void draw(Card card);  // ��cards�е��Ƽ�������
	virtual void draw(vector<Card> cards);  // ��cards�е��Ƽ�������
	virtual void setPosition(int pos);  // ��ʼ���ã���������������
	virtual void showHand();  // ��ӡ����
	virtual void observed(int pos, vector<Card> cards);  // �۲⵽��ҳ���
	virtual vector<Card> play();  // �ֵ��Լ�ʱ������ʲô��
	vector<string> OriginOut(vector<string>);  //ѡ��һ��ԭʼ�ĳ���
	bool leftNoCard();  // �����Ƿ�������ƣ�
};
