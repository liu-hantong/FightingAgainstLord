// Please use UTF-8 encoding so that the comments can be displayed correctly.
// 标注TODO的是你需要完善的地方
#pragma once
#include"DDZGame.h"
// ----------------------------------------------------------------------------

int main() {
    srand(0x5942B);

    DDZPlayer p1("Alice"), p2("Bob"), p3("Charlie");
    DDZGame g(&p1, &p2, &p3);
    g.run();
	system("pause");
    return 0;
}

/*
int main2() {
    string name;
    cout << "Please input your name:" << endl;
    getline(cin, name);

    srand(0x5942B);

    DDZPlayer p1("Alice"), p2("Bob");
    DDZHumanPlayer p3(name);
    DDZGame g(&p1, &p2, &p3);
    g.run();

    return 0;
}
*/

