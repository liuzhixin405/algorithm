using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PB_BFind
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] arr = { 7,16,23,42,45};

            int   = 43;
            int len = arr.Length;

            int low = 0;
            int high = len - 1;
            while (low <= high)
            {
                int middle = (low + high) / 2;
                if (findVal == arr[middle])
                {
                    Console.WriteLine("查找成功。位于arr[{0}]", middle);
                    return;
                }
                else if (findVal < arr[middle])
                    high = middle - 1;
                else
                    low = middle + 1;
            }

            Console.WriteLine("查找失败。");

        }
    }
}
