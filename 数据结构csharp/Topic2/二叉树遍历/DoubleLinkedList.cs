using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DataStructDemo
{
    class DoubleLinkedList : ILinearList
    {
        public DoubleNode Head { set; get; }//头结点
        //头结点的前驱是双链表中最后一个结点
        //头结点的后继是双链表的第一个结点

        // 循环的双链表
        private int size = 0;//结点个数
        public DoubleLinkedList()
        {
            Head = new DoubleNode();
        }
        bool ILinearList.IsEmpty()
        {
            return size == 0;
        }

        int ILinearList.Size()
        {
            return size;
        }

        object ILinearList.Get(int index)
        {
            int i = 0;
            DoubleNode curr;
            for (curr = Head.next; curr != Head; curr = curr.next)
            {
                i++;
                if (i == index)
                {
                    break;
                }
            }
            return curr.NodeValue;
        }

        object ILinearList.Set(int index, object elem)
        {
            throw new NotImplementedException();
        }
        public Object GetLast()
        {
            ILinearList list = this;
            if (list.Size() == 0)
            {
                throw new Exception("err");
            }
            return Head.prev.NodeValue;
        }
        public Object GetFirst()
        {
            ILinearList list = this;
            if (list.Size() == 0)
            {
                throw new Exception("err");
            }
            return null;
        }
        public void add(Object item)
        {
            addLast(item);
        }
        public void addLast(Object item)
        {
            AddBefore(Head, item);
        }
        bool ILinearList.add(int index, object elem)
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
        /// 在指定结点前添加结点
        /// </summary>
        /// <param name="curr">指定的结点</param>
        /// <param name="item">新添加的节点值</param>
        /// <returns></returns>
        private DoubleNode AddBefore(DoubleNode curr, Object item)
        {
            //
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
        object ILinearList.remove(int index)
        {
            int i = 0;
            DoubleNode curr;
            for (curr = Head.next; curr != Head; curr = curr.next)
            {
                i++;
                if (i == index)
                {
                    break;
                }
            }
            remove(curr);
            return curr.NodeValue;
        }
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
            if (temp != Head)
            {
                temp.prev.next = temp.next;
                temp.next.prev = temp.prev;
            }
            size--;
        }

        void ILinearList.clear()
        {
            throw new NotImplementedException();
        }

        bool ILinearList.add(ILinearList subList)
        {
            throw new NotImplementedException();
        }
    }
}
