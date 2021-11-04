using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PB_ShellSort
{
    class Program
    {
        static void Main(string[] args)
        {
            int[] arr = {75,60,45,21,30 };
            int length = arr.Length;

            for (int k = length / 2; k > 0; k--)
            {
                for (int i = k; i < length; i++)
                {
                    if (arr[i - k] > arr[i])
                    {
                        int temp = arr[i - k];
                        arr[i - k] = arr[i];
                        arr[i] = temp;
                    }
                }
                foreach (int n in arr)
                    Console.Write(n+"\t");
                Console.WriteLine();
            }
        }
    }
}
