using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DataStructDemo
{ 
    /// <summary>
    /// 循环的双链表
    /// </summary>
    class DoubleLinkedList : ILinearList
    {
        /// <summary>
        /// 头结点,不是第一个结点，它只是一个标记结点
        /// </summary>
        public DoubleNode Head { set; get; }
        /// <summary>
        /// 结点个数
        /// </summary>
        private int size = 0;
        public DoubleLinkedList()
        {
            Head = new DoubleNode();
        }
        /// <summary>
        /// 是否空的判断
        /// </summary>
        /// <returns></returns>
        public bool IsEmpty()
        {
            return size == 0;
        }
        /// <summary>
        /// 返回结点个数
        /// </summary>
        /// <returns></returns>
        public int Size()
        {
            return size;
        }
        /// <summary>
        /// 获取指定位置的节点
        /// </summary>
        /// <param name="index">指定的位置</param>
        /// <returns>结点的值</returns>
        public object Get(int index)
        {
            int i = 0;
            DoubleNode curr;
            for (curr = Head.next; curr != Head; curr = curr.next)
            {
                if (i == index)
                {
                    break;
                }
                i++;
            }
            return curr.NodeValue;
        }
        /// <summary>
        /// 设置指定位置的结点值
        /// </summary>
        /// <param name="index">指定的位置</param>
        /// <param name="elem"></param>
        /// <returns></returns>
        public  object Set(int index, object elem)
        {
            int i = 0;
            DoubleNode curr;
            for (curr = Head.next; curr != Head; curr = curr.next)
            {
                if (i == index)
                {
                    break;
                } 
                i++;
            }
            object oldValue = curr.NodeValue;
            curr.NodeValue = elem;
            return oldValue;
        }
        /// <summary>
        /// 获取最后一个结点--(头结点的前驱结点)
        /// </summary>
        /// <returns></returns>
        public Object GetLast()
        {
            ILinearList list = this;
            if (list.Size() == 0)
            {
                throw new Exception("err");
            }
            return Head.prev.NodeValue;
        }
        /// <summary>
        /// 获取第一个结点
        /// </summary>
        /// <returns></returns>
        public Object GetFirst()
        {
            ILinearList list = this;
            if (list.Size() == 0)
            {
                throw new Exception("err");
            }
            return null;
        }
        /// <summary>
        /// 添加一个节点
        /// </summary>
        /// <param name="item"></param>
        public void add(Object item)
        {
            addLast(item);
        }
        public void addLast(Object item)
        {
            AddBefore(Head, item);
        }
        /// <summary>
        /// 在指定结点前添加结点
        /// </summary>
        /// <param name="curr">指定的结点</param>
        /// <param name="item">新添加的节点值</param>
        /// <returns></returns>
        private DoubleNode AddBefore(DoubleNode curr, Object item)
        {
            DoubleNode newNode, prevNode;
            prevNode = curr.prev;
            newNode = new DoubleNode(item);
            //设置newnode的前驱和 后继
            newNode.next = curr;
            newNode.prev = prevNode;
            //
            prevNode.next = newNode;
            curr.prev = newNode;
            size++;
            return newNode;
        }
        /// <summary>
        /// 在指定的位置之前添加结点
        /// </summary>
        /// <param name="index"></param>
        /// <param name="elem"></param>
        /// <returns></returns>
        public  bool add(int index, object elem)
        {
            int i = 1;
            DoubleNode curr;
            for (curr = Head.next; curr != Head; curr = curr.next)
            {
                i++;
                if (i == index)
                {
                    break;
                }
            }
            AddBefore(curr, elem);
            return true;
        }
       
        /// <summary>
        /// 删除指定位置的结点
        /// </summary>
        /// <param name="index"></param>
        /// <returns></returns>
        public  object remove(int index)
        {
            int i = 0;
            DoubleNode curr;
            for (curr = Head.next; curr != Head; curr = curr.next)
            {
                if (i == index)
                {
                    break;
                } 
                i++;
            }
            remove(curr);
            return curr.NodeValue;
        }
        /// <summary>
        /// 删除第一个结点
        /// </summary>
        /// <returns></returns>
        public Object RemoveFirst()
        {
            if (size == 0)
            {
                throw new Exception("err");
            }
            Object first = Head.next.NodeValue;
            remove(Head.next);
            return first;
        }
        
        /// <summary>
        /// 移除指定的结点
        /// </summary>
        /// <param name="curr"></param>
        public void remove(DoubleNode curr)
        {
            DoubleNode temp;
            for (temp = Head.next; temp != Head; temp = temp.next)
            {
                if (temp.NodeValue == curr.NodeValue)
                {
                    break;
                }
            }
            if (temp != Head)//头结点不允许删除
            {
                temp.prev.next = temp.next;
                temp.next.prev = temp.prev;
            }
            size--;
        }
        /// <summary>
        /// 清空双链表，只剩下一个头结点
        /// </summary>
        public  void clear()
        {
            if (size != 0)
            {
                Head.next = Head;
                Head.prev = Head;
                size = 0;
            }
        }

        bool ILinearList.add(ILinearList subList)
        {
            throw new NotImplementedException();
        }
    }
}
