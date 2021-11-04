using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PB_BInsertSort
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] arr = { 7, 16, 23, 42, 45, 40 };  
            int len = arr.Length;
            int insertValue = arr[len - 1];

            int low = 0;
            int high = len - 2;
            while (low <= high)
            {
                int middle = (low + high) / 2;
                if (insertValue < arr[middle])
                {
                    high = middle - 1;
                }
                else
                {
                    low = middle + 1;
                }
            }

            for (int j = len - 1; j > high + 1; j--)
            {
                arr[j] = arr[j - 1];
            }

            arr[high + 1] = insertValue;

            foreach (int k in arr)
            {
                Console.WriteLine(k.ToString());
            }

        }
    }
}
