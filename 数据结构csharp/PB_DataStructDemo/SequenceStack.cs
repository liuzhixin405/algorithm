using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace DataStructDemo
{
    /// <summary>
    /// 顺序栈
    /// </summary>
    class SequenceStack : StackDemo.IStack
    {
        ILinearList stackList = null;
        public SequenceStack()
        {
            stackList = new SequenceList(100);
        }
        void StackDemo.IStack.Push(object item)
        {
            stackList.add(stackList.Size(), item);
        }

        object StackDemo.IStack.Pop()
        {
            StackDemo.IStack istack = this;
            if (istack.IsEmpty())
            {
                throw new Exception("stack is null");
            }
            return stackList.remove(stackList.Size()-1);
        }

        object StackDemo.IStack.Peek()
        {
            StackDemo.IStack istack = this;
            if (istack.IsEmpty())
            {
                throw new Exception("stack is null");
            }
            return stackList.Get(stackList.Size() - 1);
        }

        bool StackDemo.IStack.IsEmpty()
        {
            return stackList.IsEmpty();
        }

        int StackDemo.IStack.Size()
        {
            return stackList.Size();
        }
    }
}
