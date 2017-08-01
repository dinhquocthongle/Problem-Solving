#include <stdio.h>
using namespace std;

class ThrowTheBall
{
    public:
    //calculate the gcd...
    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a%b);
    }
    //the player 1 is always the one who hold the ball M times
    //when the game begin, it takes N/gcd(N,L) times before player 1 hold the ball again
    //also, when the player 1 start, he/she has already held the ball once
    //so player 1 only need to hold it M - 1 more times
    int timesThrown(int N, int M, int L)
    {
        int res;
        res = (M - 1) * N / gcd(N,L);
        return res;
    }
};