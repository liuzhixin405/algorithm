using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DataStructDemo
{
    /// <summary>
    /// 队列接口
    /// </summary>
    interface IQueue
    {
        /// <summary>
        /// 入队
        /// </summary>
        /// <param name="item"></param>
        void Push(Object item);
        /// <summary>
        /// 出队
        /// </summary>
        /// <returns></returns>
        Object Pop();
        /// <summary>
        /// 获取队首元素，并不出队
        /// </summary>
        /// <returns></returns>
        Object Peek();
        /// <summary>
        /// 判断是否为空
        /// </summary>
        /// <returns></returns>
        bool IsEmpty();
        /// <summary>
        /// 获取队列中的元素个数
        /// </summary>
        /// <returns></returns>
        int Size();
    }
}
