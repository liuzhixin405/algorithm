using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DataStructDemo
{
    /// <summary>
    /// 线性表接口
    /// </summary>
    interface ILinearList
    {
        /// <summary>
        /// 线性表是否为空
        /// </summary>
        /// <returns></returns>
        bool IsEmpty();
        /// <summary>
        /// 获取线性表的元素数量
        /// </summary>
        /// <returns></returns>
        int Size();
        /// <summary>
        /// 获取指定位置的线性表元素
        /// </summary>
        /// <param name="index"></param>
        /// <returns></returns>
        Object Get(int index);
        /// <summary>
        /// 设置指定位置的元素值
        /// </summary>
        /// <param name="index"></param>
        /// <param name="elem"></param>
        /// <returns></returns>
        Object Set(int index, Object elem);
        /// <summary>
        /// 在指定位置添加元素
        /// </summary>
        /// <param name="index"></param>
        /// <param name="elem"></param>
        /// <returns></returns>
        bool add(int index, Object elem);
        /// <summary>
        /// 移除指定位置的元素
        /// </summary>
        /// <param name="index"></param>
        /// <returns></returns>
        Object remove(int index);
        /// <summary>
        /// 清空线性表
        /// </summary>
        void clear();
        //bool add(Object item);
        /// <summary>
        /// 添加一个线性表
        /// </summary>
        /// <param name="subList"></param>
        /// <returns></returns>
        bool add(ILinearList subList);
    }
}
