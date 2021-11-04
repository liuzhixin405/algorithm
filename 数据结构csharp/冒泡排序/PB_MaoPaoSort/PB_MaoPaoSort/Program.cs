using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PB_MaoPaoSort
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] arr = { 3, 18, 13, 9, 42, 21, 31, 12 };
            int len = arr.Length;
            int temp;

            for (int i = len - 1; i > 1; i--)
            {
                for (int j = 0; j < i; j++)
                {
                    if (arr[j] > arr[j + 1])
                    {
                        temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }

            foreach (int x in arr)
            {
                Console.WriteLine(x);
            }
        }
    }
}
