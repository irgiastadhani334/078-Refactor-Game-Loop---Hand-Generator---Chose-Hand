#include <iostream>
#include "GameManager.h"

void GameManager::runSession() {
	std::cout << "=== Run Started ===\n";
	Hand hand = handGenerator.generateHand();
	handPlayer.playHand(hand);
	int score = scoringRule.scoreHand(hand);
	jokerCard.onHandPlayed(score);
	score = jokerCard.modifyScore(score);
	bool win = blindRule.checkBlind(score);
	int reward = rewardRule.earnMoney(win, score);
	std::cout << "Money gained: " << reward << "\n";
	std::cout << "=== Run Ended ===\n";
}
