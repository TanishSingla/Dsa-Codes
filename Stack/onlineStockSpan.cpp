class StockSpanner
{
public:
    stack<pair<int, int>> s; // price,span
    StockSpanner()
    {
    }

    int next(int price)
    {
        int span = 1;
        while (!s.empty() && s.top().first <= price)
        {
            span += s.top().second;
            // and before poping out we will add that span
            s.pop();
        }
        s.push({price, span});

        return span;
    }
};

//[100,80,60,70,60,75,85]
// we are creating a stack of pair
// int which we are storing the price as well as its span
// ex :-
// for 100 we store (100,1)
// next we have 80 as 80 is <=100
// so we will  store this as well in stack (stack=[100(1),80(1)])
// now we have 60 -> 60 is also smaller thn s.top() (stack = [100(1),80(1),60(1)])
// for 70 -> 70 is greater than 60
// while loop will run and 60 will pop out and in span of 70 we will add
// span of 60 now as 80 is greater than 70 while loop will stop and we will return 2
// stack = [100(1),80(1),70(2)]

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

// https://leetcode.com/problems/online-stock-span/