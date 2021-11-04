using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DataStructDemo
{
    class Fibonacci
    {
        /// <summary>
        /// 递归求第n项
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        public static int F(int n)
        {
            //n=0,n=1 F(0)=F(1)=1
            //F(n)=F(n-1)+F(n-2)
            if (n == 0 || n == 1)
            {
                return 1;
            }
            else
            {
                return F(n - 1) + F(n - 2);
            }
            //F(5)=F(4)+F(3)
            //F(4) =F(3)+F(2)  F(3)=F(2)+F(1)
            //F(3)=F(2)+F(1)   F(2)=F(1)+F(0)
            //F(2)=F(1)+F(0)
        }
        /// <summary>
        /// 非递归算法 
        /// </summary>
        /// <param name="n"></param>
        /// <returns></returns>
        public static int Fx(int n)
        {
            int i = 1;
            int j = 1;
            int temp = 0;
            if (n == 0 || n == 1)
            {
                return 1;
            }
            for (int k = 2; k <= n; k++)
            {
                temp = i + j;
                i = j;
                j = temp;
            }
            return temp;
        }
    }
}
