using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DataStructDemo
{
    /// <summary>
    /// 单链表实现
    /// </summary>
    class SingleLinkedList : ILinearList
    {
        /// <summary>
        /// 头结点
        /// </summary>
        public Node Head { get; set; }
        /// <summary>
        /// 无参构造
        /// </summary>
        public SingleLinkedList()
        {
        }
        public SingleLinkedList(Node head)
        {
            Head = head;
        }
        bool ILinearList.IsEmpty()
        {
            return Head == null;
        }

        int ILinearList.Size()
        {
            int size = 0;
            Node p = Head;
            while (p != null)
            {
                size++;
                p = p.next;
            }
            return size;
        }

        object ILinearList.Get(int index)
        {
            ILinearList list = this;
            if (index < 0 || index > list.Size()-1)
            {
                throw new IndexOutOfRangeException("索引越界");
            }

            Node p = Head;
            for (int i = 0; i < index; i++)
            {
                p = p.next;
            }
            return p.nodeValue;
        }

        object ILinearList.Set(int index, object elem)
        {
            ILinearList list = this;
            if (index < 0 || index > list.Size() - 1)
            {
                throw new IndexOutOfRangeException("索引越界");
            }
            Node p = Head;
            for (int i = 0; i < index; i++)
            {
                p = p.next;
            }
            Object old = p.nodeValue;
            p.nodeValue = elem;
            return old;
        }

        bool ILinearList.add(int index, object elem)
        {
            ILinearList list = this;
            if (index < 0 || index > list.Size())
            {
                throw new IndexOutOfRangeException("索引越界");
            }
            if (Head == null)//链表为空
            {
                Head = new Node(elem);
            }
            else
            {
                Node p = Head;
                for (int i = 0; i < index - 1; i++)
                {
                    p = p.next;
                }
                p.next = new Node(elem, p.next);
            }
            return true;
        }

        object ILinearList.remove(int index)
        {
            Object old = null;
            if (Head != null && index >= 0)
            {
                if (index == 0)//删除头结点
                {
                    old = Head.nodeValue;
                    Head = Head.next;
                }
                else
                {
                    Node p = Head;
                    for (int i = 0; i < index - 1 && p.next != null; i++)
                    {
                        p = p.next;
                    }
                    if (p.next != null)
                    {
                        old = p.next.nodeValue;
                        p.next = p.next.next;
                    }

                }
            }
            return old;
        }

        void ILinearList.clear()
        {
            Head = null;
        }




        #region ILinearList 成员


        bool ILinearList.add(ILinearList subList)
        {
            throw new NotImplementedException();
        }

        #endregion
    }
}
