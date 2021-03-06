using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DataStructDemo
{
    /// <summary>
    /// 双向链表的节点类
    /// </summary>
    class DoubleNode
    {
        public Object NodeValue { get; set; }//结点值
        public DoubleNode prev{get;set;}//前端指针
        public DoubleNode next { get; set; }//向后的指针

        /// <summary>
        /// 构造一个没有数据域的结点
        /// </summary>
        public DoubleNode()
        {
            NodeValue = null;
            next = this;
            prev = this;
        }
        /// <summary>
        /// 构造一个包含数据域的结点
        /// </summary>
        /// <param name="item"></param>
        public DoubleNode(Object item)
        {
            this.NodeValue = item;
            next = this;
            prev = this;
        }
    }
}
