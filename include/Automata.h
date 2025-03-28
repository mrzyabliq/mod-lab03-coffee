#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <chrono>

using namespace std;
enum STATES {
    OFF,
    WAIT,
    ACCEPT,
    CHECK,
    COOK
};

class Automata {
    public:
        void on();
        void off();
        void coin(int money);
        void choice(string drink);
        void cancel();
        STATES getState();
        void getMenu();
        int getCash();
        void change();
        Automata() {
            cash = 0;
            state = OFF;
            menu = {"Cappucino", "Americano", "Latte", "Espresso"};
            prices = {120, 100, 130, 90};
        }
    private:
        int cash;
        vector<string> menu;
        vector<int> prices;
        STATES state;
        void check(string drink);
        void cook();
        void finish();
        


};
