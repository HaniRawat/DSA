class Solution{
public:
      int distance(int X, int Y)
      {
        int dis = 0;
        while(X != Y){
            if(X > Y){
                X /= 2;
            }
            else{
                Y /= 2;
            }
            dis++;
        }
        return dis;
      }
};