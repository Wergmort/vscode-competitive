//与えられた数をこえない最大の平方数の平方根を求める
unsigned long long int_sqrt(unsigned long long N) {
    unsigned long long Left = 1, Right = 1e9;
    Left = 1, Right = 1e9;
    while (Left < Right) {
        unsigned long long Mid = (Left + Right) / 2;
        if (N >= Mid*Mid) Left = Mid; 
        if (N < Mid*Mid) Right = Mid; 
        if (N < (Left+1)*(Left+1)) {
            break;
        }
        if (N > (Right)*(Right)) {
            Left = Right;
            break;
        }
        if (N == Mid*Mid) {
            Left = Mid;
            Right = Mid;
            break;
        }
    }
    return Left; 
}
