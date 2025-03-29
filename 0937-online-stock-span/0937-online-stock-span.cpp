class StockSpanner {
public:
    int index ;
    stack<pair<int, int>> stk;
    StockSpanner() { index = 0; }

    int next(int price) {

        int temp = 1;

        while (!stk.empty() && stk.top().first <= price) {
            temp+=stk.top().second;
            stk.pop();
        }
        stk.push({price, temp});
        return temp ;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */