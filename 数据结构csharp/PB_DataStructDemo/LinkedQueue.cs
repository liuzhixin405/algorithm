using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DataStructDemo
{
    /// <summary>
    /// 队列的链式实现
    /// </summary>
    class LinkedQueue:IQueue
    {
        private DoubleLinkedList dlist = null;//双向链表
        ILinearList list = null;
        public LinkedQueue()
        {
            this.dlist = new DoubleLinkedList();
            list = dlist;
        }
        void IQueue.Push(object item)
        {
            this.dlist.add(item);
        }

        object IQueue.Pop()
        {
           return  dlist.RemoveFirst();
        }

        object IQueue.Peek()
        {
            return dlist.GetFirst();
        }

        bool IQueue.IsEmpty()
        {
            return list.IsEmpty();
        }

        int IQueue.Size()
        {
            return list.Size();
        }
    }
}
