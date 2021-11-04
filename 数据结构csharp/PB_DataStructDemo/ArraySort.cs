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
        /// 选择排序算法
        /// </summary>
        /// <param name="ST">要排序的线性表 ：顺序表</param>
        /// <param name="placenum">要排序的数据在线性表中的位置</param>
        /// <returns>一轮排序后的结果</returns>
        public static ILinearList Sort(ILinearList ST, int placenum)
        {
            if (placenum >= ST.Size() || placenum < 0)
            {
                return ST;
            }
            int j = (int)ST.Get(placenum);//一轮排序要找的最小值
            int element = (int)ST.Get(placenum);//待排序数据
            int elemplace = placenum;//排序后待排序数据要放的位置
            for (int i = placenum+1; i < ST.Size(); i++)
            {
                if (j > (int)ST.Get(i))
                {
                    j = (int)ST.Get(i);
                    elemplace = i;
                }
            }
            if (elemplace != placenum)
            {
                ST.Set(placenum, j);
                ST.Set(elemplace, element);
            }
            return ST;
        }
    }
}
