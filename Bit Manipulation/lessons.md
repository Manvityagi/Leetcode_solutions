(1) Check ith bit of a number num is set ot not `num*(1<<i)`
(2) If you know which bits are set in a number x, then x can be calculated by adding i<<i(2^i) for all the set bits i
(3) Get its last set bit of num
num &= -num;
