using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace PB_SortFind
{
    class Program
    {
        //顺序查找
        static int FindValue(int[] arr, int value)
        {
            int i;
            int len = arr.Length;
            for (i = 0; i < len; i++)
            {
                if (arr[i] == value)
                    break;
            }

            if (i > len - 1)
            {
                return -1;
            }
            else
                return i+1;
        }


        static void Main(string[] args)
        {
            int[] arr = { 16,42,23,7,45};

            int findVal = 45;

            int pos = FindValue(arr, findVal);
            if (pos >= 0)
                Console.WriteLine("查找成功。{0}在数组中的第{1}个位置", findVal, pos);
            else
                Console.WriteLine("查找失败。");
        }
    }
}
