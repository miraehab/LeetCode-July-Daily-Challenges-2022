class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        if(n == 1) return 1;
        int a = 0, b = 1, c = a + b;
        for(int i = 2; i < n; i++){
            int tmp = c + b;
            a = b;
            b = c;
            c = tmp;
        }
        return c;
    }
};