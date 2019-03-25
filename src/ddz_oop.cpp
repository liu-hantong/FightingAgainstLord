// Please use UTF-8 encoding so that the comments can be displayed correctly.
#pragma once
#include"DDZGame.h"
#include"DDZHumanPlayer.h"
// ----------------------------------------------------------------------------

int main() {
    string name;
    cout << "Please input your name:" << endl;
    getline(cin, name);

    srand(0x5943B);

    DDZPlayer p1("Alice"), p2("Bob");
    DDZHumanPlayer p3(name);
    DDZGame g(&p1, &p2, &p3);
    g.run();
	system("pause");
    return 0;
}

