using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PB_InsertSort
{
    class Program
    {
        /// <summary>
        /// 第一种
        /// </summary>
        /// <param name="args"></param>
        static void Main(string[] args)
        {
            int[] arr = { 23, 45, 16, 7, 42 };

            for (int i = 1; i < arr.Length; i++)
            {
                int curValue = arr[i];
                int temp = i;
                while (temp > 0 && arr[temp - 1] > curValue)
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

        /// <summary>
        /// 第二种
        /// </summary>
        /// <param name="arr"></param>
        /// <param name="len"></param>
        static void Insert_Sort(int[] arr, int len)
        {
            int i, j;
            for (i = 1; i < len; i++)
            {
                int temp = arr[i];
                for (j = i - 1; j >= 0 && arr[j] > temp; j--)
                {
                    arr[j + 1] = arr[j];
                }
                arr[j + 1] = temp;
            }
        }
    }
}
