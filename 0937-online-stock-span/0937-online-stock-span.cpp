class StockSpanner {
public:
    int index ;
    stack<pair<int, int>> stk;
    StockSpanner() { index = 0; }

    int next(int price) {

        while (!stk.empty() && stk.top().first <= price) {
            stk.pop();
        }
        int temp = (!stk.empty()) ? index - stk.top().second : index+1;
        stk.push({price, index++});
        return temp ;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */