#pragma once
#include"DDZPlayer.h"
class DDZHumanPlayer : public DDZPlayer {
public:
	DDZHumanPlayer(string name) : DDZPlayer(name) {};
	vector<Card> play();
};