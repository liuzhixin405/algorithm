using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DataStructDemo
{
    class Search_seq
    {
        /// <summary>
        /// 顺序查找，返回要查找的元素的位置
        /// </summary>
        /// <param name="ST"></param>
        /// <param name="key"></param>
        /// <returns></returns>
        public static int Search(ILinearList ST, string key)
        {
            int i = 0;
            while (!ST.Get(i).Equals(key))
                i++;
            return i;
        }
    }
}
