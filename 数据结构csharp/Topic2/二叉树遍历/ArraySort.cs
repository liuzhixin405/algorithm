using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DataStructDemo
{
    /// <summary>
    /// 选择排序类
    /// </summary>
    class ArraySort
    {
        /// <summary>
        /// 
        /// </summary>
        /// <param name="ST">要排序的线性表 ：顺序表</param>
        /// <param name="placenum">要排序的数据在线性表中的位置</param>
        /// <returns></returns>
        public static ILinearList Sort(ILinearList ST, int placenum)
        {
            if (placenum >= ST.Size() || placenum < 0)
            {
                return ST;
            }
            int j = (int)ST.Get(placenum);
            int element = (int)ST.Get(placenum);
            int elemplace = 0;
            for (int i = placenum; i < ST.Size(); i++)
            {
                if (j > (int)ST.Get(i))
                {
                    j = (int)ST.Get(i);
                    elemplace = i;
                }
            }
            if (elemplace != 0)
            {
                ST.Set(placenum, j);
                ST.Set(elemplace, element);
            }
            return ST;
        }
    }
}
