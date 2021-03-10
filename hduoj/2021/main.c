#include <stdio.h>

int main(int argc, char *argv[])
{
   int i, j, n, t, k, s[6] = {100, 50, 10, 5, 2, 1};
   while (scanf("%d", &n) != EOF)
   {
      if (n == 0)
      {
         break;
      }
      for (i = j = k = 0; i < n; i++, j = 0)
      {
         scanf("%d", &t);
         while (t)
         {
            // 先算大面额得需要几张，若大面额溢出则换小面额
            if (t < s[j])
            {
               j++;
            }
            else
            {
               t -= s[j], k++;
            }
         }
      }
      printf("%d\n", k);
   }
   return 0;
}