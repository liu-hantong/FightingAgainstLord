# FightingAgainstLord
命令行版本自动斗地主程序  
本项目继承自练习项目：[弱智版斗地主](https://github.com/llht/Cpp-Learning/tree/master/Projects/PokerGame)  
## 实现功能
两个单机玩家，一个用户，随机生成地主，用户命令行输入将要打出的牌，程序进行判断、比较、出牌以及显示游戏进度等一系列功能，最终判断哪方获胜  
## 输入输出以及完整打牌过程实例  
```
输出：
Please input your name:
输入：
hantong
输出：
Bob is the landlord.
Bob plays:5 5

hantong holds: A K K J J 9 9 8 7 7 7 6 6 6 5 4 3
Please input the cards you want to play.
输入：
K K
输出：
hantong plays:K K

Alice plays:2 2

Bob plays:JOKER joker

hantong holds: A J J 9 9 8 7 7 7 6 6 6 5 4 3
Please input the cards you want to play.
输入：
YAO BU QI
输出：
hantong plays:YAO BU QI

Alice plays:YAO BU QI

Bob plays:8 8

hantong holds: A J J 9 9 8 7 7 7 6 6 6 5 4 3
Please input the cards you want to play.
输入：
9 9
输出：
hantong plays:9 9

Alice plays:10 10

Bob plays:Q Q

hantong holds: A J J 8 7 7 7 6 6 6 5 4 3
Please input the cards you want to play.
输入
YAO BU QI
输出：
hantong plays:YAO BU QI

Alice plays:YAO BU QI

Bob plays:10 10

hantong holds: A J J 8 7 7 7 6 6 6 5 4 3
Please input the cards you want to play.
输入：
J J
输出：
hantong plays:J J

Alice plays:Q Q

Bob plays:A A

hantong holds: A 8 7 7 7 6 6 6 5 4 3
Please input the cards you want to play.
输入：
YAO BU QI
输出：
hantong plays:YAO BU QI

Alice plays:YAO BU QI

Bob plays:2 2

hantong holds: A 8 7 7 7 6 6 6 5 4 3
Please input the cards you want to play.
输入：
YAO BU QI
输出：
hantong plays:YAO BU QI

Alice plays:YAO BU QI

Bob plays:4

hantong holds: A 8 7 7 7 6 6 6 5 4 3
Please input the cards you want to play.
输入：
A
输出：
hantong plays:A

Alice plays:YAO BU QI

Bob plays:YAO BU QI

hantong holds: 8 7 7 7 6 6 6 5 4 3
Please input the cards you want to play.
输入：
7 7 7 6 6 6
输出：
hantong plays:7 7 7 6 6 6

Alice plays:YAO BU QI

Bob plays:YAO BU QI

hantong holds: 8 5 4 3
Please input the cards you want to play.
输入：
3
输出：
hantong plays:3

Alice plays:4

Bob plays:6

hantong holds: 8 5 4
Please input the cards you want to play.
输入：
8
输出：
hantong plays:8

Alice plays:9

Bob plays:J

hantong holds: 5 4
Please input the cards you want to play.
输入：
YAO BU QI
输出：
hantong plays:YAO BU QI

Alice plays:K

Bob plays:YAO BU QI

hantong holds: 5 4
Please input the cards you want to play.
输入：
YAO BU QI
输出：
hantong plays:YAO BU QI

Alice plays:3 3

Bob plays:YAO BU QI

hantong holds: 5 4
Please input the cards you want to play.
输入：
YAO BU QI
输出：
hantong plays:YAO BU QI

Alice plays:3

Bob plays:7

hantong holds: 5 4
Please input the cards you want to play.
输入：
YAO BU QI
输出：
hantong plays:YAO BU QI

Alice plays:8

Bob plays:9

hantong holds: 5 4
Please input the cards you want to play.
输入：
YAO BU QI
输出：
hantong plays:YAO BU QI

Alice plays:J

Bob plays:K

Landlord wins!
```
