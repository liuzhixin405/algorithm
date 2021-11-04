using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DataStructDemo
{
    /// <summary>
    /// 单链表结点
    /// </summary>
    class Node
    {
        public Object nodeValue;

        public Node next;

        public Node()
        {
            nodeValue = null;
            next = null;
        }
        public Node(Object nodeValue)
        {
            this.nodeValue = nodeValue;
            next = null;
        }
        public Node(Object nodeValue, Node next)
        {
            this.nodeValue = nodeValue;
            this.next = next;
        }

    }
}
