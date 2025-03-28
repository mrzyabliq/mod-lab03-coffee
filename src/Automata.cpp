#include "Automata.h"
void Automata::on() {
    if (state == OFF) {
        state = WAIT;
        getState();
    }
    else {
        cout<<"Machine is already working\n";
    }
}
void Automata::off()
{
    if(state == WAIT)
    {
        change();
        state = OFF;
        getState();
    }
    else
    {
        if(state != OFF)
        {
            cout<<"Machine is working, pls wait\n";
        }
    }
}
void Automata::coin(int money)
{
    if(state == WAIT || state == ACCEPT) {
        cash+=money;
        state = ACCEPT;
        getState();
    }
    else{
        cout<<"Unable to do this action now\n";
    }
    
}
void Automata::choice(string drink)
{
    if(state == ACCEPT)
    {
        if(find(menu.begin(), menu.end(), drink)!=menu.end())
        {
            cout<<"Unable to make this drink";
        }
        else
        {
            state = CHECK;
            getState();
            check(drink);
        }   
    }
    
}
void Automata::cancel()
{
    if(state != OFF)
    {
        state = WAIT;
    }
}
STATES Automata::getState()
{
    cout<<state;
    return state;
}
void Automata::getMenu()
{
    for(int i = 0; i<menu.size(); i++)
    {
        cout<<menu[i]<<' '<<prices[i]<<'\n';
    }
}
void Automata::check(string drink)
{
    if(state == CHECK)
    {
        auto it = find(menu.begin(), menu.end(), drink);
        int index = distance(menu.begin(), it);
        int price_of_coffee = prices[index];
        if(cash < price_of_coffee){
            cout<<"No money, top up your balance\n";
            cancel();
        }
        else
        {
            cash-=price_of_coffee;
            cook();
        }
    }
    else{
        cout<<"Ivalid state";
    }
}
void Automata::cook()
{
    cout<<"Started preparing. Pls, wait\n";
    auto start = chrono::steady_clock::now();
    auto duration = chrono::seconds(5);
    state = COOK;
    while (chrono::steady_clock::now() - start < duration) {
        getState();
    }
    cout<<"Drink prepapred!\n";
    finish();

}
void Automata::finish()
{
    state = WAIT;
    getState();   
}
void Automata::change()
{
    if(state == WAIT)
    {
        if(cash > 0)
        {
            cout<<"Here is your change"<<cash;
            cash = 0;
        }
    }
    
    
}
int Automata::getCash()
{
    return cash;
}
