using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PB_InsertSort
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] arr = {23, 45, 16, 7,42};

            for (int i = 1; i < arr.Length; i++)
            {
                int curValue = arr[i];
                int temp = i;
                while (temp>0 && arr[temp - 1] > curValue)
                {
                    arr[temp] = arr[temp - 1];
                    temp--;
                }
                arr[temp] = curValue;
            }

            foreach (int i in arr)
            {
                Console.WriteLine(i);
            }
        }
    }
}
