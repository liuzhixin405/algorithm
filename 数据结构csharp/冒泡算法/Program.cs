using System;

namespace 冒泡算法
{
    internal class Program
    {
        static void Main(string[] args)
        {
            int[] arr = { 2, 9, 1, 4, 45, 3, 65, -3, -100 };
            BubbleBar(arr, arr.Length);
            Traverse(arr);
            Console.WriteLine("---------------------");
            int[] arr2 = { 5,7,4,7,23,76 };
            BubbleFar(arr2, arr2.Length);
            Traverse(arr2);
            Console.WriteLine("---------------------");
            int[] arr3 = { -6,-4,-65,-12,32 };
            BubbleFoo(arr3, arr3.Length);
            Traverse(arr3);
            Console.Read();
        }

        private static void Traverse(int[] arr)
        {
            foreach (var item in arr)
            {
                Console.Write($"{item} ");
            }
            Console.WriteLine();
        }

        private static void BubbleBar(int[] arr, int len)
        {
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
        }

        private static void BubbleFar(int[] arr, int len)
        {
            int temp;
            for (int i = 0; i < len; i++)
            {
                for (int j = i + 1; j < len; j++)
                {
                    if (arr[j] > arr[i])
                    {
                        temp = arr[j];
                        arr[j] = arr[i];
                        arr[i] = temp;
                    }
                }
            }
        }

        private static void BubbleFoo(int[] arr, int len)
        {
            int temp;
            for (int i = 0; i < len - 1; i++)
            {
                for (int j = 0; j < len - 1; j++)
                {
                    if (arr[j] < arr[j + 1])
                    {
                        temp = arr[j + 1];
                        arr[j + 1] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
        }
    }
}
