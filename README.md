# FightingAgainstLord
命令行版本手动/自动斗地主程序  
本项目继承自练习项目：[弱智版斗地主](https://github.com/llht/Cpp-Learning/tree/master/Projects/PokerGame)  
## 实现功能
两个单机玩家，一个用户，随机生成地主，用户命令行输入将要打出的牌，程序进行判断、比较、出牌以及显示游戏进度等一系列功能，最终判断哪方获胜  
## 输入输出以及完整打牌过程实例
以下是手动输入牌并打牌的实例，使用```ddz_oop.cpp```中的后者main函数进行编译执行。  
使用前者main函数会得到自动的完整斗地主流程，即三个单机玩家，输出雷同，不做展示。
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
## 实现思路及各个类的大致功能  
```ddz_oop.cpp```：作为程序的执行开始，main函数提供了游戏系统```DDZGame```以及```DDZPlayer/DDZhumanPlayer```的实例化和执行。
```DDZGame.h/cpp```：实现了整个游戏流程的控制类，生成地主、判断当前玩家、判断胜负等功能，是整个项目的框架类。
```DDZPlayer.h/cpp```：实现玩家的基本功能，包括拿牌、看牌、判断出牌等功能。  
```DDZhumanPlayer.h/cpp```：继承自```DDZPlayer```，实现了命令行用户的自主选择出牌，基本功能继承于```DDZPlayer```类的虚函数。
```Card.h/cpp```；继承自STL string类，模拟了扑克牌，重载大小比较操作符以实现扑克牌的大小比较，```vector<Card>```属于整个程序的基本数据类型。  
```MyPoker/PokerAnalysis.h/cpp```：属于整个程序的幕后工作者，算法实现了牌的类型判断以及出牌的基本策略，具体可查看[原始练习项目](https://github.com/llht/Cpp-Learning/tree/master/Projects/PokerGame)的说明。  
```include.h```：项目的总需include的STL等标准库文件，需要注意的是，其中的一个vector<vector<string>>常量作为判断的底牌，用于为玩家出牌提供原始比较对象，以选择最小的牌，具体使用方式可参考```DDZPlayer```中的原始出牌实现。
